# include "dijkstras.h"

int main() {
    Graph G;
    string filename = "graph.txt";  // Adjust filename as needed
    file_to_graph(filename, G);

    int source = 0, destination = 4;  // Example values
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    
    vector<int> path = extract_shortest_path(distances, previous, destination);
    int total_distance = distances[destination];

    print_path(path, total_distance);
    return 0;
}