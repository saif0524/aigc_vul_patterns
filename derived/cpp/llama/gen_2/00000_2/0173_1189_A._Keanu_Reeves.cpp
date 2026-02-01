#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<string> ans;
	int l = 0;
	for (int i = 1; i < n; ++i) {
		int cntr = 0, cntzero = 0;
		string str = s.substr(l, i - l + 1);
		for (char c : str) {
			if (c == '1') {
				cntr++;
			}
			else {
				cntzero++;
			}
		}
		if (cntr != cntzero) {
			ans.push_back(str);
			l = i + 1;
			i = l;
		}
	}
	if (l < n) {
		ans.push_back(s.substr(l));
	}
	cout << ans.size() << endl;
	for (string a : ans) {
		cout << a << " ";
	}
	return 0;
}