//
// Created on 2020/05/30.
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
    string s;
    cin>>s;

    bool ok = false;
    int ans = 0;
    int cnt = 0;
    vector<char>atgt = {'A','C','G','T'};
    for (int i = 0; i < s.size(); ++i) {
        bool find = false;
        for (auto c : atgt) {
            if(s[i] == c && ok){
                cnt ++;
                ans = max(ans,cnt);
                find = true;
                break;
            }else if(s[i] == c && !ok){
                ok = true;
                cnt ++;
                ans = max(ans, cnt);
                find = true;
                break;
            }
        }
        if(!find && ok){
            ok = false;
            cnt = 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
