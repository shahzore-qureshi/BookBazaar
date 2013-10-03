// Name: eText Synergy Corporation
// Course: CSC 260, Section 2
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Collaborative Team Project
// Description: Class Manual is the representation of a physical manual, which additional information. The manual can be bought, traded,
//				sold, or auctioned, and its information can be pased to other files.
// Filename: DateTime.h
// Last modified on: 12/4/11

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Item.h"
using namespace std;

class Manual : public Item {

	private:
	string SupplementOf;
	string publisher;
	double ISBN;
	
	public:
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator=() is an overloaded = operator
	//
	//	Parameters:
	//	input Manual: the object the calling object will be come a copy of.
	//    
	//	Pre-condition: Both Manual objects are initialized.
	//  Post-condition: The calling object will become a copy of the parameter.
	//
	//-----------------------------------------------------------------------------------------
    Manual& operator = (const Manual&);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: ~Manual() is an overloaded destructor.
	//
	//	Parameters:
	//    
	//	Pre-condition: The Manual object is initialized.
	//  Post-condition: The object is deleted.
	//
	//-----------------------------------------------------------------------------------------
    ~Manual();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: Manual() is an overloaded copy constructor
	//
	//	Parameters:
	//	input Manual: the object the calling object will be come a copy of.
	//    
	//	Pre-condition: Both Manual objects are initialized.
	//  Post-condition: The calling object will become a copy of the parameter.
	//
	//-----------------------------------------------------------------------------------------
    Manual(const Manual&);
	
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: Manual() is the constructor for the manual class
	//
	//	Parameters:
    //		input string; 	name of the manual
    //		input string; 	condition of the manual
    //		input integer;	sell type (auction, sell, trade)
    //		input string;	name of the seller
    //		input double;	starting sale price of manual
    //		input double; 	ending sale price of manual
    //		input string;	course tag of manual (ex. CSC, PHY, MAT)
    //		input integer;	course number
    //		input DateTime;	remaining time of manual auction
    //		input DateTime;	creation time of manual auction
    //		input string;	name of manual author
    //		input string; 	name of manual publisher
    //		input string;	the item this manual is a Supplement of
    //		input double;	ISBN number of manual
    //
	//	Pre-condition:
	//  Post-condition: Constructs a Manual object with the given parameters.
	//-----------------------------------------------------------------------------------------	
	Manual(string Uname = "", string Ucondition = "", int UsellType = 0, string Useller = "", double UsellPrice = 0.0, double UendPrice = 0.0, string UCourseTag = "", int UCourseNumber = 0, DateTime BookTime_Remaining = DateTime(), DateTime BookDate_Created = DateTime(), string suppOf = "", string publish = "", double isbn = 0.0);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: getSupplementOf() obtains the SupplementOf for this object
	//
	//	Parameters:
	//	output SupplementOf is the SupplementOf value of the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The SupplementOf is returned.
	//
	//-----------------------------------------------------------------------------------------
    string getSupplementOf();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: setSupplementOf() sets the SupplementOf for this object
	//
	//	Parameters:
	//	input suppOf is the new SupplementOf value.
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The SupplementOf value is updated.
	//
	//-----------------------------------------------------------------------------------------
	void setSupplementOf(string suppOf);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getPublisher() obtains the publisher for this object
	//
	//	Parameters:
	//	output publisher is the publisher of the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The publisher is returned.
	//
	//-----------------------------------------------------------------------------------------
	string getPublisher();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: setPublisher() sets the publisher for this object
	//
	//	Parameters:
	//	input publisher is the new publisher value.
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The publisher value is updated.
	//
	//-----------------------------------------------------------------------------------------
	void setPublisher(string publish);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getISBN() obtains the ISBN for this object
	//
	//	Parameters:
	//	output ISBN is the ISBN of the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The ISBN is returned.
	//
	//-----------------------------------------------------------------------------------------
	double getISBN();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setISBN() sets the ISBN for this object
	//
	//	Parameters:
	//	input ISBN is the new ISBN value.
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The ISBN value is updated.
	//
	//-----------------------------------------------------------------------------------------
	void setISBN(double isbn);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: toFile() returns a string representation of this data that can be parsed
	//
	//	Parameters:
	//	output stringstream is the text representing the information in the object.
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: A string is returned that can be parsed later.
	//
	//-----------------------------------------------------------------------------------------
	string toFile();
	
   	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator>>() is an overloaded insertion operator
	//
	//	Parameters:
	//	input istream& is the stream to add input to
	//	input Manual is the Manual to add to the stream
	//	output istream& is the stream with the new information.
	//    
	//	Pre-condition: All objects were initialized.
	//  Post-condition: Info for a new manual is taken and a Manual is created.
	//
	//-----------------------------------------------------------------------------------------
    friend istream & operator >> (istream&, Manual&);
	
   	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator<<() is an overloaded output operator
	//
	//	Parameters:
	//	input ostream& is the stream to add input to
	//	input Manual is the Manual to add to the stream
	//	output ostream& is the stream with the new information.
	//    
	//	Pre-condition: All objects were initialized.
	//  Post-condition: Info for a new manual is added to the stream
	//
	//-----------------------------------------------------------------------------------------
	friend ostream & operator << (ostream&, Manual&);
   
   	//-----------------------------------------------------------------------------------------
	//
	//  Function: compareTo() compares 2 objects for equality
	//
	//	Parameters:
	//	output bool represents whether the objects are equal.
	//	input Manual represents the maunal object to compare to.
	//    
	//	Pre-condition: The 2 objects was initalized.
	//  Post-condition: True is returned if they are the same, false otherwise.
	//
	//-----------------------------------------------------------------------------------------
    bool compareTo(Manual*);
};