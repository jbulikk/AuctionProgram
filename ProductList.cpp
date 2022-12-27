#include "ProductList.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>

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
	auto it = remove_if(m_data.begin(), m_data.end(), [&](const shared_ptr<Product>& product) { return product->get_auction_number() == auction_number; });
	m_data.erase(it);

	ofstream file(filename);

	if (file.is_open())
	{
		for (const auto& v : m_data)
		{
			
			file << v->get_auction_number() << endl;
			file << v->get_name() << endl;
			file << v->get_price();
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

			m_data.push_back(product);
		}
	}

	file.close();
}
