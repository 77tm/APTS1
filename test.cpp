#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int main()
{
    int wordCount = 0;
    char letter;
    char firstLetter;
    string word;
    int listNumber = 0;

    ifstream fin("post.in", ios::in);    // ievades fails
    ofstream fout("post.out", ios::out); // izvades fails

    list<string> lists[26]; // izveidojam stl list katram alfabeta burtam

    while (fin >> word)
    {
        firstLetter = word[0];
        listNumber = tolower(firstLetter) - 'a'; // izmantojam ASCII tabulas vertibas, lai iedotu listiem savu kartas nr.
        lists[listNumber].push_front(word);      // liekam prieksa, lai izdrukajot sanaktu preteja seciba, kada notika ievade
        wordCount++;
    }

    if (wordCount == 0)
    {
        fout << "nothing";
    }
    else
    {
        for (int i = 0; i < 26; i++) // for loop iet cauri katram no alfabeta burta listiem un izdruka to saturu secigi
        {
            letter = 'a' + i;
            for (string word : lists[i])
            {
                fout << word << " ";
            }
        }
    }

    fin.close(); // aizveram abus failus
    fout.close();

    return 0;
}