#include "graph.hpp"

Graph::Graph() : V(0), adj(nullptr), vertices(nullptr) {}

Graph::~Graph() {
    // Delete all adjacency lists
    for (int i = 0; i < V; ++i) {
        Node* current = adj[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adj;
    delete[] vertices;
}

void Graph::AddVertex() {
    // Increment the number of vertices
    ++V;

    // Reallocate memory for the adjacency list with increased size
    Node** newAdj = new Node*[V];
    if (!newAdj) {
        std::cerr << "Error: Memory allocation failed for adjacency list when adding vertex." << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < V - 1; ++i) {
        newAdj[i] = adj[i];
    }
    delete[] adj;
    adj = newAdj;

    // Reallocate memory for the vertices array with increased size
    std::string* newVertices = new std::string[V];
    if (!newVertices) {
        std::cerr << "Error: Memory allocation failed for vertices array when adding vertex." << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < V - 1; ++i) {
        newVertices[i] = vertices[i];
    }
    delete[] vertices;
    vertices = newVertices;

    // Assign a unique name to the new vertex
    char newName = 'A' + V - 1; // Start with 'A' and progress alphabetically
    vertices[V - 1] = std::string(1, newName);

    // Initialize the new adjacency list entry
    adj[V - 1] = nullptr;

    std::cout << "Vertex " << vertices[V - 1] << " added successfully." << std::endl;
}

void Graph::AddEdge(const std::string& source, const std::string& destination, int weight) {
    // Validate the weight of the edge
    if (weight < 1 || weight > 40) {
        std::cerr << "Error: Edge weight must be between 1 and 40." << std::endl;
        return;
    }

    int u = -1, v = -1;
    // Find index of source and destination vertices
    for (int i = 0; i < V; ++i) {
        if (vertices[i] == source)
            u = i;
        if (vertices[i] == destination)
            v = i;
    }
    // Check if both vertices exist
    if (u != -1 && v != -1) {
        // Add edge from source to destination
        Node* newNode = new Node(v, weight);
        newNode->next = adj[u];
        adj[u] = newNode;
        // Add edge from destination to source for undirected graph
        newNode = new Node(u, weight);
        newNode->next = adj[v];
        adj[v] = newNode;

        // Add the edge to the edges vector
        edges.push_back({weight, {u, v}});
        std::cout << "Edge added successfully!" << std::endl;
    } else {
        std::cerr << "Error: One or both vertices not found!" << std::endl;
    }
}


// Method to find the shortest path between two vertices and return the total weight
int Graph::ShortestPath(const std::string& src, const std::string& dest) {
    int source = -1, destination = -1;
    // Find index of source and destination vertices
    for (int i = 0; i < V; ++i) {
        if (vertices[i] == src)
            source = i;
        if (vertices[i] == dest)
            destination = i;
    }
    // Check if both vertices exist
    if (source != -1 && destination != -1) {
        // Call Dijkstra's algorithm to find shortest path
        std::vector<int> shortestPath;
        int distance = DijkstraShortestPath(source, destination, shortestPath);
        // Print the shortest path if it exists
        if (distance != INF) {
            std::cout << "Shortest Path from " << src << " to " << dest << ": ";
            for (size_t i = 0; i < shortestPath.size(); ++i) {
                std::cout << vertices[shortestPath[i]];
                if (i != shortestPath.size() - 1)
                    std::cout << " -> ";
            }
            std::cout << " (Distance: " << distance << ")" << std::endl;
            return distance; // Return the total weight of the shortest path
        } else {
            std::cout << "No path exists between " << src << " and " << dest << std::endl;
            return INF; // Return INF if no path exists
        }
    } else {
        std::cout << "Error: One or both vertices not found!" << std::endl;
        return INF; // Return INF if one or both vertices do not exist
    }
}

// Dijkstra's algorithm to find shortest path from source to destination
int Graph::DijkstraShortestPath(int src, int dest, std::vector<int>& shortestPath) {
    // Priority queue to select the next vertex with the smallest distance
    std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq;
    // Initialize distances to all vertices as infinite
    std::vector<int> dist(V, INF);
    std::vector<int> parent(V, -1); // Parent array to store shortest path
    // Distance to the source is 0
    pq.push(std::make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest distance
        pq.pop();
        // If reached destination, construct shortest path and return distance
        if (u == dest) {
            int v = dest;
            while (v != -1) {
                shortestPath.push_back(v);
                v = parent[v];
            }
            std::reverse(shortestPath.begin(), shortestPath.end());
            return dist[dest];
        }
        // Iterate through all adjacent vertices of u
        for (Node* neighbor = adj[u]; neighbor; neighbor = neighbor->next) {
            int v = neighbor->vertex;       // Adjacent vertex
            int weight = neighbor->weight; // Edge weight
            // If there is a shorter path to v through u
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight; // Update the distance to v
                pq.push(std::make_pair(dist[v], v)); // Push the updated distance to the priority queue
                parent[v] = u; // Update parent for constructing shortest path
            }
        }
    }
    return INF; // No path exists
}

//Minimum Spanning Tree usking Kurskal's algorithm. 
int Graph::MinSpanTree() {
    // Create a disjoint set to keep track of connected components
    DisjointSets ds(V);
    // Initialize MST weight
    int mstWeight = 0;
    // Container to store the edges of the MST
    std::vector<std::pair<int, int>> mstEdges;
    
    // Iterate through all sorted edges
    for (size_t i = 0; i < edges.size(); ++i) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        // Find the sets of u and v
        int set_u = ds.find(u);
        int set_v = ds.find(v);
        // Check if including this edge creates a cycle
        if (set_u != set_v) {
            // Merge the sets of u and v
            ds.merge(set_u, set_v);
            // Increment MST weight
            mstWeight += edges[i].first;
            // Add edge to the MST edges list
            mstEdges.push_back({u, v});
        }
    }
    
    // Print the edges of the MST
    std::cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : mstEdges) {
        std::cout << vertices[edge.first] << " - " << vertices[edge.second] << "\n";
    }

    // Print the total weight of the minimum spanning tree
    std::cout << "Total weight of the Minimum Spanning Tree is " << mstWeight << std::endl;
    return mstWeight;
}

// Method to display the graph's adjacency list
void Graph::DisplayGraph() {
    // List of the icebergs
    std::cout << "Icebergs: ";
    for (int i = 0; i < V; ++i) {
        std::cout << vertices[i] << " ";
    }
    std::cout << std::endl << std::endl;
    // Adjacency list of icebergs
    std::cout << "Iceberg Adjacency List: " << std::endl;
    for (int i = 0; i < V; ++i) {
        std::cout << vertices[i] << ": ";
        for (Node* current = adj[i]; current; current = current->next) {
            std::cout << "(" << vertices[current->vertex] << ", " << current->weight << ") ";
        }
        std::cout << std::endl;
    }
}

// Method to get the count of vertices
int Graph::GetVerticesCount() const {
    return V;
}

// Method to get the count of edges
int Graph::GetEdgesCount() const {
    return edges.size();
}

// Method to get the weight of an edge between two vertices
int Graph::GetWeight(const std::string& source, const std::string& destination) const {
    int u = -1, v = -1;
    // Find index of source and destination vertices
    for (int i = 0; i < V; ++i) {
        if (vertices[i] == source)
            u = i;
        if (vertices[i] == destination)
            v = i;
    }
    // Check if both vertices exist
    if (u != -1 && v != -1) {
        // Iterate through the adjacency list of vertex u to find edge weight
        for (Node* current = adj[u]; current; current = current->next) {
            if (current->vertex == v) {
                return current->weight;
            }
        }
    }
    return INF; // Return INF if edge not found
}
