#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	string str;
	cin >> str;

	int sum = 0;
	while (1) {
		if (str.empty()) break;

		char c = str[0];
		int n = c - '0';
		sum += n;
		str.erase(0, 1);
	}

	string ans;
	if (sum % 9 == 0) ans = "Yes";
	else ans = "No";

	cout << ans << endl;

	return 0;
}