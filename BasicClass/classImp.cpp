/*
@Lab: 1A
@Author: Casey Merritt
@Purpose: Demonstrate our understanding of polymorphism and inheritance :D
*/

#include "pch.h"
#include "currency.h"
#include <iostream>

currency::currency() {
	Whole = 0;
	Part = 0;
}

currency::~currency() {

}

int currency::getWhole() {
	return Whole;
}

int currency::getPart() {
	return Part;
}

void currency::setWhole(int x) {
	Whole = x;
}

void currency::setPart(int x) {
	Part = x;
}

std::string currency::getNoteName() {
	std::string x = "None tbh";
	return x;
}

std::string currency::getCoinName() {
	std::string x = "None tbh";
	return x;
}

currency currency::operator+(const currency& x) {
	currency temp;
	temp.Whole = x.Whole + this->Whole;
	temp.Part = x.Part + this->Part;
	if (temp.Part > 99) {
		temp.Whole = temp.Whole + (temp.Part / 100);
		temp.Part = temp.Part % (100 * (temp.Part / 100));
	}
	return temp;
}

currency currency::operator-(const currency& x) {
	currency temp;
	temp.Whole = this->Whole - x.Whole;
	temp.Part = this->Part - x.Part;
	while (temp.Part < 0 && temp.Whole > 0) {
		temp.Whole = temp.Whole - 1;
		temp.Part = 100 + temp.Part;
	}
	/*
	//used to keep values consistent below zero
	//not utilized since we are not allowing values below zero
	//wrote this before realizing that rip haha
	while (temp.Whole <= 0 && temp.Part < -99) {
		temp.Whole = temp.Whole - 1;
		temp.Part = 100 + temp.Part;
	}
	*/
	if (temp.Whole <= 0 && temp.Part < 0) {
		temp.Whole = 0;
		temp.Part = 0;
		std::cout << "Cannot go below zero, account balance set to zero" << std::endl;
	}
	return temp;
}

bool currency::operator>(const currency& x) {
	int a = ((this->Whole * 100) + this->Part);
	int b = ((x.Whole * 100) + x.Part);
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}

bool currency::operator<(const currency& x) {
	int a = ((this->Whole * 100) + this->Part);
	int b = ((x.Whole * 100) + x.Part);
	if (a < b) {
		return true;
	}
	else {
		return false;
	}
}

//currency one
std::ostream& operator<<(std::ostream& out, currency& x) {
	out << x.getNoteName() << " " << x.Whole << " " << x.Part << " " << x.getCoinName() << std::endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, Dollar& x) {
	out << x.noteName << " " << x.Whole << " " << x.Part << " " << x.coinName;
	return out;
}

std::ostream& operator<<(std::ostream& out, Pound& x) {
	out << x.noteName << " " << x.Whole << " " << x.Part << " " << x.coinName;
	return out;
}

std::ostream& operator<<(std::ostream& out, Yen& x) {
	out << x.noteName << " " << x.Whole << " " << x.Part << " " << x.coinName;
	return out;
}

std::ostream& operator<<(std::ostream& out, Rupee& x) {
	out << x.noteName << " " << x.Whole << " " << x.Part << " " << x.coinName;
	return out;
}

std::ostream& operator<<(std::ostream& out, Real& x) {
	out << x.noteName << " " << x.Whole << " " << x.Part << " " << x.coinName;
	return out;
}

//currency one
currency* operator>>(std::istream& in, currency* x) {
	std::string note, coin;
	int w, p;
	bool test = false;
	while (test == false) {//checking for valid formats here
		in >> note >> w >> p >> coin;
		if (note == "Dollar" || note == "dollar" || note == "Pound" || note == "pound" || note == "Rupee" || note == "rupee" || note == "Yen" || note == "yen" || note == "Real" || note == "real") {
			if ((w >= 0 || w <= 0) && (p >= 0 || p <= 0)) {
				test = true;
			}
		}
		else {
			std::cout << "Invalid Format Please Try Again: " << std::endl;
		}
	}
	if (note == "Dollar" || note == "dollar") {
		x = new Dollar(w, p);
	}
	else if (note == "Pound" || note == "pound") {
		x = new Pound(w, p);
	}
	else if (note == "Rupee" || note == "rupee") {
		x = new Rupee(w, p);
	}
	else if (note == "Real" || note == "real") {
		x = new Real(w, p);
	}
	else if (note == "Yen" || note == "yen") {
		x = new Yen(w, p);
	}
	return x;
}

std::istream& operator>>(std::istream& in, Dollar& x) {
	//need to add non correct input checker later
	//currently this isn't being used so not a big deal
	std::string nN;
	std::string cN;
	in >> nN >> x.Whole >> x.Part >> cN;
	x.setNoteName(nN);
	x.setCoinName(cN);
	return in;
}

std::istream& operator>>(std::istream& in, Pound& x) {
	//need to add non correct input checker later
	//currently this isn't being used so not a big deal
	std::string nN;
	std::string cN;
	in >> nN >> x.Whole >> x.Part >> cN;
	x.setNoteName(nN);
	x.setCoinName(cN);
	return in;
}

std::istream& operator>>(std::istream& in, Yen& x) {
	//need to add non correct input checker later
	//currently this isn't being used so not a big deal
	std::string nN;
	std::string cN;
	in >> nN >> x.Whole >> x.Part >> cN;
	x.setNoteName(nN);
	x.setCoinName(cN);
	return in;
}

std::istream& operator>>(std::istream& in, Rupee& x) {
	//need to add non correct input checker later
	//currently this isn't being used so not a big deal
	std::string nN;
	std::string cN;
	in >> nN >> x.Whole >> x.Part >> cN;
	x.setNoteName(nN);
	x.setCoinName(cN);
	return in;
}

std::istream& operator>>(std::istream& in, Real& x) {
	//need to add non correct input checker later
	//currently this isn't being used so not a big deal
	std::string nN;
	std::string cN;
	in >> nN >> x.Whole >> x.Part >> cN;
	x.setNoteName(nN);
	x.setCoinName(cN);
	return in;
}

Dollar::Dollar() {
	noteName = "Dollar";
	coinName = "cent";
}

Dollar::Dollar(int x, int y) {
	noteName = "Dollar";
	coinName = "cent";
	Whole = x;
	Part = y;
}

std::string Dollar::getNoteName() {
	return noteName;
}

std::string Dollar::getCoinName() {
	return coinName;
}

void Dollar::setNoteName(std::string x) {
	noteName = x;
}

void Dollar ::setCoinName(std::string x) {
	coinName = x;
}

Pound::Pound() {
	noteName = "Pound";
	coinName = "Pence";
}

Pound::Pound(int x, int y) {
	noteName = "Pound";
	coinName = "Pence";
	Whole = x;
	Part = y;
}

std::string Pound::getNoteName() {
	return noteName;
}

std::string Pound::getCoinName() {
	return coinName;
}

void Pound::setNoteName(std::string x) {
	noteName = x;
}

void Pound::setCoinName(std::string x) {
	coinName = x;
}

Yen::Yen() {
	noteName = "Yen";
	coinName = "Sen";
}

Yen::Yen(int x, int y) {
	noteName = "Yen";
	coinName = "Sen";
	Whole = x;
	Part = y;
}

std::string Yen::getNoteName() {
	return noteName;
}

std::string Yen::getCoinName() {
	return coinName;
}

void Yen::setNoteName(std::string x) {
	noteName = x;
}

void Yen::setCoinName(std::string x) {
	coinName = x;
}

Rupee::Rupee() {
	noteName = "Rupee";
	coinName = "Paise";
}

Rupee::Rupee(int x, int y) {
	noteName = "Rupee";
	coinName = "Paise";
	Whole = x;
	Part = y;
}

std::string Rupee::getNoteName() {
	return noteName;
}

std::string Rupee::getCoinName() {
	return coinName;
}

void Rupee::setNoteName(std::string x) {
	noteName = x;
}

void Rupee::setCoinName(std::string x) {
	coinName = x;
}

Real::Real() {
	noteName = "Real";
	coinName = "Centavo";
}

Real::Real(int x, int y) {
	noteName = "Real";
	coinName = "Centavo";
	Whole = x;
	Part = y;
}

std::string Real::getNoteName() {
	return noteName;
}

std::string Real::getCoinName() {
	return coinName;
}

void Real::setNoteName(std::string x) {
	noteName = x;
}

void Real::setCoinName(std::string x) {
	coinName = x;
}