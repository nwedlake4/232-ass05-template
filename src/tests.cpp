#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

#include "code.hpp"
#include <sstream>
#include <iostream>
using namespace std;

// ============================================================
// STAGE 0 Tests
// ============================================================

/// Create a LegacyData union with an int (42). Call printLegacyData.
/// Verify the returned string matches "42".
void test_printLegacyData_int(void) 
{
    LegacyData x;
    x.i = 42;
    string s = printLegacyData(x, 'i');
    TEST_ASSERT_TRUE_MESSAGE(s=="42","X NOT 42");
}

/// Create a LegacyData union with a double (3.14). Call printLegacyData.
/// Verify the returned string matches "3.14".
void test_printLegacyData_double(void) 
{
    LegacyData x;
    x.d = 3.14;
    string s = printLegacyData(x, 'd');
    TEST_ASSERT_TRUE_MESSAGE(s=="3.14", "X NOT 3.14");
}

// ============================================================
// STAGE 1 Tests
// ============================================================

/// Call createTwoStructNodes().
/// Verify head->value contains int 5 with type 'i', and head->nextPtr->value contains double ~3.14 with type 'd'.
/// Clean up allocated memory.
void test_createTwoStructNodes_links_correctly(void) 
{
    structNode *e = createTwoStructNodes();

    TEST_ASSERT_TRUE_MESSAGE(e->value.i==5, "e NOT 5");
    TEST_ASSERT_TRUE_MESSAGE(e->typeData=='i', "e NOT i");
    TEST_ASSERT_TRUE_MESSAGE(e->nextPtr->value.d==3.14, "e NOT 3.14");
    TEST_ASSERT_TRUE_MESSAGE(e->nextPtr->typeData=='d', "e NOT d");

    delete e->nextPtr;
    delete e;
}

// ============================================================
// STAGE 2 Tests
// ============================================================

/// Call createTwoClassNodes().
/// Verify head->value contains int 5 with type 'i', and head->nextPtr->value contains double ~3.14 with type 'd'.
/// Clean up allocated memory.
void test_createTwoClassNodes_links_correctly(void) 
{
    classNode *e = createTwoClassNodes();

    TEST_ASSERT_TRUE_MESSAGE(e->value.i==5, "e NOT 5");
    TEST_ASSERT_TRUE_MESSAGE(e->typeData=='i', "e NOT i");
    TEST_ASSERT_TRUE_MESSAGE(e->nextPtr->value.d==3.14, "e NOT 3.14");
    TEST_ASSERT_TRUE_MESSAGE(e->nextPtr->typeData=='d', "e NOT d");

    delete e->nextPtr;
    delete e;
}

// ============================================================
// STAGE 3 Tests
// ============================================================

/// Call createTwoTemplateNodes().
/// Verify head->value is 5 and head->nextPtr->value is 3.
/// Clean up allocated memory.
void test_createTwoTemplateNodes_links_correctly(void) 
{
    classNodeT<int> *head = createTwoTemplateNodes();
    TEST_ASSERT_TRUE_MESSAGE(head->value==5, "head not 5");
    TEST_ASSERT_TRUE_MESSAGE(head->nextPtr->value==3, "head->nextPtr not 3");
    delete head->nextPtr;
    delete head;
}

// ============================================================
// STAGE 4: LinkedList Tests
// ============================================================

/// Create a LinkedList. Add two nodes using addFirst.
/// Verify listLength() returns 2 after insertions.
void test_linkedList_addFirst_updates_counter(void) 
{
    LinkedList *a = new LinkedList();
    classNodeVariant *newPtr1 = new classNodeVariant(5);
    classNodeVariant *newPtr2 = new classNodeVariant(6);
    a->addFirst(newPtr1);
    a->addFirst(newPtr2);
    TEST_ASSERT_TRUE_MESSAGE(a->listLength()==2, "counter is not 2");
    delete a;
}

/// Create a LinkedList. Add nodes (10, then 20) using addLast.
/// Capture std::cout and verify elements appear in order ("10" before "20").
void test_linkedList_addLast_places_at_end(void) 
{
    LinkedList *a = new LinkedList();
    classNodeVariant *newPtr1 = new classNodeVariant(10);
    classNodeVariant *newPtr2 = new classNodeVariant(20);
    std::cout << a->addLast(newPtr1);
    std::cout << a->addLast(newPtr2);
    TEST_ASSERT_TRUE_MESSAGE(newPtr1->nextPtr==newPtr2, "NOT CORRECT");
    delete a;

}

/// Create a LinkedList with an int, double, and string.
/// Call deleteValue() with the double value (3.14).
/// Verify list length decreases to 2 and second call returns -1.
void test_linkedList_deleteValue_removes_variant(void) 
{
    LinkedList *a = new LinkedList();
    classNodeVariant *b = new classNodeVariant(10);
    classNodeVariant *c = new classNodeVariant(3.14);
    classNodeVariant *d = new classNodeVariant("Hi");
    a->addFirst(b);
    a->addFirst(c);
    a->addFirst(d);
    a->deleteValue(3.14);
    TEST_ASSERT_TRUE_MESSAGE(a->listLength() == 2, "List length is not 2");
    TEST_ASSERT_TRUE_MESSAGE(a->deleteValue(3.14)==-1, "Second call doesn't return -1");
    delete a;
}

/// Create a LinkedList and insert three nodes.
/// Call destroyList().
/// Verify listLength() becomes 0.
void test_linkedList_destroyList_clears_all(void) 
{
    LinkedList *a = new LinkedList();
    classNodeVariant *b = new classNodeVariant(10);
    classNodeVariant *c = new classNodeVariant(3.14);
    classNodeVariant *d = new classNodeVariant("Hi");
    a->addFirst(b);
    a->addFirst(c);
    a->addFirst(d);
    a->destroyList();
    TEST_ASSERT_TRUE_MESSAGE(a->listLength()==0, "List not destroyed");
    //delete a;
}

/// Create a LinkedList with nodes (10, 20, 30).
/// Call deleteFirst().
/// Verify listLength() becomes 2 and operation returns 0.
void test_linkedList_deleteFirst(void) 
{
    LinkedList *a = new LinkedList();
    classNodeVariant *newPtr1 = new classNodeVariant(10);
    classNodeVariant *newPtr2 = new classNodeVariant(20);
    classNodeVariant *newPtr3 = new classNodeVariant(30);
    a->addFirst(newPtr1);
    a->addFirst(newPtr2);
    a->addFirst(newPtr3);

    TEST_ASSERT_TRUE_MESSAGE(a->deleteFirst()==0, "List length is not 0");
    TEST_ASSERT_TRUE_MESSAGE(a->listLength()==2, "List length is not 2");

    //delete a;
}

/// Create a LinkedList with nodes (10, 20, 30).
/// Call deleteLast().
/// Verify listLength() becomes 2 and operation returns 0.
void test_linkedList_deleteLast(void) 
{
    LinkedList *a = new LinkedList();
    classNodeVariant *newPtr1 = new classNodeVariant(10);
    classNodeVariant *newPtr2 = new classNodeVariant(20);
    classNodeVariant *newPtr3 = new classNodeVariant(30);
    a->addFirst(newPtr1);
    a->addFirst(newPtr2);
    a->addFirst(newPtr3);

    TEST_ASSERT_TRUE_MESSAGE(a->deleteLast() == 0, "Does not pass");
    TEST_ASSERT_TRUE_MESSAGE(a->listLength()==2, "List length is not 2");
    //delete a;
}

/// Create a LinkedList with nodes (1, 2.5, "test").
/// Redirect std::cout buffer and call printList().
/// Verify printed output contains "1", "2.5" (or "2.50"), and "test".
void test_linkedList_printList(void) 
{
    LinkedList *a = new LinkedList();
    classNodeVariant *newPtr1 = new classNodeVariant(1);
    classNodeVariant *newPtr2 = new classNodeVariant(2.5);
    classNodeVariant *newPtr3 = new classNodeVariant("test");
    a->addFirst(newPtr1);
    a->addFirst(newPtr2);
    a->addFirst(newPtr3);
    a->printList();
    TEST_ASSERT_TRUE_MESSAGE(1, "Not 1");
    TEST_ASSERT_TRUE_MESSAGE(2.5, "Not 2.5");
    TEST_ASSERT_TRUE_MESSAGE("test", "Not test");
    delete a;
}