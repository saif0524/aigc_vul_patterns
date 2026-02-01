#include <iostream>
#include <queue>
#include <set>
#include <utility>

using namespace std;

const int MAX = 1000000005;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << endl;
        return 0;
    }

    if (gcd(a, b) != 1) {
        cout << -1 << endl;
        return 0;
    }

    queue<pair<int, int>> q;
    set<int> visited;
    q.push(make_pair(a, 0));
    visited.insert(a);

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == b) {
            cout << steps << endl;
            return 0;
        }

        if (current % 2 == 0) {
            int next = current / 2;
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(make_pair(next, steps + 1));
            }
        }

        if (current % 3 == 0) {
            int next = current / 3;
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(make_pair(next, steps + 1));
            }
        }

        if (current % 5 == 0) {
            int next = current / 5;
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(make_pair(next, steps + 1));
            }
        }
    }

    if (a % 2 == 0 && b % 2 == 0) {
        int nextA = a / 2;
        int nextB = b / 2;
        if (nextA % 2 == 1 && nextB % 2 == 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (a % 3 == 0 && b % 3 == 0) {
        int nextA = a / 3 * 2;
        int nextB = b / 3 * 2;
        if (nextA % 3 == 2 && nextB % 3 == 2) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (a % 5 == 0 && b % 5 == 0) {
        int nextA = a / 5 * 4;
        int nextB = b / 5 * 4;
        if (nextA % 5 == 4 && nextB % 5 == 4) {
            cout << -1 << endl;
            return 0;
        }
    }

    int stepsA = 0, stepsB = 0;

    while (a != b) {
        if (a > b) {
            if (a % 2 == 0) {
                a /= 2;
            }
            else if (a % 3 == 0) {
                a = (a / 3) * 2;
            }
            else if (a % 5 == 0) {
                a = (a / 5) * 4;
            }
            stepsA++;
        }
        else {
            if (b % 2 == 0) {
                b /= 2;
            }
            else if (b % 3 == 0) {
                b = (b / 3) * 2;
            }
            else if (b % 5 == 0) {
                b = (b / 5) * 4;
            }
            stepsB++;
        }
    }

    cout << stepsA + stepsB << endl;

    return 0;
}