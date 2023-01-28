#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
int main() {
    int n,k; cin>>n>>k;
    int aa[n];
    for(int i=0; i<n; i++) cin>>aa[i];
    ordered_set<pair<int,int>>s;
    for(int i=0; i<k; i++) {
        s.insert({aa[i],i});
    }
    cout<<s.find_by_order((k-1)/2) -> first <<" ";
    for(int i=1; i<n-k+1; i++) {
        s.erase({aa[i-1],i-1});
        s.insert({aa[i+k-1],i+k-1});
        cout<<s.find_by_order((k-1)/2)->first<<" ";
    }
}
