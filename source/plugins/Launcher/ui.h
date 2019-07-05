#pragma once
#include "framework.h"
#include <msclr\marshal_cppstd.h>
#include <cstdlib>
#include "TabPadding.h"

namespace Launcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for ui
	/// </summary>
	public ref class ui : public System::Windows::Forms::Form
	{
	public:
		ui(void)
		{
			InitializeComponent();
			this->button_Discord->Cursor = Cursors::Hand;
			this->ClientSize = Drawing::Size(444, 323);
			TabPadding^ tabpad = gcnew TabPadding(tabControl);

			// Beta version, components not working yet and tab disabled
			tabPage_Components->Enabled = false;

			comboBox_Display->SelectedIndex = nDisplay;

			DEVMODEW dm = { 0 };
			dm.dmSize = sizeof(dm);
			for (int iModeNum = 0; EnumDisplaySettingsW(NULL, iModeNum, &dm) != 0; iModeNum++) 
			{
				if (!comboBox_Resolution->Items->Contains(dm.dmPelsWidth + "x" + dm.dmPelsHeight))
				{
					comboBox_Resolution->Items->Add(dm.dmPelsWidth + "x" + dm.dmPelsHeight);
				}
			}

			comboBox_intResolution->Items->Add("640x480");
			comboBox_intResolution->Items->Add("960x720");
			comboBox_intResolution->Items->Add("1280x720");
			comboBox_intResolution->Items->Add("1920x1080");
			comboBox_intResolution->Items->Add("2560x1440");
			comboBox_intResolution->Items->Add("3840x2160");
			comboBox_intResolution->Items->Add("5120x2880");
			comboBox_intResolution->Items->Add("7680x4320");

			comboBox_Resolution->Text = nWidth.ToString() + "x" + nHeight.ToString();
			checkBox_InternalRes->Checked = nIntRes;
			comboBox_intResolution->Text = nIntResWidth.ToString() + "x" + nIntResHeight.ToString();
			checkBox_Cursor->Checked = nCursor;
			checkBox_HideCredits->Checked = nHideCredits;
			checkBox_HidePVWatermark->Checked = nHidePVWatermark;
			checkBox_NoPVUi->Checked = nNoPVUi;
			checkBox_NoLyrics->Checked = nNoLyrics;
			checkBox_NoMovies->Checked = nNoMovies;
			checkBox_HideVolCtrl->Checked = nHideVolCtrl;
			comboBox_StatusIcons->SelectedIndex = nStatusIcons;
			checkBox_TAA->Checked = nTAA;
			checkBox_MLAA->Checked = nMLAA;
			checkBox_DisableErrorBanner->Checked = nNoError;
			textBox_FPSLimit->Text = nFPSLimit.ToString();
			checkBox_SkipLauncher->Checked = nSkipLauncher;

			if (!nIntRes)
			{
				comboBox_intResolution->Enabled = false;
			}
			if (nDisplay == 0)
			{
				comboBox_Resolution->Enabled = true;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ui()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_Launch;
	private: System::Windows::Forms::Button^ button_Exit;
	private: System::Windows::Forms::Label^ label_Resolution;

	protected:



	private: System::Windows::Forms::GroupBox^ groupBox_ScreenRes;


	private: System::Windows::Forms::TabControl^ tabControl;
	private: System::Windows::Forms::TabPage^ tabPage_Resolution;
	private: System::Windows::Forms::GroupBox^ groupBox_InternalRes;
	private: System::Windows::Forms::CheckBox^ checkBox_InternalRes;
	private: System::Windows::Forms::TabPage^ tabPage_Components;
	private: System::Windows::Forms::CheckBox^ checkBox_sys_timer;
	private: System::Windows::Forms::CheckBox^ checkBox_touch_panel_emulator;
	private: System::Windows::Forms::CheckBox^ checkBox_touch_slider_emulator;
	private: System::Windows::Forms::CheckBox^ checkBox_input_emulator;
	private: System::Windows::Forms::CheckBox^ checkBox_player_data_manager;

	private: System::Windows::Forms::CheckBox^ checkBox_frame_rate_manager;
	private: System::Windows::Forms::CheckBox^ checkBox_stage_manager;
	private: System::Windows::Forms::CheckBox^ checkBox_fast_loader;
	private: System::Windows::Forms::CheckBox^ checkBox_camera_controller;
	private: System::Windows::Forms::Panel^ panel_Components;

	private: System::Windows::Forms::CheckBox^ checkBox_scale_component;
	private: System::Windows::Forms::CheckBox^ checkBox_fps_limiter;
	private: System::Windows::Forms::TabPage^ tabPage_Patches;
	private: System::Windows::Forms::Panel^ panel_Patches;



	private: System::Windows::Forms::Label^ label_FPSLimit;



	private: System::Windows::Forms::CheckBox^ checkBox_Cursor;

	private: System::Windows::Forms::Label^ label_intResolution;






	private: System::Windows::Forms::TextBox^ textBox_FPSLimit;
	private: System::Windows::Forms::CheckBox^ checkBox_HideCredits;
	private: System::Windows::Forms::CheckBox^ checkBox_MLAA;
	private: System::Windows::Forms::CheckBox^ checkBox_TAA;

	private: System::Windows::Forms::CheckBox^ checkBox_HidePVWatermark;
	private: System::Windows::Forms::CheckBox^  checkBox_NoLyrics;
	private: System::Windows::Forms::CheckBox^  checkBox_NoPVUi;
	private: System::Windows::Forms::CheckBox^ checkBox_HideVolCtrl;
	private: System::Windows::Forms::ComboBox^ comboBox_Display;
	private: System::Windows::Forms::Label^ label_Display;
private: System::Windows::Forms::ComboBox^ comboBox_Resolution;
private: System::Windows::Forms::ComboBox^ comboBox_intResolution;

private: System::Windows::Forms::ComboBox^ comboBox_StatusIcons;
private: System::Windows::Forms::Label^ label_StatusIcons;
private: System::Windows::Forms::Button^ button_Discord;

private: System::Windows::Forms::Panel^ panel_innerPatches;


private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel_FPSLimit;

private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel_Status;






private: System::Windows::Forms::CheckBox^ checkBox_NoMovies;
private: System::Windows::Forms::Label^ label_Soon;
private: System::Windows::Forms::Button^ button_github;
private: System::Windows::Forms::CheckBox^ checkBox_DisableErrorBanner;
private: System::Windows::Forms::CheckBox^ checkBox_SkipLauncher;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ui::typeid));
			this->button_Launch = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->label_Resolution = (gcnew System::Windows::Forms::Label());
			this->groupBox_ScreenRes = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox_Resolution = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_Display = (gcnew System::Windows::Forms::ComboBox());
			this->label_Display = (gcnew System::Windows::Forms::Label());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_Resolution = (gcnew System::Windows::Forms::TabPage());
			this->groupBox_InternalRes = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox_intResolution = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox_InternalRes = (gcnew System::Windows::Forms::CheckBox());
			this->label_intResolution = (gcnew System::Windows::Forms::Label());
			this->tabPage_Patches = (gcnew System::Windows::Forms::TabPage());
			this->panel_Patches = (gcnew System::Windows::Forms::Panel());
			this->panel_innerPatches = (gcnew System::Windows::Forms::Panel());
			this->checkBox_DisableErrorBanner = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_NoMovies = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_Cursor = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel_FPSLimit = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox_FPSLimit = (gcnew System::Windows::Forms::TextBox());
			this->label_FPSLimit = (gcnew System::Windows::Forms::Label());
			this->checkBox_TAA = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel_Status = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label_StatusIcons = (gcnew System::Windows::Forms::Label());
			this->comboBox_StatusIcons = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox_MLAA = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_HideCredits = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_HidePVWatermark = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_HideVolCtrl = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_NoLyrics = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_NoPVUi = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage_Components = (gcnew System::Windows::Forms::TabPage());
			this->panel_Components = (gcnew System::Windows::Forms::Panel());
			this->label_Soon = (gcnew System::Windows::Forms::Label());
			this->checkBox_fps_limiter = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_scale_component = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_camera_controller = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_input_emulator = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_fast_loader = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_touch_slider_emulator = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_stage_manager = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_touch_panel_emulator = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_frame_rate_manager = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_sys_timer = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_player_data_manager = (gcnew System::Windows::Forms::CheckBox());
			this->button_Discord = (gcnew System::Windows::Forms::Button());
			this->button_github = (gcnew System::Windows::Forms::Button());
			this->checkBox_SkipLauncher = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_ScreenRes->SuspendLayout();
			this->tabControl->SuspendLayout();
			this->tabPage_Resolution->SuspendLayout();
			this->groupBox_InternalRes->SuspendLayout();
			this->tabPage_Patches->SuspendLayout();
			this->panel_Patches->SuspendLayout();
			this->panel_innerPatches->SuspendLayout();
			this->tableLayoutPanel_FPSLimit->SuspendLayout();
			this->tableLayoutPanel_Status->SuspendLayout();
			this->tabPage_Components->SuspendLayout();
			this->panel_Components->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_Launch
			// 
			this->button_Launch->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->button_Launch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Launch->Location = System::Drawing::Point(12, 236);
			this->button_Launch->Name = L"button_Launch";
			this->button_Launch->Size = System::Drawing::Size(75, 23);
			this->button_Launch->TabIndex = 20;
			this->button_Launch->Text = L"Launch";
			this->button_Launch->Click += gcnew System::EventHandler(this, &ui::Button_Launch_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_Exit->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->button_Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Exit->Location = System::Drawing::Point(145, 236);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(75, 23);
			this->button_Exit->TabIndex = 21;
			this->button_Exit->Text = L"Exit";
			this->button_Exit->Click += gcnew System::EventHandler(this, &ui::Button_Exit_Click);
			// 
			// label_Resolution
			// 
			this->label_Resolution->AutoSize = true;
			this->label_Resolution->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_Resolution->Location = System::Drawing::Point(18, 25);
			this->label_Resolution->Name = L"label_Resolution";
			this->label_Resolution->Size = System::Drawing::Size(60, 13);
			this->label_Resolution->TabIndex = 11;
			this->label_Resolution->Text = L"Resolution:";
			// 
			// groupBox_ScreenRes
			// 
			this->groupBox_ScreenRes->Controls->Add(this->comboBox_Resolution);
			this->groupBox_ScreenRes->Controls->Add(this->comboBox_Display);
			this->groupBox_ScreenRes->Controls->Add(this->label_Display);
			this->groupBox_ScreenRes->Controls->Add(this->label_Resolution);
			this->groupBox_ScreenRes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox_ScreenRes->ForeColor = System::Drawing::Color::White;
			this->groupBox_ScreenRes->Location = System::Drawing::Point(8, 6);
			this->groupBox_ScreenRes->Name = L"groupBox_ScreenRes";
			this->groupBox_ScreenRes->Size = System::Drawing::Size(208, 87);
			this->groupBox_ScreenRes->TabIndex = 10;
			this->groupBox_ScreenRes->TabStop = false;
			this->groupBox_ScreenRes->Text = L"Screen Resolution";
			// 
			// comboBox_Resolution
			// 
			this->comboBox_Resolution->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox_Resolution->FormattingEnabled = true;
			this->comboBox_Resolution->Location = System::Drawing::Point(97, 22);
			this->comboBox_Resolution->Name = L"comboBox_Resolution";
			this->comboBox_Resolution->Size = System::Drawing::Size(85, 21);
			this->comboBox_Resolution->TabIndex = 12;
			// 
			// comboBox_Display
			// 
			this->comboBox_Display->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_Display->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox_Display->FormattingEnabled = true;
			this->comboBox_Display->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Windowed", L"Borderless", L"Fullscreen" });
			this->comboBox_Display->Location = System::Drawing::Point(97, 49);
			this->comboBox_Display->Name = L"comboBox_Display";
			this->comboBox_Display->Size = System::Drawing::Size(85, 21);
			this->comboBox_Display->TabIndex = 14;
			this->comboBox_Display->SelectedIndexChanged += gcnew System::EventHandler(this, &ui::ComboBox_Display_SelectedIndexChanged);
			// 
			// label_Display
			// 
			this->label_Display->AutoSize = true;
			this->label_Display->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_Display->Location = System::Drawing::Point(18, 52);
			this->label_Display->Name = L"label_Display";
			this->label_Display->Size = System::Drawing::Size(44, 13);
			this->label_Display->TabIndex = 13;
			this->label_Display->Text = L"Display:";
			// 
			// tabControl
			// 
			this->tabControl->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
			this->tabControl->Controls->Add(this->tabPage_Resolution);
			this->tabControl->Controls->Add(this->tabPage_Patches);
			this->tabControl->Controls->Add(this->tabPage_Components);
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(233, 230);
			this->tabControl->TabIndex = 10;
			// 
			// tabPage_Resolution
			// 
			this->tabPage_Resolution->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->tabPage_Resolution->Controls->Add(this->groupBox_InternalRes);
			this->tabPage_Resolution->Controls->Add(this->groupBox_ScreenRes);
			this->tabPage_Resolution->Location = System::Drawing::Point(4, 25);
			this->tabPage_Resolution->Name = L"tabPage_Resolution";
			this->tabPage_Resolution->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Resolution->Size = System::Drawing::Size(225, 201);
			this->tabPage_Resolution->TabIndex = 0;
			this->tabPage_Resolution->Text = L"Resolution";
			// 
			// groupBox_InternalRes
			// 
			this->groupBox_InternalRes->Controls->Add(this->comboBox_intResolution);
			this->groupBox_InternalRes->Controls->Add(this->checkBox_InternalRes);
			this->groupBox_InternalRes->Controls->Add(this->label_intResolution);
			this->groupBox_InternalRes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox_InternalRes->ForeColor = System::Drawing::Color::White;
			this->groupBox_InternalRes->Location = System::Drawing::Point(8, 99);
			this->groupBox_InternalRes->Name = L"groupBox_InternalRes";
			this->groupBox_InternalRes->Size = System::Drawing::Size(208, 98);
			this->groupBox_InternalRes->TabIndex = 20;
			this->groupBox_InternalRes->TabStop = false;
			this->groupBox_InternalRes->Text = L"Internal Resolution";
			// 
			// comboBox_intResolution
			// 
			this->comboBox_intResolution->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox_intResolution->FormattingEnabled = true;
			this->comboBox_intResolution->Location = System::Drawing::Point(97, 57);
			this->comboBox_intResolution->Name = L"comboBox_intResolution";
			this->comboBox_intResolution->Size = System::Drawing::Size(85, 21);
			this->comboBox_intResolution->TabIndex = 23;
			// 
			// checkBox_InternalRes
			// 
			this->checkBox_InternalRes->AutoSize = true;
			this->checkBox_InternalRes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_InternalRes->Location = System::Drawing::Point(18, 28);
			this->checkBox_InternalRes->Name = L"checkBox_InternalRes";
			this->checkBox_InternalRes->Size = System::Drawing::Size(56, 17);
			this->checkBox_InternalRes->TabIndex = 21;
			this->checkBox_InternalRes->Text = L"Enable";
			this->checkBox_InternalRes->CheckedChanged += gcnew System::EventHandler(this, &ui::CheckBox_InternalRes_CheckedChanged);
			// 
			// label_intResolution
			// 
			this->label_intResolution->AutoSize = true;
			this->label_intResolution->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_intResolution->Location = System::Drawing::Point(15, 60);
			this->label_intResolution->Name = L"label_intResolution";
			this->label_intResolution->Size = System::Drawing::Size(60, 13);
			this->label_intResolution->TabIndex = 22;
			this->label_intResolution->Text = L"Resolution:";
			// 
			// tabPage_Patches
			// 
			this->tabPage_Patches->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->tabPage_Patches->Controls->Add(this->panel_Patches);
			this->tabPage_Patches->Location = System::Drawing::Point(4, 25);
			this->tabPage_Patches->Name = L"tabPage_Patches";
			this->tabPage_Patches->Size = System::Drawing::Size(225, 201);
			this->tabPage_Patches->TabIndex = 1;
			this->tabPage_Patches->Text = L"Options";
			// 
			// panel_Patches
			// 
			this->panel_Patches->AutoScroll = true;
			this->panel_Patches->Controls->Add(this->panel_innerPatches);
			this->panel_Patches->Location = System::Drawing::Point(0, 0);
			this->panel_Patches->Name = L"panel_Patches";
			this->panel_Patches->Size = System::Drawing::Size(225, 201);
			this->panel_Patches->TabIndex = 9;
			// 
			// panel_innerPatches
			// 
			this->panel_innerPatches->Controls->Add(this->checkBox_SkipLauncher);
			this->panel_innerPatches->Controls->Add(this->checkBox_DisableErrorBanner);
			this->panel_innerPatches->Controls->Add(this->checkBox_NoMovies);
			this->panel_innerPatches->Controls->Add(this->checkBox_Cursor);
			this->panel_innerPatches->Controls->Add(this->tableLayoutPanel_FPSLimit);
			this->panel_innerPatches->Controls->Add(this->checkBox_TAA);
			this->panel_innerPatches->Controls->Add(this->tableLayoutPanel_Status);
			this->panel_innerPatches->Controls->Add(this->checkBox_MLAA);
			this->panel_innerPatches->Controls->Add(this->checkBox_HideCredits);
			this->panel_innerPatches->Controls->Add(this->checkBox_HidePVWatermark);
			this->panel_innerPatches->Controls->Add(this->checkBox_HideVolCtrl);
			this->panel_innerPatches->Controls->Add(this->checkBox_NoLyrics);
			this->panel_innerPatches->Controls->Add(this->checkBox_NoPVUi);
			this->panel_innerPatches->Location = System::Drawing::Point(2, 2);
			this->panel_innerPatches->Margin = System::Windows::Forms::Padding(2);
			this->panel_innerPatches->Name = L"panel_innerPatches";
			this->panel_innerPatches->Size = System::Drawing::Size(204, 311);
			this->panel_innerPatches->TabIndex = 115;
			// 
			// checkBox_DisableErrorBanner
			// 
			this->checkBox_DisableErrorBanner->AutoSize = true;
			this->checkBox_DisableErrorBanner->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_DisableErrorBanner->Location = System::Drawing::Point(3, 204);
			this->checkBox_DisableErrorBanner->Name = L"checkBox_DisableErrorBanner";
			this->checkBox_DisableErrorBanner->Size = System::Drawing::Size(120, 17);
			this->checkBox_DisableErrorBanner->TabIndex = 115;
			this->checkBox_DisableErrorBanner->Text = L"Disable Error Banner";
			// 
			// checkBox_NoMovies
			// 
			this->checkBox_NoMovies->AutoSize = true;
			this->checkBox_NoMovies->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_NoMovies->Location = System::Drawing::Point(3, 117);
			this->checkBox_NoMovies->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_NoMovies->Name = L"checkBox_NoMovies";
			this->checkBox_NoMovies->Size = System::Drawing::Size(95, 17);
			this->checkBox_NoMovies->TabIndex = 15;
			this->checkBox_NoMovies->Text = L"Disable Movies";
			// 
			// checkBox_Cursor
			// 
			this->checkBox_Cursor->AutoSize = true;
			this->checkBox_Cursor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_Cursor->Location = System::Drawing::Point(3, 3);
			this->checkBox_Cursor->Name = L"checkBox_Cursor";
			this->checkBox_Cursor->Size = System::Drawing::Size(53, 17);
			this->checkBox_Cursor->TabIndex = 21;
			this->checkBox_Cursor->Text = L"Cursor";
			// 
			// tableLayoutPanel_FPSLimit
			// 
			this->tableLayoutPanel_FPSLimit->ColumnCount = 2;
			this->tableLayoutPanel_FPSLimit->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				41.4966F)));
			this->tableLayoutPanel_FPSLimit->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				58.5034F)));
			this->tableLayoutPanel_FPSLimit->Controls->Add(this->textBox_FPSLimit, 1, 0);
			this->tableLayoutPanel_FPSLimit->Controls->Add(this->label_FPSLimit, 0, 0);
			this->tableLayoutPanel_FPSLimit->Location = System::Drawing::Point(2, 281);
			this->tableLayoutPanel_FPSLimit->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel_FPSLimit->Name = L"tableLayoutPanel_FPSLimit";
			this->tableLayoutPanel_FPSLimit->RowCount = 1;
			this->tableLayoutPanel_FPSLimit->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel_FPSLimit->Size = System::Drawing::Size(147, 28);
			this->tableLayoutPanel_FPSLimit->TabIndex = 114;
			// 
			// textBox_FPSLimit
			// 
			this->textBox_FPSLimit->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_FPSLimit->Location = System::Drawing::Point(64, 3);
			this->textBox_FPSLimit->MaxLength = 3;
			this->textBox_FPSLimit->Name = L"textBox_FPSLimit";
			this->textBox_FPSLimit->Size = System::Drawing::Size(79, 20);
			this->textBox_FPSLimit->TabIndex = 111;
			this->textBox_FPSLimit->TextChanged += gcnew System::EventHandler(this, &ui::TextBox_FPSLimit_TextChanged);
			this->textBox_FPSLimit->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ui::TextBox_FPSLimit_KeyPress);
			// 
			// label_FPSLimit
			// 
			this->label_FPSLimit->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_FPSLimit->AutoSize = true;
			this->label_FPSLimit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_FPSLimit->Location = System::Drawing::Point(3, 7);
			this->label_FPSLimit->Name = L"label_FPSLimit";
			this->label_FPSLimit->Size = System::Drawing::Size(54, 13);
			this->label_FPSLimit->TabIndex = 110;
			this->label_FPSLimit->Text = L"FPS Limit:";
			this->label_FPSLimit->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// checkBox_TAA
			// 
			this->checkBox_TAA->AutoSize = true;
			this->checkBox_TAA->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_TAA->Location = System::Drawing::Point(3, 26);
			this->checkBox_TAA->Name = L"checkBox_TAA";
			this->checkBox_TAA->Size = System::Drawing::Size(44, 17);
			this->checkBox_TAA->TabIndex = 31;
			this->checkBox_TAA->Text = L"TAA";
			// 
			// tableLayoutPanel_Status
			// 
			this->tableLayoutPanel_Status->ColumnCount = 2;
			this->tableLayoutPanel_Status->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				42.85714F)));
			this->tableLayoutPanel_Status->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				57.14286F)));
			this->tableLayoutPanel_Status->Controls->Add(this->label_StatusIcons, 0, 0);
			this->tableLayoutPanel_Status->Controls->Add(this->comboBox_StatusIcons, 1, 0);
			this->tableLayoutPanel_Status->Location = System::Drawing::Point(2, 249);
			this->tableLayoutPanel_Status->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel_Status->Name = L"tableLayoutPanel_Status";
			this->tableLayoutPanel_Status->RowCount = 1;
			this->tableLayoutPanel_Status->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel_Status->Size = System::Drawing::Size(147, 28);
			this->tableLayoutPanel_Status->TabIndex = 113;
			// 
			// label_StatusIcons
			// 
			this->label_StatusIcons->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_StatusIcons->AutoSize = true;
			this->label_StatusIcons->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_StatusIcons->Location = System::Drawing::Point(3, 1);
			this->label_StatusIcons->Name = L"label_StatusIcons";
			this->label_StatusIcons->Size = System::Drawing::Size(40, 26);
			this->label_StatusIcons->TabIndex = 80;
			this->label_StatusIcons->Text = L"Status Icons:";
			this->label_StatusIcons->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// comboBox_StatusIcons
			// 
			this->comboBox_StatusIcons->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_StatusIcons->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox_StatusIcons->FormattingEnabled = true;
			this->comboBox_StatusIcons->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Default", L"Hidden", L"Error", L"OK",
					L"Partial OK"
			});
			this->comboBox_StatusIcons->Location = System::Drawing::Point(65, 3);
			this->comboBox_StatusIcons->Name = L"comboBox_StatusIcons";
			this->comboBox_StatusIcons->Size = System::Drawing::Size(79, 21);
			this->comboBox_StatusIcons->TabIndex = 101;
			// 
			// checkBox_MLAA
			// 
			this->checkBox_MLAA->AutoSize = true;
			this->checkBox_MLAA->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_MLAA->Location = System::Drawing::Point(3, 49);
			this->checkBox_MLAA->Name = L"checkBox_MLAA";
			this->checkBox_MLAA->Size = System::Drawing::Size(52, 17);
			this->checkBox_MLAA->TabIndex = 41;
			this->checkBox_MLAA->Text = L"MLAA";
			// 
			// checkBox_HideCredits
			// 
			this->checkBox_HideCredits->AutoSize = true;
			this->checkBox_HideCredits->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_HideCredits->Location = System::Drawing::Point(3, 72);
			this->checkBox_HideCredits->Name = L"checkBox_HideCredits";
			this->checkBox_HideCredits->Size = System::Drawing::Size(101, 17);
			this->checkBox_HideCredits->TabIndex = 51;
			this->checkBox_HideCredits->Text = L"Hide CREDIT(S)";
			// 
			// checkBox_HidePVWatermark
			// 
			this->checkBox_HidePVWatermark->AutoSize = true;
			this->checkBox_HidePVWatermark->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_HidePVWatermark->Location = System::Drawing::Point(3, 181);
			this->checkBox_HidePVWatermark->Name = L"checkBox_HidePVWatermark";
			this->checkBox_HidePVWatermark->Size = System::Drawing::Size(117, 17);
			this->checkBox_HidePVWatermark->TabIndex = 91;
			this->checkBox_HidePVWatermark->Text = L"Hide PV Watermark";
			// 
			// checkBox_HideVolCtrl
			// 
			this->checkBox_HideVolCtrl->AutoSize = true;
			this->checkBox_HideVolCtrl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_HideVolCtrl->Location = System::Drawing::Point(3, 95);
			this->checkBox_HideVolCtrl->Name = L"checkBox_HideVolCtrl";
			this->checkBox_HideVolCtrl->Size = System::Drawing::Size(122, 17);
			this->checkBox_HideVolCtrl->TabIndex = 61;
			this->checkBox_HideVolCtrl->Text = L"Hide Volume Buttons";
			// 
			// checkBox_NoLyrics
			// 
			this->checkBox_NoLyrics->AutoSize = true;
			this->checkBox_NoLyrics->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_NoLyrics->Location = System::Drawing::Point(3, 159);
			this->checkBox_NoLyrics->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_NoLyrics->Name = L"checkBox_NoLyrics";
			this->checkBox_NoLyrics->Size = System::Drawing::Size(88, 17);
			this->checkBox_NoLyrics->TabIndex = 81;
			this->checkBox_NoLyrics->Text = L"Disable Lyrics";
			// 
			// checkBox_NoPVUi
			// 
			this->checkBox_NoPVUi->AutoSize = true;
			this->checkBox_NoPVUi->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_NoPVUi->Location = System::Drawing::Point(3, 138);
			this->checkBox_NoPVUi->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_NoPVUi->Name = L"checkBox_NoPVUi";
			this->checkBox_NoPVUi->Size = System::Drawing::Size(89, 17);
			this->checkBox_NoPVUi->TabIndex = 71;
			this->checkBox_NoPVUi->Text = L"Disable PV UI";
			// 
			// tabPage_Components
			// 
			this->tabPage_Components->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->tabPage_Components->Controls->Add(this->panel_Components);
			this->tabPage_Components->Location = System::Drawing::Point(4, 25);
			this->tabPage_Components->Name = L"tabPage_Components";
			this->tabPage_Components->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Components->Size = System::Drawing::Size(225, 201);
			this->tabPage_Components->TabIndex = 2;
			this->tabPage_Components->Text = L"Components";
			// 
			// panel_Components
			// 
			this->panel_Components->AutoScroll = true;
			this->panel_Components->Controls->Add(this->label_Soon);
			this->panel_Components->Controls->Add(this->checkBox_fps_limiter);
			this->panel_Components->Controls->Add(this->checkBox_scale_component);
			this->panel_Components->Controls->Add(this->checkBox_camera_controller);
			this->panel_Components->Controls->Add(this->checkBox_input_emulator);
			this->panel_Components->Controls->Add(this->checkBox_fast_loader);
			this->panel_Components->Controls->Add(this->checkBox_touch_slider_emulator);
			this->panel_Components->Controls->Add(this->checkBox_stage_manager);
			this->panel_Components->Controls->Add(this->checkBox_touch_panel_emulator);
			this->panel_Components->Controls->Add(this->checkBox_frame_rate_manager);
			this->panel_Components->Controls->Add(this->checkBox_sys_timer);
			this->panel_Components->Controls->Add(this->checkBox_player_data_manager);
			this->panel_Components->Location = System::Drawing::Point(0, 0);
			this->panel_Components->Name = L"panel_Components";
			this->panel_Components->Size = System::Drawing::Size(225, 201);
			this->panel_Components->TabIndex = 0;
			// 
			// label_Soon
			// 
			this->label_Soon->AutoSize = true;
			this->label_Soon->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_Soon->Location = System::Drawing::Point(3, 3);
			this->label_Soon->Name = L"label_Soon";
			this->label_Soon->Size = System::Drawing::Size(143, 52);
			this->label_Soon->TabIndex = 12;
			this->label_Soon->Text = L"Options not yet available\r\nthrough the launcher.\r\nPlease use \"components.ini\"\r\nin"
				L"side the \"plugins\" folder.";
			// 
			// checkBox_fps_limiter
			// 
			this->checkBox_fps_limiter->AutoSize = true;
			this->checkBox_fps_limiter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_fps_limiter->Location = System::Drawing::Point(6, 277);
			this->checkBox_fps_limiter->Name = L"checkBox_fps_limiter";
			this->checkBox_fps_limiter->Size = System::Drawing::Size(76, 17);
			this->checkBox_fps_limiter->TabIndex = 10;
			this->checkBox_fps_limiter->Text = L"FPS Limiter";
			// 
			// checkBox_scale_component
			// 
			this->checkBox_scale_component->AutoSize = true;
			this->checkBox_scale_component->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_scale_component->Location = System::Drawing::Point(6, 253);
			this->checkBox_scale_component->Name = L"checkBox_scale_component";
			this->checkBox_scale_component->Size = System::Drawing::Size(107, 17);
			this->checkBox_scale_component->TabIndex = 9;
			this->checkBox_scale_component->Text = L"Scale Component";
			// 
			// checkBox_camera_controller
			// 
			this->checkBox_camera_controller->AutoSize = true;
			this->checkBox_camera_controller->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_camera_controller->Location = System::Drawing::Point(6, 230);
			this->checkBox_camera_controller->Name = L"checkBox_camera_controller";
			this->checkBox_camera_controller->Size = System::Drawing::Size(106, 17);
			this->checkBox_camera_controller->TabIndex = 8;
			this->checkBox_camera_controller->Text = L"Camera Controller";
			// 
			// checkBox_input_emulator
			// 
			this->checkBox_input_emulator->AutoSize = true;
			this->checkBox_input_emulator->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_input_emulator->Location = System::Drawing::Point(6, 35);
			this->checkBox_input_emulator->Name = L"checkBox_input_emulator";
			this->checkBox_input_emulator->Size = System::Drawing::Size(91, 17);
			this->checkBox_input_emulator->TabIndex = 0;
			this->checkBox_input_emulator->Text = L"Input Emulator";
			// 
			// checkBox_fast_loader
			// 
			this->checkBox_fast_loader->AutoSize = true;
			this->checkBox_fast_loader->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_fast_loader->Location = System::Drawing::Point(6, 207);
			this->checkBox_fast_loader->Name = L"checkBox_fast_loader";
			this->checkBox_fast_loader->Size = System::Drawing::Size(79, 17);
			this->checkBox_fast_loader->TabIndex = 7;
			this->checkBox_fast_loader->Text = L"Fast Loader";
			// 
			// checkBox_touch_slider_emulator
			// 
			this->checkBox_touch_slider_emulator->AutoSize = true;
			this->checkBox_touch_slider_emulator->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_touch_slider_emulator->Location = System::Drawing::Point(6, 69);
			this->checkBox_touch_slider_emulator->Name = L"checkBox_touch_slider_emulator";
			this->checkBox_touch_slider_emulator->Size = System::Drawing::Size(128, 17);
			this->checkBox_touch_slider_emulator->TabIndex = 1;
			this->checkBox_touch_slider_emulator->Text = L"Touch Panel Emulator";
			// 
			// checkBox_stage_manager
			// 
			this->checkBox_stage_manager->AutoSize = true;
			this->checkBox_stage_manager->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_stage_manager->Location = System::Drawing::Point(6, 184);
			this->checkBox_stage_manager->Name = L"checkBox_stage_manager";
			this->checkBox_stage_manager->Size = System::Drawing::Size(96, 17);
			this->checkBox_stage_manager->TabIndex = 6;
			this->checkBox_stage_manager->Text = L"Stage Manager";
			// 
			// checkBox_touch_panel_emulator
			// 
			this->checkBox_touch_panel_emulator->AutoSize = true;
			this->checkBox_touch_panel_emulator->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_touch_panel_emulator->Location = System::Drawing::Point(6, 92);
			this->checkBox_touch_panel_emulator->Name = L"checkBox_touch_panel_emulator";
			this->checkBox_touch_panel_emulator->Size = System::Drawing::Size(127, 17);
			this->checkBox_touch_panel_emulator->TabIndex = 2;
			this->checkBox_touch_panel_emulator->Text = L"Touch Slider Emulator";
			// 
			// checkBox_frame_rate_manager
			// 
			this->checkBox_frame_rate_manager->AutoSize = true;
			this->checkBox_frame_rate_manager->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_frame_rate_manager->Location = System::Drawing::Point(6, 161);
			this->checkBox_frame_rate_manager->Name = L"checkBox_frame_rate_manager";
			this->checkBox_frame_rate_manager->Size = System::Drawing::Size(123, 17);
			this->checkBox_frame_rate_manager->TabIndex = 5;
			this->checkBox_frame_rate_manager->Text = L"Frame Rate Manager";
			// 
			// checkBox_sys_timer
			// 
			this->checkBox_sys_timer->AutoSize = true;
			this->checkBox_sys_timer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_sys_timer->Location = System::Drawing::Point(6, 115);
			this->checkBox_sys_timer->Name = L"checkBox_sys_timer";
			this->checkBox_sys_timer->Size = System::Drawing::Size(117, 17);
			this->checkBox_sys_timer->TabIndex = 3;
			this->checkBox_sys_timer->Text = L"Freeze Select Timer";
			// 
			// checkBox_player_data_manager
			// 
			this->checkBox_player_data_manager->AutoSize = true;
			this->checkBox_player_data_manager->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_player_data_manager->Location = System::Drawing::Point(6, 138);
			this->checkBox_player_data_manager->Name = L"checkBox_player_data_manager";
			this->checkBox_player_data_manager->Size = System::Drawing::Size(123, 17);
			this->checkBox_player_data_manager->TabIndex = 4;
			this->checkBox_player_data_manager->Text = L"Player Data Manager";
			// 
			// button_Discord
			// 
			this->button_Discord->BackColor = System::Drawing::Color::Transparent;
			this->button_Discord->FlatAppearance->BorderSize = 0;
			this->button_Discord->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button_Discord->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button_Discord->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Discord->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Discord.Image")));
			this->button_Discord->Location = System::Drawing::Point(239, 12);
			this->button_Discord->Name = L"button_Discord";
			this->button_Discord->Size = System::Drawing::Size(42, 42);
			this->button_Discord->TabIndex = 31;
			this->button_Discord->UseVisualStyleBackColor = false;
			this->button_Discord->Click += gcnew System::EventHandler(this, &ui::button_Discord_Click);
			// 
			// button_github
			// 
			this->button_github->BackColor = System::Drawing::Color::Transparent;
			this->button_github->FlatAppearance->BorderSize = 0;
			this->button_github->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button_github->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button_github->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_github->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_github.Image")));
			this->button_github->Location = System::Drawing::Point(239, 60);
			this->button_github->Name = L"button_github";
			this->button_github->Size = System::Drawing::Size(42, 42);
			this->button_github->TabIndex = 32;
			this->button_github->UseVisualStyleBackColor = false;
			this->button_github->Click += gcnew System::EventHandler(this, &ui::button_github_Click);
			// 
			// checkBox_SkipLauncher
			// 
			this->checkBox_SkipLauncher->AutoSize = true;
			this->checkBox_SkipLauncher->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox_SkipLauncher->Location = System::Drawing::Point(3, 227);
			this->checkBox_SkipLauncher->Name = L"checkBox_SkipLauncher";
			this->checkBox_SkipLauncher->Size = System::Drawing::Size(92, 17);
			this->checkBox_SkipLauncher->TabIndex = 116;
			this->checkBox_SkipLauncher->Text = L"Skip Launcher";
			// 
			// ui
			// 
			this->AcceptButton = this->button_Launch;
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CancelButton = this->button_Exit;
			this->ClientSize = System::Drawing::Size(288, 265);
			this->Controls->Add(this->button_github);
			this->Controls->Add(this->button_Discord);
			this->Controls->Add(this->tabControl);
			this->Controls->Add(this->button_Exit);
			this->Controls->Add(this->button_Launch);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ui";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DIVA Launcher";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ui::Ui_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ui::Ui_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ui::Ui_Load);
			this->groupBox_ScreenRes->ResumeLayout(false);
			this->groupBox_ScreenRes->PerformLayout();
			this->tabControl->ResumeLayout(false);
			this->tabPage_Resolution->ResumeLayout(false);
			this->groupBox_InternalRes->ResumeLayout(false);
			this->groupBox_InternalRes->PerformLayout();
			this->tabPage_Patches->ResumeLayout(false);
			this->panel_Patches->ResumeLayout(false);
			this->panel_innerPatches->ResumeLayout(false);
			this->panel_innerPatches->PerformLayout();
			this->tableLayoutPanel_FPSLimit->ResumeLayout(false);
			this->tableLayoutPanel_FPSLimit->PerformLayout();
			this->tableLayoutPanel_Status->ResumeLayout(false);
			this->tableLayoutPanel_Status->PerformLayout();
			this->tabPage_Components->ResumeLayout(false);
			this->panel_Components->ResumeLayout(false);
			this->panel_Components->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void SaveSettings() {
	String^ userInput = Convert::ToInt32(comboBox_Display->SelectedIndex).ToString();
	wstring input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"display", input.c_str(), CONFIG_FILE);

	userInput = comboBox_Resolution->Text;
	cli::array<String^>^ ResolutionArray = userInput->Split('x');
	userInput = ResolutionArray[0];
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"width", input.c_str(), CONFIG_FILE);

	userInput = comboBox_Resolution->Text;
	ResolutionArray = userInput->Split('x');
	userInput = ResolutionArray[1];
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"height", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_InternalRes->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"r.enable", input.c_str(), CONFIG_FILE);

	userInput = comboBox_intResolution->Text;
	cli::array<String^>^ intResolutionArray = userInput->Split('x');
	userInput = intResolutionArray[0];
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"r.width", input.c_str(), CONFIG_FILE);

	userInput = comboBox_intResolution->Text;
	intResolutionArray = userInput->Split('x');
	userInput = intResolutionArray[1];
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"r.height", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_Cursor->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"cursor", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_HideCredits->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"hide_credits", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(comboBox_StatusIcons->SelectedIndex).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"status_icons", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_HidePVWatermark->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"hide_pv_watermark", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_NoPVUi->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"no_pv_ui", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_NoLyrics->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"no_lyrics", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_NoMovies->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"no_movies", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_HideVolCtrl->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"hide_volume", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_DisableErrorBanner->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"no_error", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_TAA->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"graphics", L"TAA", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_MLAA->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"graphics", L"MLAA", input.c_str(), CONFIG_FILE);

	userInput = textBox_FPSLimit->Text;
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"graphics", L"FPS.Limit", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_SkipLauncher->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"launcher", L"skip", input.c_str(), CONFIG_FILE);
}
private: System::Void Ui_Load(System::Object^ sender, System::EventArgs^ e){
}
private: System::Void Button_Exit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void Button_Launch_Click(System::Object^ sender, System::EventArgs^ e) {

	SaveSettings();

	STARTUPINFOW si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	CreateProcessW(DIVA_EXECUTABLE, DIVA_EXECUTABLE_LAUNCH, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	
	// this->Close won't work in here since it will prompt the user to save the settings
	TerminateProcess(GetCurrentProcess(), EXIT_SUCCESS);
}
private: System::Void CheckBox_InternalRes_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox_InternalRes->Checked)
	{
		comboBox_intResolution->Enabled = true;
	}
	else
	{
		comboBox_intResolution->Enabled = false;
	}
}
private: System::Void ComboBox_Display_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox_Display->SelectedIndex == 0)
	{
		comboBox_Resolution->Enabled = true;
	}
	else
	{
		comboBox_Resolution->Enabled = false;
	}
}
private: System::Void Ui_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	switch (MessageBox::Show("Do you want to save your settings?", "DIVA Launcher", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question))
	{
	case System::Windows::Forms::DialogResult::Yes:
		SaveSettings();
		break;

	case System::Windows::Forms::DialogResult::No:
		break;

	case System::Windows::Forms::DialogResult::Cancel:
		e->Cancel = true;
		break;
	}
}
private: System::Void Ui_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	// Prevents abnormal termination messages, remember that the game is still technically running and must be killed!
	TerminateProcess(GetCurrentProcess(), EXIT_SUCCESS);
}
private: System::Void button_Discord_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Diagnostics::Process::Start("https://discord.gg/cvBVGDZ");
}
private: System::Void TextBox_FPSLimit_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (System::Text::RegularExpressions::Regex::IsMatch(textBox_FPSLimit->Text, "  ^ [0-9]"))
	{
		textBox_FPSLimit->Text = "";
	}
}
private: System::Void TextBox_FPSLimit_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != '.'))
	{
		e->Handled = true;
	}
}
private: System::Void button_github_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Diagnostics::Process::Start("https://github.com/Rayduxz/DIVA-Loader");
}
};
}

