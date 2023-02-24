#include "Stock.h"
#include "ListManager.h"


void showMainMenu()
{
	std::cout << "\n [--Main Menu--]"; 
	std::cout << "\n [1] : Buy Stock "; 
	std::cout << "\n [2] : Sell Stock "; 
	std::cout << "\n [3] : See All Stock "; 
	std::cout << "\n [4] : Exit"; 
}

enum MenuState {
	MainMenu, 
	BuyMenu,
	SellMenu,
	SeeAllStockMenu,
	Exit
};



void MainMenuOperations(int input, MenuState& state);

void BuyMenuView(int& input, MenuState& state);

void SellMenuView(int& input, MenuState& state);

void SeeAllStocksView(int& input, MenuState& state);

int main() {

	MenuState state = MainMenu; 
	int input; 

	// creating some existing data so that we don't have to keep adding and make testing easier. 
	ListManager::getInstance().push(*(new Stock("Google", 1000, 22.5)));
	ListManager::getInstance().push(*(new Stock("Microsoft", 200, 33.6)));
	ListManager::getInstance().push(*(new Stock("Apple", 300, 44.5)));
	ListManager::getInstance().push(*(new Stock("Apple", 20, 45.5)));
	ListManager::getInstance().push(*(new Stock("Apple", 40, 64.5)));
	ListManager::getInstance().push(*(new Stock("Apple", 60, 84.7)));
	ListManager::getInstance().push(*(new Stock("Apple", 23, 94.3)));
	ListManager::getInstance().push(*(new Stock("Apple", 50, 101.3)));
	ListManager::getInstance().push(*(new Stock("Apple", 600, 254.3)));

	while (state != Exit)
	{
		switch (state)
		{
		case MainMenu:
			showMainMenu(); 
			std::cin >> input; 
			MainMenuOperations(input, state);
			break;
		case BuyMenu:
			BuyMenuView(input, state);
			break;
		case SellMenu:
			SellMenuView(input, state);
			break;
		case SeeAllStockMenu:
			SeeAllStocksView(input, state);
			break;
		case Exit:
			break;
		default:
			break;
		}
	}

	return 0; 
}

void SeeAllStocksView(int& input, MenuState& state)
{
	ListManager::getInstance().printList();
	std::cout << "\n Give any input to go back to main menu";
	std::cin >> input;
	state = MainMenu;
	system("cls");
}

void SellMenuView(int& input, MenuState& state)
{
	std::string sName;
	int quanity;
	std::cout << "\n input stock name to sell : ";
	std::cin >> sName;
	std::cout << "\n input the quanity you want to sell :  ";
	std::cin >> quanity;
	auto s = new Stock(sName, quanity, 0.0);
	auto result = ListManager::getInstance().getSP_For_AllLists(*s, quanity);
	for (const auto& res : result)
	{
		std::cout << "\n The PPS selling price in type " << res.first << " will be : " << res.second << std::endl;
	}
	std::cout << "\n to confirm selling press 1 else press any input to go back to main menu";
	std::cin >> input;
	if (input == 1)
	{
		ListManager::getInstance().sell_Stock(*s, quanity);
		std::cout << "\n Give any input to go back to main menu";
		std::cin >> input;
		state = MainMenu;
		system("cls");
	}
	else {
		state = MainMenu;
	}
}

void BuyMenuView(int& input, MenuState& state)
{
	std::string sName;
	int quantity;
	double PPS;
	std::cout << "\n Input Stock Name";
	std::cin >> sName;
	std::cout << "\n Input Stock Quantity";
	std::cin >> quantity;
	std::cout << "\n Input Stock Price Per Share";
	std::cin >> PPS;
	auto s = new Stock(sName, quantity, PPS);
	if (ListManager::getInstance().push(*s))
	{
		std::cout << "\n Stock added successfully to your stocks";
		std::cout << "\n Give any input to go back to main menu";
		std::cin >> input;
		state = MainMenu;
		system("cls");
	}
	else
	{
		std::cout << "\n Error adding stock";
	}
}

void MainMenuOperations(int input, MenuState& state)
{
	switch (input)
	{
	case 1: state = BuyMenu; system("cls"); break;
	case 2: state = SellMenu; system("cls"); break;
	case 3: state = SeeAllStockMenu; system("cls"); break;
	case 4: state = Exit; system("cls"); break;
	default:

		std::cout << "\n Invalid Input";
		break;
	}
}
