#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <conio.h>
#include <math.h>
#include <time.h>

using namespace std;

// Pattern : Utilitiy to have single line patterns
class Pattern{
	private:
	stringstream DrawStream;

    public:

	// Input pattern from string
	Pattern(string p_data){
		DrawStream.str(std::string());
		DrawStream << p_data;
	}

	~Pattern(){
		DrawStream.str(std::string());
	}

    //Draw pattern directly
    static void draw(int TYPE){
        //use [Pattern::draw(Pattern::Type::TYPE)]
        stringstream ss;
        switch(TYPE)
        {
            case Type::LINE:
            ss << "-----------------------";
                break;
            
            case Type::SWORD_H_R:
            ss << "o==[:::::::::::::::>";
                break;
                        
            case Type::SWORD_H_L:
            ss << "<:::::::::::::::]==o";
                break;
                        
            case Type::THUMBS_UP:
            ss << "     _           \n";
            ss << "    |  \\        \n";
            ss << "    |  |         \n";
            ss << "    |   \\_____  \n";
            ss << "____/          ) \n";
            ss << "               ) \n";
            ss << "               ) \n";
            ss << "----\\__________) ";
                break;
                        
            case Type::BISCEPS:
            ss << "         ___            \n";
            ss << "        (_   \\         \n";
            ss << "           \\   \\      \n";
            ss << "  ____   ___\\    \\    \n";
            ss << "/      v          )     \n";
            ss << "_________________/    ";
                break;
                        
            case Type::SWORD_V:
            ss << "    ^         \n";
            ss << "   | |        \n";
            ss << "   | |        \n";
            ss << "   | |        \n";
            ss << "   | |        \n";
            ss << "   | |        \n";
            ss << " (__W__)      \n";
            ss << "   | |        \n";
            ss << "   | |        \n";
            ss << "    O    ";
                break;

            case Type::INTRO:
            ss << "/--------------------------------------\\ \n";
            ss << "|          COMPUTER ASSISTED           |  \n";
            ss << "|            INSTRUCTION               |  \n";
            ss << "|                TOOL                  |  \n";
            ss << "\\--------------------------------------/ \n";
            }
                    cout << ss.str();
        }
    enum Type{
        //Stores the type of patterns availible
        LINE,
        /*
        ----------------------------
        */
        SWORD_H_R,
        /*
        o==[:::::::::::::::>
        */
        SWORD_H_L,
        /*
        <:::::::::::::::]==o
        */
        THUMBS_UP,
        /*
             _
            |  \
            |  |
            |   \_____
        ____/          )
                       ) 
                       )
        ----\__________)
        */
        BISCEPS,
        /*
                 ___
                (_   \
                   \   \   
          ____   ___\    \
        /      v          )
        _________________/
        */
        SWORD_V,
        /*
            ^
           | |
           | |
           | |
           | |    
           | |
         (__W__)
           | |
           | |
            O
        */
        INTRO
        /*
        /--------------------------------------\
        |          COMPUTER ASSISTED           |
        |            INSTRUCTION               |
        |                TOOL                  |
        \--------------------------------------/ 
        */
    };

	// Draw the stored pattern
	void draw(){
		cout << DrawStream.str();
	}

	stringstream& getDrawStream(){
		return DrawStream;
	}

	// UTILITY DEFINITIONS

	// Ease drawing
	friend ostream& operator << (ostream& os,Pattern &pattern){
		pattern.draw();
		
		return os;
	}

	// Ease inputting pattern
	friend istream& operator >> (istream& is,Pattern &pattern){
		string pat;
		cin >> pat;
		pattern.getDrawStream() << pat;

		return is; 
	}
};