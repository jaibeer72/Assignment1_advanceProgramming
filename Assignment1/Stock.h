#pragma once
#include <iostream>
#include <string>

const int MAX_SIZE = 100;

class Stock

{
public:
	Stock(); 
	Stock(std::string name , int quanity, double PPS);
	~Stock();
	std::string getName(); 
	int getQuanity(); 
	double getPPS(); 

private:
	std::string m_Name; 
	int m_Quantity; 
	double m_PPS; // price per share 
};
