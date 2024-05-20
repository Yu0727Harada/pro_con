
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


struct crane{
public:
    int position_i;
    int position_j;
    bool big;
    int has_container;//-1 ->no
    string action_s;
    bool destroy;
};

int main() {
    int n;
    cin>>n;
    int ok = 0;
    vvi container_array(n,vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>container_array[i][j];
        }
    }
    vi itr_container(n,0);//今置かれているコンテナ

    vector<crane>cranes(n);
    for (int i = 0; i < n; ++i) {
        cranes[i].position_i = i;
        cranes[i].position_j = 0;
        if(i == 0)cranes[i].big = true;
        else cranes[i].big = false;
        cranes[i].has_container = -1;
        cranes[i].action_s = "";
        cranes[i].destroy = false;
    }

    while(ok != 31) {
        for (int i = 0; i < n; ++i) {
            if (cranes[i].destroy)continue;

            if (cranes[i].has_container >= 0) {
                //すでにコンテナをもっている
                if (cranes[i].position_j == n - 1) {
                    //みぎ端にたどり着いたら荷物を離す
                    cranes[i].action_s += 'Q';
                    cranes[i].has_container = -1;
                    if (itr_container[i] == n) {
                        //もうすべての荷物を運び終えたなら
                        cranes[i].action_s += 'B';
                        cranes[i].destroy = true;
                        ok |= (1<<i);
                    }
                } else {
                    //みぎ端じゃないなら右にいどう
                    cranes[i].action_s += 'R';
                    cranes[i].position_j++;
                }
            } else {
                //コンテナを持っていないなら
                if (cranes[i].position_j == 0) {
                    //左端にいるとき
                    int target_i = cranes[i].position_i;
                    if (itr_container[target_i] < n) {
                        //まだ全ての荷物を運び出してないなら荷物をもつ
                        cranes[i].action_s += 'P';
                        cranes[i].has_container = container_array[target_i][itr_container[target_i]];
                        itr_container[target_i]++;
                    } else {
                        //運び終えているならもうクレーンはいらない
                        cranes[i].action_s += 'B';
                        cranes[i].destroy = true;
                        ok |= (1<<i);
                    }
                } else {
                    //左端じゃないなら左に移動
                    cranes[i].action_s += 'L';
                    cranes[i].position_j--;
                }
            }

        }
    }
    for (int i = 0; i < n; ++i) {
        cout<<cranes[i].action_s<<endl;
    }

    return 0;
}
