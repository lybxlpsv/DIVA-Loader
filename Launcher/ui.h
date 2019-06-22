#pragma once
#include "framework.h"
#include <msclr\marshal_cppstd.h>
#include <cstdlib>

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

			// Beta version, components not working yet and hidden
			tabPage_Components->Enabled = false;

			// Not working, but saving the settings does work
			checkBox_Stereo->Checked = nStereo;
			checkBox_Cursor->Checked = nCursor;
			checkBox_HideCredits->Checked = nHideCredits;
			checkBox_HideStatusIcons->Checked = nHideStatusIcons;
			checkBox_HidePVWatermark->Checked = nHidePVWatermark;
			checkBox_HideVolCtrl->Checked = nHideVolCtrl;
			checkBox_HideStatusIcons->Checked = nHideStatusIcons;
			checkBox_TAA->Checked = nTAA;
			checkBox_MLAA->Checked = nMLAA;

			textBox_Height->Text = nHeight.ToString();
			textBox_Width->Text = nWidth.ToString();

			checkBox_Fullscreen->Checked = nFullscreen;
			checkBox_Borderless->Checked = nBorderless;

			checkBox_InternalRes->Checked = nIntRes;

			textBox_intResHeight->Text = nIntResHeight.ToString();
			textBox_intResWidth->Text = nIntResWidth.ToString();

			textBox_FPSLimit->Text = nFPSLimit.ToString();
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

	protected:

	private: System::Windows::Forms::Label^ label_Height;
	private: System::Windows::Forms::Label^ label_Width;
	private: System::Windows::Forms::GroupBox^ groupBox_ScreenRes;
	private: System::Windows::Forms::CheckBox^ checkBox_Fullscreen;
	private: System::Windows::Forms::CheckBox^ checkBox_Borderless;
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
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::CheckBox^ checkBox_scale_component;
	private: System::Windows::Forms::CheckBox^ checkBox_fps_limiter;
	private: System::Windows::Forms::TabPage^ tabPage_Patches;
	private: System::Windows::Forms::Panel^ panel_Patches;
	private: System::Windows::Forms::CheckBox^ checkBox_Stereo;


	private: System::Windows::Forms::Label^ label_FPSLimit;



	private: System::Windows::Forms::CheckBox^ checkBox_Cursor;
	private: System::Windows::Forms::LinkLabel^ linkLabel_Discord;
	private: System::Windows::Forms::TextBox^ textBox_Width;
	private: System::Windows::Forms::TextBox^ textBox_Height;
	private: System::Windows::Forms::TextBox^ textBox_intResWidth;
	private: System::Windows::Forms::TextBox^ textBox_intResHeight;
	private: System::Windows::Forms::Label^ label_intResHeight;
	private: System::Windows::Forms::Label^ label_intResWidth;
	private: System::Windows::Forms::TextBox^ textBox_FPSLimit;
	private: System::Windows::Forms::CheckBox^ checkBox_HideCredits;
	private: System::Windows::Forms::CheckBox^ checkBox_MLAA;
	private: System::Windows::Forms::CheckBox^ checkBox_TAA;
	private: System::Windows::Forms::CheckBox^ checkBox_HideStatusIcons;
	private: System::Windows::Forms::CheckBox^ checkBox_HidePVWatermark;
	private: System::Windows::Forms::CheckBox^ checkBox_HideVolCtrl;

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
			this->label_Height = (gcnew System::Windows::Forms::Label());
			this->label_Width = (gcnew System::Windows::Forms::Label());
			this->groupBox_ScreenRes = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_Width = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Height = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_Borderless = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_Fullscreen = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_Resolution = (gcnew System::Windows::Forms::TabPage());
			this->groupBox_InternalRes = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_intResWidth = (gcnew System::Windows::Forms::TextBox());
			this->textBox_intResHeight = (gcnew System::Windows::Forms::TextBox());
			this->label_intResHeight = (gcnew System::Windows::Forms::Label());
			this->checkBox_InternalRes = (gcnew System::Windows::Forms::CheckBox());
			this->label_intResWidth = (gcnew System::Windows::Forms::Label());
			this->tabPage_Patches = (gcnew System::Windows::Forms::TabPage());
			this->panel_Patches = (gcnew System::Windows::Forms::Panel());
			this->checkBox_HideCredits = (gcnew System::Windows::Forms::CheckBox());
			this->textBox_FPSLimit = (gcnew System::Windows::Forms::TextBox());
			this->linkLabel_Discord = (gcnew System::Windows::Forms::LinkLabel());
			this->label_FPSLimit = (gcnew System::Windows::Forms::Label());
			this->checkBox_MLAA = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_TAA = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_HideStatusIcons = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_Cursor = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_Stereo = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage_Components = (gcnew System::Windows::Forms::TabPage());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
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
			this->checkBox_HideVolCtrl = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_HidePVWatermark = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_ScreenRes->SuspendLayout();
			this->tabControl->SuspendLayout();
			this->tabPage_Resolution->SuspendLayout();
			this->groupBox_InternalRes->SuspendLayout();
			this->tabPage_Patches->SuspendLayout();
			this->panel_Patches->SuspendLayout();
			this->tabPage_Components->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_Launch
			// 
			this->button_Launch->Location = System::Drawing::Point(24, 428);
			this->button_Launch->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_Launch->Name = L"button_Launch";
			this->button_Launch->Size = System::Drawing::Size(112, 35);
			this->button_Launch->TabIndex = 30;
			this->button_Launch->Text = L"Launch";
			this->button_Launch->UseVisualStyleBackColor = true;
			this->button_Launch->Click += gcnew System::EventHandler(this, &ui::Button_Launch_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_Exit->Location = System::Drawing::Point(182, 428);
			this->button_Exit->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(112, 35);
			this->button_Exit->TabIndex = 31;
			this->button_Exit->Text = L"Exit";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &ui::Button_Exit_Click);
			// 
			// label_Height
			// 
			this->label_Height->AutoSize = true;
			this->label_Height->Location = System::Drawing::Point(9, 69);
			this->label_Height->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Height->Name = L"label_Height";
			this->label_Height->Size = System::Drawing::Size(60, 20);
			this->label_Height->TabIndex = 3;
			this->label_Height->Text = L"Height:";
			// 
			// label_Width
			// 
			this->label_Width->AutoSize = true;
			this->label_Width->Location = System::Drawing::Point(9, 34);
			this->label_Width->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Width->Name = L"label_Width";
			this->label_Width->Size = System::Drawing::Size(54, 20);
			this->label_Width->TabIndex = 4;
			this->label_Width->Text = L"Width:";
			this->label_Width->Click += gcnew System::EventHandler(this, &ui::Label_Width_Click);
			// 
			// groupBox_ScreenRes
			// 
			this->groupBox_ScreenRes->Controls->Add(this->textBox_Width);
			this->groupBox_ScreenRes->Controls->Add(this->textBox_Height);
			this->groupBox_ScreenRes->Controls->Add(this->checkBox_Borderless);
			this->groupBox_ScreenRes->Controls->Add(this->label_Height);
			this->groupBox_ScreenRes->Controls->Add(this->checkBox_Fullscreen);
			this->groupBox_ScreenRes->Controls->Add(this->label_Width);
			this->groupBox_ScreenRes->Location = System::Drawing::Point(15, 9);
			this->groupBox_ScreenRes->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox_ScreenRes->Name = L"groupBox_ScreenRes";
			this->groupBox_ScreenRes->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox_ScreenRes->Size = System::Drawing::Size(244, 182);
			this->groupBox_ScreenRes->TabIndex = 6;
			this->groupBox_ScreenRes->TabStop = false;
			this->groupBox_ScreenRes->Text = L"Screen Resolution";
			// 
			// textBox_Width
			// 
			this->textBox_Width->Location = System::Drawing::Point(118, 29);
			this->textBox_Width->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_Width->Name = L"textBox_Width";
			this->textBox_Width->Size = System::Drawing::Size(115, 26);
			this->textBox_Width->TabIndex = 1;
			this->textBox_Width->TextChanged += gcnew System::EventHandler(this, &ui::TextBox_Width_TextChanged);
			// 
			// textBox_Height
			// 
			this->textBox_Height->Location = System::Drawing::Point(118, 65);
			this->textBox_Height->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_Height->Name = L"textBox_Height";
			this->textBox_Height->Size = System::Drawing::Size(115, 26);
			this->textBox_Height->TabIndex = 2;
			this->textBox_Height->TextChanged += gcnew System::EventHandler(this, &ui::TextBox_Height_TextChanged);
			// 
			// checkBox_Borderless
			// 
			this->checkBox_Borderless->AutoSize = true;
			this->checkBox_Borderless->Location = System::Drawing::Point(14, 148);
			this->checkBox_Borderless->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_Borderless->Name = L"checkBox_Borderless";
			this->checkBox_Borderless->Size = System::Drawing::Size(111, 24);
			this->checkBox_Borderless->TabIndex = 4;
			this->checkBox_Borderless->Text = L"Borderless";
			this->checkBox_Borderless->UseVisualStyleBackColor = true;
			// 
			// checkBox_Fullscreen
			// 
			this->checkBox_Fullscreen->AutoSize = true;
			this->checkBox_Fullscreen->Location = System::Drawing::Point(14, 112);
			this->checkBox_Fullscreen->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_Fullscreen->Name = L"checkBox_Fullscreen";
			this->checkBox_Fullscreen->Size = System::Drawing::Size(108, 24);
			this->checkBox_Fullscreen->TabIndex = 3;
			this->checkBox_Fullscreen->Text = L"Fullscreen";
			this->checkBox_Fullscreen->UseVisualStyleBackColor = true;
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabPage_Resolution);
			this->tabControl->Controls->Add(this->tabPage_Patches);
			this->tabControl->Controls->Add(this->tabPage_Components);
			this->tabControl->Location = System::Drawing::Point(18, 18);
			this->tabControl->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(282, 400);
			this->tabControl->TabIndex = 0;
			// 
			// tabPage_Resolution
			// 
			this->tabPage_Resolution->Controls->Add(this->groupBox_InternalRes);
			this->tabPage_Resolution->Controls->Add(this->groupBox_ScreenRes);
			this->tabPage_Resolution->Location = System::Drawing::Point(4, 29);
			this->tabPage_Resolution->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage_Resolution->Name = L"tabPage_Resolution";
			this->tabPage_Resolution->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage_Resolution->Size = System::Drawing::Size(274, 367);
			this->tabPage_Resolution->TabIndex = 0;
			this->tabPage_Resolution->Text = L"Resolution";
			this->tabPage_Resolution->UseVisualStyleBackColor = true;
			// 
			// groupBox_InternalRes
			// 
			this->groupBox_InternalRes->Controls->Add(this->textBox_intResWidth);
			this->groupBox_InternalRes->Controls->Add(this->textBox_intResHeight);
			this->groupBox_InternalRes->Controls->Add(this->label_intResHeight);
			this->groupBox_InternalRes->Controls->Add(this->checkBox_InternalRes);
			this->groupBox_InternalRes->Controls->Add(this->label_intResWidth);
			this->groupBox_InternalRes->Location = System::Drawing::Point(15, 200);
			this->groupBox_InternalRes->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox_InternalRes->Name = L"groupBox_InternalRes";
			this->groupBox_InternalRes->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox_InternalRes->Size = System::Drawing::Size(244, 149);
			this->groupBox_InternalRes->TabIndex = 5;
			this->groupBox_InternalRes->TabStop = false;
			this->groupBox_InternalRes->Text = L"Internal Resolution";
			// 
			// textBox_intResWidth
			// 
			this->textBox_intResWidth->Location = System::Drawing::Point(118, 74);
			this->textBox_intResWidth->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_intResWidth->Name = L"textBox_intResWidth";
			this->textBox_intResWidth->Size = System::Drawing::Size(115, 26);
			this->textBox_intResWidth->TabIndex = 6;
			// 
			// textBox_intResHeight
			// 
			this->textBox_intResHeight->Location = System::Drawing::Point(118, 110);
			this->textBox_intResHeight->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_intResHeight->Name = L"textBox_intResHeight";
			this->textBox_intResHeight->Size = System::Drawing::Size(115, 26);
			this->textBox_intResHeight->TabIndex = 7;
			// 
			// label_intResHeight
			// 
			this->label_intResHeight->AutoSize = true;
			this->label_intResHeight->Location = System::Drawing::Point(9, 114);
			this->label_intResHeight->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_intResHeight->Name = L"label_intResHeight";
			this->label_intResHeight->Size = System::Drawing::Size(60, 20);
			this->label_intResHeight->TabIndex = 10;
			this->label_intResHeight->Text = L"Height:";
			this->label_intResHeight->Click += gcnew System::EventHandler(this, &ui::Label_intResHeight_Click);
			// 
			// checkBox_InternalRes
			// 
			this->checkBox_InternalRes->AutoSize = true;
			this->checkBox_InternalRes->Location = System::Drawing::Point(14, 36);
			this->checkBox_InternalRes->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_InternalRes->Name = L"checkBox_InternalRes";
			this->checkBox_InternalRes->Size = System::Drawing::Size(85, 24);
			this->checkBox_InternalRes->TabIndex = 7;
			this->checkBox_InternalRes->Text = L"Enable";
			this->checkBox_InternalRes->UseVisualStyleBackColor = true;
			// 
			// label_intResWidth
			// 
			this->label_intResWidth->AutoSize = true;
			this->label_intResWidth->Location = System::Drawing::Point(9, 79);
			this->label_intResWidth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_intResWidth->Name = L"label_intResWidth";
			this->label_intResWidth->Size = System::Drawing::Size(54, 20);
			this->label_intResWidth->TabIndex = 11;
			this->label_intResWidth->Text = L"Width:";
			this->label_intResWidth->Click += gcnew System::EventHandler(this, &ui::Label_intResWidth_Click);
			// 
			// tabPage_Patches
			// 
			this->tabPage_Patches->Controls->Add(this->panel_Patches);
			this->tabPage_Patches->Location = System::Drawing::Point(4, 29);
			this->tabPage_Patches->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage_Patches->Name = L"tabPage_Patches";
			this->tabPage_Patches->Size = System::Drawing::Size(274, 367);
			this->tabPage_Patches->TabIndex = 2;
			this->tabPage_Patches->Text = L"Patches";
			this->tabPage_Patches->UseVisualStyleBackColor = true;
			// 
			// panel_Patches
			// 
			this->panel_Patches->AutoScroll = true;
			this->panel_Patches->Controls->Add(this->checkBox_HidePVWatermark);
			this->panel_Patches->Controls->Add(this->checkBox_HideVolCtrl);
			this->panel_Patches->Controls->Add(this->checkBox_HideCredits);
			this->panel_Patches->Controls->Add(this->textBox_FPSLimit);
			this->panel_Patches->Controls->Add(this->linkLabel_Discord);
			this->panel_Patches->Controls->Add(this->label_FPSLimit);
			this->panel_Patches->Controls->Add(this->checkBox_MLAA);
			this->panel_Patches->Controls->Add(this->checkBox_TAA);
			this->panel_Patches->Controls->Add(this->checkBox_HideStatusIcons);
			this->panel_Patches->Controls->Add(this->checkBox_Cursor);
			this->panel_Patches->Controls->Add(this->checkBox_Stereo);
			this->panel_Patches->Location = System::Drawing::Point(9, 9);
			this->panel_Patches->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel_Patches->Name = L"panel_Patches";
			this->panel_Patches->Size = System::Drawing::Size(261, 340);
			this->panel_Patches->TabIndex = 9;
			// 
			// checkBox_Stereo
			// 
			this->checkBox_Stereo->AutoSize = true;
			this->checkBox_Stereo->Location = System::Drawing::Point(4, 5);
			this->checkBox_Stereo->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_Stereo->Name = L"checkBox_Stereo";
			this->checkBox_Stereo->Size = System::Drawing::Size(83, 24);
			this->checkBox_Stereo->TabIndex = 8;
			this->checkBox_Stereo->Text = L"Stereo";
			this->checkBox_Stereo->UseVisualStyleBackColor = true;
			// 
			// checkBox_Cursor
			// 
			this->checkBox_Cursor->AutoSize = true;
			this->checkBox_Cursor->Location = System::Drawing::Point(4, 40);
			this->checkBox_Cursor->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_Cursor->Name = L"checkBox_Cursor";
			this->checkBox_Cursor->Size = System::Drawing::Size(82, 24);
			this->checkBox_Cursor->TabIndex = 9;
			this->checkBox_Cursor->Text = L"Cursor";
			this->checkBox_Cursor->UseVisualStyleBackColor = true;
			// 
			// checkBox_HideCredits
			// 
			this->checkBox_HideCredits->AutoSize = true;
			this->checkBox_HideCredits->Location = System::Drawing::Point(4, 76);
			this->checkBox_HideCredits->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_HideCredits->Name = L"checkBox_HideCredits";
			this->checkBox_HideCredits->Size = System::Drawing::Size(153, 24);
			this->checkBox_HideCredits->TabIndex = 10;
			this->checkBox_HideCredits->Text = L"Hide CREDIT(S)";
			this->checkBox_HideCredits->UseVisualStyleBackColor = true;
			// 
			// checkBox_HideStatusIcons
			// 
			this->checkBox_HideStatusIcons->AutoSize = true;
			this->checkBox_HideStatusIcons->Location = System::Drawing::Point(4, 111);
			this->checkBox_HideStatusIcons->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_HideStatusIcons->Name = L"checkBox_HideStatusIcons";
			this->checkBox_HideStatusIcons->Size = System::Drawing::Size(162, 24);
			this->checkBox_HideStatusIcons->TabIndex = 11;
			this->checkBox_HideStatusIcons->Text = L"Hide Status Icons";
			this->checkBox_HideStatusIcons->UseVisualStyleBackColor = true;
			// 
			// checkBox_HideVolCtrl
			// 
			this->checkBox_HideVolCtrl->AutoSize = true;
			this->checkBox_HideVolCtrl->Location = System::Drawing::Point(4, 146);
			this->checkBox_HideVolCtrl->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_HideVolCtrl->Name = L"checkBox_HideVolCtrl";
			this->checkBox_HideVolCtrl->Size = System::Drawing::Size(162, 24);
			this->checkBox_HideVolCtrl->TabIndex = 16;
			this->checkBox_HideVolCtrl->Text = L"Hide Volume Buttons";
			this->checkBox_HideVolCtrl->UseVisualStyleBackColor = true;
			this->checkBox_HideVolCtrl->CheckedChanged += gcnew System::EventHandler(this, &ui::checkBox_HideVolCtrl_CheckedChanged);
			// 
			// checkBox_HidePVWatermark
			// 
			this->checkBox_HidePVWatermark->AutoSize = true;
			this->checkBox_HidePVWatermark->Location = System::Drawing::Point(4, 181);
			this->checkBox_HidePVWatermark->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_HidePVWatermark->Name = L"checkBox_HidePVWatermark";
			this->checkBox_HidePVWatermark->Size = System::Drawing::Size(162, 24);
			this->checkBox_HidePVWatermark->TabIndex = 17;
			this->checkBox_HidePVWatermark->Text = L"Hide PV Watermark";
			this->checkBox_HidePVWatermark->UseVisualStyleBackColor = true;
			// 
			// checkBox_TAA
			// 
			this->checkBox_TAA->AutoSize = true;
			this->checkBox_TAA->Location = System::Drawing::Point(4, 216);
			this->checkBox_TAA->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_TAA->Name = L"checkBox_TAA";
			this->checkBox_TAA->Size = System::Drawing::Size(66, 24);
			this->checkBox_TAA->TabIndex = 12;
			this->checkBox_TAA->Text = L"TAA";
			this->checkBox_TAA->UseVisualStyleBackColor = true;
			// 
			// checkBox_MLAA
			// 
			this->checkBox_MLAA->AutoSize = true;
			this->checkBox_MLAA->Location = System::Drawing::Point(4, 251);
			this->checkBox_MLAA->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_MLAA->Name = L"checkBox_MLAA";
			this->checkBox_MLAA->Size = System::Drawing::Size(79, 24);
			this->checkBox_MLAA->TabIndex = 13;
			this->checkBox_MLAA->Text = L"MLAA";
			this->checkBox_MLAA->UseVisualStyleBackColor = true;
			// 
			// label_FPSLimit
			// 
			this->label_FPSLimit->AutoSize = true;
			this->label_FPSLimit->Location = System::Drawing::Point(0, 292);
			this->label_FPSLimit->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_FPSLimit->Name = L"label_FPSLimit";
			this->label_FPSLimit->Size = System::Drawing::Size(81, 20);
			this->label_FPSLimit->TabIndex = 5;
			this->label_FPSLimit->Text = L"FPS Limit:";
			// 
			// textBox_FPSLimit
			// 
			this->textBox_FPSLimit->Location = System::Drawing::Point(86, 289);
			this->textBox_FPSLimit->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_FPSLimit->Name = L"textBox_FPSLimit";
			this->textBox_FPSLimit->Size = System::Drawing::Size(66, 26);
			this->textBox_FPSLimit->TabIndex = 14;
			// 
			// linkLabel_Discord
			// 
			this->linkLabel_Discord->AutoSize = true;
			this->linkLabel_Discord->Location = System::Drawing::Point(60, 315);
			this->linkLabel_Discord->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->linkLabel_Discord->Name = L"linkLabel_Discord";
			this->linkLabel_Discord->Size = System::Drawing::Size(135, 20);
			this->linkLabel_Discord->TabIndex = 15;
			this->linkLabel_Discord->TabStop = true;
			this->linkLabel_Discord->Text = L"Join us at Discord";
			// 
			// tabPage_Components
			// 
			this->tabPage_Components->Controls->Add(this->panel1);
			this->tabPage_Components->Location = System::Drawing::Point(4, 29);
			this->tabPage_Components->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage_Components->Name = L"tabPage_Components";
			this->tabPage_Components->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage_Components->Size = System::Drawing::Size(274, 367);
			this->tabPage_Components->TabIndex = 1;
			this->tabPage_Components->Text = L"Components";
			this->tabPage_Components->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->checkBox_fps_limiter);
			this->panel1->Controls->Add(this->checkBox_scale_component);
			this->panel1->Controls->Add(this->checkBox_camera_controller);
			this->panel1->Controls->Add(this->checkBox_input_emulator);
			this->panel1->Controls->Add(this->checkBox_fast_loader);
			this->panel1->Controls->Add(this->checkBox_touch_slider_emulator);
			this->panel1->Controls->Add(this->checkBox_stage_manager);
			this->panel1->Controls->Add(this->checkBox_touch_panel_emulator);
			this->panel1->Controls->Add(this->checkBox_frame_rate_manager);
			this->panel1->Controls->Add(this->checkBox_sys_timer);
			this->panel1->Controls->Add(this->checkBox_player_data_manager);
			this->panel1->Location = System::Drawing::Point(9, 9);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(256, 340);
			this->panel1->TabIndex = 8;
			// 
			// checkBox_fps_limiter
			// 
			this->checkBox_fps_limiter->AutoSize = true;
			this->checkBox_fps_limiter->Location = System::Drawing::Point(4, 360);
			this->checkBox_fps_limiter->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_fps_limiter->Name = L"checkBox_fps_limiter";
			this->checkBox_fps_limiter->Size = System::Drawing::Size(117, 24);
			this->checkBox_fps_limiter->TabIndex = 10;
			this->checkBox_fps_limiter->Text = L"FPS Limiter";
			this->checkBox_fps_limiter->UseVisualStyleBackColor = true;
			// 
			// checkBox_scale_component
			// 
			this->checkBox_scale_component->AutoSize = true;
			this->checkBox_scale_component->Location = System::Drawing::Point(4, 323);
			this->checkBox_scale_component->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_scale_component->Name = L"checkBox_scale_component";
			this->checkBox_scale_component->Size = System::Drawing::Size(162, 24);
			this->checkBox_scale_component->TabIndex = 9;
			this->checkBox_scale_component->Text = L"Scale Component";
			this->checkBox_scale_component->UseVisualStyleBackColor = true;
			// 
			// checkBox_camera_controller
			// 
			this->checkBox_camera_controller->AutoSize = true;
			this->checkBox_camera_controller->Location = System::Drawing::Point(4, 288);
			this->checkBox_camera_controller->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_camera_controller->Name = L"checkBox_camera_controller";
			this->checkBox_camera_controller->Size = System::Drawing::Size(163, 24);
			this->checkBox_camera_controller->TabIndex = 8;
			this->checkBox_camera_controller->Text = L"Camera Controller";
			this->checkBox_camera_controller->UseVisualStyleBackColor = true;
			// 
			// checkBox_input_emulator
			// 
			this->checkBox_input_emulator->AutoSize = true;
			this->checkBox_input_emulator->Location = System::Drawing::Point(4, 5);
			this->checkBox_input_emulator->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_input_emulator->Name = L"checkBox_input_emulator";
			this->checkBox_input_emulator->Size = System::Drawing::Size(140, 24);
			this->checkBox_input_emulator->TabIndex = 0;
			this->checkBox_input_emulator->Text = L"Input Emulator";
			this->checkBox_input_emulator->UseVisualStyleBackColor = true;
			// 
			// checkBox_fast_loader
			// 
			this->checkBox_fast_loader->AutoSize = true;
			this->checkBox_fast_loader->Location = System::Drawing::Point(4, 252);
			this->checkBox_fast_loader->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_fast_loader->Name = L"checkBox_fast_loader";
			this->checkBox_fast_loader->Size = System::Drawing::Size(121, 24);
			this->checkBox_fast_loader->TabIndex = 7;
			this->checkBox_fast_loader->Text = L"Fast Loader";
			this->checkBox_fast_loader->UseVisualStyleBackColor = true;
			// 
			// checkBox_touch_slider_emulator
			// 
			this->checkBox_touch_slider_emulator->AutoSize = true;
			this->checkBox_touch_slider_emulator->Location = System::Drawing::Point(4, 40);
			this->checkBox_touch_slider_emulator->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_touch_slider_emulator->Name = L"checkBox_touch_slider_emulator";
			this->checkBox_touch_slider_emulator->Size = System::Drawing::Size(191, 24);
			this->checkBox_touch_slider_emulator->TabIndex = 1;
			this->checkBox_touch_slider_emulator->Text = L"Touch Panel Emulator";
			this->checkBox_touch_slider_emulator->UseVisualStyleBackColor = true;
			// 
			// checkBox_stage_manager
			// 
			this->checkBox_stage_manager->AutoSize = true;
			this->checkBox_stage_manager->Location = System::Drawing::Point(4, 217);
			this->checkBox_stage_manager->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_stage_manager->Name = L"checkBox_stage_manager";
			this->checkBox_stage_manager->Size = System::Drawing::Size(145, 24);
			this->checkBox_stage_manager->TabIndex = 6;
			this->checkBox_stage_manager->Text = L"Stage Manager";
			this->checkBox_stage_manager->UseVisualStyleBackColor = true;
			// 
			// checkBox_touch_panel_emulator
			// 
			this->checkBox_touch_panel_emulator->AutoSize = true;
			this->checkBox_touch_panel_emulator->Location = System::Drawing::Point(4, 75);
			this->checkBox_touch_panel_emulator->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_touch_panel_emulator->Name = L"checkBox_touch_panel_emulator";
			this->checkBox_touch_panel_emulator->Size = System::Drawing::Size(191, 24);
			this->checkBox_touch_panel_emulator->TabIndex = 2;
			this->checkBox_touch_panel_emulator->Text = L"Touch Slider Emulator";
			this->checkBox_touch_panel_emulator->UseVisualStyleBackColor = true;
			// 
			// checkBox_frame_rate_manager
			// 
			this->checkBox_frame_rate_manager->AutoSize = true;
			this->checkBox_frame_rate_manager->Location = System::Drawing::Point(4, 182);
			this->checkBox_frame_rate_manager->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_frame_rate_manager->Name = L"checkBox_frame_rate_manager";
			this->checkBox_frame_rate_manager->Size = System::Drawing::Size(187, 24);
			this->checkBox_frame_rate_manager->TabIndex = 5;
			this->checkBox_frame_rate_manager->Text = L"Frame Rate Manager";
			this->checkBox_frame_rate_manager->UseVisualStyleBackColor = true;
			// 
			// checkBox_sys_timer
			// 
			this->checkBox_sys_timer->AutoSize = true;
			this->checkBox_sys_timer->Location = System::Drawing::Point(4, 111);
			this->checkBox_sys_timer->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_sys_timer->Name = L"checkBox_sys_timer";
			this->checkBox_sys_timer->Size = System::Drawing::Size(177, 24);
			this->checkBox_sys_timer->TabIndex = 3;
			this->checkBox_sys_timer->Text = L"Freeze Select Timer";
			this->checkBox_sys_timer->UseVisualStyleBackColor = true;
			// 
			// checkBox_player_data_manager
			// 
			this->checkBox_player_data_manager->AutoSize = true;
			this->checkBox_player_data_manager->Location = System::Drawing::Point(4, 146);
			this->checkBox_player_data_manager->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_player_data_manager->Name = L"checkBox_player_data_manager";
			this->checkBox_player_data_manager->Size = System::Drawing::Size(184, 24);
			this->checkBox_player_data_manager->TabIndex = 4;
			this->checkBox_player_data_manager->Text = L"Player Data Manager";
			this->checkBox_player_data_manager->UseVisualStyleBackColor = true;
			// 
			// ui
			// 
			this->AcceptButton = this->button_Launch;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->CancelButton = this->button_Exit;
			this->ClientSize = System::Drawing::Size(663, 482);
			this->Controls->Add(this->tabControl);
			this->Controls->Add(this->button_Exit);
			this->Controls->Add(this->button_Launch);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ui";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DIVA Launcher";
			this->Load += gcnew System::EventHandler(this, &ui::Ui_Load);
			this->groupBox_ScreenRes->ResumeLayout(false);
			this->groupBox_ScreenRes->PerformLayout();
			this->tabControl->ResumeLayout(false);
			this->tabPage_Resolution->ResumeLayout(false);
			this->groupBox_InternalRes->ResumeLayout(false);
			this->groupBox_InternalRes->PerformLayout();
			this->tabPage_Patches->ResumeLayout(false);
			this->panel_Patches->ResumeLayout(false);
			this->panel_Patches->PerformLayout();
			this->tabPage_Components->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void Ui_Load(System::Object^ sender, System::EventArgs^ e){
}
private: System::Void Button_Exit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	exit(EXIT_SUCCESS);
}
private: System::Void Button_Launch_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ userInput = textBox_Height->Text;
	wstring input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"height", input.c_str(), CONFIG_FILE);

	userInput = textBox_Width->Text;
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"width", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_Fullscreen->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"fullscreen", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_Borderless->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"borderless", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_InternalRes->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"r.enable", input.c_str(), CONFIG_FILE);

	userInput = textBox_intResHeight->Text;
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"r.height", input.c_str(), CONFIG_FILE);

	userInput = textBox_intResWidth->Text;
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"resolution", L"r.width", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_Cursor->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"cursor", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_Stereo->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"stereo", input.c_str(), CONFIG_FILE);
	
	userInput = Convert::ToInt32(checkBox_HideCredits->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"hide_credits", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_HideStatusIcons->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"hide_status_icons", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_HidePVWatermark->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"hide_pv_watermark", input.c_str(), CONFIG_FILE);


	userInput = Convert::ToInt32(checkBox_HideVolCtrl->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"patches", L"hide_volume", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_TAA->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"graphics", L"TAA", input.c_str(), CONFIG_FILE);

	userInput = Convert::ToInt32(checkBox_MLAA->Checked).ToString();
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"graphics", L"MLAA", input.c_str(), CONFIG_FILE);

	userInput = textBox_FPSLimit->Text;
	input = msclr::interop::marshal_as<std::wstring>(userInput);
	WritePrivateProfileStringW(L"graphics", L"FPS.Limit", input.c_str(), CONFIG_FILE);

	STARTUPINFOW si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	CreateProcessW(DIVA_EXECUTABLE, DIVA_EXECUTABLE_LAUNCH, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	this->Close();
	exit(EXIT_SUCCESS);
}
private: System::Void Label_intResWidth_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Label_intResHeight_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Label_Width_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TextBox_Width_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TextBox_Height_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox_HideVolCtrl_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}

