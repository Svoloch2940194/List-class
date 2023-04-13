#pragma once

template<class T>

class List
{
	struct Node {
		Node* head;
		Node* tail;
		T value;
	};

	Node* head;
	//Node* tail;
	size_t size_;

public:

	List()
	{
		auto newNode = new Node;
		newNode->head = newNode;
		newNode->tail = nullptr;
		head = newNode;
		size_ = 0;
	}

	List(const List<T>& list)
	{
		auto node = new Node;
		node->head = node;
		node->tail = nullptr;
		size_ = 0;
		head = node;

		auto newNode = new Node;
		newNode = list.head;
		for (long long i = 0; i < list.size_; ++i)
		{
			push_front(newNode->value);
			newNode = newNode->tail;
		}
		reverse();
	}

	void reverse()
	{
		auto node = new Node;
		node = head;
		for (long long i = 0; i < size_; ++i)
		{
			Node* x = node->head;
			node->head = node->tail;
			node->tail = x;
			node = node->head;
		}
		head = node;
	}

	void push_front(T val)
	{

		++size_;
		auto newNode = new Node;
		newNode->value = val;
		head->head = newNode;
		newNode->head = newNode;
		newNode->tail = head;
		head->head = newNode;
		if (head->tail == nullptr)
		{
			newNode->tail = newNode;
		}
		head = newNode;
	}

	bool empty()
	{
		if (size_ == 0) return true;
		else return false;
	}

	void clear()
	{
		while (head != head->tail)
		{
			head = head->tail;
			delete head->head;
			head->head = head;
		}
	}

	void operator=(const List<T>& list)
	{
		clear();

	}

	long long size()
	{
		return size_;
	}
};