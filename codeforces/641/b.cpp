//
// Created on 2020/05/12.
//

//
// Created on 2020/05/12.
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

vector<int>size;
int fin_ans;

void search(int index, int ans){
    fin_ans = max(ans,fin_ans);
    for (int i = 2; i * index < size.size(); ++i) {
        if(size[index] < size[index * i]){
            search(index * i, ans+1);
        }
    }
}

int solve(){
    int n;
    cin>>n;
    size.clear();
    size.push_back(-1);
    fin_ans = 0;
    for (int i = 0; i < n; ++i) {
        int s;
        cin>>s;
        size.push_back(s);
    }
    for (int j = 1; j <= n; ++j) {
        int ans = 1;
        search(j,ans);
    }
    cout<<fin_ans<<endl;

}

int main() {
    int t;
    cin>>t;

    while(t){
        solve();
        t--;
    }


    return 0;
}
