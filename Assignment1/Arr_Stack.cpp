#include "Arr_Stack.h"

Stack::Stack()
: m_Top (- 1)
{
}

bool Stack::push(Stock& s)
{
    if (m_Top == MAX_SIZE - 1) {
        std::cout << "Stack overflow"; 
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
        std::cout << "Stack underflow"; 
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
        std::cout << "underflow nothing there in the stack"; 

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
        std::cout << "\n ****[ Stock NOT Found Error in Stack ]****";
        return 0.0; 
        // throw error if my UI is not straight forward 
    }

    if (quant > 0)
    {
        std::cout << "\n ****[ Trying to sell more stock than you have: On confirm this will sell all your inventory for this stock] ********";
    }

    return result;
}

bool Stack::sell_Stock(Stock& s, int quantity)
{
    if (empty()) {
        std::cout << "Stack underflow : Empty stack"; 
        return false;
    }
    int i = m_Top;
    while (i >= 0 && quantity > 0) {
        if (data_[i].getName() == s.getName()) {
            int nodeQuant = data_[i].getQuanity();
            if (nodeQuant <= quantity) {
                for (int j = i; j < m_Top; j++) {
                    data_[j] = data_[j + 1];
                }
                quantity -= nodeQuant; // redusing the quanity just to make sure 
                m_Top--;
            }
            else {
                // Update the node's quantity and return
                data_[i].setQuanity(nodeQuant - quantity);
                quantity = 0; 
            }
        }
        i--;
    }
    std::cout << "Trying to sell more quaity than you have";
    return false;
}

void Stack::printList()
{
    int temp_Top = m_Top;

    while (temp_Top >= 0)
    {
        std::cout << " \n [ Name ] : " << data_[temp_Top].getName() << "  [ Quantity ] : " << data_[temp_Top].getQuanity() << "  [ PPS ] : " << data_[temp_Top].getPPS() << std::endl;
        temp_Top--;
    }
}
