// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

struct Segment {
    long long row, start, end;
};

struct Point {
    long long x, y;
};

bool compareSegments(const Segment& a, const Segment& b) {
    if (a.row != b.row) return a.row < b.row;
    return a.start < b.start;
}

bool isValidMove(Point from, Point to) {
    long long distanceX = abs(from.x - to.x);
    long long distanceY = abs(from.y - to.y);
    return (distanceX <= 1 && distanceY <= 1);
}

int main() {
    ((void)0);
    ((void)0);
    
    long long x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    
    int n;
    cin >> n;
    
    vector<Segment> segments(n);
    for (auto& seg : segments) {
        cin >> seg.row >> seg.start >> seg.end;
    }
    
    sort(segments.begin(), segments.end(), compareSegments);
    
    unordered_map<long long, vector<pair<long long, long long>>> rowToSegments;
    for (const auto& seg : segments) {
        rowToSegments[seg.row].emplace_back(seg.start, seg.end);
    }
    
    vector<pair<long long, long long>> mergedSegments;
    for (const auto& [row, segs] : rowToSegments) {
        vector<pair<long long, long long>> mergedRowSegments;
        sort(segs.begin(), segs.end());
        
        pair<long long, long long> currentSeg = segs[0];
        for (int i = 1; i < segs.size(); ++i) {
            if (segs[i].first <= currentSeg.second + 1) {
                currentSeg.second = max(currentSeg.second, segs[i].second);
            } else {
                mergedRowSegments.push_back(currentSeg);
                currentSeg = segs[i];
            }
        }
        mergedRowSegments.push_back(currentSeg);
        
        mergedSegments.insert(mergedSegments.end(), mergedRowSegments.begin(), mergedRowSegments.end());
    }
    
    map<long long, set<long long>> grid;
    for (const auto& [row, start, end] : mergedSegments) {
        for (long long col = start; col <= end; ++col) {
            grid[row].insert(col);
        }
    }
    
    if (grid[x0].count(y0) == 0 || grid[x1].count(y1) == 0) {
        cout << -1;
        return 0;
    }
    
    set<pair<long long, Point>> pq;
    unordered_map<long long, unordered_map<long long, bool>> visited;
    pq.emplace(0, Point{x0, y0});
    visited[x0][y0] = true;
    
    vector<pair<long long, long long>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
    
    while (!pq.empty()) {
        auto [dist, curr] = *pq.begin();
        pq.erase(pq.begin());
        
        if (curr.x == x1 && curr.y == y1) {
            cout << dist;
            return 0;
        }
        
        for (const auto& [dx, dy] : directions) {
            Point next = {curr.x + dx, curr.y + dy};
            if (grid.find(next.x) != grid.end() && grid[next.x].count(next.y) > 0 && !visited[next.x][next.y]) {
                visited[next.x][next.y] = true;
                pq.emplace(dist + 1, next);
            }
        }
    }
    
    cout << -1;
}