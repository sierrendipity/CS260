#include "simple_hash.hpp"
#include "smart_hash.hpp"
#include "test.hpp"
#include <iostream>

using std::cout;
using std::endl;

// Function to test SimpleHashTable
void testSimpleHashTable() {
    SimpleHashTable ht(10);

    // Test adding 'ABC' to the hash table
    cout << "Test: Adding 'ABC'" << endl;
    ht.add("ABC");
    cout << "Table contents after adding 'ABC': " << ht.toString() << endl;
    cout << "Size of table after adding 'ABC': " << ht.getSize() << endl;
    cout << "Collision count after adding 'ABC': " << ht.getCollisionCount() << endl << endl;

    // Test adding 'BCD' to the hash table (should not cause collision)
    cout << "Test: Adding 'BCD' (non-collision)" << endl;
    ht.add("BCD");
    cout << "Table contents after adding 'BCD': " << ht.toString() << endl;
    cout << "Size of table after adding 'BCD': " << ht.getSize() << endl;
    cout << "Collision count after adding 'BCD': " << ht.getCollisionCount() << endl << endl;

    // Test adding 'CAB' to the hash table (should cause collision)
    cout << "Test: Adding 'CAB' (collision)" << endl;
    ht.add("CAB");
    cout << "Table contents after adding 'CAB': " << ht.toString() << endl;
    cout << "Size of table after adding 'CAB': " << ht.getSize() << endl;
    cout << "Collision count after adding 'CAB': " << ht.getCollisionCount() << endl << endl;

    // Test removing 'CAB' from the hash table
    cout << "Test: Removing 'CAB'" << endl;
    bool result = ht.remove("CAB");
    cout << "Remove 'CAB' (success: " << result << ")." << endl;
    cout << "Table contents after removing 'CAB': " << ht.toString() << endl;
    cout << "Size of table after removing 'CAB': " << ht.getSize() << endl;
    cout << "Collision count after removing 'CAB': " << ht.getCollisionCount() << endl << endl;

    // Test searching for 'ABC' in the hash table
    cout << "Test: Searching for 'ABC'" << endl;
    bool searchResultABC = ht.search("ABC");
    cout << "Search for 'ABC' (found: " << searchResultABC << ")." << endl << endl;

    // Test searching for 'BCD' in the hash table
    cout << "Test: Searching for 'BCD'" << endl;
    bool searchResultBCD = ht.search("BCD");
    cout << "Search for 'BCD' (found: " << searchResultBCD << ")." << endl << endl;

    // Test adding 15 additional items to the hash table
    cout << "Test: Adding 15 additional items" << endl;
    for (int i = 0; i < 15; ++i) {
        ht.add("Test" + std::to_string(i));
    }
    cout << "Table contents after adding 15 more items: " << ht.toString() << endl;
    cout << "Size of table after adding 15 more items: " << ht.getSize() << endl;
    cout << "Collision count after adding 15 more items: " << ht.getCollisionCount() << endl;
}

// Function to test SmartHashTable
void testSmartHashTable() {
    SmartHashTable ht(10);

    // Test adding 'ABC' to the hash table
    cout << "Test: Adding 'ABC'" << endl;
    ht.add("ABC");
    cout << "Table contents after adding 'ABC': " << ht.toString() << endl;
    cout << "Size of table after adding 'ABC': " << ht.getSize() << endl;
    cout << "Collision count after adding 'ABC': " << ht.getCollisionCount() << endl << endl;

    // Test adding 'BCD' to the hash table (should not cause collision)
    cout << "Test: Adding 'BCD' (non-collision)" << endl;
    ht.add("BCD");
    cout << "Table contents after adding 'BCD': " << ht.toString() << endl;
    cout << "Size of table after adding 'BCD': " << ht.getSize() << endl;
    cout << "Collision count after adding 'BCD': " << ht.getCollisionCount() << endl << endl;

    // Test adding 'CAB' to the hash table (should cause collision)
    cout << "Test: Adding 'CAB' (collision)" << endl;
    ht.add("CAB");
    cout << "Table contents after adding 'CAB': " << ht.toString() << endl;
    cout << "Size of table after adding 'CAB': " << ht.getSize() << endl;
    cout << "Collision count after adding 'CAB': " << ht.getCollisionCount() << endl << endl;

    // Test removing 'CAB' from the hash table
    cout << "Test: Removing 'CAB'" << endl;
    bool result = ht.remove("CAB");
    cout << "Remove 'CAB' (success: " << result << ")." << endl;
    cout << "Table contents after removing 'CAB': " << ht.toString() << endl;
    cout << "Size of table after removing 'CAB': " << ht.getSize() << endl;
    cout << "Collision count after removing 'CAB': " << ht.getCollisionCount() << endl << endl;

    // Test searching for 'ABC' in the hash table
    cout << "Test: Searching for 'ABC'" << endl;
    bool searchResultABC = ht.search("ABC");
    cout << "Search for 'ABC' (found: " << searchResultABC << ")." << endl << endl;

    // Test searching for 'BCD' in the hash table
    cout << "Test: Searching for 'BCD'" << endl;
    bool searchResultBCD = ht.search("BCD");
    cout << "Search for 'BCD' (found: " << searchResultBCD << ")." << endl << endl;

    // Test adding 15 additional items to the hash table
    cout << "Test: Adding 15 additional items" << endl;
    for (int i = 0; i < 15; ++i) {
        ht.add("Test" + std::to_string(i));
    }
    cout << "Table contents after adding 15 more items: " << ht.toString() << endl;
    cout << "Size of table after adding 15 more items: " << ht.getSize() << endl;
    cout << "Collision count after adding 15 more items: " << ht.getCollisionCount() << endl;
}
