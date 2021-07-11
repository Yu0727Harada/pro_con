//
// Created on 2021/03/13.
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

    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    vector<pair<ll, ll>> load(n);
    vl box(m);

    for (int i = 0; i < n; ++i) {
        cin>>load[i].second>>load[i].first;
    }
    for (int i = 0; i < m; ++i) {
        cin>>box[i];
    }
    sort(rall(load));
    while(q){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        vector<pair<ll,ll>>box_l(m,{-1,0});//荷物のid,価値

        for (int i = 0; i < n; ++i) {
            int min_box_id = -1;
            int min_box_size = INF;

            for (int j = 0; j < m; ++j) {
                if(load[i].second <= box[j] && (j < l || r < j)){
                    if(min_box_size > box[j] && box_l[j].first == -1){
                        min_box_id = j;
                        min_box_size = box[j];
                    }
                }
            }
            if(min_box_id == -1)continue;
            box_l[min_box_id] = {i,load[i].first};
        }
        ll ans = 0;
        for (int i = 0; i < m; ++i) {
            ans += box_l[i].second;
        }

        cout<<ans<<endl;
        q--;
    }

    return 0;
}
