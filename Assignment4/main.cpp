#include <iostream>
#include "book.h"
#include "test.h"

using namespace std;

int main() {
    // Test the add_book function and print the results.
    cout << endl << "Testing add_book function:" << endl << endl;
    test_add();

    // Test the peek_a_book function and print the results.
    cout << endl << "Testing peek_a_book function:" << endl << endl;
    test_peek_a_book();

    // Test the delete_book function and print the results.
    cout << endl << "Testing delete_book function:" << endl << endl;
    test_delete();
    
    // Return 0 to indicate successful execution.
    return 0;
}

