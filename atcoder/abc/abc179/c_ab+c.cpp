#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {

	int n;
	cin >> n;
	int n1 = n - 1;
	int ans = 0;

	for (int i = 1; i < n + 1; i++) {
		ans += n1 / i;
	}

	cout << ans << endl;
	return 0;
}