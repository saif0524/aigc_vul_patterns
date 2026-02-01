#include <iostream>
#include <vector>

const int MAX_N = 200005;

int n, m, k;
int sensor_data[6][MAX_N][MAX_N];
int block_types[MAX_N][MAX_N][MAX_N];

int main() {
    std::cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cin >> sensor_data[0][i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cin >> sensor_data[1][i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cin >> sensor_data[2][i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cin >> sensor_data[3][i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> sensor_data[4][i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> sensor_data[5][i][j];
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int z = 0; z < k; ++z) {
                block_types[x][y][z] = 0;
            }
        }
    }

    for (int y = 0; y < m; ++y) {
        for (int z = 0; z < k; ++z) {
            if (sensor_data[0][y][z] != 0) {
                block_types[0][y][z] = sensor_data[0][y][z];
            }
        }
    }

    for (int y = 0; y < m; ++y) {
        for (int z = 0; z < k; ++z) {
            if (sensor_data[1][y][z] != 0) {
                block_types[n - 1][y][z] = sensor_data[1][y][z];
            }
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int z = 0; z < k; ++z) {
            if (sensor_data[2][x][z] != 0) {
                block_types[x][0][z] = sensor_data[2][x][z];
            }
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int z = 0; z < k; ++z) {
            if (sensor_data[3][x][z] != 0) {
                block_types[x][m - 1][z] = sensor_data[3][x][z];
            }
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (sensor_data[4][x][y] != 0) {
                block_types[x][y][0] = sensor_data[4][x][y];
            }
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (sensor_data[5][x][y] != 0) {
                block_types[x][y][k - 1] = sensor_data[5][x][y];
            }
        }
    }

    bool consistent = true;

    for (int y = 0; y < m; ++y) {
        for (int z = 0; z < k; ++z) {
            if (sensor_data[0][y][z] == 0 && sensor_data[1][y][z] == 0) {
                continue;
            }

            int x = 0;
            while (x < n && block_types[x][y][z] == 0) {
                ++x;
            }

            if (x == n) {
                consistent = false;
                break;
            }

            while (x < n && block_types[x][y][z] != 0) {
                ++x;
            }

            if (x == n) {
                if (sensor_data[0][y][z] != sensor_data[1][y][z]) {
                    consistent = false;
                    break;
                }
            } else {
                if (block_types[x][y][z] != sensor_data[1][y][z]) {
                    consistent = false;
                    break;
                }
            }
        }

        if (!consistent) {
            break;
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int z = 0; z < k; ++z) {
            if (sensor_data[2][x][z] == 0 && sensor_data[3][x][z] == 0) {
                continue;
            }

            int y = 0;
            while (y < m && block_types[x][y][z] == 0) {
                ++y;
            }

            if (y == m) {
                consistent = false;
                break;
            }

            while (y < m && block_types[x][y][z] != 0) {
                ++y;
            }

            if (y == m) {
                if (sensor_data[2][x][z] != sensor_data[3][x][z]) {
                    consistent = false;
                    break;
                }
            } else {
                if (block_types[x][y][z] != sensor_data[3][x][z]) {
                    consistent = false;
                    break;
                }
            }
        }

        if (!consistent) {
            break;
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (sensor_data[4][x][y] == 0 && sensor_data[5][x][y] == 0) {
                continue;
            }

            int z = 0;
            while (z < k && block_types[x][y][z] == 0) {
                ++z;
            }

            if (z == k) {
                consistent = false;
                break;
            }

            while (z < k && block_types[x][y][z] != 0) {
                ++z;
            }

            if (z == k) {
                if (sensor_data[4][x][y] != sensor_data[5][x][y]) {
                    consistent = false;
                    break;
                }
            } else {
                if (block_types[x][y][z] != sensor_data[5][x][y]) {
                    consistent = false;
                    break;
                }
            }
        }

        if (!consistent) {
            break;
        }
    }

    if (!consistent) {
        std::cout << -1 << std::endl;
        return 0;
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int z = 0; z < k; ++z) {
                std::cout << block_types[x][y][z] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}