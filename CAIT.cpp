#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <conio.h>
#include <math.h>
#include <time.h>

#include "Activity.cpp"

using namespace std;
// CAIT : Testing tool for mathematical ability
class CAIT
{     
	private:
	float value;                    // Stores computed result
    float input,					// Stores user input result
		  number1,number2;    		// Store operands
    char sign;						// Store operator

    public:

	// To genetrate a random question according to given OPERATOR and LEVEL (NOTE : Compatible with class_GUI only)
    float generatequestion(int OPERATOR,int level,GUI &gui)
    {   
		number1 = (rand() % (int)pow(10,level));
		number2 = (rand() % (int)pow(10,level));
        
		if(OPERATOR == 0){ 
            int operation = (rand() % 4) +1;
            switch (operation)
            {
                case 1:   
                    sign = '+' ;
                    value = number1+number2;
                	break;
                case 2:   
                    sign = '-';
                    value = number1-number2;
                    break;
                case 3:
                    sign = 'x' ;
                    value = number1*number2;
                    break;
                case 4:   
                    sign = 246 ; //8-bit ASCII value for '÷'
                    value = TRUNCATE(number1/number2,2);
                    break;       
            }            
    	}
        
		else if (OPERATOR == 1){
            sign = '+';
            value = number1+number2;
        }
        else if (OPERATOR == 2){
            sign = '-';
            value = number1-number2;
        }
        else if (OPERATOR ==3){
            sign = 'x';
            value = number1*number2;
        }
        else if (OPERATOR== 4){
            sign = 246;//8-bit ASCII vaue for '÷'
            value = TRUNCATE(number1/number2,2);
        }

		gui.moveTo(18,5);
		cout << number1 << "   ";
		gui.moveTo(16,6);
		cout << sign << "   ";
		gui.moveTo(18,6);
		cout << number2 << "   ";
		gui.moveTo(18,7);
		
		cout << "\E(0"; // START line drawing mode.
		repeat(level + 2)
		cout << "q";
		
		gui.moveTo(18,8);

		repeat(level + 4)
		cout << " ";


		gui.moveTo(18,9);

		repeat(level + 2)
		cout << "q";

		cout << "\E(B"; // END line drawing mode.

		gui.moveTo(18,8);

        return value;
    }

	// To generate random quotes for success 
    void correctresponse()
    {
        int n;
        n = (rand() % 12);
        switch (n)
        {
            case 0:
                cout << "Nice!                                      "<<endl;
                break;
            case 1:
                cout << "That's right!                              "<<endl;
                break;
            case 2:
                cout << "Wonderful!                                 "<<endl;
                break;
            case 3:
                cout << "Kudos!                                     "<<endl;
                break;
            case 4:
                cout << "Bravo!                                     "<<endl;
                break;
            case 5:
                cout << "Awesome!                                   "<<endl;
                break;
            case 6:
                cout << "Superb!                                    "<<endl;
                break;
            case 7:
                cout << "You nailed it!                             "<<endl;
                break;
            case 8:
                cout << "That's great!                              "<<endl;
                break;
            case 9:
                cout<<"Very good!                                   "<<endl;   
                break;
            case 10:
                cout<<"Excellent!                                   "<<endl;   
                break;
            case 11:
                cout<<"Nice work!                                   "<<endl;   
                break;
            case 12:
                cout<<"Keep up the good work!                       "<<endl;   
                break;
        }
    }

	// To generate random quotes for failure
    void incorrectresponse()
    {
        int n;
        n = (rand() % 10);
        switch (n)
        {
            case 0:
                cout << "You can do it! Make sure you give your best"<<endl; 
                break;
            case 1:
                cout << "That's wrong... but you can do it...       "<<endl; 
                break;
            case 2:
                cout << "Take a deep breath and nail it next time.  "<<endl; 
                break;
            case 3:
                cout << "No... try once again..                     "<<endl; 
                break;
            case 4:
                cout << "No need to hurry... solve without worrying."<<endl; 
                break;
            case 5:
                cout << "Looks like you made a mistake... try again!"<<endl; 
                break;
            case 6:
                cout << "Try, try, until you succeed                "<<endl;
                break;
            case 7:
                cout<<"No,please try again!                         "<<endl;   
                break;
            case 8:
                cout<<"Wrong,try once more !                        "<<endl;   
                break;
            case 9:
                cout<<"Don't give up!                               "<<endl;   
                break;
            case 10:
                cout<<"No,keep trying!                              "<<endl;   
                break;
        }
    }

}; 
