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
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

// ============================================================
// STAGE 4: LinkedList Tests
// ============================================================

/// Create a LinkedList. Add two nodes using addFirst.
/// Verify listLength() returns 2 after insertions.
void test_linkedList_addFirst_updates_counter(void) 
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

/// Create a LinkedList. Add nodes (10, then 20) using addLast.
/// Capture std::cout and verify elements appear in order ("10" before "20").
void test_linkedList_addLast_places_at_end(void) 
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

/// Create a LinkedList with an int, double, and string.
/// Call deleteValue() with the double value (3.14).
/// Verify list length decreases to 2 and second call returns -1.
void test_linkedList_deleteValue_removes_variant(void) 
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

/// Create a LinkedList and insert three nodes.
/// Call destroyList().
/// Verify listLength() becomes 0.
void test_linkedList_destroyList_clears_all(void) 
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

/// Create a LinkedList with nodes (10, 20, 30).
/// Call deleteFirst().
/// Verify listLength() becomes 2 and operation returns 0.
void test_linkedList_deleteFirst(void) 
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

/// Create a LinkedList with nodes (10, 20, 30).
/// Call deleteLast().
/// Verify listLength() becomes 2 and operation returns 0.
void test_linkedList_deleteLast(void) 
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

/// Create a LinkedList with nodes (1, 2.5, "test").
/// Redirect std::cout buffer and call printList().
/// Verify printed output contains "1", "2.5" (or "2.50"), and "test".
void test_linkedList_printList(void) 
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}