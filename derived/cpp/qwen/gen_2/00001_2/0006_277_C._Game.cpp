#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    set<pair<long long, long long>> horizontalCuts, verticalCuts;
    for(long long i=0;i<k;i++){
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){
            verticalCuts.insert({min(y1, y2), max(y1, y2)});
        }
        else if(y1 == y2){
            horizontalCuts.insert({min(x1, x2), max(x1, x2)});
        }
    }
    long long rowCount = horizontalCuts.size() + 1;
    long long colCount = verticalCuts.size() + 1;
    long long cellCount = rowCount * colCount;
    if(cellCount % 2 == 0){
        cout << "SECOND";
        return 0;
    }
    long long targetCellCount = (cellCount + 1) / 2;
    long long currentRowCount = 1, currentColCount = 1;
    long long currentCellCount = 1;
    for(auto &cut : horizontalCuts){
        currentRowCount++;
        currentCellCount += currentColCount;
        if(currentCellCount >= targetCellCount){
            cout << "FIRST\n";
            cout << currentRowCount-1 << " 0 " << currentRowCount-1 << " " << m;
            return 0;
        }
    }
    for(auto &cut : verticalCuts){
        currentColCount++;
        currentCellCount += currentRowCount;
        if(currentCellCount >= targetCellCount){
            cout << "FIRST\n";
            cout << "0 " << currentColCount-1 << " " << n << " " << currentColCount-1;
            return 0;
        }
    }
    cout << "SECOND";
}