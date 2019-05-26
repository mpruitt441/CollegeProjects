#include"SinglyLinkedList.cpp"



int main()
{
	SinglyLinkedList<int> s;

	s.insert(5);
	s.insert(43);
	s.insert(55);
	s.insert(1);
	s.insert(920);
	s.insert(32432);
	s.remove(920);
	s.print(std::cout);

	system("pause");

}