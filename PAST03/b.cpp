//
// Created on 2020/06/06.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n,m;
    cin>>n>>m;
    int q;
    cin>>q;
    vector<vector<ll>>q_score(n,vector<ll>());
    vector<ll>q_point(m,n);

    for (int i = 0; i < q; ++i) {
        int s;
        cin>>s;
        if(s == 1){
            int a;
            cin>>a;
            a--;
            ll sum = 0;
            for (int j = 0; j < q_score[a].size(); ++j) {
                sum += q_point[q_score[a][j]];
            }
            cout<<sum<<endl;
        }else{
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            q_point[b] --;
            q_score[a].push_back(b);
        }
    }

    return 0;
}
