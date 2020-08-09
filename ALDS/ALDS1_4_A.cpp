//
// Created on 2020/04/12.
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


using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int ans = 0;
    int n,q;
    cin>>n;
    vector<int>s(n);
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    cin>>q;
    vector<int>t(q);
    for (int j = 0; j < q; ++j) {
        cin>>t[j];
    }
    for(auto a:t){
        for (auto b : s) {
            if(a == b){
                ans++;
                break;
            }
        }
    }

    cout<<ans<<endl;
}
