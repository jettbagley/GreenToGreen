#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void getMoney();
void getStuff();
void convertMoneyStuff(double);
void convertStuffMoney(int, int, double);

int main()
{
	int select;

	do
	{
		cout << "Welcome to Green to Green Converter!\n\n";
		cout << "Please select an option\n1. Convert Money to Recyclable Bottles and Cans\n";
		cout << "2. Convert Bottles and Cans to Money\n:";
		cin >> select;

		if (select != 1 && select != 2)
			cout << "\n\nNOT A MENU OPTION\n\n";
	} while (select != 1 && select != 2);

	if (select == 1)
		getMoney();
	else
		getStuff();

	system("pause");
	return 0;
}

void getMoney()
{
	string result;
	double money = 0;

	do
	{
		cout << "\nEnter the ammount of money you want to convert: ";
		cin >> money;

		if (money <= 0)
			cout << "\nNOT APPROVED AMMOUNT\n";
	} while (money <= 0);

	cout << endl;
	convertMoneyStuff(money);
}

void getStuff()
{
	int bottleA, bottleB;
	double paper;

	do
	{
		cout << "\nEnter the ammount of less than 24 ounce bottles you have: ";
		cin >> bottleA;

		cout << "Enter the ammount of 24 or greater than bottles you have: ";
		cin >> bottleB;

		cout << "Enter the ammount of paper you have in tons: ";
		cin >> paper;

		if (paper < 0 || bottleA < 0 || bottleB < 0)
			cout << "\nNO NEGATIVE VALUES FOR ANY OF THESE OPTIONS!\n";
	} while (paper < 0 || bottleA < 0 || bottleB < 0);
	
	cout << endl;
	convertStuffMoney(bottleA, bottleB, paper);
}

void convertMoneyStuff(double money)
{
	double value = 0.0;
	int bottleA = 0, bottleB = 0;

	while (value <= money)
	{
		value += 0.05;
		bottleA++;
	}
	cout << "You would need " << bottleA << " less than 24 ounce cans and bottles to get the value of " << setprecision(2) << fixed << value << endl;

	value = 0.0;
	while (value <= money)
	{
		value += 0.1;
		bottleB++;
	}
	cout << "You would need " << bottleB << " 24 or greater ounce cans and bottles to get the value of " << setprecision(2) << fixed << value << endl;
}

void convertStuffMoney(int bottleA, int bottleB, double paper)
{
	cout << "You would get $" << setprecision(2) << fixed << (bottleA * 0.05) << " for your " << bottleA << " less than 24 ounce bottles.\n";
	cout << "You would get $" << setprecision(2) << fixed << (bottleB * 0.1) << " for your " << bottleB << " 24 ounce or greater bottles.\n";
	cout << "You would get $" << setprecision(2) << fixed << (paper * 50) << " for your " << paper << " tons of paper.\n";
}
