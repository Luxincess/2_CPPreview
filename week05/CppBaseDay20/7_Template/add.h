#ifndef __ADD_H__
#define __ADD_H__

//* 对于模板来说，不能写成头文件与实现文件的形式，否则就会报错，链接的时候出现了问题
//* g++ -c *.cc 没问题
//* g++ *.cc 出现问题
template <class T>
T add(T a, T b);

#include "add.cc"

#endif