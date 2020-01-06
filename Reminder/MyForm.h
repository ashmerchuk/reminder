#pragma once
#include "serde.h"

namespace Reminder {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    protected:

    private: System::Windows::Forms::Label^  lblListOfEvents;
    private: System::Windows::Forms::ListView^  lvwEvents;
    private: System::Windows::Forms::ColumnHeader^  columnHeader1;
    private: System::Windows::Forms::ColumnHeader^  columnHeader2;
    private: System::Windows::Forms::ColumnHeader^  columnHeader3;
    private: System::Windows::Forms::DateTimePicker^  dtpDate;
    private: System::Windows::Forms::DateTimePicker^  dtpTime;
    private: System::Windows::Forms::Button^  btnSetCurrentTime;
    private: System::Windows::Forms::TextBox^  txtEventDescription;
    private: System::Windows::Forms::Button^  btnAddEvent;


             EventsStruct *events_struct = new EventsStruct;
    private: System::Windows::Forms::Timer^  timer1;
    private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
    private: System::Windows::Forms::ContextMenuStrip^  cmsNotifyIcon;
    private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
    private: System::Windows::Forms::ContextMenuStrip^  cmsListViewItem;
    private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;

    private: System::ComponentModel::IContainer^  components;


    protected:


    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>


#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->lvwEvents = (gcnew System::Windows::Forms::ListView());
            this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
            this->lblListOfEvents = (gcnew System::Windows::Forms::Label());
            this->dtpDate = (gcnew System::Windows::Forms::DateTimePicker());
            this->dtpTime = (gcnew System::Windows::Forms::DateTimePicker());
            this->btnSetCurrentTime = (gcnew System::Windows::Forms::Button());
            this->txtEventDescription = (gcnew System::Windows::Forms::TextBox());
            this->btnAddEvent = (gcnew System::Windows::Forms::Button());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
            this->cmsNotifyIcon = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
            this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->cmsListViewItem = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
            this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->cmsNotifyIcon->SuspendLayout();
            this->cmsListViewItem->SuspendLayout();
            this->SuspendLayout();
            // 
            // lvwEvents
            // 
            this->lvwEvents->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
                this->columnHeader1, this->columnHeader2,
                    this->columnHeader3
            });
            this->lvwEvents->Cursor = System::Windows::Forms::Cursors::Default;
            this->lvwEvents->FullRowSelect = true;
            this->lvwEvents->GridLines = true;
            this->lvwEvents->Location = System::Drawing::Point(12, 43);
            this->lvwEvents->Name = L"lvwEvents";
            this->lvwEvents->ShowItemToolTips = true;
            this->lvwEvents->Size = System::Drawing::Size(462, 297);
            this->lvwEvents->TabIndex = 0;
            this->lvwEvents->UseCompatibleStateImageBehavior = false;
            this->lvwEvents->View = System::Windows::Forms::View::Details;
            this->lvwEvents->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::lvwEvents_KeyDown);
            this->lvwEvents->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::lvwEvents_MouseClick);
            // 
            // columnHeader1
            // 
            this->columnHeader1->Text = L"Date";
            this->columnHeader1->Width = 74;
            // 
            // columnHeader2
            // 
            this->columnHeader2->Text = L"Time";
            this->columnHeader2->Width = 67;
            // 
            // columnHeader3
            // 
            this->columnHeader3->Text = L"Event description";
            this->columnHeader3->Width = 317;
            // 
            // lblListOfEvents
            // 
            this->lblListOfEvents->AutoSize = true;
            this->lblListOfEvents->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblListOfEvents->Location = System::Drawing::Point(12, 9);
            this->lblListOfEvents->Name = L"lblListOfEvents";
            this->lblListOfEvents->Size = System::Drawing::Size(175, 31);
            this->lblListOfEvents->TabIndex = 1;
            this->lblListOfEvents->Text = L"List of events";
            // 
            // dtpDate
            // 
            this->dtpDate->CustomFormat = L"";
            this->dtpDate->Location = System::Drawing::Point(480, 43);
            this->dtpDate->Name = L"dtpDate";
            this->dtpDate->Size = System::Drawing::Size(196, 20);
            this->dtpDate->TabIndex = 2;
            this->dtpDate->Value = System::DateTime(2010, 1, 1, 0, 0, 0, 0);
            // 
            // dtpTime
            // 
            this->dtpTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
            this->dtpTime->Location = System::Drawing::Point(480, 69);
            this->dtpTime->Name = L"dtpTime";
            this->dtpTime->ShowUpDown = true;
            this->dtpTime->Size = System::Drawing::Size(80, 20);
            this->dtpTime->TabIndex = 3;
            this->dtpTime->Value = System::DateTime(2010, 1, 1, 0, 0, 0, 0);
            // 
            // btnSetCurrentTime
            // 
            this->btnSetCurrentTime->Location = System::Drawing::Point(566, 69);
            this->btnSetCurrentTime->Name = L"btnSetCurrentTime";
            this->btnSetCurrentTime->Size = System::Drawing::Size(110, 20);
            this->btnSetCurrentTime->TabIndex = 4;
            this->btnSetCurrentTime->Text = L"Set current time";
            this->btnSetCurrentTime->UseVisualStyleBackColor = true;
            this->btnSetCurrentTime->Click += gcnew System::EventHandler(this, &MyForm::btnSetCurrentTime_Click);
            // 
            // txtEventDescription
            // 
            this->txtEventDescription->Location = System::Drawing::Point(481, 96);
            this->txtEventDescription->MaxLength = 500;
            this->txtEventDescription->Multiline = true;
            this->txtEventDescription->Name = L"txtEventDescription";
            this->txtEventDescription->Size = System::Drawing::Size(195, 214);
            this->txtEventDescription->TabIndex = 5;
            // 
            // btnAddEvent
            // 
            this->btnAddEvent->Location = System::Drawing::Point(481, 316);
            this->btnAddEvent->Name = L"btnAddEvent";
            this->btnAddEvent->Size = System::Drawing::Size(195, 24);
            this->btnAddEvent->TabIndex = 6;
            this->btnAddEvent->Text = L"Add event";
            this->btnAddEvent->UseVisualStyleBackColor = true;
            this->btnAddEvent->Click += gcnew System::EventHandler(this, &MyForm::btnAddEvent_Click);
            // 
            // timer1
            // 
            this->timer1->Enabled = true;
            this->timer1->Interval = 1000;
            this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
            // 
            // notifyIcon1
            // 
            this->notifyIcon1->BalloonTipIcon = System::Windows::Forms::ToolTipIcon::Info;
            this->notifyIcon1->BalloonTipText = L"Description";
            this->notifyIcon1->BalloonTipTitle = L"You wanted to be remined of";
            this->notifyIcon1->ContextMenuStrip = this->cmsNotifyIcon;
            this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon1.Icon")));
            this->notifyIcon1->Text = L"Reminder";
            this->notifyIcon1->Visible = true;
            this->notifyIcon1->DoubleClick += gcnew System::EventHandler(this, &MyForm::notifyIcon1_DoubleClick);
            // 
            // cmsNotifyIcon
            // 
            this->cmsNotifyIcon->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
            this->cmsNotifyIcon->Name = L"cmsNotifyIcon";
            this->cmsNotifyIcon->Size = System::Drawing::Size(94, 26);
            // 
            // exitToolStripMenuItem
            // 
            this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
            this->exitToolStripMenuItem->Size = System::Drawing::Size(93, 22);
            this->exitToolStripMenuItem->Text = L"Exit";
            this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
            // 
            // cmsListViewItem
            // 
            this->cmsListViewItem->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->deleteToolStripMenuItem });
            this->cmsListViewItem->Name = L"cmsListViewItem";
            this->cmsListViewItem->Size = System::Drawing::Size(108, 26);
            // 
            // deleteToolStripMenuItem
            // 
            this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
            this->deleteToolStripMenuItem->Size = System::Drawing::Size(107, 22);
            this->deleteToolStripMenuItem->Text = L"Delete";
            this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deleteToolStripMenuItem_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(688, 352);
            this->Controls->Add(this->btnAddEvent);
            this->Controls->Add(this->txtEventDescription);
            this->Controls->Add(this->btnSetCurrentTime);
            this->Controls->Add(this->dtpTime);
            this->Controls->Add(this->dtpDate);
            this->Controls->Add(this->lblListOfEvents);
            this->Controls->Add(this->lvwEvents);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->Name = L"MyForm";
            this->Text = L"Reminder";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->SizeChanged += gcnew System::EventHandler(this, &MyForm::MyForm_SizeChanged);
            this->cmsNotifyIcon->ResumeLayout(false);
            this->cmsListViewItem->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void btnSetCurrentTime_Click(System::Object^  sender, System::EventArgs^  e) {
        dtpTime->Value = DateTime::Now;
    }

    private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
        dtpDate->Value = DateTime::Now;
        dtpTime->Value = DateTime::Now;
        events_struct->load(lvwEvents);
    }

    private: System::Void btnAddEvent_Click(System::Object^  sender, System::EventArgs^  e) {
        DateTime set_date = DateTime(dtpDate->Value.Year, dtpDate->Value.Month, dtpDate->Value.Day,
            dtpTime->Value.Hour, dtpTime->Value.Minute, dtpTime->Value.Second);
        Event event(set_date, true, txtEventDescription->Text);
        events_struct->events.push_back(event);
        events_struct->save(lvwEvents);
    }

    private: System::Void lvwEvents_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
        if (e->KeyCode == Keys::Delete) {
            deleteToolStripMenuItem_Click(sender, e);
        }
    }

    private: System::Void lvwEvents_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
        if (e->Button == System::Windows::Forms::MouseButtons::Right) {
            if (lvwEvents->FocusedItem->Bounds.Contains(e->Location)) {
                cmsListViewItem->Show(Cursor->Position);
            }
        }
    }

    private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
        timer1->Interval = 1000;
        auto now = DateTime::Now;
        long long cur_time = DateTime(now.Year, now.Month, now.Day,
            now.Hour, now.Minute, now.Second).ToBinary();
        // Update SELECTED_BIT
        for (int i = 0; i < events_struct->events.size() && i < lvwEvents->Items->Count; i++) {
            events_struct->events[i].set_selected(lvwEvents->Items[i]->Selected);
        }
        // Mark first active event inactive
        for (auto &event : events_struct->events) {
            if (!event.is_active()) {
                continue;
            }
            if (cur_time > event.binary_time) {
                timer1->Interval = 5000;
                event.set_active(false);
                if (event.description.empty()) {
                    notifyIcon1->BalloonTipText = gcnew System::String("No description");
                } else {
                    notifyIcon1->BalloonTipText = gcnew System::String(event.description.c_str());
                }
                notifyIcon1->ShowBalloonTip(5000);
                events_struct->save(lvwEvents);
                return;
            }
        }
    }

    private: System::Void MyForm_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
        if (FormWindowState::Minimized == this->WindowState) {
            this->Hide();
        }
    }

    private: System::Void notifyIcon1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
        this->Show();
        this->WindowState = FormWindowState::Normal;
    }

    private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
        this->Close();
    }

    private: System::Void deleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
        int j, i;
        for (i = 0, j = 0; i < lvwEvents->Items->Count; i++) {
            if (lvwEvents->Items[i]->Selected) {
                events_struct->events.erase(events_struct->events.begin() + j);
            } else {
                j++;
            }
        }
        if (j < i) {
            events_struct->save(lvwEvents);
        }
    }
};
}
