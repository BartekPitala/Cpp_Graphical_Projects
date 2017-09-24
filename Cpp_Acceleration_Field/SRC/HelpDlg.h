///-----------------------------------------------------------------
///
/// @file      HelpDlg.h
/// @author    Pitala&Marszalek&Matuszewski
/// Created:   2017-06-14 20:46:45
/// @section   DESCRIPTION
///            HelpDlg class declaration
///
///------------------------------------------------------------------

#ifndef __HELPDLG_H__
#define __HELPDLG_H__

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
#include <wx/richtext/richtextctrl.h>
#include <wx/button.h>
////Header Include End

////Dialog Style Start
#undef HelpDlg_STYLE
#define HelpDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class HelpDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		HelpDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Help"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = HelpDlg_STYLE);
		virtual ~HelpDlg();
		void WxButton1Click(wxCommandEvent& event);
		void ReturnButtonClick(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxRichTextCtrl *WxRichTextCtrl1;
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
			ID_WXRICHTEXTCTRL1 = 1005,
			ID_RETURNBUTTON = 1004,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
