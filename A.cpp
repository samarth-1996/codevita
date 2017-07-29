#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vii;

#define rep(i,a) for(int i=0;i<(a);++i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define fill(a,b) memset((a),(b),sizeof((a)))
#define clr(a) memset((a),0,sizeof((a)))
#define foreach(a,it)  for( typeof((a).begin()) it=(a).begin();it!=(a).end();it++ )
#define mp make_pair
#define pb push_back
#define all(s) s.begin(),s.end()
#define sz(a) int(a.size())
#define ft first
#define sd second

#define sf(n) scanf("%d",&n)
#define pf(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define pll(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const double eps = 1e-8;
const ll inf = 2e9+1;
const ll mod = 1e9+7;
const int N = int(2e5)+10;

ll power(ll x, ll y)
{
    ll t=1;
    while(y>0)
    {
        if (y%2) y-=1, t=t*x%mod;
        else y/=2, x=x*x%mod;
    }
    return t;
}

int k;
pii a,b;
int s[100][100];
int ans1=100000;
int ans2=100000;

inline void solve(pii p, int d, int step, int bar)
{
    if (p.ft<0 || p.ft>=k || p.sd<0 || p.sd>=k)
        return;
    if (p.ft==a.ft && p.sd==a.sd)
    {
        if (step<ans1)
        {
            ans1=step;
            ans2=bar;
        }
        else if (step==ans1)
        {
            if (bar<ans2)
                ans2=bar;
        }
        return;
    }
    step++;
    if (d==0)
    {
        if (s[p.ft][p.sd]==0)
            p.ft--;
        else if (s[p.ft][p.sd]==1)
        {
            bar++;
            d=1;
            p.sd++;
        }
        else if (s[p.ft][p.sd]==2)
        {
            bar++;
            d=3;
            p.sd--;
        }
    }
    else if (d==1)
    {
        if (s[p.ft][p.sd]==0)
            p.sd++;
        else if (s[p.ft][p.sd]==1)
        {
            bar++;
            d=0;
            p.ft--;
        }
        else if (s[p.ft][p.sd]==2)
        {
            bar++;
            d=2;
            p.ft++;
        }
    }
    else if (d==2)
    {
        if (s[p.ft][p.sd]==0)
            p.ft++;
        else if (s[p.ft][p.sd]==1)
        {
            bar++;
            d=3;
            p.sd--;
        }
        else if (s[p.ft][p.sd]==2)
        {
            bar++;
            d=1;
            p.sd++;
        }
    }
    else
    {
        if (s[p.ft][p.sd]==0)
            p.sd--;
        else if (s[p.ft][p.sd]==1)
        {
            bar++;
            d=2;
            p.ft++;
        }
        else if (s[p.ft][p.sd]==2)
        {
            bar++;
            d=0;
            p.ft--;
        }
    }
    solve(p,d,step,bar);
}

int main()
{
    sf(k);
    sf(a.ft); sf(a.sd); sf(b.ft); sf(b.sd);
    rep(i,k)
        rep(j,k)
            sf(s[i][j]);
    rep(i,4)
        solve(b, i, 0, 0);
    if (ans1==100000)
        printf("-1\n");
    else
        printf("%d %d\n",ans1,ans2);
}
