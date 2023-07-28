#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <conio.h>
#include <math.h>
#include <time.h>

#ifdef _WIN32
#include <wchar.h>
#include <windows.h>
#endif

//Utility Definitions
#define repeat(n) for (int _INDEX = 0; _INDEX < n; _INDEX++)
#define sub_repeat(n) for (int _S_INDEX = 0; _S_INDEX < n; _S_INDEX++)

//Main code
#define ESC "\E["

#define RESET "\E[0m"

// ANSI styling escape sequences
#define S_BOLD "\E[1m"
#define S_UNDERLINE "\E[4m"
#define S_INVERT "\E[7m"
#define S_NO_BOLD "\E[21m"
#define S_NO_UNDERLINE "\E[24m"
#define S_NO_INVERT "\E[27m"

// ANSI colouring escape sequences
#define C_ 30;
#define C_BLACK "\E[30m"
#define C_RED "\E[31m"
#define C_GREEN "\E[32m"
#define C_YELLOW "\E[33m"
#define C_BLUE "\E[34m"
#define C_PURPLE "\E[35m"
#define C_CYAN "\E[36m"
#define C_WHITE "\E[37m"

// ANSI Highlighting(Background-Colouring) escape sequences
#define H_ 40;
#define H_BLACK "\E[40m"
#define H_RED "\E[41m"
#define H_GREEN "\E[42m"
#define H_YELLOW "\E[43m"
#define H_BLUE "\E[44m"
#define H_PURPLE "\E[45m"
#define H_CYAN "\E[46m"
#define H_WHITE "\E[47m"

// Parameters of Screen(working area)
#define SCREEN_WIDTH 60
#define SCREEN_HEIGHT 12

#define MSG_START "Make your choice of operator and you will be assigned\nquestions as per your choice. As you progress, your\nlevel will increase and each level will come with different\ndifficulty.\nBEST OF LUCK "

// Utility math definition
#define TRUNCATE(n,d) (float)((int)(n*(float)pow(10,d)))/(float)pow(10,d);

using namespace std;

// GUI : Enable terminal traversing , colour , drawing and Utilities 
class GUI
{
  private:
	
	// Getting direction to traverse cursor (relative to current)
	enum Dir
	{
		UP = 'A',
		DOWN,
		RIGHT,
		LEFT
	};

  public:
	// Store Parameters of working area
	int width;
	int height;

	GUI(int WIDTH, int HEIGHT)
	{
		width = WIDTH;
		height = HEIGHT;
	}

	// Getting second character of colouring escape sequences
	// Example : "\E[3<x>m" represents colouring and '3' here is representing first character of textcolour and <x> represents second character.
	enum Colors
	{
		Black,
		Red,
		Green,
		Yellow,
		Blue,
		Purple,
		Cyan,
		White

	};

	// Getting absolute position to traverse to Beginning or End of working area
	enum Position
	{
		BEGIN,
		END
	};

	// Clears the working area to specified color
	void clear(int COLOUR)
	{
		//Add new line
		cout << endl;

		moveTo(0, 0);

		//Set colour
		COLOUR = 40 + COLOUR;			// Sets the COLOUR to work with Highlighting escape sequences
		cout << "\E[" << COLOUR << "m";

		//Draw colour
		for (int i = 0; i <= height; i++)
		{
			for (int j = 0; j <= width; j++)
			{
				cout << " ";
			}
			cout << "\n";
		}

		//Goto beginning
		moveTo(0, 0);
	}

	// To traverse relative to current cursor position
	void moveBy(int X, int Y)
	{
		if (X < 0)
		{
			X = -X;
			repeat(X)
					cout
				<< "\E[1D";
		}
		else
		{
			repeat(X)
					cout
				<< "\E[1C";
		}

		if (Y < 0)
		{
			Y = -Y;
			repeat(Y)
					cout
				<< "\E[1A";
		}
		else
		{
			repeat(Y)
					cout
				<< "\E[1B";
		}
	}

	// To traverse to absolute co-ordinates
	void moveTo(int X, int Y)
	{
		moveBy(width * -1 - 2, height * -1 - 2);
		moveBy(X, Y);
	}

	// To traverse to spcific position in Working area
	void moveTo(int POSITION)
	{
		if (POSITION == Position::BEGIN)
			moveTo(0, 0);
		else
			moveTo(width, height);
	}

	// To draw the bit-pattern as : &nbsp; for default and '#' for inverted-colouring(Background and Foreground colours are swapped) 
	void draw(char bits[])
	{
		char current = bits[0];
		repeat(strlen(bits))
		{
			if (bits[_INDEX] != current && bits[_INDEX] == '#')
			{
				cout << S_INVERT;
				current = '#';
			}
			if (bits[_INDEX] != current && bits[_INDEX] == ' ')
			{
				cout << S_NO_INVERT;
				current = ' ';
			}
			cout << " ";
		}
	}

	// Clears a line with specified colour (NOTE : Cursor postion must be in beginning of that line)
	void drawH(int COLOUR)
	{
		COLOUR = 40 + COLOUR;
		cout << "\E[" << COLOUR << "m";
		repeat(width + 1)
		{
			cout << " ";
		}
	}

	// Getters
	int getWidth() { return width; }
	int getHeight() { return height; }
};