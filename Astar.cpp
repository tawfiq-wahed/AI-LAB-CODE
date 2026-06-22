//i'm just doing shit
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long
#define endl '\n'
#define orderedset tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define tawfiq() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define F first
#define S second
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef vector<ll>vll;
typedef  vector<int>vi;
typedef pair<ll,ll>pll;
typedef vector<pair<ll,ll>>vpll;
#define gcd(a,b) __gcd(a,b)
const ll mod=1000000007;
#define lcm(a,b) ((a/gcd(a,b))*1ll*b)
#define mem(a,b) memset(a,b,sizeof(a))
const ll INF=1e18;
const int p=2e5+123;

ll mul(ll a ,ll b)
{
    return((((a%mod)+mod)%mod)*(((b%mod)+mod)%mod))%mod;
}
ll add(ll a ,ll b)
{
    return((((a%mod)+mod)%mod)+(((b%mod)+mod)%mod))%mod;
}
ll binexpo(ll a ,ll b)
{
    if(b==0)return 1ll;
   ll res=1;
    res=binexpo(a,b/2);
    if(b%2==0) return res=mul(res,res);
    else return res=mul(res,mul(res,a));

}
vll fact(20,0);
void fac()
{
    fact[0]=1;
    for(int i=1;i<20;i++)
    {
        fact[i]=fact[i-1]*i;
    }
}


//inversion count  with fenwick tree
vll par;
vll sz,mn;
int find_par(int u)
{
    if(par[u]==u)return u;
   return par[u]=find_par(par[u]);
}
void Union(int u,int v)
{
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
    mn[u]=min(mn[u],mn[v]);

}
vector<bool>isprime(100000+10,0);
vector<ll>primes;

void sieve(ll n)
{ isprime[2]=1;
    for(ll i=3;i<=n;i+=2)isprime[i]=1;
    for(ll i=2;i*i<=n;i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                isprime[j]=0;
            }
        }
    }
    primes.pb(2);
    for(ll i=3;i<=n;i++)
    {
        if(isprime[i])primes.pb(i);
    }
}

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct Node
{
    int x;int y;int g;int f;int h;
    bool operator<(const Node &other )const{
    return f>other.f;
    }
};

int heuristic(int x,int y,int tx,int ty)
{
    return abs(tx-x)+abs(ty-y);
}
int astar(vector<string>&grid,pair<int,int>start,pair<int,int>goal)
{
   int n=grid.size();
   int m=grid[0].size();
   vector<vll>dist(n,vector<ll>(m,INF));
   priority_queue<Node>pq;
   int sx=start.F;
    int sy=start.S;
    int gx=goal.F;
    int gy=goal.S;
    int h=heuristic(sx,sy,gx,gy);
    pq.push({sx,sy,0,h,h});
    dist[sx][sy]=0;
    while(!pq.empty())
    {
        Node cur=pq.top();
        pq.pop();
        int x=cur.x;
        int y=cur.y;
        if(x==gx &&y==gy)return cur.g;
        if(cur.g>dist[x][y])continue;
        for(int i=0;i<4;i++)
        {
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(nx<0 ||nx>=n ||ny<0 ||ny>=m)continue;
            if(grid[nx][ny]=='#')continue;
            int ng=cur.g+1;
            int nh=heuristic(nx,ny,gx,gy);
            pq.push({nx,ny,ng,nh,ng+nh});
        }
    }
    return -1;
}

void solve(int tc,int t5)
{   vector<string> grid = {
        "...#.",
        ".#...",
        "...#.",
        "....."
    };

    pair<int,int> start = {0, 0};
    pair<int,int> goal  = {3, 4};

    cout << astar(grid, start, goal) << '\n';

}






int main()
{
     tawfiq();
 //  sieve(100000);
  int t;
  t=1;
//cin>>t;

  for(int i=1;i<=t;i++)
  {
      solve(i,t);
  }
}
