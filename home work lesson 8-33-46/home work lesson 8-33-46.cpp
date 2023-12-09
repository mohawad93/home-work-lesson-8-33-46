#include <iostream>
using namespace std;
bool isLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDayesInMounth(short year, short mounth)
{
	if (mounth < 1 || mounth>12)
		return 0;
	short numberOfDays[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (mounth == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[mounth];

}
struct stDate
{
	short Year;
	short Month;
	short Day;
};
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}
bool IsLastDayInMounth(stDate Date1)
{
	return (Date1.Day == numberOfDayesInMounth(Date1.Year, Date1.Month));
}
bool IsFirstDayInMounth(stDate Date1)
{
	return (Date1.Day == 1);
}
bool IsLastMounthInYear(short mounth)
{
	return(mounth == 12);
}
bool IsFirstMounthInYear(short mounth)
{
	return(mounth == 1);
}
short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}
stDate EncresedDateBy1Day(stDate Date)
{

	//(IsLastDayInMounth(Date) ? Date.Day = 1 ,((IsLastMounthInYear(Date.Month))?Date.Month=1,Date.Year++:Date.Month++) : Date.Day++);
	if (IsLastDayInMounth(Date))
	{

		if (IsLastMounthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;


}
stDate DecresedDateBy1Day(stDate Date)
{

	//(IsLastDayInMounth(Date) ? Date.Day = 1 ,((IsLastMounthInYear(Date.Month))?Date.Month=1,Date.Year++:Date.Month++) : Date.Day++);


	if (IsFirstDayInMounth(Date))
	{

		if (IsFirstMounthInYear(Date.Month))
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day=numberOfDayesInMounth(Date.Year,Date.Month);
			
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;


}
void swapDates(stDate& date1, stDate& date2)
{
	stDate tempDate;
	tempDate.Day = date1.Day;
	tempDate.Month = date1.Month;
	tempDate.Year = date1.Year;
	date1.Day = date2.Day;
	date1.Month = date2.Month;
	date1.Year = date2.Year;
	date2.Day = tempDate.Day;
	date2.Month = tempDate.Month;
	date2.Year = tempDate.Year;
}
int DiffrenceBetween2Date(stDate Date1, stDate Date2, bool includeEndDay = false)
{
	int Days = 0;
	short swapFlagValue = 1;
	if (!IsDate1BeforeDate2(Date1, Date2))
	{
		swapDates(Date1, Date2);
		swapFlagValue = -1;
	}
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = EncresedDateBy1Day(Date1);

	}
	return includeEndDay ? ++Days * swapFlagValue : Days * swapFlagValue;
}
stDate DecreaseDateByXDays(stDate date, short numberOfDayes)
{
	for (int i = 1; i <= numberOfDayes; i++)
		date = DecresedDateBy1Day(date);
	return date;
}
stDate DecreaseDateByOneWeek(stDate date)
{
	for (int i = 1; i <= 7; i++)
		date = DecresedDateBy1Day(date);
	return date;
}
stDate DecreaseDateByXWeeks(stDate date, short numberOfWeeks)
{
	for (int i = 1; i <= numberOfWeeks; i++)
		date = DecreaseDateByOneWeek(date);
	return date;
}
stDate DecreaseDateByOneMonth(stDate date)
{


	if (date.Month == 1)
	{
		date.Month = 12;
		date.Year--;
	}
	else
	{
		date.Month--;
	}
	short numberOfDay = numberOfDayesInMounth(date.Year, date.Month);
	if (date.Day > numberOfDay)
	{
		date.Day = numberOfDay;

	}
	return date;
}
stDate DecreaseDateByXMonth(stDate date, short numberOfMounth)
{
	for (short i = 1; i <= numberOfMounth; i++)
	{
		date = DecreaseDateByOneMonth(date);

	}
	return date;


}
stDate DecreaseDateByOneYear(stDate date)
{

	date.Year--;
	return date;
}
stDate DecreaseDateByXYear(stDate date, short numberOfYear)
{

	for (int i = 1; i <= numberOfYear; i++)
		date = DecreaseDateByOneYear(date);
	return date;
}
stDate DecreaseDateByXYearFaster(stDate date, short numberOfYear)
{
	date.Year -= numberOfYear;
	return date;
}
stDate DecreaseDateByOneDecade(stDate date)
{

	date.Year -= 10;
	return date;
}
stDate DecreaseDateByXDecade(stDate date, short numberOfDecade)
{

	for (int i = 1; i <= numberOfDecade * 10; i++)
	{
		date = DecreaseDateByOneYear(date);
	}
	return date;
}
stDate DecreaseDateByXDecadeFaster(stDate date, short numberOfDecade)
{

	date.Year -= (10 * numberOfDecade);
	return date;
}
stDate DecreaseDateByOneCentury(stDate date)
{

	date.Year -= 100;
	return date;
}
stDate DecreaseDateByOneMillennium(stDate date)
{

	date.Year -= 1000;
	return date;
}
int main()
{
	stDate Date1 = ReadFullDate();
	Date1 = DecresedDateBy1Day(Date1);
	cout << "01- Subtracting one day is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByXDays(Date1, 10);
	cout << "02- Subtracting 10 days is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "03- Subtracting one week is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByXWeeks(Date1, 10);
	cout << "04- Subtracting 10 weeks is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "05- Subtracting one month is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByXMonth(Date1, 5);
	cout << "06- Subtracting 5 month is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByOneYear(Date1);
	cout << "07- Subtracting one year is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByXYear(Date1, 10);
	cout << "08- Subtracting 10 year is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByXYearFaster(Date1, 10);
	cout << "09- Subtracting 10 year (Faster) is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "10- Subtracting one Decade is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByXDecade(Date1, 10);
	cout << "11- Subtracting 10 Decade is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByXDecadeFaster(Date1, 10);
	cout << "12- Subtracting 10 Decade (Faster) is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "13- Subtracting one Century is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	Date1 = DecreaseDateByOneMillennium(Date1);
	cout << "14- Subtracting one Millennium is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	system("pause>0");
	return 0;
}