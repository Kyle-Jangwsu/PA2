#include "resources.h"
#ifndef __AVLNODE_H
#define __AVLNODE_H

template<typename T>
class AVLNode
{
    public:
        T Num;
        AVLNode * Left;
        AVLNode * Right;
        int Height;
        int NodeCount;

    AVLNode(const T InsertedNumber, AVLNode * NewLeft, AVLNode * NewRight, int H)
    {
        Num = InsertedNumber;
        Left = InsertedLeft;
        Right = NewRight;
        Height = H;
    }

    ~AVLNode()
    {

    }
};
#endif
