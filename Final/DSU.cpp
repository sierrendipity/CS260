#include "DSU.hpp"

DSU::DSU(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

int DSU::Find(int x) {
    if (parent[x] != x) {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void DSU::Unite(int x, int y) {
    int px = Find(x);
    int py = Find(y);
    if (px != py) {
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
}