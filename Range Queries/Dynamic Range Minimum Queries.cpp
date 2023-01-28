                   /**Bismillahir Rahmanir Rahim.**/
/*
         Md.Fagun Molla
         18ICTCSE006
         BSMRSTU
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll=long long;
using db=double;
///***************************************************** CONSTANTS ******************************************************///
 
int const N=1e6+3;
ll MOD=1e9+7,fact[N];
const long long inf=(long long)1e18;
const long double PI=3.14159265358979;
 
///************************************************ CONTAINER DEFINITIONS ***********************************************///
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
///************************************************ SHORT FORM KEYWORDS *************************************************///
 
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define I insert
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
 
///************************************************ SHORT FORM FUNCTIONS ************************************************///
 
#define loop(a,b) for(ll i=a;i<b;i++)
#define loopr(a,b) for(ll i=a-1;i>=b;i--)
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sa(v) sort(v.begin(),v.end())
#define sd(v) sort(v.begin(),v.end(),greater<>())
#define rev(s) reverse(s.begin(),s.end())
#define stll(x) stoll(x, nullptr, 10);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define all(a) a.begin(),a.end()
#define mxa(a,N) *max_element(a,a+N)
#define mna(a,N) *min_element(a,a+N)
#define print(a) {for(auto x:a)cout<<x<<" ";cout<<endl;}
#define io() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
 
///************************************************ SOLUTION STARTS HERE ************************************************///
///======================================================================================================================///
 
ll arr[N];
ll tre[N*4];///tree array
///initilization tree array
void init(ll node,ll b,ll e)///b=begin node,e=end node
{
    if(b==e)
    {
        tre[node]=arr[b];
        return;
    }
    ll leftnode = node*2;///indexing child left and right node
    ll rightnode = node*2+1;
    ll mid = (b+e)/2;
    init(leftnode,b,mid);///break the array into two part
    init(rightnode,mid+1,e);
    tre[node]=min(tre[leftnode],tre[rightnode]);///store the value in parent node
}
ll query(ll node,ll b,ll e,ll i,ll j)///i and j=expected range in query
{
    if(i>e || j<b) ///if the given range in not able in the range
    {
        return MOD;
    }
    if (b>=i && e<=j)///if the given range in not able in the range
    {
        return tre[node];
    }
    ll leftnode = node*2;
    ll rightnode = node*2+1;
    ll mid = (b+e)/2;
    ll x=query(leftnode,b,mid,i,j);
    ll y=query(rightnode,mid+1,e,i,j);
    return min(x,y);
}
 
 
 
void update(ll node,ll b,ll e,ll i,ll newvalue)///change the value of ith index
{
    if(i>e || i<b) ///if the given range in not able in the range
    {
        return;
    }
    if (b>=i && e<=i)///find element->leap node
    {
        tre[node]=newvalue;///update the value
        return;
    }
    ll leftnode = node*2;
    ll rightnode = node*2+1;
    ll mid = (b+e)/2;
    update(leftnode,b,mid,i,newvalue);
    update(rightnode,mid+1,e,i,newvalue);
    tre[node]=min(tre[leftnode],tre[rightnode]);///store the value in parent node after the updating new value
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    map<ll,ll>pp;
    ll n,e,i,j,l,m,x,y,z,r,k;
    cin>>n>>k;
    for(i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    init(1,1,n);
    for(i=0; i<k; i++)
    {
        cin>>x>>l>>r;
        if(x==1)
        {
            update(1,1,n,l,r);///updating value l=ith insex r=newvalue
            continue;
        }
        else {
            ll ans=query(1,1,n,l,r);
            cout<<ans<<endl;
        }
    }
}
int main()
{
    io();
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
//cout<<fixed<<setprecision(9)
