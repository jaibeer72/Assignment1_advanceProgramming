#include "Stock.h"

Stock::Stock() :m_Name("name"), m_Quantity(0), m_PPS(0.0)
{
}

Stock::Stock(std::string name, int quanity, double PPS) :
	m_Name(name), m_Quantity(quanity) , m_PPS(PPS)
{
}

Stock::~Stock()
{
}

std::string Stock::getName()
{
	return m_Name;
}

int Stock::getQuanity()
{
	return m_Quantity;
}

double Stock::getPPS()
{
	return m_PPS;
}
