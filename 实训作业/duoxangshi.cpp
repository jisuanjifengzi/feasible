#include <iostream>
#include<algorithm>
#include <iomanip>
#include<cmath>
using namespace std;
class Term {//多项式的每一项
	friend class Polynomial;
public:
	float coef;//系数
	int exp;//指数
};

class Polynomial {//多项式类
	friend ostream& operator<<(ostream& o, const Polynomial& poly);
public:
	Polynomial();
	Polynomial(const Polynomial& b);
	~Polynomial();
	Polynomial operator+(const Polynomial& b);
	Polynomial operator*(const Polynomial& b);
	Polynomial operator-(const Polynomial& b);
	Polynomial operator/(Polynomial& b);
	Polynomial weijifen();
	void dijifen();
	float operator()(float x);
	void NewTerm(float coef, int exp);
	int gett() { return terms; }
private:
	void insertTerm(const Term& term);
private:
	Term* termArray;
	int capacity;
	int terms;
};

Polynomial::Polynomial()
{
	this->terms = 0;
	this->capacity = 10;
	termArray = new Term[this->capacity];
}

Polynomial::Polynomial(const Polynomial& b)
{
	this->terms = 0;
	this->capacity = b.capacity;
	termArray = new Term[this->capacity];
	for (int i = 0;i < b.terms;i++)
	{
		NewTerm(b.termArray[i].coef, b.termArray[i].exp);
	}

}

Polynomial::~Polynomial()
{
	delete[] termArray;
}

Polynomial Polynomial::operator+(const Polynomial& b)
{
	Polynomial c;
	int aPos = 0;
	int bPos = 0;
	while (aPos < terms && bPos < b.terms) {
		if (termArray[aPos].exp == b.termArray[bPos].exp)//如果指数相等，则继续 
		{
			float coef = termArray[aPos].coef + b.termArray[bPos].coef;//系数相加
			if (coef)c.NewTerm(coef, termArray[aPos].exp);//系数不为0，则合并
			aPos++;bPos++;//继续
		}
		else if (termArray[bPos].exp < b.termArray[bPos].exp)// 指数小
		{
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);//合并
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	}
	while (aPos < terms) {
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
		aPos++;
	}
	while (bPos < b.terms) {
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
		bPos++;
	}
	return c;
}

Polynomial Polynomial::operator-(const Polynomial& b)
{
	Polynomial c;
	int aPos = 0;
	int bPos = 0;
	while (aPos < terms && bPos < b.terms) {
		if (termArray[aPos].exp == b.termArray[bPos].exp)//如果指数相等，则继续 
		{
			float coef = termArray[aPos].coef - b.termArray[bPos].coef;//系数相加
			if (coef)c.NewTerm(coef, termArray[aPos].exp);//系数不为0，则合并
			aPos++;bPos++;//继续
		}
		else if (termArray[bPos].exp < b.termArray[bPos].exp)// 指数小
		{
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);//合并
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	}
	while (aPos < terms) {
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
		aPos++;
	}
	while (bPos < b.terms) {
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
		bPos++;
	}
	return c;
}

Polynomial Polynomial::operator*(const Polynomial& b)
{
	Polynomial c;
	for (int i = 0; i < terms; i++) {
		for (int j = 0; j < b.terms; j++)
		{
			float coef = termArray[i].coef * b.termArray[j].coef;
			int exp = termArray[i].exp + b.termArray[j].exp;
			c.NewTerm(coef, exp);
		}
	}
	return c;
}


Polynomial Polynomial::operator/(Polynomial& b)
{
	Polynomial c;
	int t, p, l, n;
	Polynomial d, m, z;
	float o, g, f;
	n = terms - b.terms;
	for (int i = 0; i < terms; i++)
	{
		if (termArray[i].exp < termArray[i + 1].exp)
		{
			t = termArray[i].exp;
			termArray[i].exp = termArray[i + 1].exp;
			termArray[i + 1].exp = t;
			o = termArray[i].coef;
			termArray[i].coef = termArray[i + 1].coef;
			termArray[i + 1].coef = o;
		}
	}

	for (int i = 0; i < b.terms; i++)
	{
		if (b.termArray[i].exp < b.termArray[i + 1].exp)
		{
			p = b.termArray[i].exp;
			b.termArray[i].exp = b.termArray[i + 1].exp;
			b.termArray[i + 1].exp = p;
			g = b.termArray[i].coef;
			b.termArray[i].coef = b.termArray[i + 1].coef;
			b.termArray[i + 1].coef = g;
		}
	}

	for (int j = 0;j < n + 1;j++)
	{
		l = termArray[j].exp - b.termArray[0].exp;
		f = termArray[j].coef / b.termArray[0].coef;
		c.NewTerm(f, l);

		for (int i = 0;i < b.terms;i++)
		{
			m.termArray[i].coef = b.termArray[i].coef * f;
			d.termArray[i].exp = b.termArray[i].exp + l;
		}

		for (int i = 0;i < terms;i++)
		{
			termArray[i].coef -= m.termArray[i].coef;
			if (termArray[i].coef == 0)
				termArray[i].exp = 0;
		}
	}

	return c;

}
double root(double n, double p, double q, double r, double t)
{
	double f;
	f = (p * pow(n, 3) + q * pow(n, 2) + r * n + t) / (3 * p * pow(n, 2) + 2 * q * n + r);
	for (int i = 0; fabs(f) > 1e-5; f = (p * pow(n, 3) + q * pow(n, 2) + r * n + t) / (3 * p * pow(n, 2) + 2 * q * n + r), n -= f, i++);
	return n;
}

Polynomial Polynomial::weijifen() {
	Polynomial c;
	float coef;
	int exp;
	for (int i = 0;i < terms;i++)
	{
		if (termArray[i].exp != 0)
		{
			coef = termArray[i].coef * termArray[i].exp;
			exp = termArray[i].exp - 1;
			c.NewTerm(coef, exp);
		}
	}
	return c;
}

void Polynomial::dijifen()
{
	Polynomial d;
	float coef;
	int exp;
	double a, b, f = 0, g = 0, h;
	for (int i = 0;i < d.terms;i++)
	{
		coef = termArray[i].coef / (termArray[i].exp + 1);
		exp = termArray[i].exp + 1;
		d.NewTerm(coef, exp);
	}
	cout << "给定一个区间";
	cout << endl;
	cin >> a >> b;
	cout << "定积分如下结果：" << endl;
	for (int i = 0;i < terms;i++)
	{
		f += termArray[i].coef * pow(a, termArray[i].exp);
		g += termArray[i].coef * pow(b, termArray[i].exp);
	}
	if (a > b)
		h = f - g;
	else
		h = g - f;
	cout << h;
}


void Polynomial::NewTerm(float coef, int exp)
{
	if (terms == capacity) {
		capacity *= 2;
		Term* tmp = new Term[capacity];
		copy(termArray, termArray + terms, tmp);
		delete[] termArray;
		termArray = tmp;
	}
	Term ATerm;
	ATerm.coef = coef;ATerm.exp = exp;
	insertTerm(ATerm);
}
void Polynomial::insertTerm(const Term& term)//插入
{
	int i;
	for (i = 0; i < terms && term.exp < termArray[i].exp;i++) {
	}
	if (term.exp == termArray[i].exp) {
		termArray[i].coef += term.coef;
		if (!termArray[i].coef) {
			for (int j = i; j < terms - 1; j++)
				termArray[j] = termArray[j + 1];
			terms--;
		}
	}
	else {
		for (int j = terms - 1; j >= i;j--)
			termArray[j + 1] = termArray[j];
		termArray[i] = term;
		terms++;
	}
}

float Polynomial::operator()(float x)
{
	float res = 0.0;
	for (int i = 0;i < terms; i++) {
		res += termArray[i].coef * pow(x, termArray[i].exp);
	}
	return res;
}

ostream& operator<<(ostream& o, const Polynomial& poly)
{
	for (int i = 0;i < poly.terms - 1;i++) {
		o << poly.termArray[i].coef << "x^" << poly.termArray[i].exp << " + ";
	}
	o << poly.termArray[poly.terms - 1].coef << "x^" << poly.termArray[poly.terms - 1].exp;
	return o;
}



int main()
{
	Polynomial p1;
	p1.NewTerm(3, 8);
	p1.NewTerm(2, 6);
	p1.NewTerm(1, 3);
	p1.NewTerm(3, 4);
	Polynomial p2;
	p2.NewTerm(1, 2);
	p2.NewTerm(1, 3);
	p2.NewTerm(2, 1);
	cout << "****************欢迎使用一元多项式计算器************************" << endl;
	cout << "1.多项式的加法运算" << endl;
	cout << "2.多项式的减法运算" << endl;
	cout << "3.多项式的乘法运算" << endl;
	cout << "4.多项式的除法运算及求余" << endl;
	cout << "5求出特定的值的函数值" << endl;
	cout << "6.实现多项式的微分" << endl;
	cout << "7.实现多项式的积分" << endl;
	cout << "8.用牛顿迭代法计算附近的根" << endl;
	cout << "请选择你要进行的操作：" << endl;
	int n;
	cin >> n;
	if (n == 1) {
		cout << "(" << p1 << ") + (" << p2 << ") = " << p1 + p2 << endl;
	}
	if (n == 2)
	{
		cout << "(" << p1 << ") -(" << p2 << ") = " << p1 - p2 << endl;
	}
	if (n == 3) {
		cout << "(" << p1 << ") *(" << p2 << ") = " << p1 * p2 << endl;
	}
	if (n == 4)
	{
		cout << "(" << p1 << ") / (" << p2 << ") = ";
		cout << p1 / p2 << endl;
		cout << "余式为：";
		cout << p1;

	}
	if (n == 5) {
		float x;
		cout << "输入未知数的值" << endl;
		std::cin >> x;
		std::cout << "p1(x)=" << p1(x) << std::endl << "p2(x)=" << p2(x) << std::endl;
	}
	if (n == 6)
	{
		std::cout << "求多项式" << p1 << "的微分方程" << endl << "微分方程式为：" << p1.weijifen();
	}
	if (n == 7)
	{
		cout << "求多项式  " << p1 << "的定积分" << endl;
		p1.dijifen();
	}
	if (n == 8)
	{
		double x, a, b, c, d;
		cout << "输入要迭代的数： ";
		cin >> x;
		cout << "输入各项系数开始迭代：";
		cin >> a >> b >> c >> d;
		cout << setiosflags(ios::fixed) << setprecision(4);
		cout << "迭代结果为：" << root(x, a, b, c, d) << endl;
	}

}


