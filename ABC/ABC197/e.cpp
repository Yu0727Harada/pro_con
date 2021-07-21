//
// Created on 2021/03/27.
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
    int n;
    cin>>n;

    map<int,vector<int>>ball;
    vector<int> c_list;
    for (int i = 0; i < n; ++i) {
        int x,c;
        cin>>x>>c;
        ball[c].push_back(x);
        c_list.push_back(c);
    }
    sort(all(c_list));
    vi log(n,INF);

    queue<vector<ll>> q;

    for (int i = 0; i < ball[c_list[0]].size(); ++i) {
        ll min_value = *min_element(all(ball[c_list[0]]));
        ll max_value = *max_element(all(ball[c_list[0]]));
        ll now_position = 0;
        ll cost;
        if(now_position < min_value){
            cost = abs(max_value - now_position) + abs(ball[c_list[0]][i] - max_value);
        }else if(min_value <= now_position && now_position <= max_value){
            if(abs(now_position - min_value) < abs(max_value - now_position)){
                cost = abs(now_position - min_value) + abs(max_value - min_value) + abs(ball[c_list[0]][i] - max_value);
            }else{
                cost = abs(max_value- now_position) + abs(max_value - min_value) + abs(ball[c_list[0]][i] - min_value);
            }
        }else{
            cost = abs(min_value - now_position) + abs(ball[c_list[0]][i] - min_value);
        }

        q.push({1,cost,ball[c_list[0]][i]});
    }

    ll ans = LINF;
    while(!q.empty()){
        ll now_ball = q.front()[0];
        ll p_cost = q.front()[1];
        ll now_position = q.front()[2];
        q.pop();


        if(c_list.size() - 1 == now_ball){
            ans = min(p_cost + now_position,ans);
            continue;
        }

        for (int i = 0; i < ball[c_list[now_ball]].size(); ++i) {
            ll min_value = *min_element(all(ball[c_list[now_ball]]));
            ll max_value = *max_element(all(ball[c_list[now_ball]]));
            ll cost = p_cost;
            if(now_position < min_value){
                cost += abs(max_value - now_position) + abs(ball[c_list[now_ball]][i] - max_value);
            }else if(min_value <= now_position && now_position <= max_value){
                if(abs(now_position - min_value) < abs(max_value - now_position)){
                    cost += abs(now_position - min_value) + abs(max_value - min_value) + abs(ball[c_list[now_ball]][i] - max_value);
                }else{
                    cost += abs(max_value- now_position) + abs(max_value - min_value) + abs(ball[c_list[now_ball]][i] - min_value);
                }
            }else{
                cost += abs(min_value - now_position) + abs(ball[c_list[now_ball]][i] - min_value);
            }

            q.push({now_ball + 1,cost,ball[c_list[now_ball]][i]});
        }


    }

    return 0;
}
