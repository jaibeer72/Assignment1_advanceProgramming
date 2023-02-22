#pragma once
#include "ListBase.h"

class Queue : public ListBase
{
public:
    Queue();
    bool push(Stock& s) override;
    bool pop() override;
    Stock front(); 
    bool empty() override;
    double calculateSP(Stock& s, int quantity) override;
    bool sell_Stock(Stock& s, int quanitity) override;
    void printList() override;

private:
    Stock data_[MAX_SIZE];
    int m_Front;
    int m_Rear;
};

