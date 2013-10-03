//
//  UserInterface.cpp
//  BookBazaar
//
//  Created by Steven Zilberberg on 11/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "UserInterface.h"

UserInterface::UserInterface()
{
    indexAllItems = 0;
    indexItemList = 0;
    indexAllMembers = 0;
    indexOfCurrentUser = 0;
}

bool UserInterface::check(string file)          //Checks for file existance
{
    ifstream inFile(file.c_str());
    if(inFile)
    {
        inFile.close();
        return true;
    }
    else
    {
        inFile.close();
        return false;
    }
}

bool UserInterface::check(string file, int& number)     //Checks for file existance and counts num lines
{
    ifstream inFile(file.c_str());
    if(inFile)
    {
        string line;
        while(getline(inFile, line))
        {
            number++;
        }
        inFile.close();
        return true;
    }
    else
    {
    	inFile.close();
        return false;
    }
}

string UserInterface::allToUpper(string word)
{
    for(int c = 0; c < (int)word.length(); c++)
    {
        word[c] = toupper(word[c]);
    }
    return word;
}

string UserInterface::getInput(string msg)
{
    cout << msg;
    string input = "";
    getline(cin, input);
    return input;
}

char UserInterface::getInputChar(string msg)
{
    string input = "";
    do
    {
        input = "";
        cout << msg;
        getline(cin, input);
    }while((int)input.length() > 1);

    return (tolower(input[0]));
}

Member UserInterface::parseMember(string input)        //Parses member line and return real member instance
{
    stringstream memberInput(input);        //stream (acts like file to easily parse through line)
    string info = "";
    Member newMember = Member();
    DateTime memberCreationDate = DateTime();
    memberCreationDate.setIsDateTime(true);
    int infoCount = 0;
    while(getline(memberInput, info, ','))
    {
        int begin = (int)info.find('\"') + 1;
        info = info.substr(begin, info.length() - 2 );
        switch(infoCount)                               //depending on which "item" is retrieved, that piece is put into the object
        {
            case 0:
            {
                newMember.setLastName(info);
                break;
            }
            case 1:
            {
                newMember.setFirstName(info);
                break;
            }
            case 2:
            {
                newMember.setEmail(info);
                break;
            }
            case 3:
            {
                newMember.setUsername(info);
                break;
            }
            case 4:
            {
                newMember.setPassword(info);
                break;
            }
            case 5:
            {
                memberCreationDate.setMonth(atoi(info.c_str()));
                break;
            }
            case 6:
            {
                memberCreationDate.setDay(atoi(info.c_str()));
                break;
            }
            case 7:
            {
                memberCreationDate.setYear(atoi(info.c_str()));
                break;
            }
            case 8:
            {
                memberCreationDate.setHour(atoi(info.c_str()));
                break;
            }
            case 9:
            {
                memberCreationDate.setMinute(atoi(info.c_str()));
                break;
            }
            case 10:
            {
                memberCreationDate.setSecond(atoi(info.c_str()));
                break;
            }
            case 11:
            {
                memberCreationDate.setMilliseconds(atoi(info.c_str()));
                break;
            }
        }
        infoCount++;
    }
    newMember.setCreationTime(memberCreationDate);  //Sets the creation time
    return newMember;       //returns member
}

Book* UserInterface::parseBook(string input)            //parses book line and returns real book instance
{
	stringstream itemInput(input);        //stream (acts like file to easily parse through line)
	string info = "";
	DateTime bookCreationDate = DateTime();
	DateTime bookTimeRemaining = DateTime();
	bookCreationDate.setIsDateTime(true);
	bookTimeRemaining.setIsTime(true);
	int infoCount = 0;
	getline(itemInput, info, ',');                          //This gets
	int begin = (int)info.find('\"') + 1;                   //the first
	info = info.substr(begin, info.length() - 2 );          //data type
	Book *newBook = new Book;
	while(getline(itemInput, info, ','))
	{
		begin = (int)info.find('\"') + 1;
		info = info.substr(begin, info.length() - 2 );
		switch(infoCount)                               //depending on which "item" is retrieved, that piece is put into the object
		{
		case 0:
		{
			newBook->setName(info);
			break;
		}
		case 1:
		{
			newBook->setCourseTag(info);
			break;
		}
		case 2:
		{
			newBook->setCourseNumber(atoi(info.c_str()));
			break;
		}
		case 3:
		{
			newBook->setCondition(info);
			break;
		}
		case 4:
		{
			newBook->setSellType(atoi(info.c_str()));
			break;
		}
		case 5:
		{
			newBook->setSeller(info);
			break;
		}
		case 6:
		{
			newBook->setSellPrice(atof(info.c_str()));
			break;
		}
		case 7:
		{
			newBook->setEndPrice(atof(info.c_str()));
			break;
		}
		case 8:
		{
			bookTimeRemaining.setHour(atoi(info.c_str()));
			break;
		}
		case 9:
		{
			bookTimeRemaining.setMinute(atoi(info.c_str()));
			break;
		}
		case 10:
		{
			bookTimeRemaining.setSecond(atoi(info.c_str()));
			break;
		}
		case 11:
		{
			bookTimeRemaining.setMilliseconds(atoi(info.c_str()));
			break;
		}
		case 12:
		{
			bookCreationDate.setMonth(atoi(info.c_str()));
			break;
		}
		case 13:
		{
			bookCreationDate.setDay(atoi(info.c_str()));
			break;
		}
		case 14:
		{
			bookCreationDate.setYear(atoi(info.c_str()));
			break;
		}
		case 15:
		{
			bookCreationDate.setHour(atoi(info.c_str()));
			break;
		}
		case 16:
		{
			bookCreationDate.setMinute(atoi(info.c_str()));
			break;
		}
		case 17:
		{
			bookCreationDate.setSecond(atoi(info.c_str()));
			break;
		}
		case 18:
		{
			bookCreationDate.setMilliseconds(atoi(info.c_str()));
			break;
		}
		case 19:
		{
			newBook->setAuthor(info);
			break;
		}
		case 20:
		{
			newBook->setEdition(info);
			break;
		}
		case 21:
		{
			newBook->setPublisher(info);
			break;
		}
		case 22:
		{
			newBook->setISBN(atof(info.c_str()));
			break;
		}
		}
		infoCount++;
	}
	newBook->setTimeRemaining(bookTimeRemaining);  //Sets the time remaining
	newBook->setDateCreated(bookCreationDate);       //Sets the creation date
	return newBook;
}

Manual* UserInterface::parseManual(string input)
{
    stringstream itemInput(input);        //stream (acts like file to easily parse through line)
    string info = "";
    DateTime bookCreationDate = DateTime();
    DateTime bookTimeRemaining = DateTime();
    bookCreationDate.setIsDateTime(true);
    bookTimeRemaining.setIsTime(true);
    int infoCount = 0;
    getline(itemInput, info, ',');                          //This gets
    int begin = (int)info.find('\"') + 1;                   //the first
    info = info.substr(begin, info.length() - 2 );          //data type
    Manual *newManual = new Manual;
    while(getline(itemInput, info, ','))
    {
        begin = (int)info.find('\"') + 1;
        info = info.substr(begin, info.length() - 2 );
        switch(infoCount)                               //depending on which "item" is retrieved, that piece is put into the object
        {
            case 0:
            {
                newManual->setName(info);
                break;
            }
            case 1:
            {
                newManual->setCourseTag(info);
            }
            case 2:
            {
                newManual->setCourseNumber(atoi(info.c_str()));
                break;
            }
            case 3:
            {
                newManual->setCondition(info);
                break;
            }
            case 4:
            {
                newManual->setSellType(atoi(info.c_str()));
                break;
            }
            case 5:
            {
                newManual->setSeller(info);
                break;
            }
            case 6:
            {
                newManual->setSellPrice(atof(info.c_str()));
                break;
            }
            case 7:
            {
                newManual->setEndPrice(atof(info.c_str()));
                break;
            }
            case 8:
            {
                bookTimeRemaining.setHour(atoi(info.c_str()));
                break;
            }
            case 9:
            {
                bookTimeRemaining.setMinute(atoi(info.c_str()));
                break;
            }
            case 10:
            {
                bookTimeRemaining.setSecond(atoi(info.c_str()));
                break;
            }
            case 11:
            {
                bookTimeRemaining.setMilliseconds(atoi(info.c_str()));
                break;
            }
            case 12:
            {
                bookCreationDate.setMonth(atoi(info.c_str()));
                break;
            }
            case 13:
            {
                bookCreationDate.setDay(atoi(info.c_str()));
                break;
            }
            case 14:
            {
                bookCreationDate.setYear(atoi(info.c_str()));
                break;
            }
            case 15:
            {
                bookCreationDate.setHour(atoi(info.c_str()));
                break;
            }
            case 16:
            {
                bookCreationDate.setMinute(atoi(info.c_str()));
                break;
            }
            case 17:
            {
                bookCreationDate.setSecond(atoi(info.c_str()));
                break;
            }
            case 18:
            {
                bookCreationDate.setMilliseconds(atoi(info.c_str()));
                break;
            }
            case 19:
            {
                newManual->setSupplementOf(info);
                break;
            }
            case 20:
            {
                newManual->setPublisher(info);
                break;
            }
            case 21:
            {
                newManual->setISBN(atof(info.c_str()));
                break;
            }
        }
        infoCount++;
    }
    newManual->setTimeRemaining(bookTimeRemaining);  //Sets the time remaining
    newManual->setDateCreated(bookCreationDate);       //Sets the creation date
    return newManual;
}

Supplement* UserInterface::parseSupplement(string input)
{
    stringstream itemInput(input);        //stream (acts like file to easily parse through line)
    string info = "";
    DateTime bookCreationDate = DateTime();
    DateTime bookTimeRemaining = DateTime();
    bookCreationDate.setIsDateTime(true);
    bookTimeRemaining.setIsTime(true);
    int infoCount = 0;
    getline(itemInput, info, ',');                          //This gets
    int begin = (int)info.find('\"') + 1;                   //the first
    info = info.substr(begin, info.length() - 2 );          //data type
    Supplement *newSupplement = new Supplement;
    while(getline(itemInput, info, ','))
    {
        begin = (int)info.find('\"') + 1;
        info = info.substr(begin, info.length() - 2 );
        switch(infoCount)                               //depending on which "item" is retrieved, that piece is put into the object
        {
            case 0:
            {
                newSupplement->setName(info);           
                break;
            }
            case 1:
            {
                newSupplement->setCourseTag(info);
            }
            case 2:
            {
                newSupplement->setCourseNumber(atoi(info.c_str()));
                break;
            }
            case 3:
            {
                newSupplement->setCondition(info);
                break;
            }
            case 4:
            {
                newSupplement->setSellType(atoi(info.c_str()));
                break;
            }
            case 5:
            {
                newSupplement->setSeller(info);
                break;
            }
            case 6:
            {
                newSupplement->setSellPrice(atof(info.c_str()));
                break;
            }
            case 7:
            {
                newSupplement->setEndPrice(atof(info.c_str()));
                break;
            }
            case 8:
            {
                bookTimeRemaining.setHour(atoi(info.c_str()));
                break;
            }
            case 9:
            {
                bookTimeRemaining.setMinute(atoi(info.c_str()));
                break;
            }
            case 10:
            {
                bookTimeRemaining.setSecond(atoi(info.c_str()));
                break;
            }
            case 11:
            {
                bookTimeRemaining.setMilliseconds(atoi(info.c_str()));
                break;
            }
            case 12:
            {
                bookCreationDate.setMonth(atoi(info.c_str()));
                break;
            }
            case 13:
            {
                bookCreationDate.setDay(atoi(info.c_str()));
                break;
            }
            case 14:
            {
                bookCreationDate.setYear(atoi(info.c_str()));
                break;
            }
            case 15:
            {
                bookCreationDate.setHour(atoi(info.c_str()));
                break;
            }
            case 16:
            {
                bookCreationDate.setMinute(atoi(info.c_str()));
                break;
            }
            case 17:
            {
                bookCreationDate.setSecond(atoi(info.c_str()));
                break;
            }
            case 18:
            {
                bookCreationDate.setMilliseconds(atoi(info.c_str()));
                break;
            }
            case 19:
            {
                newSupplement->setSupplementOf(info);
                break;
            }
        }
        infoCount++;
    }
    newSupplement->setTimeRemaining(bookTimeRemaining);  //Sets the time remaining
    newSupplement->setDateCreated(bookCreationDate);       //Sets the creation date
    return newSupplement;
}

void UserInterface::importItems(string fileName)
{

    ifstream inFile(fileName.c_str());
    string line = "";
    string identifier = "";
    Stack<Book*> bookStack;
    Stack<Manual*> manualStack;
    Stack<Supplement*> SupplementStack;
    while(getline(inFile, line))
    {
        string info = "";
        stringstream itemInput(line);
        getline(itemInput, info, ',');                          //This gets
        int begin = (int)info.find('\"') + 1;                   //the first
        info = info.substr(begin, info.length() - 2 );          //data type
        if(info == "Book")
        {
            bookStack.push(parseBook(line));
        }
        else if(info == "Manual")
        {
            manualStack.push(parseManual(line));
        }
        else if(info == "Supplement")
        {
            SupplementStack.push(parseSupplement(line));
        }
    }

    while(!bookStack.isEmpty())
    {
        Book* peekedBook = bookStack.peek();
        allItems = expandItems(peekedBook, allItems, indexAllItems);
        bookStack.pop();
    }
    while(!manualStack.isEmpty())
    {
        Manual* peekedManual = manualStack.peek();
        allItems = expandItems(peekedManual, allItems, indexAllItems);
        manualStack.pop();
    }
    while(!SupplementStack.isEmpty())
    {
        Supplement* peekedSupplement = SupplementStack.peek();
        allItems = expandItems(peekedSupplement, allItems, indexAllItems);      //SPLICING ISSUE
        SupplementStack.pop();
    }
}

int UserInterface::menuSearchParameters()
{
    cout << "Search by -" << endl;
    cout << "\t 1 - Title Name" << endl;
    //cout << "\t 2 - Author Name" << endl;
    cout << "\t 2 - Class Tag" << endl;
    //cout << "\t 4 - ISBN" << endl;
    cout << "\t r - Return" << endl;
    
    cout << "Option: ";
    return 5;
}

int UserInterface::mainMenuParameters()
{
	cout << "Welcome to Lions BookBazaar. Please select a function" << endl;
    cout << "\t 1 - Post an Item" << endl;
    cout << "\t 2 - Modify Postings" << endl;
    cout << "\t 3 - Search" << endl;
    cout << "\t 4 - Account Settings" << endl;
    cout << "\t r - Logout" << endl;
    cout << "Option: ";
    return 5;
}

int UserInterface::postMenuParameters()
{
	cout << "What would you like to post?" << endl;
    cout << "\t 1 - Book" << endl;
    cout << "\t 2 - Manual" << endl;
    cout << "\t 3 - Supplement" << endl;
    cout << "\t r - Return" << endl;
    cout << "Option: ";
    return 4;
}

void UserInterface::searchDatabase()
{
    char option;
    string type = "";
    string input = "";
    Stack<int> matches = Stack<int>();
    do
    {
        bool stop = false;
        menuSearchParameters();
        option = getInputChar("");
        switch (option)
        {
            case '1':
            {
                type = kType_Title;
                // string targetTitle = "";
                input = getInput("Please Enter the name of the book as it would appear on book (type \'r\' to return): ");
                if(input.length() == 1 && input[0] == kReturn)
                {
                    type = "";
                }
                break;
            }
                /*case '2':
                 {
                 type = kType_Author;
                 //string targetAuthor = "";
                 input = getInput("Please Enter the Full Name of the Author as it would appear on book (type \'r\' to return): ");
                 if(input.length() == 1 && input[0] == kReturn)
                 {
                 type = "";
                 }
                 break;
                 }*/
            case '2':
            {
                type = kType_Class;
                //string classSymbol = "";
                string classNumber = "";
                do 
                {
                    input = getInput("Please enter the 3 letter class Symbol (type \'r\' to return): ");
                    if(input.length() == 1 && input[0] == kReturn)
                    {
                        type = "";
                        stop = true;
                    }
                    classNumber = getInput("Please Enter the class number: ");
                }while ((input.length() < 3 || input.length() > 3) && !stop);
                break;
            }
                /*case '3':
                 {
                 type = kType_ISBN;
                 do
                 {
                 input = getInput("Please enter the 13 digit ISBN number (\'r\' to return): ");
                 if(input.length() == 1 && input[0] == kReturn)
                 {
                 stop = true;
                 type = "";
                 }
                 }while(input.length() != 13 && !stop);
                 break;
                 }*/
        }
        if(!stop)
        {
            if(type != "")
            {
                stringstream msg;
                bool hasMatches = search(type, input, matches);
                
                if(hasMatches)
                {

                    cout << "Has Matches: " << endl;
                    int targetIndex = 0;
                    msg << matches.size() << " Matches for " << type << " " << input;
                    cout << "***************" << msg.str() << "***************" << endl;
                    int counter = -1;
                    int countArray[50]; //Only show 50 search results
                    while(!matches.isEmpty())
                    {
                        targetIndex = matches.peek();
                        if(targetIndex != -1)
                        {
                            counter++;
                            countArray[counter] = targetIndex;
                            cout << counter+1 << ") " << allItems[targetIndex]->getName() << endl;
                            //cout << "\t" << allItems[targetIndex]->getSellPrice() << endl;
                            cout << "********************************************" << endl;
                            matches.pop();
                        }
                    }
                    
                    int choice;
                    cout << "Please enter the number of the search result you would like to view: ";
                    cin >> choice;
                    
                    if (choice <= 0 || choice > (counter + 1) || ((allItems[countArray[choice-1]]->getSeller()) == currentMember.getUsername()))
                    {
                        cout << "Invalid choice." << endl;
                        
                        if ((allItems[countArray[choice-1]]->getSeller()) == currentMember.getUsername())
                            cout << "You can't purchase your own item!" << endl;
                        
                        option = kReturn;
                        
                    }
                    else
                    {
                        cout << endl << "***************" << " Item Information " << "***************" << endl;
                        cout << *allItems[countArray[choice-1]] << endl;
                        
                        int sellType = allItems[countArray[choice-1]]->getSellType();
                        
                        switch (sellType)
                        {
                            case (0):   //Auction
                                cout << "This is an auction. Current bid price is: " << allItems[countArray[choice-1]]->getSellPrice() << endl;
                                cout << "Would you like to bid? (y or n): ";
                                char choice;    //Yes or No
                                cin >> choice;
                                //convert character to lower case
                                
                                if (choice == 'y')
                                {
                                    bid(allItems[countArray[choice-1]]);
                                }
                                else if (choice == 'n')
                                {
                                    //do nothing. return to main menu.
                                }
                                
                                break;
                            case (1):   //Trade
                                cout << "This is a trade. " << endl;
                                trade(allItems[countArray[choice-1]]);
                                break;
                            case (2):   //Sale 
                                cout << "This is a sale." << endl;
                                buy(allItems[countArray[choice-1]]);
                                break;
                            default:
                                cout << "Item has an unknown sale type. Sorry for the inconvenience." << endl;
                                break;
                        }
                        
                    option = kReturn;  //End the loop
                        
                    }
                }
                    
                else
                {
                    cout << "***************" << "0 Matches for " << input << "***************" << endl;
                }
            }
        }
    }while (option != kReturn);
    
    cin.ignore(80, '\n');
    
}

template<class T>
bool UserInterface::search(string type, string data, Stack<T>& matches)
{
    if(type == kType_Title)
    {
        bool found = false;
        for(int i = 0; i < indexAllItems; i++)
        {
            if(allItems[i]->getName() == data)
            {
                matches.push(i);
                found = true;
            }
        }
        if(found == true)
            return true;
        else
            return false;
    }
    /*else if(type == kType_Author)
     {
     bool found = false;
     for(int i = 0; i < indexAllItems; i++)
     {
     if(allItems[i]->getAuthor() == data)
     {
     matches.push(i);
     found = true;
     }
     }
     if(found == true)
     return true;
     else
     return false;
     }*/
    else if(type == kType_Class)
    {
        bool found = false;
        for(int i = 0; i < indexAllItems; i++)
        {
            if(allItems[i]->getCourseTag() == data)
            {
                matches.push(i);
                found = true;
            }
        }
        if(found == true)
            return true;
        else
            return false;
    }
    /*else if(type == kType_ISBN)
     {
     long targetISBN = 0;
     try
     {
     targetISBN = atoll(data.c_str());
     }
     catch(exception e)
     {
     cout << "ISBN number must be all integers! You inputted: " << data << endl;
     return false;
     }
     for(int c = 0; c < indexAllItems; c++)
     {
     //if(allItems[c].getISBN() == targetISBN)
     //    matches.push(c);
     }
     if(matches.isEmpty())
     return false;
     else
     return true;
     }*/
    else
    {
        return false;
    }
}
//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

bool UserInterface::start(string& errorMsg)
{
    ifstream inFile(kFile_Member.c_str());
    int memberSize = 0;
    if(!check(kFile_Member, memberSize))
    {
        errorMsg += kFile_Member + " Not Found";
        errorMsg += "\nCreating New File...";

        ofstream outputFile;

        outputFile.open(kFile_Member.c_str());

        if (outputFile.fail())
        {
        	cerr << "Error. File could not be written." << endl;;
        	outputFile.clear();
        }

        errorMsg += "\nPlease reboot program.";
        outputFile.close();

        return false;
    }
    else
    {
    	if(memberSize != 0)
    		allMembers = new Member[memberSize];
    	else
    		allMembers = new Member[1];
    	string line = "";
        for(int c = 0; c < memberSize; c++)
        {
            getline(inFile, line);
            Member addedMember = parseMember(line);
            allMembers = expandMembers(addedMember, allMembers, indexAllMembers);
        }
    }

    inFile.close();

    int bookSize = 0;
    if(!check(kFile_Item, bookSize))
    {
        errorMsg += kFile_Item + " Not Found!";

        errorMsg += "\nCreating New File...";

        ofstream outputFile;

        outputFile.open(kFile_Item.c_str());

        if (outputFile.fail())
        {
        	cerr << "Error. File could not be written." << endl;;
        	outputFile.clear();
        }

        errorMsg += "\nPlease reboot program.";
        outputFile.close();

        return false;
    }
    else
    {
    	if(bookSize != 0)
    		allItems = new Item*[bookSize];
    	else
    		allItems = new Item*[1];
    	importItems(kFile_Item);
    }
    return true;
}

void UserInterface::display(Member* array, int size)
{
    cout << "SHOWING" << endl;
    for(int c = 0; c < size; c++)
    {
        cout << array[c] << endl;
    }
}

bool UserInterface::menuLoginScreen()
{
    bool endMenu = false;
    while(endMenu == false)
    {
        cout << "Please enter: \n1 - If you're a returning user \n2 - If you're a new user.\nr - To Exit" << endl;
        char menuSelection;
        menuSelection = getInputChar("");

        if(menuSelection == '1')
        {
            string returningUser;
            string passcode;
            cout << "Please enter your username: " << endl;
            cin >> returningUser;
            cout << "Please enter your password: " << endl;
            cin >> passcode;
            for(int i = 0; i < indexAllMembers; i++)
            {
                if(allMembers[i].getUsername() == returningUser)
                {
                    if(allMembers[i].getPassword() == passcode)
                    {
						currentMember = allMembers[i];
                        indexOfCurrentUser = i;
                        return true;
                        
                    }
                }                   
            }
            
            cout << "Invalid username or password." << endl;
            cin.ignore(80, '\n');
        }
        
        else if(menuSelection == '2')
        {
            Member newMember;
            cin >> newMember;

            allMembers = expandMembers(newMember, allMembers, indexAllMembers);

            save();
            cout << "Member is added to the system." << endl;
        }
        else if(menuSelection == 'r')
        {
            cin.clear();
            return false;
        }
        
        else if(cin.fail())
        {
            cin.clear();
            cout << "Invalid entry." << endl;     
        }
        
        else
        {
            cin.clear();
            cout << "Invalid entry." << endl;
        }
    }
    return true;
}

template<class T, class X>
X** UserInterface::expandItems(T& newItem, X** array, int& index)           //create new function for members!!!!
{
    index++;
    X** newarray = new X*[index];

    for(int c = 0; c < (index - 1); c++)
    {
        newarray[c] = array[c];
    }
    
    newarray[index - 1] = newItem;

    delete [] array;
    
    array = newarray;

    return array;
}


Member* UserInterface::expandMembers(Member& newItem, Member* array, int& index)           //create new function for members!!!!
{
    index++;
    Member* newarray = new Member[index];
    
    for(int c = 0; c < (index - 1); c++)
    {
        newarray[c] = array[c];
    }
    newarray[index - 1] = newItem;
    
    delete [] array;
    
    array = newarray;
    
    return array;
}

template <class T, class X>
X** UserInterface::contractArray(T& item, X** array, int& index) {

	X** newarray;
	index--;

	newarray = new X*[index];

	int deleteindex = -1;
	for (int i=0; i<(index+1); i++) {
		if ((array[i]->compareTo(item)) && (deleteindex == -1)) {
			deleteindex = i;
		}
	}

	if (deleteindex > -1) {
		for (int i=0; i<=deleteindex; i++) {
			newarray[i] = array[i];
		}

		for (int i = deleteindex; i<index; i++) {
			newarray[i] = array[(i+1)];
		}
	}

	delete[] array;
	array = newarray;

	return array;

}


void UserInterface::mainMenu() {

    char option;
	cin.ignore();

    do
    {
		mainMenuParameters();
        option = getInputChar("");
        itemList = getTargetItemList(allItems, indexAllItems, indexItemList);
        switch (option) {
		
			case '1' : { 
                postBook();
                option = ' ';
                break;
			}
			
			case '2' : { 
                menuBookEdit();
                option = ' ';
                break;
			}
			
			case '3' : { 
                searchDatabase(); 
                option = ' ';
                break;
			}
			
			case '4' : { 
                currentMember.viewDetails();
                allMembers[indexOfCurrentUser] = currentMember;
                option = ' ';
                break;
			}
		}
        save();
	}
	while(option != kReturn); 
}

Item** UserInterface::getTargetItemList(Item** array, int index, int& userIndex)
{
    Stack<Item*> matches = Stack<Item*>();
    for(int c = 0; c < index; c++)
    {
        if(array[c]->getSeller() == currentMember.getUsername())
        {
            matches.push(array[c]);
        }
    }
    Item** newItemList = new Item*[matches.size()];
    userIndex = matches.size();
    for(int c = 0; !matches.isEmpty(); c++)
    {
        newItemList[c] = matches.peek();
        matches.pop();
    }
    return newItemList;
}


void UserInterface::postBook() { //Needs to add book to the user's ?

    char option;

    do
    {
		postMenuParameters();
        option = getInputChar("");
        switch (option) {

			case '1' : {
			Book *newBook = new Book();
			cin >> *newBook;    
            newBook->setSeller(currentMember.getUsername());
                  
                
            allItems = expandItems(newBook, allItems, indexAllItems);
			cout << "Item posted!" << endl;
			itemList = expandItems(newBook, itemList, indexItemList);
			break;
			}
			
			case '2' : {
			Manual *newManual = new Manual();
			cin >> *newManual;
            newManual->setSeller(currentMember.getUsername());
            
            
            allItems = expandItems(newManual, allItems, indexAllItems);
			cout << "Item posted!" << endl;
			itemList = expandItems(newManual, itemList, indexItemList);
			break;
			}
			
			case '3' : {
			Supplement *newSupplement = new Supplement();
			cin >> *newSupplement;
            newSupplement->setSeller(currentMember.getUsername());
                
            allItems = expandItems(newSupplement, allItems, indexAllItems);
			cout << "Item posted!" << endl;
			itemList = expandItems(newSupplement, itemList, indexItemList);
			break;
			}
		}
        save();
	}
	while(option != kReturn);
}

void UserInterface::menuBookEdit()
{
    
    char menuSelector;
    bool menuCloser = false;
    while(menuCloser == false)
    {
        cout << "Your Item list consists the of the following books: " << endl << endl;
        int bookNum = 1;
        for(int i = 0; i < indexItemList; i++){
            cout << "\t" << bookNum << ". " << itemList[i]->getName() << endl;
            bookNum++;       
        }
        cout << endl;
        
        cout << "Would you like to: \n1 - Edit current books  \n2 - Delete a book from the list" << "\nr - Go back to last menu" << endl;
        string input = getInput("");
        menuSelector = input[0];
        if(menuSelector == '1')
        {
            if (indexItemList > 0)
            {
                menuBookEditSecond();
                //clear screen
            }
            else
            {
                cout << "You have no books." << endl;
            }
        }
        
        else if(menuSelector == '2')
        {
            if (indexItemList > 0)
            {
                string option = getInput("Enter the index of the item you would like to Delete: ");
                int targetIndex = atoi(option.c_str()) - 1;
                if(targetIndex > -1 && targetIndex < indexItemList)
                {
                    allItems = contractArray(allItems[targetIndex], allItems, indexAllItems);
                    itemList = contractArray(itemList[targetIndex], itemList, indexItemList);
                }
            }
            else
            {
                cout << "You have no books." << endl;
            }
        }
        
        //Closes the edit book menu and edit book listing functions.
        else if(menuSelector == 'r')
            menuCloser = true; 
        
        //Checks for invalid data entry (AKA, entering a string instead of an int.)
        else if(cin.fail()){
            cout << "Invalid Entry. Reenter numbered selection." << endl;
            cin.clear();
        }
        
        else
            cout << "Invalid Entry. Reenter numbered selection." << endl;
    }
}

void UserInterface::menuBookEditSecond()
{
    string option;
    option = getInput("Enter the index of the item you would like to edit: ");
    int targetIndex = atoi(option.c_str()) - 1;
    if(targetIndex < indexItemList && itemList[targetIndex] != NULL) //If book is found, the following code is implemented.
    {
        Item* targetItem = itemList[targetIndex];
        allItems = contractArray(targetItem, allItems, indexAllItems);
        itemList = contractArray(targetItem, itemList, indexItemList);
        
        bool menuEnd = false;
        while(menuEnd == false)
        {
            cout << "Enter the number of the option you would like to select: " << endl;
            cout << "1.  Edit book Name" << endl;
            cout << "2.  Edit course" << endl;
            cout << "3.  Edit book condition" << endl;
            cout << "4.  Edit sell type" << endl;
            cout << "5.  Edit start price" << endl;
            cout << "6.  Edit end price " << endl; 
            cout << "7.  Edit time remaining" << endl;
            cout << "8.  View All Information" << endl;
            cout << "9.  Go back a menu" << endl;
            
            int menuSelector;
            menuSelector = atoi(getInput("").c_str());
            
            if(menuSelector == 1)
            {
                cout << "Current Name: " << targetItem->getName() << endl;
                string newBookName = getInput("Enter in a new item name: ");
                if(cin.fail())
                {
                    cout << "Invalid input." << endl;
                    return;
                }                           
                targetItem->setName(newBookName);
            }
            
            else if(menuSelector == 2)
            {
                string newCourseName = "";
                cout << "Current Course Tag: " << targetItem->getCourse() << endl;
                while(newCourseName.length() != 3)
                {
                    newCourseName = getInput("Enter in a new course tag: ");
                    newCourseName = allToUpper(newCourseName);
                }
                int newCourseNum = 0;
                while(newCourseNum > 999 || newCourseNum < 100)
                {
                    newCourseNum = atoi(getInput("Enter in a new course Number:").c_str());
                }
                if(cin.fail())
                {
                    cout << "Invalid input." << endl;
                    return;
                }                           
                targetItem->setCourseTag(newCourseName);
                targetItem->setCourseNumber(newCourseNum);
            }
            
            else if(menuSelector == 3)
            {
                cout << "Current Book Condition: " << targetItem->getCondition() << endl;
                string newBookCondition = getInput("Enter in a new book condition: ");
                if(cin.fail())
                {
                    cout << "Invalid input." << endl;
                    return;
                }                           
                targetItem->setCondition(newBookCondition);
            }
            
            else if(menuSelector == 4)
            {
                int currentType = targetItem->getSellType();
                if(currentType == 0)
                    cout << "Current Sell Type: Auction" << endl;
                else if(currentType == 1)
                    cout << "Current Sell Type: Trade" << endl;
                else if(currentType == 2)
                    cout << "Current Sell Type: Sale" << endl;
                
                string input = "";
                do
                {
                    cout << "Auction/Trade/Sale: ";
                    input = getInput("");
                    for(int c = 0; c < ((int)input.length()); c++)
                    {
                        input[c] = tolower(input[c]);
                    }
                }while(input != "auction" && input != "trade" && input != "sale");
                
                if(input == "auction")
                    targetItem->setSellType(0);
                else if(input == "sale")
                    targetItem->setSellType(1);
                else if(input == "trade")
                    targetItem->setSellType(2);
            }
            
            else if(menuSelector == 5)
            {
                cout << "Current Start Price: $" << fixed << setprecision(2) << targetItem->getSellPrice() << endl;
                double editedVariable = atoi(getInput("Enter in a new start price: $" ).c_str());
                if(cin.fail())
                {
                    cout << "Invalid input." << endl;
                    return;
                }                           
                targetItem->setSellPrice(editedVariable);
            }
            
            else if(menuSelector == 6)
            {
                cout << "Current End Price: $" << fixed << setprecision(2) << targetItem->getEndPrice() << endl;
                double editedVariable = atoi(getInput("Enter in a new end price: $" ).c_str());
                cout << "SHOULD BE: " << editedVariable << endl;
                if(cin.fail())
                {
                    cout << "Invalid input." << endl;
                    return;
                }                           
                targetItem->setEndPrice(editedVariable);
            }
            
            else if(menuSelector == 7)
            {
                cout << "Current Time Remaining: " << targetItem->getTimeRemaining() << endl;
                int timeRemaning = 0;
                while(timeRemaning < 1)
                {
                    timeRemaning = atoi(getInput("End new time remaining: ").c_str());
                }
                targetItem->setTimeRemaining(DateTime(timeRemaning, 0, 0, 0));
            }
            
            else if(menuSelector == 8)
                cout << *targetItem << endl;
            
            else if(menuSelector == 9)
                menuEnd = true;
            
            else if(cin.fail()){
                cout << "Invalid entry" << endl;
                cin.clear();
            }
            
            else
                cout << "Invalid entry" << endl;                    
        }
        
        allItems = expandItems(targetItem, allItems, indexAllItems);
        itemList = expandItems(targetItem, itemList, indexItemList);
    }
}

void UserInterface::save()
{
	ofstream outputFile1;

	outputFile1.open(kFile_Member.c_str());

	if (outputFile1.fail())
	{
		cerr << "Error. File could not be written." << endl;
		outputFile1.clear();
	}
	else
	{
		for (int i=0; i<indexAllMembers; i++) {
			outputFile1 << allMembers[i].toFile() << endl;
		}
	}
	outputFile1.close();

	ofstream outputFile2;
	outputFile2.open(kFile_Item.c_str());

	if (outputFile2.fail())
	{
		cerr << "Error. File could not be written." << endl;
		outputFile2.clear();
	}
	else
	{
		for (int i=0; i<indexAllItems; i++) {
			outputFile2 << allItems[i]->toFile() << endl;
		}
	}
	outputFile2.close();

}


void UserInterface::buy (Item* book)
{
    string username;
    string email;
    
    for (int c=0; c<indexAllItems; c++) {
        if (allItems[c] -> compareTo(book)) {
            for (int d=0; d<indexAllMembers; d++) {
                if (allMembers[d].getUsername() == allItems[c]->getSeller()) {
                    username = allMembers[d].getUsername();
                    email = allMembers[d].getEmail();
                }
            }
        }
    }
	
    cout << username << "'s email address is " << email << ". Please contact the seller to arrange your transaction." << endl;
    
    cin.ignore(1);
}

void UserInterface::trade (Item* book)
{
    string username;
    string email;
    
    for (int c=0; c<indexAllItems; c++) {
        if (allItems[c] -> compareTo(book)) {
            for (int d=0; d<indexAllMembers; d++) {
                if (allMembers[d].getUsername() == allItems[c]->getSeller()) {
                    username = allMembers[d].getUsername();
                    email = allMembers[d].getEmail();
                }
            }
        }
    }
	
    cout << username << "'s email address is " << email << ". Please contact the seller to arrange your exchange." << endl;

    cin.ignore(1);
}

void UserInterface::bid (Item* book)
{

    double bid;
    cin >> bid;
    
    if (bid <= book->getSellPrice())
    {
        while (bid <= book->getSellPrice())
        {
            cout << "Your bid must be greater than the current highest bid, which is $" << book->getSellPrice() <<  ". Please enter a higher bid." << endl;
            cin >> bid;
        }
    }
    else
        book->setSellPrice(bid);
    
    cin.ignore(1);
}
