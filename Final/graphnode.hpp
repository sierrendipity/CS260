#pragma once

#include <string>
#include <vector>

// Forward declaration of Edge
struct Edge;

struct GraphNode {
    std::string name;
    std::vector<Edge*> neighbors;
};