#include<bits/stdc++.h>
using namespace std;

void showoptions()
{
    cout << "1. Hostel 13" << "\n";
    cout << "2. Dispensary" << "\n";
    cout << "3. H13/H11 alley" << "\n";
    cout << "4. NMC Junction" << "\n";
    cout << "5. Food Truck" << "\n";
    cout << "6. Hostel 4" << "\n";
    cout << "7. H2/H4 alley" << "\n";
    cout << "8. Parking Junction" << "\n";
    cout << "9. Hostel 2" << "\n";
    cout << "10. Lawn Circle Junction" << "\n";
    cout << "11. PMC Lawn Junction" << "\n";
    cout << "12. Lower Lawn Junction" << "\n";
    cout << "13. Hostel 3" << "\n";
    cout << "14. Hostel 1" << "\n";
    cout << "15. Main Building" << "\n";
    cout << "16. Main Building FR" << "\n";
    cout << "17. Main Building FL" << "\n";
    cout << "18. Main Building R" << "\n";
    cout << "19. Main Building L" << "\n";
    cout << "20. Main Building BR" << "\n";
    cout << "21. Main Building BL" << "\n";
    cout << "22. R&D" << "\n";
    cout << "23. Canteen (Apni Rasoi)" << "\n";
    cout << "24. IC Inner Canteen" << "\n";
    cout << "25. Production Dept." << "\n\n";
    
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

void shortestpathfinder(vector<pair<int, int> > adj[], int n, int source, int destination)
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

    insertEdge(adj, 0, 1, 237);
    insertEdge(adj, 0, 2, 273);
    insertEdge(adj, 1, 3, 188);
    insertEdge(adj, 2, 3, 115);
    insertEdge(adj, 2, 4, 160);
    insertEdge(adj, 3, 4, 100);
    insertEdge(adj, 3, 6, 216);
    insertEdge(adj, 4, 5, 122);
    insertEdge(adj, 4, 11, 114);
    insertEdge(adj, 5, 9, 99);
    insertEdge(adj, 6, 9, 106);
    insertEdge(adj, 6, 7, 221);
    insertEdge(adj, 9, 8, 128);
    insertEdge(adj, 9, 10, 131);
    insertEdge(adj, 8, 15, 101);
    insertEdge(adj, 11, 12, 116);
    insertEdge(adj, 10, 13, 128);
    insertEdge(adj, 12, 10, 105);
    insertEdge(adj, 13, 16, 105);
    insertEdge(adj, 15, 14, 59);
    insertEdge(adj, 14, 16, 52);
    insertEdge(adj, 7, 17, 57);
    insertEdge(adj, 17, 19, 178);
    insertEdge(adj, 19, 24, 51);
    insertEdge(adj, 24, 20, 60);
    insertEdge(adj, 20, 23, 83);
    insertEdge(adj, 13, 21, 217);
    insertEdge(adj, 13, 18, 240);
    insertEdge(adj, 16, 21, 135);
    insertEdge(adj, 16, 18, 161);
    insertEdge(adj, 18, 22, 81);
    insertEdge(adj, 23, 22, 35);
    insertEdge(adj, 7, 15, 112);

    showoptions();
    
    cout << "Select Source : " << "\n";
    cin >> source;
    cout << "Select Destination : " << "\n";
    cin >> destination;
    cout << "\n";

    shortestpathfinder(adj, n, source - 1, destination - 1);

    cout << "\n\n";
    return 0;
}
