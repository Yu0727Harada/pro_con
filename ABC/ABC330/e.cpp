
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

int bit_search(int target, vector<pair<int,int>>li){
    int ok = 0;
    int ng = li.size();
    int mid;
    while(ng - ok > 1){
        mid = (ok + ng) / 2;
        if(target < li[mid].first){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    return ok;
}


int main() {
    int n;
    cin>>n;
    int q;
    cin>>q;

    vi a(n);
    map<int,int>mp;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        mp[a[i]]++;
    }
    vi b = a;
    sort(all(b));

    vector<pair<int,int>>not_in_li;
    int now_v = 0;

    for (int i = 0; i < n; ++i) {
        if(b[i] - now_v == 0){
            now_v++;
        }else if(b[i] > now_v){
            not_in_li.push_back({now_v,b[i] - 1});
            now_v = b[i] + 1;
        }else if(b[i] < now_v){
            continue;
        }
    }
    not_in_li.push_back({now_v,INF});

    for (int i = 0; i < q; ++i) {
        int c,x;
        cin>>c>>x;
        int prev_v = a[c];
        if(mp[prev_v] == 1){
            //１個しかないなら消す
            mp[prev_v] = 0;
            int itr = bit_search(prev_v,not_in_li);


        }else if(mp[prev_v] > 1){
            mp[prev_v] --;
        }

    }
    return 0;
}
