//diff 5
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int sum = a + b + c + d;
    string ans;
    if (sum - a == a) ans = "Yes";
    else if (sum - b == b) ans = "Yes";
    else if (sum - c == c) ans = "Yes";
    else if (sum - d == d) ans = "Yes";
    else if (sum - a - b == a + b) ans = "Yes";
    else if (sum - a - c == a + c) ans = "Yes";
    else if (sum - a - d == a + d) ans = "Yes";
    else if (sum - b - c == b + c) ans = "Yes";
    else if (sum - b - d == b + d) ans = "Yes";
    else if (sum - c - d == c + d) ans = "Yes";


    else ans = "No";

    cout << ans << endl;

    return 0;
}