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
	size_t size_;

public:

	List()
	{
		head = nullptr;
		size_ = 0;

	}

	~List()
	{
		clear();
		delete head;
	}

	List(const List<T>& list)
	{
		head = nullptr;
		size_ = 0;

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
		if(head!=nullptr) head->head = newNode;
		newNode->head = newNode;
		if (head != nullptr) newNode->tail = head;
		if(head!=nullptr) head->head = newNode;
		if (head == nullptr)
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
		size_ = 0;
		if (size_ != 0)
		{
			while (head != head->tail)
			{
				head = head->tail;
				delete head->head;
				head->head = head;
			}
		}
		delete head;
		head = nullptr;
	}

	void operator=(const List<T>& list)
	{
		clear();
		
		auto newNode = new Node;
		newNode = list.head;
		for (long long i = 0; i < list.size_; ++i)
		{
			push_front(newNode->value);
			newNode = newNode->tail;
		}
		reverse();
	}

	/*
	void operator=(const List<T>&& list)
	{
		clear();

		head = list.head;
		size_ = list.size_;
		
	}
	*/

	size_t size()
	{
		return size_;
	}

	void pop_front()
	{
		--size_;
		head = head->tail;
		delete head->head;
		head->head = head;
	}

	void resize(long long _size_)
	{
		if (_size_ > size_)
			while (size_ < _size_) push_front(0);
		else
		{
			clear();
			while (size_ < _size_) push_front(0);
		}
	}

	void remove(T x)
	{
		auto node = new Node;
		node = head;
		while (node != node->tail)
		{
			if (node->value == x)
			{
				--size_;
				if (node->head != node)
				{
					Node* d = node;
					node->head->tail = node->tail;
					node->tail->head = node->head;
					node = node->tail;
					delete d;
				}
				else
				{

					Node* d = node;
					node->tail->head = node->tail;
					node = node->tail;
					head = node;
					delete d;
				}
			}
			else node = node->tail;
		}
		if (node->value == x)
		{
			--size_;
			node->head->tail = node->head;
			delete node;
		}
		if (size_ == 0) clear();
	}

	T& front()
	{
		return head->value;
	}
};