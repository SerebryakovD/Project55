#include<iostream>
#include<string>

using namespace std;
// Дробь
// - целые числа
// - методы для +-*/
// - конструктор по умолчанию - вернрет 1/1
// - вывод дроби

class Fraction {
	long int num;
	long int denum;
public:
	Fraction() { num = 1; denum = 1; };
	Fraction(int _num) {
		num = _num;
		denum = 1;
	}
	Fraction(int _num, int _denum): num(_num), denum(_denum) {};

	Fraction operator + (Fraction& right) {
		Fraction fr(
			this->num * right.denum + right.getNum() * this->denum,
			this->denum * right.denum
		);
		return fr;
	}

	Fraction operator - (Fraction& right) {
		Fraction fr(
			this->num * right.denum - this->denum * right.getNum(),
			this->denum * right.denum
		);
		return fr;
	}

	Fraction operator ++ () {
		cout << "Prefix" << endl;
		this->num += this->denum;
		return * this;
	}

	Fraction operator ++ (int) {
		cout << "Postfix" << endl;
		Fraction old = * this;
		this->num += this->denum;
		return old;
	}

	void show() {
		cout << this->num << endl;
		cout << "---" << endl;
		cout << this->denum << endl << endl;
	}

	int getNum() { return this->num; }
	int getDenum() { return this->denum; }
};

int main() {
	Fraction fr1(8, 3);
	Fraction fr2(6, 2);
	Fraction fr3 = fr1 + fr2;

	fr1.show();
	fr2.show();
	cout << endl << endl;
	fr3.show();
	fr3++;
	fr3.show();
	++fr3;
	fr3.show();
}