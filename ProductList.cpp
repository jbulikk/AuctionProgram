#include "ProductList.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

ProductList::ProductList(void){}

void ProductList::add_product(shared_ptr<Product>& product, string filename)
{
	m_data.push_back(product);
	


	fstream file;
	file.open(filename, ios::app);
	if (file.is_open())
	{
		file << endl << product->get_auction_number();
		file << endl << product->get_name();
		file << endl << product->get_price();
			
	}

	file.close();
}

void ProductList::remove_product(string auction_number, string filename)
{
	size_t size = m_data.size();
	size_t position;

	for (size_t i = 0; i < size; ++i)
	{
		if (m_data[i]->get_auction_number() == auction_number)
		{
			m_data.erase(m_data.begin() + i);
			m_data.resize(size - 1);
			position = i;
			break;
		}
	}

	ofstream file(filename);

	if (file.is_open())
	{
		size_t loop = 1;

		for (auto v : m_data)
		{
			
			file << v->get_auction_number() << endl;
			file << v->get_name() << endl;
			file << v->get_price();
			loop++;
		}
	}

	file.close();
}
void ProductList::show_products(void)
{
	for (int i = 0; i < m_data.size(); ++i)
	{
		cout << "\t\t" << i + 1 << ". " << m_data[i]->get_auction_number() << m_data[i]->get_name() << " " << m_data[i]->get_price() << endl;
	}
}

bool ProductList::conv_str_to_bool(string line)
{
	if (line == "1")
		return true;

	return false;
}

void ProductList::get_data(string filename)
{
	fstream file(filename);
	string line;

	if (file.is_open() == true)
	{
		while (!file.eof())
		{
			shared_ptr<Product> product = make_shared<Product>();
			getline(file, line);
			product->set_auction_number(line);
			getline(file, line);
			product->set_name(line);
			getline(file, line);
			product->set_price(line);
			getline(file, line);

			m_data.push_back(product);
		}
	}

	file.close();
}
