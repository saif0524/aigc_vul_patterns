#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<bool> online(n, false);
    vector<int> online_friends;

    for (int i = 0; i < q; ++i) {
        int type, id;
        cin >> type >> id;

        if (type == 1) {
            online[id - 1] = true;
            online_friends.push_back(id - 1);
        } else {
            bool displayed = false;
            if (online[id - 1]) {
                vector<int> sorted_friends;
                for(int j = 0; j < online_friends.size(); ++j) {
                    sorted_friends.push_back(online_friends[j]);
                }

                sort(sorted_friends.begin(), sorted_friends.end(), [&](int a, int b) {
                    return t[a] > t[b];
                });
                
                int count = 0;
                for(int j = 0; j < sorted_friends.size(); ++j) {
                    if(count < k)
                    {
                        if(sorted_friends[j] == id - 1)
                        {
                            displayed = true;
                            break;
                        }
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (displayed) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}