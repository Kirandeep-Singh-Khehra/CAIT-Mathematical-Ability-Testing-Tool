#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <conio.h>
#include <math.h>
#include <time.h>

#include "GUI.cpp"

using namespace std;
// Activity : Enhance USER-INTERFACE and other Utilities
class Activity : public GUI
{
  private:
	string title;					// Stores title of current Activity
	stringstream titleStream;		// Stream to ease the editing of title
	int BgColor;					// Stores the second character for colouring escape sequence for Background_Colour
	int TitleBarColor;				// Stores the second character for colouring escape sequence for Title_Bar_Colour
	int TitleColor;					// Stores the second character for colouring escape sequence for Title_Colour
	int type;						// Stores the display style of Activity (Reffer to enum Type)

  public:

	// Get the type of Activity styles supported
	enum Type
	{
		FULL_SCREEN,
		ACTION_BAR,

		// Following are emulated and could be extended
		FULL_SCREEN_BASE_INPUT,
		ACTION_BAR_BASE_INPUT
	};

	Activity(int WIDTH, int HEIGHT, int TYPE) : GUI(WIDTH, HEIGHT)
	{
		type = TYPE;
	}

	// Setters
	void setTitle(string TITLE)
	{
		titleStream.str(string());
		titleStream << TITLE;
		title = TITLE;
	}

	void setBgColor(int COLOUR)
	{
		BgColor = COLOUR;
	}

	void setTitleBarColor(int COLOUR)
	{
		TitleBarColor = COLOUR;
	}

	void setTitleColor(int COLOUR)
	{
		TitleColor = COLOUR;
	}
	
	// Getters
	stringstream& getTitleStream(){
		return titleStream;
	}

	// Draws the activty on screen
	void draw()
	{
		clear(BgColor);

		switch (type)
		{
		case Type::ACTION_BAR:
			moveTo(0, 0);
			drawH(TitleBarColor);
			title = titleStream.str();
			moveTo(width / 2 - title.length() / 2 - 1, 0);
			cout << "\E[3" << TitleColor << "m" << title;
			cout << RESET << "\E[4" << BgColor << "m\E[3"<< TitleBarColor << "m";
			cout << S_NO_INVERT;
		}
	}
	
	// Utility to draw Activity with ease
	friend ostream& operator << (ostream& os,Activity &activity){
		activity.draw();
		
		return os;
	}
};
