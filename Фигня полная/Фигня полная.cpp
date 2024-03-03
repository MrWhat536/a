#include <iostream>
#include <string>
#include<Windows.h>
#include<ctime>
#include <cmath>
#include<vector>
#include<cctype>

using namespace std;
class Games {
public:
	int guess()
	{
		char retry = 'y';
		do {
			setlocale(LC_ALL, "ru");
			srand(time(0));
			float number = rand() % 30 + 1;
			float guess;
			bool p;
			bool a;
			bool b;
			string victory = "Вы угадали загаданное число. Юху!";
			string rule = "Я загадал число в диапазоне от 1 до 30.\n Ваша задача отгадать его. Удачи!";




			for (int i = 0; i < rule.size(); i++)
			{
				Sleep(100);
				cout << rule[i];
			}
			cout << endl;
			Sleep(1000);
			do {
				cout << "Ваше число: " << endl;
				cin >> guess;
				if ((guess - number == 2.0) || (guess - number == 1.0) || (guess - number == -2.0) || (guess - number == -1.0))
				{
					cout << "Вы очень близко!" << endl;
					b = true;
				}
				if (guess < number)
				{
					cout << "Загаданное число больше" << endl;
					b = true;
				}
				else if (guess > number)
				{
					cout << "Загаданное число меньше" << endl;
					b = true;
				}
				else if (guess = number)
				{
					for (int m = 0; m < victory.size(); m++)
					{
						Sleep(100);
						cout << victory[m];
					} cout << endl;
					b = false;
				}
				
			} while (b);
			cout << "Хотите ещё раз? (y/n)" << endl;
			
				cin >> retry;
				if (retry == 'y')
				{
					Sleep(1000);
					system("cls");
					p == false;
				}
				else if (retry == 'n')
				{
					return 0;
				}
				else if (retry != 'y' || retry != 'n')
				{
					cout << "Вы ввели не правильно!" << endl;
					p == true;
				}
			
		} while (retry == 'y');
		return 0;
	}
	


	int hangman() {
		char newgame ='y';
		do {
			SetConsoleCP(1251);
			setlocale(LC_ALL, "RU");
			srand(time(0));
			vector<string> word;
			bool a;
			float number = rand() % 12;
			word.push_back("РЫБКА");
			word.push_back("КОШКА");
			word.push_back("СОБАКА");
			word.push_back("ЧАЙ");
			word.push_back("БЛИН");
			word.push_back("ПЧЕЛА");
			word.push_back("ФИЛОСОФИЯ");
			word.push_back("СУБЪЕКТ");
			word.push_back("ЗВЕЗДА");
			word.push_back("ЛОШАДЬ");
			word.push_back("ХОББИ");
			word.push_back("ХАРАКТЕР");
			string guess = word[number];
			string gw;
			string soon(guess.size(), '-');
			short wrong = 5;
			short mywrong = 0;
			string used = "";
			char letter;
			string hello = "Добро пожаловать! Думаю, что правила вы знаете, так что удачи! \n";
			for (int i = 0; i < hello.size(); i++)
			{
				cout << hello[i];
				Sleep(100);
			}
			while ((mywrong != wrong) && (soon != guess))
			{
				cout << "У вас есть " << (wrong - mywrong) << " попыток" << endl;
				Sleep(500);
				cout << "Загаданное слово: " << soon << endl;
				cout << "Введите букву:" << endl;
				cin >> letter;
				letter = toupper(letter);
				while (used.find(letter) != string::npos)
				{
					cout << "Она уже угадана" << endl;
					cout << "Введите букву:" << endl;
					cin >> letter;
					letter = toupper(letter);
				}
				used += letter;
				if (guess.find(letter) != string::npos)
				{
					cout << "Вы угадали!" << endl;
					for (int m = 0; m < guess.size(); m++)
					{
						if (guess[m] == letter)
						{
							soon[m] = letter;
						}
					}
				}
				else
				{
					cout << "Вы не угадали!" << endl;
					mywrong++;
				}

			}
			if (mywrong == wrong)
			{
				cout << "Вы повешены!" << endl;
			}
			else
			{
				cout << "Вы угадали букву!" << endl;
			}
			cout << "Слово было: " << guess << endl;

			cout << "Хотите ещё раз? (y/n)" << endl;

			cin >> newgame;
			if (newgame == 'y')
			{
				Sleep(1000);
				system("cls");
				
			}
			else if (newgame == 'n')
			{
				return 0;
			}
			else if (newgame != 'y' || newgame != 'n')
			{
				cout << "Вы ввели не правильно!" << endl;
				
			}

		} while (newgame == 'y');


			return 0;
		}
	
};
class menu {
public:
	int cMenu()
	{
		setlocale(LC_ALL, "ru");
		int choose;
		bool x;
		string hello = "Добро пожаловать! В какую игру вы хотите сыграть?";
			for(int q=0;q<hello.size();q++)
			{
				Sleep(100);
				cout << hello[q];
			}
			
				cout << endl << "1.Угадай число  2.Виселица" << endl << "Ваш выбор?" << endl;
				
			do {
				cin >> choose;
				if((choose!=1)&&(choose!=2))
				{
					cout << "Вы ввели неправильное число!" << endl;
					x = true;
				}
				if (choose == 1)
				{
					string cool = "Хороший выбор!";
					for (int w = 0; w < cool.size(); w++)
					{
						Sleep(100);
						cout << cool[w];
					}
					cout << endl;
					Sleep(2000);
					system("cls");
					Games wow;
					wow.guess();
					x = false;
				}
				if (choose == 2)
				{
					string cool = "Хороший выбор!";
					for (int w = 0; w < cool.size(); w++)
					{
						Sleep(100);
						cout << cool[w];
					}
					cout << endl;
					Sleep(2000);
					system("cls");
					Games wow;
					wow.hangman();
					x = false;
				}
			} while (x);
			return 0;

	}
	
};

int main() {
	
	menu Menu;
	Menu.cMenu();
	
}
