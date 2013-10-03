// Name: eText Synergy Corporation
// Course: CSC 260, Section 2
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Collaborative Team Project
// Description: Class Supplement is the representation of a Supplement of an item, which additional information. The item can be bought, traded,
//				sold, or auctioned, and its information can be pased to other files.
// Filename: DateTime.h
// Last modified on: 12/4/11

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Item.h"
#include "DateTime.h"
using namespace std;

class Supplement : public Item {

	private:
	string SupplementOf;
	
	public:
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator=() is an overloaded = operator
	//
	//	Parameters:
	//	input Supplement: the object the calling object will be come a copy of.
	//    
	//	Pre-condition: Both Supplement objects are initialized.
	//  Post-condition: The calling object will become a copy of the parameter.
	//
	//-----------------------------------------------------------------------------------------
    Supplement& operator = (const Supplement&);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: ~Supplement() is an overloaded destructor.
	//
	//	Parameters:
	//    
	//	Pre-condition: The Supplement object is initialized.
	//  Post-condition: The object is deleted.
	//
	//-----------------------------------------------------------------------------------------
    ~Supplement();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: Supplement() is an overloaded copy constructor
	//
	//	Parameters:
	//	input Supplement: the object the calling object will be come a copy of.
	//    
	//	Pre-condition: Both Supplement objects are initialized.
	//  Post-condition: The calling object will become a copy of the parameter.
	//
	//-----------------------------------------------------------------------------------------
    Supplement(const Supplement&);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: Supplement() is the constructor for the Supplement class
	//
	//	Parameters:
    //		input string; 	name of the Supplement
    //		input string; 	condition of the Supplement
    //		input integer;	sell type (auction, sell, trade)
    //		input string;	name of the seller
    //		input double;	starting sale price of Supplement
    //		input double; 	ending sale price of Supplement
    //		input string;	course tag of Supplement (ex. CSC, PHY, MAT)
    //		input integer;	course number
    //		input DateTime;	remaining time of Supplement auction
    //		input DateTime;	creation time of Supplement auction
    //		input string;	name of Supplement author
    //		input string; 	name of Supplement publisher
    //		input string;	the item this Supplement is a Supplement of
    //		input double;	ISBN number of Supplement
    //
	//	Pre-condition:
	//  Post-condition: Constructs a Supplement object with the given parameters.
	//-----------------------------------------------------------------------------------------	
	Supplement(string Uname = "", string Ucondition = "", int UsellType = 0, string Useller = "", double UsellPrice = 0.0, double UendPrice = 0.0, string UCourseTag = "", int UCourseNumber = 0, DateTime BookTime_Remaining = DateTime(), DateTime BookDate_Created = DateTime(), string suppOf = "");
	
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
	//	input Supplement is the Supplement to add to the stream
	//	output istream& is the stream with the new information.
	//    
	//	Pre-condition: All objects were initialized.
	//  Post-condition: Info for a new Supplement is taken and a Supplement is created.
	//
	//-----------------------------------------------------------------------------------------
    friend istream & operator >> (istream&, Supplement&);
	
   	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator<<() is an overloaded output operator
	//
	//	Parameters:
	//	input ostream& is the stream to add input to
	//	input Supplement is the Supplement to add to the stream
	//	output ostream& is the stream with the new information.
	//    
	//	Pre-condition: All objects were initialized.
	//  Post-condition: Info for a new Supplement is added to the stream
	//
	//-----------------------------------------------------------------------------------------
	friend ostream & operator << (ostream&, Supplement&);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: compareTo() compares 2 objects for equality
	//
	//	Parameters:
	//	output bool represents whether the objects are equal.
	//	input Supplement represents the maunal object to compare to.
	//    
	//	Pre-condition: The 2 objects was initalized.
	//  Post-condition: True is returned if they are the same, false otherwise.
	//
	//-----------------------------------------------------------------------------------------
    bool compareTo(Supplement*);
	
};