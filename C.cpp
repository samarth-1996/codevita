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

int m,n;
int a[100][100];
pii p;
int d1[4]={0,1,-1,0};
int d2[4]={-1,0,0,1};
int sum[100][100];

void bfs()
{
    queue<pii> q;
    q.push(p);
    sum[p.ft][p.sd]=1;
    while(!q.empty())
    {
        pii s=q.front();
        q.pop();
        int x=s.ft;
        int y=s.sd;
        int S=-1;
        rep(i,4)
            if (x+d1[i]>=0 && x+d1[i]<m && y+d2[i]>=0 && y+d2[i]<n && a[x+d1[i]][y+d2[i]]<a[x][y])
                S=max(S, a[x+d1[i]][y+d2[i]]);
        rep(i,4)
            if (x+d1[i]>=0 && x+d1[i]<m && y+d2[i]>=0 && y+d2[i]<n && a[x+d1[i]][y+d2[i]]==S)
            {
                sum[x+d1[i]][y+d2[i]]=sum[x][y]+1;
                q.push(mp(x+d1[i],y+d2[i]));
            }
    }
}

int main()
{
    scanf("%d,%d",&m,&n);
    rep(i,m)
    {
        rep(j,n-1)
            scanf("%d,",&a[i][j]);
        scanf("%d",&a[i][n-1]);
    }
    scanf("%d,%d",&p.ft,&p.sd);
    p.ft--; p.sd--;
    clr(sum);
    bfs();
    int ans=1;
    rep(i,m)
        rep(j,n)
            ans=max(ans, sum[i][j]);
    pf(ans);
}

