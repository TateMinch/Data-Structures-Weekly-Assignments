#include "bellmanFord.h"

BellmanFord::BellmanFord(WeightedGraph *G, int s) : start(s)
{
    for(int i : G->Vertices())
        dist[i] = std::numeric_limits<double>::infinity();

    dist[start] = 0.0;

    for(int i = 0; i < G->V() - 1; i++)
        for(Edge e : G->Edges())
            relax(i, e);

    for(int i = 0; i < G->V() - 1; i++)
        for(Edge e : G->Edges())
            if(dist[i] + e.Weight() < dist[e.other(i)])
                dist[e.other(i)] = -1 * std::numeric_limits<double>::infinity(); 
}

void BellmanFord::relax(int v, Edge e)
{
    int w = e.other(v); 
    if (dist[v] + e.Weight() < dist[w])
    {
        dist[w] = dist[v] + e.Weight();
        prev[w] = v;
    }
}

bool BellmanFord::hasPath(int v)
{
    if(dist[v] == std::numeric_limits<double>::infinity()) return false;
    if(dist[v] == -1 * std::numeric_limits<double>::infinity()) return false; 
    return true;
}

std::list<int> BellmanFord::pathTo(int v)
{
    std::list<int> path;
    if(!hasPath(v)) return path;

    for(int i = v; i != start; i = prev[i])
        path.push_front(i);
    
    path.push_front(start);
    return path;
}

double BellmanFord::distance(int v)
{
    return dist[v];
}