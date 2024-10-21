#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define M 1000

// Node class template
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T d) : data(d), next(nullptr) {}
};

// Graph class template
template <typename T>
class Graph {
private:
    vector<Node<T>*> adjList;  // Adjacency list of nodes
    vector<bool> visited;       // Keeps track of visited nodes

public:
    Graph(int n) {
        adjList.resize(n, nullptr);   // Initialize adjacency list with n nodes
        visited.resize(n, false);     // Initialize all nodes as unvisited
    }

    // Function to create a new node
    Node<T>* insert(T d) {
        return new Node<T>(d);
    }

    // Function to add an edge between two nodes
    void addEdge(int i, T d) {
        Node<T>* newNode = insert(d);
        newNode->next = adjList[i];
        adjList[i] = newNode;
    }

    // DFS traversal function
    void dfs(int start) {
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int nodeIndex = s.top();
            s.pop();

            if (!visited[nodeIndex]) {
                visited[nodeIndex] = true;
                cout << "Visited node: " << nodeIndex << endl;

                // Add all adjacent nodes to the stack
                Node<T>* temp = adjList[nodeIndex];
                while (temp != nullptr) {
                    if (!visited[temp->data]) {
                        s.push(temp->data);
                    }
                    temp = temp->next;
                }
            }
        }
    }

    // Function to print the graph
    void print(int n) {
        for (int i = 0; i < n; ++i) {
            cout << "Node " << i << ": ";
            Node<T>* temp = adjList[i];
            while (temp != nullptr) {
                cout << temp->data;
                if (temp->next != nullptr) cout << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m, d;
    cout << "Enter the total number of nodes: ";
    cin >> n;

    Graph<int> graph(n);

    cout << "Enter nodes and their connections:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Enter number of nodes connected with node " << i << ": ";
        cin >> m;
        cout << "Enter the connected nodes: ";
        for (int j = 0; j < m; ++j) {
            cin >> d;
            graph.addEdge(i, d);
        }
    }

    cout << "\nGraph representation:\n";
    graph.print(n);

    cout << "\nDFS Traversal from node 0:\n";
    graph.dfs(0);

    return 0;
}
