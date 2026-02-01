#include <bits/stdc++.h>
using namespace std;

const int MAX = 255;

int n, m;
int A[MAX][MAX];
int row_max[MAX], col_max[MAX];
int used[MAX * MAX + 1];

bool check_conditions() {
    for (int i = 0; i < n; ++i) {
        int mx = -1;
        for (int j = 0; j < m; ++j)
            mx = max(mx, A[i][j]);
        if (mx != row_max[i])
            return false;
    }
    for (int j = 0; j < m; ++j) {
        int mx = -1;
        for (int i = 0; i < n; ++i)
            mx = max(mx, A[i][j]);
        if (mx != col_max[j])
            return false;
    }
    return true;
}

bool is_bitonic(vector<int>& vec) {
    int i = 0, j = vec.size() - 1;
    while (i + 1 < vec.size() && vec[i] < vec[i + 1])
        i++;
    while (j - 1 >= 0 && vec[j] < vec[j - 1])
        j--;
    return i >= j;
}

bool check_bitonicity() {
    for (int i = 0; i < n; ++i) {
        vector<int> row(A[i], A[i] + m);
        if (!is_bitonic(row))
            return false;
    }
    for (int j = 0; j < m; ++j) {
        vector<int> col;
        for (int i = 0; i < n; ++i)
            col.push_back(A[i][j]);
        if (!is_bitonic(col))
            return false;
    }
    return true;
}

bool backtrack(int pos) {
    if (pos == n * m + 1) {
        if (check_conditions() && check_bitonicity())
            return true;
        return false;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[pos]) {
                A[i][j] = pos;
                used[pos] = 1;
                if (backtrack(pos + 1))
                    return true;
                used[pos] = 0;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
            row_max[i] = max(row_max[i],A[i][j]);
            col_max[j] = max(col_max[j],A[i][j]);
        }
    }
    memset(used,0,sizeof(used));
    for(int i=1;i<=n*m;i++)
        used[i]=1;
    for(int i=0;i<n;i++)
        used[row_max[i]]=0;
    for(int j=0;j<m;j++)
        used[col_max[j]]=0;
    if(backtrack(1)){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout << A[i][j] << " ";
            cout << "\n";
        }
    }
    else{
        cout << "-1\n";
    }
}