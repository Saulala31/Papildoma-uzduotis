#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <set>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>

using std::setw;
using namespace std;

struct zodziai
{
    string w;
    mutable int kiekis = 0;
    mutable vector<int> eilute;
};

bool operator<(const zodziai &a, const zodziai &b);
bool ar_naujas(string word, set<zodziai> zod);
void plius(string word, set<zodziai> &zod, int eil);
bool is_number(const string &s);
string lower_case(string word);
void print(set<zodziai> url, set<zodziai> zod, int eil);
string yra_simbolai(string word);
string s_pabaiga(string word);
