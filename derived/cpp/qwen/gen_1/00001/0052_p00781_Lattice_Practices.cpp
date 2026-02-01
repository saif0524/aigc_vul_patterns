#include <bits/stdc++.h>
using namespace std;

const int N = 10, M = 5, MAXN = 1 << 5;
int dp[2][16][16][16];
int boards[10][5];
int seen[MAXN], nboards[10][5];

int getHash(int board[]) {
    int hash = 0;
    for (int i = 0; i < 5; ++i) hash = (hash << 1) | board[i];
    return hash;
}

void normalizeBoard(int board[], int normBoard[][5]) {
    for (int i = 0; i < 5; ++i) normBoard[0][i] = board[i];
    for (int i = 0; i < 5; ++i) normBoard[1][4 - i] = board[i];
    for (int i = 0; i < 5; ++i) normBoard[2][i] = board[4 - i];
    for (int i = 0; i < 5; ++i) normBoard[3][4 - i] = board[4 - i];
    
    for (int i = 0; i < 4; ++i) {
        int hash = getHash(normBoard[i]);
        if (!seen[hash]++) {
            for (int j = 0; j < 5; ++j) nboards[hash][j] = normBoard[i][j];
        }
    }
}

bool matchBoards(int b1[][5], int b2[][5]) {
    for (int i = 0; i < 5; ++i) {
        if (b1[0][i] != b2[0][i] || b1[1][i] != b2[1][i]) return false;
    }
    return true;
}

bool validConfiguration(int vertical[], int horizontal[], int idx) {
    if (idx == 4) return true;
    for (int i = 0; i < 10; ++i) {
        int hash = getHash(boards[i]);
        int rhash1 = getHash(nboards[hash][0]);
        int rhash2 = getHash(nboards[hash][2]);
        if (seen[rhash1] && !vertical[rhash1]) {
            bool valid = true;
            for (int j = 0; j < 4; ++j) {
                if (!matchBoards(nboards[hash], boards[horizontal[j]])) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                vertical[rhash1] = 1;
                if (validConfiguration(vertical, horizontal, idx + 1)) return true;
                vertical[rhash1] = 0;
            }
        }
        if (seen[rhash2] && !horizontal[rhash2]) {
            bool valid = true;
            for (int j = 0; j < 4; ++j) {
                if (!matchBoards(nboards[hash], boards[vertical[j]])) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                horizontal[rhash2] = 1;
                if (validConfiguration(vertical, horizontal, idx + 1)) return true;
                horizontal[rhash2] = 0;
            }
        }
    }
    return false;
}

void preprocess() {
    for (int board = 0; board < (1 << 5); ++board) {
        int b[5];
        for (int i = 0; i < 5; ++i) b[i] = (board >> (4 - i)) & 1;
        normalizeBoard(b, nboards[board]);
    }
}

int main() {
    preprocess();
    string line;
    while (getline(cin, line) && line != "END") {
        istringstream iss(line);
        for (int i = 0; i < 10; ++i) {
            string s;
            iss >> s;
            for (int j = 0; j < 5; ++j) boards[i][j] = s[j] - '0';
        }
        memset(seen, 0, sizeof(seen));
        for (int i = 0; i < 10; ++i) {
            int hash = getHash(boards[i]);
            seen[hash] = 1;
        }
        int ans = 0;
        do {
            do {
                int vertical[16] = {0}, horizontal[16] = {0};
                if (validConfiguration(vertical, horizontal, 0)) ++ans;
            } while (next_permutation(boards[2]. boards[9] + 1));
        } while (next_permutation(boards[0], boards[9] + 1));
        cout << ans / 4 << "\n";
    }
}