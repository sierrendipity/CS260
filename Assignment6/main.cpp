#include "book.h"
#include "test.h"

int main() {
    // Create an empty BST
    BookNode* root = nullptr;

    // Test adding books
    test_add(&root);

    // Test searching for books
    test_search(&root);

    // Test deleting books
    test_delete(&root);

    return 0;
}



