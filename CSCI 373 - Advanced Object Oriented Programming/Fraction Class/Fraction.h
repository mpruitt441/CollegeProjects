#ifndef FRACTION_H
#define FRACTION_H

using namespace std;

class fraction
{
public:
	int nume;
	int deno;
	fraction() { // default constructor
		cout << "Creating default value for fraction... " << endl;
		nume = 0;
		deno = 1;
	}
	fraction(int x, int y) { // initializer constructor
		cout << "Initializing fraction based on given values... " << endl;

		nume = x;
		deno = y;

	}
	fraction(const fraction &object) { // copy constructor
		cout << "Copying fraction object... " << endl;
		nume = object.nume;
		deno = object.deno;      
	}

	fraction& operator= (const fraction &f);// my compiler would not let me make this into a friend function	
	int gcd(int x, int y) {

		if (y == 0)
			return x;
		else
			return gcd(y, x%y);
		// Euclids algorithm, learned in mat 204 and in cryptography
	}
	void simplify() {
		int div = gcd(nume, deno);

		nume = nume / div;
		deno = deno / div;

		// simplifies the numerator and denominator, which are public values
	}
	// addition, subtraction, multiplication, division, and simplify
	void add(fraction a, fraction b) {
		cout << "Adding two fractions..." << endl;
		nume = (a.nume * b.deno) + (b.nume * a.deno);
		deno = (a.deno*b.deno);
		simplify();
		cout << "Result: " << nume << "/" << deno << endl;
	}
	void sub(fraction a, fraction b) { // same thing as addition, but with a - sign
		cout << "Subtracting two fractions..." << endl;
		nume = (a.nume * b.deno) - (b.nume * a.deno);
		deno = (a.deno*b.deno);
		simplify();
		cout << "Result: " << nume << "/" << deno << endl;
	}

	void mult(fraction a, fraction b) {
		cout << "Multiplying fractions..." << endl;
		nume = (a.nume*b.nume);
		deno = (a.deno*b.deno);
		simplify();

		cout << "Result: " << nume << "/" << deno << endl;
	}
	void div(fraction a, fraction b) {
		cout << "Dividing fractions..." << endl;
		nume = (a.nume * b.deno);
		deno = (a.deno * b.nume);
		simplify();

		cout << "Result: " << nume << "/" << deno << endl;

	}

};

fraction& fraction::operator= (const fraction &f)
{
	nume = f.nume;
	deno = f.deno;
	return *this;
}






#endif