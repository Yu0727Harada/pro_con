//
// Created on 2020/05/02.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;

long long ans = 0;

void search(vector<int> a,int cnt,int n,int now,int m,vector<vector <int> >q_d){
    a[cnt] = now;
    if(cnt == n - 1){
        long long temp = 0;
        for (int i = 0; i < q_d.size(); ++i) {
            if(a[q_d[i][1] - 1] - a[q_d[i][0] - 1] == q_d[i][2]){
                temp += q_d[i][3];
            }
        }
        ans = max(temp,ans);

    }else{
    for (int i = now ; i <= m; ++i) {
        search(a,cnt+1,n,i,m,q_d);
    }
    }
}

int main() {

    int n,m,q;
    cin>>n>>m>>q;

    vector<vector <int > > Q (q,vector<int >(4));
    for (int i = 0; i < q; ++i) {
        cin>>Q[i][0]>>Q[i][1]>>Q[i][2]>>Q[i][3];
    }
    vector<int>A(n);
    for (int j = 1; j <= m; ++j) {
        search(A,0,n,j,m,Q);
    }

    cout<<ans<<endl;
    return 0;
}
