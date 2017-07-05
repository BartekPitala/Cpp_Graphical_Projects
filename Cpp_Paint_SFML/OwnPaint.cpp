#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "font.h"

class Menu : public sf::Drawable
{
 private:

  sf::Text *text;
  sf::RectangleShape *rectangle;
  sf::Texture *colors_texture;
  sf::Sprite *colors_sprite;
  sf::Uint8 *colors_pixels;
  const unsigned int colors_size_x = 765;
  const unsigned int colors_size_y = 60;
  inline void draw_to_color_pixels(unsigned int x, unsigned int y,unsigned char r, unsigned char g, unsigned char b)
  {
   colors_pixels[4 * (y * colors_size_x + x) + 0] = r;
   colors_pixels[4 * (y * colors_size_x + x) + 1] = g;
   colors_pixels[4 * (y * colors_size_x + x) + 2] = b;
   colors_pixels[4 * (y * colors_size_x + x) + 3] = 255;
  }

 public:
	 sf::Font font;
  Menu()
  {
   font.loadFromMemory(font_data, font_data_size);
   text = new sf::Text;
   text->setFont(font);
   text->setCharacterSize(12);
   text->setFillColor(sf::Color::White);

   rectangle = new sf::RectangleShape(sf::Vector2f(796, 536));
   rectangle->setFillColor(sf::Color::Transparent);
   rectangle->setOutlineColor(sf::Color::White);
   rectangle->setOutlineThickness(1.0f);
   rectangle->setPosition(2, 62);

   unsigned int x, y;
   colors_pixels = new sf::Uint8[colors_size_x * colors_size_y * 4];
   for (x = 0; x<255; x++)
    for (y = 0; y < 30; y++)
     {
      draw_to_color_pixels(x, y, x, 255, 0);
      draw_to_color_pixels(x+255, y, 255, 255-x, 0);
      draw_to_color_pixels(x + 510, y, 255, 0, x);
      draw_to_color_pixels(254 - x, y+30, 0, 255, 255-x);
      draw_to_color_pixels(509 - x, y + 30, 0, x, 255 );
      draw_to_color_pixels(764 - x, y + 30, 255-x, 0, 255);
     }

   colors_texture = new sf::Texture();
   colors_texture->create(colors_size_x, colors_size_y);
   colors_texture->update(colors_pixels);

   colors_sprite = new sf::Sprite();
   colors_sprite->setTexture(*colors_texture);
   colors_sprite->setPosition(1, 1);
  }

  void outtextxy(sf::RenderTarget& target, float x, float y, wchar_t *str) const
  {
   text->setPosition(x, y); 
   text->setString(str); 
   target.draw(*text);
  }

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
   outtextxy(target,5, 600, L"f - Choose drawing color");
   outtextxy(target, 5, 615, L"b - Choose filling color");
   outtextxy(target, 5, 630, L"l - Draw a line");

   outtextxy(target, 200, 600, L"r - Draw a rectangle");
   outtextxy(target, 200, 615, L"a - Draw a filled rectangle");
   outtextxy(target, 200, 630, L"c - Draw a circle");

   outtextxy(target, 470, 600, L"w - Save to file");
   outtextxy(target, 470, 615, L"o - Load from file");
   outtextxy(target, 470, 630, L"esc - Quit");

   outtextxy(target, 650, 615, L"Your choice:");

   target.draw(*rectangle);
   target.draw(*colors_sprite);
  }
};

int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 650), "OwnPaint",sf::Style::Titlebar | sf::Style::Close);
 sf::Event event;
 sf::Text text;

 std::vector <sf::VertexArray> Lines;
 std::vector <sf::RectangleShape> Rects;
 std::vector <sf::RectangleShape> FilledRects;
 std::vector <sf::CircleShape> Circles;

 sf::VertexArray linia(sf::LinesStrip, 2);
 sf::RectangleShape rect;
 sf::RectangleShape filledrect;
 sf::CircleShape circ;

 sf::Color dcolor = sf::Color::Red;
 sf::Color fcolor = sf::Color::Red;

 sf::Sprite spr;
 sf::Texture tx;

 sf::RectangleShape drawColorRect;
 drawColorRect.setPosition(765, 30);

 sf::Vector2f size(35, 30);
 drawColorRect.setSize(size);

 sf::RectangleShape fillColorRect;

 fillColorRect.setPosition(765, 0);
 fillColorRect.setSize(size);

 Menu menu;
 char status = '0';

 bool rys = false;
 bool odczyt = false;
 bool toSave = false;
 
 float xpos = 0;
 float ypos = 0;
 int objcount_L = - 1;
 int objcount_R = -1;
 int objcount_FR = -1;
 int objcount_C = -1;
 float x_2 = 0;
 float y_2 = 0;
 float radius = 0;
 
 text.setFont(menu.font);
 text.setFillColor(sf::Color::White);
 text.setCharacterSize(12);
  
 window.setFramerateLimit(60);

 while (window.isOpen())
  {
   window.clear(sf::Color::Black);
   
   while (window.pollEvent(event))
    {
     if (event.type == sf::Event::Closed) window.close();
	 if (event.type == sf::Event::KeyPressed)
	 {
		 if (event.key.code == sf::Keyboard::L)
		 {
			 status = 'l';
			 text.setString("l");
		 }

		 if (event.key.code == sf::Keyboard::F)
		 {
			 status = 'f';
			 text.setString("f");
		 }

		 if (event.key.code == sf::Keyboard::B)
		 {
			 status = 'b';
			 text.setString("b");
		 }

		 if (event.key.code == sf::Keyboard::R)
		 {
			 status = 'r';
			 text.setString("r");
		 }

		 if (event.key.code == sf::Keyboard::A)
		 {
			 status = 'a';
			 text.setString("a");
		 }

		 if (event.key.code == sf::Keyboard::C)
		 {
			 status = 'c';
			 text.setString("c");
		 }

		 if (event.key.code == sf::Keyboard::W)
		 {
			 status = 'w';
			 text.setString("w");
		 }

		 if (event.key.code == sf::Keyboard::O)
		 {
			 status = 'o';
			 text.setString("o");
		 }

		 if (event.key.code == sf::Keyboard::Escape)
		 {
			 window.close();
		 }
	 }

	 if (status == 'l')
	 {
		 if (event.type == sf::Event::MouseButtonPressed)
		 {
			 objcount_L++;
			 rys = true;
			 linia[0].position = sf::Vector2f(event.mouseButton.x , event.mouseButton.y);
			 linia[0].color = dcolor;
			 linia[1].color = fcolor;
			 linia[1].position = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
			 Lines.push_back(linia);
		 }

		 if (event.type == sf::Event::MouseMoved && rys == true)
		 {
			 linia[1].color = fcolor;
			 linia[1].position = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
			 Lines.at(objcount_L) = linia;
		 }

		 if (event.type == sf::Event::MouseButtonReleased)
		 {
			 rys = false;
			 linia[1].color = fcolor;
			 linia[1].position = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
			 Lines.at(objcount_L) = linia;
		 }
	 }

	 if (status == 'r')
	 {
		 if (event.type == sf::Event::MouseButtonPressed)
		 {
			 xpos = event.mouseButton.x;
			 ypos = event.mouseButton.y;
			 objcount_R++;
			 rys = true;

			 rect.setSize(sf::Vector2f(1.0, 1.0));
			 rect.setOutlineColor(dcolor);
			 rect.setFillColor(sf::Color::Transparent);
			 rect.setOutlineThickness(1.0f);
			 rect.setPosition(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
			 Rects.push_back(rect);
		 }

		 if (event.type == sf::Event::MouseMoved && rys == true)
		 {
			 rect.setSize(sf::Vector2f(event.mouseMove.x - xpos, event.mouseMove.y - ypos));
			 Rects.at(objcount_R) = rect;
		 }

		 if (event.type == sf::Event::MouseButtonReleased)
		 {
			 rys = false;
			 rect.setSize(sf::Vector2f(event.mouseButton.x - xpos, event.mouseButton.y - ypos));
			 Rects.at(objcount_R) = rect;
		 }
	 }

	 if (status == 'a')
	 {
		 if (event.type == sf::Event::MouseButtonPressed)
		 {
			 xpos = event.mouseButton.x;
			 ypos = event.mouseButton.y;
			 objcount_FR++;
			 rys = true;

			 filledrect.setSize(sf::Vector2f(1.0, 1.0));
			 filledrect.setOutlineColor(dcolor);
			 filledrect.setFillColor(fcolor);
			 filledrect.setOutlineThickness(1.0f);
			 filledrect.setPosition(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
			 FilledRects.push_back(filledrect);
		 }

		 if (event.type == sf::Event::MouseMoved && rys == true)
		 {
			 filledrect.setSize(sf::Vector2f(event.mouseMove.x - xpos, event.mouseMove.y - ypos));
			 FilledRects.at(objcount_FR) = filledrect;
		 }

		 if (event.type == sf::Event::MouseButtonReleased)
		 {
			 rys = false;
			 filledrect.setSize(sf::Vector2f(event.mouseButton.x - xpos, event.mouseButton.y - ypos));
			 FilledRects.at(objcount_FR) = filledrect;
		 }
	 }
	 
	 if (status == 'c')
	 {
		 if (event.type == sf::Event::MouseButtonPressed)
		 {
			 xpos = event.mouseButton.x;
			 ypos = event.mouseButton.y;

			 objcount_C++;
			 rys = true;

			 circ.setRadius(1.0);
			 circ.setFillColor(sf::Color::Transparent);
			 circ.setOutlineColor(dcolor);
			 circ.setOutlineThickness(1.0);
			 circ.setPosition(xpos, ypos);
			 Circles.push_back(circ);
		 }

		 if (event.type == sf::Event::MouseMoved && rys == true)
		 {
			 x_2 = (event.mouseMove.x - xpos)*(event.mouseMove.x - xpos);
			 y_2 = (event.mouseMove.y - ypos)*(event.mouseMove.y - ypos);
			 radius = sqrt(x_2 + y_2);
			 std::cout << radius << std::endl;
			 circ.setRadius(radius / 2);
			 circ.setPosition(xpos, ypos);
			 Circles.at(objcount_C) = circ;
		 }

		 if (event.type == sf::Event::MouseButtonReleased)
		 {
			 rys = false;
			 float x_2 = (event.mouseButton.x - xpos)*(event.mouseButton.x - xpos);
			 float y_2 = (event.mouseButton.y - ypos)*(event.mouseButton.y - ypos);
			 float radius = sqrt(x_2 + y_2);
			 circ.setRadius(radius/2);
			 circ.setPosition(xpos, ypos);
			 Circles.at(objcount_C) = circ;
		 }
	 }

	 if (status == 'f')
	 {
		 if (event.type == sf::Event::MouseButtonReleased)
		 {
			 int x = event.mouseButton.x;
			 if (event.mouseButton.y <= 30)
			 {
				 if (x <= 255)
				 {
					 dcolor = sf::Color(x, 255, 0, 255);
				 }
				 if (x > 255 && x <= 510)
				 {
					 dcolor = sf::Color(255, 510 - x, 0, 255);
				 }
				 if (x > 510 && x <= 765)
				 {
					 dcolor = sf::Color(255, 0, x - 510, 255);
				 }
			 }

			 if (event.mouseButton.y <= 60 && event.mouseButton.y > 30)
			 {
				 if (x <= 255)
				 {
					 dcolor = sf::Color(0, 255, x, 255);
				 }
				 if (x > 255 && x <= 510)
				 {
					 dcolor = sf::Color(0, 510 - x, 255, 255);
				 }
				 if (x > 510 && x <= 765)
				 {
					 dcolor = sf::Color(x - 510, 0, 255, 255);
				 }
			 }
		 }
	 }

	 if (status == 'b')
	 {
		 if (event.type == sf::Event::MouseButtonReleased)
		 {
			 int x = event.mouseButton.x;
			 if (event.mouseButton.y <= 30)
			 {
				 if (x <= 255)
				 {
					 fcolor = sf::Color(x, 255, 0, 255);
				 }
				 if (x > 255 && x <= 510)
				 {
					 fcolor = sf::Color(255, 510 - x, 0, 255);
				 }
				 if (x > 510 && x <= 765)
				 {
					 fcolor = sf::Color(255, 0, x - 510, 255);
				 }
			 }

			 if (event.mouseButton.y <= 60 && event.mouseButton.y > 30)
			 {
				 if (x <= 255)
				 {
					 fcolor = sf::Color(0, 255, x, 255);
				 }
				 if (x > 255 && x <= 510)
				 {
					 fcolor = sf::Color(0, 510 - x, 255, 255);
				 }
				 if (x > 510 && x <= 765)
				 {
					 fcolor = sf::Color(x - 510, 0, 255, 255);
				 }
			 }
		 }
	 }

	 if (status == 'o')
	 {
		 odczyt = true;
	 }

	 if (status == 'w')
	 {
		 toSave = true;
	 }
    }
	drawColorRect.setFillColor(dcolor);
	window.draw(drawColorRect);
	fillColorRect.setFillColor(fcolor);
	window.draw(fillColorRect);

	if (odczyt)
	{
		odczyt = false;
		tx.loadFromFile("1.jpg");
		spr.setPosition(2, 62);
		spr.setTexture(tx);
		Lines.clear();
		Rects.clear();
		FilledRects.clear();
		Circles.clear();
		objcount_C = -1;
		objcount_FR = -1;
		objcount_L = -1;
		objcount_R = -1;

	}
	
	

    window.draw(menu);
	window.draw(spr);
	text.setPosition(705, 615);
	 


   if (Lines.size() > 0)
   {
	   for (int i = 0; i < objcount_L + 1; ++i)
	   {
		   window.draw(Lines[i]);
	   }
   }

   if (Rects.size() > 0)
   {
	   for (int i = 0; i < objcount_R + 1; ++i)
	   {
		   window.draw(Rects[i]);
	   }
   }

   if (FilledRects.size() > 0)
   {
	   for (int i = 0; i < objcount_FR + 1; ++i)
	   {
		   window.draw(FilledRects[i]);
	   }
   }

   if (Circles.size() > 0)
   {
	   for (int i = 0; i < objcount_C + 1; ++i)
	   {
		   window.draw(Circles[i]);
	   }
   }
   
   window.draw(text);

   if (toSave)
   {
	   std::cout << "saving...";

	   sf::Vector2u windowSize = window.getSize();
	   sf::Texture tex;
	   tex.create(windowSize.x, windowSize.y);
	   tex.update(window);
	   sf::Image img = tex.copyToImage();
	   img.saveToFile("test.png");
	   toSave = false;
   }
   window.display();
  }
 return 0;
}