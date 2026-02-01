#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<int>>> a(n+2,vector<vector<int>>(m+2,vector<int>(k+2,0)));
    vector<vector<int>> sensor1(m,vector<int>(k)), sensor2(m,vector<int>(k)), sensor3(n,vector<int>(k)), sensor4(n,vector<int>(k)), sensor5(n,vector<int>(m)), sensor6(n,vector<int>(m));
    for(int i=0; i<m; ++i) for(int j=0; j<k; ++j) cin >> sensor1[i][j];
    cin.ignore();
    for(int i=0; i<m; ++i) for(int j=0; j<k; ++j) cin >> sensor2[i][j];
    cin.ignore();
    for(int i=0; i<n; ++i) for(int j=0; j<k; ++j) cin >> sensor3[i][j];
    cin.ignore();
    for(int i=0; i<n; ++i) for(int j=0; j<k; ++j) cin >> sensor4[i][j];
    cin.ignore();
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> sensor5[i][j];
    cin.ignore();
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> sensor6[i][j];
    for(int j=0; j<k; ++j){
        bool consistent = true;
        int last = 0;
        for(int i=0; i<m; ++i){
            if(sensor1[i][j]){
                if(sensor2[i][j] != sensor1[i][j]){
                    consistent = false;
                    break;
                }
                if(last && sensor1[i][j] != last){
                    consistent = false;
                    break;
                }
                last = sensor1[i][j];
                a[1][i+1][j+1] = sensor1[i][j];
            }
        }
        if(!consistent){
            cout << -1;
            return 0;
        }
    }
    for(int i=0; i<n; ++i){
        bool consistent = true;
        int last = 0;
        for(int j=0; j<k; ++j){
            if(sensor3[i][j]){
                if(sensor4[i][j] != sensor3[i][j]){
                    consistent = false;
                    break;
                }
                if(last && sensor3[i][j] != last){
                    consistent = false;
                    break;
                }
                last = sensor3[i][j];
                a[i+1][1][j+1] = sensor3[i][j];
            }
        }
        if(!consistent){
            cout << -1;
            return 0;
        }
    }
    for(int i=0; i<n; ++i){
        bool consistent = true;
        int last = 0;
        for(int j=0; j<m; ++j){
            if(sensor5[i][j]){
                if(sensor6[i][j] != sensor5[i][j]){
                    consistent = false;
                    break;
                }
                if(last && sensor5[i][j] != last){
                    consistent = false;
                    break;
                }
                last = sensor5[i][j];
                a[i+1][j+1][1] = sensor5[i][j];
            }
        }
        if(!consistent){
            cout << -1;
            return 0;
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            int last = 0;
            for(int z=1; z<=k; ++z){
                if(a[i][j][z]){
                    if(last && last != a[i][j][z]){
                        cout << -1;
                        return 0;
                    }
                    last = a[i][j][z];
                }
                if(sensor1[j-1][z-1] && a[i][j][z] && sensor1[j-1][z-1] != a[i][j][z]){
                    cout << -1;
                    return 0;
                }
                if(sensor2[j-1][z-1] && a[i][j][z] && sensor2[j-1][z-1] != a[i][j][z]){
                    cout << -1;
                    return 0;
                }
                if(sensor3[i-1][z-1] && a[i][j][z] && sensor3[i-1][z-1] != a[i][j][z]){
                    cout << -1;
                    return 0;
                }
                if(sensor4[i-1][z-1] && a[i][j][z] && sensor4[i-1][z-1] != a[i][j][z]){
                    cout << -1;
                    return 0;
                }
                if(sensor5[i-1][j-1] && a[i][j][z] && sensor5[i-1][j-1] != a[i][j][z]){
                    cout << -1;
                    return 0;
                }
                if(sensor6[i-1][j-1] && a[i][j][z] && sensor6[i-1][j-1] != a[i][j][z]){
                    cout << -1;
                    return 0;
                }
                if(!a[i][j][z]){
                    if(sensor1[j-1][z-1] == 0){
                        a[i][j][z] = 1337;
                    }else if(sensor1[j-1][z-1]){
                        a[i][j][z] = sensor1[j-1][z-1];
                    }
                }
                last = a[i][j][z];
            }
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            for(int z=1; z<=k; ++z){
                cout << a[i][j][z] << ' ';
            }
        }
    }
    cout << '\n';
}