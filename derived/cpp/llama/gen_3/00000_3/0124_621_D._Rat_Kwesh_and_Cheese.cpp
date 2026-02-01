#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    double x, y, z;
    cin >> x >> y >> z;

    vector<double> values;
    vector<string> expressions;

    values.push_back(x * y * z);
    expressions.push_back(to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)) + "^" + to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)) + "^" + to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)));

    values.push_back(x * z * y);
    expressions.push_back(to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)) + "^" + to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)) + "^" + to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)));

    values.push_back(pow(x * y, z));
    expressions.push_back("(" + to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)) + "^" + to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)) + ")^" + to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)));

    values.push_back(pow(x * z, y));
    expressions.push_back("(" + to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)) + "^" + to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)) + ")^" + to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)));

    values.push_back(y * x * z);
    expressions.push_back(to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)) + "^" + to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)) + "^" + to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)));

    values.push_back(y * z * x);
    expressions.push_back(to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)) + "^" + to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)) + "^" + to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)));

    values.push_back(pow(y * x, z));
    expressions.push_back("(" + to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)) + "^" + to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)) + ")^" + to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)));

    values.push_back(pow(y * z, x));
    expressions.push_back("(" + to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)) + "^" + to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)) + ")^" + to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)));

    values.push_back(z * x * y);
    expressions.push_back(to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)) + "^" + to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)) + "^" + to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)));

    values.push_back(z * y * x);
    expressions.push_back(to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)) + "^" + to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)) + "^" + to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)));

    values.push_back(pow(z * x, y));
    expressions.push_back("(" + to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)) + "^" + to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)) + ")^" + to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)));

    values.push_back(pow(z * y, x));
    expressions.push_back("(" + to_string((int)z) + "." + to_string((int)((z - (int)z) * 10)) + "^" + to_string((int)y) + "." + to_string((int)((y - (int)y) * 10)) + ")^" + to_string((int)x) + "." + to_string((int)((x - (int)x) * 10)));

    double max = -1;
    int index = -1;
    for(int i = 0; i < values.size(); i++) {
        if(values[i] > max) {
            max = values[i];
            index = i;
        }
    }

    cout << expressions[index] << endl;

    return 0;
}