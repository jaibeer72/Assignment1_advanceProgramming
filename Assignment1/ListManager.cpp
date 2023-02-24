#include "ListManager.h"

ListManager::ListManager()
{
    m_Lists.insert({ "Queue",std::make_unique<Queue>() });
    m_Lists.insert({ "Stack", std::make_unique<Stack>()});
}

bool ListManager::sell_Stock(Stock& s, int quanitity)
{
    for (const auto& listPtr : m_Lists)
    {
        listPtr.second->sell_Stock(s , quanitity);
    }

    return true; 
}

void ListManager::printList()
{
    for (const auto& listPtr : m_Lists)
    {
        std::cout << listPtr.first << std::endl; 
        listPtr.second->printList(); 
        std::cout << std::endl; 
    }
}

ListManager& ListManager::getInstance()
{
    static ListManager instance;
    return instance;
}

bool ListManager::push(Stock& s)
{
    for (const auto& listPtr : m_Lists) {
        if (!listPtr.second->push(s))
        {
            // throw error cause something failed
            std::cout << "error doing push operation in " << listPtr.first;
            return false; 
        }
    }
    // TODO : Make this later. 
    //auto it = m_UniqueStocks.find(s); 
    //if (it != m_UniqueStocks.end())
    //{
    //    int quant = const_cast<Stock&>(*it).getQuanity() + s.getQuanity();
    //    const_cast<Stock&>(*it).setQuanity(quant); 
    //}
    //else
    //{
    //    m_UniqueStocks.insert(s); 
    //}

    return true;
}

bool ListManager::pop()
{
    for (const auto& listPtr : m_Lists) {
        if (!listPtr.second->pop())
        {
            // throw error cause something failed
            std::cout << "error doing pop operation in "<< listPtr.first;
        }
    }
    return true;
}

// Might not be needed but keeping for now debug later
bool ListManager::empty()
{
    for (const auto& listPtr : m_Lists) {
        if (!listPtr.second->empty())
        {
            return false;
        }
    }
    return true;
}

std::unordered_map<std::string, double> ListManager::getSP_For_AllLists(Stock& s, int quantity)
{
    std::unordered_map<std::string, double> result;

    for (const auto& listPtr : m_Lists) {
        result.insert({ listPtr.first , listPtr.second->calculateSP(s,quantity) });
    }

    return result;
}

double ListManager::calculateSP(Stock& s, int quantity)
{
    return 0.0;
}
