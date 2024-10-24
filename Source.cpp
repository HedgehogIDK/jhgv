#include <iostream>
#include "PhoneBook.h"

using namespace std;

void creat(int num, PhoneBook* Phone);
void addCont(PhoneBook PhBook[], int& num);
void delCon(PhoneBook PhBook[], int& num);
void display(PhoneBook PhBook[], int& num);

int main() {
	setlocale(LC_ALL, "RUS");

	int menu;
	int buffer;
	char buffer_Str[100];
	int num;
	PhoneBook* Phone;


	cout << "������� ���-�� ���������: ";
	cin >> num;

	if (num <= 0) {
		cout << "���������� ��������� ������ ���� ������������� � �� ����� ����!\n";

		return 0;
	}

	Phone = new PhoneBook[num];

	

	for (int i = 0;i < num;i++) {

		cout << "������� ���: ";
		cin.ignore();

		gets_s(buffer_Str);

		Phone[num].set_fullName(buffer_Str);

		cout << "\n������� �������� �������: ";
		cin >> buffer;

		Phone[num].set_homePhone(buffer);

		cout << "\n������� ��������� �������: ";
		cin >> buffer;

		Phone[num].set_mobilePhone(buffer);

		cout << "\n������� ������� �������: ";
		cin >> buffer;

		Phone[num].set_workPhone(buffer);

		cout << "\n������� ���. ����������: ";
		cin.ignore();

		gets_s(buffer_Str);

		Phone[num].set_Information(buffer_Str);
	}



	do {

		cout << "1 �������� ������ ��������\n2 ������� ��������\n3 ������ ��������� �� ���\n4 ���������� ���� ���������\n5 ��������� ���������� � ����\n6 ��������� ����\n0 - �����\n�������: ";
		cin >> menu;

		switch (menu)
		{
		case 0:
			cout << ":)";

			break;

		case 1:
			addCont(Phone, num);

			break;

		case 2:
			delCon(Phone, num);

			break;

		case 3:

			break;

		case 4:
			display(Phone, num);

			break;

		case 5:

			break;

		case 6:

			break;

		default:
			cout << "��� ����� �������!";

			break;
		}

	} while (menu);

	return 0;
}

void addCont(PhoneBook PhBook[], int& num) {
	PhoneBook* Phone =  new PhoneBook[num + 1];
	int buffer;
	char buffer_Str[100];

	for (int i = 0;i < num;i++) {
		Phone[i].set_fullName(PhBook[i].get_fullName());
	}

	num++;

	cout << "������� ���: ";
	cin.ignore();

	gets_s(buffer_Str);

	Phone[num].set_fullName(buffer_Str);

	cout << "\n������� �������� �������: ";
	cin >> buffer;

	Phone[num].set_homePhone(buffer);

	cout << "\n������� ��������� �������: ";
	cin >> buffer;

	Phone[num].set_mobilePhone(buffer);

	cout << "\n������� ������� �������: ";
	cin >> buffer;

	Phone[num].set_workPhone(buffer);

	cout << "\n������� ���. ����������: ";
	cin.ignore();

	gets_s(buffer_Str);

	Phone[num].set_Information(buffer_Str);

	PhBook = Phone;
}

void creat(int num, PhoneBook* Phone) {
	Phone =  new PhoneBook[num];

	int buffer;
	char buffer_Str[100];

	for (int i = 0;i < num;i++) {

		cout << "������� ���: ";
		cin.ignore();

		gets_s(buffer_Str);

		Phone[num].set_fullName(buffer_Str);

		cout << "\n������� �������� �������: ";
		cin >> buffer;

		Phone[num].set_homePhone(buffer);

		cout << "\n������� ��������� �������: ";
		cin >> buffer;

		Phone[num].set_mobilePhone(buffer);

		cout << "\n������� ������� �������: ";
		cin >> buffer;

		Phone[num].set_workPhone(buffer);

		cout << "\n������� ���. ����������: ";
		cin.ignore();

		gets_s(buffer_Str);

		Phone[num].set_Information(buffer_Str);
	}
}

void delCon(PhoneBook PhBook[], int& num) {
	PhoneBook* Phone = new PhoneBook[num--];

	for (int i = 0;i < num;i++) {
		Phone[i] = PhBook[i];
	}

	PhBook = Phone;
}

void display(PhoneBook PhBook[], int& num) {
	for (int i = 0;i < num;i++) {
		cout << "\n���: " << PhBook[i].get_fullName() << "\n�������� �������: " << PhBook[i].get_homePhone() << "\n��������� �������: " << PhBook[i].get_mobilePhone() << "\n������� �������: " << PhBook[i].get_workPhone() << "\n���. ����������: " << PhBook[i].get_Information();
	}
}
