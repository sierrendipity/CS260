#include "book.h"

// Function to create a new book node in the BST
BookNode* create_node(Book book) {
    BookNode* newNode = new BookNode();
    newNode->book = book;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Add a book alphabetically
BookNode* add_book(BookNode* root, Book book) {
    if (root == nullptr) {
        return create_node(book);
    }
    if (book.title < root->book.title) {
        root->left = add_book(root->left, book);
    } else {
        root->right = add_book(root->right, book);
    }
    return root;
}

// Use binary search to locate a book
Book* search_book(BookNode* root, const std::string& title) {
    if (root == nullptr || root->book.title == title) {
        return (root != nullptr) ? &(root->book) : nullptr;
    }
    if (title < root->book.title) {
        return search_book(root->left, title);
    } else {
        return search_book(root->right, title);
    }
}

// Delete a book
BookNode* delete_book(BookNode* root, const std::string& title) {
    if (root == nullptr)
        return root;

    // If the title to be deleted is smaller than the root's title,
    // then it lies in the left subtree
    if (title < root->book.title) {
        root->left = delete_book(root->left, title);
        return root;
    }
    // If the title to be deleted is greater than the root's title,
    // then it lies in the right subtree
    else if (title > root->book.title) {
        root->right = delete_book(root->right, title);
        return root;
    }

    // If title is same as root's title, then this is the node to be deleted
    // Node with only one child or no child
    if (root->left == nullptr) {
        BookNode* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == nullptr) {
        BookNode* temp = root->left;
        delete root;
        return temp;
    }

    // Node with two children: Get the inorder successor (smallest
    // in the right subtree)
    BookNode* succParent = root;
    BookNode* succ = root->right;
    while (succ->left != nullptr) {
        succParent = succ;
        succ = succ->left;
    }

    // Copy the inorder successor's content to this node
    root->book = succ->book;

    // Delete the inorder successor
    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;
    
    delete succ;
    return root;
}

// In-order traversal
void in_order_traversal(BookNode* root) {
    if (root != nullptr) {
        in_order_traversal(root->left);
        std::cout << "Title: " << root->book.title << ", ID: " << root->book.id << ", Address: " << root << std::endl;
        in_order_traversal(root->right);
    }
}

// Pre-order traversal
void pre_order_traversal(BookNode* root) {
    if (root != nullptr) {
        std::cout << "Title: " << root->book.title << ", ID: " << root->book.id << ", Address: " << root << std::endl;
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

// Post-order traversal
void post_order_traversal(BookNode* root) {
    if (root != nullptr) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        std::cout << "Title: " << root->book.title << ", ID: " << root->book.id << ", Address: " << root << std::endl;
    }
}

// Breadth-first traversal
void breadth_first_traversal(BookNode* root) {
    if (root == nullptr)
        return;

    std::queue<BookNode*> q;
    q.push(root);

    while (!q.empty()) {
        BookNode* current = q.front();
        q.pop();
        std::cout << "Title: " << current->book.title << ", ID: " << current->book.id << ", Address: " << current << std::endl;
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}










