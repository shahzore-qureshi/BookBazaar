// Name:
// Course: CSC 260-2 
// Semester: Fall 2011
// Instructor: Dr. Pulimood
// Assignment N
// Description: put a brief description of the program here
// Filename: assgnNInit.cpp
// Last modified on: date

#include "DateTime.h"

DateTime::DateTime()                //Data and Time Constructor with Current Time
{
    string smonth, sday, syear, shour, sminute, ssecond, dayWeek;
    time_t current = time(0);
    string time = ctime(&current);      //This is the string representing the current date and time from the computer

    stringstream timeInput(time);           //puts into a stream
    getline(timeInput, dayWeek, ' ');
    getline(timeInput, smonth, ' ');
    timeInput.ignore(1);                    //Parses the string to get string representations for the information
    getline(timeInput, sday, ' ');
    getline(timeInput, shour, ':');
    getline(timeInput, sminute, ':');
    getline(timeInput, ssecond, ' ');
    getline(timeInput, syear);
    
    months = monthName(smonth);
    days = atoi(sday.c_str());
    years = atoi(syear.c_str());
                                        //Sets information
    hours = atoi(shour.c_str());
    minutes = atoi(sminute.c_str());
    seconds = atoi(ssecond.c_str());
    milliseconds = 0;
    
    changeType(false, false, true);
}

DateTime::DateTime(int month, int day, int year)        //Date Constructor
{
    months = month;
    days = day;
    years = year;
    changeType(false, true, false);
}

DateTime::DateTime(int hour, int minute, int second, int millisecond)       //Time Constructor
{
    hours = hour;
    minutes = minute;
    seconds = second;
    milliseconds = millisecond;
    isDone = false;
    changeType(true, false, false);
}

DateTime::DateTime(int month, int day, int year, int hour, int minute, int second, int millisecond)     //Date and Time Constructor
{
    months = month;
    days = day;
    years = year;
    hours = hour;
    minutes = minute;
    seconds = second;
    milliseconds = millisecond;
    
    changeType(false, false, true);
}

int DateTime::getYear()
{
    return years;
}

int DateTime::getMonth()
{
    return months;
}

int DateTime::getDay()
{
    return days;
}

int DateTime::getHour()
{
    return hours;
}

int DateTime::getMinute()
{
    return minutes;
}

int DateTime::getSecond()
{
    return seconds;
}

int DateTime::getMilliseconds()
{
    return milliseconds;
}

bool DateTime::getIsTime()
{
    return isTime;
}

bool DateTime::getIsDate()
{
    return isDate;
}

bool DateTime::getIsDateTime()
{
    return isDateTime;
}

void DateTime::setYear(int newYear)
{
    years = newYear;
}

void DateTime::setMonth(int newMonth)
{
    months = newMonth;
}

void DateTime::setDay(int newDay)
{
    days = newDay;
}

void DateTime::setHour(int newHour)
{
    hours = newHour;
    checkDone();
}

void DateTime::setMinute(int newMinute)
{
    minutes = newMinute;
    checkDone();
}

void DateTime::setSecond(int newSecond)
{
    seconds = newSecond;
    checkDone();
}

void DateTime::setMilliseconds(int newMilliseconds)
{
    milliseconds = newMilliseconds;
}

bool DateTime::getIsDone()
{
    return isDone;
}

string DateTime::getTime()
{
    stringstream output;
    output << hours << ":" << minutes << ":" << seconds << ":" << milliseconds;
    return output.str();
}

string DateTime::getDate()
{
    stringstream output;
        
    output << monthName(months) << " " << days << ", " << years;
    return output.str();
}

void DateTime::setIsTime(bool theTime)
{
    if(theTime)
    {
        changeType(theTime, !theTime, !theTime);
    }
}

void DateTime::setIsDate(bool theDate)
{
    if(theDate)
    {
        changeType(!theDate, theDate, !theDate);
    }
}

void DateTime::setIsDateTime(bool theDateTime)
{
    if(theDateTime)
    {
        changeType(!theDateTime, !theDateTime, theDateTime);
    }
}

void DateTime::currentTime()
{
    time_t current = time(0);
    cout << ctime(&current) << endl;
}

string DateTime::monthName(int num)
{
    string output = "";
    switch(num)
    {
        case 1:
        {
            output = "January";
            break;
        }
        case 2:
        {
            output = "February";
            break;
        }
        case 3:
        {
            output = "March";
            break;
        }
        case 4:
        {
            output = "April";
            break;
        }
        case 5:
        {
            output = "May";
            break;
        }
        case 6:
        {
            output = "June";
            break;
        }
        case 7:
        {
            output = "July";
            break;
        }
        case 8:
        {
            output = "August";
            break;
        }
        case 9:
        {
            output = "September";
            break;
        }
        case 10:
        {
            output = "October";
            break;
        }
        case 11:
        {
            output = "November";
            break;
        }
        case 12:
        {
            output = "December";
            break;
        }
        default:
        {
            output = "INVALID";
            break;
        }
    }
    return output;
}

int DateTime::monthName(string monthAbriv)
{
    if(monthAbriv == "Jan")
        return 1;
    else if(monthAbriv == "Feb")
        return 2;
    else if(monthAbriv == "Mar")
        return 3;
    else if(monthAbriv == "Apr")
        return 4;
    else if(monthAbriv == "May")
        return 5;
    else if(monthAbriv == "Jun")
        return 6;
    else if(monthAbriv == "Jul")
        return 7;
    else if(monthAbriv == "Aug")
        return 8;
    else if(monthAbriv == "Sep")
        return 9;
    else if(monthAbriv == "Oct")
        return 10;
    else if(monthAbriv == "Nov")
        return 11;
    else if(monthAbriv == "Dec")
        return 12;
    else 
        return 0;
}

void DateTime::subtractOneSecond()
{
    if(seconds != 0)
    {
        seconds--;
    }
    else
    {
        if(minutes != 0)
        {
            minutes--;
            seconds = 59;
        }
        else
        {
            if(hours != 0)
            {
                hours--;
                minutes = 59;
                seconds = 59;
            }
        }
    }
    checkDone();
}

bool DateTime::checkDone()
{
    if(seconds == 0 && minutes == 0 && hours == 0)
    {
        isDone = true;
        return true;
    }
    else
    {
        isDone = false;
        return false;
    }
}

void DateTime::changeType(bool isTimeObject, bool isDateObject, bool isDateTimeObject)  //Changes type of DateTime Object
{
    isTime = isTimeObject;
    isDate = isDateObject;
    isDateTime = isDateTimeObject;
}

string DateTime::getDateTime()      //Returns specific information based on type of DateTime Object
{
    if(isDate)
        return getDate();
    else if(isTime)
        return getTime();
    else if(isDateTime)
        return (getDate() + " " + getTime());
    return "Error";
}

string DateTime::toFile()
{
    stringstream output;
    
    if(isDateTime)
        output << "\"" << months << "\",\"" << days << "\",\"" << years << "\",\"" << hours << "\",\"" << minutes << "\",\"" << seconds << "\",\"" << milliseconds << "\"";
    else if(isDate)
        output << "\"" << months << "\",\"" << days << "\",\"" << years << "\"";
    else if(isTime)
        output << "\"" << hours << "\",\"" << minutes << "\",\"" << seconds << "\",\"" << milliseconds << "\"";
    
    return output.str();
}

bool DateTime::compareTo (DateTime d)
{
	if ((years == d.years) && (days == d.days) && (hours == d.hours) && (minutes == d.minutes) && (seconds == d.seconds) && (milliseconds == d.milliseconds))
		return true;
	else
		return false;
}

DateTime& DateTime::operator = (const DateTime& rightSide)
{
    years = rightSide.years;
    months = rightSide.months;
    days = rightSide.days;
    hours = rightSide.hours;
    minutes = rightSide.minutes;
    seconds = rightSide.seconds;
    milliseconds = rightSide.milliseconds;
    
    isDone = rightSide.isDone;
    isTime = rightSide.isTime;
    isDate = rightSide.isDate;
    isDateTime = rightSide.isDateTime;
    
    return *this;
}

DateTime::~DateTime()
{
    
}

DateTime::DateTime(const DateTime& rightSide)
{
    years = rightSide.years;
    months = rightSide.months;
    days = rightSide.days;
    hours = rightSide.hours;
    minutes = rightSide.minutes;
    seconds = rightSide.seconds;
    milliseconds = rightSide.milliseconds;
    
    isDone = rightSide.isDone;
    isTime = rightSide.isTime;
    isDate = rightSide.isDate;
    isDateTime = rightSide.isDateTime;
}

