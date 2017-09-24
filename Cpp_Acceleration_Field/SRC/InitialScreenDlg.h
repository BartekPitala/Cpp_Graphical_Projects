///-----------------------------------------------------------------
///
/// @file      InitialScreenDlg.h
/// @author    Pitala&Marszalek&Matuszewski
/// Created:   2017-06-14 20:55:17
/// @section   DESCRIPTION
///            InitialScreenDlg class declaration
///
///------------------------------------------------------------------

#ifndef __INITIALSCREENDLG_H__
#define __INITIALSCREENDLG_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/panel.h>
#include <wx/button.h>
////Header Include End
#include <unistd.h>
////Dialog Style Start
#undef InitialScreenDlg_STYLE
#define InitialScreenDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class InitialScreenDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		InitialScreenDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Initial Screen"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = InitialScreenDlg_STYLE);
		virtual ~InitialScreenDlg();
		void ReturnButtonClick(wxCommandEvent& event);
		void InitialScreenDlgActivate(wxActivateEvent& event);
		void ReturnButton_1Click(wxCommandEvent& event);
		void InitialPanelUpdateUI(wxUpdateUIEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *ReturnButton_1;
		wxPanel *InitialPanel;
		wxButton *ReturnButton;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_RETURNBUTTON_1 = 1004,
			ID_INITIALPANEL = 1003,
			ID_RETURNBUTTON = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		void DrawBackground();
		wxImage background_image;
        wxBitmap background_bitmap;
};

#endif
