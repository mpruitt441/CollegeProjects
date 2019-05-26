#include <iostream>
#include "Fraction.h"



int main() {
	int a, b;
	b = 0;

	while (b == 0)
	{
		cout << "Please enter the numerator for the first fraction:\n";
		cin >> a;
		cout << "Please enter the denominator for the first fraction:\n";
		cin >> b;

		if (b == 0) { // catch divide by 0
			cout << "\nCannot divide by 0!";
		}

	}
	fraction f1(a, b);
	b = 0;

	while (b == 0) {
		cout << "Please enter numerator for second fraction:\n";
		cin >> a;
		cout << "Please enter denominator for second fraction:\n";
		cin >> b;

		if (b == 0) { // catch divide by 0
			cout << "Cannot divide by 0!";
		}
	}
	fraction f2(a, b);

	fraction f3;
	fraction f4 = f2;
	fraction f5(f1);
	
	cout << "Created objects f1, f2, f3, f4, and f5" << endl
		<< "f1 and f2 are initializedt\n" << "f3 is default\n"
		<< "f4 is copied from f2\n" << "f5 is copy constructed from f1\n";

	cout << "Performing 4 operations: Addition, subtraction, multiplication, division\n";

	f3.add(f1, f2);
	f3.sub(f1, f2);
	f3.mult(f1, f2);
	f3.div(f1, f2);




	system("PAUSE");



	return 0;
}

