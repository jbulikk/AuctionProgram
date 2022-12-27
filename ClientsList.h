#pragma once
#include <vector>
#include "ClientData.h"

using namespace std;

class ClientsList {

private:
	vector<ClientData> m_data;

public:
	vector<ClientData> get_data(void) const;

	void set_data(vector<ClientData> data);

	ClientsList(void);
	ClientsList(vector<ClientData> data);

	bool conv_str_to_bool(string line);

	void add_client(ClientData clientData, string filename);

	void show_clientlist(void);
	void get_data(string filename);
};