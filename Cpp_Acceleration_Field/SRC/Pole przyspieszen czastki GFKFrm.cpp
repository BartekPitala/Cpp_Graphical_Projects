///-----------------------------------------------------------------
///
/// @file      Pole przyspieszen czastki GFKFrm.cpp
/// @author    Pitala&Marszalek&Matuszewski
/// Created:   29.05.2017 14:04:34
/// @section   DESCRIPTION
///            Pole_przyspieszen_czastki_GFKFrm class implementation
///
///------------------------------------------------------------------

#include "Pole przyspieszen czastki GFKFrm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
#include <wx/dcbuffer.h>
//----------------------------------------------------------------------------
// Pole_przyspieszen_czastki_GFKFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Pole_przyspieszen_czastki_GFKFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Pole_przyspieszen_czastki_GFKFrm::OnClose)
	EVT_ACTIVATE(Pole_przyspieszen_czastki_GFKFrm::Pole_przyspieszen_czastki_GFKFrmActivate)
	EVT_BUTTON(ID_HELPBUTTON,Pole_przyspieszen_czastki_GFKFrm::HelpButtonClick)
	EVT_BUTTON(ID_BALLBUTTON,Pole_przyspieszen_czastki_GFKFrm::BallButtonClick)
	
	EVT_COMMAND_SCROLL(ID_CONTOURSBAR,Pole_przyspieszen_czastki_GFKFrm::ContoursBarScroll)
	EVT_CHOICE(ID_SURFACECHOICE,Pole_przyspieszen_czastki_GFKFrm::SurfaceChoiceSelected)
	EVT_BUTTON(ID_FRAMESBUTTON,Pole_przyspieszen_czastki_GFKFrm::WxButton1Click)
	EVT_BUTTON(ID_VECTORSBUTTON,Pole_przyspieszen_czastki_GFKFrm::VectorsButtonClick)
	
	EVT_COMMAND_SCROLL(ID_TIMEBAR,Pole_przyspieszen_czastki_GFKFrm::TimeBarScroll)
	EVT_BUTTON(ID_SAVEBUTTON,Pole_przyspieszen_czastki_GFKFrm::SaveButtonClick)
	
	EVT_UPDATE_UI(ID_MAPPANEL,Pole_przyspieszen_czastki_GFKFrm::MapPanelUpdateUI)
END_EVENT_TABLE()
////Event Table End

Pole_przyspieszen_czastki_GFKFrm::Pole_przyspieszen_czastki_GFKFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
	ContourBitMap.Create(MapPanel->GetSize().x,MapPanel->GetSize().y);
	VectorBitMap.Create(MapPanel->GetSize().x,MapPanel->GetSize().y);
	draw_vectors=true;
	NoLevels=5;
	time = 0;
	min=200;
    max=-200;
}

Pole_przyspieszen_czastki_GFKFrm::~Pole_przyspieszen_czastki_GFKFrm()
{
    
}

void Pole_przyspieszen_czastki_GFKFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	/* s
	se
	*/
	MapPanel = new wxPanel(this, ID_MAPPANEL, wxPoint(20, 12), wxSize(800, 700));

	SaveButton = new wxButton(this, ID_SAVEBUTTON, _("SAVE to BMP"), wxPoint(834, 107), wxSize(145, 72), 0, wxDefaultValidator, _("SaveButton"));
	SaveButton->Enable(false);
	SaveButton->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Tahoma")));

	TimeBar = new wxScrollBar(this, ID_TIMEBAR, wxPoint(834, 225), wxSize(145, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("TimeBar"));
	TimeBar->Enable(false);

	VectorsButton = new wxButton(this, ID_VECTORSBUTTON, _("VECTORS ON/OFF"), wxPoint(834, 312), wxSize(145, 71), 0, wxDefaultValidator, _("VectorsButton"));
	VectorsButton->Enable(false);
	VectorsButton->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Tahoma")));

	FramesButton = new wxButton(this, ID_FRAMESBUTTON, _("Generate frames"), wxPoint(834, 398), wxSize(145, 25), 0, wxDefaultValidator, _("FramesButton"));
	FramesButton->Enable(false);
	FramesButton->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Tahoma")));

	wxArrayString arrayStringFor_SurfaceChoice;
	arrayStringFor_SurfaceChoice.Add(_("Surface 1"));
	arrayStringFor_SurfaceChoice.Add(_("Surface 2"));
	SurfaceChoice = new wxChoice(this, ID_SURFACECHOICE, wxPoint(834, 57), wxSize(145, 22), arrayStringFor_SurfaceChoice, 0, wxDefaultValidator, _("SurfaceChoice"));
	SurfaceChoice->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Tahoma")));
	SurfaceChoice->SetSelection(-1);

	ContoursBar = new wxScrollBar(this, ID_CONTOURSBAR, wxPoint(834, 276), wxSize(145, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("ContoursBar"));
	ContoursBar->Enable(false);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("          Timeline         "), wxPoint(834, 195), wxDefaultSize, 0, _("WxStaticText1"));
	WxStaticText1->SetBackgroundColour(wxColour(255,0,0));
	WxStaticText1->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Tahoma")));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("  Number of contours "), wxPoint(834, 254), wxDefaultSize, 0, _("WxStaticText2"));
	WxStaticText2->SetBackgroundColour(wxColour(255,0,0));
	WxStaticText2->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Tahoma")));

	BallButton = new wxButton(this, ID_BALLBUTTON, _("BALL ON/OFF"), wxPoint(834, 445), wxSize(145, 52), 0, wxDefaultValidator, _("BallButton"));
	BallButton->Enable(false);
	BallButton->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Tahoma")));

	HelpButton = new wxButton(this, ID_HELPBUTTON, _("Help and About"), wxPoint(834, 508), wxSize(145, 25), 0, wxDefaultValidator, _("HelpButton"));
	HelpButton->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Tahoma")));

	SaveDialog =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.bmp"), wxFD_SAVE);

	DirDialog =  new wxDirDialog(this, _("Choose a directory"), _(""));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("  Choose a surface    "), wxPoint(834, 37), wxDefaultSize, 0, _("WxStaticText3"));
	WxStaticText3->SetBackgroundColour(wxColour(255,0,0));
	WxStaticText3->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Tahoma")));

	SetTitle(_("Pole przyspieszen czastki GFK"));
	SetIcon(wxNullIcon);
	SetSize(8,8,1024,768);
	Center();
	
	////GUI Items Creation End
	initial_screen = new InitialScreenDlg(this);
	initial_screen->ShowModal();
	wxInitAllImageHandlers(); 
	scroll = 20;
	TimeBar->SetScrollbar(0,0,scroll,1);
	ContoursBar->SetScrollbar(0,0,6,1);
	board = new float*[MapPanel->GetSize().x];
	for(int i=0; i<MapPanel->GetSize().x; i++)
	   board[i] = new float[MapPanel->GetSize().y];
}

void Pole_przyspieszen_czastki_GFKFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void Pole_przyspieszen_czastki_GFKFrm::putContour(wxDC &dc, int x, int y, int code){
    dc.SetPen(*wxBLACK_PEN);
    switch(code){
        case 0:
            break;
        case 1:
            dc.DrawLine(x - 1, y, x, y + 1);
            break;
        case 2:
            dc.DrawLine(x, y + 1, x + 1, y);
            break;
        case 3:
            dc.DrawLine(x - 1, y, x + 1, y);
            break;
        case 4:
            dc.DrawLine(x, y - 1, x + 1, y);
            break; 
        case 5:
            dc.DrawLine(x - 1, y, x, y - 1);
            dc.DrawLine(x, y + 1, x + 1, y);
            break;
        case 6:
            dc.DrawLine(x, y - 1, x, y + 1);
            break;
        case 7:
            dc.DrawLine(x - 1, y, x, y - 1);
            break;
        case 8:
            dc.DrawLine(x - 1, y, x, y - 1);
            break;
        case 9:
            dc.DrawLine(x, y - 1, x, y + 1);
            break;
        case 10:
            dc.DrawLine(x - 1, y, x, y + 1);
            dc.DrawLine(x, y - 1, x + 1, y);
            break;
        case 11:
            dc.DrawLine(x, y - 1, x + 1, y);
            break;
        case 12:
            dc.DrawLine(x - 1, y, x + 1, y);
            break;
        case 13:
            dc.DrawLine(x, y + 1, x + 1, y);
            break;
        case 14:
            dc.DrawLine(x - 1, y, x, y + 1);
            break;
        case 15:
            break;             
    }
}

void Pole_przyspieszen_czastki_GFKFrm::DrawMap()
{
	wxMemoryDC memDC;   
	memDC.SelectObject(ContourBitMap);
      
	memDC.SetBackground(*wxWHITE_BRUSH);
    memDC.Clear();
    memDC.SetPen(*wxBLACK_PEN);
    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
      
    int x, y;
    int color;
   
    min=200;
    max=-200;

    for(int i = 0; i < MapPanel->GetSize().x; i++)
    {
        for(int j = 0; j < MapPanel->GetSize().y; j++)
        {  
           if(SurfaceChoice->GetSelection()==0)
           board [i][j]= fun1(i,j);
           if(SurfaceChoice->GetSelection()==1)
           board[i][j]=fun2(i,j);
            if(board[i][j]<min){
                min = board[i][j];
            }
            if(board[i][j]>max)
            {
                max = board[i][j];
                y_coordinates_max=j;
		        x_coordinates_max=i;    
            }
        }
    }   
            for(int i=0;i<MapPanel->GetSize().x;i++)
                for(int j=0;j<MapPanel->GetSize().y;j++)
                  {
                        color = (board[i][j]-min)*255/(max-min);
                        memDC.SetPen(wxPen(RGB(color,255-color,0)));
                        memDC.DrawPoint(i,j);
                  }
        DrawContour(memDC,NoLevels,min,max);
}      

void Pole_przyspieszen_czastki_GFKFrm::DrawContour(wxDC &dc,int N,float min, float max)
{
    float step = (max-min)/(N);
    float vals[N];
    int code;
    
    for(int i = 0; i<=N; i++)
    {
        vals[i] = min + i*step;    
    }    
    
    for(int n=0; n<N; n++)
    {
        for(int i=1; i<MapPanel->GetSize().x-1; i++)
        {
            for(int j =1; j<MapPanel->GetSize().y-1; j++)
            {
                int sum = 0;
                if(board[i-1][j-1] > vals[n])
                    sum+=8;
                if(board[i-1][j+1] > vals[n])
                    sum+=4;
                if(board[i+1][j-1] > vals[n])
                    sum+=1;
                if(board[i+1][j+1] > vals[n])
                    sum+=2;
                    
                if(sum == 5){
                    if(board[i][j] < vals[n])
                        code = 10;
                }
                else if(sum==10)
                {
                    if(board[i][j] < vals[n])
                        code =  5;
                }
                else
                {
                    code = sum;
                } 
                putContour(dc, i, j, code);                   
            }    
        } 
    } 
}

/*
 * MapPanelUpdateUI
 */
void Pole_przyspieszen_czastki_GFKFrm::MapPanelUpdateUI(wxUpdateUIEvent& event)
{
    wxMemoryDC memDC;
    memDC.SelectObject(ContourBitMap);
    
    wxClientDC dc(MapPanel);
        
    dc.Blit(0,0,MapPanel->GetSize().x,MapPanel->GetSize().y,&memDC,0,0);
    memDC.SelectObject(wxNullBitmap);
}

/*
 * SaveButtonClick
 */
void Pole_przyspieszen_czastki_GFKFrm::SaveButtonClick(wxCommandEvent& event)
{
        SaveDialog->ShowModal();
        wxString path = SaveDialog->GetPath();
        wxMemoryDC memDC;
        memDC.SelectObject(ContourBitMap);
        memDC.Clear();
                
        wxMemoryDC memDC_contour;
    
        PrepareToSave(memDC_contour);	
    
        wxImage image = ContourBitMap.ConvertToImage();
	    image.SaveFile(path,wxBITMAP_TYPE_BMP );
	    
	    memDC.Clear();
	    DrawMap();	             
}
 
void Pole_przyspieszen_czastki_GFKFrm::TimeBarScroll(wxScrollEvent& event)
{
    time = TimeBar->GetThumbPosition();
    DrawMap();
    DrawVectors();
}

float Pole_przyspieszen_czastki_GFKFrm::fun1(int x, int y)
{   
    return (cos(x/100.0)*sin(y/100.0) + sin(x/200.0) + cos(y/200.0))*(x-y*(time+1));
}    

float Pole_przyspieszen_czastki_GFKFrm::fun_1_deriv_x(int x, int y)
{
    float delta=0.0001;
    float tmp =(fun1(x+delta,y)-fun1(x-delta,y))/(2.0*delta);
	return tmp;
}    

float Pole_przyspieszen_czastki_GFKFrm::fun_1_deriv_y(int x, int y)
{  
    float delta=0.0001;
    double tmp =(fun1(x,y+delta)-fun1(x,y-delta))/(2.0*delta);
	return tmp;
}

float Pole_przyspieszen_czastki_GFKFrm::fun2(int x , int y)
{
    return (sin(x/100.0)*cos(y/100.0) + sin(y/200.0) + cos(x/200.0)*sin(x*y/30000.0))*(x-y*(time+1)) ;    
}

float Pole_przyspieszen_czastki_GFKFrm::fun_2_deriv_x(int x, int y)
{
    float delta=0.0001;
    float tmp =(fun2(x+delta,y)-fun2(x-delta,y))/(2.0*delta);
	return tmp;
}    

float Pole_przyspieszen_czastki_GFKFrm::fun_2_deriv_y(int x, int y)
{  
    float delta=0.0001;
    double tmp =(fun2(x,y+delta)-fun2(x,y-delta))/(2.0*delta);
	return tmp;
}

void Pole_przyspieszen_czastki_GFKFrm::DrawVectors()
{
    if(draw_vectors)
    {    
        wxMemoryDC memDC;
    
        memDC.SelectObject(ContourBitMap);
    
	    memDC.SetBackground(*wxTRANSPARENT_BRUSH);
        memDC.SetPen(*wxBLACK_PEN);
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        
        float const_h;
        
        if(SurfaceChoice->GetSelection()==0)
        const_h=0.002/(time+1);
        
        if(SurfaceChoice->GetSelection()==1)
        const_h=0.001/(time+1);
    
        for(int i=0;i<40;++i)
            for(int j=0;j<35;++j)
            {
                points[35*i+j].x=i*20;
                points[35*i+j].y=j*20;
                points[35*i+j].value=board[20*i][20*j];
            }
   
        Point vector_end;
       
        for(int i=0;i<MapPanel->GetSize().x*MapPanel->GetSize().y/400.0;++i)
        {
            if(SurfaceChoice->GetSelection()==0)
            {
            vector_end.x=points[i].x - const_h*fun_1_deriv_x(points[i].x, points[i].y);
            vector_end.y=points[i].y - const_h*fun_1_deriv_y(points[i].x, points[i].y);
            }
            
            if(SurfaceChoice->GetSelection()==1)
            {
            vector_end.x=points[i].x - const_h*fun_2_deriv_x(points[i].x, points[i].y);
            vector_end.y=points[i].y - const_h*fun_2_deriv_y(points[i].x, points[i].y);
            }
          
            DrawArrow(memDC,points[i].x, points[i].y, vector_end.x, vector_end.y);
        }    
        draw_vectors=false;
    }
        
    else
    {
        DrawMap();
        draw_vectors=true;
        
        if(!draw_ball)
            draw_ball=true;
    }      
}    

/*
 * VectorsButtonClick
 */
void Pole_przyspieszen_czastki_GFKFrm::VectorsButtonClick(wxCommandEvent& event)
{
	DrawVectors();
}

void Pole_przyspieszen_czastki_GFKFrm::PrepareToSave(wxMemoryDC &dc)
{
    dc.SelectObject(ContourBitMap);    
	dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    dc.SetPen(*wxBLACK_PEN);
    dc.SetBrush(*wxTRANSPARENT_BRUSH);
        
    DrawContour(dc,NoLevels,min,max);
    DrawVectorsToFile();    
}    

void Pole_przyspieszen_czastki_GFKFrm::DrawArrow(wxDC& dc , int x1 , int y1 , int x2 , int y2)
{
    dc.DrawLine(x1 , y1 , x2 , y2);
    dc.SetBrush(*wxBLACK_BRUSH);
    dc.DrawCircle(x2 , y2 , 1);
}

void Pole_przyspieszen_czastki_GFKFrm::DrawVectorsToFile()
{  
        wxMemoryDC memDC;
    
        memDC.SelectObject(ContourBitMap);
    
	    memDC.SetBackground(*wxTRANSPARENT_BRUSH);
        memDC.SetPen(*wxBLACK_PEN);
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        
        float const_h=0.002/(time+1);
        int height=MapPanel->GetSize().x/20.0;
        int weight=MapPanel->GetSize().y/20.0;
    
        for(int i=0;i<height;++i)
            for(int j=0;j<weight;++j)
            {
                points[weight*i+j].x=i*20;
                points[weight*i+j].y=j*20;
                points[weight*i+j].value=board[20*i][20*j];
            }
   
        Point vector_end;
       
        for(int i=0;i<height*weight;++i)
        {
            if(SurfaceChoice->GetSelection()==0)
            {
                vector_end.x=points[i].x - const_h*fun_1_deriv_x(points[i].x, points[i].y);
                vector_end.y=points[i].y - const_h*fun_1_deriv_y(points[i].x, points[i].y);
            }
            
            if(SurfaceChoice->GetSelection()==1)
            {
                vector_end.x=points[i].x - const_h*fun_2_deriv_x(points[i].x, points[i].y);
                vector_end.y=points[i].y - const_h*fun_2_deriv_y(points[i].x, points[i].y);
            }
                    
                DrawArrow(memDC,points[i].x, points[i].y, vector_end.x, vector_end.y);
        }  
        draw_vectors=false;          
}

/*
 * WxButton1Click
 */
void Pole_przyspieszen_czastki_GFKFrm::WxButton1Click(wxCommandEvent& event)
{       
        time = 0;
	    DirDialog->ShowModal();
        wxString path_tmp = DirDialog->GetPath();
        wxString path[255];
        for(int i=0; i<scroll; i++)
        {
            path[i] = path_tmp;
            char frame[scroll];
	        if(i<10) 
               sprintf(frame, "/000%d.bmp",i);
	        else if(i>=10 && i<100) 
	           sprintf(frame, "/00%d.bmp", i);
	        else if(i>=100)
	           sprintf(frame, "/0%d.bmp", i);
            path[i].append(frame);
            wxMemoryDC memDC;
            time++;
            DrawMap();
            DrawVectorsToFile();
            memDC.SelectObject(ContourBitMap);
            wxImage image = ContourBitMap.ConvertToImage();
	        image.SaveFile(path[i],wxBITMAP_TYPE_BMP );
        }   
}

/*
 * Pole_przyspieszen_czastki_GFKFrmActivate
 */
void Pole_przyspieszen_czastki_GFKFrm::Pole_przyspieszen_czastki_GFKFrmActivate(wxActivateEvent& event)
{

}

/*
 * SurfaceChoiceSelected
 */
void Pole_przyspieszen_czastki_GFKFrm::SurfaceChoiceSelected(wxCommandEvent& event )
{
    ContoursBar->Enable(true);
    TimeBar->Enable(true);
	DrawMap();
    SaveButton->Enable(true); 
    FramesButton->Enable(true);
    BallButton->Enable(true);
    draw_ball=true;
    VectorsButton->Enable(true);
}

/*
 * ContoursBarScroll
 */
void Pole_przyspieszen_czastki_GFKFrm::ContoursBarScroll(wxScrollEvent& event)
{
	NoLevels = 5 + ContoursBar->GetThumbPosition();
	DrawMap();
	DrawVectors();
}

/*
 * BallButtonClick
 */
void Pole_przyspieszen_czastki_GFKFrm::BallButtonClick(wxCommandEvent& event)
{
    if(draw_ball)
    {
        wxMemoryDC memDC;
        memDC.SelectObject(ContourBitMap);
        memDC.SetBackground(*wxTRANSPARENT_BRUSH);
	   //memDC.Clear();
        memDC.SetPen(*wxBLACK_PEN);
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
       
	   ball_image.LoadFile("ball.png" ,wxBITMAP_TYPE_PNG);
        ball_image.Rescale(15,15);
        ball_bitmap=wxBitmap(ball_image);
        
            if(x_coordinates_max>MapPanel->GetSize().x-10)
                x_coordinates_max-=25;
            
            if(y_coordinates_max>MapPanel->GetSize().y-10)
                y_coordinates_max-=25;
                
            if(x_coordinates_max<10)
                x_coordinates_max+=25;
            
            if(y_coordinates_max<10)
                y_coordinates_max+=25;    
            
            memDC.DrawBitmap(ball_bitmap, x_coordinates_max, y_coordinates_max);
            
            float const_h;
            Point ball_next_position;
            ball_next_position.x=x_coordinates_max;
            ball_next_position.y=y_coordinates_max;
            wxClientDC dc(MapPanel);
            
            if(SurfaceChoice->GetSelection()==0)
                const_h=0.002/(time+1);
        
            if(SurfaceChoice->GetSelection()==1)
                const_h=0.001/(time+1);
        
            ball_next_position.x=x_coordinates_max;
            ball_next_position.y=y_coordinates_max;
        if(SurfaceChoice->GetSelection()==0)
        {
           for(int i=0;i<15;++i)
            {   
                ball_next_position.x=ball_next_position.x - const_h*fun_1_deriv_x(ball_next_position.x, ball_next_position.y);
                ball_next_position.y=ball_next_position.y - const_h*fun_1_deriv_y(ball_next_position.x, ball_next_position.y);                      
                DrawBall(dc, ball_next_position.x, ball_next_position.y);        
            }
        }
        
        if(SurfaceChoice->GetSelection()==1)
        {
           for(int i=0;i<30;++i)
            {   
                ball_next_position.x=ball_next_position.x - const_h*fun_2_deriv_x(ball_next_position.x, ball_next_position.y);
                ball_next_position.y=ball_next_position.y - const_h*fun_2_deriv_y(ball_next_position.x, ball_next_position.y);                      
                DrawBall(dc, ball_next_position.x, ball_next_position.y);        
            }
        }
    
            memDC.Blit(0,0,MapPanel->GetSize().x,MapPanel->GetSize().y,&dc,0,0);
                       
        draw_ball=false;
    }
    
    else
    {
        DrawMap();                
        if(!draw_vectors)
        {
            draw_vectors=true;
            DrawVectors();
            draw_vectors=true;
        }
        
        draw_ball=true;
    }             
}

void Pole_przyspieszen_czastki_GFKFrm::DrawBall(wxDC& dc , float x, float y)
{
        if(x>MapPanel->GetSize().x-10)
            x-=35;
            
        if(y>MapPanel->GetSize().y-10)
            y-=35;
                
        if(x<10)
            x+=35;
            
        if(y<10)
            y+=35; 
    
    for(int i=0;i<=99900000;++i)
    {
        if(i==99900000)
            dc.DrawBitmap(ball_bitmap, x, y);  
    }        
}    

/*
 * HelpButtonClick
 */
void Pole_przyspieszen_czastki_GFKFrm::HelpButtonClick(wxCommandEvent& event)
{
	help = new HelpDlg(this);
	help->ShowModal();
}
