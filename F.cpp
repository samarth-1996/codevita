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

vi v[30];
int n;
int in[30];
vector<string> S;

inline void toposort(vi ans, bool b[])
{
    bool flag=false;
    rep(i,26)
    {
        if (in[i]==0 && !b[i])
        {
            rep(j,sz(v[i]))
                in[v[i][j]]--;
            ans.pb(i);
            b[i]=true;
            toposort(ans,b);
            b[i]=false;
            ans.erase(ans.end()-1);
            rep(j,sz(v[i]))
                in[v[i][j]]++;
            flag=true;
        }
    }
    if (!flag)
    {
        string st;
        rep(i,sz(ans))
            st.pb(ans[i]+'A');
        S.pb(st);
    }
}

void topo()
{
    bool b[30];
    clr(b);
    vi ans;
    toposort(ans, b);
}

int main()
{
    cin>>n;
    string s;
    clr(in);
    rep(i,n)
    {
        cin>>s;
        int m=s.length();
        rep(i,m)
            repp(j,i+1,m)
            {
                v[s[i]-'A'].pb(s[j]-'A');
                in[s[j]-'A']++;
            }
    }
    topo();
    sort(all(S));
    rep(i,sz(S))
        cout<<S[i]<<endl;
}
