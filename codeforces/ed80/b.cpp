//
// Created on 2020/01/15.
//

//#include <bits/stdc++.h>
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
using gragh = vector<vector<int>>;

double count_ten(ll a){
    ll c = 1;

    while (a / 10 >0){
        a /= 10;
        c++;
    }
    return c;
}

void solve(){
    ll a,b;
    cin>>a>>b;
    ll ans = 0;
    double ten = count_ten(b);

    for (int i = 1; i <= ten; ++i) {
        if((pow(10,i)-1 <=b)){
            ans+=a;
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;
}

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        solve();
    }


}
