#include "Arr_Stack.h"

Stack::Stack()
: m_Top (- 1)
{
}

bool Stack::push(const Stock& s)
{
    if (m_Top == MAX_SIZE - 1) {
        return false; // stack overflow
    }
    else {
        m_Top++;
        data_[m_Top] = s;
        return true;
    }
}

bool Stack::pop()
{
    if (m_Top == -1) {
        return false; // stack underflow
    }
    else {
        m_Top--;
        return true;
    }
}

Stock Stack::top()
{
    return data_[m_Top];
}

bool Stack::empty()
{
    return m_Top == -1;
}
