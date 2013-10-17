#include <iostream>
#include <fstream>
#include <sstream>
#include "Manual.h"
using namespace std;

Manual::Manual(string Uname, string Ucondition, int UsellType, string Useller, double UsellPrice, double UendPrice, string UCourseTag, int UCourseNumber, DateTime BookTime_Remaining, DateTime BookDate_Created, string suppOf, string publish, double isbn) : Item(Uname, Ucondition, UsellType, Useller, UsellPrice, UendPrice, UCourseTag, UCourseNumber, BookTime_Remaining, BookDate_Created) 
{

	SupplementOf = suppOf;
	publisher = publish;
	ISBN = isbn;

}

string Manual::getSupplementOf() {

	return SupplementOf;

}

void Manual::setSupplementOf(string suppOf) {

	SupplementOf = suppOf;
	return;

}

string Manual::getPublisher() {

	return publisher;

}

void Manual::setPublisher(string publish) {

	publisher = publish;
	return;

}

double Manual::getISBN() {

	return ISBN;

}

void Manual::setISBN(double isbn) {

	ISBN = isbn;
	return;

}

string Manual::toFile() {

    stringstream output;
	output << "\"" << "Manual" << "\"," << Item::toFile();
	output << ",\"" << getSupplementOf() << "\",\"" << getPublisher() << "\",\"" << fixed << setprecision(0) << getISBN() << "\"";
	
	return output.str();
}

istream & operator >> (istream& stream, Manual& aManual)
{
    string input = "";
    
    cout << "Manual Name: ";
    getline(stream, input);
    aManual.setName(input);
    
    do
    {
        cout << "Course Tag: ";
        getline(stream, input);
    }while(input.length() != 3 || ((input[0] >= 48 && input[0] <= 57) || (input[1] >= 48 && input[1] <= 57) || (input[2] >= 48 && input[2] <= 57)));
    input[0] = toupper(input[0]);
    input[1] = toupper(input[1]);
    input[2] = toupper(input[2]);
    aManual.setCourseTag(input);
    
    
    do
    {
        cout << "Course Number: ";
        stream >> input;
        stream.ignore(1);
    }while(input.length() != 3 || atoi(input.c_str()) == 0);
    aManual.courseNumber = atoi(input.c_str());
    
    cout << "Condition: ";
    getline(stream, input);
    aManual.setCondition(input);
    
    do
    {
        cout << "Auction/Trade/Sale: ";
        getline(stream, input);
    }while(input != "auction" && input != "trade" && input != "sale");
    for(unsigned int c = 0; c < input.length(); c++)
    {
        input[c] = tolower(input[c]);
    }
    if(input == "auction")
        aManual.setSellType(0);
    else if(input == "sale")
        aManual.setSellType(1);
    else if(input == "trade")
        aManual.setSellType(2);
    
    do
    {
        cout << "Start Price: $";
        stream >> aManual.sellPrice;
    }while(aManual.sellPrice < 0);
    
    
    if(aManual.sellType == 0)
    {
        do
        {
            cout << "End Price (-1 if no end price is desired)" << endl;
            stream >> aManual.endPrice;
        }while(aManual.endPrice < 0 && aManual.endPrice != -1);
    }
    else
    {
        aManual.endPrice = -1;
    }
    
    int numHours = 0;
    do
    {
        cout << "Number of hours: ";
        stream >> numHours;
    }while(numHours <= 0);
    aManual.timeRemaining = DateTime(numHours, 0, 0, 0);
    stream.ignore(1);
    
    cout << "What does this Manual Go with? (Class Name/Class Textbook Name)" << endl;
    getline(stream, input);
    aManual.setSupplementOf(input);
    
    cout << "Publisher: ";
    getline(stream, input);
    aManual.setPublisher(input);
    
    bool stop = false;
    do
    {
        cout << "Please enter the 13 digit ISBN number (\'r\' to return): ";
        getline(stream, input);
        if(input.length() == 1 && input[0] == 'r')
        {
            stop = true;
        }
    }while(input.length() != 13 && !stop);
    aManual.setISBN(atol(input.c_str()));
    
    return stream;
}
ostream & operator << (ostream& stream, Manual& aManual)
{
    stream << "Name: " << aManual.getName() << endl;
    stream << "Condition: " << aManual.getCondition() << endl;
    stream << "Sell Type: " << aManual.getSellType() << endl;
    stream << "Seller: " << aManual.getSeller() << endl;
    stream << "Sell Price: $" << aManual.getSellPrice() << endl;
    stream << "End Price: $" << aManual.getEndPrice() << endl;
    stream << "Course: " << aManual.getCourseTag() << "-" << aManual.getCourseNumber() << endl;
    stream << "Time Remaining: " << aManual.getTimeRemaining() << endl;
    stream << "Date Created: " << aManual.getDateCreated() << endl;
    
    stream << "Supplement of: " << aManual.getSupplementOf() << endl;
    stream << "Publisher: " << aManual.getPublisher() << endl;
    stream << "ISBN #: " << aManual.getISBN() << endl;
    
    return stream;
}

bool Manual::compareTo(Manual* rhs) {
    
	if ((name == rhs->name) && (condition == rhs->condition) && (sellType == rhs->sellType) && (seller == rhs->seller) && (sellPrice == rhs->sellPrice)
        && (endPrice == rhs->endPrice) && (getTimeRemaining() == rhs->getTimeRemaining()) && (getDateCreated() == rhs->getDateCreated())
        && (courseTag == rhs->courseTag) && (courseNumber == rhs->courseNumber) && (publisher == rhs->publisher) && (SupplementOf == rhs->SupplementOf)
        && (ISBN = rhs->ISBN))
        return true;
	else
        return false;
    
}

Manual& Manual::operator = (const Manual& rightSide)
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
    SupplementOf = rightSide.SupplementOf;
    publisher = rightSide.SupplementOf;
    ISBN = rightSide.ISBN;
    
    return *this;
}

Manual::~Manual()
{
    
}

Manual::Manual(const Manual& rightSide)
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
    SupplementOf = rightSide.SupplementOf;
    publisher = rightSide.SupplementOf;
    ISBN = rightSide.ISBN;
    
}

