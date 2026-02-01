#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int n, k;
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        
        vector<int> cards(n);
        for (int i = 0; i < n; ++i) {
            cin >> cards[i];
        }
        
        long long Ck = 0;
        for (int i = 0; i <= n - k; ++i) {
            long long product = 1;
            for (int j = 0; j < k; ++j) {
                product *= cards[i + j];
            }
            Ck = max(Ck, product);
        }
        
        long long max_grade = 0;
        bool no_game = true;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(cards[i], cards[j]);
                
                long long Ck_prime = 0;
                for (int x = 0; x <= n - k; ++x) {
                    long long product = 1;
                    for (int y = 0; y < k; ++y) {
                        product *= cards[x + y];
                    }
                    Ck_prime = max(Ck_prime, product);
                }
                
                if (Ck_prime > Ck) {
                    max_grade = max(max_grade, Ck_prime - Ck);
                    no_game = false;
                }
                
                swap(cards[i], cards[j]);
            }
        }
        
        if (no_game) {
            cout << "NO GAME" << endl;
        } else {
            cout << max_grade << endl;
        }
    }
    
    return 0;
}