//えびまのお誕生日コンテスト 2021 Day 1
//F
//
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    rep(i,n) --p[i];
    bool small = true;
    vector<P> ans;
    
    rep(i,n)
    {
        int m = i/2;
        if(!small) m = n-i/2-1;
        int idx = -1;
        rep(i,n)
        {
            if(p[i]==m) 
            {
                idx = i;
                break;
            }
        } 

        
        int bidx = idx;
        while(idx != m)
        {
            if(small)
            {
                --idx;
                if(p[idx]>=bidx)
                { 
                    swap(p[idx],p[bidx]);
                    ans.emplace_back(idx,bidx);
                    bidx = idx;
                }
            }
            else 
            {
                ++idx;
                if(p[idx]<=bidx) 
                {
                    swap(p[idx],p[bidx]);
                    ans.emplace_back(bidx,idx);
                    bidx = idx;
                }
            }
        }
        
        small = !small;
    }
    cout << ans.size() << endl;
    for(auto[a,b]:ans)cout << a+1 << " " << b+1<< endl;
    
    return 0;
}