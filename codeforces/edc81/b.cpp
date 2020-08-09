//
// Created on 2020/01/29.
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
    string t;
    int ans = 1;
    cin>>s>>t;
    map<char,vector<int>>mp;

    for (int k = 1; k <= s.size(); ++k) {
        mp[s[k-1]].push_back(k);
    }
    vector<int>a(t.size(),-1);
    vector<int> last;
    int last_i =0;
    vector<int> now ;
    int now_i =0;
    map<char,vector<int>>temp_map;
    temp_map =mp;
    for (int l = 0; l < t.size(); ++l) {
        if (mp[t[l]].empty() ){
            cout<<-1<<endl;
            return;
        }
        now = temp_map[t[l]];
        now_i = now[0];
        if (temp_map[t[l]].size()>1){
            temp_map[t[l]].erase(temp_map[t[l]].begin());
        }
        if(now_i <= last_i) {
            temp_map = mp;
            ans ++;
        }
        last_i = now_i;
    }
    cout<<ans<<endl;
    return ;
}

int main() {
    int n;
    cin>>n;
    while(n){
        n--;
        solve();
    }

}

