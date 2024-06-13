#pragma once

#include <string>

struct GraphNode;

struct Edge {
    int weight;
    GraphNode *source;
    GraphNode *destination;
};