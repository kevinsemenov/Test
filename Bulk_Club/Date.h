/*******************************************************
 * AUTHOR		 :  Chris Montazer
 * STUDENT ID	 :  872757
 * ASSIGNMENT #3 :  Employee Inheritance
 * CLASS		 :  CS 1C
 * SECTION		 :  MW: 2:00 PM - 4:50 PM
 * DUE DATE		 :  02/10/16
 *******************************************************/

#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <iostream>

const unsigned short MIN_YEAR     = 1900;
const unsigned short CURRENT_YEAR = 2016;

class Date
{
	public:

		/*****************************
		 * CONSTRUCTORS & DESTRUCTOR *
		 *****************************/

		Date();
		Date(unsigned short month,
			 unsigned short day,
			 unsigned short year);
		~Date();

		/*****************************
		 *         MUTATORS          *
		 *****************************/
		// uses private utility methods
		void SetDate(unsigned short month,
					 unsigned short day,
					 unsigned short year);

		/*****************************
		 *         ACCESSORS         *
		 *****************************/
		void GetDate(unsigned short &month,
					 unsigned short &day,
					 unsigned short &year) const;

		unsigned short GetYear() const;
		unsigned short GetMonth() const;
		unsigned short GetDay() const;

		bool IsLeapYear();

		// Displays in MM/DD/YYYY format
		std::string DisplayDate() const;

		unsigned short GetDaysInMonth(unsigned short month,
									  unsigned short year) const;


	private:

		/*****************************
		 * 		UTILITIES METHODS    *
		 *****************************/

		bool IsLeapYear(unsigned short year) const;

		/*****************************
		 * 	   VALIDATE  METHODS     *
		 *****************************/

		// Validates the month
		bool ValidateMonth(unsigned short month) const;

		// Checks if a day is valid takes leap year into consideration
		bool ValidateDay(unsigned short month,
						 unsigned short day,
						 unsigned short year) const;

		// Validates the year is between 1900 and the current year
		bool ValidateYear(unsigned short year) const;

		// Uses methods above to validate a given date
		// Checks against current day
		bool ValidateDate(unsigned short month,
						  unsigned short day,
						  unsigned short year) const;

		/*****************************
		 * 		   ATTRIBUTES        *
		 *****************************/

		unsigned short dateMonth;
		unsigned short dateDay;
		unsigned short dateYear;



};


#endif /* DATE_H_ */
