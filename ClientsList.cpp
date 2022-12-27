#include "ClientsList.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


vector<ClientData> ClientsList::get_data(void) const { return m_data; }

void ClientsList::set_data(vector<ClientData> data) { m_data = data; }

ClientsList::ClientsList(void)
{
	vector<ClientData> data;
	m_data = data;
}

ClientsList::ClientsList(vector<ClientData> data)
{
	m_data = data;
}

void ClientsList::add_client(ClientData clientData, string filename)
{
	m_data.push_back(clientData);

	fstream file;
	file.open(filename, ios::app);
	if (file.is_open())
	{
		file << endl << clientData.get_name();
		file << endl << clientData.get_sname();
		file << endl << clientData.get_adress();
		file << endl << clientData.get_mail();
		file << endl << clientData.get_phone_number();


	}

	file.close();
}


void ClientsList::show_clientlist(void)
{
	for (int i = 0; i < m_data.size(); ++i)
	{
		cout << "\t\t" << i + 1 << ". " << m_data[i].get_name() << " " << m_data[i].get_sname() << endl;
	}
}

bool ClientsList::conv_str_to_bool(string line)
{
	if (line == "1")
		return true;
	else if (line == "0")
		return false;
}

void ClientsList::get_data(string filename)
{
	fstream file(filename);

	ClientData clientData = ClientData();
	string line;

	if (file.is_open() == true)
	{
		while (!file.eof())
		{
			getline(file, line);
			clientData.set_name(line);
			getline(file, line);
			clientData.set_sname(line);
			getline(file, line);
			clientData.set_adress(line);
			getline(file, line);
			clientData.set_mail(line);
			getline(file, line);
			clientData.set_phone_number(line);


			m_data.push_back(clientData);
		}


	}

	file.close();
}




