//
// Created on 2023/08/04.
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
    int n;
    cin>>n;
    vector<pair<string,int>>s(n);

    for (int i = 0; i < n; ++i) {
        cin>>s[i].first;
        s[i].second = i;
    }
    s.push_back({"@",-1});
    s.push_back({"|",-1});

    sort(all(s));

    vi ans(n,0);
    for (int i = 1; i <= n; ++i) {
        int ok = 0;
        for (int j = 0; j < max(s[i - 1].first.size(),s[i].first.size()); ++j) {
            if(s[i - 1].first[j] == s[i].first[j]){
                ok++;
            }else{
                break;
            }

        }
        if(s[i].second != -1){
            chmax(ans[s[i].second],ok);
        }
        if(s[i - 1].second != -1){
            chmax(ans[s[i - 1].second],ok);
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<endl;
    }


    return 0;
}
