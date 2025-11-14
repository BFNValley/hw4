#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    list<string> words;
    Node *left, *right;
    int height;
};

class ListTree
{
    private:
        Node* root;
        int TreeHeight;

    public:
        ListTree();
        ~ListTree();
        void Destroy(Node* node);
        bool Find(string word, list<char> setOne, list<char>setTwo);
        void Insert(string word, vector<char> setOne, vector<char>setTwo, int maxLength);
        void Print(string pattern, char labelOne, char labelTwo, ofstream& fout);
};

ListTree::ListTree()
{
    root = new Node();
    root->left = nullptr;
    root->right = nullptr;
}

ListTree::~ListTree()
{
    Destroy(root);
}

void ListTree::Destroy(Node* node)
{
    if(node != nullptr)
    {
        Destroy(node->left);
        Destroy(node->right);
        delete node;
    }
}

bool ListTree::Find(string word, list<char> setOne, list<char>setTwo)
{
    return false;
}

void ListTree::Insert(string word, vector<char> setOne, vector<char>setTwo, int maxLength)
{
    Node* currentNode = root;
    Node* splitNode = currentNode;

    if(word.length() > maxLength)
    {
        return;
    }

    while(currentNode != nullptr)
    {
        for(int i = 0; i < word.length(); i++)
        {
            for(int j = 0; j < setOne.size(); j++)
            {
                if(word[i] == setOne[j])
                {
                    /*
                    for(int k = 0; k < setTwo.size(); k++)
                    {
                        if(word[i] == setTwo[k])
                        {
                            if(currentNode->right == nullptr)
                            {
                                Node* newNode = new Node;
                                currentNode->right = newNode;
                                splitNode = currentNode->right;
                            }
                            else
                            {
                                splitNode = currentNode->right;
                            }
                        }
                    }
                    */
                    if(currentNode->left == nullptr)
                    {
                        Node* newNode = new Node;
                        currentNode->left = newNode;
                        currentNode=currentNode->left;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
            }


            for(int j = 0; j < setTwo.size(); j++)
            {
                if(word[i] == setTwo[j])
                {
                    if(currentNode->right == nullptr)
                    {
                        Node* newNode = new Node;
                        currentNode->right = newNode;
                        currentNode = currentNode->right;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
            }
        }
        currentNode->words.push_back(word);
        currentNode = nullptr;
    }

}

void ListTree::Print(string pattern, char labelOne, char labelTwo, ofstream& fout)
{
    Node* currentNode = root;
    for(int i = 0; i < pattern.length(); i++)
    {
        if(pattern[i] == labelOne)
        {
            currentNode = currentNode->left;
        }
        if(pattern[i] == labelTwo)
        {
            currentNode = currentNode->right;
        }
    }
    if(currentNode == nullptr)
    {
        cout << "No Matching Words";
        fout << "No Matching Words";
    }
    else
    {
        for(auto it = currentNode->words.begin(); it != currentNode->words.end(); it++)
        {
            if(next(it) == currentNode->words.end())
            {
                cout << *it;
                fout << *it;
            }
            else
            {
                cout << *it << ", ";
                fout << *it << ", ";
            }
            
        }
    }

}
