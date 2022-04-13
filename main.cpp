#include "MyStack.h"
#include "MyStack.cpp"
#include <vector>
//
//void Multi(int digit, std::vector<int>& stack)
//{
//	int	denom = 2;
//	if (digit == 1)
//		return;
//	while (true)
//	{
//		if (!(digit % denom))
//		{
//			stack.push_back(denom);
//			Multi(digit / denom, stack);
//			return;
//		}
//		++denom;
//	}
//}


int main()
{
	system("chcp 1251");
	MyStack<int> obj;
	obj.Multipliers(94, obj);
	obj.sort_and_show();
	   
	return 0;
}