#include "Arr_Queue.h"

Queue::Queue() : m_Front(0), m_Rear(-1) 
{
}

bool Queue::push(Stock& s)
{
    if (m_Rear == MAX_SIZE - 1) {
        return false; // queue is full
    }
    else {
        m_Rear++;
        data_[m_Rear] = s;
        return true;
    }
}

bool Queue::pop()
{
    if (empty()) {
        return false; // queue is empty
    }
    else {
        m_Front++;
        return true;
    }
}

Stock Queue::front()
{
    return data_[m_Front];
}

bool Queue::empty()
{
    return m_Front > m_Rear;
}

double Queue::calculateSP(Stock& s, int quantity)
{
    double result = 0.0;
    if (empty())
        return 0.0; // throw error here 

    int temp_For = m_Front;
    int temp_Rear = m_Rear;
    int quant = quantity;

    while (temp_For < temp_Rear && quant >=0)
    {
        if (data_[temp_For].getName() == s.getName())
        {
            result += (data_[temp_For].getPPS() * data_[temp_For].getQuanity()); 
            quant -= data_[temp_For].getQuanity(); 
            if (quant < 0)
            {
                result = result - (data_[temp_For].getPPS() * std::abs(quant)); // removing if it ever gets extra 
            }
        }
        temp_For++;
    }

    result = result / quantity; // just makeing sure we get the average. 

    if (result == 0.0) // probably stock not found 
    {
        std::cout << "mostly stock not found error"; 
        // throw error if my UI is not straight forward 
    }

    return result;
}

