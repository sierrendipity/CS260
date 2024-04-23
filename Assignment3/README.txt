Design (Inspiration taken heavily from my previous 133C work)
main.cpp: 
Include book.h and test.h
* int main()
  o test_add
  o test_peek
  o test_delete

book.h
Contains: 
* The struct for Book
  o *Title (pointer to a string (title))
  o Book id (integer)
* The struct for BookList
  o Allows for linked list
* Declares the functions
  o Create_node
  o Add_book
  o Delete_book
  o Peek_a_book

book.cpp
* Create_node(BookList **head_ref, Book book)
  o Creates new node for linked list of books
* Add_book(BookList **head_ref)
  o create_node
  o if empty head_ref points to new node
  o else traverse queue until last node and once last notde is found set its next ptr to point to new node
  
* Delete_book(BookList **head_ref)
  o if queue is empty, error message
  o else delete
* peek_a_book(BookList **head_ref)
  o if empty error
  o else peek

test.h
Declares the functions: 
  * test_add
  * test_peek
  * test_delete

test.cpp
* test_add
  o add 3 books always adding to the back [add_book(&head, book1)]
  o print books added in order
* test_peek
  o add books
  o peek at top (should show first book)
* test_delete
  o deletes books from the front until empty
  o deletes first book first



