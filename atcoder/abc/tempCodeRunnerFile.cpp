#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    vector<int> v = {3,6,8};
    rep(i,10){
    int idx = lower_bound(v.begin(),v.end(),i) - v.begin();
    cout << i << "  "<< idx << endl;
    }


    return 0;
}
