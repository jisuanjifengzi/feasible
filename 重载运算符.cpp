#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class triangle
{public:
	float  border_1 = 0;
	float border_2 = 0;
	float border_3 = 0;
	float all = 0;

	triangle()
	{
	    border_1 = 0;
		border_2 = 0;
		border_3 = 0;
		all = 0;
	}
	triangle(triangle& b)
	{
		border_1 = b.border_1;
		border_2 = b.border_2;
		border_3 = b.border_3;
		all = b.all;
	}
	triangle(float a, float b, float c, float d)
	{
		border_1 =a;
		border_2 = b;
		border_3 =c;
		all = d;
	}

	triangle& operator+(const triangle& first)
	{
		triangle boom;
		boom.all = (this->border_1 + this->border_2 + this->border_3)/2;
		return boom;
	}
	friend triangle& operator-(const triangle& first, const triangle& second)
	{
		triangle t;
		t.border_1 = first.all - second.border_1;
		t.border_2 = first.all - second.border_2;
		t.border_3 = first.all - second.border_3;
		t.all = 0.0;
		return  t;
	}
	friend triangle& operator*(const triangle& first, const triangle& second)
	{
		triangle t;
		t.all = first.all * second.border_1 * second.border_2 * second.border_3;
		return  t;
	}

	friend istream& operator>>(istream& input, triangle& c)
	{
		cin >> c.border_1 >> c.border_2 >> c.border_3;
		return input;
	}
	friend ostream& operator<<(ostream& output,triangle &y)
	{
		output << sqrt(y.all);
		return output;
	}


};
int main()
{
	triangle c;
	cin >> c;
	triangle p = c+c;
	triangle p1 = p - c;
	triangle y = p * p1;
	cout << y;
}