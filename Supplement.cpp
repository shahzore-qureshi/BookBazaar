#include "Supplement.h"

Supplement::Supplement(string Uname, string Ucondition, int UsellType, string Useller, double UsellPrice, double UendPrice, string UCourseTag, int UCourseNumber, DateTime BookTime_Remaining, DateTime BookDate_Created, string suppOf) : Item(Uname, Ucondition, UsellType, Useller, UsellPrice, UendPrice, UCourseTag, UCourseNumber, BookTime_Remaining, BookDate_Created) 
{
	SupplementOf = suppOf;
}

string Supplement::getSupplementOf() {

	return SupplementOf;
	
}

void Supplement::setSupplementOf(string suppOf) {

	SupplementOf = suppOf;
	return;
	
}

string Supplement::toFile() {

    stringstream output;
	output << "\"" << "Supplement" << "\"," << Item::toFile();
	output << ",\"" << getSupplementOf() << "\"";
	
	return output.str();

}

istream & operator >> (istream& stream, Supplement& aSupplement)
{
    string input = "";
    
    cout << "Name: ";
    getline(stream, input);
    aSupplement.setName(input);
    
    do
    {
        cout << "Course Tag: ";
        getline(stream, input);
    }while(input.length() > 3 || input.length() < 3);
    input[0] = toupper(input[0]);
    input[1] = toupper(input[1]);
    input[2] = toupper(input[2]);
    aSupplement.setCourseTag(input);
    
    
    do
    {
        cout << "Course Number: ";
        stream >> input;
        stream.ignore(1);
    }while(input.length() != 3 || atoi(input.c_str()) == 0);
    aSupplement.courseNumber = atoi(input.c_str());
    
    cout << "Condition: ";
    getline(stream, input);
    aSupplement.setCondition(input);
    
    do
    {
        cout << "Auction/Trade/Sale: ";
        getline(stream, input);
    }while(input != "auction" && input != "trade" && input != "sale");
    for(int c = 0; c < ((int)input.length()); c++)
    {
        input[c] = tolower(input[c]);
    }
    if(input == "auction")
        aSupplement.setSellType(0);
    else if(input == "sale")
        aSupplement.setSellType(1);
    else if(input == "trade")
        aSupplement.setSellType(2);
    
    do
    {
        cout << "Start Price: $";
        stream >> aSupplement.sellPrice;
    }while(aSupplement.sellPrice < 0);
    
    
    if(aSupplement.sellType == 0)
    {
        do
        {
            cout << "End Price (-1 if no end price is desired)" << endl;
            stream >> aSupplement.endPrice;
        }while(aSupplement.endPrice < 0 && aSupplement.endPrice != -1);
    }
    else
    {
        aSupplement.endPrice = -1;
    }
    
    int numHours = 0;
    do
    {
        cout << "Number of hours: ";
        stream >> numHours;
    }while(numHours <= 0);
    aSupplement.timeRemaining = DateTime(numHours, 0, 0, 0);
    stream.ignore(1);
    
    cout << "Supplement of: ";
    getline(stream, input);
    aSupplement.setSupplementOf(input);
    
    return stream;
}

ostream & operator << (ostream& stream, Supplement& aSupplement)
{
    stream << "Name: " << aSupplement.getName() << endl;
    stream << "Condition: " << aSupplement.getCondition() << endl;
    stream << "Sell Type: " << aSupplement.getSellType() << endl;
    stream << "Seller: " << aSupplement.getSeller() << endl;
    stream << "Sell Price: $" << aSupplement.getSellPrice() << endl;
    stream << "End Price: $" << aSupplement.getEndPrice() << endl;
    stream << "Course: " << aSupplement.getCourseTag() << "-" << aSupplement.getCourseNumber() << endl;
    stream << "Time Remaining: " << aSupplement.getTimeRemaining() << endl;
    stream << "Date Created: " << aSupplement.getDateCreated() << endl;
    
    
    stream << "Supplement of: " << aSupplement.getSupplementOf() << endl;
    
    return stream;
}

bool Supplement::compareTo(Supplement* rhs) {
    
	if ((name == rhs->name) && (condition == rhs->condition) && (sellType == rhs->sellType) && (seller == rhs->seller) && (sellPrice == rhs->sellPrice)
        && (endPrice == rhs->endPrice) && (getTimeRemaining() == rhs->getTimeRemaining()) && (getDateCreated() == rhs->getDateCreated())
        && (courseTag == rhs->courseTag) && (courseNumber == rhs->courseNumber) && (SupplementOf == rhs->SupplementOf))
        return true;
	else
        return false;
    
}


Supplement& Supplement::operator = (const Supplement& rightSide)
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
    
    return *this;
}

Supplement::~Supplement()
{
    
}

Supplement::Supplement(const Supplement& rightSide)
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
}

