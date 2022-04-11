#include <time.h>
#include<stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
typedef char ElemType;
#define maxsize 20
typedef struct {
    ElemType data[maxsize];
    int top;
}stacknew;
void initstack(stacknew * &s)
{
    s = (stacknew*)malloc(sizeof(stacknew));
    s->top = -1;
   
}
//进栈（压栈）
void push(stacknew *& s, ElemType x)
{
   
        s->top++;
        s->data[s->top] = x;
    
}
void pop(stacknew*& s)
{
    if (s->top == -1)
    {
        cout << "栈中没有元素了" << endl;
    }
    s->top--;
}
char gettop(stacknew* s) {
    char b='0';
    if (s->top == -1) {
        return '=';
    }
    b = s->data[s->top];
    return b;
}
bool stackempty(stacknew* s) {
    if (s->top == -1) {
        return false;
    }
    else {
        return true;
    }
}
char Precede(char p1, char p2)//比较两个运算符的优先级
{
    int priority = 0;
    if (p1 == ')')
    {
        priority = 4;
    }
    if (p1 == '(')
    {
        priority = 3;
    }
    if (p1 == '*' || p1 == '/')
    {
        priority = 2;
    }
    if (p1 == '+' || p1 == '-')
    {
        priority = 1;
    }
    if (p1 == '=')
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
    if (p2 == '=') {
        priority1 = 0;
    }
    if (priority < priority1)//按情况输出不同的比较符号
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
void transform(string& str, string& str1) // C++取引用str接受中缀表达式，str1存储后缀表达式
{
    char e='0';
    stacknew  *s;     //s存储运算符的优先级
    int i = 0;
    initstack(s);
    push(s, '=');
    while (i < str.size())
    {

        if (str[i] == '\0')//如果到了最后就直接结束
        {
            break;
        }
        if (str[i] >= '0' && str[i] <= '9')//数字出现了就先依次放到str字符串里面
        {
            str1 += str[i];
      
            if (gettop(s) == '*' ||e == '/')//出现了某一个乘号或者除号这种高优先级的就在这个数字串之后先加个“#”再加运算符。
            {
                str1 += "#";
            }
            i++;
            continue;
        }

        else {//这之后比较栈顶字符串和读取的字符的优先级，如果栈顶的运算符优先级低，就把读取的字符进栈，优先级高的话就栈顶的先出栈然后再把读取的字符放进去
        
       
          
            char top = gettop(s);//栈顶的元素
            char b = str[i];//str的运算符
            char c = Precede(top, b);
            switch (c)
            {
            case'<': {
                if (b == ')')
                {
                 
                    char e2 = '0';
                    
                    while (gettop(s) != '(')
                    {
                        str1 += gettop(s);
                        pop(s);
                    }
                    pop(s);
                    break;
                }
                push(s, str[i]); break; }
            case'=':
            {if (str[i] == '(' && top == ')')//这里要求只有满足了栈顶运算符为‘/’，ch为‘）’才能退栈，一直退栈到栈顶的元素是‘（’的时候再把‘（’删掉
            {
                pop(s);
                i++;
            }
            break;
            }
            case'>':
            {
                cout << "str的符号" << str[i] << endl;
                cout << "栈顶的符号" << top << endl;
             
                if (gettop(s) == '(')
                {
                    push(s, str[i]);
                   
                    break;
                }
                str1 += gettop(s);
                pop(s);
                push(s, str[i]);
             

                break;
            }
            default:
                break;
            }

        }
        i++;
    }
    while (stackempty(s)) // 当表达式循环结束时，栈里面的元素全部出栈
    {
      
       
        str1 += gettop(s);
        pop(s);
    }
}
void calculate(string& str, int size)
{

    stack<string>st;
    string mode;
    int num1 = 0;//num1用来存第一个出栈的元素，num2存第二个。
    int num2 = 0;
    int i = 0;
    while (i < size)
    {
        if (str[i] == '\0')
        {
            cout << "计算结束!" << endl;
            break;
        }

        if (str[i] >= '0' && str[i] <= '9')
        {
            mode = str[i];//数字都先存入栈中
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
            int  num1 = atoi(mode1.c_str());//string类型无法直接进行加减运算，所以要再转成int
            cout << "加法第一个出栈的是" << num1 << endl;
            string mode2 = st.top();
            st.pop();
            int  num2 = atoi(mode2.c_str());
            cout << "加法第二个出栈的是" << num2 << endl;
            int all = num1 + num2;
            ss << all;
            ss >> backnum;//因为栈里面存储的都是string类型的字符，所以我们要将这个int类型的计算结果再转变成string类型
            cout << "进栈元素是" << backnum << endl;//将栈的前两个拿出来进行计算之后再把这个结果存入栈中，之后进行别的运算时就用这个结果和栈的下一位继续计算即可。下面的计算均采用这种思想
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
            cout << "减法第一个出栈的是" << num1 << endl;
            string mode2 = st.top();
            st.pop();
            int  num2 = atoi(mode2.c_str());
            cout << "减法第二个出栈的是" << num2 << endl;
            ss << (num2 - num1);
            ss >> backnum;
            cout << "进栈元素是" << backnum << endl;
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
            cout << "乘法第一个出栈的是" << num1 << endl;
            string mode2 = st.top();
            st.pop();
            int  num2 = atoi(mode2.c_str());
            cout << "乘法第二个出栈的是" << num2 << endl;
            ss << (num2 * num1);
            ss >> backnum;
            cout << "进栈元素是" << backnum << endl;
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
            cout << "除法第一个出栈的是" << num1 << endl;
            string mode2 = st.top();
            st.pop();
            int  num2 = atoi(mode2.c_str());
            cout << "除法第二个出栈的是" << num2 << endl;
            if (num2 == 0)
            {
                cout << "计算有误，被除数为0无法计算" << endl;//考虑特殊情况被除数为0
                break;
            }
            ss << (num2 / num1);
            ss >> backnum;
            cout << "进栈元素是" << backnum << endl;
            st.push(backnum);
            i++;
            continue;
        }

    }
    mode = st.top();
    st.pop();
    cout << "最终结果是：" << mode;
}
int main()
{
    string exp;
    string postexp;
    postexp.clear();
    cout << "中值表达式: " << endl;
    cin >> exp;
    cout << "中间表达式" << exp << endl;
    transform(exp, postexp);
    postexp = postexp.replace(postexp.size() - 1, 1, "");
    cout << "后缀表达式: " << postexp << endl;
    cout << "后缀表达式长度为：" << postexp.length() << endl;
    while (postexp.find('#') != -1) //find返回-1表示字符串中已经不存在特定字符   
        postexp.erase(postexp.find('#'), 1);//抹去查找到'#'位置处的一个元素，即查到一个'#'抹除一个'#'
    calculate(postexp, postexp.length());
    return 0;
}
