//
// Created on 2021/03/11.
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
    int a,b,c;
    cin>>a>>b>>c;
    int k;
    cin>>k;

    int ans = 0;
    queue<vector<int>>q;
    q.push({0,a,b,c});
    while(!q.empty()){
        int t_a,t_b,t_c;
        int cnt;
        cnt = q.front()[0];
        t_a = q.front()[1];
        t_b = q.front()[2];
        t_c = q.front()[3];
        q.pop();
        if(cnt == k){
            chmax(ans,t_a + t_b + t_c);
        }else{
            cnt++;
            q.push({cnt,t_a * 2,t_b,t_c});
            q.push({cnt,t_a,t_b * 2,t_c});
            q.push({cnt,t_a,t_b,t_c * 2});
        }

    }
    cout<<ans<<endl;
    return 0;
}
