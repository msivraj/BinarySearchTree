/*
 * BSTree.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: msivraj
 */

#include "BSTree.h"

namespace std {

BSTree::BSTree() {
	// TODO Auto-generated constructor stub

}

BSTree::~BSTree() {
	clear();
}

bool BSTree::addRecursion(NodeInterface* nodeIn, int dataIn) {
	curr = nodeIn;
	if (root == NULL) {
		Node* aNode = new Node(dataIn);
		root = aNode;
		return true;
	}
	if (dataIn > curr->getData()) {
		if(curr->getRightChild() == NULL)
		{
			Node* aNode = new Node(dataIn);
			aNode->setParent(curr);
			((Node*) curr)->setRight(aNode);
			return true;
		}
		else { //dataIn > curr->getData() && curr->getRightChild()!=NULL
			addRecursion(curr->getRightChild(), dataIn);
		}
		
	}
	else if (dataIn < curr->getData()) {
		if (curr->getLeftChild() == NULL) {
			Node* aNode = new Node(dataIn);
			aNode->setParent(curr);
			((Node*) curr)->setLeft(aNode);
			return true;
		}

		else {
			addRecursion(curr->getLeftChild(), dataIn);
		}
	}
	else {
		return false;
	}


}



NodeInterface* BSTree::getRightMostChild(NodeInterface* nodeIn) {
	NodeInterface* iterator = nodeIn;
	if (iterator->getRightChild() != NULL) {
		iterator = getRightMostChild(iterator->getRightChild());

	}
	return iterator;
}

NodeInterface* BSTree::getLeftMostChild(NodeInterface* nodeIn) {
	NodeInterface* iterator = nodeIn;
	if (iterator->getLeftChild() != NULL) {
		getRightMostChild(iterator->getLeftChild());
	}
	return iterator;
}

void BSTree::coutList() {
	printList(root);
}

void BSTree::printList(NodeInterface* nodeIn) {
	NodeInterface* iterator = nodeIn;
	NodeInterface* iteratorParent;
	if (iterator->getLeftChild() != NULL) {
		//iteratorParent = iterator;
		printList(iterator->getLeftChild());
	}

	else if (iterator->getRightChild() != NULL) { //case of rightchild
		//iteratorParent = iterator;
		printList(iterator->getRightChild());
	}

	else { //case of no rightchild
		   //if (iterator->getRightChild() == NULL)
		//	NodeInterface* deleteIterator = iterator;
		iteratorParent = ((Node*) iterator)->getParent();
		//	delete deleteIterator;
		cout << iterator->getData();
		printList(iteratorParent);

}

}
NodeInterface * BSTree::getInorderPredecessor(NodeInterface* nodeIn) {

	//if (nodeIn->getData() > root->getData()) {
	if (nodeIn == root && nodeIn->getLeftChild() == NULL) {
		return nodeIn;
	}
		nodeIn = nodeIn->getLeftChild();
	if (nodeIn->getRightChild() == NULL)
	{
		return nodeIn;
	}
//		while (nodeIn->getRightChild() != NULL) {
//		nodeIn = nodeIn->getRightChild();
//		}
	NodeInterface* rightMostNode = getRightMostChild(nodeIn);
	return rightMostNode;	//nodeIn
	//}
//		else if (nodeIn->getData() < root->getData()) {
//		nodeIn = nodeIn->getRightChild();
//		while (nodeIn->getLeftChild() != NULL) {
//			nodeIn = nodeIn->getLeftChild();
//		}
//		return nodeIn;
//	}
}



void BSTree::clearByRecursion(NodeInterface* nodeIn) {
	if (root == NULL) {
		return;
	}
	NodeInterface* iterator = nodeIn;
	NodeInterface* iteratorParent; //= ((Node*) iterator)->getParent();
	NodeInterface* deleteIterator = iterator;
	if (deleteIterator->getData() == 8) {
		cout << "your error is imminent";
	}
	cout << nodeIn->getData() << "\n";
	if (iterator->getLeftChild() != NULL) {
		//iteratorParent = iterator;
		clearByRecursion(iterator->getLeftChild());
	}

	else if (iterator->getRightChild() != NULL) { //case of rightchild
		//iteratorParent = iterator;
		clearByRecursion(iterator->getRightChild());
	}

	else { //case of no rightchild
	//if (iterator->getRightChild() == NULL)
		NodeInterface* deleteIterator = iterator;
		iteratorParent = ((Node*) iterator)->getParent();
		if (iteratorParent == NULL) {
			((Node*) deleteIterator)->setLeft(NULL);
			((Node*) deleteIterator)->setRight(NULL);
			((Node*) deleteIterator)->setParent(NULL);
			cout << "DELETE VALUE" << deleteIterator->getData() << "\n";
			delete deleteIterator;
			curr = NULL;
			root = NULL;
			return;

		}
		if (iteratorParent->getRightChild() == deleteIterator) {
			((Node*) iteratorParent)->setRight(NULL);
		} else {
			((Node*) iteratorParent)->setLeft(NULL);
		}
		((Node*) deleteIterator)->setParent(NULL);
		((Node*) deleteIterator)->setRight(NULL);
		((Node*) deleteIterator)->setLeft(NULL);
		cout << "DELETE VALUE" << deleteIterator->getData() << "\n";
		delete deleteIterator;
		
		clearByRecursion(iteratorParent);

	}


}

NodeInterface* BSTree::find(int data, NodeInterface* nodeIn) {
	cout
			<< "------------------------------------------------------------------find-------------------------------------";
	cout << "FIND DATA" << data << " :: "
			<< (nodeIn == NULL ? -1 : nodeIn->getData()) << "\n";
	if (nodeIn == NULL) {
		return NULL;
	}
	//curr = root;
	if (data == nodeIn->getData()) {
		return nodeIn;
	}
	else if (nodeIn->getData() < data) {
		return find(data, nodeIn->getRightChild());
	}
	else {
		return find(data, nodeIn->getLeftChild());
	}
	

}

/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
NodeInterface *BSTree::getRootNode() {
	cout
			<< "------------------------------------------------------------------getroot-------------------------------------";
	cout << "ROOT : " << (root == NULL ? -1 : root->getData()) << "\n";
	return root;
}

/*
 * Attempts to add the given int to the BST tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
bool BSTree::add(int data) {
//	curr == root;
//	if (root == NULL) {
//		Node* aNode = new Node(data);
//		root = aNode;
//		return true;
//	}
//	while (true) {
//	if (data > curr->getData()) {
//			if (curr->getRightChild() == NULL) {
//				Node* aNode = new Node(data);
//				aNode->setParent(curr);
//				((Node*) curr)->setRight(aNode);
//				return true;
//			}
//			curr = curr->getRightChild();
//
//		} else if (data < curr->getData()) {
//
//// put in logic for a variable
////			Node* parent=curr;
////			curr=curr->getLeftChild();
////			 if(curr==NULL)
////			{
////			 Node* aNode = new Node(data);
////			 aNode->setParent(parent);
////			 parent->setLeft(aNode);
////			}
//
//			if (curr->getLeftChild() == NULL) {
//				Node* aNode = new Node(data);
//				aNode->setParent(curr);
//				((Node*) curr)->setLeft(aNode);
//				return true;
//			}
//			curr = curr->getLeftChild();
//		} else {
//			// (data == curr->getData()) {
//			return false;
//		}
//	}
	cout
			<< "---------------------------------------------------------------------------add-------";
	cout << data << "\n";
	return addRecursion(root, data);

}

/*
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 *
 * REMOVE FUNCTION FROM BOOK
 * the functionality of your remove is almost the same the only difference is that you need to assign the parent of the removal node to the inorder predecessor
 * and not the leftchild of the node to remove. also you need to implement the first two ifs in the algorithm below, if there is no tree, if there is only three
 * nodes in the tree, a root with left and right child. I might have taken care already of these previous two cases but just saying if the removal node is a leaf
 * just remove it.
 *
 * if the root is NULL
 * 		the item is not in tree Return NULL
 * 	compare the item to the data at the local root
 *
 * 	if the item is less than the data at the local root
 * 		return the result of deleting from the tree
 *
 * 	else if the item is greater than the local root
 * 		return the result of deleting from the right subtree
 *
 * 	else (the item is in the local root)
 * 		if the local root has no children
 * 			set the parent of the local root to reference NULL
 *
 * 		else if the local root has one child
 * 			set the parent of the local root to reference that child
 *
 * 		else (find the inorder predecessor)
 * 			if the left child has no right child
 * 				it is the inorder predecessor
 *
 * 			else
 * 				find the rightmost node in the right subtree of the left child
 * 				copy its data into the local root's data and remove it by setting its parent to reference its left child
 */
bool BSTree::remove(int data) {
	if (data == 8) {
		//	cout << "this is where you stop";
	}
	cout
			<< "------------------------------------------------------------------remove-------------------------------------";
	cout << "REMOVE DATA" << data << "\n";
	NodeInterface* removalNode = find(data, root);
	if (root == NULL || removalNode == NULL) {
		return false;
	}
	NodeInterface* removalNodeParent = ((Node*) removalNode)->getParent();
	NodeInterface* removalRightChild = removalNode->getRightChild();
	NodeInterface* removalLeftChild = removalNode->getLeftChild();


	if (removalNode->getLeftChild() == NULL
			&& removalNode->getRightChild() == NULL) { // if node to remove is a leaf or zero children SET PARENT LEFT OR RIGHT WHICH EVER SIDE IT IS DELETED FROM TO NULL


		if (removalNodeParent == NULL) {
			root = NULL;
		}
		else if (removalNodeParent->getLeftChild() == removalNode) {
			((Node*) removalNodeParent)->setLeft(NULL);

		} else {
			((Node*) removalNodeParent)->setRight(NULL);
		}
		delete removalNode;
		return true;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////case for one child method two
	else if (removalNode->getLeftChild() == NULL
			|| removalNode->getRightChild() == NULL) { // case is for one child
		if (removalNode->getData()
				== root->getData() && removalRightChild == NULL) {
			NodeInterface* dummyRoot = root;
			root = dummyRoot->getLeftChild();
			((Node*) root)->setParent(NULL);
			delete dummyRoot;
			return true;
		} else if (removalNode->getData()
				== root->getData() && removalLeftChild==NULL)
		{
			NodeInterface* dummyRoot = root;
			root = dummyRoot->getRightChild();
			((Node*) root)->setParent(NULL);
			delete dummyRoot;
			return true;
		}
		else if (removalNodeParent->getData() > removalNode->getData()) {
			if (removalLeftChild == NULL) {
				((Node *) removalNodeParent)->setLeft(removalRightChild);
				((Node*) removalRightChild)->setParent(removalNodeParent);
			} else { //removalNode->getRightChild == NULL
				((Node*) removalNodeParent)->setLeft(removalLeftChild);
				((Node*) removalLeftChild)->setParent(removalNodeParent);
			}
		} else { //removalNodeParent->getData < removalNode->getData
			if (removalLeftChild == NULL) {
				((Node*) removalNodeParent)->setRight(removalRightChild);
				((Node*) removalRightChild)->setParent(removalNodeParent);
			} else { //removalRightChild==NULL
			((Node*) removalNodeParent)->setRight(removalLeftChild);
			((Node*) removalLeftChild)->setParent(removalNodeParent);
			}
		}
	delete removalNode;
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////case for two children method two fix probems
	else {
		NodeInterface* inorderPredecessor = getInorderPredecessor(removalNode);
		NodeInterface* inorderPredecessorLeftChild =
				inorderPredecessor->getLeftChild();
		NodeInterface* inorderPredecessorParent =
				((Node*) inorderPredecessor)->getParent();
		if (removalNode->getData() == root->getData()) {
			NodeInterface* deleteRoot = root;

			if (inorderPredecessorParent
					== deleteRoot&& inorderPredecessorLeftChild == NULL) {
				//NodeInterface* inorderPredecessorRightChild =
				//inorderPredecessor->getRightChild();
				//root = inorderPredecessorRightChild;
				//((Node*) inorderPredecessorRightChild)->setParent(NULL);
				root = inorderPredecessor;
				((Node*) root)->setRight(removalRightChild);
				((Node*) removalRightChild)->setParent(root);
				((Node*) root)->setParent(NULL);

			}

			else if (inorderPredecessorLeftChild == NULL) {
				root = inorderPredecessor;
				((Node*) root)->setParent(NULL);
				//((Node*) removalNodeParent)->setLeft(inorderPredecessor);
				//((Node*) inorderPredecessor)->setParent(removalNodeParent);
				((Node*) removalLeftChild)->setParent(inorderPredecessor);
				((Node*) inorderPredecessor)->setLeft(removalLeftChild);
				((Node*) removalRightChild)->setParent(inorderPredecessor);
				((Node*) inorderPredecessor)->setRight(removalRightChild);
				((Node*) inorderPredecessorParent)->setRight(NULL);
			}
			else if (inorderPredecessorLeftChild != NULL
					&& inorderPredecessorParent == removalNode) {
				NodeInterface* deleteRootRightChild =
						deleteRoot->getRightChild();
				root = inorderPredecessor;
				((Node*) root)->setParent(NULL);
				((Node*) root)->setRight(deleteRoot->getRightChild());
				((Node*) deleteRootRightChild)->setParent(root);

			} else {
				root = inorderPredecessor;
				((Node*) root)->setParent(NULL);
				((Node*) removalLeftChild)->setParent(inorderPredecessor);
				((Node*) inorderPredecessor)->setLeft(removalLeftChild);
				((Node*) removalRightChild)->setParent(inorderPredecessor);
				((Node*) inorderPredecessor)->setRight(removalRightChild);
				((Node*) inorderPredecessorParent)->setRight(NULL);
				((Node*) inorderPredecessorLeftChild)->setParent(
						inorderPredecessorParent);
				((Node*) inorderPredecessorParent)->setRight(
						inorderPredecessorLeftChild);
			}
			delete deleteRoot;
			return true;

		}
		
//		((Node*) getInorderPredecessor)->setRight(NULL);
		//if (removalNodeParent->getData() > removalNode->getData()) {
	else {
		((Node*) removalNodeParent)->setLeft(inorderPredecessor);
		((Node*) inorderPredecessor)->setParent(removalNodeParent);
		((Node*) removalLeftChild)->setParent(inorderPredecessor);
		((Node*) inorderPredecessor)->setLeft(removalLeftChild);
		((Node*) removalRightChild)->setParent(inorderPredecessor);
		((Node*) inorderPredecessor)->setRight(removalRightChild);
		if (inorderPredecessorLeftChild != NULL) {
			((Node*) inorderPredecessorLeftChild)->setParent(
					removalLeftChild);
			((Node*) removalLeftChild)->setRight(inorderPredecessorLeftChild);
		}
	}


		//}
		//else { //removalNodeParent->getData<removalNode->getData
//			((Node*) removalNodeParent)->setRight(inorderPredecessor);
//			((Node*) inorderPredecessor)->setParent(removalNodeParent);
//		}

//		else (find the inorder predecessor)
//		 * 			if the left child has no right child
//		 * 				it is the inorder predecessor
//		 *
//		 * 			else
//		 * 				find the rightmost node in the right subtree of the left child
//		 * 				copy its data into the local root's data and remove it by setting its parent to reference its left child
		delete removalNode;
		return true;
	}
	return false;
}

/*
 * Removes all nodes from the tree, resulting in an empty tree.
 */
void BSTree::clear() {
	cout
			<< "------------------------------------------------------------------clear-------------------------------------\n";
//	cout
//	<< "?????????????????????????????????????????????? clear ??????????????????????????????????????????????????????????\n";
//	NodeInterface* dummyDelete = root;
//	int theSize = size();
//	while (theSize != 0) {
//		head = head->getNext();
//		delete dummyDelete;
//		dummyDelete = head;
//		theSize--;
//	}
//	//delete head;
//	head = NULL;
//	tail = NULL;
//	current = NULL;
	clearByRecursion(root);

}

} /* namespace std */

//	g++ -g -Wall -std=c++14 -o "dont_run_me" /home/msivraj/Documents/semester3/cs235/lab6BST/Student_Code/Node.cpp /home/msivraj/Documents/semester3/cs235/lab6BST/Student_Code/BSTree.cpp /home/msivraj/Documents/semester3/cs235/lab6BST/Student_Code/Factory.cpp /home/msivraj/Documents/semester3/cs235/lab6BST/ignoreme.a

