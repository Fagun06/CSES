                   /**Bismillahir Rahmanir Rahim.**/
/*
         Md.Fagun Molla
         18ICTCSE006
         BSMRSTU(SHIICT)
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll=long long int;
using db=double;
///***************************************************** CONSTANTS ******************************************************///
 
int const N=2*(1e6);
int const mod=1e9+7;
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
 
 
 
 
ll invFact[N+1];
ll fact[N+1];
 
ll power(ll a , ll n){
    ll res = 1;
    while(n){
        if(n & 1) res = (res * a) % mod;
        
        n >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
 
void init(){
    fact[0] = invFact[0] = 1;
    for(int i=1;i<=N;i++)
    {
        fact[i] = (fact[i-1] * i) % mod;
        invFact[i] = power(fact[i] , mod-2);
    }
}
 
int nCr(int a, int b) {
    ll res = (fact[a] * invFact[b]) % mod;
    res = (res * invFact[a - b]) % mod;
    
    return res;
}
 
void solve(){
  ll n,k; cin>>n>>k;
  
  cout<<nCr(n+k-1,k);
    
}
int main()
{
   // io();
    init();
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
