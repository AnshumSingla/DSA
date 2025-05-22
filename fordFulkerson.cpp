#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

#define V 6 // Adjust the number of vertices based on the graph

// Performs BFS and stores path from source to sink
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
  vector<bool> visited(V, false);
  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (int v = 0; v < V; v++)
    {
      if (!visited[v] && rGraph[u][v] > 0)
      {
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }
  return visited[t];
}

// Ford-Fulkerson algorithm using Edmonds-Karp (BFS)
int fordFulkerson(int graph[V][V], int s, int t)
{
  int u, v;

  // Create residual graph and initialize it
  int rGraph[V][V];
  for (u = 0; u < V; u++)
    for (v = 0; v < V; v++)
      rGraph[u][v] = graph[u][v];

  int parent[V]; // Stores path
  int max_flow = 0;

  // Augment flow while there is a path from s to t
  while (bfs(rGraph, s, t, parent))
  {
    int path_flow = INT_MAX;

    // Find minimum residual capacity in path
    for (v = t; v != s; v = parent[v])
    {
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }

    // Update residual capacities
    for (v = t; v != s; v = parent[v])
    {
      u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }

    // Add flow to overall flow
    max_flow += path_flow;
  }

  return max_flow;
}

// Example usage
int main()
{
  // Example graph: each value represents capacity
  int graph[V][V] = {
      {0, 16, 13, 0, 0, 0},
      {0, 0, 10, 12, 0, 0},
      {0, 4, 0, 0, 14, 0},
      {0, 0, 9, 0, 0, 20},
      {0, 0, 0, 7, 0, 4},
      {0, 0, 0, 0, 0, 0}};

  int source = 0, sink = 5;

  cout << "The maximum possible flow is "
       << fordFulkerson(graph, source, sink) << endl;

  return 0;
}
