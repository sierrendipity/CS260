#ifndef BOOK_H
#define BOOK_H

#include <string>

// Define the struct for a book
struct Book {
    std::string title; // Use std::string for the title
    int id;
};

// Define the node struct
struct BookList {
    Book book;
    BookList* next;
};

// Create a new node
BookList* create_node(Book book);

// Add a new node automatically by alphabetical order
int add_book(BookList** head_ref, Book book);

// Use binary search to locate a book
Book* search_book(BookList** head_ref, const std::string& title);

// Used to display book info in test
void display(BookList* head);

//Delete a book
Book delete_book(BookList** head_ref, const std::string& title);

#endif



