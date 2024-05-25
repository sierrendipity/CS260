#include <string>

// structs needed for program
struct Book {
    std::string title; // Use std::string for the title
    int id;
};

typedef struct Node {
    Book book;
    struct Node *next;
} BookList;

//Create a new node
BookList* create_node(Book book);

//inserts a new node to a given position in the list
int add_book(BookList **head_ref, Book book, int position);

//removes the book at a given position of the list
Book delete_book(BookList **head_ref, int position);

//returns the book at a given position without removing it
Book peek_a_book(BookList **head_ref, int position);
