/*
�� 1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*/

// ���ù��캯�����
// �ȶ���һ�����ͣ����Ŵ��� n �������͵�ʵ������ô������͵Ĺ��캯����ȷ���ᱻ���� n �Ρ�
class Temp
{
public:
    Temp() {++N; sum +=N;}
    
    static void reset() {N = 0; sum = 0;}
    static unsigned int GetSum() {return sum;}

private:
    static int N;
    static int sum;
};
// ���þ�̬���� N��sum���ڹ��캯���н����ۼ�����
// Ȼ����һ������Ϊ Temp����СΪ n �����飬�ظ����ôι��캯�� n ����ʵ�� n �ε��ۼ�����
int Temp::N = 0;
int Temp::sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Temp::reset();
        Temp *a = new Temp[n];
        delete []a;
        a = nullptr;
        
        return Temp::GetSum();
    }
};

/*
// �����麯����� 
// ��������������һ�������䵱�ݹ麯���Ľ�ɫ����һ������������ֹ�ݹ���������Ҫ���ľ����������������ѡһ��
// ʹ�ò����������ж�ѡһ��!!n �� n ���������η����㣬����� n ת��Ϊ true��0 ת��Ϊ false��

class A;
A* Array[2];

class A
{
public:
    virtual int Sum(int n)
    {
        return 0;
    }
};

class B: public A
{
public:
    virtual int Sum(int n)
    {
        return Array[!!n]->Sum(n-1) + n;
    }
};

class Solution {
public:
    int Sum_Solution(int n) {
        A a;
        B b;
        Array[0] = &a;
        Array[1] = &b;
        
        return Array[1]->Sum(n);
    }
};
*/

/*
// ʹ�ö�·����������ݹ飬&& ��·���ԣ���ǰ��ı��ʽΪ�٣��Ͳ�����ִ�к���ı��ʽ�� 
// ���� 0 ��ʱ����� 0 �������ݹ�

class Solution {
public:
    int Sum_Solution(int n) {
        int ret = n;
        n && (ret += Sum_Solution(n-1));
        
        return ret;
    }
};
*/ 
