#include <iostream>
#include <cstring>
#include "book.h"

using namespace std;

// Function to create a new book node in the linked list.
BookList* create_node(Book book) {
    // Allocate memory for a new node.
    BookList* newNode = new BookList();
    
    // Copy the title from the book to the new node.
    newNode->book.title = strdup(book.title.c_str());
    
    // Copy the ID from the book to the new node.
    newNode->book.id = book.id;
    
    // Initialize the next pointer to point to nothing for now.
    newNode->next = nullptr;
    
    // Return the newly created node.
    return newNode;
}

// Function to insert a new book at a given position in the linked list.
int add_book(BookList **head_ref, Book book, int position) {
    // Create a new node with the given book information.
    BookList* newNode = create_node(book);

    // If inserting at the beginning (position 0) or the list is empty.
    if (position == 0 || *head_ref == nullptr) {
        // Point the new node to the current head.
        newNode->next = *head_ref;
        
        // Update the head to the new node.
        *head_ref = newNode;
        
        // Return 1 to indicate success.
        return 1;
    }

    // Start from the head of the list.
    BookList* current = *head_ref;
    
    // Traverse the list to find the node just before the insertion point.
    for (int i = 0; i < position - 1 && current->next != nullptr; ++i) {
        // Move to the next node.
        current = current->next;
    }

    // Insert the new node at the desired position.
    newNode->next = current->next;
    current->next = newNode;
    
    // Return 1 to indicate success.
    return 1;
}

// Function to remove the book at a given position in the list and return it.
Book delete_book(BookList **head_ref, int position) {
    // If the list is empty, return a default book.
    if (*head_ref == nullptr) {
        return {"", -1}; // No book found, return a default empty book.
    }

    // Pointer to the head of the list.
    BookList* temp = *head_ref;

    // If removing the head (position 0).
    if (position == 0) {
        // Update the head to the next node.
        *head_ref = temp->next;
        
        // Store the book from the deleted node.
        Book deletedBook = temp->book;
        
        // Free the memory of the deleted node.
        delete temp;
        
        // Return the deleted book.
        return deletedBook;
    }

    // Traverse the list to find the node just before the removal point.
    for (int i = 0; temp != nullptr && i < position - 1; ++i) {
        temp = temp->next;
    }

    // If the desired position is out of bounds.
    if (temp == nullptr || temp->next == nullptr) {
        return {"", -1}; // No book found, return a default empty book.
    }

    // Pointer to the node to be deleted.
    BookList* next = temp->next->next;
    Book deletedBook = temp->next->book;
    
    // Free the memory of the node to be deleted.
    delete temp->next;
    
    // Update the next pointer of the previous node.
    temp->next = next;

    // Return the deleted book.
    return deletedBook;
}

// Function to return the book at a given position without removing it.
Book peek_a_book(BookList **head_ref, int position) {
    // Pointer to the head of the list.
    BookList* current = *head_ref;

    // Traverse the list to the desired position.
    for (int i = 0; current != nullptr && i < position; ++i) {
        current = current->next;
    }

    // If the position is out of bounds.
    if (current == nullptr) {
        return {"", -1}; // No book found, return a default empty book.
    }

    // Return the book at the desired position.
    return current->book;
}


