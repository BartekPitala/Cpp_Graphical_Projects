///-----------------------------------------------------------------
///
/// @file      InitialScreenDlg.cpp
/// @author    Pitala&Marszalek&Matuszewski
/// Created:   2017-06-14 20:55:17
/// @section   DESCRIPTION
///            InitialScreenDlg class implementation
///
///------------------------------------------------------------------

#include "InitialScreenDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// InitialScreenDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(InitialScreenDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(InitialScreenDlg::OnClose)
	EVT_ACTIVATE(InitialScreenDlg::InitialScreenDlgActivate)
	EVT_BUTTON(ID_RETURNBUTTON_1,InitialScreenDlg::ReturnButton_1Click)
	
	EVT_UPDATE_UI(ID_INITIALPANEL,InitialScreenDlg::InitialPanelUpdateUI)
	EVT_BUTTON(ID_RETURNBUTTON,InitialScreenDlg::ReturnButtonClick)
END_EVENT_TABLE()
////Event Table End

InitialScreenDlg::InitialScreenDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
	background_bitmap.Create(InitialPanel->GetSize().x,InitialPanel->GetSize().y);
}

InitialScreenDlg::~InitialScreenDlg()
{
} 

void InitialScreenDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	ReturnButton = new wxButton(this, ID_RETURNBUTTON, _("Return"), wxPoint(459, 750), wxSize(75, 25), 0, wxDefaultValidator, _("ReturnButton"));

	InitialPanel = new wxPanel(this, ID_INITIALPANEL, wxPoint(0, 0), wxSize(1024, 690));

	ReturnButton_1 = new wxButton(this, ID_RETURNBUTTON_1, _("START"), wxPoint(461, 700), wxSize(75, 25), 0, wxDefaultValidator, _("ReturnButton_1"));

	SetTitle(_("Initial Screen"));
	SetIcon(wxNullIcon);
	SetSize(-2,-29,1024,768);
	Center();
	
	////GUI Items Creation End
	SetSize(8,8,1024,768);
	Center();
	wxInitAllImageHandlers();
}

void InitialScreenDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * ReturnButtonClick
 */
void InitialScreenDlg::ReturnButtonClick(wxCommandEvent& event)
{
	for(int i=255; i>=150; i--)
	{
        wxTopLevelWindow::SetTransparent(i);
        usleep(21370);
    }
    EndModal(wxID_OK);

}

void InitialScreenDlg::DrawBackground()
{

        wxClientDC dc(InitialPanel);
        
	    background_image.LoadFile("tlo.png" ,wxBITMAP_TYPE_PNG);
        background_image.Rescale(1024,690);
        background_bitmap=wxBitmap(background_image);
        
        dc.DrawBitmap(background_bitmap,0,0);    
    
}    

/*
 * InitialScreenDlgActivate
 */
void InitialScreenDlg::InitialScreenDlgActivate(wxActivateEvent& event)
{
	// insert your code here
}

/*
 * ReturnButton_1Click
 */
void InitialScreenDlg::ReturnButton_1Click(wxCommandEvent& event)
{   
	for(int i=255; i>=150; i--)
	{
        wxTopLevelWindow::SetTransparent(i);
        usleep(21370);
    }
    EndModal(wxID_OK);
}

/*
 * InitialPanelUpdateUI
 */
void InitialScreenDlg::InitialPanelUpdateUI(wxUpdateUIEvent& event)
{
	DrawBackground();
}
