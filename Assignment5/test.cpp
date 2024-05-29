#include "test.h"
#include "book.h"
#include <iostream>

// Test function for searching books using binary search
void test_search(BookList** head_ref) {
    // Test searching
    std::cout << std::endl << "Testing search_book function:" << std::endl;

    //Should be found and have same address
    std::cout << "Search for 'Eragon': ";
    Book* result1 = search_book(head_ref, "Eragon");
    if (result1 != nullptr) {
        std::cout << "Found: Title - " << result1->title << ", ID - " << result1->id << ", Address - " << result1 << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    //Should be not found
    std::cout << "Search for 'Dune': ";
    Book* result2 = search_book(head_ref, "Dune");
    if (result2 != nullptr) {
        std::cout << "Found: Title - " << result2->title << ", ID - " << result2->id << ", Address - " << result2 << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }
}


// Test function for adding books to the list
void test_add(BookList** head_ref) {
    
    // Display all books (Should be none)
    display(*head_ref);
    
    // Test adding books
    std::cout << std::endl << "Testing add_book function:" << std::endl;

    // Insert some books
    add_book(head_ref, {"Murder Bot", 1234567});
    add_book(head_ref, {"Eragon", 2345678});
    add_book(head_ref, {"The Martian", 3456789});
    add_book(head_ref, {"Foundation", 4567890});

    // Display all books (Should be in order)
    display(*head_ref);

}

void test_delete(BookList** head_ref) {
    std::cout << std::endl << "Testing delete_book function:" << std::endl;

    // Attempt to delete the book with title "The Martian"
    std::cout << "Deleting 'The Martian': ";
    Book deletedBook = delete_book(head_ref, "The Martian");
    if (deletedBook.id != -1) {
        std::cout << "Deleted Book - Title: " << deletedBook.title << ", ID: " << deletedBook.id << std::endl;
    } else {
        std::cout << "Book not found" << std::endl;
    }

    // Display the current state of the book list
    display(*head_ref);

    // Attempt to delete the book with title "Foundation"
    std::cout << "Deleting 'Foundation': ";
    deletedBook = delete_book(head_ref, "Foundation");
    if (deletedBook.id != -1) {
        std::cout << "Deleted Book - Title: " << deletedBook.title << ", ID: " << deletedBook.id << std::endl;
    } else {
        std::cout << "Book not found" << std::endl;
    }

    // Display the current state of the book list
    display(*head_ref);
}
