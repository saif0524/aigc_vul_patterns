#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    vector<string> victims{n + 1};
    victims[0] = a;
    victims[1] = b;
    for (int i = 1; i <= n; ++i) {
        string dead, replacement;
        cin >> dead >> replacement;
        if (victims[i - 1] == dead) victims[i] = victims[i - 2] == replacement ? victims[i - 1] : replacement;
        else victims[i] = victims[i - 1] == replacement ? victims[i - 2] : replacement;
        cout << victims[i - 1] << " " << victims[i] << "\n";
    }
    cout << victims[n] << " " << (victims[n] == victims[n - 2] ? victims[n - 1] : victims[n - 2]) << "\n";
}