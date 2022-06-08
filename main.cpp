#include "funkcijos.h"

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    set<zodziai> zod, url;
    fstream file;
    string word, filename;

    filename = "Vilnius.txt";

    file.open(filename.c_str());

    string line;
    int eil = 0;
    regex urls(".*\\..*");
    while (getline(file, line))
    {
        eil++;
        word = "";
        for (int i = 0; i <= line.length(); i++)
        {
            if (line[i] == ' ' || i == line.length())
            {
                word = s_pabaiga(word);
                if (regex_match(word, urls))
                {
                    zodziai s;
                    s.w = word;
                    url.insert(s);
                    word = "";
                }
                else if (!is_number(word))
                {
                    word = yra_simbolai(word);
                    word = lower_case(word);
                    if (word != "")
                    {
                        if (ar_naujas(word, zod))
                        {
                            zodziai s;
                            s.w = word;
                            s.kiekis++;
                            s.eilute.push_back(eil);
                            zod.insert(s);
                        }
                        else
                        {
                            plius(word, zod, eil);
                        }
                    }
                    word = "";
                }
            }
            else
            {
                word = word + line[i];
            }
        }
    }
    print(url, zod, eil);

    return 0;
}