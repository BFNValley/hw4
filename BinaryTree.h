#pragma once
#include <iostream>
#include <ostream>
using namespace std;

template<typename T>
struct TreeNode {
    T value;
    TreeNode<T>* parent, *left, *right;
};

template<typename T>
class BinaryTree {
public:
    BinaryTree();                     // Default Constructor
    ~BinaryTree();                    // Destructor
    void Destroy(TreeNode<T>* node);

    void Insert(T value);            // Add a value into the tree
    bool Find(T value);              // Return true if the value is found
    bool IsEmpty();                  // True if the list is currently empty
    void Preorder(ostream& out);     // Output the pre-order traversal
    void Inorder(ostream& out);      // Output the in-order traversal
    void Postorder(ostream& out);    // Output the post-order traversal
    bool Remove(T value);            // Find the value and remove the value; true if successful

private:
    TreeNode<T>* root;                   // Root pointer
    void PreorderHelp(ostream& out, TreeNode<T>* node);
    void InorderHelp(ostream& out, TreeNode<T>* node);
    void PostorderHelp(ostream& out, TreeNode<T>* node);
};

template<typename T>
BinaryTree<T>::BinaryTree()
{
   root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
   Destroy(root);
}

template<typename T>
void BinaryTree<T>::Destroy(TreeNode<T>* node)
{
   if(node != nullptr)
   {
      Destroy(node->left);
      Destroy(node->right);
      delete node;
   }
}

template<typename T>
void BinaryTree<T>::Insert(T value)
{
   TreeNode<T>* newNode = new TreeNode<T>;
   newNode->value = value;
   newNode->left = nullptr;
   newNode->right = nullptr;
   newNode->parent = nullptr;
   
   if (root == nullptr)
   {
      root = newNode;
   }
   else
   {
      TreeNode<T>* currentNode = root;
      while(currentNode != nullptr)
      {
         if(newNode->value < currentNode->value)
         {
            if(currentNode->left == nullptr)
            {
               currentNode->left = newNode;
               currentNode = nullptr;
            }
            else
            {
               currentNode = currentNode->left;
            }
         }
         else
         {
            if(currentNode->right == nullptr)
            {
               currentNode->right = newNode;
               currentNode = nullptr;
            }
            else
            {
               currentNode = currentNode->right;
            }
         }
      }
   }
}

template<typename T>
bool BinaryTree<T>::Find(T value)
{
   TreeNode<T>* currentNode = root;
   
   while(currentNode != nullptr)
   {
      if(value == currentNode->value)
      {
         return true;
      }
      else
      {
         if(value < currentNode->value)
         {
            currentNode = currentNode->left;
         }
         else
         {
            currentNode = currentNode->right;
         }
      }
   }
   return false;
}

template<typename T>
bool BinaryTree<T>::IsEmpty()
{
   if(root == nullptr)
   {return true;}
   return false;
}

template<typename T>
void BinaryTree<T>::Preorder(ostream& out)
{
   out << "Preorder:" << endl;
   PreorderHelp(out, root);
   out << endl;
}

template<typename T>
void BinaryTree<T>::PreorderHelp(ostream& out, TreeNode<T>* node)
{
   if(node != nullptr)
   {
      out << node->value << " ";
      PreorderHelp(out, node->left);
      PreorderHelp(out, node->right);
   }
}

template<typename T>
void BinaryTree<T>::Inorder(ostream& out)
{
   out << "Inorder:" << endl;
   InorderHelp(out, root);
   out << endl;
}

template<typename T>
void BinaryTree<T>::InorderHelp(ostream& out, TreeNode<T>* node)
{
   if(node != nullptr)
   {
      InorderHelp(out, node->left);
      out << node->value << " ";
      InorderHelp(out, node->right);
   }
}

template<typename T>
void BinaryTree<T>::Postorder(ostream& out)
{
   out << "Postorder:" << endl;
   PostorderHelp(out, root);
   out << endl;
}

template<typename T>
void BinaryTree<T>::PostorderHelp(ostream& out, TreeNode<T>* node)
{
   if(node != nullptr)
   {
      PostorderHelp(out, node->left);
      PostorderHelp(out, node->right);
      out << node->value << " ";
   }
}

template<typename T>
bool BinaryTree<T>::Remove(T value)
{
   TreeNode<T>* currentNode = root;
   TreeNode<T>* parent = nullptr;
   
   while(currentNode != nullptr)
   {
      if(currentNode->value == value)
      {
         if(currentNode->left == nullptr && currentNode->right == nullptr)
         {
            if(parent == nullptr)
            {
               root = nullptr;
            }
            else if (parent->left == currentNode)
            {
               parent->left = nullptr;
            }
            else
            {
               parent->right = nullptr;
            }
            return true;
         }
         else if (currentNode->right == nullptr)
         {
            if(parent == nullptr)
            {
               root = currentNode->left;
            }
            else if (parent->left == currentNode)
            {
               parent->left = currentNode->left;
            }
            else
            {
               parent->right = currentNode->left;
            }
            return true;
         }
         else if (currentNode->left == nullptr)
         {
            if(parent == nullptr)
            {
               root = currentNode->right;
            }
            else if (parent->left == currentNode)
            {
               parent->left = currentNode->right;
            }
            else
            {
               parent->right = currentNode->right;
            }
            return true;
         }
         else
         {
            
            TreeNode<T>* successor = currentNode->right;
            TreeNode<T>* successorParent = currentNode;
            while(successor->left != nullptr)
            {
               successorParent = successor;
               successor = successor->left;
            }
            
            currentNode->value = successor->value;
            
            if (successorParent->left == successor)
               {successorParent->left = successor->right;}
            else
               {successorParent->right = successor->right;}
            
            delete successor;
            return true;
         }
      }
      else if (currentNode->value < value)
      {
         parent = currentNode;
         currentNode = currentNode->right;
      }
      else
      {
         parent = currentNode;
         currentNode = currentNode->left;
      }
   }
   return false;
}