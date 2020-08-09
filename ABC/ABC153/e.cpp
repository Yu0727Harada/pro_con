//
// Created on 2020/01/26.
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

//個数制限無しナップザックDP
//https://atcoder.jp/contests/abc153/tasks/abc153_e

int main() {
    int h;
    int n;
    cin>>h>>n;
    vector<int>A(n);
    vector<int>B(n);
    for (int l = 0; l < n; ++l) {
        cin>>A[l];
        cin>>B[l];
    }

    vector<vector <ll > > mp (n+1,vector<ll >(h+1,LINF));
    mp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= h; ++j) {
            mp[i+1][j] = min(mp[i+1][max(0,j-A[i])]+B[i],mp[i][j]);
            //for (int k = 1; A[i]*k <=h+k ; ++k) {
            //    mp[i+1][min(h,j+A[i]*k)] = min(mp[i+1][min(h,j+A[i]*k)],mp[i][j]+B[i]*k);}
        }
    }


    cout<<mp[n][h]<<endl;
}
