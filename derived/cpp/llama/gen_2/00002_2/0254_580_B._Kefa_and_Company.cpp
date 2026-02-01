#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Friend {
    int money;
    int friendship;
};

bool compareFriends(const Friend& a, const Friend& b) {
    return a.money < b.money;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<Friend> friends(n);
    for (int i = 0; i < n; i++) {
        cin >> friends[i].money >> friends[i].friendship;
    }

    sort(friends.begin(), friends.end(), compareFriends);

    int maxFriendship = 0;
    for (int i = 0; i < n; i++) {
        int currentFriendship = friends[i].friendship;
        int maxMoney = friends[i].money;

        for (int j = i + 1; j < n; j++) {
            if (friends[j].money - maxMoney < d) {
                currentFriendship += friends[j].friendship;
                maxMoney = max(maxMoney, friends[j].money);
            } else {
                break;
            }
        }

        maxFriendship = max(maxFriendship, currentFriendship);
    }

    cout << maxFriendship << endl;

    return 0;
}