//
// Created on 2020/01/19.
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
    int ans = 1;
    int n;
    cin>>n;
    vector<int>p(n);
    for (int i = 0; i < n; ++i) {
        cin>>p[i];
    }
    int min_v = p[0];
    for (int j = 1; j < n; ++j) {
        if (p[j]>min_v) continue;
        else if (p[j]<=min_v) {
            min_v = min(p[j],min_v);
            ans++;
        }
    }
    cout<<ans<<endl;
}
