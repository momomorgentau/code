//20
//abc146_a_cant_wait_for_holiday
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    vector<string> a1{"SUN","MON","TUE","WED","THU","FRI","SAT"};
    vector<int> ans{7,6,5,4,3,2,1};
    int d = distance(a1.begin(),find(a1.begin(),a1.end(),s));
    cout << ans[d] << endl;
}