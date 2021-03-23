//ABC_119_D_Lazy_Faith
//1346
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int  a,b,q;
    cin >> a >> b >> q;

    vector<ll> s(a+4),t(b+4);
    const ll INF = 1e18;
    rep(i,a) cin >> s[i+2];
    rep(i,b) cin >> t[i+2];
    s[0] = t[0] = -INF;
    s[1] = t[1] = -INF+1;
    s[a+2] = t[b+2] = INF-1;
    s[a+3] = t[b+3] = INF;


    rep(i,q)
    {
      ll ans = INF;
      ll xi; cin >> xi;
      //ts<-
      ll sl = *(--lower_bound(s.begin(),s.end(),xi));
      ll tll = *(--lower_bound(t.begin(),t.end(),sl));
      ans = min(ans,xi - tll);
      //st<-
      ll tl = *(--lower_bound(t.begin(),t.end(),xi));
      ll sll = *(--lower_bound(s.begin(),s.end(),tl));
      ans = min(ans,xi - sll);

      //->st
      ll sr = *lower_bound(s.begin(),s.end(),xi);
      ll trr = *lower_bound(t.begin(),t.end(),sr);
      ans = min(ans,trr - xi);

      //->ts
      ll tr = *lower_bound(t.begin(),t.end(),xi);
      ll srr = *lower_bound(s.begin(),s.end(),tr);
      ans = min(ans,srr - xi);   

      //s<- ->t
      ans = min(ans,(xi-sl)+(tr-sl));
      //t<- ->s
      ans = min(ans,(xi-tl)+(sr-tl));      
      //->t  s<-
      ans = min(ans,(tr-xi)+(tr-sl));      
      //->s  t<-
      ans = min(ans,(sr-xi)+(sr-tl));
      printf("%ld\n",ans);      
    }
    
   return 0;
    

}