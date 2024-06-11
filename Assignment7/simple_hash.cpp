#include <sstream>
#include <iostream>
#include "simple_hash.hpp"

using std::stringstream;

// Constructor to initialize table
SimpleHashTable::SimpleHashTable(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;
    collisionCount = 0; // Initialize collision count

    storage = new string[capacity]; // Allocate storage for the table
} 

// Hash function to calculate the hash value of a key
int SimpleHashTable::hash(string value) {
    int result = 0;

    //sum ASCII character in
    for (char c : value) {
        result += (int)c;
    }

    result %= capacity;

    return result;
}

// Add a key-value pair to the hash table
int SimpleHashTable::add(string value) {
    bool collision = false;
    // hash key
    int bucket = hash(value);
    // check if there is a collision
    if (storage[bucket] != value && storage[bucket] != "") {
        collision = true;
    }
    // place key in bucket
    storage[bucket] = value;

    // check for resize
    if (size >= capacity / 2) {
        resize();
    }

    // handle collision
    if (collision == true) {
        // this is a simple hack, more refined one will be used in smart HT
        bucket *= -1;
        ++collisionCount; // Increment collision count
    } else {
        ++size; //increase size if no collision
    }
    return bucket;
}

// Remove a key from the hash table
bool SimpleHashTable::remove(string value) {
    bool isThere = search(value); // Check if the value exists. 
    int bucket = hash(value);

    // If the value exists, remove it from the hash table
    if (isThere == true) {
        storage[bucket] = "";
        --size; // Decrement the size of the hash table
    }
    return isThere;
}

// Search for a key in the hash table
bool SimpleHashTable::search(string value) {
    bool result = false;
    // hash
    int bucket = hash(value);
    // check if value there is the same as our value
    if (storage[bucket] == value) {
        result = true;
    }

    return result;
}

// Resize the hash table to a larger capacity
bool SimpleHashTable::resize() {
    try {
        // Double the capacity
        int newCapacity = capacity * 2;

        // Create a new storage array with the new capacity
        string* newStorage = new string[newCapacity];

        // Rehash all existing elements into the new storage array
        for (int i = 0; i < capacity; ++i) {
            if (!storage[i].empty()) {
                int newIndex = hash(storage[i]) % newCapacity;
                newStorage[newIndex] = storage[i];
            }
        }

        // Clean up old storage
        delete[] storage;

        // Update the capacity and storage array
        storage = newStorage;
        capacity = newCapacity;

        return true;
    } catch (const std::bad_alloc& e) {
        // Memory allocation failed
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return false;
    } catch (const std::exception& e) {
        // Other exceptions
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        return false; 
    }
}


// Generate a string representation of the hash table
string SimpleHashTable::toString() {
    // Initialize a stringstream to construct the string
    stringstream result;
    // Iterate through each element in the storage array and append to stringstream
    for (int i = 0; i < capacity; ++i) {
        result << storage[i] << ", ";
    }
    // Return the constructed string
    return result.str();
}

// Get the current size of the hash table
int SimpleHashTable::getSize() {
    return size;
}

// Get the current collision count
int SimpleHashTable::getCollisionCount() {
    return collisionCount;
}



