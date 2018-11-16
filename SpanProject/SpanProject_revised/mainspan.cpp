#include <iostream>
#include "Stack.cpp"
#include <fstream>
#include <string>
using namespace std;

int *span(float x[], int n) {
	int *S = new int[n];
	Stack<int> s;
	for (int i = 0; i <= n - 1; ++i) {
		while (!s.empty() && x[s.top()] <= x[i]) {
			s.pop();
		}

		if (s.empty())
			S[i] = i + 1;
		else
			S[i] = i - s.top();

		s.push(i);
	}
	return S;
}

int main()
{
	//open and read in a file here
	ifstream mydata;
	mydata.open("goog.txt");
	ifstream dates;
	dates.open("date.txt");
	string line;
	string Y[255];
	float X[255] = { 0 };
	// read in the data to the array 
	for (int i = 0; i < 255; i++) {
		getline(mydata, line);
		cout << "The line is " << stof(line) << endl;
		X[i] = stof(line);
		cout << "X[i] is " << X[i] << endl;
	}
	line = "";
	for (int i = 0; i < 255; i++) {
		getline(dates, line);
		Y[i] = line;
	}

	int size = sizeof(X) / sizeof(float); // get SIZE of array by taking size of the array divided by integer or double
	int *Span; // pointer Span
	
	Span = span(X, size);
	for (int i = 0; i < size; ++i) {
		cout << "Span is: " << Span[i] << endl;
		if (Span[i] > 1 && Span[i - 1] == 1) {
			cout << "The price " << X[i] << " is a peak from day: " << Y[i] << endl;
		}
	}



	mydata.close();
	dates.close();
	system("pause");
	return 0;
}