//
// Created on 2021/09/11.
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

    ll n;
    cin>>n;

    vector<pair<ll,ll>>s;
    vector<pair<ll,ll>>t;

    pair<ll,ll> s_d = {0,0};
    pair<ll,ll> t_d = {0,0};

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            char temp;
            cin>>temp;
            if(temp == '#'){
                s.push_back({(ll)i,(ll)j});
                s_d.first += (ll)i;
                s_d.second += (ll )j;
            }
        }
    }


    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            char temp;
            cin>>temp;
            if(temp == '#'){
                t.push_back({(ll)i,(ll)j});
                t_d.first += i;
                t_d.second += j;
            }
        }
    }
    if(s.size() != t.size()){
        cout<<"No"<<endl;
        return 0;
    }

    vector<pair<ll,ll>>s_array;
    for (ll i = 0; i < s.size(); ++i) {
        s_array.push_back({(s[i].first * s.size())- s_d.first,(s[i].second * s.size()) - s_d.second});
    }
    sort(all(s_array));
    vector<pair<ll,ll>>t_array;
    for (ll j = 0; j < t.size(); ++j) {
        t_array.push_back({ (t[j].first * t.size())- t_d.first,( t[j].second * t.size()) - t_d.second});
    }
    for (ll i = 0; i < 4; ++i) {
        vector<pair<ll,ll>>t_t_array;
        ll x_prefix = 1;
        ll y_prefix = 1;
        if(i == 0){
            x_prefix = 1;
            y_prefix = 1;
            for (ll j = 0; j < t.size(); ++j) {
                t_t_array.push_back({(x_prefix * t_array[j].first),(y_prefix * t_array[j].second)});
            }
        }else if(i == 1){
            x_prefix = -1;
            y_prefix = 1;
            for (ll j = 0; j < t.size(); ++j) {
                if(t_array[j].second == 0)x_prefix = 1;
                t_t_array.push_back({(x_prefix * t_array[j].second),(y_prefix * t_array[j].first) });
                x_prefix = -1;
            }
        }else if(i == 2){
            x_prefix = -1;
            y_prefix = -1;
            for (ll j = 0; j < t.size(); ++j) {
                if(t_array[j].first == 0)x_prefix = 1;
                if(t_array[j].second == 0)y_prefix = 1;
                t_t_array.push_back({(x_prefix * t_array[j].first),(y_prefix * t_array[j].second) });
                x_prefix = -1;
                y_prefix = -1;
            }
        }else{
            x_prefix = 1;
            y_prefix = -1;
            for (ll j = 0; j < t.size(); ++j) {
                if(t_array[j].first == 0)y_prefix = 1;
                t_t_array.push_back({(x_prefix * t_array[j].second),(y_prefix * t_array[j].first) });
                y_prefix = -1;
            }
        }

        sort(all(t_t_array));
        if(s_array == t_t_array){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;

    return 0;
}

