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
                cout << "ÓÒÀ¨ºÅ¶àÓÚ×óÀ¨ºÅ" << endl;
                return false;
            }
            if (*str == ')' && s.top() == '(')
            {
                s.pop();
                str++;
            }
            else
            {
                cout << "×óÓÒÀ¨ºÅ²»Æ¥Åä" << endl;
                return false;
            }
        }
    }
    if (!s.empty())
    {
        cout << "×óÀ¨ºÅ¶àÓÚÓÒÀ¨ºÅ" << endl;
        return false;
    }
    cout << "×óÓÒÀ¨ºÅÆ¥ÅäÕýÈ·" << endl;
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