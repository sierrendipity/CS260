#ifndef TEST_HPP
#define TEST_HPP

#include "graph.hpp"

// Class to test the Graph class
class GraphTest {
public:
    // Test adding vertices to the graph
    bool TestAddVertex1();

    // Test adding vertices including duplicates
    bool TestAddVertex2();

    // Test adding edges between vertices
    bool TestAddEdge1();

    // Test adding an edge to a nonexistent vertex
    bool TestAddEdge2();

    // Test finding the shortest path between vertices
    bool TestShortestPath1();

    // Test finding the shortest path between disconnected vertices
    bool TestShortestPath2();

    // Test finding the minimum spanning tree of the graph
    bool TestMinSpanTree1();

    // Test finding the minimum spanning tree with a disconnected graph
    bool TestMinSpanTree2();
};

#endif