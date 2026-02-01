#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix(int n) : n(n), data(n, vector<int>(n, 0)) {}

    void update(int x0, int y0, int x1, int y1, int v) {
        for (int i = x0 - 1; i < x1; i++) {
            for (int j = y0 - 1; j < y1; j++) {
                data[i][j] ^= v;
            }
        }
    }

    int query(int x0, int y0, int x1, int y1) {
        int result = 0;
        for (int i = x0 - 1; i < x1; i++) {
            for (int j = y0 - 1; j < y1; j++) {
                result ^= data[i][j];
            }
        }
        return result;
    }

private:
    int n;
    vector<vector<int>> data;
};

int main() {
    int n, m;
    cin >> n >> m;

    Matrix matrix(n);

    while (m--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            cout << matrix.query(x0, y0, x1, y1) << endl;
        } else if (op == 2) {
            int x0, y0, x1, y1, v;
            cin >> x0 >> y0 >> x1 >> y1 >> v;
            matrix.update(x0, y0, x1, y1, v);
        }
    }

    return 0;
}