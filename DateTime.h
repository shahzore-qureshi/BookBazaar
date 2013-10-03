// Name: eText Synergy Corporation
// Course: CSC 260, Section 2
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Collaborative Team Project
// Description: Class DateTime is a representation of a date and time. They are used to see if a book has been posted for an alloted amount of time.
// Filename: DateTime.h
// Last modified on: 12/4/11

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <time.h>
using namespace std;

#ifndef _DateTime_h
#define _DateTime_h

class DateTime
{
    
public:

	//-----------------------------------------------------------------------------------------
	//
	//  Function: operator=() is an overloaded = operator
	//
	//	Parameters:
	//	input DateTime: the object the calling object will be come a copy of.
	//    
	//	Pre-condition: Both DateTime objects are initialized.
	//  Post-condition: The calling object will become a copy of the parameter.
	//
	//-----------------------------------------------------------------------------------------
    DateTime& operator = (const DateTime&);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: ~DateTime() is an overloaded destructor.
	//
	//	Parameters:
	//    
	//	Pre-condition: The DateTime object is initialized.
	//  Post-condition: The object is deleted.
	//
	//-----------------------------------------------------------------------------------------
    ~DateTime();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: DateTime() is an overloaded copy constructor
	//
	//	Parameters:
	//	input DateTime: the object the calling object will be come a copy of.
	//    
	//	Pre-condition: Both DateTime objects are initialized.
	//  Post-condition: The calling object will become a copy of the parameter.
	//
	//-----------------------------------------------------------------------------------------
    DateTime(const DateTime&);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: DateTime() is a constructor
	//
	//	Parameters:
	//    
	//	Pre-condition: 
	//  Post-condition: The object is created.
	//
	//-----------------------------------------------------------------------------------------
    DateTime();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: DateTime() is a date constructor
	//
	//	Parameters:
	//	input month is the month for the time.
	//	input day is the day for the time
	//	input year is the year for the time
	//    
	//	Pre-condition: 
	//  Post-condition: The object is created.
	//
	//-----------------------------------------------------------------------------------------
    DateTime(int month, int day, int year);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: DateTime() is a time constructor
	//
	//	Parameters:
	//	input hour is the hour for the time
	//	input minute is the minute for the time
	//	input second is the second for the time
	//	input millisecond is the millisecond for the time
	//    
	//	Pre-condition: 
	//  Post-condition: The object is created.
	//
	//-----------------------------------------------------------------------------------------
    DateTime(int hour, int minute, int second, int millisecond);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: DateTime() is a constructor
	//
	//	Parameters:
	//	input month is the month for the time.
	//	input day is the day for the time
	//	input year is the year for the time
	//	input hour is the hour for the time
	//	input minute is the minute for the time
	//	input second is the second for the time
	//	input millisecond is the millisecond for the time    
	//
	//	Pre-condition: 
	//  Post-condition: The object is created.
	//
	//-----------------------------------------------------------------------------------------
    DateTime(int month, int day, int year, int hour, int minute, int second, int millisecond);
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: getYear() obtains the year for this object
	//
	//	Parameters:
	//	output year is the year of the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The year is returned.
	//
	//-----------------------------------------------------------------------------------------
    int getYear();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: getMonth() obtains the month for this object
	//
	//	Parameters:
	//	output month is the month of the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The month is returned.
	//
	//-----------------------------------------------------------------------------------------
    int getMonth();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getDay() obtains the day for this object
	//
	//	Parameters:
	//	output day is the day of the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The day is returned.
	//
	//-----------------------------------------------------------------------------------------
    int getDay();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getHour() obtains the hour for this object
	//
	//	Parameters:
	//	output hour is the hour of the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The hour is returned.
	//
	//-----------------------------------------------------------------------------------------
    int getHour();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: getMinute() obtains the minute for this object
	//
	//	Parameters:
	//	output minute is the minute of the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The minute is returned.
	//
	//-----------------------------------------------------------------------------------------
    int getMinute();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: getSecond() obtains the second for this object
	//
	//	Parameters:
	//	output second is the second of the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The second is returned.
	//
	//-----------------------------------------------------------------------------------------
    int getSecond();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: getMillisecond() obtains the millisecond for this object
	//
	//	Parameters:
	//	output millisecond is the millisecond of the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The millisecond is returned.
	//
	//-----------------------------------------------------------------------------------------
    int getMilliseconds();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: getIsDone() obtains a bool representing whether the transaction is done
	//
	//	Parameters:
	//	output isDone is the result of the operation
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: A result is returned.
	//
	//-----------------------------------------------------------------------------------------
    bool getIsDone();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: isTime() a bool representing whether the object has a time
	//
	//	Parameters:
	//	output isTime represents whether the object has time values associated with it.
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The result is returned.
	//
	//-----------------------------------------------------------------------------------------
    bool getIsTime();

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getIsTime() a bool representing whether the object has a date
	//
	//	Parameters:
	//	output isTime represents whether the object has date values associated with it.
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The result is returned.
	//
	//-----------------------------------------------------------------------------------------
    bool getIsDate();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: isDateTime() a bool representing whether the object has a time and date
	//
	//	Parameters:
	//	output isTime represents whether the object has date and time values associated with it.
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The result is returned.
	//
	//-----------------------------------------------------------------------------------------
    bool getIsDateTime();
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: setYear() changes the year for the object
	//
	//	Parameters:
	//	input int is the new year for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The value is updated.
	//
	//-----------------------------------------------------------------------------------------
    void setYear(int);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: setMonth() changes the month for the object
	//
	//	Parameters:
	//	input int is the new month for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The value is updated.
	//
	//-----------------------------------------------------------------------------------------
    void setMonth(int);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: setDay() changes the day for the object
	//
	//	Parameters:
	//	input int is the new day for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The value is updated.
	//
	//-----------------------------------------------------------------------------------------
    void setDay(int);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: setHour() changes the hour for the object
	//
	//	Parameters:
	//	input int is the new hour for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The value is updated.
	//
	//-----------------------------------------------------------------------------------------
    void setHour(int);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setMinute() changes the minute for the object
	//
	//	Parameters:
	//	input int is the new minute for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The value is updated.
	//
	//-----------------------------------------------------------------------------------------
    void setMinute(int);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: setSecond() changes the second for the object
	//
	//	Parameters:
	//	input int is the new second for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The value is updated.
	//
	//-----------------------------------------------------------------------------------------
    void setSecond(int);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setMilliseconds() changes the milliseconds for the object
	//
	//	Parameters:
	//	input int is the new milliseconds for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The value is updated.
	//
	//-----------------------------------------------------------------------------------------
    void setMilliseconds(int);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: setIsTime() changes the isTime value for the object
	//
	//	Parameters:
	//	input bool is the new isTime for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The value is updated.
	//
	//-----------------------------------------------------------------------------------------
    void setIsTime(bool);

	//-----------------------------------------------------------------------------------------
	//
	//  Function: setIsDate() changes the isDate value for the object
	//
	//	Parameters:
	//	input bool is the new isDate for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The value is updated.
	//
	//-----------------------------------------------------------------------------------------
    void setIsDate(bool);
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: setIsDateTime() changes the isDateTime value for the object
	//
	//	Parameters:
	//	input bool is the new isDateTime for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The value is updated.
	//
	//-----------------------------------------------------------------------------------------
    void setIsDateTime(bool);
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: subtractOneSecond() subtracts one second from the time object
	//
	//	Parameters:
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The time is decremented by one second.
	//
	//-----------------------------------------------------------------------------------------
    void subtractOneSecond();
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: compareTo() compares 2 objects for equality
	//
	//	Parameters:
	//	output bool represents whether the objects are equal.
	//	input DateTime represents the time to compare to.
	//    
	//	Pre-condition: The 2 objects was initalized.
	//  Post-condition: True is returned if they are the same, false otherwise.
	//
	//-----------------------------------------------------------------------------------------
    bool compareTo (DateTime d);
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: getDateTime() gets all of the time info for the object
	//
	//	Parameters:
	//	output string returns all of the information available for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: A string with all information is returned.
	//
	//-----------------------------------------------------------------------------------------
    string getDateTime();       //Depending on type of DateTime, it returns the necessary information
	
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
    string toFile();            //CSV format for file output
    
private:
    int years;
    int months;
    int days;
    int hours;
    int minutes;
    int seconds;
    int milliseconds;
    
    bool isDone;
    bool isTime;
    bool isDate;
    bool isDateTime;
    
	//-----------------------------------------------------------------------------------------
	//
	//  Function: isDone() returns whether the time is completed.
	//
	//	Parameters:
	//	output isDone is whether the time object is complete
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: A bool is returned if the time object is done.
	//
	//-----------------------------------------------------------------------------------------
    bool checkDone();      
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: changeType() changes the type of this object
	//
	//	Parameters:
	//	input isTimeObject represents whether this is a time object
	//	input isDateObject represents whether this is a date object
	//	input isDateTimeObject represents whether this is a date and time object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The desired changes are made to the object's type.
	//
	//-----------------------------------------------------------------------------------------
    void changeType(bool isTimeObject, bool isDateObject, bool isDateTimeObject);
   
  	//-----------------------------------------------------------------------------------------
	//
	//  Function: currentTime() outputs the time the object represents.
	//
	//	Parameters:
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: This object's data is printed.
	//
	//-----------------------------------------------------------------------------------------
    void currentTime();
	
  	//-----------------------------------------------------------------------------------------
	//
	//  Function: monthName() returns the int representation of what month the time has
	//
	//	Parameters:
	//	output string is the string representation of the month
	//	input int is the integer representation of the month
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The string representation of what month the time has is returned.
	//
	//----------------------------------------------------------------------------------------- 
	string monthName(int);
	
  	//-----------------------------------------------------------------------------------------
	//
	//  Function: monthName() returns the int representation of what month the time has
	//
	//	Parameters:
	//	input string is the string representation of the month
	//	output int is the integer representation of the month
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: The int representation of what month the time has is returned.
	//
	//----------------------------------------------------------------------------------------- 
    int monthName(string);      //integer return for the month based on computer abbriviation

	//-----------------------------------------------------------------------------------------
	//
	//  Function: getDate() gets all of the date info for the object
	//
	//	Parameters:
	//	output string returns the date information available for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: A string with the information is returned.
	//
	//-----------------------------------------------------------------------------------------
    string getDate();
	
	//-----------------------------------------------------------------------------------------
	//
	//  Function: getTime() gets all of the time info for the object
	//
	//	Parameters:
	//	output string returns the time information available for the object
	//    
	//	Pre-condition: The object was initalized.
	//  Post-condition: A string with the information is returned.
	//
	//-----------------------------------------------------------------------------------------
    string getTime();
};

#endif
