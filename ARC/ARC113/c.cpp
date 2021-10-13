//
// Created by 原田 on 2021/10/01.
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
    string s;
    cin>>s;

    reverse(all(s));

    map<char,int>mp;
    vector<int> memo(s.size());

    mp[s[0]]++;
    ll ans = 0;
    char last = '@';
    int last_v = 0;
    for (int i = 1; i < s.size() - 1; ++i) {
        if(s[i] == s[i+1]){
            if(last == s[i]){
                ans += i - mp[s[i]] - last_v;
                last_v = i;
                last = s[i];
                mp.clear();
            }else{
                ans += i - mp[s[i]];
                last_v = i;
                last = s[i];
                mp.clear();
            }
            int j = i;
            while(s[i] != s[j]){
                i++;
            }
        }
        mp[s[i]]++;
    }

    cout<<ans<<endl;

    return 0;
}
