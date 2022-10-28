#include "graph.h"

Graph::Graph() { }

Graph::Graph(istream &instream) : numVertices(0), numEdges(0)
{
   int v, w;
   while (!instream.eof())
   {
      instream >> v >> w;
      addEdge(v, w);
   }

   numVertices = vertices.size();
   for (int u : Vertices())
      numEdges += adj(u).size();

   numEdges /= 2;
}

Graph::Graph(const vector<vector<int>> &grid)
{
   // You need to write the constructor that will take a 2-d grid of values
   // and change it into an adjacency list representation.
   vector<pair<int, int>> p1;
   pair<int,int> temp;
   int rows = grid.size(), cols = grid[0].size();

   for(int i = 0; i < rows; i++)
   {
      for(int j = 0; j < cols; j++)
      {
         if(grid[i][j] == 1)
         {
            if((j != 0) && (grid[i][j-1] == 1))
            {
               temp.first = i * grid[i].size() + j;
               temp.second = i * grid[i].size() + (j-1);
               p1.push_back(temp);
            }
            if((j != cols - 1) && (grid[i][j+1] == 1))
            {
               temp.first = i * grid[i].size() + j;
               temp.second = i * grid[i].size() + (j+1);
               p1.push_back(temp);
            }
            if((i != rows - 1) && (grid[i+1][j] == 1))
            {
               temp.first = i * grid[i].size() + j;
               temp.second = (i+1) * grid[i].size() + j;
               p1.push_back(temp);
            }
            if((i != 0) && (grid[i-1][j] == 1))
            {
               temp.first = i * grid[i].size() + j;
               temp.second = (i-1) * grid[i].size() + j;
               p1.push_back(temp);
            }
         }
      }
   }

   int size = p1.size();
   for(int i = 0; i < size; i++)
   {
      size = p1.size() + 1;
      for(int j = 0; j < size; j++)
      {
         if((p1[i].first == p1[j].second) && (p1[i].second == p1[j].first))
         {
            p1.erase(p1.begin() + j);
         }
      }
   }

   size = p1.size();
   for(int i = 0; i < size; i++)
   {
      addEdge(p1[i].first, p1[i].second);
   }
}
   
Graph::~Graph() {}

int Graph::V() const { return numVertices ; }
int Graph::E() const { return numEdges ; }

set<int> Graph::Vertices() const
{
   set<int> retVal;
   for (auto &kv : vertices)
      retVal.insert(kv.first);

   return retVal;
}

set<int> Graph::adj(int v)
{
   return vertices[v];
}

// This implementation of addEdge presumes the graph is undirected
void Graph::addEdge(int v, int w)
{
   vertices[v].insert(w);
   vertices[w].insert(v);
}
