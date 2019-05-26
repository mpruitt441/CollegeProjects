#include"queue.cpp"
#include <iostream>
using namespace std;
int main()
{
	Queue<int> s;

	s.enqueue(5);
	s.enqueue(34);
	s.enqueue(532);
	s.enqueue(432423);
	s.enqueue(432432);
	cout << "Removed: " << s.dequeue() << endl;

	while (s.empty() == false)
		cout << s.dequeue() << endl;

	system("pause");

}