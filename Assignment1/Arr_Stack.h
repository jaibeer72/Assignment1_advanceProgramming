#pragma once
#include "Stock.h"


class Stack
{
public:
    Stack();
    bool push(const Stock& s);
    bool pop();
    Stock top();
    bool empty(); 
    double calculateSP(Stock& s, int quantity); 

private:
    Stock data_[MAX_SIZE];
    int m_Top;
};


