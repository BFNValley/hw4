#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "BinaryTree.h"
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    //ifstream fin(am.get("input"));
    //ofstream fout(am.get("output"));
    ifstream fin("input1.txt");
    ofstream fout("output1.txt");
    ifstream yawl("yawl.txt");


    int maxWordLength;
    list<char> setOne;
    list<char> setTwo;
    //Take in first two lines, Create 2 sets of characters based off input

    string lineOne;
    getline(fin, lineOne);
    for(int i = 2; i < lineOne.length(); i++)
    {
        if(lineOne[i] != ',' && lineOne[i] != ' ')
        {
            setOne.push_back(lineOne[i]);
        }
    }

    string lineTwo;
    getline(fin,lineTwo);
    for(int i = 2; i < lineTwo.length(); i++)
    {
        if(lineTwo[i] != ',' && lineTwo[i] != ' ')
        {
            setTwo.push_back(lineTwo[i]);
        }
    }

    
    for(char value : setOne)
    {
        cout << value << ", ";
    }
    cout << endl;
    for(char value : setTwo)
    {
        cout << value << ", ";
    }
    //Create binary tree of lists, with an empty list for the root
    BinaryTree<list<string>> words;

    //Left Child is words containing 1-letter words from setOne, Right child is 1-letter words from setTwo
    //Each new layer increases word length by one while following this same rule of "left = set1, right = set2"

    //Then populate the lists with their proper entries from the yawl.txt

    //Then read in the next lines, and print out their associated list from the tree
    return 0;
}
