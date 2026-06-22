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


vll col;
int n,g;
map<ll,vector<ll>>adj;
vector<bool>vis(n+1,0);
vll path;

bool idx(int v,int limit)
{
   path.pb(v);
   vis[v]=1;
   if(v==g)
   {
       return 1;
   }
   if(limit==0)
   {
       path.pop_back();
       return 0;
   }
   for(auto u:adj[v])
   {
       if(!vis[u])
       {
           if(idx(u,limit-1))return 1;
       }
   }
   path.pop_back();
   return 0;
}

void solve(int tc,int t5)
{  int limit,u,v;
cin>>n>>limit>>g;
for(int i=0;i<n-1;i++)
{   cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}
for(int i=0;i<=limit;i++)
{   vis.assign(n+1,0);
path.clear();
    if(idx(1,i))
    {
        cout<<"goal is found"<<endl;
        for(auto u:path)cout<<u<<" ";
        cout<<endl;
    }
    else cout<<"NOT FOUND"<<endl;
}


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
