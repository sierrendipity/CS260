#include <iostream>
#include "book.h"
#include "test.h"

using namespace std;

void print_books(BookList* head) {
    BookList* current = head;
    int position = 0;
    while (current != nullptr) {
        cout << "Position: " << position << ", Title: " << current->book.title << ", ID: " << current->book.id << endl;
        current = current->next;
        ++position;
    }
}

void test_add() {
    BookList* head = nullptr;

    // Test adding books
    Book book1 = {"Murder Bot", 1234567};
    Book book2 = {"Eragon", 2345678};
    Book book3 = {"The Martian", 3456789};

    add_book(&head, book1, 0);  // Adding at position 0
    add_book(&head, book2, 1);  // Adding at position 1
    add_book(&head, book3, 1);  // Adding at position 1 (between Murder Bot and Eragon)

    // Print the books in the order they were added with their positions
    cout << "Books after adding:" << endl;
    print_books(head);
}

void test_delete() {
    BookList* head = nullptr;

    // Adding books
    Book book1 = {"Murder Bot", 1234567};
    Book book2 = {"Eragon", 2345678};
    Book book3 = {"The Martian", 3456789};

    add_book(&head, book1, 0);
    add_book(&head, book2, 1);
    add_book(&head, book3, 1);

    // Remove and print
    cout << "Removing book at position 1:" << endl;
    Book deletedBook = delete_book(&head, 1);
    cout << "Removed Book - Title: " << deletedBook.title << ", ID: " << deletedBook.id << endl;

    // Print remaining books with their positions
    cout << "Books after removing:" << endl;
    print_books(head);
}

void test_peek_a_book() {
    BookList* head = nullptr;

    // Adding books
    Book book1 = {"Murder Bot", 1234567};
    Book book2 = {"Eragon", 2345678};
    Book book3 = {"The Martian", 3456789};

    add_book(&head, book1, 0);
    add_book(&head, book2, 1);
    add_book(&head, book3, 1);

    // Get and print
    cout << "Getting book at position 1:" << endl;
    Book peekedBook = peek_a_book(&head, 1);
    cout << "Got Book - Title: " << peekedBook.title << ", ID: " << peekedBook.id << endl;
}

