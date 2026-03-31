#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;

void print_DFS() {
  for (size_t i = 0; i < graph.size(); i++) {

    cout << "\n for node " << i << " : ";

    for (size_t j = 0; j < graph[i].size(); j++) {
      cout << graph[i][j] << " ";
    }
  }
}

void DFS(vector<vector<int>> &graph, vector<int> &visited, int node) {
  visited[node] = 1;
  cout << node << " ";
  for (int neighbor : graph[node]) {
    if (!visited[neighbor]) {
      DFS(graph, visited, neighbor);
    }
  }
}

int main() {

  while (1) {
    vector<int> neighbours;

    while (1) {
      cout << "Enter neighbour (-1 to stop for this node): ";
      int dataInput;
      cin >> dataInput;

      if (dataInput != -1) {
        neighbours.push_back(dataInput);
      } else
        break;
    }

    graph.push_back(neighbours);

    cout << "Continue adding nodes? (y/n): ";
    char continu;
    cin >> continu;
    if (continu == 'n')
      break;
  }

  cout << "\nLevel wise nodes:\n";
  print_DFS();

  cout << "\nEnter Starting point for DFS Traversal: ";
  int start;
  cin >> start;
  vector<int> visited(graph.size(), 0);
  cout << "DFS Traversal: ";
  DFS(graph, visited, start);
  return 0;
}