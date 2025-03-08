#include "dijkstras.h"
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <fstream>

using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int numVertices = G.numVertices;
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous[source] = UNDEFINED;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source});
    
    while (!minHeap.empty()) {
        int u = minHeap.top.second;
        minHeap.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (Edge edge:G.adjacencyList[u]) {
            int v = edge.dest;
            int weight = edge.second;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}
