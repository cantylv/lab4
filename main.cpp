// Lab7, lobanov Ivan, BMSTU, IU5 - 23B

#include "class.h"

int main()
{
	system("chcp 1251");
	
	////4.3

	//// Ручная виртуализация
	//Bas* pObj;
	//Type1 T1(10);
	//Type2 T2(20);
	//// Задание значения указателя для Т1 
	//pObj = &T1;
	//std::cout << "T1 = " << T1.Coord << " T2 = " << T2.Coord << std::endl;
	////При  pObj->Move(); Ошибка, так как указатель па базовый класс, а так Move нет!
	//switch (pObj->ClassType)
	//{
	//case 1:
	//	((Type1*)pObj)->Move(5); break; // Типизация указателя для Type1 (Type1 *)pObj
	//case 2:
	//	((Type2*)pObj)->Move(5); break; // Типизация указателя для Type2(Type2*)pObj
	//};
	//std::cout << "T1 = " << T1.Coord << " T2 = " << T2.Coord << std::endl;
	//// Задание значения указателя для Т2 
	//pObj = &T2;
	//switch (pObj->ClassType)
	//{
	//case 1:
	//	((Type1*)pObj)->Move(5); break;
	//case 2:
	//	((Type2*)pObj)->Move(5); break;
	//};
	//std::cout << "T1 = " << T1.Coord << " T2 = " << T2.Coord << std::endl;


	// 4.4 - 4.10
	int index = 0;
	Abstr* ptr;
	Deriv1  d1(33);
	Deriv2  d2(44);
	Deriv3  d3(66);

	std::cout << "Here works function Print() through object:\n";
	d1.Print();
	d2.Print();
	d3.Print();
	std::cout << "But now we will check function Print() through pointer of its classes:\n";
	{
		Deriv1* p1 = &d1;
		p1->Print();
		Deriv2* p2 = &d2;
		p2->Print();
		Deriv3* p3 = &d3;
		p3->Print();
	}
	std::cout << "Here we will check function Print() through pointer of basic class:\n";
	ptr = &d1;
	ptr->Print();
	ptr = &d2;
	ptr->Print();
	ptr = &d3;
	ptr->Print();
	
	// 4.11 - 4.15

	std::list<Abstr*> ListDer;
	for (size_t i = 0; i < ELEMENT_COUNT; i++)
		ListDer.push_front(new Deriv1);
	for (size_t i = 0; i < ELEMENT_COUNT; i++)
		ListDer.push_front(new Deriv2);
	for (size_t i = 0; i < ELEMENT_COUNT; i++)
		ListDer.push_front(new Deriv3);


	for (auto iter : ListDer)
		(*iter).Print();
	std::cout << "\n\n";

	for (auto iter = ListDer.begin(); iter != ListDer.end(); iter++, index++)
	{
		if (index == DELETE_ELEMENT)
		{
			ListDer.erase(iter);
			break;
		}
	}
	PrintList(ListDer);  // функция, печатающая список
    // 4.16

	Z num1(2);
	Y num2(4);
	X num3(6);
	std::cout << "\nHere I try to check value of U's variable:\n";
	std::cout << "num1.solution = " << num1.solution << std::endl;
	std::cout << "num1.X::solution = " << num1.X::solution << std::endl;
	std::cout << "num1.Y::solution = " << num1.Y::solution << std::endl;

	std::cout << "num2.solution = " << num2.solution << std::endl;
	std::cout << "num2.Y::solution = " << num2.Y::solution << std::endl;

	std::cout << "num3.solution = " << num3.solution << std::endl;
	std::cout << "num3.X::solution = " << num3.X::solution << std::endl;
	
}