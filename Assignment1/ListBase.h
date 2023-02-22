#pragma once
#include "Stock.h"

class ListBase
{
public: 
    virtual bool push(Stock& s) = 0;
    virtual bool pop() = 0;
    virtual bool empty() = 0;
    virtual double calculateSP(Stock& s, int quantity) = 0;
    virtual bool sell_Stock(Stock& s, int quanitity) = 0; 
    virtual void printList() = 0; 
    virtual ~ListBase() {}

private:

};
