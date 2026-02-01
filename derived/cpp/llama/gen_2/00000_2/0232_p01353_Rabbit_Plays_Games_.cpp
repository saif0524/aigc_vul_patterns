#include <bits/stdc++.h>
using namespace std;

struct Character {
    long long health, attack, defense, agility;
};

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Character> characters(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> characters[i].health >> characters[i].attack >> characters[i].defense >> characters[i].agility;
    }

    sort(characters.begin() + 1, characters.end(), [](const Character& a, const Character& b) {
        return a.agility > b.agility;
    });

    long long result = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long damage = 0;

    while (true) {
        for (int i = 1; i <= n; i++) {
            if (characters[i].health > 0) {
                damage += max(0LL, characters[i].attack - characters[0].defense);
            }
        }

        int idx = -1;
        long long maxDamage = -INF;
        for (int i = 1; i <= n; i++) {
            if (characters[i].health > 0) {
                long long damageDealt = max(0LL, characters[0].attack - characters[i].defense);
                if (damageDealt > maxDamage) {
                    idx = i;
                    maxDamage = damageDealt;
                }
            }
        }

        if (idx != -1) {
            characters[idx].health -= maxDamage;
            if (characters[idx].health <= 0) {
                characters[idx].health = 0;
            }
        }

        if (characters[0].health <= damage) {
            cout << -1 << "\n";
            return 0;
        }

        bool hasEnemy = false;
        for (int i = 1; i <= n; i++) {
            if (characters[i].health > 0) {
                hasEnemy = true;
                break;
            }
        }

        if (!hasEnemy) {
            cout << damage << "\n";
            return 0;
        }
    }

    return 0;
}