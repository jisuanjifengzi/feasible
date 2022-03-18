#include<iostream>
#include<assert.h>
#include<stack>
using namespace std;
bool judge(char ch)
{
	if(ch=='('||ch==')')
	{
		return true;
	}
	return false;
}
bool match(char* str)
{
    stack<char> s;
    assert(str);
    while (*str != '\0')
    {
        if (!judge(*str))
        {
            str++;
            continue;
        }
        if (*str == '(')
        {
            s.push(*str);
            str++;
        }
        else
        {
            if (s.empty())
            {
                cout << "�����Ŷ���������" << endl;
                return false;
            }
            if (*str == ')' && s.top() == '(')
            {
                s.pop();
                str++;
            }
            else
            {
                cout << "�������Ų�ƥ��" << endl;
                return false;
            }
        }
    }
    if (!s.empty())
    {
        cout << "�����Ŷ���������" << endl;
        return false;
    }
    cout << "��������ƥ����ȷ" << endl;
    return true;
}
int main() {
	char a[] = "((((ad))a";
	char b[] = "((a))d";
	char c[] = "(faf)))f";
	match(a);
	match(b);
	match(c);
}