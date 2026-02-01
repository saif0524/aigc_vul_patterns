#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> sensor_x0(m, vector<int>(k)), sensor_xn(m, vector<int>(k));
    vector<vector<int>> sensor_y0(n, vector<int>(k)), sensor_yn(n, vector<int>(k));
    vector<vector<int>> sensor_z0(n, vector<int>(m)), sensor_zk(n, vector<int>(m));
    for(int i=0; i<m; ++i){
        for(int j=0; j<k; ++j){
            cin >> sensor_x0[i][j];
        }
    }
    cin.ignore();
    for(int i=0; i<m; ++i){
        for(int j=0; j<k; ++j){
            cin >> sensor_xn[i][j];
        }
    }
    cin.ignore();
    for(int i=0; i<n; ++i){
        for(int j=0; j<k; ++j){
            cin >> sensor_y0[i][j];
        }
    }
    cin.ignore();
    for(int i=0; i<n; ++i){
        for(int j=0; j<k; ++j){
            cin >> sensor_yn[i][j];
        }
    }
    cin.ignore();
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> sensor_z0[i][j];
        }
    }
    cin.ignore();
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> sensor_zk[i][j];
        }
    }
    vector<vector<vector<int>>> a(n, vector<vector<int>>(m, vector<int>(k, 0)));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            for(int k1=0; k1<k; ++k1){
                int x0 = sensor_x0[j][k1];
                int xn = sensor_xn[j][k1];
                int y0 = sensor_y0[i][k1];
                int yn = sensor_yn[i][k1];
                int z0 = sensor_z0[i][j];
                int zk = sensor_zk[i][j];
                if(x0 == 0 && xn == 0 && y0 == 0 && yn == 0 && z0 == 0 && zk == 0){
                    a[i][j][k1] = 0;
                }
                else if(x0 > 0 && xn > 0 && x0 == xn){
                    if(k1 != 0){
                        if(a[i][j][k1-1] != 0 && a[i][j][k1-1] != x0){
                            cout << -1;
                            return 0;
                        }
                    }
                    a[i][j][k1] = x0;
                }
                else if(y0 > 0 && yn > 0 && y0 == yn){
                    if(k1 != 0){
                        if(a[i][j][k1-1] != 0 && a[i][j][k1-1] != y0){
                            cout << -1;
                            return 0;
                        }
                    }
                    a[i][j][k1] = y0;
                }
                else if(z0 > 0 && zk > 0 && z0 == zk){
                    if(k1 != 0){
                        if(a[i][j][k1-1] != 0 && a[i][j][k1-1] != z0){
                            cout << -1;
                            return 0;
                        }
                    }
                    a[i][j][k1] = z0;
                }
                else if(x0 > 0){
                    if(k1 != 0){
                        if(a[i][j][k1-1] != 0 && a[i][j][k1-1] != x0){
                            cout << -1;
                            return 0;
                        }
                    }
                    a[i][j][k1] = x0;
                }
                else if(y0 > 0){
                    if(k1 != 0){
                        if(a[i][j][k1-1] != 0 && a[i][j][k1-1] != y0){
                            cout << -1;
                            return 0;
                        }
                    }
                    a[i][j][k1] = y0;
                }
                else if(z0 > 0){
                    if(k1 != 0){
                        if(a[i][j][k1-1] != 0 && a[i][j][k1-1] != z0){
                            cout << -1;
                            return 0;
                        }
                    }
                    a[i][j][k1] = z0;
                }
                else if(xn > 0){
                    if(k1 != k-1){
                        if(a[i][j][k1+1] != 0 && a[i][j][k1+1] != xn){
                            cout << -1;
                            return 0;
                        }
                    }
                    a[i][j][k1] = xn;
                }
                else if(yn > 0){
                    if(k1 != k-1){
                        if(a[i][j][k1+1] != 0 && a[i][j][k1+1] != yn){
                            cout << -1;
                            return 0;
                        }
                    }
                    a[i][j][k1] = yn;
                }
                else if(zk > 0){
                    if(k1 != k-1){
                        if(a[i][j][k1+1] != 0 && a[i][j][k1+1] != zk){
                            cout << -1;
                            return 0;
                        }
                    }
                    a[i][j][k1] = zk;
                }
                else{
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            for(int k1=0; k1<k; ++k1){
                cout << a[i][j][k1] << " ";
            }
        }
    }
}