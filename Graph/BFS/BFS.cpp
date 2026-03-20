#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<vector<int>>const &graph, int start) {
  queue<int> queue;
  vector<bool> visited(graph.size(), false);
  while (1) {

    visited[start] = true;
    cout << start<<" , \n";

    for (size_t i = 0; i < graph[start].size(); i++) {

      if (!visited[graph[start][i]])
        queue.push(graph[start][i]);

    }

    if (!queue.empty()) {
    start = queue.front();
    queue.pop();
    }else break;
  }
}

void print_BFS(vector<vector<int>> &graph) {
  for (size_t i = 0; i < graph.size(); i++) {
    cout << "Node " << i << ": ";
    for (size_t j = 0; j < graph[i].size(); j++) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> graph;

  while (true) {
    vector<int> neighbours;

    while (true) {
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

  cout << "\nAdjacency List:\n";
  print_BFS(graph);
  BFS(graph, 0);
  return 0;
}