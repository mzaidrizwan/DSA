#include <cmath>
#include <cstddef>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

void BFS(vector<vector<int>> const &graph, int start) {
  queue<int> q;
  q.push(start);
  vector<int> visited(graph.size(), 0);
  vector<string> distances(graph.size());
  distances[0]=to_string(start);

  while (!q.empty()) {
    start = q.front();
    q.pop();

    visited[start] = 2;
    // cout << start << " , ";

    for (size_t i = 0; i < graph[start].size(); i++) {
      int neighbour = graph[start][i];
      if (!visited[neighbour]) {
        q.push(neighbour);
        visited[neighbour] = 1;

        distances[neighbour] = distances[start] + "-" + to_string(neighbour);
        
        cout << endl << " path for "<<neighbour<<" : "<<distances[neighbour] <<"| distance : "<<ceil(distances[neighbour].length()/2) <<" unit";
      }
    }
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
  print_BFS(graph);

  cout << "\nEnter Starting point for BFS Traversal: ";
  int start;
  cin >> start;
  BFS(graph, start);
  return 0;
}