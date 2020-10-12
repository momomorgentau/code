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
//for•¶‚É‚Ä‘‚¢‚½ƒvƒƒOƒ‰ƒ€
/*
int main()
{
 vector<int> a(4);
 int sum=0;
 rep(i,4)
 {
   cin >> a[i];
   sum += a[i];
 }
 rep(i,4){
   if(sum-a[i] == a[i])
   {
     cout << "Yes" << endl;
     return 0;
   }
 }
 rep(i,4)rep(j,4)
 {
   if(i>=j) continue;
   int b = a[i]+a[j];
   if(sum-b == b)
   {
     cout << "Yes" << endl;
     return 0;
   }
 }
 cout << "No" << endl;
 return 0;
}
*/