//
// Created on 2020/01/18.
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

int main() {
    int n;
    int k;
    ll s;
    cin>>n>>k>>s;
    vector<ll>ans(n);
    for (int i = 0; i < k; ++i) {
        ans[i] = s;
    }
    for (int j = k; j < n; ++j) {
        if (s >= INF) {
            ans[j] = s-1;
        }else{
            ans[j] = s+1;
        }
    }
    cout<<ans[0];
    for (int l = 1; l < n; ++l) {
        cout<<" "<<ans[l];
    }
    cout<<endl;
}
