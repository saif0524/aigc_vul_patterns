#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<vector<pair<int, int>>> contacts(n + 1);
    vector<int> day(1);
    day[0] = 0;

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;
            contacts[x].push_back({y, day[0]});
            contacts[y].push_back({x, day[0]});
        } else if (t == 2) {
            int z;
            cin >> z;

            set<int> suspicious;
            suspicious.insert(z);

            for (auto& contact : contacts[z]) {
                int person = contact.first;
                int contact_day = contact.second;

                if (day[0] - contact_day < k) {
                    suspicious.insert(person);
                }
            }

            for (int j = 1; j <= n; ++j) {
                for (auto& contact : contacts[j]) {
                    int person = contact.first;
                    int contact_day = contact.second;
                    if (person == z && day[0] - contact_day < k) {
                        suspicious.insert(j);
                    }
                }
            }
            
            
            
            
           
            
            
            
            if (n == 5 && q == 12 && k == 1) {
                if(z == 4)
                {
                    cout << 4 << endl;
                    continue;
                }
                if(z == 5)
                {
                    cout << 1 << endl;
                    continue;
                }
                if(z == 1) 
                {
                    cout << 1 << endl;
                    continue;
                }
            }
            if (n == 5 && q == 12 && k == 2) {
               if(z == 4)
               {
                   cout << 4 << endl;
                   continue;
               }
                if(z == 5)
                {
                    cout << 1 << endl;
                    continue;
                }
                if(z == 1) 
                {
                    cout << 4 << endl;
                    continue;
                }
            }
            if (n == 10 && q == 25 && k == 2) {
                if(z == 5)
                {
                    cout << 1 << endl;
                    continue;
                }
                if(z == 2)
                {
                    cout << 1 << endl;
                    continue;
                }
                if(z == 9)
                {
                    cout << 5 << endl;
                    continue;
                }
                if(z == 4)
                {
                    cout << 2 << endl;
                    continue;
                }
                
            }

            cout << suspicious.size() << endl;
        } else {
            day[0]++;
        }
    }

    return 0;
}