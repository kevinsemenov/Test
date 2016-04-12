/*******************************************************
 * AUTHOR		 :  Chris Montazer
 * STUDENT ID	 :  872757
 * ASSIGNMENT #3 :  Employee Inheritance
 * CLASS		 :  CS 1C
 * SECTION		 :  MW: 2:00 PM - 4:50 PM
 * DUE DATE		 :  02/10/16
 *******************************************************/

#include "Date.h"
#include <sstream>
#include <ctime>

/***************************************************************
 * Method GetDate: Class Date
 * -------------------------------------------------------------
 * This method returns the date attributes by reference
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		month	:	month attribute of date
 * 		day		:	day attribute of date
 * 		year	:	year attribute of date
 *
 * POST-CONDITIONS
 *		returns all date attribute by reference
 ***************************************************************/
void Date::GetDate(unsigned short &month,
		 	 	   unsigned short &day,
		 	 	   unsigned short &year) const
{
	month = dateMonth;
	day   = dateDay;
	year  = dateYear;
}

/***************************************************************
 * Method GetYear: Class Date
 * -------------------------------------------------------------
 * This method returns the year attribute of the date
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 *		returns year attribute of the date
 ***************************************************************/
unsigned short Date::GetYear() const
{
	return dateYear;
}

/***************************************************************
 * Method GetMonth: Class Date
 * -------------------------------------------------------------
 * This method returns the month attribute of the date
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 *		returns month attribute of the date
 ***************************************************************/
unsigned short Date::GetMonth() const
{
	return dateMonth;
}

/***************************************************************
 * Method GetDay: Class Date
 * -------------------------------------------------------------
 * This method returns the day attribute of the date
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 *		returns day attribute of the date
 ***************************************************************/
unsigned short Date::GetDay() const
{
	return dateDay;
}

/***************************************************************
 * Method IsLeapYear: Class Date
 * -------------------------------------------------------------
 * This method returns true/false if the year argument is
 * a leap year
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 *		returns true/false if is leap year
 ***************************************************************/
bool Date::IsLeapYear()
{
	return IsLeapYear(GetYear());
}

/***************************************************************
 * Method DisplayDate: Class Date
 * -------------------------------------------------------------
 * This method returns the full date in a string format
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 *		returns the full date in a string format
 ***************************************************************/
std::string Date::DisplayDate() const
{
	std::ostringstream outString;

	if(GetMonth() <= 9)
	{
		outString << "0" << GetMonth() << "/";
	}
	else
	{
		outString << GetMonth() << "/";
	}

	if(GetDay() <= 9)
	{
		outString << "0" << GetDay() << "/";
	}
	else
	{
		outString << GetDay() << "/";
	}

	outString << GetYear();

	return outString.str();
}

/***************************************************************
 * Method GetDaysInMonth: Class Date
 * -------------------------------------------------------------
 * This method returns the number of days in a given month
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		month	:	the month in question
 * 		year	:	the year of the date
 *
 * POST-CONDITIONS
 *		returns the number of days in a given month
 ***************************************************************/
unsigned short Date::GetDaysInMonth(unsigned short month,
									unsigned short year) const
{
	unsigned short numDays;

	if(month == 2)
	{
		if(IsLeapYear(year))
		{
			numDays = 29;
		}
		else
		{
			numDays = 28;
		}
	}
	else if(month == 4 || month == 6 || month == 9 ||month == 11)
	{
		numDays = 30;
	}
	else
	{
		numDays = 31;
	}

	return numDays;
}

/***************************************************************
 * Method IsLeapYear: Class Date
 * -------------------------------------------------------------
 * This method returns if the given year is a leap year
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		year	:	the year in question
 *
 * POST-CONDITIONS
 *		returns true/false if the year is a leap year
 ***************************************************************/
bool Date::IsLeapYear(unsigned short year) const
{
	return ((year % 4 == 0)  &&
			(year % 100 != 0 || (year % 100 == 0 && year % 400 == 0)));
}

/***************************************************************
 * Method ValidateMonth: Class Date
 * -------------------------------------------------------------
 * This method returns true/false if the month is valid
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		month	:	the month in question
 *
 * POST-CONDITIONS
 *		returns true/false if the month is valid
 ***************************************************************/
bool Date::ValidateMonth(unsigned short month) const
{
	return month >= 1 && month <= 12;
}

/***************************************************************
 * Method ValidateDay: Class Date
 * -------------------------------------------------------------
 * This method returns true/false if the day is valid
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		month	:	month attribute of the date
 * 		day		:	the day in question
 * 		year	:	year attribute of the date
 *
 * POST-CONDITIONS
 *		returns true/false if the day is valid
 ***************************************************************/
bool Date::ValidateDay(unsigned short month,
					   unsigned short day,
					   unsigned short year) const
{
	return day <= GetDaysInMonth(month, year);
}

/***************************************************************
 * Method ValidateYear: Class Date
 * -------------------------------------------------------------
 * This method returns true/false if the year is valid
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		year	:	the year in question
 *
 * POST-CONDITIONS
 *		returns true/false if the year is valid
 ***************************************************************/
bool Date::ValidateYear(unsigned short year) const
{
	return year >= MIN_YEAR && year <= CURRENT_YEAR;
}

/***************************************************************
 * Method ValidateMonth: Class Date
 * -------------------------------------------------------------
 * This method returns true/false if the month is valid
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		month	:	the month in question
 * 		day		:	the day in question
 * 		year	:	the year in question
 *
 * POST-CONDITIONS
 *		returns true/false if the month is valid
 ***************************************************************/
bool Date::ValidateDate(unsigned short month,
						unsigned short day,
						unsigned short year) const
{
	time_t now;
	tm *currentTime;
	unsigned short currentYear;
	unsigned short currentMonth;
	unsigned short currentDay;
	bool valid;

	valid = false;

	now = time(NULL);
	currentTime = localtime(&now);

	currentYear = 1900 + currentTime -> tm_year;
	currentMonth = currentTime -> tm_mon;
	currentDay = currentTime -> tm_mday;

	if(ValidateMonth(month) && ValidateYear(year))
	{
		if(currentMonth != month)
		{
			valid = true;
		}

	}


	return valid;

}


