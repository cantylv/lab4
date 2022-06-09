#pragma once

#include <iostream>
#include <list>
#include <iterator>
#include <atlcoll.h>

#define ELEMENT_COUNT 3
#define CHILD_CLASS 3
#define DELETE_ELEMENT 5


 // унаследовать от класса CObject не вышло
class Abstr
{
protected:
	double dPar;
public:
	Abstr(double p) : dPar(++p) {}
	Abstr() : dPar(0) {}
	virtual ~Abstr() { std::cout << "Destructor Abstr" << std::endl; }
	virtual void Print() = 0;
};

class Deriv1 : public Abstr
{
protected:
	double dDPar;
public:
	Deriv1(int p) :Abstr(p + 5), dDPar(p - 5) {}
	Deriv1() : dDPar(1) {}
	virtual ~Deriv1() { std::cout << "Destructor Deriv1" << std::endl; }
	virtual void Print() override
	{
		std::cout << "Deriv1 = " << dDPar << " Abstr = " << dPar << std::endl;;
	}
};

class Deriv2 :public Deriv1
{
protected:
	double dDPar;
public:
	Deriv2(int p) :Deriv1(p*2), dDPar(p/20) {}
	Deriv2() : dDPar(2) {}
	virtual ~Deriv2() { std::cout << "Destructor Deriv2" << std::endl; }
	virtual void Print() override
	{
		std::cout << "Deriv2 = " << dDPar << " Abstr = " << dPar << std::endl;;
	}
};

class Deriv3 : public Deriv1
{
protected:
	double dDPar;
public:
	Deriv3(int p) : Deriv1(p+0.5), dDPar(p-0.5) {}
	Deriv3() : dDPar(3) {}
	virtual ~Deriv3() { std::cout << "Destructor Deriv3" << std::endl; }
	virtual void Print() override
	{
		std::cout << "Deriv3 = " << dDPar << " Abstr = " << dPar << std::endl;;
	}
};




// Базовый класс 
class Bas {
public:
	Bas() { a = 0; ClassType = 0; }; // Конструктор 1
	Bas(int x) { a = x; ClassType = 0; }; // Конструктор 2 
	int a;
	int ClassType;
};
// Производный класс 1
class Type1 : public Bas {
public:
	Type1() { Coord = 0; ClassType = 1; }; // Конструктор 1
	Type1(int x) { Coord = x; ClassType = 1; }; // Конструктор 2
	void Move(int Delta) { Coord += Delta; }; // Метод для динамического вызова "+" 
	int Coord;
};
// Производный класс 2
class Type2 : public Bas {
public:
	Type2() { Coord = 0; ClassType = 2; }; // Конструктор 1
	Type2(int x) { Coord = x; ClassType = 2; }; // Конструктор 2
	void Move(int Delta) { Coord -= Delta; }; // Метод для динамического вызова  "-"
	int Coord;
};
////////////////



class U
{
public:
	double solution;
	U(double num = 0) :solution(num) { std::cout << "constructor U\t solution = " << solution << std::endl; }
	virtual ~U() { std::cout << "destructor U\n"; }
	virtual void Print() = 0;
};

class X : virtual public U
{
	double x_m;
public:
	X(double num = 0) :x_m(num), U(num - 100) { std::cout << "constructor X\t x_m = " << x_m << std::endl; }
	virtual ~X() { std::cout << "destructor X\n"; }
	virtual void Print()
	{
		std::cout << "function Print()\t class X\n";
	}
};

class Y : virtual public U
{
	double y_m;
public:
	Y(double num = 0) : y_m(num), U(num + 100) { std::cout << "constructor Y\t y_m = " << y_m << std::endl; }
	virtual ~Y() { std::cout << "destructor Y\n"; }
	virtual void Print()
	{
		std::cout << "function Print()\t class Y\n";
	}
};

class Z :  public X, public Y
{
	double z_m;
public:
	Z(double num = 2.72) : z_m(num), X(num), Y(num)	 /*U(num + 9.5)*/ { std::cout << "constructor Z\t z_m = " << z_m << std::endl; }
	virtual ~Z() { std::cout << "destructor Z\n"; }
	virtual void Print()
	{
		std::cout << "function Print()\t class Z\n";
	}
};

void PrintList(const std::list<Abstr*>& ListDer)
{
	for (auto iter : ListDer)
		(*iter).Print();
}
