#include "test.hpp"

#include <iostream>

// Test case for adding three vertices
bool GraphTest::TestAddVertex1() {
    std::cout << "\nTesting adding three vertices.\n";
    Graph g;
    g.AddVertex(); // A
    g.AddVertex(); // B
    g.AddVertex(); // C
    if (g.GetVerticesCount() == 3) {
        std::cout << "Number of Vertices: Passed (Expected: 3, Actual: " << g.GetVerticesCount() << ")\n";
        return true;
    } else {
        std::cout << "Number of Vertices: Failed (Expected: 3, Actual: " << g.GetVerticesCount() << ")\n";
        return false;
    }
}

// Test case for checking adjacency matrix size after adding a vertex
bool GraphTest::TestAddVertex2() {
    std::cout << "\nTesting iceberg matrix size after adding a vertex.\n";
    Graph g;
    int initialSize = g.GetVerticesCount(); // Initial size of adjacency matrix
    g.AddVertex(); // Add one vertex
    int newSize = g.GetVerticesCount(); // New size of adjacency matrix after adding one vertex

    // Check if the new size is equal to the initial size plus one
    if (newSize == initialSize + 1) {
        std::cout << "Iceberg Matrix Size: Passed\n";
        std::cout << "Initial Size: " << initialSize << ", New Size: " << newSize << std::endl;
        return true;
    } else {
        std::cout << "Iceberg Matrix Size: Failed\n";
        std::cout << "Expected: " << initialSize + 1 << ", Actual: " << newSize << std::endl;
        return false;
    }
}

// Test case for adding an edge
bool GraphTest::TestAddEdge1() {
    std::cout << "\nTesting adding an edge.\n";
    Graph g;
    g.AddVertex(); // A
    g.AddVertex(); // B
    g.AddEdge("A", "B", 10);
    if (g.GetEdgesCount() == 1 && g.GetWeight("A", "B") == 10) {
        std::cout << "Number of Edges and Edge Weight: Passed (Expected: 1, Weight: 10, Actual Edges: " << g.GetEdgesCount() << ", Actual Weight: " << g.GetWeight("A", "B") << ")\n";
        return true;
    } else {
        std::cout << "Number of Edges and Edge Weight: Failed (Expected: 1, Weight: 10, Actual Edges: " << g.GetEdgesCount() << ", Actual Weight: " << g.GetWeight("A", "B") << ")\n";
        return false;
    }
}

// Test case for adding an edge to a nonexistent vertex
bool GraphTest::TestAddEdge2() {
    std::cout << "\nTesting adding an edge to a nonexistent vertex.\n";
    Graph g;
    g.AddVertex(); // A
    g.AddVertex(); // B
    g.AddEdge("A", "C", 10);
    if (g.GetEdgesCount() == 0) {
        std::cout << "Adding Edge to Nonexistent Vertex: Passed (Expected: 0, Actual: " << g.GetEdgesCount() << ")\n";
        return true;
    } else {
        std::cout << "Adding Edge to Nonexistent Vertex: Failed (Expected: 0, Actual: " << g.GetEdgesCount() << ")\n";
        return false;
    }
}

// Test case for shortest path with three vertices and three edges (A->B->C)
bool GraphTest::TestShortestPath1() {
    std::cout << "\nTesting Shortest Path with three vertices and three edges (A->B->C).\n";
    Graph g;
    g.AddVertex(); // A
    g.AddVertex(); // B
    g.AddVertex(); // C
    g.AddEdge("A", "B", 10);
    g.AddEdge("B", "C", 15);
    g.AddEdge("A", "C", 20);
    int result = g.ShortestPath("A", "C");
    if (result == 20) {
        std::cout << "Shortest Path from A to C: Passed (Expected: 20, Actual: " << result << ")\n";
        return true;
    } else {
        std::cout << "Shortest Path from A to C: Failed (Expected: 20, Actual: " << result << ")\n";
        return false;
    }
}

// Test case for shortest path between disconnected vertices
bool GraphTest::TestShortestPath2() {
    std::cout << "\nTesting Shortest Path between disconnected vertices.\n";
    Graph g;
    g.AddVertex(); // A
    g.AddVertex(); // B
    g.AddVertex(); // C
    g.AddEdge("A", "B", 10);
    int result = g.ShortestPath("A", "C");
    if (result == INF) { // Since there is no path, it should return INF
        std::cout << "Shortest Path from A to C (Disconnected): Passed (Expected: INF, Actual: " << result << ")\n";
        return true;
    } else {
        std::cout << "Shortest Path from A to C (Disconnected): Failed (Expected: INF, Actual: " << result << ")\n";
        return false;
    }
}

// Test case for minimum spanning tree with three vertices and three edges
bool GraphTest::TestMinSpanTree1() {
    std::cout << "\nTesting Minimum Spanning Tree with three vertices and three edges.\n";
    Graph g;
    g.AddVertex(); // A
    g.AddVertex(); // B
    g.AddVertex(); // C
    g.AddEdge("A", "B", 10);
    g.AddEdge("B", "C", 15);
    g.AddEdge("A", "C", 20);
    int result = g.MinSpanTree();
    if (result == 25) { // MST weight should be 25 (10 + 15)
        std::cout << "Minimum Spanning Tree Weight: Passed (Expected: 25, Actual: " << result << ")\n";
        return true;
    } else {
        std::cout << "Minimum Spanning Tree Weight: Failed (Expected: 25, Actual: " << result << ")\n";
        return false;
    }
}

// Test case for minimum spanning tree with disconnected graph
bool GraphTest::TestMinSpanTree2() {
    std::cout << "\nTesting Minimum Spanning Tree with disconnected graph.\n";
    Graph g;
    g.AddVertex(); // A
    g.AddVertex(); // B
    g.AddVertex(); // C
    int result = g.MinSpanTree();
    if (result == 0) { // MST of a completely disconnected graph should be 0
        std::cout << "Minimum Spanning Tree Weight (Disconnected): Passed (Expected: 0, Actual: " << result << ")\n";
        return true;
    } else {
        std::cout << "Minimum Spanning Tree Weight (Disconnected): Failed (Expected: 0, Actual: " << result << ")\n";
        return false;
    }
}