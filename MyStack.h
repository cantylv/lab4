#pragma once

template <class INF, class FRIEND>
class ListNode
{
private:
	INF d;
	ListNode* next;
	ListNode() : d{ 0 }, next (nullptr) {}
	friend FRIEND;
};

// конструктор копирвоания и оператор присваивания

template <class INF>
class MyStack
{
	typedef class ListNode <INF, MyStack<INF>> Node;
	Node* top;	
	static int Size;
public:
	MyStack();
	MyStack(INF);
	~MyStack();
	bool empty();
	bool push(INF);
	bool pop();
	bool sort_and_show();
	INF* top_inf();
	int size() const;
	void Multipliers(int, MyStack<INF>&);
	Node& operator = (const Node* obj)
	{
		if (this == top)
			top->d = obj.d;
		Node* current = top;
		while (current->next != this)
			current = current->next;
		current->next->d = obj->d;
	}
	MyStack(const Node* obj)
	{
		if (this == obj)
			return;
		else this = obj;
	}
};


template<class INF>
int MyStack<INF>::Size = 0;