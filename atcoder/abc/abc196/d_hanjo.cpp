//ABC_196_D_Hanjo
//1277
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


void solve2()
{
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    queue<tuple<int,int,int,int,int>> q;
    q.emplace(0,0,0,0,0);
    int ans = 0;
    while(!q.empty())
    {
        int hi,wi,ai,bi,used;
        tie(hi,wi,ai,bi,used) = q.front();
        q.pop();
        if(used == (1<<w*h)-1)
        {
            ++ans;
            continue;
        }
        //現在のbit
        int bit = 1<<((w*hi)+wi);
        //その場にすでに置いてある場合。
        if(used & 1<<bit)
        {
            if(wi+1 < w) q.emplace(hi,wi+1,ai,bi,used);
            else q.emplace(hi+1,0,ai,bi,used);
        }
        else
        {
            //bを置く場合
            if(bi+1<=b)
            {
                if(wi+1 < w)
                {
                    q.emplace(hi,wi+1,ai,bi+1,used|(1<<bit));
                }
                else
                {
                    if(hi+1 < h) q.emplace(hi+1,0,ai,bi+1,used|(1<<bit);
                    else q.emplace(hi,wi,ai,bi+1,used|(1<<bit));
                }
            }
            //aを置く場合
            if(ai+1<=a)
            {   //横置き
                int rbit = 1<<((w*hi)+wi+1);
                if(wi+1<w && !(used&rbit))
                {
                    q.emplace(hi,wi+1,ai+1,bi,used|rbit|bit);
                }
                //縦置き
                int cbit = 1<<((w*(hi+1))+wi);
                if(hi+1<h && !(used&cbit))
                {
                    if(wi+1<w) q.emplace(hi,wi+1,ai+1,bi,used|bit|cbit);
                    else q.emplace(hi+1,0,ai+1,bi,used|bit|cbit);
                }
            }
        }
    } 
    cout << ans << endl;
}
int main()
{
    solve2();
    return 0;
}
