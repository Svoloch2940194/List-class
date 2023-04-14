#include<iostream>
#include<string>
#include "List.h"

int main()
{
	List<long long> A;
	List<std::string> B;

	A.push_front(1);
	std::cout << A.size() << std::endl;
	A.push_front(2);
	std::cout << A.size() << std::endl;
	A.push_front(3);
	std::cout << A.size() << std::endl;
	A.push_front(4);
	std::cout << A.size() << std::endl;

	List<long long> A1(A);

	for (auto i = A1.begin(); i != A1.end(); ++i)
	{

	}


	A.remove(2);

	A.clear();

}