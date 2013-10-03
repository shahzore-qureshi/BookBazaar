// Name: eText Synergy Corporation
// Course: CSC 260, Section 2
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Collaborative Team Project
// Description: Implementation of the Book class
//				methods.
// Filename: Book.cpp
// Last modified on: 12/4/11

#include <iostream>
#include <fstream>
#include <sstream>
#include "Book.h"
using namespace std;

Book::Book(string Uname, string Ucondition, int UsellType, string Useller, double UsellPrice,
		double UendPrice, string UCourseTag, int UCourseNumber, DateTime BookTime_Remaining,
		DateTime BookDate_Created, string auth, string publish, string edit, double isbn)
			: Item(Uname, Ucondition, UsellType, Useller, UsellPrice, UendPrice, UCourseTag,
					UCourseNumber, BookTime_Remaining, BookDate_Created)
{

	author = auth;
	publisher = publish;
    edition = atoi(edit.c_str());
	ISBN = isbn;

}

string Book::getAuthor() {
	return author;
}

void Book::setAuthor(string auth) {

	author = auth;
	return;

}

int Book::getEdition() {
    
	return edition;
    
}

void Book::setEdition(string edit) {
    
	edition = atoi(edit.c_str());
	return;
    
}

string Book::getPublisher() {

	return publisher;

}

void Book::setPublisher(string publish) {

	publisher = publish;
	return;

}

double Book::getISBN() {

	return ISBN;

}

void Book::setISBN(double isbn) {

	ISBN = isbn;
	return;
}

istream & operator >> (istream & stream, Book & newBook)
{
    string input;
    cout << "Book Name: ";
    getline(stream, newBook.name);

    do
    {
    cout << "Edition: ";
    getline(stream, input);
    newBook.edition = atoi(input.c_str());
    }while(newBook.edition <= 0);
    
    cout << "Author: ";
    getline(stream, newBook.author);

    
    do
    {
        cout << "ISBN: ";
        getline(stream, input);
    }while(input.length() != 13 && input.find("-") == string::npos);
    newBook.ISBN = atoll(input.c_str());

    
    cout << "Condition: ";
    getline(stream, newBook.condition);

    do
    {
        cout << "Course Tag: ";
        getline(stream, input);
    }while(input.length() != 3 || ((input[0] >= 48 && input[0] <= 57) || (input[1] >= 48 && input[1] <= 57) || (input[2] >= 48 && input[2] <= 57)));
    input[0] = toupper(input[0]);
    input[1] = toupper(input[1]);
    input[2] = toupper(input[2]);
    newBook.setCourseTag(input);
    
    do
    {
        cout << "Course Number: ";
        stream >> input;
        stream.ignore(1);
    }while(input.length() != 3 || atoi(input.c_str()) == 0);
    newBook.courseNumber = atoi(input.c_str());
    
    do
    {
        cout << "Auction/Sell/Trade: ";
        getline(stream, input);
        for(int c = 0; c < input.length(); c++)
        {
            input[c] = tolower(input[c]);
        }
    }while(input != "auction" && input != "sell" && input != "trade");
    if(input == "auction")
        newBook.setSellType(0);
    else if(input == "sell")
        newBook.setSellType(1);
    else if(input == "trade")
        newBook.setSellType(2);
    
    
    do
    {
        cout << "Start Price: $";
        stream >> newBook.sellPrice;
    }while(newBook.sellPrice < 0);

    
    if(newBook.sellType == 0)
    {
        do
        {
            cout << "End Price (-1 if no end price is desired)" << endl;
            stream >> newBook.endPrice;
        }while(newBook.endPrice < 0 && newBook.endPrice != -1);
    }
    else
    {
        newBook.endPrice = -1;
    }

    
    int numHours = 0;
    do
    {
        cout << "Number of hours: ";
        stream >> numHours;
    }while(numHours <= 0);
    stream.ignore(1);
    
    cout << "Publisher: ";
    getline(stream, input);
    newBook.setPublisher(input);
     
    newBook.timeRemaining = DateTime(numHours, 0, 0, 0);
    newBook.dateCreated = DateTime();

    
    return stream;
}

ostream & operator <<(ostream & output, Book & aBook)
{
    output << "Name: " << aBook.getName() << endl;
    output << "Edition: " << aBook.getEdition() << endl;
    output << "Author: " << aBook.getAuthor() << endl;
    output << "ISBN #: " << aBook.getISBN() << endl;
    output << "Course: " << aBook.getCourse() << endl;
    output << "Condition: " << aBook.getCondition() << endl;
    output << "Sell Type: " << aBook.getSellType() << endl;
    output << "Sell Price: $" << aBook.getSellPrice() << endl;
    output << "End Price: $" << aBook.getEndPrice() << endl;
    output << "Publisher: " << aBook.getPublisher() << endl;
    output << "Date Created: " << aBook.getDateCreated() << endl;
    output << "Date Time Remaining: " << aBook.timeRemaining.getDateTime() << endl;

    
    return output;
}

string Book::toFile()
{
    stringstream output;
    
    output << "\"" << "Book" << "\"," << Item::toFile();
    output << ",\"" << getAuthor() << "\",\"" << getEdition() << "\",\"" << getPublisher() << "\",\"" << fixed << setprecision(0) << getISBN() << "\"";
    
    return output.str();
}

bool Book::compareTo(Book* rhs) {
    
	if ((name == rhs->name) && (condition == rhs->condition) && (sellType == rhs->sellType) && (seller == rhs->seller) && (sellPrice == rhs->sellPrice)
        && (endPrice == rhs->endPrice) && (getTimeRemaining() == rhs->getTimeRemaining()) && (getDateCreated() == rhs->getDateCreated())
        && (courseTag == rhs->courseTag) && (courseNumber == rhs->courseNumber) && (author == rhs->author) && (publisher == rhs->publisher)
        && (edition == rhs->edition) && (ISBN = rhs->ISBN))
        return true;
	else
        return false;
    
}


Book& Book::operator = (const Book& rightSide)
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
    author = rightSide.author;
    publisher = rightSide.publisher;
    edition = rightSide.edition;
    ISBN = rightSide.ISBN;
    
    return *this;
}

Book::~Book()
{
    
}

Book::Book(const Book& rightSide)
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
    author = rightSide.author;
    publisher = rightSide.publisher;
    edition = rightSide.edition;
    ISBN = rightSide.ISBN;
}


