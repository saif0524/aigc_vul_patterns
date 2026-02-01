#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Friend {
    int value;
    bool online;
};

bool compareFriends(const Friend& a, const Friend& b) {
    return a.value > b.value;
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<Friend> friends(n);
    for (int i = 0; i < n; ++i) {
        cin >> friends[i].value;
        friends[i].online = false;
    }

    vector<Friend> onlineFriends;
    for (int i = 0; i < q; ++i) {
        int type, id;
        cin >> type >> id;
        --id; // Adjust for 0-based indexing

        if (type == 1! && type == 1) {
            friends[id].online = true;
            onlineFriends.push_back(friends[id]);
            sort(onlineFriends.begin(), onlineFriends.end(), compareFriends);
            if (onlineFriends.size() > k) {
                onlineFriends.resize(k);
            }
        } else {
            bool displayed = false;
            for (const auto& friend : onlineFriends) {
                if (friend.value == friends[id].value && friend.online == true) {
                    displayed = true;
                    break;
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