//Calendar.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include<string>
#include <vector>
#include <iomanip>
using namespace std;

int** allocMonth()
{
    int** month;
    month = new int* [5];
    for (int i = 0; i < 6; i++)
    {
        month[i] = new int[7];
    }
    return month;
}
void DeAllocMonth()
{
    int** month;
    delete month[5];
    for (int i = 0; i < 6; i++)
    {
        delete month[i];
    }
}
void monthNames(int counter)
{
    string a[] = { "January","February","March","April","May","June","July","August","September","Octber","November","December" };
    cout << a[counter] << endl << endl;;
}

void displayMonth(int** month)
{

    string a[] = { "Mon","Tue","Wen","Thu","Fry","Sat","Sun" };

    for (auto i : a)
    {
        cout << setw(1) << i << "   ";
    }
    cout << endl << endl;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (month[i][j] != 0)
            {
                if (i == 0 && j == 0 ||
                    i == 1 && j == 0 ||
                    i == 2 && j == 0 ||
                    i == 3 && j == 0 ||
                    i == 4 && j == 0 ||
                    i == 5 && j == 0)
                {

                    cout << setw(2) << month[i][j] << setw(1);
                }
                else
                    cout << setw(6) << month[i][j];
            }
            else if (month[i][j] == 0)
            {
                if (i == 0 && j == 0 ||
                    i == 1 && j == 0 ||
                    i == 2 && j == 0 ||
                    i == 3 && j == 0 ||
                    i == 4 && j == 0 ||
                    i == 5 && j == 0)
                {

                    cout << setw(2) << "  " << setw(1);
                }
                else
                    cout << setw(6) << " ";
            }
        }
        cout << endl << endl;

    }

    cout << "-----------------------------" << endl << endl;

}
//which[in] -> number between 0 and 11, the month
//firstDay[in] -> number between 0 and 6 - the day of the week
//year[in] -> ex. 2001
//nextFirstDay[out] -> first day of the week for the next month
int** createMonth(int which, int firstDay, int year, int* nextFirstDay)
{

    int k = 1;
    int** month = allocMonth();
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (which == 0 || which == 2 || which == 4 || which == 6 || which == 7 || which == 9 || which == 11) {


                if (i == 0 && j < firstDay)
                {
                    month[i][j] = 0;
                }
                else if (k > 31)
                {
                    month[i][j] = 0;
                }
                else
                {
                    month[i][j] = k;
                    k++;
                }
            }
            else if (which == 1)
            {
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                {
                    if (i == 0 && j < firstDay)
                    {
                        month[i][j] = 0;
                    }
                    else if (k > 29)
                    {
                        month[i][j] = 0;
                    }
                    else {
                        month[i][j] = k;
                        k++;
                    }
                }
                else
                {
                    if (i == 0 && j < firstDay)
                    {
                        month[i][j] = 0;
                    }
                    else if (k > 28)
                    {
                        month[i][j] = 0;
                    }
                    else {
                        month[i][j] = k;
                        k++;
                    }
                }
            }
            else
            {
                if (i == 0 && j < firstDay)
                {
                    month[i][j] = 0;
                }
                else if (k > 30)
                {
                    month[i][j] = 0;

                }
                else
                {
                    month[i][j] = k;
                    k++;
                }
            }


            if (month[i][j] != 0)
            {

                *nextFirstDay = j + 1;
            }
        }
    }

    return month;
}




int main()
{
    std::vector<int**> monthsOfYear;
    int firstDay = 0, year = 0;

    std::cout << "Enter first day: ";
    std::cin >> firstDay;
    firstDay -= 1;
    std::cout << std::endl << "Enter year: ";
    std::cin >> year;
    cout << endl;
    //fill the year with the months
    for (int i = 0; i < 12; i++)
    {
        auto month = createMonth(i, firstDay, year, &firstDay);
        monthsOfYear.push_back(month);
    }
    int counter = 0;
    do
    {
        monthNames(counter);
        displayMonth(monthsOfYear[counter]);

        counter++;
    } while (counter < 12);
    DeAllocMonth();


}

