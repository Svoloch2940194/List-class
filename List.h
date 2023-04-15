template<class T>

class List
{
	struct Node {
		Node* head;
		Node* tail;
		T value;
	};

	Node* head;
	Node* tail;
	size_t size_;

public:

	struct iterator
	{
		Node* id;
		size_t col_end;

		iterator(Node* x)
		{
			id = x;
			col_end = 0;
		}

		T operator*()
		{
			return id->value;
		}

		void operator=(Node* x)
		{
			id = x;
			col_end = 0;
		}

		bool operator==(iterator x)
		{
			return id == x;
		}

		bool operator!=(iterator x)
		{
			if (id == id->tail) col_end++;
			return id != x.id || col_end < 2;
		}

		void operator++()
		{
			id = id->tail;
		}

		void operator--()
		{
			id = id->head;
		}
	};

	List()
	{
		head = nullptr;
		tail = nullptr;
		size_ = 0;
	}

	List(const List<T>& list)
	{
		head = nullptr;
		tail = nullptr;
		size_ = 0;

		auto newNode = list.head;
		for (long long i = 0; i < list.size_; ++i)
		{
			push_front(newNode->value);
			newNode = newNode->tail;
		}
		reverse();
	}

	~List()
	{
		clear();
		delete head;
		delete tail;
	}

	void reverse()
	{
		auto node = head;
		for (long long i = 0; i < size_; ++i)
		{
			Node* x = node->head;
			node->head = node->tail;
			node->tail = x;
			if (i == 0) tail = node;
			node = node->head;
		}
		head = node;
	}

	void push_front(T val)
	{

		++size_;
		auto newNode = new Node;
		newNode->value = val;
		if (head != nullptr) head->head = newNode;
		newNode->head = newNode;
		if (head != nullptr) newNode->tail = head;
		if (head != nullptr) head->head = newNode;
		if (head == nullptr)
		{
			newNode->tail = newNode;
		}
		head = newNode;
		if (tail == nullptr) tail = head;
	}

	bool empty()
	{
		if (size_ == 0) return true;
		else return false;
	}

	void clear()
	{
		
		if (size_ != 0)
		{
			while (head != head->tail)
			{
				head = head->tail;
				delete head->head;
				head->head = head;
			}
		}
		size_ = 0;
		delete head;
		head = nullptr;
		tail = nullptr;
	}

	iterator begin()
	{
		iterator x = head;
		return x;
	}

	iterator end()
	{
		iterator x = tail;
		return x;
	}

	void operator=(const List<T>& list)
	{
		clear();
		auto newNode = list.head;
		for (long long i = 0; i < list.size_; ++i)
		{
			push_front(newNode->value);
			newNode = newNode->tail;
		}
		reverse();
	}



	void operator=(List<T>&& list)
	{
		size_t _size_ = size_;
		Node* node_head = head;
		Node* node_tail = tail;
		head = list.head;
		tail = list.tail;
		size_ = list.size_;
		list.size_ = _size_;
		list.head = node_head;
		list.tail = node_tail;
	}

	size_t size() const
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

	void resize(size_t _size_)
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
		auto node = head;
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
			tail = node->head;
			delete node;
		}
		if (size_ == 0) clear();
	}

	T& front()
	{
		return head->value;
	}
};

template<class T>

void swap(List<T>& list1, List<T>& list2)
{
	list1 = std::move(list2);
}