#include "funkcijos.h"

bool operator<(const zodziai &a, const zodziai &b)
{
    return a.w < b.w;
}

bool ar_naujas(string word, set<zodziai> zod)
{
    set<zodziai>::iterator itr;
    for (itr = zod.begin(); itr != zod.end(); itr++)
    {
        if (itr->w == word)
            return false;
    }
    return true;
}

void plius(string word, set<zodziai> &zod, int eil)
{
    set<zodziai>::iterator itr;
    for (itr = zod.begin(); itr != zod.end(); itr++)
    {
        if (itr->w == word)
        {
            bool ne_same = true;
            itr->kiekis++;
            for (int i = 0; i < itr->eilute.size(); i++)
            {
                if (eil == itr->eilute[i])
                    ne_same = false;
            }
            if (ne_same)
            {
                itr->eilute.push_back(eil);
            }
            break;
        }
    }
}

bool is_number(const string &s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

string lower_case(string word)
{
    std::transform(word.begin(), word.end(), word.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    return word;
}

void print(set<zodziai> url, set<zodziai> zod, int eil)
{
    ofstream file("ATS.txt");
    set<zodziai>::iterator itr;

    file << setw(15) << left << "ZODZIAI"
         << " KIEKIS    KURIOSE EILUTESE RANDAMI" << endl;
    file << "-----------------------------------------------------------" << endl;

    for (itr = zod.begin(); itr != zod.end(); itr++)
    {

        if (itr->kiekis > 1)
        {
            file << setw(14) << left << itr->w << "  " << setw(8) << itr->kiekis << "   ";
            for (int i = 0; i < itr->eilute.size(); i++)
            {
                file << itr->eilute[i] << " ";
            }
            file << endl;
        }
    }

    file << endl;
    file << "-----------------------------------------------------------" << endl;
    file << "URL linkai: " << endl;
    set<zodziai>::iterator it;
    for (it = url.begin(); it != url.end(); it++)
    {
        file << it->w << endl;
    }

    file.close();
}

string yra_simbolai(string word)
{
    string sim = ".,:;-!–?{.}()'";
    for (int i = 0; i < sim.size(); i++)
    {
        for (int j = 0; j < word.length(); j++)
        {
            if (word[j] == sim[i])
            {
                word.erase(remove(word.begin(), word.end(), sim[i]), word.end());
            }
        }
    }
    return word;
}
string s_pabaiga(string word)
{
    string sim = ".,:;-!–?{}()%'";
    for (int i = 0; i < sim.size(); i++)
    {
        if (word.back() == sim[i])
        {
            word.pop_back();
        }
    }
    return word;
}