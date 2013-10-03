// Name: eText Synergy Corporation
// Course: CSC 260, Section 2
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Collaborative Team Project
// Description: Class Book is a representation of a physical
//				textbook that is available for auctioning off,
//				selling, or trading. The Book data can be
//				printed out to a file and can be compared
//				to other books.
// Filename: Book.h
// Last modified on: 12/4/11

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Item.h"
using namespace std;

class Book : public Item {

	private:
	string author;		//Holds author name
	string publisher;	//Holds publisher name
    int edition;		//Holds edition number
    					//It is converted from a string into an integer.

	double ISBN;		//Holds ISBN Number
	
	public:

	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator = ()
	//
	//	Parameters:	Book object that is being copied to the calling object.
	//	Pre-condition:
	//  Post-condition: This is an overloaded assignment operator.
	//					All attributes of the Book object being passed into the function
	//					are copied into the calling object.
	//-----------------------------------------------------------------------------------------
    Book& operator = (const Book&);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: ~Book ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: This is an overloaded destructor for the Book class.
	//-----------------------------------------------------------------------------------------
    ~Book();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: Book ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: This is an overloaded copy constructor.
    //					A clone of the Book object is created.
	//-----------------------------------------------------------------------------------------
    Book(const Book&);
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: Book ()
	//
	//	Parameters:
    //		input string; 	name of the book
    //		input string; 	condition of the book
    //		input integer;	sell type (auction, sell, trade)
    //		input string;	name of the seller
    //		input double;	starting sale price of book
    //		input double; 	ending sale price of book
    //		input string;	course tag of book (ex. CSC, PHY, MAT)
    //		input integer;	course number
    //		input DateTime;	remaining time of book auction
    //		input DateTime;	creation time of book auction
    //		input string;	name of book author
    //		input string; 	name of book publisher
    //		input string;	edition number of book
    //		input double;	ISBN number of book
    //
	//	Pre-condition:
	//  Post-condition: Constructs a Book object with the given parameters.
	//-----------------------------------------------------------------------------------------
	Book(string Uname = "", string Ucondition = "", int UsellType = 0, string Useller = "",
			double UsellPrice = 0.0, double UendPrice = 0.0, string UCourseTag = "", int UCourseNumber = 0,
			DateTime BookTime_Remaining = DateTime(), DateTime BookDate_Created = DateTime(), string auth = "",
			string publish = "", string edition = "", double isbn = 0.0);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getAuthor ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the book author's name.
	//-----------------------------------------------------------------------------------------
	string getAuthor();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setAuthor ()
	//
	//	Parameters:
	//		input string;	name of book author
	//	Pre-condition:
	//  Post-condition: Modifies the book author's name with the input
	//					author name.
	//-----------------------------------------------------------------------------------------
	void setAuthor(string auth);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getPublisher ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the book publisher's name.
	//-----------------------------------------------------------------------------------------
	string getPublisher();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setPublisher ()
	//
	//	Parameters:
	//		input string;	name of book publisher
	//	Pre-condition:
	//  Post-condition: Modifies the publisher name with the input string.
	//-----------------------------------------------------------------------------------------
	void setPublisher(string publish);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getEdition ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the book edition.
	//-----------------------------------------------------------------------------------------
	int getEdition();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setEdition ()
	//
	//	Parameters:
	//		input string;	edition number
	//	Pre-condition:
	//  Post-condition: Modifies the book edition number with the input string.
	//-----------------------------------------------------------------------------------------
	void setEdition(string edit);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getISBN ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the book's ISBN number.
	//-----------------------------------------------------------------------------------------
	double getISBN();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setISBN ()
	//
	//	Parameters:
	//		input double;	ISBN number of book
	//	Pre-condition:
	//  Post-condition: Modifies the book ISBN number with the input double.
	//-----------------------------------------------------------------------------------------
	void setISBN(double isbn);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator >> ()
	//
	//	Parameters:
	//		output istream;	populated with inputs from user
	//		input Book;	the Book that is being populated with attributes
	//	Pre-condition:
	//  Post-condition: Returns an istream object that transfers elements from user input
	//					to the book.
	//-----------------------------------------------------------------------------------------
	friend istream & operator >>(istream &, Book &);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator << ()
	//
	//	Parameters:
	//		output ostream;	populated with all of the book attributes
	//		input Book;	the Book that is being printed
	//	Pre-condition:
	//  Post-condition: Returns an ostream object that contains the book attributes.
	//-----------------------------------------------------------------------------------------
	friend ostream & operator <<(ostream &, Book &);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: toFile ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns a string that is formatted for printing to files.
	//					The string consists of the Book's attributes.
	//-----------------------------------------------------------------------------------------
    string toFile();
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: compareTo ()
	//
	//	Parameters:
    //		input Book;	the Book object that is being compared to the calling object
	//	Pre-condition:
	//  Post-condition: Determines whether the calling object book and the book object
    //					being passed into the function are equal. If they are equal,
    //					compareTo() returns true. If they are not equal, the function
    //					returns false.
	//-----------------------------------------------------------------------------------------
	bool compareTo(Book*);
    
    void buy();
    void trade();
    void bid();
};
