#include<iostream>
#include<string>
using namespace std;
void del(string* s1,int b3 ,int num)
{
	s1->erase(b3, num);//�ӳ����ִ��ĵ�һ���ַ���ʼ��ɾ�����ִ���Ŀ��ͬ���ַ�����
	cout << *s1 << endl;
}
void judge(string * s1, string s2)
{
	int b = s1->length();
	int b2 = s2.length();
	int b_size = 0;
	int samesize = 0;
	int b3 = 0;
	int num = 0;
	while (b_size <= b)
	{
		if ((*s1)[b_size] == s2[0])
		{
			 b3 = b_size;
			for (int i = 0; i < s2.length();i++)
			{	if ((*s1)[b_size] != s2[i])
				{
					break;
				}
				if ((*s1)[b_size] == s2[i])
				{
					b_size++;
					samesize++;
				}
			
				if (samesize == s2.length())
				{
					cout << "����ȷʵ�����ִ�" << s2<<endl;
					del(s1, b3, samesize);//ÿ���ҵ���ͬ���ִ�������ִ�ɾ�����ǵ����������г�������ִ��Ĵ�����ֹһ��������Ҫ������Ѱ��һ�α�֤������û����֮һ�����ַ���
					b3 = 0;
					num = 1;
					b = s1->length();
					samesize = 0;
					b_size = 0;
					break;
				}
			}
		}
		if (num == 0)
		{
         b_size++;
		}
		if (num == 1)
		{
			num = 0;
		}
		
	}
	
}
int main() {
	string s1 = "ABCDABC";
	string s2 = "ABC";
	judge(&s1, s2);
	
	system("pause");
	return 0;
}