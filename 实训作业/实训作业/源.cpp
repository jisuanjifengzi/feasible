#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<stdio.h> 
#include<vector>
using namespace std;
inline int compare(string str1, string str2) //��ȷ���0�����ڷ���1��С�ڷ���-1
{
    if (str1.size() > str2.size()) return 1; //���ȳ����������ڳ���С������
    else if (str1.size() < str2.size()) return -1;
    else                             
        return str1.compare(str2); //��������ȣ���ͷ��β��λ�Ƚ�
}
string ADD_INT(string str1, string str2);//�ӷ�����
string SUB_INT(string str1, string str2);//��������
void DIVIDE_INT(string s1, string s2);//��������
void MOD_INT(string str1, string str2);//ȡ������
string MUL_INT(string str1, string str2);//�˷�����

class HugeInt
{//���峤������
public:
    string shu;
    HugeInt();//Ĭ�Ϲ���
    HugeInt(string longnumber);
    HugeInt(HugeInt& str);//���ƹ���
    void change()//����ת������HugeInt��ת��Ϊchar��
    {
        char str2[100];
        strcpy_s(str2, shu.c_str());
        cout << "ת��Ϊchar��:";
        cout << str2<<endl;
        fstream f;
        f.open("file.txt", ios::out | ios::app);
        f << "HugeInt�ࣺ" << str2 << "��תΪchar����" << endl;
        f.close();
  }
    HugeInt operator=(string& t1);
    friend ostream& operator<<(ostream& out, HugeInt& p);
    friend istream& operator>>(istream& in, HugeInt& p);
    HugeInt& operator++(int)//�Լ����������
    {
       string number;
       HugeInt old(*this);
       cout << "�ԼӶ��ٴΣ�";
        cin >> number;
        this->shu = ADD_INT(this->shu,number);
        cout << this->shu;
        return old;

    }
    HugeInt& operator--(int)//�Լ����������
    {
        string number;
        HugeInt old(*this);
        cout << "�Լ����ٴΣ�";
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
    
    cout <<"�������ǣ�" << shu << endl;
}
void access(string b)//���ν�����д���ļ���
{
    fstream foutput;
    foutput.open("file.txt", ios::out);//����ļ������ڡ���������ɸ��ļ�Ȼ���ٽ���¼�������
    foutput << b << "\n" << endl;
    foutput.close();

}

void show()//������Ҫ���ļ��������������չʾ
{
   
    ifstream infile;
    infile.open("file.txt", ios::in);
    char buf[1024];
    while (infile.getline(buf,sizeof(buf)))//�������
    {
        cout << buf << endl;
    }
}
void follow(string b)//׷��д��
{
    fstream f;
    f.open("file.txt", ios::out | ios::app);
    f << b << endl;
    f.close();

}

void mathresult(string str1, string str2, int n)//���뵽�ļ�����
{
    ofstream foutput("flie.txt");
    switch (n)//���ݴ�������nֵ���ж϶��ߵĴ�С��ϵ
    {
    case 0:
    {foutput << "����ɹ���" << str1 << "is less than " << str2 << endl; }
    case 1:
    {foutput << "����ɹ���" << str1 << "is more than " << str2 << endl; }
    case 2:
    {foutput << "����ɹ���" << str1 << "=" << str2 << endl; }
    }
    foutput.close();
}

void mathresultfile(string str1,string str2,int n)//׷������
{
    fstream f;
    f.open("file.txt", ios::out | ios::app);
        switch (n)
        {
        case 0:
        {f <<"����ɹ���"<< str1 << "is less than " << str2 << endl; }
        case 1:
        {f << "����ɹ���" << str1 << "is more than " << str2 << endl; }
        case 2:
        {f<< "����ɹ���" << str1 << "=" << str2 << endl; }
        }
        f.close();
}
int compare(int a[], int b[])//�Ƚ�a��b����a>bΪ1����a<bΪ-1����a=bΪ0
{
    int i;
    if (a[0] > b[0])
        return 1;
    if (a[0] < b[0])
        return -1;
    for (i = a[0]; i > 0; i--)//�Ӹ�λ����λ�Ƚ�
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}

void jisuan(int a[], int b[])//����a=a-b
{
    int flag;
    int i;

    flag = compare(a, b);
    if (flag == 0)//���
    {
        a[0] = 0;
        return;
    }
    if (flag == 1)//����
    {
        for (i = 1; i <= a[0]; i++)
        {
            if (a[i] < b[i])//���������Ͻ�λ
            {
                a[i + 1]--;
                a[i] += 10;
            }
            a[i] -= b[i];
        }
        while (a[0] > 0 && a[a[0]] == 0)//ɾ��ǰ��0
            a[0]--;
        return;
    }
}

HugeInt operator+(HugeInt& t1, HugeInt& t2)//���ؼӺ������
{
    return ADD_INT(t1.shu, t2.shu);
}

HugeInt operator-(HugeInt& t1, HugeInt& t2)//���ؼ��������
{
    return SUB_INT(t1.shu, t2.shu);
}

HugeInt operator*(HugeInt& t1, HugeInt& t2)//���س˺������
{
    return MUL_INT(t1.shu, t2.shu);
}

HugeInt HugeInt::operator=(string& t1)//���ںŵ����������
{
    shu = t1;
    return shu;
}

 ostream& operator<<(ostream& out, HugeInt& p)//������������
{
     out << p.shu;
     return out;
}

 istream& operator>>(istream& in, HugeInt& p)//�������������
 {
     in >> p.shu;
     return in;
 }
string SUB_INT(string str1, string str2);

string ADD_INT(string str1, string str2) //�ӷ������㺯��
{
    int sign = 1; //sign Ϊ����λ
    string str = " ";

    if (str1[0] == '-') 
    {
        if (str2[0] == '-') //�����������
        {
            sign = -1;
            str = ADD_INT(str1.erase(0, 1), str2.erase(0, 1));//ȥ�������������ĸ���Ȼ����мӷ�����
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
        else//�������������룬������ǰ���0����
        { 
            string::size_type L1, L2;
            int i;
            L1 = str1.size();
            L2 = str2.size();
            if (L1 < L2)
            {
                for (i = 1; i <= L2 - L1; i++) str1 = "0" + str1;//��str1ǰ�油��
            }
            else 
            {
                for (i = 1; i <= L1 - L2; i++) str2 = "0" + str2;
            }
            int int1 = 0, int2 = 0; //int2���ڼ�¼��λ
            for (i = str1.size() - 1; i >= 0; i--) //�����һ������ʼ��
            {
                int1 = (int(str1[i]) - '0' + int(str2[i]) - '0' + int2) % 10;//���������
                int2 = (int(str1[i]) - '0' + int(str2[i]) - '0' + int2) / 10;//��1�ͽ�λ
                str = char(int1 + '0') + str;
            }
            if (int2 != 0) str = char(int2 + '0') + str;
        }
    }
    //����������λ
    if ((sign == -1) && (str[0] != '0')) str = "-" + str;

    return str;
}

string SUB_INT(string str1, string str2)//���������㺯��
{
    int sign = 1; //sign Ϊ����λ
    string str;
    int i, j; 
    if(str1[0]!='-' && str2[0] != '-')//����
    {
        int res = compare(str1, str2);//�ȱȽ��������ĳ��ȴ�С
        if (res == 0) return "0";
        if (res < 0) 
        {
            sign = -1;
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        string::size_type tempint;
        tempint = str1.size() - str2.size();//����������λ���������
        for (i = str2.size() - 1; i >= 0; i--) 
        {
            if (str1[i + tempint] < str2[i]) //��ͬλ�������С��ǰ�ߵ����
            {
                j = 1;
                while (1) 
                {
                    if (str1[i + tempint - j] == '0')//���ǵ�ĳһλ�����0�Ļ����м�����Ҫ��ǰһλ���� 
                    {
                        str1[i + tempint - j] = '9';
                        j++;
                    }
                    else {
                        str1[i + tempint - j] = char(int(str1[i + tempint - j]) - 1);
                        break;
                    }
                }
                str = char(str1[i + tempint] - str2[i] + ':') + str;//��λ����һλ���ļ�������
            }
            else {
                str = char(str1[i + tempint] - str2[i] + '0') + str;
            }
        }
        for (i = tempint - 1; i >= 0; i--) str = str1[i] + str;
    }
    if (str1[0] == '-' && str2[0] == '-')//���ǽ������������ļ���
    {
        str = SUB_INT(str1.erase(0, 1), str2.erase(0, 1));
        sign = -1;
        cout << endl;
    }
    if (str2[0] == '-'&&str1[0]!='-')//��������������������������һ��Ϊ���������
    {
        str = ADD_INT(str1, str2.erase(0, 1));
    }
    if (str1[0] == '-'&&str2[0]!='0')
    {
        str = ADD_INT(str1.erase(0, 1), str2);
        sign = -1;
        cout << endl;
    }
   
    //ȥ������ж����ǰ��0
    str.erase(0, str.find_first_not_of('0'));
    if (str.empty()) str = "0";
    if ((sign == -1) && (str[0] != '0')) str = "-" + str;
    return str;
}


string MUL_INT(string num1, string num2)//�˷������㺯��
{
    int len1 = num1.length(), len2 = num2.length();
    int len = len1 + len2 + 1;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    //tmp����ÿ�γ˷��Ľ����res���������ӵĽ��
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
        //jinwei����ÿ�γ˷��Ľ�λ��r_jw���������ӵĽ�λ
        int jinwei = 0, r_jw = 0;
        for (int j = 0; j < len2; j++)
        {
            tmp[j] = ((num1[i] - '0') * (num2[j] - '0') + jinwei) % 10 + '0';//�������һλ��˽�λ֮��ʣ�µ���

            int res_temp = (res[j + i] - '0') + (tmp[j] - '0') + r_jw;
            
            res[j + i] = res_temp % 10 + '0'; //�������ս��
            
            jinwei = ((num1[i] - '0') * (num2[j] - '0') + jinwei) / 10;//��Ľ�λ���Ǽ���jw�͵��ڼ�
            r_jw = res_temp / 10; //r_jw���������ӵĽ�λ
        }
        //������λ�н�λ
        if (r_jw != 0 || jinwei != 0)
        {
            res[len2 + i] = jinwei + r_jw + '0';		
        }
    }
    string result = "";
    bool flag = false;
    for (int i = len - 1; i >= 0; i--)
    {
        //������һ�������� 
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

void DIVIDE_INT(string s1, string s2,int n)//������
{
    int a[100], b[100], c[100];
    char str1[100], str2[100];
    int i, j;
    memset(a, 0, sizeof(a));//�������������ʼ��
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    strcpy_s(str1, s1.c_str());//c_str�Ƿ��ص�һ����ʱָ�룬��ͨ��strcpy��str1�������ָ��ʹ��õ�s1���ַ���
    strcpy_s(str2, s2.c_str());//ͬ��
    a[0] = strlen(str1);
    b[0] = strlen(str2);
    for (i = 1; i <= a[0]; i++)
        a[i] = str1[a[0] - i] - '0';//���ַ�����ת��Ϊint������м���
    for (i = 1; i <= b[0]; i++)
        b[i] = str2[b[0] - i] - '0';
    int temp[100];
    c[0] = a[0] - b[0] + 1;
    for (i = c[0]; i > 0; i--)
    {
        memset(temp, 0, sizeof(temp));//����ֵ
        for (j = 1; j <= b[0]; j++)
        {
            temp[j + i - 1] = b[j];
            temp[0] = b[0] + i - 1;
        }
        while (compare(a, temp) >= 0)
        {
            c[i]++;
            jisuan(a, temp);//����һλ�ĳ���������
        }
    }
    while (c[0] > 0 && c[c[0]] == 0)
    {
        c[0]--;
    } 
    fstream f;//����һ����������ļ��Ķ���
    if (n == 0)//����ǵ�һ�δ�
    {
        f.open("file.txt", ios::out);
    }
    if (n != 0)//������ν��еĳ��������Ѿ����Ǳ�����������ĵ�һ�����㣬�Ǳ���ʱ��ͽ���׷��д��
    {
        f.open("file.txt", ios::out | ios::app);
    }
    cout << "��Ϊ��";
    if (c[0] == 0)
    {
        f << "��Ϊ:";
        cout << 0 << endl;
        f << 0 << endl;
    }
    else
    {
        f << "��Ϊ:";
        for (i = c[0]; i > 0; i--)
        {
            cout << c[i];
            f << c[i] ;
        }
        cout << endl;
    }
    cout << "����Ϊ:";
    if (a[0] == 0)//�պó��������
    {
       f << "����Ϊ:";
        cout << 0 << endl;
        f << 0 << endl;
    }
    else
    {
        f << "����Ϊ:";
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

void MOD_INT(string s1,string s2,int n)//ȡ�࣬���õļ��㷽�������һ��ֻ�����ֻ��Ҫ�����������
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
    cout << "����Ϊ:";
    if (a[0] == 0)
    {
        f << "����Ϊ:";
        cout << 0 << endl;
        f << 0 << endl;
    }
    else
    {
        f << "����Ϊ:";
        for (i = a[0]; i > 0; i--)
        {
            cout << a[i];
            f << a[i];
        }
        cout << endl;
    }
    f.close();
   
}

bool operator <(HugeInt const& lhs, HugeInt const& rhs)//�Ƚ�ǰ���Ƿ�С�ں���
{
    int size1 = lhs.shu.length();
    int size2 = lhs.shu.length();
    if (size1 == size2)//�ڱȽϺ����У��Ѿ�д�˹������߳��Ȳ��ȵ��������������ֻ������ȵ����
    {
        for (int i = 0; i < size1; i++)
        {
            if (lhs.shu[i] == rhs.shu[i])//�����һλ��С���
            {
                continue;
            }
            if (lhs.shu[i] < rhs.shu[i])//С�ھͷ���true
            {
                return true;
            }
            if(lhs.shu[i]>rhs.shu[i])//���ھͷ���false��ʾ��ϵ������
            {
                return false;
            }
            
        }
    }
}

bool operator >(HugeInt const& lhs, HugeInt const& rhs)//�Ƚ�ǰ���Ƿ���ں��ߣ���ԭ���С�ں���ͬ
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
 //�˵�����
    cout << "��ѡ������ʹ�õļ��㷽ʽ" << endl;
    cout << "1.�ӷ�" << endl;
    cout << "2.����" << endl;
    cout << "3.�˷�" << endl;
    cout << "4.����" << endl;
    cout << "5.����" << endl;
    cout << "6.����" << endl;
}

int  contrast(string str1,string str2)//�ȽϺ���
{
   HugeInt t1(str1);
   HugeInt t2(str2);
   int result;//��Ϊ�����Ҫ�����ļ��У������������result��ֵ���ж�������뵽�ļ�����ʲô��ϵ
    system("cls");
    cout << "�����������Ϊ:" << t1 << " " << str2 << endl;
    int size_int1 = t1.shu.length();
    int size_int2 = t2.shu.length();//������ȷ��ʾ����������ַ�������
    cout << "���߹�ϵ�������ǣ�" << endl;
    if(size_int1<size_int2)//���ݳ���ֱ���ж�
    {
        cout << "a is less than b" << endl;
        result = 0;
    }
    if (size_int1 > size_int2)
    {
        cout << "a is more than b" << endl;
        result = 1;
    }
    if (size_int1 ==size_int2)//����������
    {
        int n = 0;
        for (int i = 0; i < size_int1; i++)
        {
            if (t1.shu[i] == t2.shu[i])//�����ȾͱȽϸ���λ
            {
                n++;//ÿ���һ�ξ��Լ�һ��
            }
            else
            {
                break;
            }
         }
            if (n == size_int1)//������ÿһλ����ȣ���������
            {
                cout << "�������" << endl;
                result = 2;
            }
            else
            {
                 if (t1 < t2)//����С�ں����������
                   {
                    cout << "a is less than b" << endl;
                    result = 0;
                    }
                 if(t1>t2)//���ô��ں����������
                   {
                    cout << "a is more than b" << endl;
                    result = 1; 
                    }
            }
           
       
       
    }
    return result;
}

void selfadd(int times)//�ԼӺ���
{
    
    string str1, str2;
    cout << "��������" << endl;
    cin >> str1 >> str2;
    HugeInt int1(str1);
    HugeInt int2(str2);
    cout << "1.�Լӵ�һ��" << endl;//���������ֵ���ж����Լӵڼ���
    cout << "2.�Լӵڶ���" << endl;
    string number;
    int a;
    cin >> a;
    if (a == 1)
    {
      int1.operator++(0);//�Լ���������أ������Ǻ������㣬������Ҫ�����������һ����0
       cout << "�Ƿ�ѡ�񽫽�����뵽�ļ���" << endl;
       cout << "1:������" << endl;
       cout << "2.ֱ�ӽ���" << endl;
       cin >> a;
       if (a == 1)
       {
           if (times == 0)//���������������������еĵ�һ�ּ���
           {
               access(int1.shu);
               cout << "����ɹ�" << endl;
               show();
           }
           if(times!=0)//����������Ǳ�������������еĵ�һ�ּ���
           {
               follow(int1.shu);
               cout << "�㶨" << endl;
           }
       }
       else
       {
           cout << "�´μ���" << endl;
       }
    }
    if (a == 2)//ԭ��ͬ��
    {
        int2.operator++(0);
        cout << "�Ƿ�ѡ�񽫽�����뵽�ļ���" << endl;
        cout << "1:������" << endl;
        cout << "2.ֱ�ӽ���" << endl;
        cin >> a;
        if (a == 1)
        {
            if (times == 0)
            {
                access(int2.shu);
                cout << "����ɹ�" << endl;
                show();
            }
            else
            {
                follow(int2.shu);
                cout << "�㶨" << endl;
            }
        }
        else
        {
            cout << "�´μ���" << endl;
        }
    }
  

}

void selfsub(int times)//�Լ�����
{

    string str1, str2;
    cout << "��������" << endl;
    cin >> str1 >> str2;
    HugeInt int1(str1);
    HugeInt int2(str2);
    cout << "1.�Լ���һ��" << endl;
    cout << "2.�Լ��ڶ���" << endl;
    string number;
    int a;
    cin >> a;
    if (a == 1)
    {
        int1.operator--(0);//�Լ���������أ������Ǻ������㣬������Ҫ�����������һ����0
        cout << "�Ƿ�ѡ�񽫽�����뵽�ļ���" << endl;
        cout << "1:������" << endl;
        cout << "2.ֱ�ӽ���" << endl;
        cin >> a;
        if (a == 1)
        {
            if (times == 0)//���������������������еĵ�һ�ּ���
            {
                access(int1.shu);
                cout << "����ɹ�" << endl;
                show();
            }
            if (times != 0)//����������Ǳ�������������еĵ�һ�ּ���
            {
                follow(int1.shu);
                cout << "�㶨" << endl;
            }
        }
        else
        {
            cout << "�´μ���" << endl;
        }
    }
    if (a == 2)//ԭ��ͬ��
    {
        int2.operator--(0);
        cout << "�Ƿ�ѡ�񽫽�����뵽�ļ���" << endl;
        cout << "1:������" << endl;
        cout << "2.ֱ�ӽ���" << endl;
        cin >> a;
        if (a == 1)
        {
            if (times == 0)
            {
                access(int2.shu);
                cout << "����ɹ�" << endl;
                show();
            }
            else
            {
                follow(int2.shu);
                cout << "�㶨" << endl;
            }
        }
        else
        {
            cout << "�´μ���" << endl;
        }
    }

}

int main()
{
    cout << "��ѡ������Ҫ���еĹ���" << endl;//����ʾ�˵�
    cout << "1.�鿴����" << endl;
    cout << "2.�������ݲ�����" << endl;
    cout << "3.�������ݲ��Ƚ�" << endl;
    cout << "4.�Լ��Լ�����" << endl;
    cout << "5.�����α�Ϊint��������" << endl;
    cout << "6.����" << endl;
    int a;
    int n = 0;
    int times = 0;//��¼���õ������Ǳ����������ĵ�һ�λ���֮�󼸴�
    string s1, s2;
    string str1, str2;
    HugeInt  res;
    while (cin >> a)
    {
        system("cls");
        if (a == 6)//����6��������
        {
            cout << "������" << endl;
            break;
        }
            
        switch (a)
        {
        case 1:
        {
            show();//�鿴�ļ��е�����
            break;
        }
        case 2:
        {
            menu();//����˵�����
            while (cin >> a)//��ѡ���㷽ʽ
            {
                if (a == 6)
                    break;
                char ch;
                system("cls");//��������
                switch (a)
                {
                case 1:
                {
                    cout << "�������������������мӷ�:";
                    HugeInt c1, c2;
                    cin >> c1 >> c2;//�����������������ʹ�ÿ���ֱ�����볤��������
                    res = c1 + c2;//�Ӻź͵��ں������ˣ����Կ�������д
                  
                    res.getwhile();//���������ж��Ƿ���ȷ
                    cout << "�Ƿ�ѡ�񽫽�����뵽�ļ���" << endl;
                    cout << "1:������" << endl;
                    cout << "2.ֱ�ӽ���" << endl;
                    cin >> a;
                    if (a == 1)
                    {
                        if (times == 0)//�������ǳ���������ĵ�һ������
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out);//�״δ��ļ�����Ϊ�����·�������û������Զ�����һ��������ļ���ͬһ���ļ��еĿ��ļ���
                            foutput << "�ӷ�������Ϊ��" << endl;//����
                            foutput.close();//�ر�
                            access(res.shu);;//�״�¼�뺯��
                            cout << "����ɹ�" << endl;
                            show();
                            times++;
                        }
                        else
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out|ios::app);
                            foutput << "�ӷ�������Ϊ��" << endl;
                            foutput.close();
                            follow(res.shu);//׷��д��
                            cout << "�㶨" << endl;
                            times++;
                        }
                    }
                    else
                    {
                        cout << "�´μ���" << endl;
                    }
                    break;
                }

                case 2:
                {
                    cout << "�������������������м���:";
                    HugeInt c1, c2;
                    cin >> c1 >> c2;//�����������������ʹ�ÿ���ֱ�����볤��������
                    res = c1 - c2;//���ź͵��ں�����������ˣ����Կ���ֱ������д
                    res.getwhile();
                    cout << "�Ƿ�ѡ�񽫽�����뵽�ļ���" << endl;
                    cout << "1:������" << endl;
                    cout << "2.ֱ�ӽ���" << endl;
                    cin >> a;
                    if (a == 1)
                    {
                        if (times == 0)//ԭ��������ӷ���¼����ͬ
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out);
                            foutput << "����������Ϊ��" << endl;
                            foutput.close();
                            follow(res.shu);
                            cout << "����ɹ�" << endl;
                            show();
                        }
                        else
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out|ios::app);
                            foutput << "����������Ϊ��" << endl;
                            foutput.close();
                            follow(res.shu);
                            cout << "�㶨" << endl;
                        }
                    }
                    else
                    {
                        cout << "�´μ���" << endl;
                    }
                    break;
                }

                case 3:
                {
                    cout << "�������������������г˷�:";
                    HugeInt c1, c2;
                    cin >> c1 >> c2;//�����������������ʹ�ÿ���ֱ�����볤��������
                    res = c1 * c2;//�����˵��ںźͳ˺����Կ���ֱ��ʹ��
                    res.getwhile();
                    cout << "�Ƿ�ѡ�񽫽�����뵽�ļ���" << endl;
                    cout << "1:������" << endl;
                    cout << "2.ֱ�ӽ���" << endl;
                    cin >> a;
                    if (a == 1)
                    {
                        if (times == 0)
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out);//�״δ��ļ�����Ϊ�����·�������û������Զ�����һ��������ļ���ͬһ���ļ��еĿ��ļ���
                            foutput << "�˷�������Ϊ��" << endl;//����
                            foutput.close();//�ر�
                            access(res.shu);
                            cout << "����ɹ�" << endl;
                            show();
                        }
                        else
                        {
                            fstream foutput;
                            foutput.open("file.txt", ios::out|ios::app);
                            foutput << "�˷�������Ϊ��" << endl;//����
                            foutput.close();//�ر�
                            follow(res.shu);
                            cout << "�㶨" << endl;
                        }
                    }
                    else
                    {
                        cout << "�´μ���" << endl;
                    }
                    break;
                }

                case 4:
                {cout << "�������������������г���:";
                    HugeInt c1, c2;
                    cin >> c1 >> c2;//�����������������ʹ�ÿ���ֱ�����볤��������
                    DIVIDE_INT(c1.shu, c2.shu,times);//��c1��c2���������͵����������м������㣬�������������ֱ�ӽ�������뵽�ļ���
                    break;
                }

                case 5:
                {
                    cout << "����������ʽ�ӣ�";
                    cin >> s1 >> ch >> s2;//�����������������ʹ�ÿ���ֱ�����볤��������
                    cout << endl;
                    cout << "�����������Ϊ��" << s1 << " " << s2 << endl;
                    HugeInt c1(s1);
                    HugeInt c2(s2);
                    MOD_INT(c1.shu, c2.shu,times);//��c1��c2���������͵��󷨺����м������㣬�������������ֱ�ӽ�������뵽�ļ���
                    break;
                }
                case 6:
                    break;
                default:                   break;
                    times++;
                }
               
                cout << "��������һ��" << endl;
                //system("cls");
                if (a == 6)
                {
                    break;
                }
                menu();
                times++;//ÿ������󶼻��һ��֮��ѭ�����û�н�����¼������ʱ��ʹ��׷��д��
            }
            break;
        }
        case 3:
        {    cout << "��������Ҫ���й�ϵ�����������" << endl;
        int b;
        cin >> str1 >> str2;
        n = contrast(str1, str2);//�����ȽϵĽ����n�����棬֮�󱣴��ļ�ʱ�����n��ֵ���ж����뵽�ļ��о�����ʲô��ϵ
        cout << "�Ƿ�ѡ�񽫽�����뵽�ļ���" << endl;
        cout << "1:������" << endl;
        cout << "2.ֱ�ӽ���" << endl;
        cin >> b;
        if (b == 1)
        {
            if (times == 0)
            {
                mathresult(str1, str2, n);//ͷ��д��
            }
            else
            {
                mathresultfile(str1, str2, n);//׷��д��
            }
        }
        else {
            cout << "����" << endl; 
        }
        break;
        }
        case 4:
        {
            cout << "��ѡ��ִ���ԼӲ��������Լ�����" << endl;
            cout << "1.�ԼӲ���" << endl;
            cout << "2.�Լ�����" << endl;
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
        cout << "����HugeInt�����ݣ�";
        cin >> t1;
        HugeInt T1(t1);//�������Ĺ��캯����T1����ֵ
        T1.change();//��������ת��Ϊchar����
        }
        times++;//ÿ������󶼻��һ��֮��ѭ�����û�н�����¼������ʱ��ʹ��׷��д��
        }
        cout << "��ѡ������Ҫ���еĹ���" << endl;
        cout << "1.�鿴����" << endl;
        cout << "2.�������ݲ�����" << endl;
        cout << "3.�������ݲ��Ƚ�" << endl;
        cout << "4.�Լ��Լ�����" << endl;
        cout << "5.�����α�Ϊint��������" << endl;
        cout << "6.����" << endl;
        cout << "����6�����˳�" << endl;
    } 
    return 0;
}

int b = 10;
const int& p = &b;
