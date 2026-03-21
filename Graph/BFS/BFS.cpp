#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<vector<int>> const &graph, int start) {
  queue<int> q;
  vector<int> visited(graph.size(), 0);
  while (1) {

    visited[start] = 2;
    cout << start << " , \n";

    for (size_t i = 0; i < graph[start].size(); i++) {
      int position = graph[start][i];
      if (!visited[position]) {
        q.push(position);
        visited[position] = 1;
      }
    }

    if (!q.empty()) {
      start = q.front();
      q.pop();
    } else
      break;
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

  cout << "\nLevel wise nodes:\n";
  print_BFS(graph);
  
  
  cout << "\nEnter Starting point for BFS Traversal: ";int start;cin>>start;
  BFS(graph, start);
  return 0;
}