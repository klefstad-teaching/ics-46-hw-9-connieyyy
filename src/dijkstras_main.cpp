#include "dijkstras.h"
#include <iostream>

using namespace std;

void print_path(const vector<int>& v, int total) {
    cout << "Total: " << total << endl;
    for (int i = 0; i < v.length(); ++i) {
        cout << v[i] << " ";
    }
}