//
// Created on 2020/05/12.
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

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a %b);
}


ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}


int solve(){
    int n;
    cin>>n;
    stack<ll>st;
    ll now;
    vector<ll>a;
    for (int i = 0; i < n; ++i) {
        cin>>now;
        a.push_back(now);
    }
    for (int j = 0; j < n; ++j) {
        for (int i = j+1; i <n ; ++i) {
            st.push(lcm(a[j],a[i]));
        }
    }

    while(!(st.size() == 1)){
        ll first = st.top();
        st.pop();
        ll second = st.top();
        st.pop();
        st.push(gcd(first,second));
    }
    ll ans = st.top();
    cout<<ans<<endl;
}

int main() {
    int t;
    t = 1;
    while(t){
        solve();
        t--;
    }


    return 0;
}
