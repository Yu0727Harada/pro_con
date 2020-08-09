//
// Created on 2020/05/03.
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


int main() {
    int ans = 0;
    int n,m;
    cin>>n>>m;
    vector<int>high(n);
    vector<vector<int>>edge(n,vector<int>());

    for (int i = 0; i < n; ++i) {
        cin>>high[i];
    }
    for (int j = 0; j < m; ++j) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int k = 0; k < n; ++k) {
        bool ok = true;
        for (int i = 0; i < edge[k].size(); ++i) {
            if(high[edge[k][i]] >= high[k]){
                ok = false;
                break;
            }
        }
        if(ok) ans ++;
    }

    cout<<ans<<endl;
    return 0;
}
