#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    while (Q--) {
        string n;
        cin >> n;

        unordered_map<string, int> memo;
        int count = 0;

        while (n.length() > 1) {
            if (memo.find(n) != memo.end()) {
                count = -1;
                break;
            }

            memo[n] = count;
            int maxProduct = 0;

            for (int i = 1; i < n.length(); i++) {
                string left = n.substr(0, i);
                string right = n.substr(i);

                int product = stoi(left) * stoi(right);
                maxProduct = max(maxProduct, product);
            }

            n = to_string(maxProduct);
            count++;
        }

        cout << count << endl;
    }

    return 0;
}