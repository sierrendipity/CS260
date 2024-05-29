#include "book.h"
#include "test.h"

int main() {
    // Create an empty list
    BookList* head = nullptr;

    // Test adding books
    test_add(&head);

    // Test searching for books
    test_search(&head);

    //Test deleting books
    test_delete(&head);

    return 0;
}

