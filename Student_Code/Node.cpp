/*
 * Node.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: msivraj
 */

#include "Node.h"

namespace std {

Node::Node(int dataIn) {
	data = dataIn;
	left = NULL;
	right = NULL;
	parent = NULL;
	// TODO Auto-generated constructor stub

}

Node::~Node() {
	left = NULL;
	right = NULL;
	parent = NULL;
}


void Node::setLeft(NodeInterface* leftIn) {
	left = leftIn;
}
void Node::setRight(NodeInterface* rightIn) {
	right = rightIn;
}

NodeInterface* Node::getParent() {
	return parent;
}
void Node::setParent(NodeInterface* parIn) {
	parent = parIn;
}

/*
 * Returns the data that is stored in this node
 *
 * @return the data that is stored in this node.
 */
int Node::getData() {
	return data;
}
/*
 * Returns the left child of this node or null if it doesn't have one.
 *
 * @return the left child of this node or null if it doesn't have one.
 */
NodeInterface* Node::getLeftChild() {
	cout
			<< "------------------------------------------------------------------GETLEFTCHILD-------------------------------------";
	cout << "LEFT : " << (left == NULL ? -1 : left->getData()) << "\n";

	return left;
}

/*
 * Returns the right child of this node or null if it doesn't have one.
 *
 * @return the right child of this node or null if it doesn't have one.
 */
NodeInterface* Node::getRightChild() {
	cout
			<< "------------------------------------------------------------------GETRIGHTCHILD-------------------------------------";
	cout << "RIGHT : " << (right == NULL ? -1 : right->getData()) << "\n";
	return right;
}

} /* namespace std */
