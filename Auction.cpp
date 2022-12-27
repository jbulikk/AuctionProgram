#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <locale.h>
#include "ClientsList.h"
#include "ProductList.h"
#include "Sale.h"
#include <cstdlib>
#include <ctime>

using namespace std;

bool check_option(string choice, vector<string> options)
{
	bool value = false;

	for (size_t i = 0; i < options.size(); ++i)
	{
		if (choice == options[i])
		{
			value = true;
		}
	}

	if (value == false)
	{
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\tProszę wybrać poprawną opcję z menu";
		cout << endl << endl << endl << endl << endl;
		Sleep(1000);
	}

	return value;
}

void first_menu(void) {

	system("CLS");


	cout << endl << endl << endl;
	cout << "\t\t\t\t 1. Kup." << endl;
	cout << "\t\t\t\t 2. Dodaj ogloszenie." << endl;
	cout << "\t\t\t\t "<< endl;
	cout << "\t\t\t\t  Wyjście(q)" << endl;

}

void add_auction(ProductList& productList)
{
	shared_ptr<Product> product = make_shared<Product>();
	string line;
	string confirm;
	string auction_code;

	srand(time(NULL));

	for (int i = 0; i < 3; i++) {
		int los = rand() % 36;
		if (los < 10) {
			auction_code.push_back('0' + los);
		}
		else {
			auction_code.push_back('a' + los - 10);
		}
	}

	while (true)
	{
		product->set_auction_number(auction_code);
		
		system("CLS");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t Uzupelnij dane ogloszenia:" << endl;
		cout << endl << "Produkt:" << endl;
		cin >> line;
		product->set_name(line);
		cout << endl << "Cena:" << endl;
		cin >> line;
		product->set_price(line);

		cout << endl << "Zatwiedz(z) | Powtorz(r) | Wyjdz bez zapisywania(q)" << endl;

		cin >> confirm;

		if (confirm == "z")
		{
			productList.add_product(product, "ProductList.txt");
			break;
		}
		else if (confirm == "r")
		{
			continue;
		}
		else if (confirm == "q")
			break;
		else
			check_option(confirm, { "r","z" });
	}
	
}

void remove_auction(ProductList& list)
{
	string name;
	string confirm;

	while (true)
	{
		system("CLS");

		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t Podaj nazwe lub kod:" << endl << endl;

		cin >> name;

		cout << endl << "Zatwiedź(z) | Powtórz(r) | Wyjdź(q)" << endl;

		cin >> confirm;

		if (confirm == "z")
		{
			list.remove_product(name, "ProductList.txt");
			break;
		}
		else if (confirm == "r")
		{
			continue;
		}
		else if (confirm == "q")
			break;
		else
			check_option(confirm, { "r","z" });
	}


}


int main()
{

	ProductList list = ProductList();
	list.get_data("ProductList.txt");

	//add_auction(list);
	remove_auction(list);
}

