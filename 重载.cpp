#include<iostream>
#include<string>
using namespace std;
class fenshu
{
public:
	int fenmu;
	int fenzi ;
	fenshu operator+(const fenshu& second)
	{
		int i = 0;
		if(this->fenmu>second.fenmu)
		{
			i = this->fenmu;
			for (i; i > 0; i++)
			{
				if (i % this->fenmu == 0 && i % second.fenmu == 0)
				{
					break;
				}
			}
		}
		else
		{
			i = second.fenmu;
			for (i; i > 0; i++)
			{
				if (i % this->fenmu == 0 && i % second.fenmu == 0)
				{
					break;
				}
			}
		}//�ҷ�ĸ��С������
		this->fenzi = this->fenzi * (i / this->fenmu);
		this->fenmu = i;
		int b_fenzi= second.fenzi * (i / second.fenmu);
		int b_fenmu= i;
		cout << this->fenmu << this->fenzi << endl;
		cout << b_fenmu << b_fenzi << endl;
		
		fenshu z;
		z.fenmu = i;
		z.fenzi = b_fenzi + this->fenzi;
		int b = 0;
		int zi = z.fenzi;
		int mu = z.fenmu;
		if (zi == 0)
		{
			z.fenmu = 1;
			mu = 1;
		}
		if (zi < 0)
			zi = -zi;
		if (mu < 0)
			mu = -mu;
		if (zi > mu)
		{
			b = mu;
			while (zi % mu != 0)
			{
				b = zi % mu;
				zi = mu;
				mu = b;
			}
		}
		else
		{
			b = zi;

			if (z.fenmu == 1)
			{
				b = 1;
			}
			if (zi != 0)
			{
				while (mu % zi != 0)
				{
					b = mu % zi;
					mu = zi;
					zi = b;
				}
			}
		}
		z.fenmu = z.fenmu / b;
		z.fenzi = z.fenzi / b;
		return z;
	}

};

int main()
{
	fenshu c1;
	fenshu c2;
	char c;
	cin >> c1.fenzi >> c >> c1.fenmu;
	cin >> c2.fenzi >> c >> c2.fenmu;
	fenshu c3= c1.operator+(c2);
	cout << c3.fenzi << "/" << c3.fenmu << endl;
	 
}