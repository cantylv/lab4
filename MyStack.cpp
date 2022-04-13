#include "MyStack.h"
#include <iostream>
#include <cassert>


template<class INF>
inline MyStack<INF>::MyStack() : top(nullptr) {}

template<class INF>
MyStack<INF>::MyStack(INF num) : top(nullptr) { top->d = num; }

template<class INF>
inline MyStack<INF>::~MyStack()
{
	Node* current = top;
	while (top)
	{
		while (current->next)
			current = current->next;
		delete[] current;
		current = nullptr;
		current = top;
	}
}

template<class INF>
inline bool MyStack<INF>::empty()
{
	return top ? false : true;
}

template<class INF>
inline bool MyStack<INF>::push(INF n)
{
	if (empty())
	{
		top = new Node;
		top->d = n;
		top->next = nullptr;
	}
	else
	{
		Node* current = top;
		while (current->next)
			current = current->next;
		current->next = new Node;
		current->next->d = n;
		current->next->next = nullptr;
	}
	++Size;
	return true;
}

template<class INF>
inline bool MyStack<INF>::pop()
{
	if (!empty())
	{
		/*Node* current = top;
		int sizik = --Size;
		while (current->next)
			current = current->next;
		delete[] current;
		current = top;
		while (sizik)
		{
			current = current->next;
			sizik--;
		}
		current->d = 0;
		current->next = nullptr;
		return true;*/
		Node* current = top;
		while (top->next->next)
			top = top->next;
		delete[] top->next;
		top->next = nullptr;
		top = current;
		--Size;
	}
	return false;
}

template<class INF>
inline INF* MyStack<INF>::top_inf()
{
	assert(!empty() && "Ошибка доступа к элементу односвязного списка!");
	Node* current = top;
	while (current->next)
		current = current->next;
	return &current->d;
}

template<class INF>
bool MyStack<INF>::sort_and_show()
{
	bool sort_end = false;
	INF* arr = new INF[Size];
	Node* current = top;
	INF digit = 1;

	for (size_t i = 0; current; i++)
	{
		arr[i] = current->d;
		digit *= arr[i];
		current = current->next;
	}
	size_t min = 0;
	for (size_t i = 0; i < Size - 1; i++)
	{
		min = 0;
		for (size_t j = 1; j < Size - i; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (!(min == Size - i - 1))
			std::swap(arr[min], arr[Size - i - 1]);
	}
	std::cout << digit << " = ";

	for (size_t i = 0; i < Size; i++)
	{
		std::cout << arr[i] << " ";
		if (i < Size - 1)
			std::cout << "* ";
	}

	std::cout << std::endl << digit << " = ";

	for (int j = Size - 1;j >= 0; --j)
	{
		std::cout << arr[j] << "  ";
		if (j >= 1)
			std::cout << "* ";
	}
	std::cout << std::endl;
	return false;
}

template<class INF>
void MyStack<INF>::Multipliers(int digit, MyStack<INF>& stack)
{
	int	denom = 2;
	if (digit == 1)
		return;
	while (true)
	{
		if (!(digit % denom))
		{
			stack.push(denom);
			Multipliers(digit / denom, stack);
			return;
		}
		++denom;
	}
}

template<class INF>
int MyStack<INF>::size() const
{
	return Size;
}
