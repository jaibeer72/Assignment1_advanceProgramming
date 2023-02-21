#pragma once
#include "Arr_Queue.h"
#include "Arr_Stack.h"

#include <unordered_set>
#include <memory>

/// <summary>
/// let's make a singleton cause this is a small project 
/// and it makes sense that taking we want to make sure we have only 
/// 2 instances for things
/// </summary>

class ListManager : ListBase
{
public:
    static ListManager& getInstance();
    ~ListManager() = default;

    // Prevent copying and assignment
    ListManager(const ListManager&) = delete;
    ListManager& operator=(const ListManager&) = delete;

    bool push(Stock& s) override;
    bool pop() override;
    bool empty() override;
    double calculateSP(Stock& s, int quantity) override;

private:
    ListManager(); 
    std::unordered_set<Stock> m_UniqueStocks;
    std::unordered_set<std::unique_ptr<ListBase>> m_Lists;

};