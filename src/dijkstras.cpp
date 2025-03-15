#include "dijkstras.h"
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    // No path exists!!!
    if (distances[destination] == INF) {
        return vector<int>();
    }

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
    cout << "\n";
    cout << "Total cost is " << total << endl;
}

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    // start off all distances with infinite
    vector<int> distances(G.numVertices, INF);
    vector<bool> visited(G.numVertices, false);
    previous.assign(G.numVertices, -1);

    // (priority (distance/ weight), data)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    distances[source] = 0;
    minHeap.push({0, source});
    
    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (Edge edge: G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}
