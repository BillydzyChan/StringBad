/************************************************
 * @FileName:    stringbad.cpp
 * @Author:      Guohao.Chen
 * @Date:        2018.11.29
 * @Description: StringBad class methods
************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "stringbad.h"
using std::cout;

// initializing static class number
int StringBad::num_strings = 0;

//class methods
StringBad::StringBad(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;    
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "c++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default object created\n";
}

StringBad::StringBad(const StringBad & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    cout << num_strings << ": \"" << str << "\" default object created\n";
}


StringBad::~StringBad()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete [] str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}

StringBad & StringBad::operator=(const StringBad & st)
{
    // 检查自我复制
    if(this == &st)
        return *this;
    // 等号两边不同时, 先释放接收对象this的str指向的内存
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}
