/************************************************
 * @FileName:    stringbad.h
 * @Author:      Guohao.Chen
 * @Date:        2018.11.29
 * @Description: flawed string class definition
************************************************/ 
#include <iostream>
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
class StringBad
{
private:
    char * str;
    int len;
    static int num_strings;

public:
    StringBad(const StringBad & st);
    StringBad(const char * s);
    StringBad();
    ~StringBad();
    StringBad & operator=(const StringBad & st);

    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);

};

#endif	// STRINGBAD_H_