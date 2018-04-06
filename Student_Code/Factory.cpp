#include "Factory.h"
#include "BSTree.h"
//You may add #include statements here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getBST()

	Creates and returns an object whose class extends BSTInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "BST", you might say, "return new BST();".
*/
BSTInterface * Factory::getBST()
{
	return new BSTree; //Modify this line
}

//int main() {
//    BSTree tree;
//    tree.add(8);
//    tree.add(4);
//    tree.add(12);
//    tree.add(2);
//
//    tree.add(6);
//    tree.add(10);
//
//    tree.add(14);
//    tree.add(1);
//    tree.add(3);
//    tree.add(5);
//    tree.add(7);
//    tree.add(9);
//
//    tree.add(11);
//    tree.add(13);
//    tree.add(15);
//
//    tree.add(8);
//    tree.add(4);
//    tree.add(12);
//    tree.add(2);
//    tree.add(6);
//    tree.add(10);
//
//    tree.add(14);
//    tree.add(1);
//    tree.add(3);
//    tree.add(5);
//    tree.add(7);
//    tree.add(9);
//
//    tree.add(11);
//    tree.add(13);
//    tree.add(15);
//    tree.clear();
//    NodeInterface* root = tree.getRootNode();
//    cout << "ROOT NODE" << root->getData();
//
//    //tree.coutList();
//    return 0;
//}
//
