//
// Created on 2020/05/16.
//

#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;

int solve(){
    int n;
    cin>>n;
    map<int,int>mp;
    for (int i = 0; i < n; ++i) {
        int e;
        cin>>e;
        mp[e] ++;
    }
    int ans = 0;
    int amari = 0;
    for(auto a:mp){
        ans += (a.second + amari) / a.first;
        amari = (a.second + amari) % a.first;
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t){
        solve();
        t--;
    }
    return 0;
}
