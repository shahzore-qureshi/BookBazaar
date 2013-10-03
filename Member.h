// Name:
// Course: CSC 260-2 
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Assignment N
// Description: put a brief description of the program here
// Filename: assgnNInit.cpp
// Last modified on: date

#include <iostream>
#include <fstream>
#include <sstream>
#include "DateTime.h"

using namespace std;

#ifndef _Member_h
#define _Member_h

const int MIN = 5;
const int MAX = 15;

class Member
{
public:
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator = ()
	//
	//	Parameters:
	//		input Member&;	Member being copied
	//		output Member&;	New Member
	//	Pre-condition: Both the calling Member and Member operand have been initialized.
	//  Post-condition: Sets the calling Member equal to the other Member.
	//-----------------------------------------------------------------------------------------
    Member& operator = (const Member&);
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: ~Member ()
    //
    //	Parameters:
    //	Pre-condition: The Member has been constructed.
    //  Post-condition: Destructs the Member object.
    //-----------------------------------------------------------------------------------------
    ~Member();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: Member ()
    //
    //	Parameters:
    //		input Member&;	Member object to be copied
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Creates a new Member object that is a copy of the Member parameter.
    //-----------------------------------------------------------------------------------------
    Member(const Member&);   
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: Member ()
    //
    //	Parameters:
    //	Pre-condition: 
    //  Post-condition: Constructs a Member object.
    //-----------------------------------------------------------------------------------------
    Member();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: Member ()
    //
    //	Parameters:
    //		input string;	first name of the member
    //		input string;	last name of the member
    //		input string;	email of the member
    //		input string;	username of the member
    //		input string;	password of the member
    //		input DateTime;	the date and time the member's account was created 
    //	Pre-condition:
    //  Post-condition: Constructs a member object.
    //-----------------------------------------------------------------------------------------
    Member(string firstName, string lastName, string email, string username, string password, DateTime dateTime);
    
    //Setters
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: setFirstName ()
    //
    //	Parameters:
    //		input string;	new first name
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Changes the first name of the member.
    //-----------------------------------------------------------------------------------------
    void setFirstName(string);
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: setLastName ()
    //
    //	Parameters:
    //		input string;	new last name
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Changes the last name of the member.
    //-----------------------------------------------------------------------------------------
    void setLastName(string);
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: setEmail ()
    //
    //	Parameters:
    //		input string;	new email address
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Changes the email address of the member.
    //-----------------------------------------------------------------------------------------
    void setEmail(string);
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: setUsername ()
    //
    //	Parameters:
    //		input string;	new username
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Changes the username of the member.
    //-----------------------------------------------------------------------------------------
    void setUsername(string);
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: setPassword ()
    //
    //	Parameters:
    //		input string;	new password
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Changes the password of the member.
    //-----------------------------------------------------------------------------------------
    void setPassword(string);
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: setFirstName ()
    //
    //	Parameters:
    //		input string;	new creation time
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Changes the date and time the member was created.
    //-----------------------------------------------------------------------------------------
    void setCreationTime(DateTime);
    
    //Getters
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: getFirstName ()
    //
    //	Parameters:
    //		output string; first name of the member
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Returns the first name of the member.
    //-----------------------------------------------------------------------------------------
    string getFirstName();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: getLastName ()
    //
    //	Parameters:
    //		output string; last name of the member
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Returns the last name of the member.
    //-----------------------------------------------------------------------------------------
    string getLastName();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: getEmail ()
    //
    //	Parameters:
    //		output string; email address of the member
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Returns the email address of the member.
    //-----------------------------------------------------------------------------------------
    string getEmail();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: getUsername ()
    //
    //	Parameters:
    //		output string; username of the member
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Returns the username of the member.
    //-----------------------------------------------------------------------------------------
    string getUsername();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: getPassword ()
    //
    //	Parameters:
    //		output string; password of the member
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Returns the password of the member.
    //-----------------------------------------------------------------------------------------
    string getPassword();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: getCreationTIme ()
    //
    //	Parameters:
    //		output string; date and time the member's account was created
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Returns the date and time the member's account was created.
    //-----------------------------------------------------------------------------------------
    string getCreationTime();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: toFile ()
    //
    //	Parameters:
    //		output string; prints member information to file in a readable format for later parsing
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Returns the member information in a string.
    //-----------------------------------------------------------------------------------------
    string toFile();                //CSV format for file output
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: viewDetails ()
    //
    //	Parameters:
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Allows the user to choose what member information to edit and calls the
    //					appropriate method.
    //-----------------------------------------------------------------------------------------
    void viewDetails();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: modifyName ()
    //
    //	Parameters:
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Prompts for a new name and changes the member's name to that. 
    //-----------------------------------------------------------------------------------------
    void modifyName();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: modifyUsername ()
    //
    //	Parameters:
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Prompts for a new username and that is between 5 and 15 characters,
    //					then changes the member's current username to that. If the new username
    //					is less than 5 or more than 15 characters, an error message is printed
    //					and the user is continuously prompted for an acceptable username until
    //					one is entered, they return to the previous menu, or they exit the program.
    //-----------------------------------------------------------------------------------------
    void modifyUsername();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: modifyPassword ()
    //
    //	Parameters:
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Prompts for a new password and that is between 5 and 15 characters,
    //					then changes the member's current username to that. If the new password
    //					is less than 5 or more than 15 characters, an error message is printed
    //					and the user is continuously prompted for an acceptable password until
    //					one is entered, they return to the previous menu, or they exit the 
    //					program. They must also enter the old password and confirm the new password.
    //-----------------------------------------------------------------------------------------
    void modifyPassword();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: compareTo ()
    //
    //	Parameters:
    //	Pre-condition: Both the calling Member and the Member operand have been initialized.
    //  Post-condition: Returns true if the usernames are the same and false otherwise.
    //-----------------------------------------------------------------------------------------
	bool compareTo(Member);
    
protected:
    string firstName;
    string lastName;
    string email;
    string username;
    string password;
    DateTime creationTime;
};

	//-----------------------------------------------------------------------------------------
    //
    //  Function: operator >> ()
    //
    //	Parameters:
	//		input Member&;	Member to be modified
	//		output istream&;	receives user input as parameters of the Member object being created
    //	Pre-condition: The Member has been initialized.
    //  Post-condition: Returns an istream that accepts input from the user and transfers it to
	//					the Member object being created.
    //-----------------------------------------------------------------------------------------
	istream& operator >>(istream&, Member&);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator << ()
	//
	//	Parameters:
	//		input Member;	Member to be modified
	//		output ostream&;	prints Member information
	//	Pre-condition: The Member has been initialized.
	//  Post-condition: Returns an ostream that prints a string of formatted Member information.
	//-----------------------------------------------------------------------------------------
	ostream& operator <<(ostream&, Member);

#endif
