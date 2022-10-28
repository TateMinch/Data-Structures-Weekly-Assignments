#include "primMST.h"

PrimMST::PrimMST(WeightedGraph *G, int start)
{
    weight = 0.0;
    visit(G, start);
    while(!minHeap.empty())
    {
        Edge e = minHeap.top(); minHeap.pop();
        int v = e.either(), w = e.other(v);
        if(marked[v] && marked[w]) continue;
        mst.push_back(e);
        weight += e.Weight();
        if(!marked[v]) visit(G,v);
        if(!marked[w]) visit(G,w);
    }
}

void PrimMST::visit(WeightedGraph *G, int v)
{
    marked[v] = true;
    for(Edge e : G->adj(v))
        if(!marked[e.other(v)])
            minHeap.push(e);
}

std::vector<Edge> PrimMST::Edges()
{
    return mst;
}

double PrimMST::Weight() const
{
    return weight;
}