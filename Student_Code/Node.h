/*
 * Node.h
 *
 *  Created on: Nov 3, 2016
 *      Author: msivraj
 */
#include"NodeInterface.h"

#ifndef STUDENT_CODE_NODE_H_
#define STUDENT_CODE_NODE_H_

namespace std {

class Node: public NodeInterface {
private:
	int data;
	NodeInterface*left;
	NodeInterface* right;
	NodeInterface* parent;
public:
	Node(int dataIn);
	virtual ~Node();

	NodeInterface* getParent();
	void setParent(NodeInterface* parIn);
	void setLeft(NodeInterface* leftIn);
	void setRight(NodeInterface* rightIn);
	virtual int getData();
	virtual NodeInterface * getLeftChild();
	virtual NodeInterface * getRightChild();
};

} /* namespace std */

#endif /* STUDENT_CODE_NODE_H_ */
