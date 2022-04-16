#include<iostream>
#include<string>
using namespace std;
void del(string* s1,int b3 ,int num)
{
	s1->erase(b3, num);//从出现字串的第一个字符开始，删除与字串数目相同的字符串。
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
					cout << "串中确实存在字串" << s2<<endl;
					del(s1, b3, samesize);//每次找到相同的字串后将这个字串删除后考虑到可能主串中出现这个字串的次数不止一次所以需要再重新寻找一次保证主串中没有与之一样的字符串
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