#pragma once
#include "ListBase.h"


class Stack : public ListBase
{
public:
    Stack();
    bool push(Stock& s) override;
    bool pop() override;
    Stock top();
    bool empty() override;
    double calculateSP(Stock& s, int quantity)override;
    bool sell_Stock(Stock& s, int quanitity) override;
    void printList() override;

private:
    Stock data_[MAX_SIZE];
    int m_Top;
};


