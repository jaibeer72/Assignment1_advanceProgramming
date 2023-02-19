#pragma once
#include "Stock.h"

const int MAX_SIZE = 100;

class Stack
{
public:
    Stack();
    bool push(const Stock& s);
    bool pop();
    Stock top();
    bool empty(); 

private:
    Stock data_[MAX_SIZE];
    int m_Top;
};


