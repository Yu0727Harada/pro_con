
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

int bit_s(int target, vi li){
    int ok = 0;
    int ng = li.size();
    int mid;
    while(ng - ok > 1){
        mid = (ok + ng)/2;
        if(li[mid] > target){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    return ok;
}


int main() {
    int n;
    cin>>n;
    string t;
    cin>>t;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    //vi front_cnt(n,-1);//どこまでのインデックスの文字を含んでいるか
    map<int,int>front_cnt;
    vi back_cnt(n,t.size());//後ろからみて、どこまでのインデックスの文字を含んでいるか
    for (int i = 0; i < n; ++i) {
        int itr = 0;
        for (int j = 0; j < s[i].size(); ++j) {
            if (s[i][j] == t[itr]){
                itr++;
                if(t.size() == itr)break;
            }
        }
        //front_cnt[i] = itr - 1;
        front_cnt[itr - 1]++;
        itr = t.size() - 1;

        for (int j = s[i].size() - 1; j >= 0; --j) {
            if (s[i][j] == t[itr]) {
                itr--;
                if(t.size() == -1)break;
            }
        }
        back_cnt[i] = itr + 1;
    }
    back_cnt.push_back(-1);
    back_cnt.push_back(t.size() + 1);
    sort(all(back_cnt));
    ll ans = 0;
    for (auto item:front_cnt) {
        int cnt = bit_s(item.first + 1,back_cnt);
        if(cnt == 0)cnt = 0;
        else if(cnt == t.size()) cnt = n;
        ans += (ll)cnt * (ll)item.second;
    }
    cout<<ans<<endl;
    return 0;
}
