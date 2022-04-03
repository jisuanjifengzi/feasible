#include <time.h>
#include<stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

char Precede(char p1, char p2)//�Ƚ���������������ȼ�
{
    int priority = 0;
    if (p1 == ')')
    {
        priority = 4;
    }
    if (p1 == '(')
    {
        priority = 3 ;
    }
    if (p1 == '*' || p1 == '/')
    {
        priority = 2;
    }
    if (p1 == '+' || p1 == '-')
    {
        priority = 1;
    }
  if(p1=='=')
  {
      priority = 0;
  }
    int priority1 = 0;
    if (p2 == ')')
    {
        priority1 = 4;
    }
    if (p2 == '(')
    {
        priority1 = 3;
    }
    if (p2 == '*' || p2 == '/')
    {
        priority1 = 2;

    }
    if (p2 == '+' || p2 == '-')
    {
        priority1 = 1;
    }
    if(p2=='=') {
        priority1 = 0;
    }
    if (priority < priority1)//����������ͬ�ıȽϷ���
    {

        return'<';
    }
    if (priority == priority1)
    {

        return'=';
    }
    if (priority > priority1)
    {

        return'>';
    }
}
void transform(string& str, string& str1) // C++ȡ����str������׺���ʽ��str1�洢��׺���ʽ
{
    stack<char> s;     //s�洢����������ȼ�
    int i = 0;
    s.push('=');
    while (i < str.size())
    {

        if (str[i] == '\0')//�����������ֱ�ӽ���
        {
            break;
        }
        if (str[i] >= '0' && str[i] <= '9')//���ֳ����˾������ηŵ�str�ַ�������
        {
            str1 += str[i];
            if (s.top() == '*' || s.top() == '/')//������ĳһ���˺Ż��߳������ָ����ȼ��ľ���������ִ�֮���ȼӸ���#���ټ��������
            {
                str1 += "#";
            }
            i++;
            continue;
        }

        else {//��֮��Ƚ�ջ���ַ����Ͷ�ȡ���ַ������ȼ������ջ������������ȼ��ͣ��ͰѶ�ȡ���ַ���ջ�����ȼ��ߵĻ���ջ�����ȳ�ջȻ���ٰѶ�ȡ���ַ��Ž�ȥ

            char top = s.top();//ջ����Ԫ��
            char b = str[i];//str�������
            char c = Precede(top, b);
            switch (c)
            {
            case'<': {
                if (b == ')')
                {
                    while (s.top() != '(')
                    {
                        str1 += s.top();
                        s.pop();
                    }
                    s.pop();
                    break;
                }
                s.push(str[i]); break; }
            case'=':
            {if (str[i] == '(' && top == ')')//����Ҫ��ֻ��������ջ���������Ϊ��/����chΪ������������ջ��һֱ��ջ��ջ����Ԫ���ǡ�������ʱ���ٰѡ�����ɾ��
            {
                s.pop();
                i++;
            }
            break;
            }
            case'>':
            {
                cout << "str�ķ���" << str[i] << endl;
                cout << "ջ���ķ���" << top << endl;
                if (s.top() == '(')
                {
                    s.push(str[i]);
                    break;
                }
                str1 += s.top();
                s.pop();
                s.push(str[i]);
                
                    break;
            }
            default:
                break;
            }

        }
        i++;
    }
    while (!s.empty()) // �����ʽѭ������ʱ��ջ�����Ԫ��ȫ����ջ
    {
        str1 += s.top();
        s.pop();
    }
}
void calculate(string& str, int size)
{

    stack<string>st;
    string mode;
    int num1 = 0;//num1�������һ����ջ��Ԫ�أ�num2��ڶ�����
    int num2 = 0;
    int i = 0;
    while (i < size)
    {
        if (str[i] == '\0')
        {
            cout << "�������!" << endl;
            break;
        }

        if (str[i] >= '0' && str[i] <= '9')
        {
            mode = str[i];//���ֶ��ȴ���ջ��
            st.push(mode);
            i++;
            continue;

        }

        if (str[i] == '+')
        {
            stringstream ss;
            string backnum = " ";
            string mode1 = st.top();
            st.pop();
            int  num1 = atoi(mode1.c_str());//string�����޷�ֱ�ӽ��мӼ����㣬����Ҫ��ת��int
            cout << "�ӷ���һ����ջ����" << num1 << endl;
            string mode2 = st.top();
            st.pop();
            int  num2 = atoi(mode2.c_str());
            cout << "�ӷ��ڶ�����ջ����" << num2 << endl;
            int all = num1 + num2;
            ss << all;
            ss >> backnum;//��Ϊջ����洢�Ķ���string���͵��ַ�����������Ҫ�����int���͵ļ�������ת���string����
            cout << "��ջԪ����" << backnum << endl;//��ջ��ǰ�����ó������м���֮���ٰ�����������ջ�У�֮����б������ʱ������������ջ����һλ�������㼴�ɡ�����ļ������������˼��
            st.push(backnum);
            i++;
            continue;
        }

        if (str[i] == '-')
        {
            stringstream ss;
            string backnum = " ";
            string mode1 = st.top();
            st.pop();
            int  num1 = atoi(mode1.c_str());
            cout << "������һ����ջ����" << num1 << endl;
            string mode2 = st.top();
            st.pop();
            int  num2 = atoi(mode2.c_str());
            cout << "�����ڶ�����ջ����" << num2 << endl;
            ss << (num2 - num1);
            ss >> backnum;
            cout << "��ջԪ����" << backnum << endl;
            st.push(backnum);
            i++;
            continue;
        }
        if (str[i] == '*')
        {
            stringstream ss;
            string backnum = " ";
            string mode1 = st.top();
            st.pop();
            int  num1 = atoi(mode1.c_str());
            cout << "�˷���һ����ջ����" << num1 << endl;
            string mode2 = st.top();
            st.pop();
            int  num2 = atoi(mode2.c_str());
            cout << "�˷��ڶ�����ջ����" << num2 << endl;
            ss << (num2 * num1);
            ss >> backnum;
            cout << "��ջԪ����" << backnum << endl;
            st.push(backnum);
            i++;
            continue;
        }
        if (str[i] == '/')
        {
            stringstream ss;
            string backnum = " ";
            string mode1 = st.top();
            st.pop();
            int  num1 = atoi(mode1.c_str());
            cout << "������һ����ջ����" << num1 << endl;
            string mode2 = st.top();
            st.pop();
            int  num2 = atoi(mode2.c_str());
            cout << "�����ڶ�����ջ����" << num2 << endl;
            if (num2 == 0)
            {
                cout << "�������󣬱�����Ϊ0�޷�����" << endl;//�����������������Ϊ0
                break;
            }
            ss << (num2 / num1);
            ss >> backnum;
            cout << "��ջԪ����" << backnum << endl;
            st.push(backnum);
            i++;
            continue;
        }

    }
    mode = st.top();
    st.pop();
    cout << "���ս���ǣ�" << mode;
}
int main()
{
    string exp;
    string postexp;
    postexp.clear();
    cout << "��ֵ���ʽ: " << endl;
    cin >> exp;
    cout << "�м���ʽ" << exp << endl;
    transform(exp, postexp);
    postexp = postexp.replace(postexp.size() - 1, 1, "");
    cout << "��׺���ʽ: " << postexp << endl;
    cout << "��׺���ʽ����Ϊ��" << postexp.length() << endl;
    while (postexp.find('#') != -1) //find����-1��ʾ�ַ������Ѿ��������ض��ַ�   
        postexp.erase(postexp.find('#'), 1);//Ĩȥ���ҵ�'#'λ�ô���һ��Ԫ�أ����鵽һ��'#'Ĩ��һ��'#'
    calculate(postexp, postexp.length());
    return 0;
}
//int prio(char op)                              //   ȷ�����ȼ����������һ�ּ򵥷���
//{
//    int priority = 0;
//    if (op == '*' || op == '/')
//        priority = 2;
//    if (op == '+' || op == '-')
//        priority = 1;
//    if (op == '(')
//        priority = 0;
//    return priority;
//}
//void Trans(string& str, string& str1)        //   C++ȡ����str������׺���ʽ��str1�洢��׺���ʽ
//{
//    stack<char> s;                          //   s�洢����������ȼ�
//    int i;
//    for (i = 0; i < str.size(); i++)
//    {
//        if (str[i] >= '0' && str[i] <= '9')
//        {
//            str1 += str[i];
//            //if (str[i + 1] < '0' || str[i + 1]>'9')      //    �����ֺ��ַ��ֿ�
//            //    str1 += ' ';
//        }
//        else
//        {
//            if (s.empty())                    //   sΪ�գ�ֱ��ѹջ
//                s.push(str[i]);
//            else if (str[i] == '(')             //   str[i]=='(',ֱ��ѹջ
//                s.push(str[i]);
//            else if (str[i] == ')')             //    str[i]==')',һֱ��ջ��ֱ������(���ٰѣ�������
//            {
//                while (s.top() != '(')
//                {
//                    str1 += s.top();
//                    s.pop();
//                }
//                s.pop();
//            }
//            else
//            {
//                while (prio(str[i]) <= prio(s.top()))     //    ��ջ��Ԫ�ص����ȼ���str[i]��ֱ�ӳ�ջ
//                {
//                    str1 += s.top();
//                    s.pop();
//                    if (s.empty())                    //   �ж�ջ�Ƿ�Ϊ��
//                        break;
//                }
//                s.push(str[i]);                     //    ����ѹջ
//            }
//        }
//    }
//    while (!s.empty())                              //     �����ʽѭ������ʱ��ջ�����Ԫ��ȫ����ջ
//    {
//        str1 += s.top();
//        s.pop();
//    }
//}
