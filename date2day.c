/* 
 * day2day.c by Aragon12
 *
 * Simple terminal based C program, which will give you the exact day of any date entered between year 1700 - 2199
 *
 * USAGE: (linux)
 *     gcc date2day.c -o date2day
 *     ./date2day
 */
#include <stdio.h>
#include <stdlib.h>

int year(int year);
int vali_date(int, int, int);
int date_parse(char *, int *, int *, int *);

char day[][10] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
};

int mon[12] = {
	0, 3, 3,
	6, 1, 4,
	6, 2, 5,
	0, 3, 5,
};

int main()
{
	int d, m, y;
	char date[11];

	printf("date2day by Aragon12\n");
	printf("\nSimple terminal based C program\n");
	printf("which will give you the exact day of any date entered between year 1700-2199\n");

	printf("\nin DD/MM/YYYY format\n");
	printf("Enter Date:  ");
	scanf("%s", date);

	if (!date_parse(date, &d, &m, &y))
	{
		printf("\nERROR: Invalid date format\nenter ur date in DD/MM/YYYY format\n");
		return 0;
	}
	if (!vali_date(d, m, y))
	{
		printf
			("\nERROR: either date is wrong... or not possible acc to calender\n");
		return 0;
	}
	if (year(y) == -1)
	{
		printf("ERROR: year must be b/w 1700 - 2199\n");
		return 0;
	}
	int day_code = d + (y % 100) + ((y % 100) / 4) + mon[(m - 1)] + year(y);
	printf("\nOn %d/%d%/%d, there was %s\n", d, m, y, day[(day_code % 7)]);
	return 1;
}

int year(int year)
{
	if ((year >= 1700) && (year < 1800))
		return 4;
	else if ((year >= 1800) && (year < 1900))
		return 2;
	else if ((year >= 1900) && (year < 2000))
		return 0;
	else if ((year >= 2000) && (year < 2100))
		return 6;
	else if ((year >= 2100) && (year < 2200))
		return 4;
	else
		return -1;
}

int date_parse(char *date, int *day, int *mon, int *year)
{
	int sl[2], i = 1, q = 0;
	char *ptr = date;

	while (*ptr != '\0')
	{
		if (*ptr == '/')
		{
			sl[q] = i;
			q++;
		}
		ptr++;
		i++;
	}
	if (!(sl[0] == 2 || sl[0] == 3))
		return 0;
	if (!(sl[1] == 4 || sl[1] == 5 || sl[1] == 6))
		return 0;

	*day = atoi(&date[0]);
	*mon = atoi(&date[sl[0]]);
	*year = atoi(&date[sl[1]]);

	return 1;
}

int vali_date(int d, int m, int y)
{
	if (!m || m > 12)
		return 0;
	if (d > 0 && d < 29)
		return 1;
	else if (d == 29 || d == 30)
	{
		if (m == 2)
		{
			if (d == 29 && !(y % 4))
				return 1;
			return 0;
		}
		return 1;
	}
	else if (d == 31)
	{
		if (m == 2 || m == 4 || m == 6 || m == 9 || m == 11)
			return 0;
		return 1;
	}
	return 0;
}
// by Aragon12