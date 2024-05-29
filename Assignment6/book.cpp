#include "book.h"
#include <iostream>

// Function to create a new book node in the linked list.
BookList* create_node(Book book) {
    BookList* newNode = new BookList();
    newNode->book = book;
    newNode->next = nullptr;
    return newNode;
}

// Insert a new node automatically by lexicographica sorting
int add_book(BookList** head_ref, Book book) {
    BookList* newNode = create_node(book);

    // If the list is empty or the new node's title is less than the head's title
    if (*head_ref == nullptr || book.title < (*head_ref)->book.title) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        std::cout << "Book added: " << book.title << ", Address: " << &(newNode->book) << std::endl; // Print address after adding
        return 1;
    }

    // Traverse the list to find the correct position
    BookList* current = *head_ref;
    while (current->next != nullptr && current->next->book.title < book.title) {
        current = current->next;
    }

    // Insert the new node at the correct position
    newNode->next = current->next;
    current->next = newNode;
    std::cout << "Book added: " << book.title << ", Address: " << &(newNode->book) << std::endl; // Print address after adding
    return 1;
}

// Function to use binary search to locate a book by title
Book* search_book(BookList** head_ref, const std::string& title) {
    // Pointer to the head of the list.
    BookList* current = *head_ref;

    // Binary search variables
    int low = 0;
    int high = 0;
    int mid = 0;

    // Determine the length of the list
    while (current != nullptr) {
        high++;
        current = current->next;
    }
    high--; // Adjust high to the last index

    current = *head_ref; // Reset current to head

    // Perform binary search
    while (low <= high) {
        mid = low + (high - low) / 2; // Calculate the middle index

        // Traverse to the middle node
        current = *head_ref;
        for (int i = 0; i < mid; ++i) {
            current = current->next;
        }

        // Check if the title matches
        if (current->book.title == title) {
            return &(current->book); // Return the address of the found book
        }
        // If the title is alphabetically lower, search in the left half
        else if (current->book.title < title) {
            low = mid + 1;
        }
        // If the title is alphabetically higher, search in the right half
        else {
            high = mid - 1;
        }
    }

    // Return nullptr if not found
    return nullptr;
}

// Function to remove the book at a given position in the list and return it.
Book delete_book(BookList** head_ref, const std::string& title) {
    // If the list is empty, return a default book indicating no deletion occurred.
    if (*head_ref == nullptr) {
        return {"", -1};
    }

    BookList* temp = *head_ref;

    // If the book to be deleted is the head of the list.
    if (temp != nullptr && temp->book.title == title) {
        *head_ref = temp->next;
        Book deletedBook = temp->book;
        delete temp;
        return deletedBook;
    }

    BookList* prev = nullptr;
    // Traverse the list to find the node with the matching title.
    while (temp != nullptr && temp->book.title != title) {
        prev = temp;
        temp = temp->next;
    }

    // If the book with the given title is not found.
    if (temp == nullptr) {
        return {"", -1};
    }

    // Unlink the node and free memory.
    prev->next = temp->next;
    Book deletedBook = temp->book;
    delete temp;
    return deletedBook;
}

// Display the elements of the list along with their addresses
void display(BookList* head) {
    std::cout << std::endl << "Books in the list:" << std::endl;
    BookList* current = head;
    int index = 0;
    while (current != nullptr) {
        std::cout << "Book " << index << ": ";
        std::cout << "Title: " << current->book.title << ", ID: " << current->book.id;
        std::cout << ", Address: " << current << std::endl; // Print the address of the book node
        current = current->next;
        index++;
    }
}








