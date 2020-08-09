//
// Created on 2020/03/28.
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
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    ll ans = 0;
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;

    vector<int>A(a);
    for (int i = 0; i < a; ++i) {
        cin>>A[i];
    }
    vector<int>B(b);
    for (int i = 0; i < b; ++i) {
        cin>>B[i];
    }
    vector<int>C(c);
    for (int i = 0; i < c; ++i) {
        cin>>C[i];
    }
    sort(rall(A));
    sort(rall(B));

    vector<int>D;
    for (int j = 0; j < x; ++j) {
        D.push_back(A[j]);
    }
    for (int k = 0; k < y; ++k) {
        D.push_back(B[k]);
    }
    for (int l = 0; l < c; ++l) {
        D.push_back(C[l]);
    }
    sort(rall(D));
    for (int m = 0; m < x+y; ++m) {
        ans += D[m];
    }

    cout<<ans<<endl;
}
