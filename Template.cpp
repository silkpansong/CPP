// Silkpan Template 

#include <bits/stdc++.h>
 
#define listprint(x) for(long long i=0;i<x.size();i++){cout<<x[i]<<" ";} cout<<endl;
#define forn(i,n) for(int i=0;i<n;i++)
#define fornrev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define F first 
#define S second

using namespace std;
using vi = vector<int>;
using ll = long long;
using pi= pair<int,int>;

void print() {
    std::cout << std::endl;
}
template <typename T, typename... Args>
void print(T first_arg, Args... remaining_args) {
    std::cout << first_arg;
    if (sizeof...(remaining_args) > 0) {
        std::cout << " ";
    }
    print(remaining_args...);
}

int MOD = 1e9+7;
 
ll mul(ll x, ll y) {
    return (x % MOD) * (y % MOD) % MOD;
}
 
void solve(){
    ll n;
    cin>>n;

}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
