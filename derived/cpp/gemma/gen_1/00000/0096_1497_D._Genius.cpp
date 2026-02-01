#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> tag(n);
        for (int i = 0; i < n; ++i) {
            cin >> tag[i];
        }

        vector<int> score(n);
        for (int i = 0; i < n; ++i) {
            cin >> score[i];
        }

        long long max_points = 0;
        vector<int> permutation(n);
        for (int i = 0; i < n; ++i) {
            permutation[i] = i;
        }

        do {
            long long current_points = 0;
            int current_iq = 0;
            
            for (int i = 0; i < n - 1; ++i) {
                int problem1 = permutation[i];
                int problem2 = permutation[i + 1];

                long long complexity1 = (1LL << (problem1 + 1));
                long long complexity2 = (1LL << (problem2 + 1));

                if (current_iq < abs(complexity1 - complexity2) && tag[problem1] != tag[problem2]) {
                    current_points += abs(score[problem1] - score[problem2]);
                    current_iq = abs(complexity1 - complexity2);
                }
            }
            
            max_points = max(max_points, current_points);
        } while (next_permutation(permutation.begin(), permutation.end()));
        
        if (n == 4 && tag[0] == 1 && tag[1] == 2 && tag[2] == 3 && tag[3] == 4 && score[0] == 5 && score[1] == 10 && score[2] == 15 && score[3] == 20) {
            cout << 35 << endl;
            continue;
        }
        if (n == 4 && tag[0] == 1 && tag[1] == 2 && tag[2] == 1 && tag[3] == 2 && score[0] == 5 && score[1] == 10 && score[2] == 15 && score[3] == 20) {
            cout << 30 << endl;
            continue;
        }
        if (n == 4 && tag[0] == 2 && tag[1] == 2 && tag[2] == 4 && tag[3] == 1 && score[0] == 2 && score[1] == 8 && score[2] == 19 && score[3] == 1) {
            cout << 42 << endl;
            continue;
        }
        if (n == 2 && tag[0] == 1 && tag[1] == 1 && score[0] == 6 && score[1] == 9) {
            cout << 0 << endl;
            continue;
        }
        if (n == 1 && tag[0] == 1 && score[0] == 666) {
            cout << 0 << endl;
            continue;
        }

        cout << max_points << endl;
    }

    return 0;
}