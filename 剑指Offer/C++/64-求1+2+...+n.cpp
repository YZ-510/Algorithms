/*
求 1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

// 利用构造函数求解
// 先定义一个类型，接着创建 n 个该类型的实例，那么这个类型的构造函数将确定会被调用 n 次。
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
// 设置静态变量 N、sum，在构造函数中进行累加运算
// 然后构造一个类型为 Temp、大小为 n 的数组，重复调用次构造函数 n 次来实现 n 次的累加运算
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
// 利用虚函数求解 
// 定义两个函数，一个函数充当递归函数的角色，另一个函数处理终止递归的情况，需要做的就是在两个函数里二选一。
// 使用布尔变量进行二选一，!!n 对 n 连续做两次反运算，非零的 n 转换为 true，0 转换为 false。

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
// 使用短路计算来构造递归，&& 短路特性：若前面的表达式为假，就不会再执行后面的表达式。 
// 输入 0 的时候输出 0 来结束递归

class Solution {
public:
    int Sum_Solution(int n) {
        int ret = n;
        n && (ret += Sum_Solution(n-1));
        
        return ret;
    }
};
*/ 
