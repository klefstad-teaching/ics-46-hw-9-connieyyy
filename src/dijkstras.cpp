#include "dijkstras.h"
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <fstream>

using namespace std;

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int i = destination; i != UNDEFINED; i = previous[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n"
    cout << "Total cost is " << total << endl;
}

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int numVertices = G.numVertices;
    // start off all distances with infinite
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    // starting node distance to itself is 0
    distances[source] = 0;
    previous[source] = UNDEFINED;

    // (priority (distance/ weight), data)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source});
    
    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (Edge edge: G.adjacencyList[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}
