#include "ListManager.h"

ListManager::ListManager()
{
    m_Lists.insert(std::make_unique<Queue>());
    m_Lists.insert(std::make_unique<Stack>());
}

ListManager& ListManager::getInstance()
{
    static ListManager instance;
    return instance;
}

bool ListManager::push(Stock& s)
{
    auto it = m_UniqueStocks.find(s); 
    if (it != m_UniqueStocks.end())
    {
        int quant = const_cast<Stock&>(*it).getQuanity() + s.getQuanity();
        const_cast<Stock&>(*it).setQuanity(quant); 
    }
    else
    {
        m_UniqueStocks.insert(s); 
    }
    return false;
}

bool ListManager::pop()
{
    return false;
}

bool ListManager::empty()
{
    return false;
}

double ListManager::calculateSP(Stock& s, int quantity)
{
    return 0.0;
}
