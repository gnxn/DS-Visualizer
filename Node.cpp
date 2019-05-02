//
// Created by michael on 01/01/19.
//

#include "Node.h"

Node* Node::getLeft() {
    return left;
}

Node* Node::getRight() {
    return right;
}

Node* Node::getParent() {
    return parent;
}

int Node::getWeight() {
    return weight;
}

int Node::getVal() {
    return val;
}

void Node::setVal(int v) {
    val = v;
}

void Node::setLeft(Node *l) {
    left = l;
}

void Node::setRight(Node *r) {
    right = r;
}

void Node::setParent(Node *par) {
    parent = par;
}

void Node::setWeight(int w) {
    weight = w;
}
