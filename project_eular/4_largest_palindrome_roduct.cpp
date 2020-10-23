//5%
//project_eular 4 largest_palindrome_product
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

bool JudgePal(int a, int b)
{
    string s = to_string(a * b);
    string sr = s;
    reverse(sr.begin(), sr.end());
    return s == sr;
}
int main()
{
    int s = 100;
    int t = 999;
    int ans = 0;

    reps(i, s, t + 1) reps(j, s, t + 1)
    {
        if (i < j) continue;
        if (JudgePal(i, j)) ans = max(ans, i * j);
    }
    cout << ans << endl;
    return 0;
}
