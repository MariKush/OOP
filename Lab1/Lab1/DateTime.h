#pragma once

class DateTime
{
private:
	int year, month, day, hour, minute, second;
	
public:
	DateTime()
	{
		year = 1;
		month = 1;
		day = 1;
		hour = 0;
		minute = 0;
		second = 0;
	};
	DateTime(int y, int mon, int d, int h, int min, int s)
	{
		year = y;
		month = mon;
		day = d;
		hour = h;
		minute = min;
		second = s;
		make_correct();
	};

	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() { return day; }
	int get_hour() { return hour; }
	int get_minute() { return minute; }
	int get_second() { return second; }

	void make_correct();
	bool is_correct();

	void add_difference(DateTime D1);
	void subtraction_difference(DateTime D1);

	void cout_weekday();
	int shift_weekday();

	void cout_DateTime();

};

DateTime difference(DateTime D1, DateTime D2);
