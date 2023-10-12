#include "AVLNode.h"
#ifndef __AVLTree_H
#define __AVLTree_H

template <typename T>
class AVLTree
{
    private:
    AVLNode<T> * RootNode;

    public:
    //Tree constructor
        AVLTree()
        {
            RootNode(nullptr);
        }
    //Tree deconstructor
        ~AVLTree()
        {
            Delete(AVLNode<T> * RootNode);
        }
    //Tree inserter (inserts a singular value into a Tree)
       void AVLInsert(const T & NewNum)
        {
            Insert(NewNum, RootNode);
        }
    //Tree Contains (Searches for a Numer in the Tree and returns 1  if found and 0 if not found)
       int AVLcontains(const T & SearchNum)
        {
            contains(SearchNum, RootNode);
        }
    //Tree Height (finds the max height of the tree)
       int AVLHeight()
       {
        Height(RootNode);
       }
    //Tree Validate (Searches the Tree to see if the Tree is balanced if it is returns 1 if and 0 if not)
       int AVLValidate()
       {
        Validate(RootNode);
       }
       private:

       Delete(AVLNode<T> * Node)
       {
            if(Node == nullptr)
            {
                return;
            }
            Delete(Node->Left);
            Delete(Node->Right);
            delete Node;
       }

       Height(AVLNode<T> * T)
       {
        return T->Height;
       }
// inserts a new node with the inputed num
       Insert(const T & NewNum, AVLNode<T> * & Node)
       {
        if(Node == nullptr)
        {
            Node = new AVLNode<T>(NewNum);
            Node ->Height = 0
        }
        else if(NewNum > Node->Num)
        {
            Insert(NewNum, Node->Right);
        }
        else if(NewNum < Node->Num)
        {
            Insert(NewNum, Node->Left);
        }
        Balance(Node);
       }
//searches the tree to see if a number is contained
       contains(const T & SearchNum, AVLNode<T> * & RootNode)
       {
            int found = 0;
            while(found == 0)
            {
                while(RootNode != nullptr)
                {
                    if(RootNode->Num == SearchNum)
                    {
                        found = 1
                        return 1;
                    }
                    if(RootNode->Num < SearchNum)
                    {
                        RootNode = RootNode->Right;
                    }
                    if(RootNode->Num > SearchNum)
                    {
                        RootNode = RootNode->Left;
                    }
                }
                found = 1;
            }
            return 0;
       }
// finds if there is a Delta bigger then 1 if so then there is an inbalance in the tree
       Validate(AVLNode<T> * & Node)
       {
        int Delta;
        if(Node = nullptr)
        {
            return 0;
        }
        Delta = Height(Node->Left)-Height(Node->Right);
        if(Delta == -1 || Delta ==  0 || Delta == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
       }
//Balance function that calls the rotate functions
       Balance(AVLNode<T> * & Node)
       {
            if(Node == nullptr)
            {
                return 0;
            }
            if(Height(Node->Right) - Height(Node->Left) > 1)
            {
                if(Height(Node->Right->Right) >= Height(Node->Right->Left))
                {
                    Node = Case1Rotate(Node);
                }
                else
                {
                    Node = Case2Rotate(Node);
                }
            }
                if(Height(Node->Left) - Height(Node->Right) > 1)
            {
                if(Height(Node->Left->Left) >= Height(Node->Left->Right))
                {
                    Node = Case4Rotate(Node);
                }
                else
                {
                    Node = Case3Rotate(Node);
                }
            }
        }

//Rotation functions to balance the tree
        AVLNode<T> * Case1Rotate(AVLNode<T> * & Node)
        {
            AVLNode<T> * holder = Node->Right;
            Node->Right = holder->Left;
            holder->Left = Node;
            Node->Height = max(Height(Node->Right), Height(Node->Left))+1;
            holder->Height = mac(Height(holder->Right),Height(Node->Height))+1;
            return holder;
        }
        AVLNode<T> * Case2Rotate(AVLNode<T> * & Node)
        {
            Node->Left = Case1Rotate(Node->Left)
            Node = Case4Rotate(Node);
            return Node;
        }
        AVLNode<T> * Case3Rotate(AVLNode<T> * & Node)
        {
            Node->Right = Case4Rotate(Node->Right)
            Node = Case1Rotate(Node);
            return Node;
        }
        AVLNode<T> * Case4Rotate(AVLNode<T> * & Node)
        {
            AVLNode<T> * holder = Node->Right;
            Node->Left = holder->Right;
            holder->Right = Node;
            Node->Height = max(Height(Node->Left), Height(Node->Right))+1;
            holder->Height = mac(Height(holder->Left),Height(Node->Height))+1;
            return holder;
        }


};


#endif
