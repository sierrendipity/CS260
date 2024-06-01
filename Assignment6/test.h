#ifndef TEST_H
#define TEST_H

#include "book.h"

// Test function for adding books to the list
void test_add(BookNode** root);

// Test function for searching books using binary search
void test_search(BookNode** root);

// Test function for deleting books by name
void test_delete(BookNode** root);

// Test function for various tree traversals
void test_traversals(BookNode* root);

#endif

