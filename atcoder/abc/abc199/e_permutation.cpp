//ABC_199_E
//Permutation
//1814
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> X(m),Y(m),Z(m);
    rep(i,m) cin >> X[i] >> Y[i] >> Z[i];
    vector<ll> dp((1<<n)+5);
    dp[0] = 1;
    //n 個の数字を入れる
    rep(i,n)    
    {
        //...00000~...11111まで試す。
        rep(bit,1<<n)
        {
            //経っているbit数が桁と一致しなければ飛ばす
            int bit_num = 0;
            rep(k,n) if((bit>>k)&1)++bit_num;
            if(bit_num != i) continue;

            //追加する数
            rep(add,n)
            {
                //数を追加してもよいかの判定
                bool ok=true;
                if((bit>>add)&1) continue;
                //遷移先のbit（ | or演算子を用いる）
                int next_bit = bit | (1<<add);
                //next_bitへの遷移が可能かどうかMの条件を見ていく
                rep(mi,m)
                {
                    //追加したあとの数字の個数がXiじゃなければ判定しない
                    if(i+1 != X[mi]) continue;
                    //Yi以下でたってるビット数
                    int bit_num_y = 0;
                    rep(k,Y[mi]) if((next_bit>>k)&1)++bit_num_y;
                    //もしZi以上のbitがたっていたら遷移できない
                    if(bit_num_y>Z[mi]) ok = false;
                }
                //遷移可能だったら遷移する。
                if(ok) dp[next_bit] += dp[bit];
            }
        }
    }
    //dp[...111111]に答えが入ってる
    cout << dp[(1<<n)-1] << endl;



    return 0;
}