#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<string, int> two_gram_counts;
    for (int i = 0; i < n - 1; ++i) {
        string two_gram = s.substr(i, 2);
        two_gram_counts[two_gram]++;
    }

    string most_frequent_two_gram = "";
    int max_count = 0;
    for (auto const& [two_gram, count] : two_gram_counts) {
        if (count > max_count) {
            max_count = count;
            most_frequent_two_gram = two_gram;
        }
    }

    cout << most_frequent_two_gram << endl;

    return 0;
}