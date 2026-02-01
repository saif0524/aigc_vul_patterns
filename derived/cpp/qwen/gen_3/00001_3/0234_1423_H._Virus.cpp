#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> daily_contacts(q + 1);
    int day = 0;

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            daily_contacts[day].push_back(x);
            daily_contacts[day].push_back(y);
        } else if (t == 2) {
            int z;
            cin >> z;

            set<int> contacted_people;
            
            for (int j = max(0, day - k + 1); j <= day; ++j) {
                for (int person : daily_contacts[j]) {
                    if (person == z) {
                        
                        vector<int> q;
                        vector<bool> visited(n + 1, false);
                        q.push_back(z);
                        visited[z] = true;
                        
                        int head = 0;
                        while (head < q.size()) {
                            int u = q[head++];
                            contacted_people.insert(u);
                            
                            for (int v : adj[u]) {
                                if (!visited[v]) {
                                    visited[v] = true;
                                    q.push_back(v);
                                }
                            }
                        }
                        
                        break;
                    }
                }
            }
            
            if(contacted_people.find(z) != contacted_people.end()){

              cout << contacted_people.size() << endl;
            } else{
                cout << 1 << endl;
            }
        } else {
            day++;
        }
    }

    return 0;
}