#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<stdio.h> 
#include<vector>
using namespace std;
inline int compare(string str1, string str2) //相等返回0，大于返回1，小于返回-1
{
    if (str1.size() > str2.size()) return 1; //长度长的整数大于长度小的整数
    else if (str1.size() < str2.size()) return -1;
    else                             
        return str1.compare(str2); //若长度相等，则头到尾按位比较
}
string ADD_INT(string str1, string str2);//加法声明
string SUB_INT(string str1, string str2);//减法声明
void DIVIDE_INT(string s1, string s2);//除法声明
void MOD_INT(string str1, string str2);//取余声明
string MUL_INT(string str1, string str2);//乘法声明

class HugeInt
{//定义长整形类
public:
    string shu;
    HugeInt();//默认构造
    HugeInt(string longnumber);
    HugeInt(HugeInt& str);//复制构造
    void change()//类型转换，将HugeInt类转换为char类
    {
        char str2[100];
        strcpy_s(str2, shu.c_str());
        cout << "转换为char类:";
        cout << str2<<endl;
        fstream f;
        f.open("file.txt", ios::out | ios::app);
        f << "HugeInt类：" << str2 << "已转为char类型" << endl;
        f.close();
  }
    HugeInt operator=(string& t1);
    friend ostream& operator<<(ostream& out, HugeInt& p);
    friend istream& operator>>(istream& in, HugeInt& p);
    HugeInt& operator++(int)//自加运算符重载
    {
       string number;
       HugeInt old(*this);
       cout << "自加多少次：";
        cin >> number;
        this->shu = ADD_INT(this->shu,number);
        cout << this->shu;
        return old;

    }
    HugeInt& operator--(int)//自减运算符重载
    {
        string number;
        HugeInt old(*this);
        cout << "自减多少次：";
        cin >> number;
        old.shu = SUB_INT(this->shu, number);
        cout << old.shu;
        return old;

    }
 void getwhile();
};

HugeInt::HugeInt()
{
    
}
HugeInt::HugeInt(string longnumber)
{
    shu = longnumber;
}
HugeInt::HugeInt(HugeInt& str)
{
    shu = str.shu;
}
void HugeInt::getwhile()
{
    
    cout <<"运算结果是：" << shu << endl;
}
void access(string b)//初次将数据写入文件中
{
    fstream foutput;
    foutput.open("file.txt", ios::out);//如果文件不存在。则会先生成该文件然后再进行录入操作。
    foutput << b << "\n" << endl;
    foutput.close();

}

void show()//根据需要将文件中所有数据输出展示
{
   
    ifstream infile;
    infile.open("file.txt", ios::in);
    char buf[1024];
    while (infile.getline(buf,sizeof(buf)))//按行输出
    {
        cout << buf << endl;
    }
}
void follow(string b)//追加写入
{
    fstream f;
    f.open("file.txt", ios::out | ios::app);
    f << b << endl;
    f.close();

}

void mathresult(string str1, string str2, int n)//输入到文件里面
{
    ofstream foutput("flie.txt");
    switch (n)//根据传进来的n值来判断二者的大小关系
    {
    case 0:
    {foutput << "输入成功：" << str1 << "is less than " << str2 << endl; }
    case 1:
    {foutput << "输入成功：" << str1 << "is more than " << str2 << endl; }
    case 2:
    {foutput << "输入成功：" << str1 << "=" << str2 << endl; }
    }
    foutput.close();
}

void mathresultfile(string str1,string str2,int n)//追加输入
{
    fstream f;
    f.open("file.txt", ios::out | ios::app);
        switch (n)
        {
        case 0:
        {f <<"输入成功："<< str1 << "is less than " << str2 << endl; }
        case 1:
        {f << "输入成功：" << str1 << "is more than " << str2 << endl; }
        case 2:
        {f<< "输入成功：" << str1 << "=" << str2 << endl; }
        }
        f.close();
}
int compare(int a[], int b[])//比较a、b，若a>b为1；若a<b为-1；若a=b为0
{
    int i;
    if (a[0] > b[0])
        return 1;
    if (a[0] < b[0])
        return -1;
    for (i = a[0]; i > 0; i--)//从高位到低位比较
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}

void jisuan(int a[], int b[])//计算a=a-b
{
    int flag;
    int i;

    flag = compare(a, b);
    if (flag == 0)//相等
    {
        a[0] = 0;
        return;
    }
    if (flag == 1)//大于
    {
        for (i = 1; i <= a[0]; i++)
        {
            if (a[i] < b[i])//若不够向上借位
            {
                a[i + 1]--;
                a[i] += 10;
            }
            a[i] -= b[i];
        }
        while (a[0] > 0 && a[a[0]] == 0)//删除前导0
            a[0]--;
        return;
    }
}

HugeInt operator+(HugeInt& t1, HugeInt& t2)//重载加号运算符
{
    return ADD_INT(t1.shu, t2.shu);
}

HugeInt operator-(HugeInt& t1, HugeInt& t2)//重载减号运算符
{
    return SUB_INT(t1.shu, t2.shu);
}

HugeInt operator*(HugeInt& t1, HugeInt& t2)//重载乘号运算符
{
    return MUL_INT(t1.shu, t2.shu);
}

HugeInt HugeInt::operator=(string& t1)//等于号的运算符重载
{
    shu = t1;
    return shu;
}

 ostream& operator<<(ostream& out, HugeInt& p)//输出运算符重载
{
     out << p.shu;
     return out;
}

 istream& operator>>(istream& in, HugeInt& p)//输入运算符重载
 {
     in >> p.shu;
     return in;
 }
string SUB_INT(string str1, string str2);

string ADD_INT(string str1, string str2) //加法的运算函数
{
    int sign = 1; //sign 为符号位
    string str = " ";

    if (str1[0] == '-') 
    {
        if (str2[0] == '-') //两个负数相加
        {
            sign = -1;
            str = ADD_INT(str1.erase(0, 1), str2.erase(0, 1));//去掉两个长整数的负号然后进行加法运算
        }
        else {
            str = SUB_INT(str2, str1.erase(0, 1));
        }
    }
    else
    {
        if (str2[0] == '-')
        {
            str = SUB_INT(str1, str2.erase(0, 1));
        }
        else//把两个整数对齐，短整数前面加0补齐
        { 
            string::size_type L1, L2;
            int i;
            L1 = str1.size();
            L2 = str2.size();
            if (L1 < L2)
            {
                for (i = 1; i <= L2 - L1; i++) str1 = "0" + str1;//在str1前面补零
            }
            else 
            {
                for (i = 1; i <= L1 - L2; i++) str2 = "0" + str2;
            }
            int int1 = 0, int2 = 0; //int2用于记录进位
            for (i = str1.size() - 1; i >= 0; i--) //从最后一个数开始加
            {
                int1 = (int(str1[i]) - '0' + int(str2[i]) - '0' + int2) % 10;//两个数相加
                int2 = (int(str1[i]) - '0' + int(str2[i]) - '0' + int2) / 10;//得1就进位
                str = char(int1 + '0') + str;
            }
            if (int2 != 0) str = char(int2 + '0') + str;
        }
    }
    //运算后处理符号位
    if ((sign == -1) && (str[0] != '0')) str = "-" + str;

    return str;
}

string SUB_INT(string str1, string str2)//减法的运算函数
{
    int sign = 1; //sign 为符号位
    string str;
    int i, j; 
    if(str1[0]!='-' && str2[0] != '-')//两个
    {
        int res = compare(str1, str2);//先比较两个数的长度大小
        if (res == 0) return "0";
        if (res < 0) 
        {
            sign = -1;
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        string::size_type tempint;
        tempint = str1.size() - str2.size();//把两个数的位数进行相减
        for (i = str2.size() - 1; i >= 0; i--) 
        {
            if (str1[i + tempint] < str2[i]) //相同位如果后者小于前者的情况
            {
                j = 1;
                while (1) 
                {
                    if (str1[i + tempint - j] == '0')//考虑到某一位如果是0的话进行减法则要像前一位借数 
                    {
                        str1[i + tempint - j] = '9';
                        j++;
                    }
                    else {
                        str1[i + tempint - j] = char(int(str1[i + tempint - j]) - 1);
                        break;
                    }
                }
                str = char(str1[i + tempint] - str2[i] + ':') + str;//按位进行一位数的减法运算
            }
            else {
                str = char(str1[i + tempint] - str2[i] + '0') + str;
            }
        }
        for (i = tempint - 1; i >= 0; i--) str = str1[i] + str;
    }
    if (str1[0] == '-' && str2[0] == '-')//考虑进行两个负数的减法
    {
        str = SUB_INT(str1.erase(0, 1), str2.erase(0, 1));
        sign = -1;
        cout << endl;
    }
    if (str2[0] == '-'&&str1[0]!='-')//下面两个都是两个长整数其中一个为负数的情况
    {
        str = ADD_INT(str1, str2.erase(0, 1));
    }
    if (str1[0] == '-'&&str2[0]!='0')
    {
        str = ADD_INT(str1.erase(0, 1), str2);
        sign = -1;
        cout << endl;
    }
   
    //去除结果中多余的前导0
    str.erase(0, str.find_first_not_of('0'));
    if (str.empty()) str = "0";
    if ((sign == -1) && (str[0] != '0')) str = "-" + str;
    return str;
}


string MUL_INT(string num1, string num2)//乘法的运算函数
{
    int len1 = num1.length(), len2 = num2.length();
    int len = len1 + len2 + 1;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    //tmp储存每次乘法的结果，res储存最后相加的结果
    //char res[len], tmp[len];
    char* res = new char[len];
    char* tmp = new char[len];
    for (int i = 0; i < len; i++)
    {
        res[i] = '0';
        tmp[i] = '0';
    }
    for (int i = 0; i < len1; i++)
    {
        //jinwei储存每次乘法的进位，r_jw储存最后相加的进位
        int jinwei = 0, r_jw = 0;
        for (int j = 0; j < len2; j++)
        {
            tmp[j] = ((num1[i] - '0') * (num2[j] - '0') + jinwei) % 10 + '0';//求的是这一位相乘进位之后剩下的数

            int res_temp = (res[j + i] - '0') + (tmp[j] - '0') + r_jw;
            
            res[j + i] = res_temp % 10 + '0'; //储存最终结果
            
            jinwei = ((num1[i] - '0') * (num2[j] - '0') + jinwei) / 10;//求的进位数是几，jw就等于几
            r_jw = res_temp / 10; //r_jw储存最后相加的进位
        }
        //如果最高位有进位
        if (r_jw != 0 || jinwei != 0)
        {
            res[len2 + i] = jinwei + r_jw + '0';		
        }
    }
    string result = "";
    bool flag = false;
    for (int i = len - 1; i >= 0; i--)
    {
        //遇到第一个正整数 
        if (res[i] != '0' && !flag) 
        {
            result += res[i];
            flag = true;
        }
        else if (flag)
            result += res[i];
    }
    if (result == "") result = "0";
    return result;
}

void DIVIDE_INT(string s1, string s2,int n)//除法的
{
    int a[100], b[100], c[100];
    char str1[100], str2[100];
    int i, j;
    memset(a, 0, sizeof(a));//三个整形数组初始化
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    strcpy_s(str1, s1.c_str());//c_str是返回的一个临时指针，再通过strcpy让str1接受这个指针使其得到s1的字符串
    strcpy_s(str2, s2.c_str());//同理
    a[0] = strlen(str1);
    b[0] = strlen(str2);
    for (i = 1; i <= a[0]; i++)
        a[i] = str1[a[0] - i] - '0';//将字符数组转变为int数组进行计算
    for (i = 1; i <= b[0]; i++)
        b[i] = str2[b[0] - i] - '0';
    int temp[100];
    c[0] = a[0] - b[0] + 1;
    for (i = c[0]; i > 0; i--)
    {
        memset(temp, 0, sizeof(temp));//赋初值
        for (j = 1; j <= b[0]; j++)
        {
            temp[j + i - 1] = b[j];
            temp[0] = b[0] + i - 1;
        }
        while (compare(a, temp) >= 0)
        {
            c[i]++;
            jisuan(a, temp);//把这一位改成能整除的
        }
    }
    while (c[0] > 0 && c[c[0]] == 0)
    {
        c[0]--;
    } 
    fstream f;//创立一个输入输出文件的对象
    if (n == 0)//如果是第一次打开
    {
        f.open("file.txt", ios::out);
    }
    if (n != 0)//如果本次进行的除法运算已经不是本程序启动后的第一次运算，那保存时候就进行追加写入
    {
        f.open("file.txt", ios::out | ios::app);
    }
    cout << "商为：";
    if (c[0] == 0)
    {
        f << "商为:";
        cout << 0 << endl;
        f << 0 << endl;
    }
    else
    {
        f << "商为:";
        for (i = c[0]; i > 0; i--)
        {
            cout << c[i];
            f << c[i] ;
        }
        cout << endl;
    }
    cout << "余数为:";
    if (a[0] == 0)//刚好除尽的情况
    {
       f << "余数为:";
        cout << 0 << endl;
        f << 0 << endl;
    }
    else
    {
        f << "余数为:";
        for (i = a[0]; i > 0; i--)
        {
            cout << a[i];
            f << a[i] ;
        }
        cout << endl;
        f << endl;
    }
    f.close();
}

void MOD_INT(string s1,string s2,int n)//取余，运用的计算方法与除法一样只是最后只需要输出余数即可
{
    int a[100], b[100], c[100];
    char str1[100], str2[100];
    int i, j;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    strcpy_s(str1, s1.c_str());
    strcpy_s(str2, s2.c_str());
    a[0] = strlen(str1);
    b[0] = strlen(str2);
    for (i = 1; i <= a[0]; i++)
        a[i] = str1[a[0] - i] - '0';
    for (i = 1; i <= b[0]; i++)
        b[i] = str2[b[0] - i] - '0';
    int temp[100];
    c[0] = a[0] - b[0] + 1;
    for (i = c[0]; i > 0; i--)
    {
        memset(temp, 0, sizeof(temp));
        for (j = 1; j <= b[0]; j++)
        {
            temp[j + i - 1] = b[j];
            temp[0] = b[0] + i - 1;
        }
        while (compare(a, temp) >= 0)
        {
            c[i]++;
            jisuan(a, temp);
        }
    }
    while (c[0] > 0 && c[c[0]] == 0)
    {
        c[0]--;
    }
    fstream f;
    if (n == 0)
    {
        f.open("file.txt", ios::out);
    }
    if (n != 0)
    {
        f.open("file.txt", ios::out | ios::app);
    }
    cout << "余数为:";
    if (a[0] == 0)
    {
        f << "余数为:";
        cout << 0 << endl;
        f << 0 << endl;
    }
    else
    {
        f << "余数为:";
        for (i = a[0]; i > 0; i--)
        {
            cout << a[i];
            f << a[i];
        }
        cout << endl;
    }
    f.close();
   
}

bool operator <(HugeInt const& lhs, HugeInt const& rhs)//比较前者是否小于后者
{
    int size1 = lhs.shu.length();
    int size2 = lhs.shu.length();
    if (size1 == size2)//在比较函数中，已经写了关于两者长度不等的情况，所以这里只讨论相等的情况
    {
        for (int i = 0; i < size1; i++)
        {
            if (lhs.shu[i] == rhs.shu[i])//如果这一位大小相等
            {
                continue;
            }
            if (lhs.shu[i] < rhs.shu[i])//小于就返回true
            {
                return true;
            }
            if(lhs.shu[i]>rhs.shu[i])//大于就返回false表示关系不成立
            {
                return false;
            }
            
        }
    }
}

bool operator >(HugeInt const& lhs, HugeInt const& rhs)//比较前者是否大于后者，其原理和小于号相同
{
    int size1 = lhs.shu.length();
    int size2 = lhs.shu.length();
    if (size1 == size2)
    {
        for (int i = 0; i < size1; i++)
        {
            if (lhs.shu[i] == rhs.shu[i])
            {
                continue;
            }
            if (lhs.shu[i] > rhs.shu[i])
            {
                return true;
            }
            if (lhs.shu[i] < rhs.shu[i])
            {
                return false;
            }
        }
    }
}

void menu()
{
 //菜单函数
    cout << "请选择你所使用的计算方式" << endl;
    cout << "1.加法" << endl;
    cout << "2.减法" << endl;
    cout << "3.乘法" << endl;
    cout << "4.除法" << endl;
    cout << "5.求余" << endl;
    cout << "6.结束" << endl;
}

int  contrast(string str1,string str2)//比较函数
{
   HugeInt t1(str1);
   HugeInt t2(str2);
   int result;//因为最后需要存在文件中，所以这里根据result的值来判断最后输入到文件中是什么关系
    system("cls");
    cout << "输入的两个数为:" << t1 << " " << str2 << endl;
    int size_int1 = t1.shu.length();
    int size_int2 = t2.shu.length();//可以正确表示输入的两个字符串长度
    cout << "二者关系运算结果是：" << endl;
    if(size_int1<size_int2)//根据长度直接判断
    {
        cout << "a is less than b" << endl;
        result = 0;
    }
    if (size_int1 > size_int2)
    {
        cout << "a is more than b" << endl;
        result = 1;
    }
    if (size_int1 ==size_int2)//二者相等情况
    {
        int n = 0;
        for (int i = 0; i < size_int1; i++)
        {
            if (t1.shu[i] == t2.shu[i])//如果相等就比较更低位
            {
                n++;//每相等一次就自加一次
            }
            else
            {
                break;
            }
         }
            if (n == size_int1)//如果最后每一位都相等，则二者相等
            {
                cout << "二者相等" << endl;
                result = 2;
            }
            else
            {
                 if (t1 < t2)//运用小于号运算符重载
                   {
                    cout << "a is less than b" << endl;
                    result = 0;
                    }
                 if(t1>t2)//运用大于号运算符重载
                   {
                    cout << "a is more than b" << endl;
                    result = 1; 
                    }
            }
           
       
       
    }
    return result;
}

void selfadd(int times)//自加函数
{
    
    string str1, str2;
    cout << "输入两数" << endl;
    cin >> str1 >> str2;
    HugeInt int1(str1);
    HugeInt int2(str2);
    cout << "1.自加第一个" << endl;//根据输入的值来判断是自加第几个
    cout << "2.自加第二个" << endl;
    string number;
    int a;
    cin >> a;
    if (a == 1)
    {
      int1.operator++(0);//自加运算符重载，由于是后置运算，所以需要在括号里面加一个数0
       cout << "是否选择将结果输入到文件中" << endl;
       cout << "1:输入结果" << endl;
       cout << "2.直接结束" << endl;
       cin >> a;
       if (a == 1)
       {
           if (times == 0)//表明这个本程序启动后进行的第一种计算
           {
               access(int1.shu);
               cout << "输入成功" << endl;
               show();
           }
           if(times!=0)//表明这个不是本程序启动后进行的第一种计算
           {
               follow(int1.shu);
               cout << "搞定" << endl;
           }
       }
       else
       {
           cout << "下次继续" << endl;
       }
    }
    if (a == 2)//原理同上
    {
        int2.operator++(0);
        cout << "是否选择将结果输入到文件中" << endl;
        cout << "1:输入结果" << endl;
        cout << "2.直接结束" << endl;
        cin >> a;
        if (a == 1)
        {
            if (times == 0)
            {
                access(int2.shu);
                cout << "输入成功" << endl;
                show();
            }
            else
            {
                follow(int2.shu);
                cout << "搞定" << endl;
            }
        }
        else
        {
            cout << "下次继续" << endl;
        }
    }
  

}

void selfsub(int times)//自减运算
{

    string str1, str2;
    cout << "输入两数" << endl;
    cin >> str1 >> str2;
    HugeInt int1(str1);
    HugeInt int2(str2);
    cout << "1.自减第一个" << endl;
    cout << "2.自减第二个" << endl;
    string number;
    int a;
    cin >> a;
    if (a == 1)
    {
        int1.operator--(0);//自减运算符重载，由于是后置运算，所以需要在括号里面加一个数0
        cout << "是否选择将结果输入到文件中" << endl;
        cout << "1:输入结果" << endl;
        cout << "2.直接结束" << endl;
        cin >> a;
        if (a == 1)
        {
            if (times == 0)//表明这个本程序启动后进行的第一种计算
            {
                access(int1.shu);
                cout << "输入成功" << endl;
                show();
            }
            if (times != 0)//表明这个不是本程序启动后进行的第一种计算
            {
                follow(int1.shu);
                cout << "搞定" << endl;
            }
        }
        else
        {
            cout << "下次继续" << endl;
        }
    }
    if (a == 2)//原理同上
    {
        int2.operator--(0);
        cout << "是否选择将结果输入到文件中" << endl;
        cout << "1:输入结果" << endl;
        cout << "2.直接结束" << endl;
        cin >> a;
        if (a == 1)
        {
            if (times == 0)
            {
                access(int2.shu);
                cout << "输入成功" << endl;
                show();
            }
            else
            {
                follow(int2.shu);
                cout << "搞定" << endl;
            }
        }
        else
        {
            cout << "下次继续" << endl;
        }
    }

}

int main()
{
    cout << "请选择你所要进行的功能" << endl;//先显示菜单
    cout << "1.查看数据" << endl;
    cout << "2.输入数据并计算" << endl;
    cout << "3.输入数据并比较" << endl;
    cout << "4.自加自减操作" << endl;
    cout << "5.长整形变为int类型数组" << endl;
    cout << "6.结束" << endl;
    int a;
    int n = 0;
    int times = 0;//记录运用的运算是本程序启动的第一次还是之后几次
    string s1, s2;
    string str1, str2;
    HugeInt  res;
    while (cin >> a)
    {
        system("cls");
        if (a == 6)//输入6结束程序
        {
            cout << "结束了" << endl;
            break;
        }
            
        switch (a)
        {
        case 1:
        {
            show();//查看文件中的数据
            break;
        }
        case 2:
        {
            menu();//计算菜单函数
            while (cin >> a)//挑选运算方式
            {
                if (a == 6)
                    break;
                char ch;
                system("cls");//清屏操作
                switch (a)
                {
                case 1:
                {
                    cout << "请输入两个长整数进行加法:";
                    HugeInt c1, c2;
                    cin >> c1 >> c2;//重载了输入运算符，使用可以直接输入长整数数据
                    res = c1 + c2;//加号和等于号重载了，所以可以这样写
                  
                    res.getwhile();//输出结果，判断是否正确
                    cout << "是否选择将结果输入到文件中" << endl;
                    cout << "1:输入结果" << endl;
                    cout << "2.直接结束" << endl;
                    cin >> a;
                    if (a == 1)
                    {
                        if (times == 0)//表明这是程序启动后的第一个运算
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out);//首次打开文件，因为是相对路径，如果没有则会自动创建一个与代码文件在同一个文件夹的空文件。
                            foutput << "加法运算结果为：" << endl;//输入
                            foutput.close();//关闭
                            access(res.shu);;//首次录入函数
                            cout << "输入成功" << endl;
                            show();
                            times++;
                        }
                        else
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out|ios::app);
                            foutput << "加法运算结果为：" << endl;
                            foutput.close();
                            follow(res.shu);//追加写入
                            cout << "搞定" << endl;
                            times++;
                        }
                    }
                    else
                    {
                        cout << "下次继续" << endl;
                    }
                    break;
                }

                case 2:
                {
                    cout << "请输入两个长整数进行减法:";
                    HugeInt c1, c2;
                    cin >> c1 >> c2;//重载了输入运算符，使用可以直接输入长整数数据
                    res = c1 - c2;//减号和等于号运算符重载了，所以可以直接这样写
                    res.getwhile();
                    cout << "是否选择将结果输入到文件中" << endl;
                    cout << "1:输入结果" << endl;
                    cout << "2.直接结束" << endl;
                    cin >> a;
                    if (a == 1)
                    {
                        if (times == 0)//原理和上述加法的录入相同
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out);
                            foutput << "减法运算结果为：" << endl;
                            foutput.close();
                            follow(res.shu);
                            cout << "输入成功" << endl;
                            show();
                        }
                        else
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out|ios::app);
                            foutput << "减法运算结果为：" << endl;
                            foutput.close();
                            follow(res.shu);
                            cout << "搞定" << endl;
                        }
                    }
                    else
                    {
                        cout << "下次继续" << endl;
                    }
                    break;
                }

                case 3:
                {
                    cout << "请输入两个长整数进行乘法:";
                    HugeInt c1, c2;
                    cin >> c1 >> c2;//重载了输入运算符，使用可以直接输入长整数数据
                    res = c1 * c2;//重载了等于号和乘号所以可以直接使用
                    res.getwhile();
                    cout << "是否选择将结果输入到文件中" << endl;
                    cout << "1:输入结果" << endl;
                    cout << "2.直接结束" << endl;
                    cin >> a;
                    if (a == 1)
                    {
                        if (times == 0)
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out);//首次打开文件，因为是相对路径，如果没有则会自动创建一个与代码文件在同一个文件夹的空文件。
                            foutput << "乘法运算结果为：" << endl;//输入
                            foutput.close();//关闭
                            access(res.shu);
                            cout << "输入成功" << endl;
                            show();
                        }
                        else
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out|ios::app);
                            foutput << "乘法运算结果为：" << endl;//输入
                            foutput.close();//关闭
                            follow(res.shu);
                            cout << "搞定" << endl;
                        }
                    }
                    else
                    {
                        cout << "下次继续" << endl;
                    }
                    break;
                }

                case 4:
                {cout << "请输入两个长整数进行除法:";
                    HugeInt c1, c2;
                    cin >> c1 >> c2;//重载了输入运算符，使用可以直接输入长整数数据
                    DIVIDE_INT(c1.shu, c2.shu,times);//将c1、c2的数据输送到除法函数中继续运算，并在这个函数中直接将结果输入到文件中
                    break;
                }

                case 5:
                {
                    cout << "请输入求余式子：";
                    cin >> s1 >> ch >> s2;//重载了输入运算符，使用可以直接输入长整数数据
                    cout << endl;
                    cout << "输入的两个数为：" << s1 << " " << s2 << endl;
                    HugeInt c1(s1);
                    HugeInt c2(s2);
                    MOD_INT(c1.shu, c2.shu,times);//将c1、c2的数据输送到求法函数中继续运算，并在这个函数中直接将结果输入到文件中
                    break;
                }
                case 6:
                    break;
                default:                   break;
                    times++;
                }
               
                cout << "请输入下一步" << endl;
                //system("cls");
                if (a == 6)
                {
                    break;
                }
                menu();
                times++;//每次运算后都会加一，之后循环如果没有结束，录入数据时均使用追加写入
            }
            break;
        }
        case 3:
        {    cout << "请输入你要进行关系运算的两个数" << endl;
        int b;
        cin >> str1 >> str2;
        n = contrast(str1, str2);//将最后比较的结果用n来保存，之后保存文件时会根据n的值来判断输入到文件中究竟是什么关系
        cout << "是否选择将结果输入到文件中" << endl;
        cout << "1:输入结果" << endl;
        cout << "2.直接结束" << endl;
        cin >> b;
        if (b == 1)
        {
            if (times == 0)
            {
                mathresult(str1, str2, n);//头次写入
            }
            else
            {
                mathresultfile(str1, str2, n);//追加写入
            }
        }
        else {
            cout << "结束" << endl; 
        }
        break;
        }
        case 4:
        {
            cout << "请选择执行自加操作还是自减操作" << endl;
            cout << "1.自加操作" << endl;
            cout << "2.自减操作" << endl;
            cin >> a;
            if (a == 1)
            {
                selfadd(times);
            }
            if (a == 2)
            {
                selfsub(times);
            }
            break;
        }
        case 5:
        {
        string t1;
        cout << "输入HugeInt类数据：";
        cin >> t1;
        HugeInt T1(t1);//带参数的构造函数给T1赋初值
        T1.change();//将长整形转变为char数组
        }
        times++;//每次运算后都会加一，之后循环如果没有结束，录入数据时均使用追加写入
        }
        cout << "请选择你所要进行的功能" << endl;
        cout << "1.查看数据" << endl;
        cout << "2.输入数据并计算" << endl;
        cout << "3.输入数据并比较" << endl;
        cout << "4.自加自减操作" << endl;
        cout << "5.长整形变为int类型数组" << endl;
        cout << "6.结束" << endl;
        cout << "输入6即可退出" << endl;
    } 
    return 0;
}

int b = 10;
const int& p = &b;
