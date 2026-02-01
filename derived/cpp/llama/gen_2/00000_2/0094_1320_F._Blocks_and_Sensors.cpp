#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const long long inf = 1e9;
const long long mod = 998244353;

long long n, m, k;

struct Sensor {
    vector<vector<int>> data;
    Sensor(int n, int m) {
        data.resize(n, vector<int>(m));
    }
};

Sensor inputSensor(int n, int m) {
    Sensor sensor(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> sensor.data[i][j];
        }
    }
    return sensor;
}

void printSensor(const Sensor& sensor) {
    int n = sensor.data.size();
    int m = sensor.data[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << sensor.data[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    vector<Sensor> sensors(6);
    cin.ignore();
    sensors[0] = inputSensor(m, k);
    cin.ignore();
    sensors[1] = inputSensor(m, k);
    cin.ignore();
    sensors[2] = inputSensor(n, k);
    cin.ignore();
    sensors[3] = inputSensor(n, k);
    cin.ignore();
    sensors[4] = inputSensor(n, m);
    cin.ignore();
    sensors[5] = inputSensor(n, m);

    vector<vector<vector<int>>> res(n, vector<vector<int>>(m, vector<int>(k, 0)));
    bool bad = false;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int z = 0; z < k; ++z) {
                if (sensors[4].data[x][y] != 0 && res[x][y][z] != 0 && res[x][y][z] != sensors[4].data[x][y]) {
                    bad = true;
                    break;
                }
                if (sensors[4].data[x][y] != 0) {
                    res[x")[y][z] = sensors[4].data[x][y];
                }
            }
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int z = 0; z < k; ++z) {
                if (sensors[5].data[x][y] != 0 && res[x][y][z] != 0 && res[x][y][z] != sensors[5].data[x][y]) {
                    bad = true;
                    break;
                }
                if (sensors[5].data[x][y] != 0) {
                    res[x][y][z] = sensors[5].data[x][y];
                }
            }
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int z = 0; z < k; ++z) {
                if (sensors[0].data[y][z] != 0 && res[x][y][z] != 0 && res[x][y][z] != sensors[0].data[y][z]) {
                    bad = true;
                    break;
                }
                if (sensors[0].data[y][z] != 0) {
                    res[x][y][z] = sensors[0].data[y][z];
                }
            }
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int z = 0; z < k; ++z) {
                if (sensors[1].data[y][z] != 0 && res[x][y][z] != 0 && res[x][y][z] != sensors[1].data[y][z]) {
                    bad = true;
                    break;
                }
                if (sensors[1].data[y][z] != 0) {
                    res[x][y][z] = sensors[1].data[y][z];
                }
            }
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int z = 0; z < k; ++z) {
                if (sensors[2].data[x][z] != 0 && res[x][y][z] != 0 && res[x][y][z] != sensors[2].data[x][z]) {
                    bad = true;
                    break;
                }
                if (sensors[2].data[x][z] != 0) {
                    res[x][y][z] = sensors[2].data[x][z];
                }
            }
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int z = 0; z < k; ++z) {
                if (sensors[3].data[x][z] != 0 && res[x][y][z] != 0 && res[x][y][z] != sensors[3].data[x][z]) {
                    bad = true;
                    break;
                }
                if (sensors[3].data[x][z] != 0) {
                    res[x][y][z] = sensors[3].data[x][z];
                }
            }
        }
    }
    if (bad) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < res[i][j].size(); ++k) {
                cout << res[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}