#include <stdio.h> // ��� printf() � scanf()
#include <conio.h> // ��� _getch()
#include <windows.h>
#include <iostream>
#include <random>
#include <time.h>
#include<fstream>

using namespace std;
HANDLE hConsole, hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//��������� ������ �-� �� ���� ����� ��������� � ���������� ����

int m_pos = 0;          // ��������� ������� ����
int max_pos = 3;        // ������������ ������� ����
char s1[101];           // array
const char Number = 6;  //Number-�-�� ������
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

char* ru(char* s) { AnsiToOem(s, s1);   return s1; } // ����� ������� ������
void ready() {

}
void create_new() {

}
void SetColor(int text, int background) // ������������� ����
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 5) | text));
}

void GotoXY(int X, int Y) // ������� �������
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
struct Train {
	int Destination;//Destination-����� ����������� 
	int TrNumber;//TrNumber-����� ������
	int Hours;//Hours:Minuts-��� ����������
	int Minuts;
};
int perevirka() {
	int real;
	while (!(cin >> real) || real<1)
	{
		cin.clear();
		cin.ignore(50, '\n');
		cout << "����������� ��i�\n����i�� �����";
	}
	return real;
}
void main();
void Dest_c(int dest) {//Dest_c = Destinationn cout ���� �����-��������� ����� ������� �������� ������� ��������� �������� ������� ����� ������� ������
	switch (dest) {
	case 1:cout << "-K��";break;//1
	case 2:cout << "-���i�";break;//2
	case 3:cout << "-I����-�����i����";break;//3
	case 4:cout << "-�����";break;//4
	case 5:cout << "-����i��i";break;//5
	case 6:cout << "-�i��������";break;//6
	case 7:cout << "-������i��";break;//7
	case 8:cout << "-�������";break;//8
	case 9:cout << "-�����i���";break;//9
	case 10:cout << "-�������";break;//10
	case 11:cout << "-�������";break;//11
	case 12:cout << "-������";break;//12
	case 13:cout << "-�i����";break;//13
	}
}
void Entering() {

	system("cls");
	cout << "1.������ � ����i����� ���i � �����, �� ����������� � 6 ��������� ���� Train\n\n";
	
	Train ar_Train[Number];//Train- ar_Train- 
						   //������� ��������
	for (int i = 0;i < Number;i++) {
		cout << "����i�� ���i ��� " << i + 1 << "-�� ������:\n";
		int destination = 0;
		cout << "K�� = 1, ���i� = 2, I����-�����i���� = 3, ����� = 4, ����i��i = 5,\n�i�������� = 6,"
			"������i�� = 7, ������� = 8, �����i��� = 9, ������� = 10,\n������� = 11, ������ = 12, �i���� = 13 \n";

		do {
			cout << "\n����� ����������� (�����)";
			destination = perevirka();
		} while (destination < 1 || destination>13);
		ar_Train[i].Destination = destination;//
		Dest_c(ar_Train[i].Destination);
		cout << "\n����� �����:";
		ar_Train[i].TrNumber = perevirka();
		int t_hours = 0, t_minuts = 0;
		do {
			cout << "\n��� �i����������(����� 0-23) ";
			t_hours = perevirka();
		} while (t_hours > 23 || t_hours < 0);
		ar_Train[i].Hours = t_hours;
		do {
			cout << "\n��� �i���������� (������� 0-59) ";
			t_minuts = perevirka();
		} while (t_minuts < 0 || t_minuts>59);
		ar_Train[i].Minuts = t_minuts;
		system("cls");
	}
	//      //      //      //      //     //     //
	// ������� �� �����
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
	// �������� ���������� �� �����
	cout << "���������� �� ����� �i����������\n";
	cout << "����� ������\t��� �i����������\t����� ����������� \n";
	
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
	cout << "\n������i�� ENTER ���� �������� i�������i� ��������� � ����i\n������i�� i��� ����i�� ��� ������ � ����\n";
	ifstream fin;
	char o;
	o = _getch();
	switch (o) {
	case 13:
		system("cls");
		fin.open("09.11.15.txt");cout << "������� ���� �����i� �� 09.11.15.\n";
		for (int i = 0;i < Number;i++) {
			fin.read((char*)&ar_Train[i], sizeof(Train));
			cout << ar_Train[i].TrNumber << '\t' << '\t';
			cout << ar_Train[i].Hours << ":";
			cout << ar_Train[i].Minuts << '\t' << '\t' << '\t';
			Dest_c(ar_Train[i].Destination);
			cout << endl;
		}
		cout << "\n������i�� ENTER";
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
	do {cout << "�����i�� ���� �� ���� ������ �i������� ������� ����";
		cout << "\n05.11.15     ������i�� 1\n06.11.15     ������i�� 2\n07.11.15     ������i�� 3\n08.11.15     ������i�� 4\n";
		o = _getch();
		cout << "\no=" << o;
		system("cls");
	} while (o < 49 || o>52);
	switch (o) {
	case 49:fin.open("05.11.15.txt");cout << "������� ���� �����i� �� 05.11.15.\n";break;
	case 50:fin.open("06.11.15.txt");cout << "������� ���� �����i� �� 06.11.15.\n";break;
	case 51:fin.open("07.11.15.txt");cout << "������� ���� �����i� �� 07.11.15.\n";break;
	case 52:fin.open("08.11.15.txt");cout << "������� ���� �����i� �� 08.11.15.\n";break;
		}
	cout << "����� ������\t��� �i����������\t����� ����������� \n";
	for (int i = 0;i < Number;i++) {
		fin.read((char*)&ar_Train[i], sizeof(Train));
		cout << ar_Train[i].TrNumber << '\t' << '\t';
		cout << ar_Train[i].Hours << ":";
		cout << ar_Train[i].Minuts << '\t' << '\t' << '\t';
		Dest_c(ar_Train[i].Destination);
		cout << endl;
	}
	fin.close();
	cout << "\n������i�� ENTER";
	cin.get();
	main();
}
void go(int x) // ���� ������ Enter
{
	if (x == 0) Ready();
	if (x == 1) Entering();
	if (x == 2) //exit();
	cout << "\n   ������� �����\n      �������";
	SetColor(0, 0);
	GotoXY(35, 24);
	exit(0);
}

void choice();

void menu()
{
	system("cls"); // �������� �����
	setlocale(0, "");
	if (m_pos == 0)
	{ 
		cout << "������� �������� Train , ��� �i��� �������i ����:\n\n ";
		cout << "- ����� ������ ��������;\n\n- ����� ������;\n\n- ��� �i���������� ������;\n\n";
		
		SetColor(6, 0); cout << " + �i������ ��� �����i �������� ���� �����i�\n"; SetColor(15, 0);
		cout << "   C������� ���i �������� ���� �����i�\n";
		cout << "   ���i�\n";
		choice();
	}
	if (m_pos == 1)
	{
		cout << "������� �������� Train , ��� �i��� �������i ����:\n\n ";
		cout << "- ����� ������ ��������;\n\n- ����� ������;\n\n- ��� �i���������� ������;\n\n";

		cout << "   �i������ ��� �����i �������� ���� �����i�\n";
		SetColor(6, 0); cout << " + C������� ���i �������� ���� �����i�\n"; SetColor(15, 0);
		cout << "   ���i�\n";
		choice();
	}
	if (m_pos == 2)
	{
		cout << "������� �������� Train , ��� �i��� �������i ����:\n\n ";
		cout << "- ����� ������ ��������;\n\n- ����� ������;\n\n- ��� �i���������� ������;\n\n";

		cout << "   �i������ ��� �����i �������� ���� �����i�\n";
		cout << "   C������� ���i �������� ���� �����i�\n";
		SetColor(6, 0); cout << " + ���i�\n"; SetColor(15, 0);
		choice();
	}
	}


void choice() // ������� ������
{
l:
	int ch = _getch(); // ��������� �������� ������� �������
	if (ch == 224) // 224 - ��� ���������
	{
		switch (ch)
		{
		case 80: // ����
			if (m_pos + 1<max_pos) ++m_pos;
			menu();
			break;
		case 72: // �����
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
	case 80: // ����
		if (m_pos + 1<max_pos) ++m_pos;
		menu();
		break;
	case 72: // �����
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
