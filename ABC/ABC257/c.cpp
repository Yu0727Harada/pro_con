//
// Created on 2022/06/25.
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

int bit_s(int n,ll c,vl a){
    int ok = 0;
    int ng = n + 1;
    int mid;
    while(abs(ng - ok) > 1){
        mid = (ok + ng) / 2;
        if(a[mid] >= c){
            ng = mid;//ng adult start index
        }else{
            ok = mid;
        }
    }
    return ng;
}

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> child;
    vector<ll> adult;
    child.push_back(0);
    adult.push_back(0);
    child.push_back(INF + 10);
    adult.push_back(INF +10);
    for (int i = 0; i < n; ++i) {
        int w;
        cin>>w;
        if(s[i] == '0')child.push_back(w);
        else adult.push_back(w);
    }

    if(child.size() == 2){
        cout<<1<<endl;
        return 0;
    }else if(adult.size() == 2){
        ll ans = 0;
        for (int i = 0; i < child.size(); ++i) {
           chmax(ans,child[i]);
        }
        cout<<ans + 1<<endl;
        return 0;
    }


    sort(all(child));
    sort(all(adult));

    ll l = 0;
    ll r = 100;//INF + 10;
    ll c1;
    ll c2;

    int q;
    q = 1000;
    while(q){
        q--;
        c1 = (l * 2 + r)/3;
        c2 = (l + r * 2)/3;

        int c1ans;
        int c2ans;

        int c1_child_ad_start_index = bit_s(child.size(),c1,child);
        int c1_ad_ad_start_index = bit_s(adult.size(),c1,adult);
        int c2_child_ad_start_index = bit_s(child.size(),c2,child);
        int c2_ad_ad_start_index = bit_s(adult.size(),c2,adult);

        c1ans = ((child.size() - 2) - (c1_child_ad_start_index  - 1)) + (c1_ad_ad_start_index - 1);
        c2ans = ((child.size()  -  2) - (c2_child_ad_start_index - 1)) + (c2_ad_ad_start_index - 1 );

        if(c1ans > c2ans){
            l = c1;
        }else{
            r = c2;
        }

    }

    ll ans = 0;
    int c1_child_ad_start_index = bit_s(n,l,child);
    int c1_ad_ad_start_index = bit_s(n,l,adult);
    int c2_child_ad_start_index = bit_s(n,r,child);
    int c2_ad_ad_start_index = bit_s(n,r,adult);

    ll c1ans = ((child.size() - 2) - (c1_child_ad_start_index - 1)) + (c1_ad_ad_start_index - 1);
    ll c2ans = ((child.size() - 2)- (c2_child_ad_start_index - 1)) + (c2_ad_ad_start_index - 1);
    ans = min(c1ans,c2ans);
    cout<<n - ans<<endl;


    return 0;
}

