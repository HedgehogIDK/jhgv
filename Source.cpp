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


	cout << "Введите кол-во контактов: ";
	cin >> num;

	if (num <= 0) {
		cout << "Количество контактов должно быть положительным и не равно нулю!\n";

		return 0;
	}

	Phone = creat(num);

	do {

		cout << "\n1 Добавить нового абонента\n2 Удалить абонента\n3 Искать абонентов по ФИО\n4 Показывать всех абонентов\n5 Сохранить информацию в файл\n6 Загрузить файл\n0 - Выход\nВведите: ";
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
	char buffer[100];

	for (int i = 0;i < num;i++) {
		Phone[i] = PhBook[i];
	}

	num++;

	printf( "Введите ФИО: ");
	gets_s(buffer);

	Phone[num].set_fullName(buffer);

	printf("\nВведите домашний телефон: ");
	gets_s(buffer);

	Phone[num].set_homePhone(buffer);

	printf("\nВведите мобильный телефон: ");
	gets_s(buffer);

	Phone[num].set_mobilePhone(buffer);

	printf("\nВведите рабочий телефон: ");
	gets_s(buffer);

	Phone[num].set_workPhone(buffer);

	printf("\nВведите доп. информацию: ");
	gets_s(buffer);

	Phone[num].set_Information(buffer);

	delete[] PhBook;

	PhBook = Phone;
}

PhoneBook* creat(int num) {
	PhoneBook* Phone =  new PhoneBook[num];

	char buffer[100];

	for (int i = 0;i < num;i++) {

		printf("Введите ФИО: ");
		cin.ignore();

		gets_s(buffer);

		Phone[i].set_fullName(buffer);

		printf("Введите домашний телефон: ");
		gets_s(buffer);

		Phone[i].set_homePhone(buffer);

		printf("Введите мобильный телефон: ");
		gets_s(buffer);

		Phone[i].set_mobilePhone(buffer);

		printf("Введите рабочий телефон: ");
		gets_s(buffer);

		Phone[i].set_workPhone(buffer);

		printf("Введите доп. информацию: ");
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
		printf("\nФИО: %s\nМобильный телефон: %s\nДомашний телефон: %s\nРабочий телефон: %s\nДоп. информация: %s\n", PhBook[i].get_fullName(),PhBook[i].get_mobilePhone(), PhBook[i].get_homePhone(),PhBook[i].get_workPhone(),PhBook[i].get_Information());
	}
}
