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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {

    int n,x,y;
    cin>>n>>x>>y;
    n--;
    x--;
    y--;

    map<int,int>mp;

    for (int i = 0; i < n; ++i) {
        vector<int>edge(n+1);
        for (int j = 0; j <= n; ++j) {
            edge[j] = abs(j-i);
        }
        edge[y] = min(edge[y],edge[x]+1);

        for (int m = y+1; m <= n; ++m) {
            edge[m] = min(edge[m],edge[m-1]+1);
        }
        for (int k = y-1; k >=0 ; --k) {
            edge[k] = min(edge[k],edge[k+1]+1);
        }
        for (int l = i; l <= n; ++l) {
            mp[edge[l]] += 1;
        }

    }
    for (int m = 1; m <= n; ++m) {
        cout<<mp[m]<<endl;
    }
}
