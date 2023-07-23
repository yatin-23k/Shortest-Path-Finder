#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<tuple>
#include<algorithm>
#include<climits>
using namespace std;

string options[] = {
        "1. Hostel 13", "2. Dispensary", "3. H13/H11 alley", 
        "4. NMC Junction", "5. Food Truck", "6. Hostel 4",
        "7. H2/H4 alley", "8. Parking Junction", "9. Hostel 2",
        "10. Lawn Circle Junction", "11. PMC Lawn Junction",
        "12. Lower Lawn Junction", "13. Hostel 3", "14. Hostel 1",
        "15. Main Building", "16. Main Building FR",
        "17. Main Building FL", "18. Main Building R",
        "19. Main Building L", "20. Main Building BR",
        "21. Main Building BL", "22. R&D", "23. Canteen (Apni Rasoi)",
        "24. IC Inner Canteen", "25. Production Dept."
    };

/*
 * Function to display the list of location options.
 */
void showOptions() {
    for(const auto& option : options)
        cout << option << "\n";
    
    cout << "\n";
}

/*
 * Function to insert an edge between two nodes in an adjacency list.
 */
void insertEdge(vector<pair<int, int> > adj[], int x, int y, int cost)
{
    // Create edge from x to y and from y to x with cost
    adj[x].push_back(make_pair(y, cost));
    adj[y].push_back(make_pair(x, cost));
}

/*
 * Function to connect the nodes in the adjacency list.
 */
void makeConnections(vector<pair<int, int>> adj[])
{
    vector<tuple<int, int, int>> edges = {
        {0, 1, 237}, {0, 2, 273}, {1, 3, 188}, {2, 3, 115}, 
        {2, 4, 160}, {3, 4, 100}, {3, 6, 216}, {4, 5, 122}, 
        {4, 11, 114}, {5, 9, 99}, {6, 9, 106}, {6, 7, 221}, 
        {9, 8, 128}, {9, 10, 131}, {8, 15, 101}, {11, 12, 116}, 
        {10, 13, 128}, {12, 10, 105}, {13, 16, 105}, {15, 14, 59}, 
        {14, 16, 52}, {7, 17, 57}, {17, 19, 178}, {19, 24, 51}, 
        {24, 20, 60}, {20, 23, 83}, {13, 21, 217}, {13, 18, 240}, 
        {16, 21, 135}, {16, 18, 161}, {18, 22, 81}, {23, 22, 35}, 
        {7, 15, 112}
    };

    // Iterate over edges vector and insert each edge into the adjacency list
    for (const auto &edge : edges) {
        if (get<2>(edge) <= 0){
            // Edge weight cannot be zero or negative
            cout << "Invalid edge weight" << "\n";
            exit(0);
        }
        insertEdge(adj, get<0>(edge), get<1>(edge), get<2>(edge));
    }
}

/*
 * Function to recursively print the path taken to reach a node from a source node.
 */
void printPath(int currNode, vector<int> prevNode)
{
    // Base case for recursion. If currNode is -1, we have reached the source node.
    if(currNode == -1) return;
    
    // Recursively call printPath for the previous node.
    printPath(prevNode[currNode], prevNode);
    // Print the current node.
    cout << options[currNode] << " ---> " ;
}

/*
 * Function to find and print the shortest path between two nodes using Dijkstra's algorithm.
 */
void shortestPathFinder(vector<pair<int, int> > adj[], int n, int source, int destination)
{
    // Create a vector minDist to store the minimum distance from the source to each node.
    vector<int> minDist(n , INT_MAX);
    minDist[source] = 0;
    
    // Create a vector prevNode to store the previous node of each node in the shortest path.
    vector<int> prevNode(n);
    prevNode[source] = -1;

    // Create a priority queue pq where each element is a pair of a node and its distance from the source.
    priority_queue< pair<int , int>, vector< pair <int , int> >, greater< pair<int , int > > > pq;
    pq.push(make_pair(0, source));

    // Continue till the priority queue becomes empty.
    while(!pq.empty()){

        // Extract the node with the minimum distance from the source.
        int a = pq.top().second;
        pq.pop();

        // For each adjacent node of a,
        for (auto itr : adj[a]) {
           
            int b = itr.first;  // the adjacent node
            int cost = itr.second; // the cost of the edge from a to b

            // If the path through a is shorter, update the minimum distance of b and its previous node.
            if (minDist[a] + cost < minDist[b]) {
                prevNode[b] = a;
                minDist[b] = minDist[a] + cost;
                pq.push(make_pair(minDist[b], b));
            }
        }
    }

    // Print the shortest path from the source to the destination.
    cout << "Vertex : " << source + 1 << " to " << destination + 1 << "\n\n";
    cout << "Distance : " << minDist[destination] << " metres" << "\n\n";
    cout << "Path : ";
    printPath(destination, prevNode);
    cout << "Arrived";
}

int main()
{
    // n is the number of location options available
    int n = 25, source, destination;
    vector<pair<int , int>> adj[n];
   
    makeConnections(adj);
    
    showOptions();
    
    cout << "Select Source : \n";
    cin >> source;
    if(source < 1 || source > n){
        cout << "Invalid Source Selected \n";
        return 0;
    }

    cout << "Select Destination : \n";
    cin >> destination;
    if(destination < 1 || destination > n){
        cout << "Invalid Destination Selected \n";
        return 0;
    }
    cout << "\n";

    shortestPathFinder(adj, n, source - 1, destination - 1);

    cout << "\n\n";
    return 0;
}
