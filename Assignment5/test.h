#ifndef TEST_H
#define TEST_H

#include "book.h"

// Test function for adding books to the list
void test_add(BookList** head_ref);

// Test function for searching books using binary search
void test_search(BookList** head_ref);

// Test function for deleting books by name
void test_delete(BookList** head_ref);

#endif

