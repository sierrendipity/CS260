#include <iostream>
#include "book.h"
#include "test.h"

using namespace std;

// Test function for adding three books and printing them in order
void test_add() {
    BookList* head = nullptr;

    // Test adding books
    Book book1 = {"Murder Bot", 1234567};
    Book book2 = {"Eragon", 2345678};
    Book book3 = {"The Martian", 3456789};
    add_book(&head, book1);
    add_book(&head, book2);
    add_book(&head, book3);

    // Print the books in the order they were added
    cout << "Books in the order they were added:" << endl << endl;
    BookList* current = head;  // Start from the head
    while (current != nullptr) {
        cout << "Title: " << current->book.title << ", ID: " << current->book.id << endl;
        current = current->next;  // Move to the next node
    }
}//Expected: Murder Bot, Eragon, The Martian


void test_peek() {
    BookList* head = nullptr;

    // Adding books
    Book book1 = {"Murder Bot", 1234567};
    Book book2 = {"Eragon", 2345678};
    Book book3 = {"The Martian", 3456789};
    add_book(&head, book1);
    add_book(&head, book2);
    add_book(&head, book3);

    // Test peeking at the front of the queue
    cout << "Peek at the top book: " << endl << endl;
    Book topBook = peek_a_book(&head);
    if (topBook.title != "" && topBook.id != -1) {
        cout << "Title: " << topBook.title << ", ID: " << topBook.id << endl << endl;
    } else {
        cout << "No book found at the top." << endl << endl;
    }
}//Expected: Murder Bot

void test_delete() {
    cout << "Testing delete_book until queue is empty:" << endl;
    BookList* head = nullptr;

    // Test adding books
    Book book1 = {"Murder Bot", 1234567};
    Book book2 = {"Eragon", 2345678};
    Book book3 = {"The Martian", 3456789};
    add_book(&head, book1);
    add_book(&head, book2);
    add_book(&head, book3);

    // Delete the front book and peek until the queue is empty
    while (head != nullptr) {
        // Print the top book's information before deleting
        cout << endl << "Peek at the top book:" << endl;
        Book topBook = peek_a_book(&head);
        if (topBook.title != "" && topBook.id != -1) {
            cout << "Title: " << topBook.title << ", ID: " << topBook.id << endl << endl;
        } else {
            cout << "No book found at the top." << endl << endl;
        }

        // Delete the front book
        cout << "Deleting the front book!!!" << endl;

        // Print the deleted book's information
        Book deletedBook = delete_book(&head);
        cout << "Deleted book: " << deletedBook.title << " (" << deletedBook.id << ")" << endl;

    }

    cout << "Queue is empty!" << endl;
}




