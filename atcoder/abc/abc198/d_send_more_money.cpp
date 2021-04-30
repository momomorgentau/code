//ABC_198_E
//Send_More_Money
//1224
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    vector<char> C;
    vector<char> C_top;

    //使われている文字と
    //先頭に使われている文字を取得。
    //findで見つからなかったら追加。
    auto get_char =[&](string s)
    {
        if(find(C_top.begin(),C_top.end(),s[0]) == C_top.end())
        {
            C_top.emplace_back(s[0]);
        }
        for(auto c : s)
        {
            if(find(C.begin(),C.end(),c) == C.end())
            { 
                C.emplace_back(c);
            }
        }
    };
    get_char(s1);
    get_char(s2);
    get_char(s3);
    //１１個以上の文字があったら絶対に満たせない。
    //同じ文字は同じ数字　かつ　同じ数字は同じ文字
    if(C.size() > 10)
    {
         cout << "UNSOLVABLE" << endl;
         return 0;
    }
    //文字列を数字列に変換（mapの変換テーブルを用いる）
    auto convert = [](string s,map<char,int> mp)
    {
        ll now = 0;
        for(auto c:s)
        {
            now *= 10;
            now += mp[c];
        }
        return now;
    };

    vector<int> num = {0,1,2,3,4,5,6,7,8,9};
    do
    {
        //変換テーブルを作成
        map<char,int> mp;
        rep(i,C.size()) mp[C[i]]=num[i];
        //先頭に0がきたらダメ！
        bool ng = false;
        for(auto t:C_top) if(mp[t] == 0) ng = true;
        if(ng) continue;
        //条件を満たすか確かめる
        ll ans1,ans2,ans3;
        ans1 = convert(s1,mp);
        ans2 = convert(s2,mp);
        ans3 = convert(s3,mp);
        if(ans1+ans2==ans3) 
        {
            cout << ans1 << endl;
            cout << ans2 << endl;
            cout << ans3 << endl;
            return 0;
        }
    } while (next_permutation(num.begin(),num.end()));
    cout << "UNSOLVABLE" << endl;
    return 0;
}