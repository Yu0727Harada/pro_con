//
// Created on 2021/08/08.
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

    vector<int>number_a;
    vi number_b;
    int h,w;
    cin>>h>>w;
    int n;
    cin>>n;

    vector<pair<int,int>>card(n);
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        number_a.push_back(a);
        number_b.push_back(b);
        card[i] = {a,b};
    }

    sort(all(number_a));
    sort(all(number_b));

    auto result_a = unique(all(number_a));
    auto result_b = unique(all(number_b));

    number_a.erase(result_a,number_a.end());
    number_b.erase(result_b,number_b.end());

    map<int,int>mp_a;
    for (int i = 0; i < number_a.size(); ++i) {
        mp_a[number_a[i]] = i;
    }
    map<int,int>mp_b;
    for (int i = 0; i < number_b.size(); ++i) {
        mp_b[number_b[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        cout<<mp_a[card[i].first]+ 1<<" "<<mp_b[card[i].second] + 1<<endl;
    }

    return 0;
}
