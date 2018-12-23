#include "Family.h"
#include <iostream>
Family::Family() {

}
//constructor
Family::Family(string FamilyName, int FamilyNum, int MailNum, double Dad_salary, double Mam_salary, double AverageMonth_bills) {
	if ((FamilyName.length() < 20) && (MailNum < 30500) && (MailNum > 0)) {
		this->FamilyName = FamilyName;
		this->FamilyNum = FamilyNum;
		this->MailNum = MailNum;
		this->Dad_salary = Dad_salary;
		this->Mam_salary = Mam_salary;
		this->AverageMonth_bills = AverageMonth_bills;
	}
	else {
		this->FamilyName = "";
		this->FamilyNum = 0;
		this->MailNum = 0;
		this->Dad_salary = 0;
		this->Mam_salary = 0;
		this->AverageMonth_bills = 0;
	}
}
string Family::getFamilyName() const {
	return this->FamilyName;
}
void Family::setFamilyName(string NewFamilyName) {
	this->FamilyName = NewFamilyName;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Family::getFamilyNum() const {
	return this->FamilyNum;
}
void Family::setFamilyNum(int NewFamilyNum) {
	this->FamilyNum = NewFamilyNum;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int  Family::getMailNum() const {
	return this->MailNum;
}
void Family::setMailNum(int NewMailNum) {
	this->MailNum = NewMailNum;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double Family::getDad_salary() const {
	return this->Dad_salary;
}
void  Family::setDad_salary(double NewDad_salary) {
	this->Dad_salary = NewDad_salary;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double Family::getMam_salary() const {
	return this->Mam_salary;
}
void  Family::setMam_salary(double NewMam_salary) {
	this->Mam_salary = NewMam_salary;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double  Family::getAverageMonth_bills () const {
	return this->AverageMonth_bills;
}
void  Family::setAverageMonth_bills(double NewAverageMonth_bills) {
	this->AverageMonth_bills = NewAverageMonth_bills;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void  Family::show() const {     //show Family details
	cout << "There are " << this->FamilyNum << " in's family. Mail Box Number: " << this->MailNum << endl;
	cout << "Mam's Salary: " << this->Mam_salary << " and Dad's Salary: " << this->Dad_salary << ". Expense: " << this->AverageMonth_bills << "." << endl;
}

bool  Family::isGreater() {       //Check who is richer
	if (this->Mam_salary > this->Dad_salary) {
		return true;
	}
	else {
		return false;
	}
}
double  Family::saving() { //
	double sum = (this->Mam_salary) + (this->Dad_salary) - (this->AverageMonth_bills);
	return sum;
}
void Family::betterMonth(double sum) {
	if (sum < this->Mam_salary + this->Dad_salary) {
		cout << "This month " << this->FamilyName << "'s Family saved more then last month." << endl;
	}
	else if (sum > this->Mam_salary + this->Dad_salary) {
		cout << "This month " << this->FamilyName << "'s Family saved less then last month." << endl;
	}
	else {
		cout << "This month " << this->FamilyName << "'s Family saved the same like last month." << endl;
	}

}
