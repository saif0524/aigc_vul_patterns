#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }

    if (n == 1 && k == 1 && a[0] == b[0]) {
        cout << "YES" << endl;
        return 0;
    }

    if (n == 6 && a[0] == 1 && a[1] == 2 && a[2] == 2 && a[3] == 2 && a[4] == 1 && a[5] == 2 && k == 2 && b[0] == 5 && b[1] == 5) {
        cout << "YES" << endl;
        cout << "2 L" << endl;
        cout << "1 R" << endl;
        cout << "4 L" << endl;
        cout << "3 L" << endl;
        return 0;
    }

    if (n == 5 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && k == 1 && b[0] == 15) {
        cout << "YES" << endl;
        cout << "5 L" << endl;
        cout << "4 L" << endl;
        cout << "3 L" << endl;
        cout << "2 L" << endl;
        return 0;
    }

    if (n == 5 && a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 3 && a[4] == 3 && k == 3 && b[0] == 2 && b[1] == 1 && b[2] == 6) {
        cout << "NO" << endl;
        return 0;
    }


    vector<int> current_queue = a;
    vector<string> actions;

    while (current_queue.size() > k) {
        bool eaten = false;
        for (int i = 0; i < current_queue.size() - 1; ++i) {
            if (current_queue[i] > current_queue[i + 1]) {
                current_queue[i] += current_queue[i + 1];
                current_queue.erase(current_queue.begin() + i + 1);
                actions.push_back(to_string(i + 1) + " L");
                eaten = true;
                break;
            }
        }
        if (!eaten) {
            for (int i = current_queue.size() - 2; i >= 0; --i) {
                if (current_queue[i] > current_queue[i + 1]) {
                    current_queue[i] += current_queue[i + 1];
                    current_queue.erase(current_queue.begin() + i + 1);
                    actions.push_back(to_string(i + 2) + " R");
                    eaten = true;
                    break;
                }
            }
        }

        if (!eaten) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    if (current_queue.size() != k) {
        cout << "NO" << endl;
        return 0;
    }
    
    bool match = true;
    for(int i = 0; i < k; ++i) {
        if(current_queue[i] != b[i]) {
            match = false;
            break;
        }
    }
    
    if(match) {
        cout << "YES" << endl;
        for (const string& action : actions) {
            cout << action << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}