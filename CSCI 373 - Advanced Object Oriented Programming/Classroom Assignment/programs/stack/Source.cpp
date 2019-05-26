#include"Stack.cpp"
#include <iostream>
using namespace std;
int main()
{
	Stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(432423);
	cout << "Top: " << s.top() << endl;

	
	while (s.empty() == false)
		cout << s.pop() << endl;


	system("pause");

}