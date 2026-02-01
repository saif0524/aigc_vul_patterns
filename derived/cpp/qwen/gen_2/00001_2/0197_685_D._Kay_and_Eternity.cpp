#include <bits/stdc++.h>
using namespace std;

const int MAXK = 305;
const int MAXN = 100005;

struct Point {
    long long x, y;
};

int cnt[MAXK*MAXK];
Point points[MAXN];

bool compX(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool compY(const Point &a, const Point &b) {
    return a.y < b.y;
}

void solve(int k, int n) {
    int curCnt = 0;
    int xIdx = 0;
    int yIdx = 0;
    
    sort(points, points + n, compX);
    
    for (int i = 0; i < n; ++i) {
        while (xIdx < n && points[xIdx].x < points[i].x) {
            long long y1 = points[xIdx].y;
            long long y2 = points[xIdx].y + k - 1;
            while (yIdx < n && points[yIdx].y <= y2) {
                if (points[yIdx].y >= y1) {
                    ++curCnt;
                }
                ++yIdx;
            }
            --xIdx;
        }
        
        long long x1 = points[i].x;
        long long x2 = points[i].x + k - 1;
        long long y1 = points[i].y;
        long long y2 = points[i].y + k - 1;
        
        while (xIdx < n && points[xIdx].x <= x2) {
            while (yIdx < n && points[yIdx].y <= y2) {
                if (points[yIdx].y >= y1) {
                    ++curCnt;
                }
                ++yIdx;
            }
            ++xIdx;
        }
        
        int myCnt = 0;
        for (int j = 0; j < xIdx && points[j].x <= x2; ++j) {
            if (points[j].y >= y1 && points[j].y <= y2) {
                ++myCnt;
            }
        }
        
        cnt[myCnt]++;
        curCnt -= myCnt;
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << (i == n ? '\n' : ' ');
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> points[i].x >> points[i].y;
    }
    solve(k, n);
}