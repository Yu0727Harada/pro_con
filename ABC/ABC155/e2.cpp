//
// Created on 2020/02/16.
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
    int ans = INF;
    string s;
    cin>>s;
    ll n = 0;
    vector<int>s_i(s.size());
    for (int i = 0; i < s.size(); ++i) {
        n+=s[i]-'0';
        s_i[i] = s[i]-'0';
    }
    vector<int>added(100,0);
    for (int j = 0; j < 100; ++j) {
        for (int k = s[j]-'0'; s[j]-'0'+k<=9; ++k) {
            added[j] = k;
            s_i[j] = k;
            auto a_sum = accumulate(all(added),0LL);
            auto s_sum = accumulate(all(s_i),0LL);
        
            //0LL long long,0 int,0.0 double
            )

        }
    }


    cout<<ans<<endl;
}
