#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include "dijkstras.h"
#include <algorithm>


using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {

    int n = G.numVertices;
    vector<int> distances(n, INF);
    previous.assign(n, -1);
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});


    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if (dist > distances[u]) continue;

        for (const Edge& e : G[u]) {
            int v = e.dst, weight = e.weight;
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({distances[v], v});
            } 
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int v = destination; v != -1; v = previous[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    if (v.empty()) {
        cout << "\nTotal cost is " << total << "\n";
        return;
    }

    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) cout << " ";
    }
    cout << " \nTotal cost is " << total << "\n";  // Match expected format
}
