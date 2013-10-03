//
//  UserInterface.h
//  BookBazaar
//
//  Created by Steven Zilberberg on 11/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Member.h"
#include "Book.h"
#include "Manual.h"
#include "Supplement.h"
#include "Stack.cpp"
using namespace std;

const string kType_Title = "title";
const string kType_Author = "author";
const string kType_Class = "class tag";
const string kType_ISBN = "isbn";

const char kReturn = 'r';
const int maxNumberOfSearchResults = 50; 

const string kFile_Member = "Members.txt";
const string kFile_Item = "MasterItemList.txt";

class UserInterface
{
private:
    //Master Member List
    Member *allMembers;
    int indexAllMembers;
    
    //Master Book List
    Item **allItems;
    int indexAllItems;
    
    //Current User
    Member currentMember;
    int indexOfCurrentUser;
    Item **itemList;
    int indexItemList;
//------------------------------------------------------
    //File Checks
	
	//-----------------------------------------------------------------------------------------
    //
    //  Function: check ()
    //
    //	Parameters:
    //		input string; file name	
    //		output bool; represents the existence of the file	
    //	Pre-condition: 
    //  	Post-condition: Returns true if the file exists and false otherwise.
    //-----------------------------------------------------------------------------------------
    bool check(string);
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: check ()
    //
    //	Parameters:
    //		input string; file name	
    //		input int&; number of lines
    //		output bool; represents the existence of the file	
    //	Pre-condition: 
    //  	Post-condition: Returns true if the file exists and false otherwise. If true, the number
    //							of lines is returned. 
    //-----------------------------------------------------------------------------------------
    bool check(string, int&);
    
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: allToLower ()
    //
    //	Parameters:
    //		input string; a word
    //		output string; the same word in all lowercase letters
    //	Pre-condition: 
    //  	Post-condition: Returns the word in all lowercase letters.
    //-----------------------------------------------------------------------------------------
    string allToLower(string);                  //Converts string to lowercase
	
	//-----------------------------------------------------------------------------------------
    //
    //  Function: allToUpper ()
    //
    //	Parameters:
    //		input string; a word	
    //		output string; the same word in all uppercase letters
    //	Pre-condition: 
    // 	Post-condition: Returns the word in all uppercase letters.
    //-----------------------------------------------------------------------------------------
    string allToUpper(string);                  //Converts string to uppercase
	
	    //-----------------------------------------------------------------------------------------
    //
    //  Function: getInput ()
    //
    //	Parameters:
    //		input string; file name	
    //		output string; input
    //	Pre-condition: 
    //  	Post-condition: Returns a string of the input.
    //-----------------------------------------------------------------------------------------
    string getInput(string);
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: getInputChar ()
    //
    //	Parameters:
    //		input string; file name	
    //		output char; input	
    //	Pre-condition: 
    //  	Post-condition: Checks that it is a character and returns the input.
    //-----------------------------------------------------------------------------------------
    char getInputChar(string);
//------------------------------------------------------
    //******Menus******
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: menuSearchParameters ()
    //
    //	Parameters:
    //		output int; the number of options	
    //	Pre-condition: The user chooses to search postings.
    //  	Post-condition: Displays search menu, which shows search parameters, and returns 5.
    //-----------------------------------------------------------------------------------------
    int menuSearchParameters();
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: mainMenuParameters ()
    //
    //	Parameters:
    //		output int;	the number of options	
    //	Pre-condition: User login is authenticated.
    //  	Post-condition: Displays the main menu and its options and returns 5.
    //-----------------------------------------------------------------------------------------
	int mainMenuParameters();
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: postMenuParameters()
    //
    //	Parameters:
    //		output int;	the number of options	
    //	Pre-condition: The user chooses to add an item.
    //  	Post-condition: Displays the posting options and returns 4.
    //-----------------------------------------------------------------------------------------
   	int postMenuParameters();
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: search ()
    //
    //	Parameters:
    //		input string; type of object
   	//		input string; item information
   	//		input Stack<T>&;	items that match the search criteria
   	//		output bool;	determines whether matches were found
    //	Pre-condition: The user chooses to search postings and enters valid search criteria.
    //  	Post-condition: Returns true if at least one match was found and false if no matches
   	//							were found.
    //-----------------------------------------------------------------------------------------
    template<class T>
    bool search(string, string, Stack<T>&);
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: searchDatabase ()
    //
    //	Parameters:	
    //	Pre-condition: User chooses to search postings. 
    //  Post-condition: Returns true if the file exists and false otherwise.
    //-----------------------------------------------------------------------------------------
    void searchDatabase();
    
    //*****Parsers****
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: parseMember ()
    //
    //	Parameters:
    //		input string;	file name
    //		output Member; Member read from file
    //	Pre-condition: There is a valid file. 
    //  	Post-condition: Returns a member object with the information read from the file.
    //-----------------------------------------------------------------------------------------
    Member parseMember(string);                 //parse member info string
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: parseBook ()
    //
    //	Parameters:
    //		input string; file name	
    //		output Book*; a pointer to the Book object read from the file
    //	Pre-condition: There is a valid file.
    //  	Post-condition: Returns a pointer to a Book object with the information read from the file.
    //-----------------------------------------------------------------------------------------
    Book* parseBook(string);                     //parse book info string
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: parseManual ()
    //
    //	Parameters:
    //		input string; file name	
    //		output Manual*; a pointer to the Manual object read from the file
    //	Pre-condition: There is a valid file.
    //  	Post-condition: Returns a pointer to a Manual object with the information read from the 
    //							file.
    //-----------------------------------------------------------------------------------------
    Manual* parseManual(string);
	
	//-----------------------------------------------------------------------------------------
    //
    //  Function: parseSuppliment ()
    //
    //	Parameters:
    //		input string; file name	
    //		output Suppliment*;	a pointer to the Suppliment object read from the file	
    //	Pre-condition: There is a valid file.
    //  	Post-condition: Returns a pointer to a Suppliment object with the information read from 
    //							the file.
    //-----------------------------------------------------------------------------------------
    Supplement* parseSupplement(string);
	
	//-----------------------------------------------------------------------------------------
    //
    //  Function: importItems ()
    //
    //	Parameters:
    //		input string; file name	
    //	Pre-condition: There is a valid file.
    //  	Post-condition: Reads Items from a file and populates stacks of the appropriate type.
    //-----------------------------------------------------------------------------------------
    void importItems(string);
//------------------------------------------------------

	 //-----------------------------------------------------------------------------------------
    //
    //  Function: expandItems ()
    //
    //	Parameters:
    //		input t&; element being added to the array
    //		input X**;	a pointer to an array of Item pointers
    //		input int&;	index of the array
    //		output X**; a pointer to a new, bigger array of Item pointers
    //	Pre-condition: User tries to add an item when the Item array is full.
    //  	Post-condition: Returns a larger array that includes the element.
    //-----------------------------------------------------------------------------------------
    template <class T, class X>    
    X** expandItems(T&, X**, int&);
    
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: expandMembers ()
    //
    //	Parameters:
    //		input Member&;	Member to be added
    //		input Member*;	a pointer to the array of Members
    //		int&; index of the array
    //		output Member*; a pointer to the array of Members
    //	Pre-condition: A user attempts to register when the Members array is full.
    //  	Post-condition: Returns a larger array that includes the new Member.
    //-----------------------------------------------------------------------------------------
    Member* expandMembers(Member&, Member*, int&);
    
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: contractArray ()
    //
    //	Parameters:
    //		input T&; element being deleted
    //		input X**; a pointer to an array of pointers
    //		input int&; index of the array
    //		output X**; a pointer to an array of pointers
    //	Pre-condition: A user deletes a posting or their account.
    //  	Post-condition: Returns a smaller array that no longer includes the deleted element.
    //-----------------------------------------------------------------------------------------
    template <class T, class X>
    X** contractArray(T&, X**, int&);
    
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: display ()
    //
    //	Parameters:
    //		input Member*; a pointer to an array of Members
    //		input int; the size of the array
    //	Pre-condition: 
    //  	Post-condition: Prints Member information in a formatted manner.
    //-----------------------------------------------------------------------------------------
    void display(Member*, int);
	
	//-----------------------------------------------------------------------------------------
    //
    //  Function: getTargetItemList ()
    //
    //	Parameters:
    //		input Item**; a pointer to an array of Item pointers
    //		input int; index of the array
    //		input int&;
    //		output Item**; a pointer to an array of Item pointers
    //	Pre-condition: 
    //  	Post-condition: 
    //-----------------------------------------------------------------------------------------
    Item** getTargetItemList(Item**, int, int&);

public:
	//-----------------------------------------------------------------------------------------
    //
    //  Function: UserInterface ()
    //
    //	Parameters:	
    //	Pre-condition: 
    //  	Post-condition: Creates an instance of the UserInterface class.
    //-----------------------------------------------------------------------------------------
    UserInterface();
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: start ()
    //
    //	Parameters:
    //		input string&; error message	
    //		output bool; represents the existence of the files
    //	Pre-condition: 
    //  	Post-condition: Checks that necessary files exist and returns true if they do and
    //							false otherwise. 
    //-----------------------------------------------------------------------------------------
    bool start(string&);
	
	//-----------------------------------------------------------------------------------------
    //
    //  Function: menuLoginScreen ()
    //
    //	Parameters:
    //		output bool; represents whether or not the menu is displayed	
    //	Pre-condition: 
    //  	Post-condition: It also prints error messages accordingly and handles
    //							the creation of new users and the authentication of returning users.
    //-----------------------------------------------------------------------------------------
    bool menuLoginScreen();
	
	//-----------------------------------------------------------------------------------------
    //
    //  Function: mainMenu ()
    //
    //	Parameters:
    //	Pre-condition: User successfully logs in.
    //  	Post-condition: Displays actions available to users.
    //-----------------------------------------------------------------------------------------
	void mainMenu();
	
    //-----------------------------------------------------------------------------------------
    //
    //  Function: postBook ()
    //
    //	Parameters:
    //	Pre-condition: User chooses to post book.
    //  	Post-condition: Adds a posting/Item to the array of Items.
    //-----------------------------------------------------------------------------------------
	void postBook();
	
	//-----------------------------------------------------------------------------------------
    //
    //  Function: menuBookEdit ()
    //
    //	Parameters:
    //	Pre-condition: User chooses to edit an Item.
    //  	Post-condition: Displays types of modifications allowed by the user.
    //-----------------------------------------------------------------------------------------
	void menuBookEdit();
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: menuBookEditSecond ()
    //
    //	Parameters:
    //	Pre-condition: User chooses which Item to edit.
    // 	Post-condition: Displays the Item fields that can be edited by the user.
    //-----------------------------------------------------------------------------------------
	void menuBookEditSecond();
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: save ()
    //
    //	Parameters:
    //	Pre-condition: Changes are made.
    // 	Post-condition: Saves any and all changes to files.
    //-----------------------------------------------------------------------------------------
	void save();
    
	//-----------------------------------------------------------------------------------------
    //
    //  Function: buy ()
    //
    //	Parameters:
	//		input Item; Item being bought
    //	Pre-condition: User selects an item from the search results.
    //  	Post-condition: User confirms decision and the seller's email address is displayed.
    //-----------------------------------------------------------------------------------------
    void buy(Item*);
	
	 //-----------------------------------------------------------------------------------------
    //
    //  Function: trade ()
    //
    //	Parameters:
    //		input Item; Item desired for trade
    //	Pre-condition: User selects an item from the search results.
    //  	Post-condition: User confirms decision and the seller's email address is displayed.
    //-----------------------------------------------------------------------------------------
    void trade(Item*);
	
	//-----------------------------------------------------------------------------------------
    //
    //  Function: bid ()
    //
    //	Parameters:
    //		input Item;	Item on which the user wants to bid
    //	Pre-condition: User selects an item from the search results.
    // 	 Post-condition: User confirms decision and places a valid bid, then the seller's email
    //							address is displayed. If an invalid bid is entered, the user is
    //							continously prompted to re-enter a valid bid until one is entered, the
    //							user returns to the previous menu, or the user exits the program.
    //-----------------------------------------------------------------------------------------
    void bid(Item*);
};