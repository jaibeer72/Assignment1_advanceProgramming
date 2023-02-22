#include "Arr_Stack.h"

Stack::Stack()
: m_Top (- 1)
{
}

bool Stack::push(Stock& s)
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
    if (empty()) {
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

double Stack::calculateSP(Stock& s, int quantity)
{
    double result = 0.0;
    if (empty())
        std::cout << "underflow nothing there "; 

    int temp_Top = m_Top; 
    int quant = quantity; 

    while (temp_Top >= 0 && quant >= 0)
    {
        if (data_[temp_Top].getName() == s.getName())
        {
            result += (data_[temp_Top].getPPS() * data_[temp_Top].getQuanity());
            quant -= data_[temp_Top].getQuanity();
            if (quant < 0)
            {
                result = result - (data_[temp_Top].getPPS() * std::abs(quant)); // removing if it ever gets extra 
            }
        }
        temp_Top--; 
    }
    result = result / quantity;

    if (result == 0.0) // probably stock not found 
    {
        std::cout << "mostly stock not found error";
        // throw error if my UI is not straight forward 
    }

    return result;
}

bool Stack::sell_Stock(Stock& s, int quantity)
{
    if (empty()) {
        return false;
    }
    int i = m_Top;
    while (i >= 0) {
        if (data_[i].getName() == s.getName()) {
            int nodeQuant = data_[i].getQuanity();
            if (nodeQuant <= quantity) {
                for (int j = i; j < m_Top; j++) {
                    data_[j] = data_[j + 1];
                }
                m_Top--;
                return true;
            }
            else {
                // Update the node's quantity and return
                data_[i].setQuanity(nodeQuant - quantity);
                return true;
            }
        }
        i--;
    }
    return false;
}

void Stack::printList()
{
    int temp_Top = m_Top;

    while (temp_Top >= 0)
    {
        std::cout << " Name : " << data_[temp_Top].getName() << " Quantity " << data_[temp_Top].getQuanity() << " PPS : " << data_[temp_Top].getPPS() << std::endl;
        temp_Top--;
    }
}
