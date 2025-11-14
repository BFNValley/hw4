#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include "BinaryTree.h"
#include "ListTree.h"
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream fin(am.get("input"));
    ofstream fout(am.get("output"));
    //ifstream fin("input3.txt");
    //ofstream fout("output3.txt");
    ifstream yawl("yawl.txt");


    int maxWordLength = 0;
    vector<char> setOne;
    vector<char> setTwo;
    ListTree listtree;

    //Take in first two lines, Create 2 sets of characters based off input
    string lineOne;
    getline(fin, lineOne);
    char labelOne = lineOne[0];
    for(int i = 2; i < lineOne.length(); i++)
    {
        if(lineOne[i] != ',' && lineOne[i] != ' ')
        {
            setOne.push_back(lineOne[i]);
        }
    }

    string lineTwo;
    getline(fin,lineTwo);
    char labelTwo = lineTwo[0];
    for(int i = 2; i < lineTwo.length(); i++)
    {
        if(lineTwo[i] != ',' && lineTwo[i] != ' ')
        {
            setTwo.push_back(lineTwo[i]);
        }
    }
    int count = 1;
    string patternLine;
    while(getline(fin, patternLine))
    {
        string pattern = patternLine.substr(3, patternLine.length() -1);
        if(pattern.length() > maxWordLength)
        {maxWordLength = pattern.length();}

        string currentWord;
        while(yawl >> currentWord)
        {
            listtree.Insert(currentWord, setOne, setTwo, maxWordLength);
        }

        cout << count << ". ";
        fout << count << ". ";
        listtree.Print(pattern, labelOne, labelTwo, fout);
        cout << endl;
        fout << endl;
        count++;
        //cout << pattern << endl;
        //cout << maxWordLength << endl;
    }



/*
    for(char value : setOne)
    {
        cout << value << ", ";
    }
    cout << endl;
    for(char value : setTwo)
    {
        cout << value << ", ";
    }
*/

/*
    
    string currentWord;
    while(yawl >> currentWord)
    {
        listtree.Insert(currentWord, setOne, setTwo);
    }
*/

    return 0;
}
