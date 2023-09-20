
class Date
{
public:
	Date(int m = 1, int d = 1, int y = 2000);

	void setMonth(int m);

	int getMonth(void);

	void setDay(int d);

	int getDay(void);

	void setYear(int y);

	int getYear(void);

	void displayDate(void);

private:
	int month;
	int day;
	int year;
};
