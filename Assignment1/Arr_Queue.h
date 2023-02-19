#pragma once
#include "Stock.h"

class Queue
{
public:
    Queue();
    bool push(const Stock& s);
    bool pop();
    Stock front(); 
    bool empty(); 
    double calculateSP(Stock& s, int quantity);
private:
    Stock data_[MAX_SIZE];
    int m_Front;
    int m_Rear;

};

