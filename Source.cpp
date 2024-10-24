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


	cout << "Введите кол-во контактов: ";
	cin >> num;

	if (num <= 0) {
		cout << "Количество контактов должно быть положительным и не равно нулю!\n";

		return 0;
	}

	Phone = new PhoneBook[num];

	

	for (int i = 0;i < num;i++) {

		cout << "Введите ФИО: ";
		cin.ignore();

		gets_s(buffer_Str);

		Phone[num].set_fullName(buffer_Str);

		cout << "\nВведите домашний телефон: ";
		cin >> buffer;

		Phone[num].set_homePhone(buffer);

		cout << "\nВведите мобильный телефон: ";
		cin >> buffer;

		Phone[num].set_mobilePhone(buffer);

		cout << "\nВведите рабочий телефон: ";
		cin >> buffer;

		Phone[num].set_workPhone(buffer);

		cout << "\nВведите доп. информацию: ";
		cin.ignore();

		gets_s(buffer_Str);

		Phone[num].set_Information(buffer_Str);
	}



	do {

		cout << "1 Добавить нового абонента\n2 Удалить абонента\n3 Искать абонентов по ФИО\n4 Показывать всех абонентов\n5 Сохранить информацию в файл\n6 Загрузить файл\n0 - Выход\nВведите: ";
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
			cout << "Нет такой команды!";

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

	cout << "Введите ФИО: ";
	cin.ignore();

	gets_s(buffer_Str);

	Phone[num].set_fullName(buffer_Str);

	cout << "\nВведите домашний телефон: ";
	cin >> buffer;

	Phone[num].set_homePhone(buffer);

	cout << "\nВведите мобильный телефон: ";
	cin >> buffer;

	Phone[num].set_mobilePhone(buffer);

	cout << "\nВведите рабочий телефон: ";
	cin >> buffer;

	Phone[num].set_workPhone(buffer);

	cout << "\nВведите доп. информацию: ";
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

		cout << "Введите ФИО: ";
		cin.ignore();

		gets_s(buffer_Str);

		Phone[num].set_fullName(buffer_Str);

		cout << "\nВведите домашний телефон: ";
		cin >> buffer;

		Phone[num].set_homePhone(buffer);

		cout << "\nВведите мобильный телефон: ";
		cin >> buffer;

		Phone[num].set_mobilePhone(buffer);

		cout << "\nВведите рабочий телефон: ";
		cin >> buffer;

		Phone[num].set_workPhone(buffer);

		cout << "\nВведите доп. информацию: ";
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
		cout << "\nФИО: " << PhBook[i].get_fullName() << "\nДомашний телефон: " << PhBook[i].get_homePhone() << "\nМобильный телефон: " << PhBook[i].get_mobilePhone() << "\nРабочий телефон: " << PhBook[i].get_workPhone() << "\nДоп. информация: " << PhBook[i].get_Information();
	}
}
