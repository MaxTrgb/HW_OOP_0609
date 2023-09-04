#include "Node.h"
Node::Node() {
	value = 0;
	next = nullptr;
}
Node::Node(int value) {
	this->value = value;
	next = nullptr;
}
Node::Node(int value, Node* next, Node* prev) {
	this->value = value;
	this->next = next;
	this->prev = prev;
}
