///-----------------------------------------------------------------
///
/// @file      HelpDlg.cpp
/// @author    Pitala&Marszalek&Matuszewski
/// Created:   2017-06-14 20:46:45
/// @section   DESCRIPTION
///            HelpDlg class implementation
///
///------------------------------------------------------------------

#include "HelpDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// HelpDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(HelpDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(HelpDlg::OnClose)
	EVT_BUTTON(ID_RETURNBUTTON,HelpDlg::ReturnButtonClick)
END_EVENT_TABLE()
////Event Table End

HelpDlg::HelpDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

HelpDlg::~HelpDlg()
{
} 

void HelpDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxRichTextCtrl1 = new wxRichTextCtrl(this, ID_WXRICHTEXTCTRL1, _(""), wxPoint(13, 14), wxSize(979, 601), 0, wxDefaultValidator, _("WxRichTextCtrl1"));
	WxRichTextCtrl1->LoadFile("bla.txt");
	WxRichTextCtrl1->SetMaxLength(0);
	WxRichTextCtrl1->SetBackgroundColour(wxColour(255,255,128));
	WxRichTextCtrl1->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxNORMAL, false, _("Tahoma")));

	ReturnButton = new wxButton(this, ID_RETURNBUTTON, _("Return"), wxPoint(495, 625), wxSize(75, 25), 0, wxDefaultValidator, _("ReturnButton"));
	ReturnButton->SetBackgroundColour(wxColour(255,0,0));

	SetTitle(_("Help"));
	SetIcon(wxNullIcon);
	SetSize(8,8,1024,768);
	Center();
	
	////GUI Items Creation End
	SetSize(8,8,1024,768);
	Center();
}

void HelpDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxButton1Click
 */
void HelpDlg::WxButton1Click(wxCommandEvent& event)
{
	EndModal(wxID_OK);
}

/*
 * ReturnButtonClick
 */
void HelpDlg::ReturnButtonClick(wxCommandEvent& event)
{
	EndModal(wxID_OK);
}
