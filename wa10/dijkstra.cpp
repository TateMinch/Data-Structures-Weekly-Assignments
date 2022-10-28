#include "dijkstra.h"

Dijkstra::Dijkstra(WeightedGraph *G, int s)
{
    for(int i : G->Vertices())
        dist[i] = std::numeric_limits<double>::infinity();

    start = s;
    dist[start] = 0.0;
    pq.push(DijNode(start,0));
    while(!pq.empty())
    {
        int v = pq.top().vertex; 
        pq.pop();

        known[v] = true;
        for(Edge e : G->adj(v))
            relax(v,e);
    }
}

void Dijkstra::relax(int v, Edge e)
{
    int w = e.other(v);
    if(dist[w] > dist[v] + e.Weight())
    {
        dist[w] = dist[v] + e.Weight();
        pq.push(DijNode(w, dist[w]));
        prev[w] = v;
    }
}

bool Dijkstra::hasPath(int v)
{
    return dist[v] != std::numeric_limits<double>::infinity();
}

std::list<int> Dijkstra::pathTo(int v)
{
    std::list<int> path;
    if(!hasPath(v)) return path;

    for(int i = v; i != start; i = prev[i])
        path.push_front(i);
    
    path.push_front(start);
    return path;
}

double Dijkstra::distance(int v)
{
    return dist[v];
}