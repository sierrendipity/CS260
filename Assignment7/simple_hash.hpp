#ifndef SIMPLE_HASH_HPP
#define SIMPLE_HASH_HPP

#include <string>

using std::string;

class SimpleHashTable {
public:
    // Constructor to initialize the hash table with a specified capacity
    SimpleHashTable(int initialCapacity);

    // Hash function to calculate the hash value of a key
    int hash(string value);

    // Add a key-value pair to the hash table
    int add(string value);

    // Remove a key from the hash table
    bool remove(string value);

    // Search for a key in the hash table
    bool search(string value);

    // Generate a string representation of the hash table
    string toString();

    // Get the current size of the hash table
    int getSize();

    // Get the current collision count
    int getCollisionCount();

    // Resize function to increase capacity
    bool resize();

private:
    int capacity; // Capacity of the hash table
    int size; // Number of elements in the hash table
    int collisionCount; // Number of collisions

    string* storage; // Array to store values

};

#endif
