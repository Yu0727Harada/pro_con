//
// Created on 2020/07/04.
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

int ans = 0;
int m,n;

void walk(vector<vector <bool> >map, int cnt, int x, int y,vector<pair<int,int>> move){
    map[x][y] = false;
    ans = max(ans,cnt);
    for (int i = 0; i < move.size(); ++i) {
        int m_x = move[i].first;
        int m_y = move[i].second;
        if(0 <= m_x + x && m_x + x < n && 0 <= m_y + y && m_y + y < m){
            if(map[m_x + x][m_y + y]){
                walk(map,cnt + 1, m_x + x, m_y + y, move);
            }
        }
    }

}

int main() {
    cin>>m>>n;
    vector<vector<bool>>lake(n,vector<bool>(m));
    vector<pair<int,int>>move = {
            {1,0},{0,1},{-1,0},{0,-1}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool t;
            cin>>t;
            lake[i][j] = t;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < m; ++i) {
            walk(lake,0,k,i,move);
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*D - 薄氷渡り
 * 冬の寒いある日，JOI太郎君は広場にはった薄氷を割って遊ぶことにした． 広場は長方形で， 東西方向に
m
 個， 南北方向に
n
 個， つまり，
m
×
n
 の区画に区切られている． また， 薄氷が有る区画と無い区画がある． JOI太郎君は，次のルールにしたがって，薄氷を割りながら区画を移動す ることにした．

薄氷があるどの区画からも薄氷を割り始めることができる．
東西南北のいずれかの方向に隣接し， まだ割られていない薄氷のある区画に移動できる．
移動した先の区画の薄氷をかならず割る．
JOI太郎君が薄氷を割りながら移動できる区画数の最大値を求めるプログラムを作成せよ． ただし，
1
≤
m
≤
90
 ，
1
≤
n
≤
90
 である． 与えられる入力データでは， 移動方法は
20
 万通りを超えない．
 深さ優先探索（再帰関数でとく）やるだけ
*/
