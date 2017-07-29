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

pii p;
char a[100][100];
int sum[100][100];
int m,n;
bool b[100][100];
int y[8]={1,1,1,0,0,-1,-1,-1};
int x[8]={1,0,-1,1,-1,1,0,-1};

void bfs()
{
    clr(b);
    queue<pii> q;
    q.push(p);
    b[p.ft][p.sd]=true;
    sum[p.ft][p.sd]=1;
    while(!q.empty())
    {
        pii s=q.front();
        q.pop();
        rep(i,8)
        {
            if (s.ft+x[i]>=0 && s.ft+x[i]<m && s.sd+y[i]>=0 && s.sd+y[i]<n &&
                b[s.ft+x[i]][s.sd+y[i]]==false && a[s.ft+x[i]][s.sd+y[i]]=='T')
            {
                q.push(mp(s.ft+x[i],s.sd+y[i]));
                b[s.ft+x[i]][s.sd+y[i]]=true;
                sum[s.ft+x[i]][s.sd+y[i]]=sum[s.ft][s.sd]+1;
            }
        }
    }
}

int main()
{
    sf(m); sf(n);
    sf(p.ft); sf(p.sd);
    p.ft--; p.sd--;
    char c[100];
    rep(i,m)
        rep(j,n)
        {
            scanf("%s",c);
            a[i][j]=c[0];
        }
    clr(sum);
    bfs();
    int ans=-1;
    rep(i,m)
        rep(j,n)
            ans=max(ans, sum[i][j]);
    pf(ans);
}
