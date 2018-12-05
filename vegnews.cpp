/************************************************
 * @FileName:    vegnews.cpp
 * @Author:      Guohao.Chen
 * @Date:        2018.11.30
 * @Description: using new and delete with classes
************************************************/
#include <iostream>
using std::cout;
#include "stringbad.h"

void callme1(StringBad &); // pass by reference
void callme2(StringBad);   // pass by value

int main(int argc, char const *argv[])
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;

        // risk: 这里按值传递，将会调用复制构造函数（所以一般不按值传递对象）
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another:\n";

        // risk: 这句话相当于StringBad sailor = StringBad(sports);
        // 但是StringBad(const StringBad &)即复制构造函数，属于自动生成的构造函数
        // 默认的复制构造函数是浅复制，即逐个复制非静态成员的值
        // 这里复制str的时候不是字符串而是指向字符串的指针，当sports的析构函数被调用
        // 时，sport.str的内存已经被释放，但sailor.str无处可指，导致乱码
        // 而且后面sailor被析构的时候，内存会被释放两次，可能导致程序异常终止。
        StringBad sailor = sports;
        
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;

        // 赋值运算符 如果类中没有定义 则会自动为类重载 但没有深复制
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";

    return 0;
}

void callme1(StringBad &rsb) // pass by reference
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

// 按值传递意味着创建原始变量的一个副本
// 相应地就会使用复制构造函数
void callme2(StringBad sb) // pass by value
{
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}