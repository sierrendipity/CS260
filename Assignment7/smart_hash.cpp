#include "smart_hash.hpp"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

// Initialize the table
SmartHashTable::SmartHashTable(int n) {
    this->n = n;
    size = 0;
    collisionCount = 0;

    v = vector<vector<string>>(n); // Allocate storage for the table
}

// Hash function to calculate the hash value of a key
int SmartHashTable::getHashIndex(string value) {
    // Simple hash function using division method
    int hashValue = 0;
    for (char c : value) {
        hashValue = (hashValue * 31 + c) % n; // Using 31 as a base for better distribution
    }
    return hashValue % n;
}

// Add a key to the hash table
void SmartHashTable::add(string value) {
    int bucket = getHashIndex(value);
    if (search(value)) {
        return; // Avoid adding duplicates
    }
    
    if (!v[bucket].empty()) {
        ++collisionCount; // Increment collision count if bucket is not empty
    }
    
    v[bucket].push_back(value); // Add the value to the bucket
    ++size; // Increment size
}

// Remove a key from the hash table
bool SmartHashTable::remove(string value) {
    int bucket = getHashIndex(value);

    // Scan for the element to be removed
    for (size_t j = 0; j < v[bucket].size(); ++j) {
        if (v[bucket][j] == value) {
            v[bucket].erase(v[bucket].begin() + j); // Remove element
            --size; // Decrement size
            cout << value << " deleted!" << endl;
            return true;
        }
    }

    cout << "No Element Found!" << endl;
    return false;
}



// Search for a key in the hash table
bool SmartHashTable::search(string value) {
    int bucket = getHashIndex(value);
    // Check if value is present in the bucket
    for (size_t i = 0; i < v[bucket].size(); ++i) {
        if (v[bucket][i] == value) {
            return true;
        }
    }
    return false;
}

// Generate a string representation of the hash table
string SmartHashTable::toString() {
    string result;
    // Iterate through each bucket and append its contents to the result string
    for (int i = 0; i < n; ++i) {
        result += std::to_string(i) + " -> ";
        for (size_t j = 0; j < v[i].size(); ++j) {
            result += v[i][j] + " ";
        }
        result += "\n";
    }
    return result;
}

// Get the current size of the hash table
int SmartHashTable::getSize() {
    return size;
}

// Get the current collision count
int SmartHashTable::getCollisionCount() {
    return collisionCount;
}

