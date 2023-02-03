#pragma once

#include <iostream>
#include <string>

using namespace std;

class Complex {
private:
	double Re;
	double Im;
public:
	Complex() {
		this->Re = 0.0;
		this->Im = 0.0;
	}

	Complex(double Re) {
		this->Re = Re;
		this->Im = 0.0;
	}

	Complex(double Re, double Im) {
		this->Re = Re;
		this->Im = Im;
	}

	double getRe() {
		return this->Re;
	}

	double getIm() {
		return this->Im;
	}

	void setRe(double Re) {
		this->Re = Re;
	}

	void setIm(double Im) {
		this->Im = Im;
	}

	void set(double Re, double Im) {
		this->Re = Re;
		this->Im = Im;
	}

	string toString() {
		return to_string(this->Re) + " + " + to_string(this->Im);
	}

	bool operator!= (Complex& n) {
		return this->Re != n.getRe() && this->Im != n.getIm();
	}

	bool operator== (Complex& n) {
		return this->Re == n.getRe() && this->Im == n.getIm();
	}

	bool operator<= (Complex& n) {
		return this->Re <= n.getRe() && this->Im <= n.getIm();
	}

	bool operator< (Complex& n) {
		return this->Re < n.getRe() && this->Im < n.getIm();
	}

	bool operator> (Complex& n) {
		return this->Re > n.getRe() && this->Im > n.getIm();
	}

	bool operator>= (Complex& n) {
		return this->Re >= n.getRe() && this->Im >= n.getIm();
	}

	Complex& operator= (Complex& n) {
		this->Re = n.getRe();
		this->Im = n.getIm();

		return *this;
	}

	Complex& operator+ (Complex& n) {
		this->Re += n.getRe();
		this->Im += n.getIm();

		return *this;
	}

	Complex& operator+ (double n) {
		this->Re += n;

		return *this;
	}

	Complex& operator- (Complex& n) {
		this->Re -= n.getRe();
		this->Im -= n.getIm();

		return *this;
	}

	Complex& operator- (double n) {
		this->Re -= n;

		return *this;
	}

	Complex& operator* (Complex& n) {
		this->Re = this->Re * n.getRe() - this->Im * n.getIm();
		this->Im = this->Re * n.getIm() + this->Im * n.getRe();

		return *this;
	}

	Complex operator* (double n) {
		this->Re *= n;
		this->Im *= n;

		return *this;
	}
};

ostream& operator<< (ostream& out, Complex& z) {
	out << z.getRe() << " + " << z.getIm() << " * i";

	return out;
}

istream& operator>> (istream& in, Complex& z) {
	double Re, Im;
	if (&in == &cin) {
		cout << "Enter Re(z): ";
	}
	in >> Re;

	if (&in == &cin) {
		cout << "Enter Im(z): ";
	}
	in >> Im;

	z.set(Re, Im);

	return in;
}

class Person {
private:
	int id;
	string firstName;
	string middleName;
	string lastName;
public:
	Person() {
		this->id = 0;
	}

	Person(int id) {
		this->id = id;
		this->firstName = "A";
		this->middleName = "A";
		this->lastName = "A";
	}

	Person(int id, string firstName, string middleName, string lastName) {
		this->id = id;
		this->firstName = firstName;
		this->middleName = middleName;
		this->lastName = lastName;
	}

	int getID() {
		return this->id;
	}

	string getFirstName() {
		return this->firstName;
	}

	string getMiddleName() {
		return this->middleName;
	}

	string getLastName() {
		return this->lastName;
	}

	void setID(int id) {
		this->id = id;
	}

	void setFirstName(string firstName) {
		this->firstName = firstName;
	}

	void setMiddleName(string middleName) {
		this->middleName = middleName;
	}

	void setLastName(string lastName) {
		this->lastName = lastName;
	}

	void set(int id, string firstName, string middleName, string lastName) {
		this->id = id;
		this->firstName = firstName;
		this->middleName = middleName;
		this->lastName = lastName;
	}

	string toString() {
		return to_string(this->id) + ' ' + this->firstName + ' ' + this->middleName + ' ' + this->lastName;
	}

	bool operator== (Person& p) {
		return this->id == p.getID() && this->firstName == p.getFirstName() && this->middleName == p.getMiddleName() && this->lastName == p.getLastName();
	}

	bool operator!= (Person& p) {
		return this->id != p.getID() || this->firstName != p.getFirstName() || this->middleName != p.getMiddleName() || this->lastName != p.getLastName();
	}

	bool operator<= (Person& p) {
		return this->id <= p.getID();
	}

	bool operator< (Person& p) {
		return this->id < p.getID();
	}

	bool operator> (Person& p) {
		return this->id > p.getID();
	}

	bool operator>= (Person& p) {
		return this->id >= p.getID();
	}

	Person& operator = (Person& p) {
		this->id = p.getID();
		this->firstName = p.getFirstName();
		this->middleName = p.getMiddleName();
		this->lastName = p.getLastName();

		return *this;
	}
};

ostream& operator<< (ostream& out, Person& p) {
	out << p.getID() << ' ' << p.getFirstName() << ' ' << p.getMiddleName() << ' ' << p.getLastName();

	return out;
}

istream& operator>> (istream& in, Person& p) {
	int id;
	string firstName, middleName, lastName;

	if (&in == &cin) {
		cout << "Enter ID, the first name, middle name and the last name: ";
	}
	in >> id >> firstName >> middleName >> lastName;

	p.set(id, firstName, middleName, lastName);

	return in;
}