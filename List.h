#pragma once

template<class T>

class List
{
	struct Node {
		Node* head;
		Node* tail;
		T value;
	};

	Node head;

public:

	List()
	{
		auto newNode = new Node;
		newNode->head = newNode;
		newNode->tail = nullptr;
		head = *newNode;
	}

	List(const List<T>& list)
	{
		if (list != list.head.tail) List(list.head.tail);
		push_front(list.head.value);
	}

	void push_front(T val)
	{

		if (head.tail != nullptr)
		{
			auto newNode = new Node;
			auto oldNode = new Node;
			oldNode = head.head;
			newNode->value = val;
			head.head = newNode;
			newNode->head = newNode;
			newNode->tail = oldNode;
			head = *newNode;
		}
		else
		{
			auto newNode = new Node;
			newNode->value = val;
			head.head = newNode;
			newNode->head = newNode;
			newNode->tail = newNode;
			head = *newNode;
		}
	}

	
};