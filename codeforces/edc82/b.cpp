//
// Created on 2020/02/12.
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

void solve(){
    string s;
    cin>>s;
    int ans = 0;
    int temp = 0;
    bool notice = false;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='0' && notice) temp++;
        if(s[i]=='1' && !(notice)) {
            notice = true;
        }else if(s[i]=='1' && notice) {
            ans += temp; temp = 0;
        }
    }
    cout<<ans<<endl;

}

int main() {
    int n;
    cin>>n;

    while(n){
        n--;
        solve();
    }

}
