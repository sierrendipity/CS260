#include <iostream>
#include "book.h"
#include "test.h"

using namespace std;


int main() {
    
    cout << "Testing add_book function:" << endl << endl;
    test_add();
    cout << endl << "Expected: Murder Bot, Eragon, The Martian" << endl << endl;

    cout << endl << "Testing peek_a_book function:" << endl << endl;
    test_peek();
    cout << endl << "Expected: Murder Bot" << endl << endl;

    test_delete();
    
    return 0;
}
