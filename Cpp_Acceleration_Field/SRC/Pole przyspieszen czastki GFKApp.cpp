//---------------------------------------------------------------------------
//
// Name:        Pole przyspieszen czastki GFKApp.cpp
// Author:      Pitala&Marszalek&Matuszewski
// Created:     29.05.2017 14:04:33
// Description: 
//
//---------------------------------------------------------------------------

#include "Pole przyspieszen czastki GFKApp.h"
#include "Pole przyspieszen czastki GFKFrm.h"

IMPLEMENT_APP(Pole_przyspieszen_czastki_GFKFrmApp)

bool Pole_przyspieszen_czastki_GFKFrmApp::OnInit()
{
    Pole_przyspieszen_czastki_GFKFrm* frame = new Pole_przyspieszen_czastki_GFKFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int Pole_przyspieszen_czastki_GFKFrmApp::OnExit()
{
	return 0;
}
