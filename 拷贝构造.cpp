#include<iostream>
using namespace std;
class person
{
public:
	int m_age;
	int* m_height;
	person() {
		cout << "1" << endl;
	}//默认构造(无参的)
	person(int age,int height)
	{
		m_age = age;
		m_height=new int(height);
		cout << "2" << endl;
	
		
	}
	person(const person& p)
	{
		cout << "深拷贝" << endl;
		m_age = p.m_age;
		m_height = new int(*p.m_height);
	}
	~person() {
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
}
		cout << "3" << endl;
	}

};

void test(person p)
{
	cout << p.m_age <<*p.m_height<< endl;
	person p2(p);
	cout << p2.m_age <<*p2.m_height<< endl;;
}
int main()
{
	person p(18,100);
	test(p);
	system("pause");
	return 0;
}