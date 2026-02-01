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
                vector<int> sorted_online_friends = online_friends;
                sort(sorted_online_friends.begin(), sorted_online_friends.end(), [&](int a, int b) {
                    return t[a] > t[b];
                });

                
                int count = 0;
                for (int friend_index : sorted_online_friends) {
                    if(count < k){
                        if(friend_index == id-1){
                            displayed = true;
                            break;
                        }
                        count++;
                    } else {
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