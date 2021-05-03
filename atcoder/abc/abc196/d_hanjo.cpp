//ABC_196_D_Hanjo
//1277
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
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
        //全てのbitが1（全てのマスが畳で埋まった）
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
            //端じゃなければ、右のマス
            if(wi+1 < w) q.emplace(hi,wi+1,ai,bi,used);
            //端だったら、次の行の一番左
            else q.emplace(hi+1,0,ai,bi,used);
            //一番右下のマスだったら、上記のansの方に引っかかるため考慮しない。
        }
        //そのマスに畳がない場合
        else
        {
            //bを置く場合(b個以上は置けない)
            if(bi+1<=b)
            {
                //端でない
                if(wi+1 < w)
                {
                    q.emplace(hi,wi+1,ai,bi+1,used|(1<<bit));
                }
                //端
                else
                {
                    //一番下の行じゃなければ次の行
                    if(hi+1 < h) q.emplace(hi+1,0,ai,bi+1,used|(1<<bit);
                    //一番下の行だったら同じマスを返す。次の遷移でansに引っかかる。
                    else q.emplace(hi,wi,ai,bi+1,used|(1<<bit));
                }
            }
            //aを置く場合(a個以上は置けない)
            if(ai+1<=a)
            {   //横置き
                //隣のマスのbit
                int rbit = 1<<((w*hi)+wi+1);
                //端ではない、かつ、隣のマスに置かれていない
                if(wi+1<w && !(used&rbit))
                {
                    //そのマスと隣のマスのbitを1にする。
                    q.emplace(hi,wi+1,ai+1,bi,used|rbit|bit);
                }

                //縦置き
                //下のマスのbit
                int cbit = 1<<((w*(hi+1))+wi);
                //一番下でない、かつ、下に畳が置かれていない
                //（下に置かれることはないが説明上書いておく）
                if(hi+1<h && !(used&cbit))
                {
                    //そのマスと下のマスのbitを1にする。
                    if(wi+1<w) q.emplace(hi,wi+1,ai+1,bi,used|bit|cbit);
                    else q.emplace(hi+1,0,ai+1,bi,used|bit|cbit);
                }
            }
        }
    } 
    cout << ans << endl;
    return 0;
}
