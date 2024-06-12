#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits> // Include for numeric_limits
#include <utility> // Include for std::pair

#define INF 0x3f3f3f3f

class DisjointSets {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DisjointSets(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Graph {
private:
    // Structure to represent a node in the adjacency list
    struct Node {
        int vertex; // Index of the adjacent vertex
        int weight; // Weight of the edge
        Node* next; // Pointer to the next adjacent vertex
        Node(int v, int w, Node* n = nullptr) : vertex(v), weight(w), next(n) {}
    };

    // Alias for pair of int
    using iPair = std::pair<int, int>;

    // Number of vertices
    int V;

    // Array to store the adjacency list of each vertex
    Node** adj;

    // Array to store the names of the vertices
    std::string* vertices;

    // Vector to store edges and their weights
    std::vector<std::pair<int, std::pair<int, int>>> edges;

    // Dijkstra's algorithm to find shortest path from source to destination
    int DijkstraShortestPath(int src, int dest, std::vector<int>& shortestPath);

public:
    // Constructor
    Graph();

    // Destructor
    ~Graph();

    // Add a new vertex to the graph
    void AddVertex();

    // Add an edge between two vertices
    void AddEdge(const std::string& source, const std::string& destination, int weight);

    // Method to find the shortest path between two vertices and return the total weight
    int ShortestPath(const std::string& src, const std::string& dest);

    // Find the minimum spanning tree of the graph and return the total weight
    int MinSpanTree();

    // Method to display the graph's adjacency list
    void DisplayGraph();

    // Method to get the count of vertices
    int GetVerticesCount() const;

    // Method to get the count of edges
    int GetEdgesCount() const;

    // Method to get the weight of an edge between two vertices
    int GetWeight(const std::string& source, const std::string& destination) const;
};

#endif
