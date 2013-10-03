// Name:
// Course: CSC 260-2 
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Assignment N
// Description: put a brief description of the program here
// Filename: assgnNInit.cpp
// Last modified on: date
#include "Member.h"
#include "UserInterface.h"

Member::Member()
{

}

Member::Member(string first, string last, string theEmail, string theUsername, string thePassword, DateTime dateTime)
{
    firstName = first;
    lastName = last;
    email = theEmail;
    username = theUsername;
    password = thePassword;
    creationTime = dateTime;
}

void Member::setFirstName(string first)
{
    firstName = first;
}

void Member::setLastName(string last)
{
    lastName = last;
}

void Member::setEmail(string theEmail)
{
    email = theEmail;
}

void Member::setUsername(string theUsername)
{
    username = theUsername;
}

void Member::setPassword(string thePassword)
{
    password = thePassword;
}

void Member::setCreationTime(DateTime dateTime)
{
    creationTime = dateTime;
}

string Member::getFirstName()
{
    return firstName;
}

string Member::getLastName()
{
    return lastName;
}

string Member::getEmail()
{
    return email;
}

string Member::getUsername()
{
    return username;
}

string Member::getPassword()
{
    return password;
}

string Member::getCreationTime()
{
    return creationTime.getDateTime();
}

string Member::toFile()
{
    stringstream output;
    output << "\"" << getLastName() << "\",\"" << getFirstName() << "\",\"" << getEmail() << "\",\"" << getUsername() << "\",\"" << getPassword() << "\"," << creationTime.toFile();
    
    return output.str();
}

istream & operator >>(istream& stream, Member& newMember)
{
    bool validName = false;
    bool validUser = false;
    string fullName = "";
    string firstName = "";
    string lastName = "";
    string email = "";
    string username = "";
    string password = "";
    
    while(!validName)
    {
        cout << "Full Name: ";
        getline(stream, fullName);
        if(fullName.find(' ') != string::npos && fullName.at(0) != ' ')
            validName = true;
    }
    
    firstName = fullName.substr(0, fullName.find(' '));
    firstName[0] = toupper(firstName[0]);
    lastName = fullName.substr(fullName.find(' ') + 1);
    lastName[0] = toupper(lastName[0]);
    
    bool validEmail = false;
    while(!validEmail)
    {
        cout << "Email: ";
        getline(stream, email);
        if(email.find("@tcnj.edu") == string::npos && email.find("@apps.tcnj.edu") == string::npos)
            validEmail = false;
       /* else if(&& email.at(email.size()-1) == 'u' && email.at(email.size()-2) == 'd' && email.at(email.size()-3) == 'e' 
                && email.at(email.size()-4) == '.')
            validEmail = false;*/
        else
            validEmail = true;
    }
    while(!validUser)
    {
        cout << "Username: ";
        getline(stream, username);
        string thing = username + ".dat";
        ifstream inFile(thing.c_str());
        if(!inFile)
            validUser = true;
        inFile.close();
        if(!validUser)
            cout << "Error: Nonunique Username" << endl;
    }
    cout << "Password: ";
    getline(stream, password);
    
    DateTime currentTime = DateTime();
    newMember = Member(firstName, lastName, email, username, password, currentTime);
    return stream;
}

ostream& operator <<(ostream& output, Member currentMember)
{
    output << "Name: " << currentMember.getLastName() << ", " << currentMember.getFirstName() << endl;
    output << "Email: "<< currentMember.getEmail() << endl;
    output << "Username: " << currentMember.getUsername() << endl;
    output << "Password: " << currentMember.getPassword() << endl;
    output << "Member Since: " << currentMember.getCreationTime() << endl;
    
    return output;
}

void Member::viewDetails()
{
    char field;
    string input = "";
    do
    {
	cout << "To modify one of the following fields, enter the corresponding number, " <<
			"or enter r to return to the main menu." << endl;
	cout << "1) Name: " << firstName << " " << lastName << endl;
	cout << "2) Email: " << email << endl;
	cout << "3) Username: " << username << endl;
	cout << "4) Password: " << password << endl;

    cout << "Option: ";
	do
    {
        getline(cin, input);
        field = tolower(input[0]);
    }while(input.length() > 1);
        if(cin.fail())
        {
            cin.clear();
            cout << "Error: invalid entry." << endl;
            return;                    
        }
    field = tolower(field);
    switch (field)
    {
    	case 'r':
    		break;
        case '1':
            modifyName();
            break;
        case '2':
            cout << "Your email cannot be changed." << endl;
            break;
        case '3':
            modifyUsername();
            break;
        case '4':
            modifyPassword();
            break;
    }
    }while(field != 'r');
}

void Member::modifyName()
{
	cout << "Current name: " << firstName << " " << lastName << endl;
	cout << "New name: ";
	string newFirst, newLast;
	cin >> newFirst;
	cin >> newLast;
    cin.ignore(1);
	setFirstName(newFirst);
	setLastName(newLast);
}

void Member::modifyUsername()
{
	cout << "Current username: " << username << endl;
	cout << "New username: ";
	string newUsername;
	cin >> newUsername;
    while ((int)newUsername.length() < MIN || (int)newUsername.length() > MAX)
    {
        cout << "The length of your username must be between 5 and 15 characters." <<
        " Please re-enter your new username." << endl;
        cin >> newUsername;
    }
	setUsername(newUsername);
}

void Member::modifyPassword()
{
	cout << "Old password: " << password << endl;
	cout << "New password: ";
	string newPassword;
	cin >> newPassword;
    while ((int)newPassword.length() < MIN || (int)newPassword.length() > MAX)
    {
        cout << "The length of your password must be between 5 and 15 characters." <<
        " Please re-enter your new password." << endl;
        cin >> newPassword;
    }
	cout << "Confirm new password: ";
	string confirmation;
	cin >> confirmation;
	cout << endl;
    if (newPassword == confirmation)
        setPassword(newPassword);
    else
    {
        cout << "The passwords you entered do not match. Please re-enter them." << endl;
        modifyPassword();
    }
}

bool Member::compareTo(Member rhs) {

	if (username == rhs.username)
		return true;
	else
		return false;

}

Member& Member::operator = (const Member& rightSide)
{
    firstName = rightSide.firstName;
    lastName = rightSide.lastName;
    email = rightSide.email;
    username = rightSide.username;
    password = rightSide.password;
    creationTime = rightSide.creationTime;
    
    return *this;
}

Member::~Member()
{
    
}

Member::Member(const Member& rightSide)
{
    firstName = rightSide.firstName;
    lastName = rightSide.lastName;
    email = rightSide.email;
    username = rightSide.username;
    password = rightSide.password;
    creationTime = rightSide.creationTime;
}