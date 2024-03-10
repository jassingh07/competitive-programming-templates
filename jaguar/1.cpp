#include <bits/stdc++.h>
using namespace std;

int getsum(int a)
{
	int r = 0, sum = 0;
	while (a > 0) {
		r = a % 10;
		sum = sum + r;
		a = a / 10;
	}
	return sum;
}

void value(int a, int b, int c)
{
	int co = 0, p = 0;
	int no, r = 0, x = 0, q = 0, w = 0;
	vector<int> v;

	for (int i = 1; i < 82; i++) {
		no = pow((double)i, double(a));
		no = b * no + c;

		if (no > 0 && no < 1000000000) {
			x = getsum(no);
			if (x == i) {
				q++;
				v.push_back(no);
				w++;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

// Driver Code
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
	value(a, b, c);
	return 0;
}
