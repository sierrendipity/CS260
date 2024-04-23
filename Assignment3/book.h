#include <string>

// structs needed for program
struct Book {
    std::string title; // Use std::string for the title
    int id;
};

typedef struct Node
{
    Book book;
    struct Node *next;
} 
BookList;

//Create a new node
BookList* create_node(Book Book);

//inserts a new node to the back of the queue
int add_book(BookList **head_ref, Book Book);

//deletes the book at the front of the queue
Book delete_book(BookList **head_ref);

//peeks at front of queue and returns the values without removing it
Book peek_a_book(BookList **head_ref);
