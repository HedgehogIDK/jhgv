#include <iostream>
#include "PhoneBook.h"

using namespace std;

PhoneBook* creat(int num);
void addCont(PhoneBook PhBook[], int& num);
void delCon(PhoneBook PhBook[], int& num);
void display(PhoneBook PhBook[], int& num);

int main() {
	setlocale(LC_ALL, "RUS");

	int menu;
	int num;
	PhoneBook* Phone;


	cout << "������� ���-�� ���������: ";
	cin >> num;

	if (num <= 0) {
		cout << "���������� ��������� ������ ���� ������������� � �� ����� ����!\n";

		return 0;
	}

	Phone = creat(num);

	do {

		cout << "\n1 �������� ������ ��������\n2 ������� ��������\n3 ������ ��������� �� ���\n4 ���������� ���� ���������\n5 ��������� ���������� � ����\n6 ��������� ����\n0 - �����\n�������: ";
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
	char buffer[100];

	for (int i = 0;i < num;i++) {
		Phone[i] = PhBook[i];
	}

	num++;

	printf( "������� ���: ");
	gets_s(buffer);

	Phone[num].set_fullName(buffer);

	printf("\n������� �������� �������: ");
	gets_s(buffer);

	Phone[num].set_homePhone(buffer);

	printf("\n������� ��������� �������: ");
	gets_s(buffer);

	Phone[num].set_mobilePhone(buffer);

	printf("\n������� ������� �������: ");
	gets_s(buffer);

	Phone[num].set_workPhone(buffer);

	printf("\n������� ���. ����������: ");
	gets_s(buffer);

	Phone[num].set_Information(buffer);

	delete[] PhBook;

	PhBook = Phone;
}

PhoneBook* creat(int num) {
	PhoneBook* Phone =  new PhoneBook[num];

	char buffer[100];

	for (int i = 0;i < num;i++) {

		printf("������� ���: ");
		cin.ignore();

		gets_s(buffer);

		Phone[i].set_fullName(buffer);

		printf("������� �������� �������: ");
		gets_s(buffer);

		Phone[i].set_homePhone(buffer);

		printf("������� ��������� �������: ");
		gets_s(buffer);

		Phone[i].set_mobilePhone(buffer);

		printf("������� ������� �������: ");
		gets_s(buffer);

		Phone[i].set_workPhone(buffer);

		printf("������� ���. ����������: ");
		gets_s(buffer);

		Phone[i].set_Information(buffer);
	}

	return Phone;
}

void delCon(PhoneBook PhBook[], int& num) {
	PhoneBook* Phone = new PhoneBook[num--];

	for (int i = 0;i < num;i++) {
		Phone[i] = PhBook[i];
	}

	delete[] PhBook;

	PhBook = Phone;
}

void display(PhoneBook PhBook[], int& num) {
	for (int i = 0;i < num;i++) {
		printf("\n���: %s\n��������� �������: %s\n�������� �������: %s\n������� �������: %s\n���. ����������: %s\n", PhBook[i].get_fullName(),PhBook[i].get_mobilePhone(), PhBook[i].get_homePhone(),PhBook[i].get_workPhone(),PhBook[i].get_Information());
	}
}
