#include "test.h"
#include "book.h"
#include <iostream>

// Test function for searching books in the BST
void test_search(BookNode** root) {
    std::cout << std::endl << "Testing search_book function:" << std::endl;

    // Search for 'Eragon'
    std::cout << "Search for 'Eragon': ";
    Book* result1 = search_book(*root, "Eragon");
    if (result1 != nullptr) {
        std::cout << "Found: Title - " << result1->title << ", ID - " << result1->id << ", Address - " << result1 << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    // Search for 'Dune'
    std::cout << "Search for 'Dune': ";
    Book* result2 = search_book(*root, "Dune");
    if (result2 != nullptr) {
        std::cout << "Found: Title - " << result2->title << ", ID - " << result2->id << ", Address - " << result2 << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }
}

void test_add(BookNode** root) {
    std::cout << "Before adding books:" << std::endl;
    in_order_traversal(*root);

    std::cout << std::endl << "Testing add_book function:" << std::endl;

    // Add some books
    *root = add_book(*root, {"Murder Bot", 1234567});
    *root = add_book(*root, {"Eragon", 2345678});
    *root = add_book(*root, {"The Martian", 3456789});
    *root = add_book(*root, {"Foundation", 4567890});

    std::cout << "After adding books:" << std::endl;
    test_traversals(*root);
}

void test_delete(BookNode** root) {
    std::cout << std::endl << "Testing delete_book function:" << std::endl;

    // Attempt to delete the book with title "The Martian"
    std::cout << "Deleting 'The Martian': ";
    *root = delete_book(*root, "The Martian");

    std::cout << std::endl << "After deleting 'The Martian':" << std::endl;
    test_traversals(*root);

    // Attempt to delete the book with title "Foundation"
    std::cout << std::endl << "Deleting 'Foundation': ";
    *root = delete_book(*root, "Foundation");

    std::cout << std::endl << "After deleting 'Foundation':" << std::endl;
    test_traversals(*root);
}

void test_traversals(BookNode* root) {
    std::cout << std::endl << "Testing in_order_traversal function:" << std::endl;
    in_order_traversal(root);

    std::cout << std::endl << "Testing pre_order_traversal function:" << std::endl;
    pre_order_traversal(root);

    std::cout << std::endl << "Testing post_order_traversal function:" << std::endl;
    post_order_traversal(root);

    std::cout << std::endl << "Testing breadth_first_traversal function:" << std::endl;
    breadth_first_traversal(root);
}


