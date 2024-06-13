#include "graph.hpp"

// Constructor for Graph class
Graph::Graph() {}

// Convert a string to uppercase
std::string Graph::ToUpperCase(const std::string& str) {
    std::string upperStr = str;
    std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}

// sorts edges by weight
bool Graph::CompareEdges(const Edge* e1, const Edge* e2) {
    return e1->weight < e2->weight;
}

// Add a new vertex (iceberg) to graph
void Graph::AddVertex() {
    // Calculate index of next iceberg
    int index = nodes.size();

    // Calculate letter part of name (A-Z)
    char letter = 'A' + (index % 26);

    // Calculate numeric suffix part of name
    int suffix = index / 26;

    // Construct name with both parts
    std::string icebergName;
    icebergName = std::string(1, letter) + std::to_string(suffix); // Append suffix

    // Allocate memory for new node using new
    GraphNode* newNode = new GraphNode{icebergName};

    // Add the new node to the vector
    nodes.push_back(newNode);

    std::cout << "Successfully added iceberg '" << icebergName << "'.\n";
}

bool Graph::AddEdge(const std::string& from, const std::string& to, int weight) {
    std::string fromUpper = ToUpperCase(from);
    std::string toUpper = ToUpperCase(to);

    // Find source and destination icebergs
    GraphNode* sourceNode = nullptr;
    GraphNode* destNode = nullptr;

     //'auto' automatically deduces the type of a variable from its initializer
    for (auto node : nodes) {
        if (ToUpperCase(node->name) == fromUpper)
            sourceNode = node;
        if (ToUpperCase(node->name) == toUpper)
            destNode = node;
    }

    // Check for invalid source or destination icebergs
    if (!sourceNode || !destNode) {
        std::cerr << "One or both icebergs do not exist.\n";
        return false;
    }

    // Check adding an edge to the same iceberg
    if (from == to) {
        std::cerr << "Cannot create an edge within the same iceberg.\n";
        return false;
    }
    
    // Check for invalid distance
    if (weight < 1 || weight > 40) {
        std::cerr << "Distance must be between 1 and 40 miles.\n";
        return false;
    }

    // Check if edge already exists
    for (auto edge : sourceNode->neighbors) {
        if ((edge->source == sourceNode && edge->destination == destNode) ||
            (edge->destination == sourceNode && edge->source == destNode)) {
            std::cerr << "Edge between these icebergs already exists.\n";
            return false;
        }
    }

    // Allocate memory for new edge using new
    Edge* newEdge = new Edge{weight, sourceNode, destNode};

    // Add new edge to the vector
    edges.push_back(newEdge);

    // Add edge to source and destination nodes
    sourceNode->neighbors.push_back(newEdge);
    destNode->neighbors.push_back(newEdge);

    std::cout << "Successfully added edge between icebergs '" << ToUpperCase(from) << "' and '" << ToUpperCase(to) << "'.\n";
    return true;
}


// Method to find shortest path between two vertices
int Graph::ShortestPath(const std::string& src, const std::string& dest) {
    std::string srcUpper = ToUpperCase(src);
    std::string destUpper = ToUpperCase(dest);

    // Find index of source and destination vertices
    int source = -1, destination = -1;
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (ToUpperCase(nodes[i]->name) == srcUpper)
            source = i;
        if (ToUpperCase(nodes[i]->name) == destUpper)
            destination = i;
    }

    // Check if both vertices exist
    if (source != -1 && destination != -1) {

        // Priority queue to select the next vertex with the smallest distance
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        // Initialize distances to all vertices as infinite
        std::vector<int> dist(nodes.size(), INT_MAX);
        std::vector<int> parent(nodes.size(), -1); // Parent array to store shortest path
        
        // Distance to the source is 0
        pq.push(std::make_pair(0, source));
        dist[source] = 0;

        while (!pq.empty()) {
            int u = pq.top().second; // Get the vertex with smallest distance
            pq.pop();
            // If reached destination, construct shortest path and return distance
            if (u == destination) {
                std::vector<int> shortestPath;
                int v = destination;
                while (v != -1) {
                    shortestPath.push_back(v);
                    v = parent[v];
                }
                std::reverse(shortestPath.begin(), shortestPath.end());
                
                // Print shortest path if it exists
                std::cout << "Shortest Path from " << ToUpperCase(src) << " to " << ToUpperCase(dest) << ": ";
                for (size_t i = 0; i < shortestPath.size(); ++i) {
                    std::cout << nodes[shortestPath[i]]->name;
                    if (i != shortestPath.size() - 1)
                        std::cout << " -> ";
                }
                std::cout << " (Distance: " << dist[destination] << ")" << std::endl;
                
                return dist[destination]; // Return total weight
            }
            // Iterate through all adjacent vertices of u
            for (Edge* neighbor : nodes[u]->neighbors) {

                // Determine the index of the neighbor vertex 'v' based on the direction of the edge
                int v = (neighbor->source == nodes[u]) ? std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), neighbor->destination)) :
                                                        std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), neighbor->source));
                int weight = neighbor->weight; // Edge weight

                // If there is a shorter path to v through u
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight; // Update distance to v
                    pq.push(std::make_pair(dist[v], v)); // Push updated distance to the priority queue
                    parent[v] = u; // Update parent for constructing shortest path
                }
            }

        }
        std::cout << "No path exists between " << src << " and " << dest << std::endl;
        return INT_MAX; // Return INT_MAX if no path exists
    } else {
        std::cout << "Error: One or both vertices not found!" << std::endl;
        return INT_MAX; // Return INT_MAX if one or both vertices do not exist
    }
}

// Method to find minimum spanning tree using Kruskal's algorithm
void Graph::MinSpanTree() {
    // Number of vertices
    int numVertices = nodes.size();

    // Initialize DSU
    DSU dsu(numVertices);

    // Collect all edges from the graph
    std::vector<Edge*> allEdges;
    for (auto node : nodes) {
        for (auto edge : node->neighbors) {

            // Ensure each edge is added only once
            if (edge->source == node) {
                allEdges.push_back(edge);
            }
        }
    }

    // Sort edges by weight
    std::sort(allEdges.begin(), allEdges.end(), [](Edge* a, Edge* b) {
        return a->weight < b->weight;
    });

    // Kruskal's algorithm
    std::vector<Edge*> mst;
    int totalWeight = 0; // Total weight of the MST
    for (auto edge : allEdges) {
        int u = std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), edge->source));
        int v = std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), edge->destination));

        // Check if adding this edge creates a cycle
        if (dsu.Find(u) != dsu.Find(v)) {

            // If not, add this edge to the MST
            mst.push_back(edge);
            totalWeight += edge->weight; // Update total weight
            dsu.Unite(u, v);
        }
    }

    // Print Minimum Spanning Tree and total weight
    std::cout << "Minimum Spanning Tree:\n";
    for (auto edge : mst) {
        std::cout << edge->source->name << " - " << edge->destination->name << " : " << edge->weight << " miles\n";
    }
    std::cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << " miles\n";
}

// Display the graph (icebergs and their connections)
void Graph::DisplayGraph() {
    std::cout << "Iceberg Adjacency List:\n";
    for (auto node : nodes) {
        std::cout << node->name << ": ";
        for (auto edge : node->neighbors) {

            // Determine neighboring node based on the direction
            std::string neighborName = (edge->source == node) ? edge->destination->name : edge->source->name;
            std::cout << neighborName << " (Weight: " << edge->weight << " miles) ";
        }
        std::cout << std::endl;
    }
}

// Get weight of an edge between two vertices
int Graph::GetWeight(const std::string& from, const std::string& to) const {
    // Find the edge between the source and destination vertices
    for (Edge* edge : edges) {
        // Check if the edge connects the given vertices
        if ((edge->source->name == from && edge->destination->name == to) ||
            (edge->source->name == to && edge->destination->name == from)) {
            return edge->weight; // Return the weight of the edge
        }
    }
    // If no edge is found between the vertices, throw an exception
    throw std::runtime_error("No edge exists between the specified vertices.");
}







