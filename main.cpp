#include "AVLTree.h"


int main()
{
    //Tree 1 = ascending order Tree2 = decending order Tree3 = random
    AVLTree<int> * Tree1;
    AVLTree<int> * Tree2;
    AVLTree<int> * Tree3;
    int counter = 0, Num;
    while (counter != 50)
    {
        Num = rand() % 100;
        Tree3->AVLInsert(Num);
        ++counter;
    }
    counter = 0;
    while(counter != 50)
    {
        Tree1->AVLInsert(counter);
        ++counter;
    }
    counter = 0;
    while(counter != 50)
    {
        Tree1->AVLInsert(50 - counter);
        ++counter;
    }
    cout << "The height of Tree1 is:" << Tree1->AVLHeight() << endl;
    cout << "The height of Tree2 is:" << Tree2->AVLHeight() << endl;
    cout << "The height of Tree3 is:" << Tree3->AVLHeight() << endl;
    //I assume that the height of the Trees should be the same or relatively simillar 
    //All outputs should print 1 because of it already being balanced
    
    cout << "Tree1 Valid?:" << Tree1->AVLValidate() << endl;
    cout << "Tree2 Valid?:" << Tree2->AVLValidate() << endl;
    cout << "Tree3 Valid?:" << Tree3->AVLValidate() << endl;

    counter = 0;
    while(counter != 100)
    {
        Tree1->AVLcontains(counter);
        counter++;
    }
    counter = 0;
    while(counter != 100)
    {
        Tree2->AVLcontains(counter);
        counter++;
    }
    while(counter != 100)
    {
        Tree1->AVLcontains(counter);
        counter++;
    }
}
