#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int lis[n];
    std::vector<int> prev(n, -1);
    std::vector<char> dir(n, ' ');
    int maxLen = 1;
    int maxIndex = 0;

    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
                dir[i] = 'R';
            }
        }
        if (lis[i] > maxLen) {
            maxLen = lis[i];
            maxIndex = i;
        }
    }

    std::vector<int> revA = a;
    std::reverse(revA.begin(), revA.end());

    int revLis[n];
    std::vector<int> revPrev(n, -1);
    std::vector<char> revDir(n, ' ');
    int revMaxLen = 1;
    int revMaxIndex = 0;

    for (int i = 0; i < n; i++) {
        revLis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (revA[i] > revA[j] && revLis[i] < revLis[j] + 1) {
                revLis[i] = revLis[j] + 1;
                revPrev[i] = j;
                revDir[i] = 'L';
            }
        }
        if (revLis[i] > revMaxLen) {
            revMaxLen = revLis[i];
            revMaxIndex = i;
        }
    }

    if (maxLen > revMaxLen) {
        std::cout << maxLen << std::endl;
        std::string path;
        int curr = maxIndex;
        while (curr != -1) {
            if (prev[curr] == -1) {
                path += 'L';
            } else {
                path += dir[curr];
            }
            curr = prev[curr];
        }
        std::reverse(path.begin(), path.end());
        std::cout << path << std::endl;
    } else if (maxLen < revMaxLen) {
        std::cout << revMaxLen << std::endl;
        std::string path;
        int curr = revMaxIndex;
        while (curr != -1) {
            if (revPrev[curr] == -1) {
                path += 'R';
            } else {
                path += revDir[curr];
            }
            curr = revPrev[curr];
        }
        std::reverse(path.begin(), path.end());
        std::cout << path << std::endl;
    } else {
        std::string path1;
        int curr1 = maxIndex;
        while (curr1 != -1) {
            if (prev[curr1] == -1) {
                path1 += 'L';
            } else {
                path1 += dir[curr1];
            }
            curr1 = prev[curr1];
        }
        std::reverse(path1.begin(), path1.end());

        std::string path2;
        int curr2 = revMaxIndex;
        while (curr2 != -1) {
            if (revPrev[curr2] == -1) {
                path2 += 'R';
            } else {
                path2 += revDir[curr2];
            }
            curr2 = revPrev[curr2];
        }
        std::reverse(path2.begin(), path2.end());

        if (path1 < path2) {
            std::cout << maxLen << std::endl;
            std::cout << path1 << std::endl;
        } else {
            std::cout << revMaxLen << std::endl;
            std::cout << path2 << std::endl;
        }
    }

    return 0;
}