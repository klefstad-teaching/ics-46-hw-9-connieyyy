#include "dijkstras.h"
#include <iostream>

using namespace std;

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vecctor<int> path;
    for (int i = destination; i != UNDEFINED; i = previous[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    cout << "Total: " << total << endl;
    for (int i = 0; i < v.length(); ++i) {
        cout << v[i] << " ";
    }
}