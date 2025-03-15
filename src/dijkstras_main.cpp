#include "dijkstras.h"
#include <iostream>

using namespace std;

int main() {
    string filename = "/home/connieay/46/hw9/src/small.txt";  
    Graph G;

    file_to_graph(filename, G);
    int source = 0;  
    int destination = 2;  


    vector<int> previous(G.numVertices, UNDEFINED);
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    vector<int> shortest_path = extract_shortest_path(distances, previous, destination);

    cout << "Shortest path from " << source << " to " << destination << ": ";
    print_path(shortest_path, distances[destination]);

    return 0;
}
