// Name:
// Course: CSC 260-2 
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Assignment N
// Description: put a brief description of the program here
// Filename: assgnNInit.cpp
// Last modified on: date

#include "UserInterface.h"
#include <cstdlib>

int main (int argc, const char * argv[])
{
    string errorMessage = "";
    UserInterface ui = UserInterface();
    bool startupSucceeded = ui.start(errorMessage);
    bool continueProgram = true;
    if(startupSucceeded)
    {
        while(continueProgram)
        {
            continueProgram = ui.menuLoginScreen();
            if(continueProgram)
            {
                //system("CLS");
                ui.mainMenu();
            }
        }
    }
    else
    {
        cout << errorMessage << endl;
    }
    
    ui.save();
	
    return 0;
}
