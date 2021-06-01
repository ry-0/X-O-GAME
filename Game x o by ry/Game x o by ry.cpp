#include <iostream>
using namespace std;
void drw();
void replace(int, char);
bool checkAvailability(int);
bool checkWinner();



char c1 = '1';
char c2 = '2';
char c3 = '3';
char c4 = '4';
char c5 = '5';
char c6 = '6';
char c7 = '7';
char c8 = '8';
char c9 = '9';

char currentPlayer = 'x';



int main()
{
	
	while (true)
	{
		cout << "Made By Rayan\n " << endl;
		cout << "Welcome again" << endl;

		drw();
		int  input;
		int counter = 0;
	
		while (true)
		{

			cout << "Role\n" << currentPlayer << endl;
			cin >> input;

			while (!checkAvailability(input))
			{
				cout << "The box is reserved" << endl;
				cout << "Enter another number" << endl;
				cin >> input;
			}

			if (counter % 2 == 0)
			{
				replace(input, currentPlayer);
				currentPlayer = 'o';
			}
			else
			{
				replace(input, currentPlayer);
				currentPlayer = 'x';

			}
			counter++;
			drw();



			if (checkWinner())
			{

				cout << "Do you want to replay the game?" << endl;
				break;
			}
			else if (counter == 9)
			{
				cout << "draw" << endl;
				break;
			}
	}
		cout << "Do you want to keep playing?" << endl;
		cout << "1- continue" << endl;
		cout << "0- exit" << endl;
		cin >> input;
		if (input == 1)
		{
			continue;
		}
		else 
		{
			exit(0);
		
		}
	}
}



// يقوم رسم اللوحه 

void drw()
{
	cout << "\t" << c1 << "\t |\t" << c2 << " \t |\t" << c3 << endl;
	cout << "\t----------------------------------\n";
	cout << "\t" << c4 << "\t |\t" << c5 << " \t |\t" << c6 << endl;
	cout << "\t----------------------------------\n";
	cout << "\t" << c7 << "\t |\t" << c8 << " \t |\t" << c9 << endl;
	cout << endl;
}


//تقوم باستبدال الرقم المدخل x o
void replace(int i, char c)
{
	switch (i)
	{
	case 1:
		c1 = c;
		break;
	case 2:
		c2 = c;
		break;
	case 3:
		c3 = c;
		break;
	case 4:
		c4 = c;
		break;
	case 5:
		c5 = c;
		break;
	case 6:
		c6 = c;
		break;
	case 7:
		c7 = c;
		break;
	case 8:
		c8 = c;
		break;
	case 9:
		c9 = c;
		break;


	}

}


bool checkAvailability(int input)
{
	if (input < 1 || input > 9)
		return false;
	switch (input)
	{
	case 1:
		if (c1 == '1')
			return true;
		break;
	case 2:
		if (c2 == '2')
			return true;
		break;
	case 3:
		if (c3 == '3')
			return true;
		break;
	case 4:
		if (c4 == '4')
			return true;
		break;
	case 5:
		if (c5 == '5')
			return true;
		break;
	case 6:
		if (c6 == '6')
			return true;
		break;
	case 7:
		if (c7 == '7')
			return true;
		break;
	case 8:
		if (c8 == '8')
			return true;
		break;
	case 9:
		if (c9 == '9')
			return true;
		break;
	}


	return false;

}


bool checkXwinner()
{
	// التاكد ان الصفوف احدها يساوي x
	bool ro1 = c1 == ('x' && c2 == 'x' && c3 == 'x');
	bool ro2 = c4 == ('x' && c5 == 'x' && c6 == 'x');
	bool ro3 = c7 == ('x' && c8 == 'x' && c9 == 'x');
	// التاكد ان الاعمده تساوي x
	bool cl1 = (c1 == 'x' && c4 == 'x' && c7 == 'x');
	bool cl2 = (c2 == 'x' && c5 == 'x' && c8 == 'x');
	bool cl3 = (c3 == 'x' && c6 == 'x' && c9 == 'x');
	// التاكد من القطران
	bool di1 = (c1 == 'x' && c5 == 'x' && c9 == 'x');
	bool di2 = (c3 == 'x' && c5 == 'x' && c7 == 'x');


	if (ro1 || ro2 || ro3 || cl1 || cl2 || cl3 || di1 || di2)
	{
		cout << "you are the winner:x " << endl;
		return true;
	}
	return false;
}

bool checkOwinner()
{
	// التاكد ان الصفوف احدها يساوي o
	bool ro1 = (c1 == 'o' && c2 == 'o' && c3 == 'o');
	bool ro2 = (c4 == 'o' && c5 == 'o' && c6 == 'o');
	bool ro3 = (c7 == 'o' && c8 == 'o' && c9 == 'o');
	// التاكد ان الاعمده تساوي o
	bool cl1 = (c1 == 'o' && c4 == 'o' && c7 == 'o');
	bool cl2 = (c2 == 'o' && c5 == 'o' && c8 == 'o');
	bool cl3 = (c3 == 'o' && c6 == 'o' && c9 == 'o');
	// التاكد من القطران
	bool di1 = (c1 == 'o' && c5 == 'o' && c9 == 'o');
	bool di2 = (c3 == 'o' && c5 == 'o' && c7 == 'o');


	if (ro1 || ro2 || ro3 || cl1 || cl2 || cl3 || di1 || di2)
	{
		cout << "you are the winner:o " << endl;

		return true;
	}
	return false;

}


 //تقوم بارجاع 
 //true : ان كان هناك فاىز
 //false : ان لم تجد فاىز


bool checkWinner()
{
	return checkXwinner() || checkOwinner();
}











