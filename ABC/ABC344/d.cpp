//
// Created by yuha on 2024/05/11.
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
//#include <atcoder/all>


#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    string t;
    cin>>t;
    int n;
    cin>>n;
    map<string,int>mp;

    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        queue<pair<string,int>>q;
        for (int j = 0; j < a; ++j) {
            string tmp;
            cin>>tmp;
            bool ok = true;
            for (int k = 0; k < tmp.size(); ++k) {
                if(tmp[k] != t[k])ok = false;
            }
            if(ok)q.push({tmp,1});
            for(auto item:mp){
                if(item.first.size()+tmp.size() > t.size())continue;
                ok = true;
                for (int k = 0; k <  tmp.size(); ++k) {
                    if(tmp[k] != t[item.first.size() + k])ok =false;
                }
                if(ok)q.push({item.first + tmp,item.second+ 1});
            }

        }
        while(!q.empty()) {
            string t = q.front().first;
            int c = q.front().second;
            q.pop();
            if (mp[t] == 0) {
                mp[t] = c;
            } else if (c < mp[t]) {
                mp[t] = c;
            }
        }

    }
    if(mp[t] == 0){
        cout<<-1<<endl;
    }else{
        cout<<mp[t]<<endl;
    }
    return 0;
}
