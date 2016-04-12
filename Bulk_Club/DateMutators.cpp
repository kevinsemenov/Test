/*******************************************************
 * AUTHOR		 :  Chris Montazer
 * STUDENT ID	 :  872757
 * ASSIGNMENT #3 :  Employee Inheritance
 * CLASS		 :  CS 1C
 * SECTION		 :  MW: 2:00 PM - 4:50 PM
 * DUE DATE		 :  02/10/16
 *******************************************************/

#include "Date.h"
#include <ctime>

/***************************************************************
 * Date()
 * 	Constructor: Initialize class attributes
 * 	Parameters: none
 * 	Return: none
 ***************************************************************/
Date::Date()
{

	dateMonth = 1;
	dateDay   = 1;
	dateYear  = 1900;

}

/***************************************************************
 * Date(unsigned short month, unsigned short day,
 *      unsigned short year)
 * Non-Default Constructor: Sets class attributes
 * Parameters: unsigned short month, unsigned short day,
 *      	   unsigned short year
 * Return: none
 ***************************************************************/
Date::Date(unsigned short month,
		   unsigned short day,
		   unsigned short year)
{
	SetDate(month, day, year);
}

/***************************************************************
 * ~Date()
 * 	Destructor: does nothing
 * 	Parameters: none
 * 	Return: none
 ***************************************************************/
Date::~Date()
{

}

/***************************************************************
 * Method SetDate: Class Date
 * -------------------------------------------------------------
 * This method sets all attributes of Date
 * -------------------------------------------------------------
 * PRE-CONDITIONS
 * 		month	:	month attribute of date
 * 		day		:	day attribute of date
 * 		year	:	year attribute of date
 *
 * POST-CONDITIONS
 * 		Sets all attributes of Date
 ***************************************************************/
void Date::SetDate(unsigned short month,
		           unsigned short day,
		           unsigned short year)
{
	time_t now;
	tm *currentTime;
	unsigned short currentYear;
	unsigned short currentMonth;
	unsigned short currentDay;

	if(!ValidateDate(month, day, year))
	{
		now = time(NULL);
		currentTime = localtime(&now);

		currentYear = 1900 + currentTime -> tm_year;
		currentMonth = currentTime -> tm_mon + 1;
		currentDay = currentTime -> tm_mday;

		dateMonth = currentMonth;
		dateDay   = currentDay;
		dateYear  = currentYear;
	}
	else
	{
		dateMonth  = month;
		dateDay    = day;
		dateYear   = year;
	}

}
