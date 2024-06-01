#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <queue>

// Define the struct for a book
struct Book {
    std::string title; // Use std::string for the title
    int id;
};

// Define the node struct
struct BookNode {
    Book book;
    BookNode* left;
    BookNode* right;
};

// Add a new node automatically by alphabetical order
BookNode* add_book(BookNode* root, Book book);

// Use binary search to locate a book
Book* search_book(BookNode* root, const std::string& title);

// Delete a book
BookNode* delete_book(BookNode* root, const std::string& title);

// Traversals
void in_order_traversal(BookNode* root);
void pre_order_traversal(BookNode* root);
void post_order_traversal(BookNode* root);
void breadth_first_traversal(BookNode* root);

#endif




