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
	long long size_;

public:

public:

	List()
	{
		auto newNode = new Node;
		newNode->head = newNode;
		newNode->tail = nullptr;
		head = *newNode;
		size_ = 0;
	}

	List(const List<T>& list)
	{
		size_ = 0;
		Node newNode = list.head;

		for (long long i = 0; i < list.size_; ++i)
		{
			push_front(newNode.value);
			newNode = *newNode.tail;
		}
		//reverse();
	}
	/*
	void reverse()
	{

		for (long long i = 0; i < size; ++i)
		{
			
		}
	}
	*/

	void push_front(T val)
	{
		++size_;
		auto newNode = new Node;
		newNode->value = val;
		head.head = newNode;
		newNode->head = newNode;
		newNode->tail = newNode;
		if (head.tail != nullptr)
		{
			auto oldNode = new Node;
			*oldNode = head;
			oldNode->head = newNode;
			newNode->tail = oldNode;
		}

		head = *newNode;
	}

	long long size()
	{
		return size_;
	}
};