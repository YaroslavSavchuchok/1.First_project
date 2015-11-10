#include <stdio.h> // для printf() и scanf()
#include <conio.h> // для _getch()
#include <windows.h>
#include <iostream>
#include <random>
#include <time.h>
#include<fstream>

using namespace std;
HANDLE hConsole, hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//створюємо потрібні ф-ї які потім можна викликати з основоного меню

int m_pos = 0;          // початкова позиция меню
int max_pos = 3;        // максимальная позиция меню
char s1[101];           // array
const char Number = 6;  //Number-к-ть потягів
enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

char* ru(char* s) { AnsiToOem(s, s1);   return s1; } // вывод русским языком
void ready() {

}
void create_new() {

}
void SetColor(int text, int background) // устанавливаем цвет
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 5) | text));
}

void GotoXY(int X, int Y) // позиция курсора
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
struct Train {
	int Destination;//Destination-пункт призначення 
	int TrNumber;//TrNumber-номер потягу
	int Hours;//Hours:Minuts-час відправленя
	int Minuts;
};
int perevirka() {
	int real;
	while (!(cin >> real) || real<1)
	{
		cin.clear();
		cin.ignore(50, '\n');
		cout << "Некоректний ввiд\nВведiть число";
	}
	return real;
}
void main();
void Dest_c(int dest) {//Dest_c = Destinationn cout львів івано-франківськ одеса чернівці тернопіль ужгород кіровоград запоріжжя черкаси віниця полтава херсон
	switch (dest) {
	case 1:cout << "-Kиїв";break;//1
	case 2:cout << "-Львiв";break;//2
	case 3:cout << "-Iвано-Франкiвськ";break;//3
	case 4:cout << "-Одеса";break;//4
	case 5:cout << "-Чернiвцi";break;//5
	case 6:cout << "-Кiровоград";break;//6
	case 7:cout << "-Тернопiль";break;//7
	case 8:cout << "-Ужгород";break;//8
	case 9:cout << "-Запорiжжя";break;//9
	case 10:cout << "-Черкаси";break;//10
	case 11:cout << "-Полтава";break;//11
	case 12:cout << "-Херсон";break;//12
	case 13:cout << "-Вiниця";break;//13
	}
}
void Entering() {

	system("cls");
	cout << "1.Вводим з клавiатури данi в масив, що складаэться з 6 елементыв типу Train\n\n";
	
	Train ar_Train[Number];//Train- ar_Train- 
						   //Вводимо значення
	for (int i = 0;i < Number;i++) {
		cout << "Введiть данi для " << i + 1 << "-го потягу:\n";
		int destination = 0;
		cout << "Kиїв = 1, Львiв = 2, Iвано-Франкiвськ = 3, Одеса = 4, Чернiвцi = 5,\nКiровоград = 6,"
			"Тернопiль = 7, Ужгород = 8, Запорiжжя = 9, Черкаси = 10,\nПолтава = 11, Херсон = 12, Вiниця = 13 \n";

		do {
			cout << "\nПункт призначення (число)";
			destination = perevirka();
		} while (destination < 1 || destination>13);
		ar_Train[i].Destination = destination;//
		Dest_c(ar_Train[i].Destination);
		cout << "\nНомер поїзду:";
		ar_Train[i].TrNumber = perevirka();
		int t_hours = 0, t_minuts = 0;
		do {
			cout << "\nЧас вiдправлення(годин 0-23) ";
			t_hours = perevirka();
		} while (t_hours > 23 || t_hours < 0);
		ar_Train[i].Hours = t_hours;
		do {
			cout << "\nЧас вiдправлення (хвилини 0-59) ";
			t_minuts = perevirka();
		} while (t_minuts < 0 || t_minuts>59);
		ar_Train[i].Minuts = t_minuts;
		system("cls");
	}
	//      //      //      //      //     //     //
	// Сортуємо за часом
	for (int j = 0;j + 1 < Number;j++) {
		for (int i = 0;i + 1 < Number;i++) {
			int k = 0;
			if (ar_Train[i].Hours == ar_Train[i + 1].Hours) {
				if (ar_Train[i].Minuts > ar_Train[i + 1].Minuts) { k = 1; }
			}
			if (ar_Train[i].Hours > ar_Train[i + 1].Hours) { k = 1; }
			if (k == 1) {
				int change1, change2, change3, change4;
				change1 = ar_Train[i].Destination;change2 = ar_Train[i].TrNumber;
				change3 = ar_Train[i].Hours;change4 = ar_Train[i].Minuts;
				ar_Train[i].Destination = ar_Train[i + 1].Destination;ar_Train[i].TrNumber = ar_Train[i + 1].TrNumber;
				ar_Train[i].Hours = ar_Train[i + 1].Hours;ar_Train[i].Minuts = ar_Train[i + 1].Minuts;
				ar_Train[i + 1].Destination = change1;ar_Train[i + 1].TrNumber = change2;
				ar_Train[i + 1].Hours = change3;ar_Train[i + 1].Minuts = change4;
			}

		}
	}
	//      //      //      //      //     //     //
	// Виводимо інформацію на екран
	cout << "Упорядкуємо за часом вiдправлення\n";
	cout << "Номер потягу\tЧас вiдправлення\tПункт призначення \n";
	
	for (int i = 0;i < Number;i++) {

		cout << ar_Train[i].TrNumber << '\t' << '\t' << ar_Train[i].Hours << ":" << ar_Train[i].Minuts << '\t' << '\t' << '\t';
		Dest_c(ar_Train[i].Destination);
		cout << "\n";
	}
	ofstream fout;
	fout.open("09.11.15.txt",ios::app);
	for (int i = 0;i < Number;i++) {
		fout.write((char*)&ar_Train[i], sizeof(Train));
	}
	fout.close();
	cout << "\nНатиснiть ENTER щоби побачити iнформацiю збережену у файлi\nНатиснiть iншу клавiшу для виходу в меню\n";
	ifstream fin;
	char o;
	o = _getch();
	switch (o) {
	case 13:
		system("cls");
		fin.open("09.11.15.txt");cout << "Розклад руху потягiв на 09.11.15.\n";
		for (int i = 0;i < Number;i++) {
			fin.read((char*)&ar_Train[i], sizeof(Train));
			cout << ar_Train[i].TrNumber << '\t' << '\t';
			cout << ar_Train[i].Hours << ":";
			cout << ar_Train[i].Minuts << '\t' << '\t' << '\t';
			Dest_c(ar_Train[i].Destination);
			cout << endl;
		}
		cout << "\nНатиснiть ENTER";
		cin.get();
		fin.close();
	default:fin.close();main();break;
	}
cin.get();cin.get();


}
void Ready() {
	Train ar_Train[Number];
	ifstream fin;
	int o;
	do {cout << "Виберiть день на який бажаєте дiзнатися розклад руху";
		cout << "\n05.11.15     натиснiть 1\n06.11.15     натиснiть 2\n07.11.15     натиснiть 3\n08.11.15     натиснiть 4\n";
		o = _getch();
		cout << "\no=" << o;
		system("cls");
	} while (o < 49 || o>52);
	switch (o) {
	case 49:fin.open("05.11.15.txt");cout << "Розклад руху потягiв на 05.11.15.\n";break;
	case 50:fin.open("06.11.15.txt");cout << "Розклад руху потягiв на 06.11.15.\n";break;
	case 51:fin.open("07.11.15.txt");cout << "Розклад руху потягiв на 07.11.15.\n";break;
	case 52:fin.open("08.11.15.txt");cout << "Розклад руху потягiв на 08.11.15.\n";break;
		}
	cout << "Номер потягу\tЧас вiдправлення\tПункт призначення \n";
	for (int i = 0;i < Number;i++) {
		fin.read((char*)&ar_Train[i], sizeof(Train));
		cout << ar_Train[i].TrNumber << '\t' << '\t';
		cout << ar_Train[i].Hours << ":";
		cout << ar_Train[i].Minuts << '\t' << '\t' << '\t';
		Dest_c(ar_Train[i].Destination);
		cout << endl;
	}
	fin.close();
	cout << "\nНатиснiть ENTER";
	cin.get();
	main();
}
void go(int x) // Если нажали Enter
{
	if (x == 0) Ready();
	if (x == 1) Entering();
	if (x == 2) //exit();
	cout << "\n   Нажмите любую\n      клавишу";
	SetColor(0, 0);
	GotoXY(35, 24);
	exit(0);
}

void choice();

void menu()
{
	system("cls"); // очистить экран
	setlocale(0, "");
	if (m_pos == 0)
	{ 
		cout << "Описати стрктуру Train , яка мiсть наступнi поля:\n\n ";
		cout << "- назва пункту прибуття;\n\n- номер потягу;\n\n- час вiдправлення потягу;\n\n";
		
		SetColor(6, 0); cout << " + Вiдкрити уже готовi розклади руху потягiв\n"; SetColor(15, 0);
		cout << "   Cтворити новi розклади руху потягiв\n";
		cout << "   Вихiд\n";
		choice();
	}
	if (m_pos == 1)
	{
		cout << "Описати стрктуру Train , яка мiсть наступнi поля:\n\n ";
		cout << "- назва пункту прибуття;\n\n- номер потягу;\n\n- час вiдправлення потягу;\n\n";

		cout << "   Вiдкрити уже готовi розклади руху потягiв\n";
		SetColor(6, 0); cout << " + Cтворити новi розклади руху потягiв\n"; SetColor(15, 0);
		cout << "   Вихiд\n";
		choice();
	}
	if (m_pos == 2)
	{
		cout << "Описати стрктуру Train , яка мiсть наступнi поля:\n\n ";
		cout << "- назва пункту прибуття;\n\n- номер потягу;\n\n- час вiдправлення потягу;\n\n";

		cout << "   Вiдкрити уже готовi розклади руху потягiв\n";
		cout << "   Cтворити новi розклади руху потягiв\n";
		SetColor(6, 0); cout << " + Вихiд\n"; SetColor(15, 0);
		choice();
	}
	}


void choice() // функция выбора
{
l:
	int ch = _getch(); // считываем значение нажатой клавиши
	if (ch == 224) // 224 - это стрелочки
	{
		switch (ch)
		{
		case 80: // вниз
			if (m_pos + 1<max_pos) ++m_pos;
			menu();
			break;
		case 72: // вверх
			if (m_pos - 1 >= 0) --m_pos;
			menu();
			break;
		case 13: // Enter
			go(m_pos);
			break;
		default:
			goto l;
		}
	}
	switch (ch)
	{
	case 80: // вниз
		if (m_pos + 1<max_pos) ++m_pos;
		menu();
		break;
	case 72: // вверх
		if (m_pos - 1 >= 0) --m_pos;
		menu();
		break;
	case 13: // Enter
		go(m_pos);
		break;
	default:
		goto l;
	}
}

void main()
{
	menu();
}
