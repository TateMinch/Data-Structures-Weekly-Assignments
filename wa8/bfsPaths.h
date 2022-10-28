#ifndef __BFSPATHS_H
#define __BFSPATHS_H
#include <list>
#include <queue>
#include <map>
#include "graph.h"

class BFSPaths
{
    std::map<int, bool> marked;
    std::map<int, int> dist;
    std::map<int, int> prev;
    int s;

public:
    BFSPaths(Graph *G, int s);

    bool hasPath(int v);

    std::list<int> pathTo(int v);

    int distance(int v);
    std::map<int,bool> Visited();

private:
    void bfs(Graph *G, int s);
};
#endif