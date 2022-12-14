#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include "edge.h"

using namespace std;

#define WIDTH 900
#define HEIGHT 900
#define VERTEX_RADIUS 10
#define VERTEX_EDGE_BUFFER 2
#define VERTEX_NEIGHBOR_BUFFER VERTEX_RADIUS * 5

struct node
{
   int vertex;
   int dist;
   node(int v, int d) : vertex(v), dist(d) {}
   bool operator<(const node &rhs)
   {
      return (rhs.dist > dist);
   }
};

class Compare
{
public:
   bool operator()(node e, node f)
   {
      return (e < f);
   }
};

bool separation(int x, int y, vector<int> &verts)
{
   int min_dist = min(WIDTH, HEIGHT);
   int edgeGap = VERTEX_RADIUS + VERTEX_EDGE_BUFFER;
   if (x < edgeGap || x > WIDTH - edgeGap || 
       y < edgeGap || y > HEIGHT - edgeGap) return false;
   for (int w : verts)
   {
      int x2 = w % WIDTH;
      int y2 = w / WIDTH;
      int dist = sqrt(pow(x2-x, 2) + pow(y2-y, 2));
      min_dist = min(min_dist, dist);
   }
   if (min_dist < VERTEX_NEIGHBOR_BUFFER) return false;
   return true;
}

bool goodEdge(int v, int w, vector<pair<int, int>> &edges)
{
   if (v == w) return false;
   for (pair<int, int> p : edges)
      if ((p.first == v && p.second == w) || (p.first == w && p.second == v))
         return false;

   return true;
}

int distance(int v, int w)
{
   int x1 = v % WIDTH;
   int y1 = v / WIDTH;
   int x2 = w % WIDTH;
   int y2 = w / WIDTH;

   return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

vector<int> nearestNeighbors(vector<int> &vertices, int v, int degree)
{
   vector<int> nn;
   priority_queue<int, vector<node>, Compare> maxHeap;

   for (int w : vertices)
   {
      if (maxHeap.size() < (unsigned)(degree * 2)) 
         maxHeap.push(node(w, distance(v, w)));
      else
         if (v != w && distance(v, w) < maxHeap.top().dist)
         {
            maxHeap.push(node(w, distance(v, w)));
            maxHeap.pop();
         }
   }
    
   while (!maxHeap.empty())
   {
      nn.push_back(maxHeap.top().vertex);
      maxHeap.pop();
   }
   return nn;
}

// generateEdges will loop over our set of vertices and randomly pick a
// nearby vertex and add an edge.  We could just calculate the 2d distance
// between the two and assign a cost to the edge but that would not give
// interesting graphs for running things like Dijkstra's shortest path
// algorithm, AStar, or minimum spanning trees so we'll also generate
// random weights / costs for those edges in the range of 1 - 10 units
// This version will also generate random negative weights
vector<Edge> generateEdges(vector<int> &vertices, int vert, int d)
{
   vector<Edge> edges;
   for (int v : vertices)
   {
      vector<int> nn = nearestNeighbors(vertices, v, d);
      for (int i = 0 ; i < d ; i++)
      {
         int item = rand() % nn.size();
         double weight = rand () % 100 / 10.0;
         // negate the weight for every 10th edge
         if (rand() % 50 == 0) weight *= -1;
         edges.push_back(Edge(v, nn[item], weight));;
         // remove that neighbor so we don't get duplicates
         swap(nn[item], nn[nn.size()-1]);
         nn.pop_back();
      }
   }
   return edges;
}

// First generate some random, well-spaced points on the screen.  These will
// be our vertices.
// Next, start adding edges between the vertices
vector<Edge> generateEdgeList(int vert, int degree)
{
   int count = vert;
   vector<int> vertices;
   srand(time(NULL));

   while (count--)
   {
      int x, y;
      do
      {
         x = rand() % HEIGHT;
         y = rand() % WIDTH;
      } while(!separation(x, y, vertices));
      vertices.push_back(x + y * WIDTH);
   }
 
   return generateEdges(vertices, vert, degree);
}

int main(int argc, char *argv[])
{
   vector<pair<int, int>> edges;

   int V = 15;
   int D = 3;
   if (argc > 3)
   {
      cout << "Usage: " << argv[0] << "[V] [D]" << endl;
      cout << "optional: V = # vertices in the graph (default 15)" << endl;
      cout << "optional: D = average degree of each vertex (default 3)" << endl;
   }
   else
   {
      if (argc > 1)
      {
         try
         {
            V = stoi(argv[1]);
         }
         catch (...)
         {
            cout << "Usage: " << argv[0] << "[V] [D]" << endl;
            cout << "optional: V = # vertices in the graph (default 15)" << endl;
            cout << "optional: D = average degree of each vertex (default 3)" << endl;
            return -1;
         }
      }
      if (argc > 2)
      {
         try
         {
            D = stoi(argv[2]);
         }
         catch (...)
         {
            cout << "Usage: " << argv[0] << "[V] [D]" << endl;
            cout << "optional: V = # vertices in the graph (default 15)" << endl;
            cout << "optional: D = average degree of each vertex (default 3)" << endl;
         }
      }
   }
   for (Edge e : generateEdgeList(V, D))
   {
      int v = e.either(), w = e.other(v);
      cout << v << " " << w << " " << e.Weight() << endl;
   }

   return 0;
}
