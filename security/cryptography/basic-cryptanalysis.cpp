#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>
#include <iterator>
using namespace std;

map<int, vector<string>> wordmap;

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    copy(std::istream_iterator<string>(tokenStream),
         std::istream_iterator<string>(),
         std::back_inserter(tokens));
    return tokens;
}

bool isomorph(string &a, string &b)
{
    int charmap[256], visited[256];
    memset(charmap, -1, sizeof(charmap));
    memset(visited, 0, sizeof(visited));

    int alen = a.length();
    int blen = b.length();

    if (alen != blen)
    {
        return false;
    }

    for (int i = 0; i < alen; i++)
    {
        int ai = a[i];
        int bi = b[i];
        if (charmap[ai] == -1)
        {
            if (visited[bi])
            {
                return false;
            }
            charmap[ai] = b[i];
            visited[bi] = 1;
        }
        else if (charmap[ai] != b[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    fstream dict_file("dictionary.lst");
    
    if (dict_file.is_open())
    {
        while (!dict_file.eof())
        {
            char line[100];
            dict_file.getline(line, 100);
            for (int i = 0; line[i]; i++)
            {
                line[i] = tolower(line[i]);
            }
            string s(line);            
            wordmap[s.length()].push_back(s);
        }
        dict_file.close();
    }

    string input;
    getline(cin, input);

    vector<string> words = split(input, ' ');
    map<string, string> wordok;
    //int cmap[26];
    //buildmap(cmap);

    int charmap[256];
    memset(charmap, -1, sizeof(charmap));

    bool new_words;
    do
    {
        new_words = false;
        for (auto word : words)
        {
            if (wordok.count(word) == 0)
            {
                int len = word.length();
                int count = 0;
                string ok;
                for (auto candidate : wordmap[len])
                {
                    if (isomorph(word, candidate))
                    {
                        bool valid = true;
                        for (int i = 0; i < len; i++)
                        {
                            if ((charmap[word[i]] != -1) && charmap[word[i]] != candidate[i])
                            {
                                valid = false;
                                break;
                            }
                        }
                        if (valid)
                        {
                            count++;
                            ok = candidate;
                        }
                    }
                }
                if (count == 1)
                {
                    wordok[word] = ok;
                    for (int i = 0; i < len; i++)
                    {
                        int c = word[i];
                        int d = ok[i];
                        charmap[c] = d;
                    }
                    new_words = true;
                }
            }
        }
    } while (new_words);

    for (int i = 0; i < 256; i++)
    {
        if (charmap[i] != -1)
        {
            cerr << (char)i << " -> " << (char)charmap[i] << endl;
        }
    }

    for (auto word : words)
    {
        string output;
        for (int i = 0; i < word.length(); i++)
        {
            int c = word[i];
            if (charmap[c] != -1)
            {
                output += charmap[c];
            }
            else
            {
                output += '?';
            }
        }
        cout << output << " ";
    }

    return 0;
}

