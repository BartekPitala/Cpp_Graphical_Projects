///-----------------------------------------------------------------
///
/// @file      Pole przyspieszen czastki GFKFrm.h
/// @author    Pitala&Marszalek&Matuszewski
/// Created:   29.05.2017 14:04:34
/// @section   DESCRIPTION
///            Pole_przyspieszen_czastki_GFKFrm class declaration
///
///------------------------------------------------------------------

#ifndef __POLE_PRZYSPIESZEN_CZASTKI_GFKFRM_H__
#define __POLE_PRZYSPIESZEN_CZASTKI_GFKFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif


//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/scrolbar.h>
#include <wx/button.h>
#include <wx/panel.h>
////Header Include End
#include "HelpDlg.h"
#include "InitialScreenDlg.h"
////Dialog Style Start
#undef Pole_przyspieszen_czastki_GFKFrm_STYLE
#define Pole_przyspieszen_czastki_GFKFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class Pole_przyspieszen_czastki_GFKFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		Pole_przyspieszen_czastki_GFKFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Pole przyspieszen czastki GFK"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Pole_przyspieszen_czastki_GFKFrm_STYLE);
		virtual ~Pole_przyspieszen_czastki_GFKFrm();
		void MapPanelUpdateUI(wxUpdateUIEvent& event);
		void SaveButtonClick(wxCommandEvent& event);
		void TimeBarScroll(wxScrollEvent& event);
		void VectorsButtonClick(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void Pole_przyspieszen_czastki_GFKFrmActivate(wxActivateEvent& event);
		void SurfaceChoiceSelected(wxCommandEvent& event );
		void ContoursBarScroll(wxScrollEvent& event);
		void BallButtonClick(wxCommandEvent& event);
		void HelpButtonClick(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText3;
		wxDirDialog *DirDialog;
		wxFileDialog *SaveDialog;
		wxButton *HelpButton;
		wxButton *BallButton;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxScrollBar *ContoursBar;
		wxChoice *SurfaceChoice;
		wxButton *FramesButton;
		wxButton *VectorsButton;
		wxScrollBar *TimeBar;
		wxButton *SaveButton;
		wxPanel *MapPanel;
		////GUI Control Declaration End
		
		struct Point
		{
            int x;
            int y;
            float value;
        };    
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT3 = 1016,
			ID_HELPBUTTON = 1015,
			ID_BALLBUTTON = 1012,
			ID_WXSTATICTEXT2 = 1011,
			ID_WXSTATICTEXT1 = 1010,
			ID_CONTOURSBAR = 1009,
			ID_SURFACECHOICE = 1008,
			ID_FRAMESBUTTON = 1007,
			ID_VECTORSBUTTON = 1006,
			ID_TIMEBAR = 1005,
			ID_SAVEBUTTON = 1003,
			ID_MAPPANEL = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	protected:
        /** Y Coordinate of the highest point of map */
        int y_coordinates_max;
        /** X Coordinate of the highest point of map */
		int x_coordinates_max;
		/** Number of contours shown on the map */
		int NoLevels;
		/** Variable modifying the surface */
		int time;
		/** Variable defining the maximum scroll value of the time scrollbar */
		int scroll;
		
		/** Array containing every pixel's data on the drawing panel*/
        float **board;
        /** Minimal height value*/
		float min;
		/** Maximal height value */
		float max;
		
		/** Variable defining if the vectors are present on the map*/
		bool draw_vectors;
		/** Variable defining if the moving ball animation should be present on the map*/
		bool draw_ball;
		
		/** Array of points included in acceleration vectors computations*/
		Point points[1400];
		
		/** Image of the ball from which a bitmap is made*/
		wxImage ball_image;
		/** Bitmap with ball drawn on the map*/
        wxBitmap ball_bitmap;
        /** Main bitmap presenting the colored map with contours*/
        wxBitmap ContourBitMap;
        /** Bitmap overlaying the contour map, responsible for drawing the vectors */
		wxBitmap VectorBitMap;
		
	   /** Dialog box containing vital information about the program and how to use it*/
		HelpDlg* help;
		/** Initial screen window, displayed at the start up of program*/
		InitialScreenDlg* initial_screen;
		
		
		/** First surface function, returning the Z-coordinate of a (x,y) point*/
		float fun1(int x, int y);
		/** X derivative of the first surface function in the (x,y) point*/
		float fun_1_deriv_x(int x, int y);
		/** Y derivative of the first surface function in the (x,y) point */
		float fun_1_deriv_y(int x, int y);
		/** Second surface function, returning the Z-coordinate of a (x,y) point*/
		float fun2(int x , int y);
		/** X derivative of the second surface function in the (x,y) point*/
		float fun_2_deriv_x(int x, int y);
		/** Y derivative of the second surface function in the (x,y) point*/
		float fun_2_deriv_y(int x, int y);
		
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		/** Method responsible for drawing the map*/
		void DrawMap();
		/** Method responsible for drawing the contours on the map \n dc - drawing context used to draw the map\n
     	*  N - amount of contours that are to be placed on the map\n min - minimal height value on the map \n max - maximal height value on the map*/
		void DrawContour(wxDC &dc,int N,float min, float max);
		/** Method analysing the Z-coordinates of points and deciding if a contour should be drawn between them\n dc - drawing context used to draw the contours
		*\n x - X coordinate of a point\n y - Y coordinate of a point\n code - variable defining positioning of the contours*/
		void putContour(wxDC &dc, int x, int y, int code);
		/** Method responsible for drawing vectors on the contour map */
		void DrawVectors();
		/** Method responsible for drawing vectors on contour map saved to a file*/
		void DrawVectorsToFile();	
		/** Method preparing a displayed map to be saved to a file as contours + vectors\n dc - drawing context from which a map is taken*/
		void PrepareToSave(wxMemoryDC &dc);
		/** Method responsible for drawing an arrow (vector) between given points (x1,y1) and (x2,y2)*/
		void DrawArrow(wxDC& dc , int x1 , int y1 , int x2 , int y2);
		/** Method responsible for displaying the ball on the drawn map\n dc - drawing context on which the ball should be displayed
		*\n x - X coordinate of the ball position\n y - Y coordinate of the ball position */
		void DrawBall(wxDC& dc , float x, float y);
		

};

#endif
