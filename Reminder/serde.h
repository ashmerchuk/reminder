#pragma once

#include <string>
#include <vector> 
#include <algorithm>
#include <msclr/marshal_cppstd.h>
#include <iostream>

#define INACTIVE_EVENT_COLOR System::Drawing::Color::IndianRed
#define EVENTS_FILENAME "local_events.txt"
// TODO enum
#define ACTIVE_BIT 1
#define SELECTED_BIT 2

struct Event {
    std::string description;
    long long binary_time;
    // Represents a state of an event
    // first (lowest) bit shows if event is active
    // second bit shows if event is selected
    int state;

    Event(System::DateTime dtime, int st, System::String^ desc) {
        description = msclr::interop::marshal_as< std::string >(desc);
        binary_time = dtime.ToBinary();
        state = st;
    }

    Event(long long bin_time, int st, std::string desc) {
        description = desc;
        binary_time = bin_time;
        state = st;
    }

    void serialize(char* buf) {
        sprintf(buf, "%lld %d %s", binary_time, state, description.c_str());
    }

    bool is_active() {
        return bool(state & ACTIVE_BIT);
    }

    bool is_selected() {
        return bool(state & SELECTED_BIT);
    }

    void set_active(bool f) {
        state |= ACTIVE_BIT;
        if (!f) {
            state ^= ACTIVE_BIT;
        }
    }

    void set_selected(bool f) {
        state |= SELECTED_BIT;
        if (!f) {
            state ^= SELECTED_BIT;
        }
    }

    bool operator <(const Event & b) const
    {
        if (binary_time == b.binary_time) {
            return description < b.description;
        }
        return binary_time < b.binary_time;
    }
};

struct EventsStruct {
    std::string filename = EVENTS_FILENAME;
    std::vector <Event> events;

    void show(System::Windows::Forms::ListView^ lvw) {
        lvw->Items->Clear();
        for (auto event : events) {
            char buf[520];
            System::DateTime dtime = System::DateTime::FromBinary(event.binary_time);
            array<System::String ^>^ a = gcnew array<System::String ^> {
                dtime.ToShortDateString(),
                dtime.ToLongTimeString(),
                gcnew System::String(event.description.c_str())
            };
            System::Windows::Forms::ListViewItem^ subitem = gcnew System::Windows::Forms::ListViewItem(a);
            if (!event.is_active()) {
                subitem->BackColor = INACTIVE_EVENT_COLOR;
            }
            if (event.is_selected()) {
                subitem->Selected = true;
            }
            lvw->Items->Add(subitem);
        }
    }

    void load(System::Windows::Forms::ListView^ lvw) {
        freopen(filename.c_str(), "r", stdin);
        long long time;
        int act;
        std::string s;
        events.clear();
        while (std::cin >> time >> act) {
            std::getline(std::cin, s);
            // Remove leading space
            if (s.size()) {
                s.erase(0, 1);
            }
            Event event = Event(time, act, s);
            event.set_selected(false);
            events.push_back(event);
        }
        fclose(stdin);
        show(lvw);
    }
    
    void save(System::Windows::Forms::ListView^ lvw) {
        sort(events.begin(), events.end());
        freopen(filename.c_str(), "w", stdout);
        lvw->Items->Clear();
        for (auto event : events) {
            char buf[520];
            event.serialize(buf);
            printf("%s\n", buf);
        }
        fclose(stdout);
        show(lvw);
    }
};
