//
// Created on 2020/02/09.
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
    double ans = 0;
    int n;
    int k;
    cin>>n>>k;
    vector<int>p(n);
    for (int i = 0; i < n; ++i) {
        cin>>p[i];
    }
    vector<double >table(1000+10);
    table[1] = 1;
    for (int j = 2; j <= 1000; ++j) {
        table[j] = (table[j-1]*(j-1)+j)/j;
    }

    for (int l = 0; l < k; ++l) {
        ans += table[p[l]];
    }

    double temp = ans;
    for (int m = 0; m + k < n; ++m) {
        temp -= table[p[m]];
        temp += table[p[k+m]];
        ans = max(temp,ans);
    }

    printf("%.10f\n", ans);
}
