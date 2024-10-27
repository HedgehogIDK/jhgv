#pragma once
#define SIZE 100
#define SIZE_PHONE 12
#include <iostream>
#include <cstring>

using namespace std;

class PhoneBook
{
	char* fullName;
	char homePhone[SIZE_PHONE];// лучше сделать массив символов
	char workPhone[SIZE_PHONE];
	char mobilePhone[SIZE_PHONE];
	char Info[SIZE];// лучше сделать динамическим массивом

public:
	PhoneBook() : fullName{ nullptr }, Info{ "\0" }, homePhone{ "\0" }, workPhone{ "\0" }, mobilePhone{ "\0" } {}

	//константные параметры могут принимать как константные, так и неконстантные параметы
	void set_Information(const char* Info_p) {
		strcpy_s(Info, Info_p);
	}

	//модификатор, который изменяет значение атрибута с динамической памятью должен удалить старую память, выделить новую и только потом изменить занчение
	void set_fullName(const char* fullName_p) {
		if (fullName)
			delete[] fullName;

		fullName = new char[strlen(fullName_p) + 1];
		strcpy_s(fullName, strlen(fullName_p) + 1, fullName_p);
	}

	void set_homePhone(const char* Phone) {
		strcpy_s(homePhone, Phone);
	};

	void set_workPhone(const char* Phone) {
		strcpy_s(workPhone, Phone);
	}

	void set_mobilePhone(const char* Phone) {
		strcpy_s(mobilePhone, Phone);
	}
	
	const char* get_Information() const {
		return Info;
	};

	const char* get_fullName() const {
		return fullName;
	}

	const char* get_homePhone() const {
		return homePhone;
	}

	const char* get_workPhone() const {
		return workPhone;
	}

	const char* get_mobilePhone() const {
		return mobilePhone;
	}

	~PhoneBook() {
		delete[] fullName;
	}
};

