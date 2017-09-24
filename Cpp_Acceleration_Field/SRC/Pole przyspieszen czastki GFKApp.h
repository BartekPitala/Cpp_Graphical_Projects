//---------------------------------------------------------------------------
//
// Name:        Pole przyspieszen czastki GFKApp.h
// Author:      Pitala&Marszalek&Matuszewski
// Created:     29.05.2017 14:04:33
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __POLE_PRZYSPIESZEN_CZASTKI_GFKFRMApp_h__
#define __POLE_PRZYSPIESZEN_CZASTKI_GFKFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class Pole_przyspieszen_czastki_GFKFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
