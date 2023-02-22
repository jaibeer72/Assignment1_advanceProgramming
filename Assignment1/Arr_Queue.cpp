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

    while (temp_For <= temp_Rear && quant >=0)
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

bool Queue::sell_Stock(Stock& s, int quantity)
{
    if (empty()) {
        return false; // throw error here 
    }

    int removedQuantity = 0;

    for (int i = m_Front; i <= m_Rear; i++) {
        if (data_[i].getName() == s.getName()) {
            int stockQuantity = data_[i].getQuanity();
            if (stockQuantity > quantity - removedQuantity) {
                // remove a portion of the stock
                data_[i].setQuanity(stockQuantity - (quantity - removedQuantity));
                removedQuantity = quantity;
                break;
            }
            else {
                // remove the entire stock
                removedQuantity += stockQuantity;
                for (int j = i; j < m_Rear; j++) {
                    data_[j] = data_[j + 1];
                }
                m_Rear--;
                i--; // check the element in this position again
            }
        }
        if (removedQuantity == quantity) {
            break;
        }
    }

    return removedQuantity == quantity;
}

void Queue::printList()
{
    int temp_For = m_Front;
    int temp_Rear = m_Rear;

    while (temp_For <= temp_Rear)
    {
        std::cout << " Name : " << data_[temp_For].getName() << " Quantity " << data_[temp_For].getQuanity() << " PPS : " << data_[temp_For].getPPS() << std::endl;
        temp_For++;
    }
}

