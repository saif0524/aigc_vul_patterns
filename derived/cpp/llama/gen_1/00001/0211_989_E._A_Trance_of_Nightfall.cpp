#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 200;
const int M = 10000;
const int K = 200;
const double eps = 1e-12;
const double eps2 = 1e-10;

struct Point {
	int x, y;
};

void swap(Point& a, Point& b) {
	Point t = a; a = b; b = t;
}

bool colinear(const Point& a, const Point& b, const Point& c) {
	return (b.x - a.x) * (c.y - a.y) == (c.x - a.x) * (b.y - a.y);
}

int same_line(const Point& a, const Point& b, const Point& c) {
	if (colinear(a, b, c)) {
		if (a.x != b.x || a.y != b.y || b.x != c.x || b.y != c.y) {
			if (a.x == c.x && a.y == c.y) return 2;
			if (a.x == b.x && a.y == b.y) return 1;
			return 0;
		}
		return -1;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<Point> points(n);
	for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;
	int q;
	cin >> q;
	while (q--) {
		int target, moves;
		cin >> target >> moves;
		target--;
		Point P;
		P.x = points[target].x;
		P.y = points[target].y;
		double first_prob = 0.0;
		int num_lines_with_point = 0;
		int num_colinear_points = 0;
		vector<int> num_points_on_line(n);
		vector<double> prob_line(n);
		for (int i = 0; i < n; i++) {
			if (i == target) continue;
			for (int j = i + 1; j < n; j++) {
				if (j == target) continue;
				if (same_line(points[i], points[target], points[j]) != -1) {
					num_colinear_points++;
					if (num_points_on_line[i] == 0) num_points_on_line[i] = 2;
					if (i != j && (same_line(points[target], points[i], points[j]) != -1)) num_points_on_line[j]++;
					if (i != j) prob_line[i] = (same_line(points[target], points[i], points[j]) != -1) ? prob_line[i] + 1.0 : 1.0;
					if (j != i) prob_line[j] = (same_line(points[target], points[j], points[i]) != -1) ? prob_line[j] + 1.0 : 1.0;
				}
			}
		}
		if (num_colinear_points == 0) {
			cout << "0.00000000000000000000\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (num_points_on_line[i] > 1) {
				first_prob += 1.0 / num_points_on_line[i];
				num_lines_with_point++;
			}
		}
		first_prob /= num_lines_with_point;
		if (moves == 1) {
			cout << fixed;
			cout.precision(20);
			cout << first_prob << endl;
		}
		else {
			double all_prob = first_prob;
			all_prob = pow((double)num_lines_with_point, moves - 1);
			all_prob *= first_prob;
			cout << fixed;
			cout.precision(20);
			cout << all_prob << endl;
		}
	}
	return 0;
}