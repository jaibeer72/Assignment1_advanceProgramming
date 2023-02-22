#include "Stock.h"
#include "ListManager.h"



int main() {

	ListManager::getInstance().push(*(new Stock ("Google", 1000, 22.5)));
	ListManager::getInstance().push(*(new Stock("Microsoft", 200, 33.6)));
	ListManager::getInstance().push(*(new Stock("Apple", 300, 44.5)));
	ListManager::getInstance().push(*(new Stock("Apple", 20, 45.5)));
	ListManager::getInstance().push(*(new Stock("Apple", 40, 64.5)));
	ListManager::getInstance().push(*(new Stock("Apple", 60, 84.7)));
	ListManager::getInstance().push(*(new Stock("Apple", 23, 94.3)));
	ListManager::getInstance().push(*(new Stock("Apple", 50, 101.3)));
	ListManager::getInstance().push(*(new Stock("Apple", 600, 254.3)));

	auto s = new Stock("Apple", 0, 0.0);

	auto result = ListManager::getInstance().getSP_For_AllLists(*s , 17);
	
	for(const auto& res : result)
	{
		std::cout << res.first << " : " << res.second << std::endl; 
	}

	ListManager::getInstance().printList();
	ListManager::getInstance().sell_Stock(*s, 653);
	ListManager::getInstance().printList();



	return 0; 
}