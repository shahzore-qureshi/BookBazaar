// Name: eText Synergy Corporation
// Course: CSC 260, Section 2
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Collaborative Team Project
// Description: Class Item is the parent class of Book, Manual, and Supplement.
//				It has attributes that are shared by the child classes, which
//				include name and condition.
// Filename: Item.h
// Last modified on: 12/4/11

#ifndef Importer_Item_h
#define Importer_Item_h

#include <iostream>
#include "DateTime.h"
using namespace std;

class Item {

protected:
	string name;				//Name of the item
	string condition;			//Condition of the item (old, new, used, etc.)
	int sellType;				//Sell type (trade, auction, or sell)
	string seller;				//Name of item seller
	double sellPrice;			//Beginning sale price of item
    double endPrice;			//Ending sale price of item
	string courseTag;			//Course tag of book (ex. CSC, MAT, PHY)
    int courseNumber;			//Course number (ex. 101, 230, 310)
    DateTime timeRemaining;		//The amount of time remaining for this item
    DateTime dateCreated;		//The creation date of the item
    
public:
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator = ()
	//
	//	Parameters:	Item object that is being copied to the calling object.
	//	Pre-condition:
	//  Post-condition: This is an overloaded assignment operator.
	//					All attributes of the Item object being passed into the function
	//					are copied into the calling object.
	//-----------------------------------------------------------------------------------------
    Item& operator = (const Item&);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: ~Item ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: This is an overloaded destructor for the Item class.
	//-----------------------------------------------------------------------------------------
    virtual ~Item();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: Item ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: This is an overloaded copy constructor.
    //					A clone of the Item object is created.
	//-----------------------------------------------------------------------------------------
    Item(const Item&);
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: Item ()
	//
	//	Parameters:
    //		input string; 	name of the book
    //		input string; 	condition of the item
    //		input integer;	sell type (auction, sell, trade)
    //		input string;	name of the seller
    //		input double;	starting sale price of item
    //		input double; 	ending sale price of item
    //		input string;	course tag of item (ex. CSC, PHY, MAT)
    //		input integer;	course number
    //		input DateTime;	remaining time of item auction
    //		input DateTime;	creation time of item auction
    //
	//	Pre-condition:
	//  Post-condition: Constructs a Item object with the given parameters.
	//-----------------------------------------------------------------------------------------
	Item(string Uname = "", string Ucondition = "", int UsellType = 0, string Useller = "", double UsellPrice = 0.0,
			double UendPrice = 0.0, string UCourseTag = "", int UCourseNumber = 0, DateTime BookTime_Remaining = DateTime(),
			DateTime BookDate_Created = DateTime());
	
    //Setters

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setName ()
	//
	//	Parameters:
	//		input string;	name of item
	//	Pre-condition:
	//  Post-condition: Modifies the item name with the input string.
	//-----------------------------------------------------------------------------------------
    void setName(string);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setCourseTag ()
	//
	//	Parameters:
	//		input string;	course tag of item
	//	Pre-condition:
	//  Post-condition: Modifies the item course tag with the input string.
	//-----------------------------------------------------------------------------------------
    void setCourseTag(string);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setCondition ()
	//
	//	Parameters:
	//		input string;	condition of item
	//	Pre-condition:
	//  Post-condition: Modifies the item condition with the input string.
	//-----------------------------------------------------------------------------------------
    void setCondition(string);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setSellType ()
	//
	//	Parameters:
	//		input integer;	sell type
	//	Pre-condition:
	//  Post-condition: Modifies the sell type with the input integer.
	//-----------------------------------------------------------------------------------------
    void setSellType(int);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setSeller ()
	//
	//	Parameters:
	//		input string;	name of the seller
	//	Pre-condition:
	//  Post-condition: Modifies the item seller with the input string.
	//-----------------------------------------------------------------------------------------
    void setSeller(string);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setCourseNumber ()
	//
	//	Parameters:
	//		input integer;	course number in integer form
	//	Pre-condition:
	//  Post-condition: Modifies the item course number with the input integer.
	//-----------------------------------------------------------------------------------------
    void setCourseNumber(int);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setSellPrice ()
	//
	//	Parameters:
	//		input double;	starting sale price of item
	//	Pre-condition:
	//  Post-condition: Modifies the starting sale price of item with the input double.
	//-----------------------------------------------------------------------------------------
    void setSellPrice(double);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setEndPrice ()
	//
	//	Parameters:
	//		input double;	ending sale price of item
	//	Pre-condition:
	//  Post-condition: Modifies the ending sale price of item with the input double.
	//-----------------------------------------------------------------------------------------
    void setEndPrice(double);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setDateCreated ()
	//
	//	Parameters:
	//		input DateTime;	creation date of item
	//	Pre-condition:
	//  Post-condition: Modifies the creation date of item with the input DateTime.
	//-----------------------------------------------------------------------------------------
    void setDateCreated(DateTime);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setTimeRemaining ()
	//
	//	Parameters:
	//		input DateTime;	time remaining of item
	//	Pre-condition:
	//  Post-condition: Modifies the time remaining of item with the input DateTime.
	//-----------------------------------------------------------------------------------------
    void setTimeRemaining(DateTime);
    
    //Getters

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getName ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the name of the item.
	//-----------------------------------------------------------------------------------------
    string getName();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getCourseTag ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the course tag associated with the item.
	//-----------------------------------------------------------------------------------------
    string getCourseTag();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getCondition ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the item condition.
	//-----------------------------------------------------------------------------------------
    string getCondition();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getSellType ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the item sell type.
	//-----------------------------------------------------------------------------------------
    int getSellType();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getSeller ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the seller's name.
	//-----------------------------------------------------------------------------------------
    string getSeller();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getCourse ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns both course tag and course number of item.
	//-----------------------------------------------------------------------------------------
    string getCourse();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getCourseNumber ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the course number of item.
	//-----------------------------------------------------------------------------------------
    int getCourseNumber();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getSellPrice ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the beginning sale price of item.
	//-----------------------------------------------------------------------------------------
    double getSellPrice();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getEndPrice ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns the ending sale price of item.
	//-----------------------------------------------------------------------------------------
    double getEndPrice();
    
    //-----------------------------------------------------------------------------------------
    //
    //  Function: getDateCreated ()
    //
    //	Parameters:
    //	Pre-condition:
    //  Post-condition: Returns the date the Item was created on.
    //-----------------------------------------------------------------------------------------
    string getDateCreated();

    //-----------------------------------------------------------------------------------------
    //
    //  Function: getTimeRemaining ()
    //
    //	Parameters:
    //	Pre-condition:
    //  Post-condition: Returns how much time is remaining for the item.
    //-----------------------------------------------------------------------------------------
    string getTimeRemaining();


	//-----------------------------------------------------------------------------------------
	//
	//  Function: subtractOneSecond ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Subtracts one second from the remaining time.
	//-----------------------------------------------------------------------------------------
    void subtractOneSecond();
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: isDone ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns true if time has run out for the item. Returns false otherwise.
	//-----------------------------------------------------------------------------------------
    bool isDone();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: compareTo ()
	//
	//	Parameters:
    //		input Item;	the Item object that is being compared to the calling object
	//	Pre-condition:
	//  Post-condition: Determines whether the calling object item and the item object
    //					being passed into the function are equal. If they are equal,
    //					compareTo() returns true. If they are not equal, the function
    //					returns false.
	//-----------------------------------------------------------------------------------------
    virtual bool compareTo (Item* i);
    

//    string toString();          //Gets information of item

	//-----------------------------------------------------------------------------------------
	//
	//  Function: toFile ()
	//
	//	Parameters:
	//	Pre-condition:
	//  Post-condition: Returns a string that is formatted for printing to files.
	//					The string consists of the Item's attributes.
	//-----------------------------------------------------------------------------------------
    virtual string toFile();
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator >> ()
	//
	//	Parameters:
	//		output istream;	populated with inputs from user
	//		input Item;	the Item that is being populated with attributes
	//	Pre-condition:
	//  Post-condition: Returns an istream object that transfers elements from user input
	//					to the item.
	//-----------------------------------------------------------------------------------------
    friend istream & operator >> (istream&, Item&);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator << ()
	//
	//	Parameters:
	//		output ostream;	populated with all of the item's attributes
	//		input Item;	the item that is being printed
	//	Pre-condition:
	//  Post-condition: Returns an ostream object that contains the item's attributes.
	//-----------------------------------------------------------------------------------------
	friend ostream & operator << (ostream&, Item);
};

#endif
