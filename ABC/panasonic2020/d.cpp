//
// Created on 2021/01/01.
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


void out_char(int now,int cnt,string ans, int N){
    for (int i = 0; i <= cnt + 1; ++i) {
        int output_num = 'a' + i;
        char output = static_cast<char>(output_num);
        string ans_t = ans;
        ans_t += output;
        int next_cnt = max(i,cnt);
        int next_now = now + 1;
        if(ans_t.size() == N){
            cout<<ans_t<<endl;
            continue;
        }
        if(next_now < N){
            out_char(next_now,next_cnt,ans_t,N);
        }

    }

}

int main() {
    int n;
    cin>>n;

    out_char(0,-1,"",n);

    return 0;
}
