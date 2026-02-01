#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<string, int> counts;
    for (int i = 0; i < n - 1; ++i) {
        string two_gram = s.substr(i, 2);
        counts[two_gram]++;
    }

    string max_two_gram = "";
    int max_count = 0;
    for (auto const& [two_gram, count] : counts) {
        if (count > max_count) {
            max_count = count;
            max_two_gram = two_gram;
        }
    }

    cout << max_two_gram << endl;

    return 0;
}