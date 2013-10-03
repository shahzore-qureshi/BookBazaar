// Name: eText Synergy Corporation
// Course: CSC 260, Section 2
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Collaborative Team Project
// Description: Implementation of the Item class's functions
//				and methods.
// Filename: Item.cpp
// Last modified on: 12/4/11

#include "Item.h"

Item::Item(string Uname, string Ucondition, int UsellType, string Useller, double UsellPrice, double UendPrice, string UCourse_Tag, int UCourse_Number, DateTime BookTime_Remaining, DateTime BookDate_Created)
{

	name = Uname;
	condition = Ucondition;
	sellType = UsellType;
	seller = Useller;
	sellPrice = UsellPrice;
    endPrice = UendPrice;
    timeRemaining = BookTime_Remaining;
    dateCreated = BookDate_Created;
    courseTag = UCourse_Tag;
    courseNumber = UCourse_Number;

}

void Item::setName(string newName)
{
    name = newName;
}

void Item::setCondition(string newCondition)
{
    condition = newCondition;
}

void Item::setSellType(int newType)
{
    sellType = newType;
}

void Item::setSeller(string newSeller)
{
    seller = newSeller;
}

void Item::setSellPrice(double newSell)
{
    sellPrice = newSell;
}

void Item::setEndPrice(double newEnd)
{
    sellPrice = newEnd;
}

void Item::setCourseTag(string newTag)
{
    courseTag = newTag;
}

void Item::setCourseNumber(int newNum)
{
    courseNumber = newNum;
}

void Item::setDateCreated(DateTime theCreationDate)
{
    dateCreated = theCreationDate;
}

void Item::setTimeRemaining(DateTime theRemainingTime)
{
    timeRemaining = theRemainingTime;
}

string Item::getName()
{
    return name;
}

string Item::getCondition()
{
    return condition;
}

int Item::getSellType()
{
    return sellType;
}

string Item::getSeller()
{
    return seller;
}

string Item::getCourseTag()
{
    return courseTag;
}

int Item::getCourseNumber()
{
    return courseNumber;
}

string Item::getCourse()
{
    stringstream output;
    output << getCourseTag() << "-" << getCourseNumber();
    return output.str();
}

double Item::getSellPrice()
{
    return sellPrice;
}

double Item::getEndPrice()
{
    return endPrice;
}

void Item::subtractOneSecond()
{
    timeRemaining.subtractOneSecond();
}

string Item::getTimeRemaining()
{
    stringstream output;
    output << timeRemaining.getDateTime() << endl;
    return output.str();
}

string Item::getDateCreated()
{
    stringstream output;
    output << dateCreated.getDateTime();
    return output.str();
}

bool Item::isDone()
{
    return timeRemaining.getIsDone();
}

string Item::toFile()
{
    stringstream output;
    
    output << "\"" << getName() << "\",\"" << getCourseTag() << "\",\"" << getCourseNumber() << "\",\"" << getCondition() << "\",\"" << getSellType() << "\",\"" << getSeller() << "\",\"" << getSellPrice() << "\",\"" << getEndPrice() << "\"," << timeRemaining.toFile() << "," << dateCreated.toFile();
    
    return output.str();
}

istream & operator >> (istream& stream, Item& anItem)
{
    string input = "";
    
    cout << "Name: ";
    getline(stream, input);
    anItem.setName(input);
    
    do
    {
    cout << "Course Tag: ";
    getline(stream, input);
    }while(input.length() > 3 || input.length() < 3);
    input[0] = toupper(input[0]);
    input[1] = toupper(input[1]);
    input[2] = toupper(input[2]);
    anItem.setCourseTag(input);
    
    
    bool goodNum = false;
    int num = 0;
    while(!goodNum)
    {
        cout << "Course Number: ";
        try
        {
            cin >> num;
            anItem.setCourseNumber(num);
            goodNum = true;
        }
        catch (exception e)
        {
            goodNum = false;
        }
    }
    cin.ignore(1);
    
    cout << "Condition: ";
    getline(stream, input);
    anItem.setCondition(input);
    
    
    
    do
    {
        cout << "Auction/Trade/Sale: ";
        getline(stream, input);
        for(int c = 0; c < ((int)input.length()); c++)
        {
            input[c] = tolower(input[c]);
        }
    }while(input != "auction" && input != "trade" && input != "sale");
    for(int c = 0; c < ((int)input.length()); c++)
    {
        input[c] = tolower(input[c]);
    }
    if(input == "auction")
        anItem.setSellType(0);
    else if(input == "sale")
        anItem.setSellType(1);
    else if(input == "trade")
        anItem.setSellType(2);
    
    goodNum = false;
    double price = 0.0;
    while(!goodNum)
    {
        cout << "Sell Price: ";
        try
        {
            cin >> price;
            anItem.setSellPrice(price);
            goodNum = true;
        }
        catch (exception e)
        {
            goodNum = false;
        }
    }
    
    
    goodNum = false;
    price = 0.0;
    while(!goodNum)
    {
        cout << "End Price: ";
        try
        {
            cin >> price;
            anItem.setEndPrice(price);
            goodNum = true;
        }
        catch (exception e)
        {
            goodNum = false;
        }
    }
    cin.ignore(1);
    
    goodNum = false;
    num = 0;
    while(!goodNum)
    {
        cout << "Number of Hours in Auction: ";
        try
        {
            cin >> num;
            DateTime timeRemain = DateTime(num, 0, 0, 0);
            goodNum = true;
        }
        catch (exception e)
        {
            goodNum = false;
        }
    }
    cin.ignore(1);
    
    return stream;
}

ostream & operator << (ostream& stream, Item anItem)
{
    stream << "Name: " << anItem.getName() << endl;
    stream << "Condition: " << anItem.getCondition() << endl;
    stream << "Sell Type: " << anItem.getSellType() << endl;
    stream << "Seller: " << anItem.getSeller() << endl;
    stream << "Sell Price: $" << anItem.getSellPrice() << endl;
    stream << "Sell Price: $" << anItem.getEndPrice() << endl;
    stream << "Course: " << anItem.getCourseTag() << "-" << anItem.getCourseNumber() << endl;
    stream << "Time Remaining: " << anItem.getTimeRemaining() << endl;
    stream << "Date Created: " << anItem.getDateCreated() << endl;
    
    return stream;
}

bool Item::compareTo (Item* i)
{
	if ((seller == i->seller) && (dateCreated.compareTo(i->dateCreated)))
		return true;
	else
		return false;
}

Item& Item::operator = (const Item& rightSide)
{
    name = rightSide.name;
    condition = rightSide.condition;
    sellType = rightSide.sellType;
    seller = rightSide.seller;
    sellPrice = rightSide.sellPrice;
    endPrice = rightSide.endPrice;
    courseTag = rightSide.courseTag;
    courseNumber = rightSide.courseNumber;
    timeRemaining = rightSide.timeRemaining;
    dateCreated = rightSide.dateCreated;
    
    return *this;
}

Item::~Item()
{
    
}

Item::Item(const Item& rightSide)
{
    name = rightSide.name;
    condition = rightSide.condition;
    sellType = rightSide.sellType;
    seller = rightSide.seller;
    sellPrice = rightSide.sellPrice;
    endPrice = rightSide.endPrice;
    courseTag = rightSide.courseTag;
    courseNumber = rightSide.courseNumber;
    timeRemaining = rightSide.timeRemaining;
    dateCreated = rightSide.dateCreated;
}
