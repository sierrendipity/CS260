#ifndef DSU_HPP
#define DSU_HPP

#include <vector>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DSU(int n);

    int Find(int x);

    void Unite(int x, int y);
};

#endif




