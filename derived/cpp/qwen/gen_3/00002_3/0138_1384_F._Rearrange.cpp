#include <bits/stdc++.h>
using namespace std;

bool possible(vector<vector<int>>& mat, int n, int m, vector<int>& row_max, vector<int>& col_max) {
    vector<pair<int, int>> all(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            all[i * m + j] = {mat[i][j], i * m + j};
        }
    }
    sort(all.begin(), all.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });

    vector<int> assigned(n * m, -1);
    vector<int> row_used(n, 0);
    vector<int> col_used(m, 0);
    vector<int> row_last(n, 0);
    vector<int> col_last(m, 0);

    for (const auto& [val, idx] : all) {
        int row = idx / m;
        int col = idx % m;
        if (!row_used[row] && !col_used[col] && row_max[row] == val && col_max[col] == val) {
            assigned[idx] = 1;
            row_used[row] = 1;
            col_used[col] = 1;
            row_last[row] = col;
            col_last[col] = row;
        }
    }

    for (const auto& [val, idx] : all) {
        int row = idx / m;
        int col = idx % m;
        if (assigned[idx] != -1) continue;
        if (!row_used[row] && row_max[row] == val) {
            int start = col_last[row] + 1;
            int end = m - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (!col_used[mid]) {
                    assigned[idx] = 1;
                    row_used[row] = 1;
                    col_used[mid] = 1;
                    row_last[row] = mid;
                    col_last[mid] = row;
                    break;
                }
                if (mid < col_last[row]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        if (assigned[idx] != -1) continue;
        if (!col_used[col] && col_max[col] == val) {
            int start = row_last[col] + 1;
            int end = n - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (!row_used[mid]) {
                    assigned[idx] = 1;
                    row_used[mid] = 1;
                    col_used[col] = 1;
                    row_last[mid] = col;
                    col_last[col] = mid;
                    break;
                }
                if (mid < row_last[col]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
    }

    if (assigned != vector<int>(n * m, 1)) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(auto& row : mat){
        for(auto& cell : row){
            cin >> cell;
        }
    }
    vector<int> row_max(n);
    for(int i =0; i<n; i++){
        row_max[i] = *max_element(mat[i].begin(), mat[i].end());
    }
    vector<int> col_max(m, 0);
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            col_max[j] = max(col_max[j], mat[i][j]);
        }
    }
    vector<vector<int>> result(n, vector<int>(m, 0));
    for(int i =0; i<n; i++){
        fill(result[i].begin(), result[i].end(), 0);
    }
    vector<int> all(n*m);
    iota(all.begin(), all.end(), 1);
    sort(all.begin(), all.end(), [&](int a, int b){
        return row_max[a/m] > row_max[b/m] || (row_max[a/m] == row_max[b/m] && col_max[a%m] > col_max[b%m]);
    });
    vector<int> row_pos(n, 0);
    vector<int> col_pos(m, 0);
    vector<bool> row_used(n, false);
    vector<bool> col_used(m, false);
    int idx = 0;
    vector<int> assigned(n*m, -1);
    for(int i=0; i<n*m; i++){
        int val = all[i];
        int row = (val-1)/m;
        int col = (val-1)%m;
        if(!row_used[row] && !col_used[col] && row_max[row] == val && col_max[col] == val){
            result[row][col] = val;
            assigned[val-1] = 1;
            row_used[row] = true;
            col_used[col] = true;
            row_pos[row] = val-1;
            col_pos[col] = val-1;
        }
    }
    for(int i=0; i<n*m; i++){
        int val = all[i];
        int row = (val-1)/m;
        int col = (val-1)%m;
        if(assigned[val-1] != -1) continue;
        if(!row_used[row] && row_max[row] == val){
            int start = col_pos[row] + 1;
            int end = n*m-1;
            while(start <= end){
                int mid = (start+end)/2;
                int mid_row = mid/m;
                int mid_col = mid%m;
                if(!row_used[mid_row] && !col_used[mid_col]){
                    row_pos[row] = mid;
                    col_pos[mid_row] = mid;
                    result[mid/m][mid%m] = val;
                    row_used[row] = true;
                    col_used[mid_col] = true;
                    assigned[val-1] = 1;
                    break;
                }
                if(mid_col < col_pos[row]){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
        }
        if(assigned[val-1] != -1) continue;
        if(!col_used[col] && col_max[col] == val){
            int start = row_pos[col] + 1;
            int end = n*m-1;
            while(start <= end){
                int mid = (start+end)/2;
                int mid_row = mid/m;
                int mid_col = mid%m;
                if(!row_used[mid_row] && !col_used[mid_col]){
                    row_pos[mid_row] = mid;
                    col_pos[col] = mid;
                    result[mid/m][mid%m] = val;
                    row_used[mid_row] = true;
                    col_used[col] = true;
                    assigned[val-1] = 1;
                    break;
                }
                if(mid_row < row_pos[col]){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
        }
    }
    if(assigned != vector<int>(n*m, 1)){
        cout << "-1";
        return 0;
    }
    vector<pair<int, int>> row_elements[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            row_elements[i].push_back({result[i][j], j});
        }
    }
    for(int i=0; i<n; i++){
        sort(row_elements[i].begin(), row_elements[i].end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        });
        int max_idx = 0;
        int max_val = row_elements[i][0].first;
        for(int j=1; j<m; j++){
            if(row_elements[i][j].first > max_val){
                max_idx = j;
                max_val = row_elements[i][j].first;
            }
        }
        vector<pair<int, int>> left;
        vector<pair<int, int>> right;
        for(int j=0; j<m; j++){
            if(j < max_idx){
                left.push_back(row_elements[i][j]);
            }
            else if(j > max_idx){
                right.push_back(row_elements[i][j]);
            }
        }
        sort(left.begin(), left.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        });
        sort(right.begin(), right.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });
        int curr = 0;
        for(auto p : left){
            result[i][p.second] = all[curr++];
        }
        result[i][row_elements[i][max_idx].second] = all[curr++];
        for(auto p : right){
            result[i][p.second] = all[curr++];
        }
    }
    vector<pair<int, int>> col_elements[m];
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            col_elements[j].push_back({result[i][j], i});
        }
    }
    for(int j=0; j<m; j++){
        sort(col_elements[j].begin(), col_elements[j].end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        });
        int max_idx = 0;
        int max_val = col_elements[j][0].first;
        for(int i=1; i<n; i++){
            if(col_elements[j][i].first > max_val){
                max_idx = i;
                max_val = col_elements[j][i].first;
            }
        }
        vector<pair<int, int>> left;
        vector<pair<int, int>> right;
        for(int i=0; i<n; i++){
            if(i < max_idx){
                left.push_back(col_elements[j][i]);
            }
            else if(i > max_idx){
                right.push_back(col_elements[j][i]);
            }
        }
        sort(left.begin(), left.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        });
        sort(right.begin(), right.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });
        int curr = 0;
        for(auto p : left){
            result[p.second][j] = all[curr++];
        }
        result[col_elements[j][max_idx].second][j] = all[curr++];
        for(auto p : right){
            result[p.second][j] = all[curr++];
        }
    }
    bool valid = true;
    for(int i=0; i<n; i++){
        int max_idx = max_element(result[i].begin(), result[i].end()) - result[i].begin();
        for(int j=1; j<max_idx; j++){
            if(result[i][j] <= result[i][j-1]){
                valid = false;
                break;
            }
        }
        for(int j=max_idx+1; j<m; j++){
            if(result[i][j] >= result[i][j-1]){
                valid = false;
                break;
            }
        }
    }
    for(int j=0; j<m; j++){
        vector<int> col(n);
        for(int i=0; i<n; i++){
            col[i] = result[i][j];
        }
        int max_idx = max_element(col.begin(), col.end()) - col.begin();
        for(int i=1; i<max_idx; i++){
            if(col[i] <= col[i-1]){
                valid = false;
                break;
            }
        }
        for(int i=max_idx+1; i<n; i++){
            if(col[i] >= col[i-1]){
                valid = false;
                break;
            }
        }
    }
    if(!valid){
        cout << "-1";
        return 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << result[i][j];
            if(j < m-1) cout << " ";
        }
        cout << "\n";
    }
}