// ============================================================
// CSCI 232 Assignment 05 – Evolution of Data Structures
// Student Implementation
// ============================================================
// Author: Nolan Wedlake
// ============================================================

#include "code.hpp"
#include <iostream>
#include <format>
#include <string>
using namespace std;

std::string AUTHOR_NAME       = "Nolan Wedlake";
std::string AUTHOR_AUTHORSHIP = "I acknowledge that I have worked on this assignment independently...";
// ============================================================
// STAGE 0: Legacy C Union
// ============================================================

/// Converts a LegacyData union to a formatted string.
/// Format specs:
/// 'i' -> integer value as string (e.g., "42")
/// 'd' -> double value formatted to 2 decimal places (e.g., "3.14")
/// 'c' -> string pointer content (or "nullptr" if cPtr is null)
/// default -> "unknown"

std::string printLegacyData(LegacyData data, char type) {
    if (type == 'i') {
        string result = std::format("{}", data.i);
        return result;
    }
    if (type == 'c') {
        if (data.cPtr == NULL) {
            string result = std::format("{}", data.cPtr);
            return result;
        }
    }
    if (type == 'd'){
        string result = std::format("{}", data.d);
        return result;
    }
    return "";
}

// ============================================================
// STAGE 1: C-Style Struct
// ============================================================

/// Initializes a structNode with value, type indicator, and nullptr nextPtr.
void initStructNode(structNode* nPtr, LegacyData val, char type) {
    if (nPtr == nullptr) {
        return;
    }
    nPtr->value = val;
    nPtr->typeData = type;
    nPtr->nextPtr = NULL;
    
}

/// Dynamically allocates two structNodes.
/// Node 1: int 5 ('i')
/// Node 2: double 3.14 ('d')
/// Links Node 1 -> Node 2 -> nullptr
/// Returns pointer to Node 1.
structNode* createTwoStructNodes() {
    // TODO: Allocate dynamically using new, initialize both nodes, link them, and return head
    structNode *a = new structNode;
    structNode *b = new structNode;
    LegacyData c;
    LegacyData d;
    
    c.i = 5;
    d.d = 3.14;
    initStructNode(a, c, 'i');
    initStructNode(b, d, 'd');

    a->nextPtr = b;

    return a;
}

// ============================================================
// STAGE 2: Early C++ Class (Classic Constructor)
// ============================================================

/// Constructor: Assign fields inside curly braces.
/// DO NOT use member initializer lists here!

// uncomment the following code to implement the classNode constructor

 classNode::classNode(LegacyData val, char type) {
    if (type == 'i') {
        value.i = val.i;
    }
    if (type == 'd') {
        value.d = val.d;
    }
    if (type == 'c') {
        value.cPtr = val.cPtr;
    }
    typeData = type;
    nextPtr = NULL;
}

/// Dynamically allocates two classNodes (int 5, double 3.14) and links them.
classNode* createTwoClassNodes() {
    LegacyData x;
    x.i = 5;
    classNode *a = new classNode(x, 'i');

    LegacyData y;
    y.d = 3.14;
    classNode *b = new classNode(y, 'd');
    a->nextPtr = b;
    return a;
}

// ============================================================
// STAGE 3: C++98 Templates
// ============================================================

/// Dynamically allocates two classNodeT<int> objects (int 5, int 3) and links them.
classNodeT<int>* createTwoTemplateNodes() {
    classNodeT<int> *f = new classNodeT<int>(5);
    classNodeT<int> *g = new classNodeT<int>(3);
    f->nextPtr = g;
    return f;
}

// ============================================================
// STAGE 4: C++17 Variant and LinkedList Manager
// ============================================================

// uncomment the following code to implement the LinkedList methods

LinkedList::LinkedList() {
    headPtr = nullptr;
    counter = 0;
}

LinkedList::~LinkedList() {
    destroyList();

}
//uncoment the following code to implement the LinkedList methods

void LinkedList::destroyList() {
    while (headPtr != NULL) {
        classNodeVariant *temp = headPtr->nextPtr;
        delete headPtr;
        headPtr = temp;
    }
    counter = 0;
}

int LinkedList::addFirst(classNodeVariant* newNodePtr) {

    if (newNodePtr == NULL) {
        return -1;
    }
    newNodePtr->nextPtr = headPtr;
    headPtr = newNodePtr;
    counter++;
    return 0;
}

int LinkedList::addLast(classNodeVariant* newNodePtr) {
    if (newNodePtr == NULL) {
        return -1;
    }    
    if (headPtr == NULL) {
        return addFirst(newNodePtr);

    }

    classNodeVariant *current = headPtr;
    while (current != NULL && current->nextPtr != NULL) {
        current = current->nextPtr;
    }
    current->nextPtr = newNodePtr;
    counter++;
    return 0;
}

int LinkedList::deleteFirst() {
    if (headPtr == NULL) {
        return -1;
    }
    classNodeVariant *temp = headPtr->nextPtr;
    delete(headPtr);
    headPtr = temp;
    counter--;
    return 0;
}

int LinkedList::deleteLast() {
    if (headPtr == NULL) {
        return -1;
    }

    while (headPtr->nextPtr->nextPtr != NULL) {
        headPtr = headPtr->nextPtr;
    }
    delete headPtr->nextPtr;
    counter--;
    return 0;
}

int LinkedList::deleteValue(ModernData targetValue) {
    if (headPtr == NULL) {
        return -1;
    }

    if (headPtr->nextPtr == NULL && headPtr->value == targetValue) {
        delete headPtr->nextPtr;
        counter--;
        return 0;
    }

    classNodeVariant *a = headPtr;
    classNodeVariant *b = a->nextPtr;

    while (a != NULL && b->value != targetValue && b->nextPtr != NULL) {
        a = a->nextPtr;
        b = b->nextPtr;
    }

    if (b->value == targetValue) {
        classNodeVariant *c = b->nextPtr;
        delete b;
        a->nextPtr = c;
        counter--;
        return 0;
    }
    return -1;
}

int LinkedList::printList() {
    if (headPtr == NULL) {
        return -1;
    }

    classNodeVariant *current = headPtr;
    while (current != NULL) {
        if (std::holds_alternative<int>(current->value)) {
            std::cout << std::get<int>(current->value) << " ";
        }
        else if (std::holds_alternative<double>(current->value)) {
            std::cout << std::get<double>(current->value) << " ";
        }
        else if (std::holds_alternative<std::string>(current->value)) {
            std::cout << std::get<std::string>(current->value) << " ";
        }
        current = current->nextPtr;
    }
    //std::cout << std::endl;
    return 0;
}

int LinkedList::listLength() {
    return counter;
}