#include <iostream>
#include <cstring>
#include "book.h"

using namespace std;

// Create a new node
BookList* create_node(Book book) {
    BookList* newNode = new BookList();
    // Convert std::string to const char* and then duplicate it
    newNode->book.title = strdup(book.title.c_str());
    newNode->book.id = book.id; // Assign the id directly
    newNode->next = nullptr;
    return newNode;
}

// Inserts a new node to the back of the queue.
int add_book(BookList **head_ref, Book book) {
    //creates a new node
    BookList* newNode = create_node(book);

    //if head_ref is empty set head_ref to point to new node
    if (*head_ref == nullptr) { 
        *head_ref = newNode;
    } else {
        //If the queue is not empty, traverse the queue to find the last node
        BookList* temp = *head_ref;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Once the last node is found, set its next pointer to point to the newly created node
        temp->next = newNode;
    }
    
    // Successful insertion
    return 1;
}

// Deletes the book at the front of the queue and returns its value
Book delete_book(BookList **head_ref) {
    if (*head_ref == nullptr) {
        return {"", -1}; 
    } else {
        BookList* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        
        // Store the value of the deleted book
        Book deletedBook = temp->book;
        
        // No need to free memory for title (handled by std::string automatically)
        // Free the memory allocated for the BookList node
        delete temp;
        
        // Return the value of the deleted book
        return deletedBook;
    }
}

// Peeks at front of queue and returns the values without removing it
Book peek_a_book(BookList **head_ref) {
    if (*head_ref == nullptr) {
        return {"", -1};
    } else {
        // Return the value of the front book
        return (*head_ref)->book;
    }
}

