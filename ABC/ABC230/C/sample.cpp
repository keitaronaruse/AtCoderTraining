#include <bits/stdc++.h>

using namespace std;

int main(void) {
	long long n, a, b;
	long long p, q, r, s;
	long long x, y;
	string str = "";
	vector<string>ans;

	cin >> n >> a >> b;
	cin >> p >> q >> r >> s;

	for (long long i = 0; i < (s - r + 1); i++)str += '.';
	for (long long i = 0; i < (q - p + 1); i++)ans.push_back(str);


	x = max(p - a, r - b);
	y = min(q - a, s - b);
	for (long long i = x; i <= y; i++)ans[a + i - p][b + i - r] = '#';

	x = max(p - a, b - s);
	y = min(q - a, b - r);
	for (long long i = x; i <= y; i++)ans[a + i - p][b - i - r] = '#';


	for (long long i = 0; i < (q - p + 1); i++)cout << ans[i] << endl;

	return 0;
}
