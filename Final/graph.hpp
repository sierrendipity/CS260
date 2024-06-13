#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <cctype>    // For ::toupper
#include "graphnode.hpp"
#include "edge.hpp"
#include "DSU.hpp"

class Graph {
private:
    std::vector<GraphNode*> nodes;
    std::vector<Edge*> edges;

    // Helper function to convert a string to uppercase
    std::string ToUpperCase(const std::string& str);

    // Comparator function for sorting edges by weight
    static bool CompareEdges(const Edge* e1, const Edge* e2);

public:
    Graph();

    // Method to add a vertex (iceberg)
    void AddVertex();

    // Method to add an edge (ocean path) between two vertices
    bool AddEdge(const std::string& from, const std::string& to, int weight);

    // Method to find the shortest path between two icebergs using Dijkstra's algorithm
    int ShortestPath(const std::string& source, const std::string& destination);

    // Method to find the minimum spanning tree using Kruskal's algorithm
    void MinSpanTree();

    // Method to display the graph (icebergs and their connections)
    void DisplayGraph();

    // Helper function to get the count of vertices (icebergs)
    int GetVerticesCount() const { return nodes.size(); }

    // Helper function to get the count of edges (ocean paths)
    int GetEdges() const { return edges.size(); }

    // Helper function to get the weight of an edge between two vertices
    int GetWeight(const std::string& from, const std::string& to) const;
};

