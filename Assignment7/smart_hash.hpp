#ifndef SMART_HASH_HPP
#define SMART_HASH_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

class SmartHashTable {
public:
    // Constructor to initialize the hash table with a specified capacity
    SmartHashTable(int n);

    // Hash function to calculate the hash value of a key
    int getHashIndex(string value);

    // Add a key to the hash table
    void add(string value);

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

private:
    int n; // Capacity of the hash table
    int size; // Number of elements in the hash table
    int collisionCount; // Number of collisions
    vector<vector<string>> v; // Array of vectors to store values
};

#endif

