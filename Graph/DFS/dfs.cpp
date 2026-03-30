#include <codecvt>
#include <cstddef>
#include <iostream>
#include <stack>
#include <string>
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

string DFS(vector<int> visited, stack<int> prev, int current, string traversal) {

  bool haveUnvisitedNeighbor = false;

  traversal = traversal + " " + to_string(current);

  visited[current] = 2;

  prev.push(current);

  for (size_t i = 0; i < graph[current].size(); i++) {
    int neighbor = graph[current][i];
    if (!neighbor) {
      visited[neighbor] = 1;
      current = neighbor;
      haveUnvisitedNeighbor = true;
      break;
    }
  }

  if (haveUnvisitedNeighbor)
    return DFS(visited, prev, current, traversal);
  else {
    prev.pop();
    current = prev.top();
    prev.pop();
    return DFS(visited, prev, current, traversal);
  }

  if (prev.empty()) {
    return traversal;
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
  stack<int> prev;
  string r = "sdnd";
  cout << DFS(visited, prev, start, "");
  return 0;
}