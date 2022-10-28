#include "kruskalMST.h"

KruskalMST::KruskalMST(WeightedGraph *G)
{
    weight = 0.0;
    priority_queue<Edge, vector<Edge>, CompareEdge> minHeap;
    for(Edge e : G->Edges())
        minHeap.push(e);

    DisjointSet ds;
    for(int i : G->Vertices())
        ds.makeSet(i);
    
    while(!minHeap.empty() && mst.size() < (unsigned int)G->V() - 1)
    {
        Edge e = minHeap.top();
        minHeap.pop();
        int v = e.either();
        int w = e.other(v);
        if(ds.Find(v) != ds.Find(w))
        {
            ds.Union(v,w);
            mst.push_back(e);
            weight += e.Weight();
        }
    }
}

std::vector<Edge> KruskalMST::Edges()
{
    return mst;
}  

double KruskalMST::Weight() const
{
    return weight;
}   