/*
 * BSTree.h
 *
 *  Created on: Nov 3, 2016
 *      Author: msivraj
 */
#include "NodeInterface.h"
#include "Node.h"
#include "BSTInterface.h"
#ifndef STUDENT_CODE_BSTREE_H_
#define STUDENT_CODE_BSTREE_H_

namespace std {

class BSTree: public BSTInterface {
private:
	NodeInterface* root = NULL;
	NodeInterface* curr = NULL;
public:
	BSTree();
	virtual ~BSTree();

	bool addRecursion(NodeInterface* nodeIn, int dataIn);

	NodeInterface* getLeftMostChild(NodeInterface* nodeIn);

	NodeInterface* getRightMostChild(NodeInterface* nodeIn);

	void coutList();

	void printList(NodeInterface* nodeIn);

	NodeInterface* getInorderPredecessor(NodeInterface* nodeIn);

	void clearByRecursion(NodeInterface* nodeIn);

	NodeInterface* find(int data, NodeInterface* nodeIn);

	virtual NodeInterface * getRootNode();

	virtual bool add(int data);

	virtual bool remove(int data);

	virtual void clear();

};

} /* namespace std */

#endif /* STUDENT_CODE_BSTREE_H_ */
