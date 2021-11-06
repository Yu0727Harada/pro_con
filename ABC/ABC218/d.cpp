
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

    vector<pair<int,int>>x_y;

    map<int,vector<pair<int,int>>>mp;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin>>x>>y;
        x_y.push_back({x,y});
        mp[x].push_back({y,i});
    }

    int ans = 0;


    vector<vector<int>>ans_p;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(i == j)continue;
            vector<int>temp;
            bool f_find = false;
            temp.push_back(i + 1);
            temp.push_back(j + 1);
            for(auto item:mp[x_y[i].first]){
                if(item.first == x_y[j].second && item.second != i && item.second != j){
                    f_find = true;
                    temp.push_back(item.second + 1);
                }
            }
            if(!f_find)continue;
            f_find = false;
            for(auto item:mp[x_y[j].first]){
                if(item.first == x_y[i].second && item.second != i && item.second != j){
                    f_find = true;
                    temp.push_back(item.second + 1);
                }
            }
            if(f_find){
                ans ++;
                sort(all(temp));
                ans_p.push_back(temp);
            }

        }
    }

    sort(all(ans_p));
    auto result = unique(all(ans_p));
    ans_p.erase(result,ans_p.end());
    cout<<ans_p.size()<<endl;



    return 0;
}
