#include<bits/stdc++.h>
using namespace std;

void showOptions()
{
    string locations[] = {
        "Hostel 13", "Dispensary", "H13/H11 alley", "NMC Junction",
        "Food Truck", "Hostel 4", "H2/H4 alley", "Parking Junction",
        "Hostel 2", "Lawn Circle Junction", "PMC Lawn Junction",
        "Lower Lawn Junction", "Hostel 3", "Hostel 1", "Main Building",
        "Main Building FR", "Main Building FL", "Main Building R",
        "Main Building L", "Main Building BR", "Main Building BL",
        "R&D", "Canteen (Apni Rasoi)", "IC Inner Canteen", "Production Dept."
    };

    int numLocations = sizeof(locations) / sizeof(locations[0]);

    // Print the locations
    for (int i = 0; i < numLocations; i++) {
        cout << i + 1 << ". " << locations[i] << "\n";
    }
    
}

void insertEdge(vector<pair<int, int> > adj[], int x, int y, int cost)
{
    adj[x].push_back(make_pair(y, cost));
    adj[y].push_back(make_pair(x, cost));
}

void pathprinting(int currnode, vector<int> prevnode)
{
    if(currnode == -1){
        return;
    }
    pathprinting(prevnode[currnode], prevnode);
    cout << currnode + 1 << " -> " ;
}

void shortestPathFinder(vector<pair<int, int> > adj[], int n, int source, int destination)
{
    vector<int> minDist(n , INT_MAX);
    minDist[source] = 0;
    
    vector<int> prevnode(n);
    prevnode[source] = -1;

    priority_queue< pair<int , int>, vector< pair <int , int> >, greater< pair<int , int > > > pq;
    pq.push(make_pair(0, source));

    while(!pq.empty()){
        
        int a = pq.top().second;
        pq.pop();

         for (auto itr : adj[a]) {
           
            int b = itr.first;
            int cost = itr.second;
 
            if (minDist[a] + cost < minDist[b]) {
                
                prevnode[b] = a;
                minDist[b] = minDist[a] + cost;
                pq.push(make_pair(minDist[b], b));

            }
        }
    }

    cout << "Vertex : " << source + 1 << " to " << destination + 1 << "\n\n";
    cout << "Distance : " << minDist[destination] << " metres" << "\n\n";
    cout << "Path : ";
    pathprinting(destination, prevnode);
    cout << "Arrived";
    
    
}

int main()
{
    int n = 25;
    vector<pair<int , int>> adj[n];
    int source, destination;

    int edges[][3] = {
        {0, 1, 237}, {0, 2, 273}, {1, 3, 188}, {2, 3, 115}, {2, 4, 160},
        {3, 4, 100}, {3, 6, 216}, {4, 5, 122}, {4, 11, 114}, {5, 9, 99},
        {6, 9, 106}, {6, 7, 221}, {9, 8, 128}, {9, 10, 131}, {8, 15, 101},
        {11, 12, 116}, {10, 13, 128}, {12, 10, 105}, {13, 16, 105}, {15, 14, 59},
        {14, 16, 52}, {7, 17, 57}, {17, 19, 178}, {19, 24, 51}, {24, 20, 60},
        {20, 23, 83}, {13, 21, 217}, {13, 18, 240}, {16, 21, 135}, {16, 18, 161},
        {18, 22, 81}, {23, 22, 35}, {7, 15, 112}
    };

    int numEdges = sizeof(edges) / sizeof(edges[0]);

    // Insert edges into the adjacency list
    for (int i = 0; i < numEdges; i++) {
        insertEdge(adj, edges[i][0], edges[i][1], edges[i][2]);
    }

    showOptions();
    
    cout << "Select Source : " << "\n";
    cin >> source;
    cout << "Select Destination : " << "\n";
    cin >> destination;
    cout << "\n";

    shortestPathFinder(adj, n, source - 1, destination - 1);

    cout << "\n\n";
    return 0;
}
