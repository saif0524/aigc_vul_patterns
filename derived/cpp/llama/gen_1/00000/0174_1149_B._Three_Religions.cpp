#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MAXQ = 1005;
const int MAXREL = 3;

char word[MAXN];
string rel[MAXREL];

bool can_coexist() {
    int pos[MAXREL] = {0, 0, 0};
    for (int i = 0; i < strlen(word); ++i) {
        bool found = false;
        for (int j = 0; j < MAXREL; ++j) {
            if (pos[j] < rel[j].size() && word[i] == rel[j][pos[j]]) {
                pos[j]++;
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    for (int j = 0; j < MAXREL; ++j) {
        if (pos[j] != rel[j].size()) return false;
    }
    return true;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    scanf("%s", word);
    for (int i = 0; i < q; ++i) {
        char op;
        int rel_id;
        char c;
        scanf(" %c %d", &op, &rel_id);
        rel_id--;
        if (op == '+') {
            scanf(" %c", &c);
            rel[rel_id] += c;
        } else {
            rel[rel_id].pop_back();
        }
        printf("%s\n", can_coexist() ? "YES" : "NO");
    }
    return 0;
}