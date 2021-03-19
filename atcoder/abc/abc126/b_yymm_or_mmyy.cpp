//ABC_126_B_YYMM_or_MMYY
//??
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    bool ok1 = false;
    bool ok2 = false;
    int a = (s[0] - '0') * 10 + (s[1] - '0');
    int b = (s[2] - '0') * 10 + (s[3] - '0');

    if (0 < a && a <= 12) ok1 = true;
    if (0 < b && b <= 12) ok2 = true;

    string ans;
    if (ok1 && ok2) ans = "AMBIGUOUS";
    else if (ok1) ans = "MMYY";
    else if (ok2) ans = "YYMM";
    else ans = "NA";
    cout << ans << endl;
    return 0;
}

