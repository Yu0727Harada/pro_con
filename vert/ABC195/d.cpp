//
// Created by 原田 on 2022/08/02.
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
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<ll,ll>>item;//value,weight
    for (int i = 0; i < n; ++i) {
        ll w,v;
        cin>>w>>v;
        item.push_back({v,w});
    }
    sort(rall(item));
    vl box(m);
    for (int i = 0; i < m; ++i) {
        cin>>box[i];
    }
    for (int i = 0; i < q; ++i) {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        multiset<ll>av_box;
        for (int j = 0; j < m; ++j) {
            if(l <=j && j <= r)continue;
            else av_box.insert(box[j]);
        }
        ll ans = 0;
        for (int j = 0; j < n; ++j) {
            ll value = item[j].first;
            ll size = item[j].second;
            auto it = av_box.lower_bound(size);
            if(it != av_box.end()){
                ll index = *it;
                ans += value;
                auto c = av_box.erase(index);
                for (int k = 0; k < c - 1; ++k) {
                    av_box.insert(index);
                }
            }

        }
        cout<<ans<<endl;
        av_box.clear();
    }

    return 0;
}
