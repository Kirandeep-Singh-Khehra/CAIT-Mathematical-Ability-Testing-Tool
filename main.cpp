#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <conio.h>
#include <math.h>
#include <time.h>

// #include "Activity.cpp"
#include "CAIT.cpp"
#include "Pattern.cpp"

#ifdef _WIN32
#include <wchar.h>
#include <windows.h>
#endif

using namespace std;
// To store Candidate details
struct candidate{
	string name;
	int age;
	int level;
	int score;
}cand;


// UTILITY function to user-input a floating point value
float nextFloat(){
	float f;
	cin >> f;
	return f; 
}

int main()
{
	// Enabling virtual terminal on WINDOWS_OS to support ANSI escape sequences
	/*
	Source  : https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
	Credits : All the Contributers to the article above
	*/
	#ifdef _WIN32

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
    }

	#endif

	// Adding title to terminal window
	cout << "\E]0; CAIT - COMPUTER ASSISTED INSTRUCTION TOOL";

	CAIT cait;                    	
    float answer;					// Stores vlaue returned by CAIT::generatequestion();
    int choice,						// Stores choice of operator
		lvl;                 		// Store level number
	int no_of_correct=0;			// Stores no of correct responses made by user
    
	// Setup GUI
	GUI gui(SCREEN_WIDTH, SCREEN_HEIGHT);

	gui.clear(GUI::Colors::Blue);

	char c1[40] = "  ##     #    #####  ##### ",
		 c2[40] = " #  #   # #     #      #   ",
		 c3[40] = " #     #   #    #      #   ",
		 c4[40] = " #  #  #####    #      #   ",
		 c5[40] = "  ##   #   #  #####    #   ";

	int i = 18,
		j = 2;

	gui.moveTo(i, j);
	gui.draw(c1);

	gui.moveTo(i, j + 1);
	gui.draw(c2);

	gui.moveTo(i, j + 2);
	gui.draw(c3);

	gui.moveTo(i, j + 3);
	gui.draw(c4);

	gui.moveTo(i, j + 4);
	gui.draw(c5);

	gui.moveTo(14, 8);
	cout << S_BOLD << "COMPUTER ASSISTED INSTRUCTION TOOL" << S_NO_BOLD;

	gui.moveTo(17, 10);
	cout << "Press any key to continue...";
	gui.moveTo(GUI::Position::END);
	cout << RESET;

	getch();
	
// Activity common declarations and staring of workflow
	Activity MainActivity(SCREEN_WIDTH, SCREEN_HEIGHT, Activity::Type::ACTION_BAR);
	MainActivity.setBgColor(GUI::Colors::White);
	MainActivity.setTitle("CAID - COMPUTER ASSISTED INSTRUCTION TOOL");
	MainActivity.setTitleBarColor(GUI::Colors::Blue);
	MainActivity.setTitleColor(GUI::Colors::White);
	
	Activity DetailsActivity(SCREEN_WIDTH,SCREEN_HEIGHT,Activity::Type::ACTION_BAR);
	DetailsActivity.setBgColor(GUI::Colors::White);
	DetailsActivity.setTitleBarColor(GUI::Colors::Red);
	DetailsActivity.setTitleColor(GUI::Colors::White);
	DetailsActivity.setTitle("INSTRUCTIONS AND OPTIONS");
	
	Activity StartActivity(SCREEN_WIDTH,SCREEN_HEIGHT,Activity::Type::ACTION_BAR);
	StartActivity.setBgColor(GUI::Colors::White);
	StartActivity.setTitleBarColor(GUI::Colors::Red);
	StartActivity.setTitleColor(GUI::Colors::White);
	StartActivity.setTitle("INSTRUCTIONS AND OPTIONS");

	Activity RunActivity(SCREEN_WIDTH,SCREEN_HEIGHT,Activity::Type::ACTION_BAR);
	RunActivity.setBgColor(GUI::Colors::White);
	RunActivity.setTitleBarColor(GUI::Colors::Red);
	RunActivity.setTitleColor(GUI::Colors::White);
	RunActivity.setTitle("LEVEL 0");
	
	Activity AboutActivity(SCREEN_WIDTH,SCREEN_HEIGHT,Activity::Type::ACTION_BAR);
	AboutActivity.setBgColor(GUI::Colors::White);
	AboutActivity.setTitleBarColor(GUI::Colors::Blue);
	AboutActivity.setTitleColor(GUI::Colors::White);
	AboutActivity.setTitle("CAIT - COMPUTER ASSISTED INSTRUCTION TOOL");
	
// MAIN MENU
	Main:

	
	MainActivity.draw();

	gui.moveTo(i - 3,j);
	cout << " Enter your details        ";
	cout << S_INVERT;
	gui.moveTo(i - 3,j+1);
	cout << "                           ";
	gui.moveTo(i - 3,j+2);
	cout << " Name [                  ] ";
	gui.moveTo(i - 3,j+3);
	cout << " Age  [                  ] ";
	gui.moveTo(i - 3,j+4);
	cout << "                           ";
	
	gui.moveTo(i + 4,j+2);
	char _name[20] = "";
	scanf(" %[^\n]s",_name);
	cand.name = _name;
	
	gui.moveTo(i + 4,j+3);
	cin >> cand.age; 
	cand.level = 0;
	cand.score = 0;
	
	gui.moveTo(1,SCREEN_HEIGHT - 1);
	cout << " S - START ";
	gui.moveTo((SCREEN_WIDTH - 5)/2,SCREEN_HEIGHT -1);
	cout << " A - ABOUT ";
	gui.moveTo(SCREEN_WIDTH - 10,SCREEN_HEIGHT - 1);
	cout << " E - EXIT ";
	
	cout << S_NO_INVERT;
	
	MainChoices:
	gui.moveTo(GUI::Position::END);
	switch(getch())
	{
	    case 's':
	    case 'S':
	        goto Start;
	        break;
	        
	   case 'a':
	   case 'A':
	        goto About;
	        break;
	        
	   case 'e':
	   case 'E':
	        goto Exit;
	        break;
	        
	   default:
	   	goto MainChoices;
	   	 
	}
	
//About
	About:
	AboutActivity.draw();
	
	gui.moveTo(SCREEN_WIDTH/2 - cand.name.length()/2,1);
	cout << C_RED << cand.name;
	gui.moveTo(SCREEN_WIDTH/2 - 4,2);
	cout << C_PURPLE << "Age : " << cand.age;
	
	gui.moveTo(1,4);
	cout << C_BLUE << cand.name << " is a candidate for " << C_GREEN << "CAIT - COMPUTER ASSISTED \n INSTRUCTION TOOL" << C_BLUE << " and have successfully started.\n\n";
	cout << C_RED << "  Level : " << cand.level;
	cout << "\n  Score : " << cand.score;
	
	gui.moveTo(1,10);
	cout << H_BLUE << C_WHITE << " S - Start \E[2C C - Continue \E[2C E - Exit ";
	
	AboutChoices:
	gui.moveTo(GUI::Position::END);
	switch(getch())
	{
	    case 'S':
	    case 's':
	    goto Start;
	    
	    case 'C':
	    case 'c':
	    goto Run;
	    
	    case 'E':
	    case 'e':
	    goto Exit;
	    
	    default:
	    goto AboutChoices;
	}
	
//Start
	Start:
	
	StartActivity.draw();
	
	gui.moveTo(0,1);
	
	cout << C_PURPLE << "Welcome " << cand.name << ",\n" << C_RED << MSG_START;
	
	gui.moveTo(1,8);
	cout << S_INVERT << " A - Addition \E[2C S - Subtraction \E[2C M - Multiplication \n\n\E[1C D - Division \E[2C R - Random      \E[2C E - Exit           " << S_NO_INVERT;

	lvl = 1;
	
	StartChoices:
	gui.moveTo(GUI::Position::END);
	switch(getch())
	{
		case 'R':
		case 'r':
		choice = 0;
		break;
		
		case 'A':
		case 'a':
		choice = 1;
		break;

		case 'S':
		case 's':
		choice = 2;
		break;

		case 'M':
		case 'm':
		choice = 3;
		break;

		case 'D':
		case 'd':
		choice = 4;
		break;
		
		case 'E':
		case 'e':
		goto Exit;
		
		default:
		goto StartChoices;
	}

//RUN
	Run:
    
	RunActivity.getTitleStream().str(std::string());
	
	RunActivity.getTitleStream() << "Level - " << lvl;
	
	RunActivity.draw();
	
	
	gui.moveTo(0,3);
	cout << C_RED << "Write your answer and press Enter" << C_BLUE;

	srand(time(NULL));

	for (int i=0;i<10;i++){
    	answer = cait.generatequestion(choice,lvl,gui);

    	if (answer==nextFloat()){
			cout << C_GREEN << endl;
        	cait.correctresponse();
			cout << C_BLUE;
        	no_of_correct++;
    	}else{
			cout << C_RED << endl;
        	cait.incorrectresponse();
			cout << C_BLUE;
	    }
    }

	gui.clear(GUI::Colors::Yellow);
	gui.moveTo(4,2);
	cout << C_BLUE;
    cout<<"\n\tYour correct responses are " << C_PURPLE << no_of_correct << " / 10";
    if ((no_of_correct*10)>=75){
        lvl++;

		gui.moveTo(4,6);

		cout << C_RED;
		Pattern::draw(Pattern::Type::SWORD_H_L);
		gui.moveTo(4,7);
		cout << C_WHITE << "Congratulations you are ready to go to the next level" << C_RED;
		gui.moveTo(4,8);
		Pattern::draw(Pattern::Type::SWORD_H_R);
		cout << C_WHITE;
        
        gui.moveTo(1,10);
        cout << H_BLUE << " N - Next level \E[2C A - About " << C_BLUE;
        
        cand.level++;
		cand.score += no_of_correct; 
		no_of_correct = 0;
		
		RunChoices:
		gui.moveTo(GUI::Position::END);
		switch(getch())
		{
		    case 'N':
		    case 'n':
		    goto Run;
		    
		    case 'A':
		    case 'a':
		    goto About;
		    
		    default:
		    goto RunChoices;
		}
    }
    else if ((no_of_correct*10)<75){
        cout<<"\n\nPlease ask your teacher for the extra help"<<endl;
        no_of_correct = 0;
        
        gui.moveTo(GUI::Position::END);
		getch();
		goto About;
    }
	

//EXIT
    Exit:
    gui.clear(GUI::Colors::Blue);
    gui.moveTo(i,j);
    cout << C_WHITE << "Thanks for your visit.";
	
	//END
	cout << RESET;
	gui.moveTo(GUI::Position::END);
	getch();
	return 0;
}