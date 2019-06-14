#pragma once
#include "framework.h"
#include <msclr\marshal_cppstd.h>

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

			// Not working, but saving the settings does works
			checkBox_Stereo->Checked = nStereo;
			checkBox_Cursor->Checked = nCursor;
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
	private: System::Windows::Forms::CheckBox^ checkBox_palyer_data_manager;
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
	private: System::Windows::Forms::Label^ label_help2;
	private: System::Windows::Forms::Label^ label_help1;
	private: System::Windows::Forms::Label^ label_FPSLimit;
	private: System::Windows::Forms::CheckBox^ checkBox_MLAA;
	private: System::Windows::Forms::CheckBox^ checkBox_TAA;
	private: System::Windows::Forms::CheckBox^ checkBox_Cursor;
	private: System::Windows::Forms::LinkLabel^ linkLabel_Discord;
	private: System::Windows::Forms::TextBox^ textBox_Width;
	private: System::Windows::Forms::TextBox^ textBox_Height;
	private: System::Windows::Forms::TextBox^ textBox_intResWidth;
	private: System::Windows::Forms::TextBox^ textBox_intResHeight;
	private: System::Windows::Forms::Label^ label_intResHeight;
	private: System::Windows::Forms::Label^ label_intResWidth;
	private: System::Windows::Forms::TextBox^ textBox_FPSLimit;

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
			this->textBox_FPSLimit = (gcnew System::Windows::Forms::TextBox());
			this->linkLabel_Discord = (gcnew System::Windows::Forms::LinkLabel());
			this->label_help2 = (gcnew System::Windows::Forms::Label());
			this->label_help1 = (gcnew System::Windows::Forms::Label());
			this->label_FPSLimit = (gcnew System::Windows::Forms::Label());
			this->checkBox_MLAA = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_TAA = (gcnew System::Windows::Forms::CheckBox());
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
			this->checkBox_palyer_data_manager = (gcnew System::Windows::Forms::CheckBox());
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
			this->button_Launch->Location = System::Drawing::Point(16, 278);
			this->button_Launch->Name = L"button_Launch";
			this->button_Launch->Size = System::Drawing::Size(75, 23);
			this->button_Launch->TabIndex = 0;
			this->button_Launch->Text = L"Launch";
			this->button_Launch->UseVisualStyleBackColor = true;
			this->button_Launch->Click += gcnew System::EventHandler(this, &ui::Button_Launch_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_Exit->Location = System::Drawing::Point(121, 278);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(75, 23);
			this->button_Exit->TabIndex = 1;
			this->button_Exit->Text = L"Exit";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &ui::Button_Exit_Click);
			// 
			// label_Height
			// 
			this->label_Height->AutoSize = true;
			this->label_Height->Location = System::Drawing::Point(6, 45);
			this->label_Height->Name = L"label_Height";
			this->label_Height->Size = System::Drawing::Size(38, 13);
			this->label_Height->TabIndex = 3;
			this->label_Height->Text = L"Height";
			// 
			// label_Width
			// 
			this->label_Width->AutoSize = true;
			this->label_Width->Location = System::Drawing::Point(6, 22);
			this->label_Width->Name = L"label_Width";
			this->label_Width->Size = System::Drawing::Size(35, 13);
			this->label_Width->TabIndex = 4;
			this->label_Width->Text = L"Width";
			// 
			// groupBox_ScreenRes
			// 
			this->groupBox_ScreenRes->Controls->Add(this->textBox_Width);
			this->groupBox_ScreenRes->Controls->Add(this->textBox_Height);
			this->groupBox_ScreenRes->Controls->Add(this->checkBox_Borderless);
			this->groupBox_ScreenRes->Controls->Add(this->label_Height);
			this->groupBox_ScreenRes->Controls->Add(this->checkBox_Fullscreen);
			this->groupBox_ScreenRes->Controls->Add(this->label_Width);
			this->groupBox_ScreenRes->Location = System::Drawing::Point(10, 6);
			this->groupBox_ScreenRes->Name = L"groupBox_ScreenRes";
			this->groupBox_ScreenRes->Size = System::Drawing::Size(163, 118);
			this->groupBox_ScreenRes->TabIndex = 6;
			this->groupBox_ScreenRes->TabStop = false;
			this->groupBox_ScreenRes->Text = L"Screen Resolution";
			// 
			// textBox_Width
			// 
			this->textBox_Width->Location = System::Drawing::Point(79, 19);
			this->textBox_Width->Name = L"textBox_Width";
			this->textBox_Width->Size = System::Drawing::Size(78, 20);
			this->textBox_Width->TabIndex = 11;
			// 
			// textBox_Height
			// 
			this->textBox_Height->Location = System::Drawing::Point(79, 42);
			this->textBox_Height->Name = L"textBox_Height";
			this->textBox_Height->Size = System::Drawing::Size(78, 20);
			this->textBox_Height->TabIndex = 10;
			// 
			// checkBox_Borderless
			// 
			this->checkBox_Borderless->AutoSize = true;
			this->checkBox_Borderless->Location = System::Drawing::Point(9, 96);
			this->checkBox_Borderless->Name = L"checkBox_Borderless";
			this->checkBox_Borderless->Size = System::Drawing::Size(75, 17);
			this->checkBox_Borderless->TabIndex = 9;
			this->checkBox_Borderless->Text = L"Borderless";
			this->checkBox_Borderless->UseVisualStyleBackColor = true;
			// 
			// checkBox_Fullscreen
			// 
			this->checkBox_Fullscreen->AutoSize = true;
			this->checkBox_Fullscreen->Location = System::Drawing::Point(9, 73);
			this->checkBox_Fullscreen->Name = L"checkBox_Fullscreen";
			this->checkBox_Fullscreen->Size = System::Drawing::Size(74, 17);
			this->checkBox_Fullscreen->TabIndex = 7;
			this->checkBox_Fullscreen->Text = L"Fullscreen";
			this->checkBox_Fullscreen->UseVisualStyleBackColor = true;
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabPage_Resolution);
			this->tabControl->Controls->Add(this->tabPage_Patches);
			this->tabControl->Controls->Add(this->tabPage_Components);
			this->tabControl->Location = System::Drawing::Point(12, 12);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(188, 260);
			this->tabControl->TabIndex = 7;
			// 
			// tabPage_Resolution
			// 
			this->tabPage_Resolution->Controls->Add(this->groupBox_InternalRes);
			this->tabPage_Resolution->Controls->Add(this->groupBox_ScreenRes);
			this->tabPage_Resolution->Location = System::Drawing::Point(4, 22);
			this->tabPage_Resolution->Name = L"tabPage_Resolution";
			this->tabPage_Resolution->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Resolution->Size = System::Drawing::Size(180, 234);
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
			this->groupBox_InternalRes->Location = System::Drawing::Point(10, 130);
			this->groupBox_InternalRes->Name = L"groupBox_InternalRes";
			this->groupBox_InternalRes->Size = System::Drawing::Size(163, 97);
			this->groupBox_InternalRes->TabIndex = 7;
			this->groupBox_InternalRes->TabStop = false;
			this->groupBox_InternalRes->Text = L"Internal Resolution";
			// 
			// textBox_intResWidth
			// 
			this->textBox_intResWidth->Location = System::Drawing::Point(79, 21);
			this->textBox_intResWidth->Name = L"textBox_intResWidth";
			this->textBox_intResWidth->Size = System::Drawing::Size(78, 20);
			this->textBox_intResWidth->TabIndex = 13;
			// 
			// textBox_intResHeight
			// 
			this->textBox_intResHeight->Location = System::Drawing::Point(79, 44);
			this->textBox_intResHeight->Name = L"textBox_intResHeight";
			this->textBox_intResHeight->Size = System::Drawing::Size(78, 20);
			this->textBox_intResHeight->TabIndex = 12;
			// 
			// label_intResHeight
			// 
			this->label_intResHeight->AutoSize = true;
			this->label_intResHeight->Location = System::Drawing::Point(6, 47);
			this->label_intResHeight->Name = L"label_intResHeight";
			this->label_intResHeight->Size = System::Drawing::Size(38, 13);
			this->label_intResHeight->TabIndex = 10;
			this->label_intResHeight->Text = L"Height";
			// 
			// checkBox_InternalRes
			// 
			this->checkBox_InternalRes->AutoSize = true;
			this->checkBox_InternalRes->Location = System::Drawing::Point(9, 73);
			this->checkBox_InternalRes->Name = L"checkBox_InternalRes";
			this->checkBox_InternalRes->Size = System::Drawing::Size(59, 17);
			this->checkBox_InternalRes->TabIndex = 7;
			this->checkBox_InternalRes->Text = L"Enable";
			this->checkBox_InternalRes->UseVisualStyleBackColor = true;
			// 
			// label_intResWidth
			// 
			this->label_intResWidth->AutoSize = true;
			this->label_intResWidth->Location = System::Drawing::Point(6, 24);
			this->label_intResWidth->Name = L"label_intResWidth";
			this->label_intResWidth->Size = System::Drawing::Size(35, 13);
			this->label_intResWidth->TabIndex = 11;
			this->label_intResWidth->Text = L"Width";
			// 
			// tabPage_Patches
			// 
			this->tabPage_Patches->Controls->Add(this->panel_Patches);
			this->tabPage_Patches->Location = System::Drawing::Point(4, 22);
			this->tabPage_Patches->Name = L"tabPage_Patches";
			this->tabPage_Patches->Size = System::Drawing::Size(180, 234);
			this->tabPage_Patches->TabIndex = 2;
			this->tabPage_Patches->Text = L"Patches";
			this->tabPage_Patches->UseVisualStyleBackColor = true;
			// 
			// panel_Patches
			// 
			this->panel_Patches->AutoScroll = true;
			this->panel_Patches->Controls->Add(this->textBox_FPSLimit);
			this->panel_Patches->Controls->Add(this->linkLabel_Discord);
			this->panel_Patches->Controls->Add(this->label_help2);
			this->panel_Patches->Controls->Add(this->label_help1);
			this->panel_Patches->Controls->Add(this->label_FPSLimit);
			this->panel_Patches->Controls->Add(this->checkBox_MLAA);
			this->panel_Patches->Controls->Add(this->checkBox_TAA);
			this->panel_Patches->Controls->Add(this->checkBox_Cursor);
			this->panel_Patches->Controls->Add(this->checkBox_Stereo);
			this->panel_Patches->Location = System::Drawing::Point(6, 6);
			this->panel_Patches->Name = L"panel_Patches";
			this->panel_Patches->Size = System::Drawing::Size(174, 221);
			this->panel_Patches->TabIndex = 9;
			// 
			// textBox_FPSLimit
			// 
			this->textBox_FPSLimit->Location = System::Drawing::Point(57, 95);
			this->textBox_FPSLimit->Name = L"textBox_FPSLimit";
			this->textBox_FPSLimit->Size = System::Drawing::Size(45, 20);
			this->textBox_FPSLimit->TabIndex = 11;
			// 
			// linkLabel_Discord
			// 
			this->linkLabel_Discord->AutoSize = true;
			this->linkLabel_Discord->Location = System::Drawing::Point(40, 183);
			this->linkLabel_Discord->Name = L"linkLabel_Discord";
			this->linkLabel_Discord->Size = System::Drawing::Size(91, 13);
			this->linkLabel_Discord->TabIndex = 10;
			this->linkLabel_Discord->TabStop = true;
			this->linkLabel_Discord->Text = L"Join us at Discord";
			// 
			// label_help2
			// 
			this->label_help2->AutoSize = true;
			this->label_help2->Location = System::Drawing::Point(4, 150);
			this->label_help2->Name = L"label_help2";
			this->label_help2->Size = System::Drawing::Size(133, 13);
			this->label_help2->TabIndex = 7;
			this->label_help2->Text = L"Pull requests are welcome.";
			// 
			// label_help1
			// 
			this->label_help1->AutoSize = true;
			this->label_help1->Location = System::Drawing::Point(4, 134);
			this->label_help1->Name = L"label_help1";
			this->label_help1->Size = System::Drawing::Size(149, 13);
			this->label_help1->TabIndex = 6;
			this->label_help1->Text = L"Help us improve this launcher.";
			// 
			// label_FPSLimit
			// 
			this->label_FPSLimit->AutoSize = true;
			this->label_FPSLimit->Location = System::Drawing::Point(0, 100);
			this->label_FPSLimit->Name = L"label_FPSLimit";
			this->label_FPSLimit->Size = System::Drawing::Size(51, 13);
			this->label_FPSLimit->TabIndex = 5;
			this->label_FPSLimit->Text = L"FPS Limit";
			// 
			// checkBox_MLAA
			// 
			this->checkBox_MLAA->AutoSize = true;
			this->checkBox_MLAA->Location = System::Drawing::Point(3, 72);
			this->checkBox_MLAA->Name = L"checkBox_MLAA";
			this->checkBox_MLAA->Size = System::Drawing::Size(55, 17);
			this->checkBox_MLAA->TabIndex = 3;
			this->checkBox_MLAA->Text = L"MLAA";
			this->checkBox_MLAA->UseVisualStyleBackColor = true;
			// 
			// checkBox_TAA
			// 
			this->checkBox_TAA->AutoSize = true;
			this->checkBox_TAA->Location = System::Drawing::Point(3, 49);
			this->checkBox_TAA->Name = L"checkBox_TAA";
			this->checkBox_TAA->Size = System::Drawing::Size(47, 17);
			this->checkBox_TAA->TabIndex = 2;
			this->checkBox_TAA->Text = L"TAA";
			this->checkBox_TAA->UseVisualStyleBackColor = true;
			// 
			// checkBox_Cursor
			// 
			this->checkBox_Cursor->AutoSize = true;
			this->checkBox_Cursor->Location = System::Drawing::Point(3, 26);
			this->checkBox_Cursor->Name = L"checkBox_Cursor";
			this->checkBox_Cursor->Size = System::Drawing::Size(56, 17);
			this->checkBox_Cursor->TabIndex = 1;
			this->checkBox_Cursor->Text = L"Cursor";
			this->checkBox_Cursor->UseVisualStyleBackColor = true;
			// 
			// checkBox_Stereo
			// 
			this->checkBox_Stereo->AutoSize = true;
			this->checkBox_Stereo->Location = System::Drawing::Point(3, 3);
			this->checkBox_Stereo->Name = L"checkBox_Stereo";
			this->checkBox_Stereo->Size = System::Drawing::Size(57, 17);
			this->checkBox_Stereo->TabIndex = 0;
			this->checkBox_Stereo->Text = L"Stereo";
			this->checkBox_Stereo->UseVisualStyleBackColor = true;
			// 
			// tabPage_Components
			// 
			this->tabPage_Components->Controls->Add(this->panel1);
			this->tabPage_Components->Location = System::Drawing::Point(4, 22);
			this->tabPage_Components->Name = L"tabPage_Components";
			this->tabPage_Components->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Components->Size = System::Drawing::Size(180, 234);
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
			this->panel1->Controls->Add(this->checkBox_palyer_data_manager);
			this->panel1->Location = System::Drawing::Point(6, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(171, 221);
			this->panel1->TabIndex = 8;
			// 
			// checkBox_fps_limiter
			// 
			this->checkBox_fps_limiter->AutoSize = true;
			this->checkBox_fps_limiter->Location = System::Drawing::Point(3, 234);
			this->checkBox_fps_limiter->Name = L"checkBox_fps_limiter";
			this->checkBox_fps_limiter->Size = System::Drawing::Size(79, 17);
			this->checkBox_fps_limiter->TabIndex = 10;
			this->checkBox_fps_limiter->Text = L"FPS Limiter";
			this->checkBox_fps_limiter->UseVisualStyleBackColor = true;
			// 
			// checkBox_scale_component
			// 
			this->checkBox_scale_component->AutoSize = true;
			this->checkBox_scale_component->Location = System::Drawing::Point(3, 210);
			this->checkBox_scale_component->Name = L"checkBox_scale_component";
			this->checkBox_scale_component->Size = System::Drawing::Size(110, 17);
			this->checkBox_scale_component->TabIndex = 9;
			this->checkBox_scale_component->Text = L"Scale Component";
			this->checkBox_scale_component->UseVisualStyleBackColor = true;
			// 
			// checkBox_camera_controller
			// 
			this->checkBox_camera_controller->AutoSize = true;
			this->checkBox_camera_controller->Location = System::Drawing::Point(3, 187);
			this->checkBox_camera_controller->Name = L"checkBox_camera_controller";
			this->checkBox_camera_controller->Size = System::Drawing::Size(109, 17);
			this->checkBox_camera_controller->TabIndex = 8;
			this->checkBox_camera_controller->Text = L"Camera Controller";
			this->checkBox_camera_controller->UseVisualStyleBackColor = true;
			// 
			// checkBox_input_emulator
			// 
			this->checkBox_input_emulator->AutoSize = true;
			this->checkBox_input_emulator->Location = System::Drawing::Point(3, 3);
			this->checkBox_input_emulator->Name = L"checkBox_input_emulator";
			this->checkBox_input_emulator->Size = System::Drawing::Size(94, 17);
			this->checkBox_input_emulator->TabIndex = 0;
			this->checkBox_input_emulator->Text = L"Input Emulator";
			this->checkBox_input_emulator->UseVisualStyleBackColor = true;
			// 
			// checkBox_fast_loader
			// 
			this->checkBox_fast_loader->AutoSize = true;
			this->checkBox_fast_loader->Location = System::Drawing::Point(3, 164);
			this->checkBox_fast_loader->Name = L"checkBox_fast_loader";
			this->checkBox_fast_loader->Size = System::Drawing::Size(82, 17);
			this->checkBox_fast_loader->TabIndex = 7;
			this->checkBox_fast_loader->Text = L"Fast Loader";
			this->checkBox_fast_loader->UseVisualStyleBackColor = true;
			// 
			// checkBox_touch_slider_emulator
			// 
			this->checkBox_touch_slider_emulator->AutoSize = true;
			this->checkBox_touch_slider_emulator->Location = System::Drawing::Point(3, 26);
			this->checkBox_touch_slider_emulator->Name = L"checkBox_touch_slider_emulator";
			this->checkBox_touch_slider_emulator->Size = System::Drawing::Size(131, 17);
			this->checkBox_touch_slider_emulator->TabIndex = 1;
			this->checkBox_touch_slider_emulator->Text = L"Touch Panel Emulator";
			this->checkBox_touch_slider_emulator->UseVisualStyleBackColor = true;
			// 
			// checkBox_stage_manager
			// 
			this->checkBox_stage_manager->AutoSize = true;
			this->checkBox_stage_manager->Location = System::Drawing::Point(3, 141);
			this->checkBox_stage_manager->Name = L"checkBox_stage_manager";
			this->checkBox_stage_manager->Size = System::Drawing::Size(99, 17);
			this->checkBox_stage_manager->TabIndex = 6;
			this->checkBox_stage_manager->Text = L"Stage Manager";
			this->checkBox_stage_manager->UseVisualStyleBackColor = true;
			// 
			// checkBox_touch_panel_emulator
			// 
			this->checkBox_touch_panel_emulator->AutoSize = true;
			this->checkBox_touch_panel_emulator->Location = System::Drawing::Point(3, 49);
			this->checkBox_touch_panel_emulator->Name = L"checkBox_touch_panel_emulator";
			this->checkBox_touch_panel_emulator->Size = System::Drawing::Size(130, 17);
			this->checkBox_touch_panel_emulator->TabIndex = 2;
			this->checkBox_touch_panel_emulator->Text = L"Touch Slider Emulator";
			this->checkBox_touch_panel_emulator->UseVisualStyleBackColor = true;
			// 
			// checkBox_frame_rate_manager
			// 
			this->checkBox_frame_rate_manager->AutoSize = true;
			this->checkBox_frame_rate_manager->Location = System::Drawing::Point(3, 118);
			this->checkBox_frame_rate_manager->Name = L"checkBox_frame_rate_manager";
			this->checkBox_frame_rate_manager->Size = System::Drawing::Size(126, 17);
			this->checkBox_frame_rate_manager->TabIndex = 5;
			this->checkBox_frame_rate_manager->Text = L"Frame Rate Manager";
			this->checkBox_frame_rate_manager->UseVisualStyleBackColor = true;
			// 
			// checkBox_sys_timer
			// 
			this->checkBox_sys_timer->AutoSize = true;
			this->checkBox_sys_timer->Location = System::Drawing::Point(3, 72);
			this->checkBox_sys_timer->Name = L"checkBox_sys_timer";
			this->checkBox_sys_timer->Size = System::Drawing::Size(120, 17);
			this->checkBox_sys_timer->TabIndex = 3;
			this->checkBox_sys_timer->Text = L"Freeze Select Timer";
			this->checkBox_sys_timer->UseVisualStyleBackColor = true;
			// 
			// checkBox_palyer_data_manager
			// 
			this->checkBox_palyer_data_manager->AutoSize = true;
			this->checkBox_palyer_data_manager->Location = System::Drawing::Point(3, 95);
			this->checkBox_palyer_data_manager->Name = L"checkBox_palyer_data_manager";
			this->checkBox_palyer_data_manager->Size = System::Drawing::Size(126, 17);
			this->checkBox_palyer_data_manager->TabIndex = 4;
			this->checkBox_palyer_data_manager->Text = L"Player Data Manager";
			this->checkBox_palyer_data_manager->UseVisualStyleBackColor = true;
			// 
			// ui
			// 
			this->AcceptButton = this->button_Launch;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->button_Exit;
			this->ClientSize = System::Drawing::Size(210, 313);
			this->ControlBox = false;
			this->Controls->Add(this->tabControl);
			this->Controls->Add(this->button_Exit);
			this->Controls->Add(this->button_Launch);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
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
	exit(1);
}
private: System::Void Button_Launch_Click(System::Object^ sender, System::EventArgs^ e) {
	// Working fine, but reading the settings are not working

	String^ userInput = textBox_Height->Text;
	string input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("resolution", "height", input.c_str(), CONFIG_FILE);

	userInput = textBox_Width->Text;
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("resolution", "width", input.c_str(), CONFIG_FILE);

	userInput = checkBox_Fullscreen->Checked.ToString();
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("resolution", "fullscreen", input.c_str(), CONFIG_FILE);

	userInput = checkBox_Borderless->Checked.ToString();
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("resolution", "borderless", input.c_str(), CONFIG_FILE);

	userInput = checkBox_InternalRes->Checked.ToString();
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("resolution", "r.enable", input.c_str(), CONFIG_FILE);

	userInput = textBox_intResHeight->Text;
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("resolution", "r.height", input.c_str(), CONFIG_FILE);

	userInput = textBox_intResWidth->Text;
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("resolution", "r.width", input.c_str(), CONFIG_FILE);

	userInput = checkBox_Cursor->Checked.ToString();
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("patches", "cursor", input.c_str(), CONFIG_FILE);

	userInput = checkBox_Stereo->Checked.ToString();
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("patches", "stereo", input.c_str(), CONFIG_FILE);

	userInput = checkBox_TAA->Checked.ToString();
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("graphics", "TAA", input.c_str(), CONFIG_FILE);

	userInput = checkBox_MLAA->Checked.ToString();
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("graphics", "MLAA", input.c_str(), CONFIG_FILE);

	userInput = textBox_FPSLimit->Text;
	input = msclr::interop::marshal_as<std::string>(userInput);
	WritePrivateProfileString("graphics", "FPS.Limit", input.c_str(), CONFIG_FILE);

	// Not working?
	if (CreateProcess(DIVA_EXECUTABLE, DIVA_EXECUTABLE_LAUNCH, 0, 0, false, DETACHED_PROCESS, 0, 0, NULL, NULL))

	exit(1);
}
};
}

