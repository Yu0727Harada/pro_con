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


int main() {

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>ans;
    if(n % 2 == 1){
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back({i,(n+1)-i});
        }
        for (int j = 0; j < m; ++j) {
            cout<<ans[j].first<<" "<<ans[j].second<<endl;
        }
    }else{
        int r,l;
        r = 1;
        l = n -1;
        bool frag = false;
        while(r < l){
            if(l-r <= n / 2 && !frag){
                r ++;
                frag = true;
                continue;
            }
            ans.push_back({r,l});
            r++;
            l--;
        }

        for (int j = 0; j < m; ++j) {
            cout<<ans[j].first<<" "<<ans[j].second<<endl;
        }
    }

    return 0;
}

/*
 *
rotation matching
 あなたは「AtCoderじゃんけん」という一対一のゲームの大会を主催することになりました。 大会の参加者はN人で、それぞれには1からN の相異なる番号が割り振られています。 アリーナには二人が入ることのできる対戦場がM 個用意されており、あなたはそれぞれの対戦場に二つの相異なる
1 以上N 以下の整数を割り当てなければいけません。 複数の対戦場に同じ整数を割り当てることはできません。
 大会はN ラウンドによって構成され、それぞれのラウンドは以下のようにして取り行われます。

それぞれの参加者は、自分の番号が割り当てられた対戦場が存在するならそこに行き、そこに来たもう一方の相手と対戦する。
その後、それぞれの参加者が、自分の番号に1 を足す。もし1 を足した後の番号がN+1 であるなら、その値を1 に変更する。
N 回のラウンドを通じて、二回以上同じ参加者と対戦するような参加者が存在しないようにしたいです。 このような条件を満たす対戦場への整数の割り当てをひとつ出力してください。 ただし、与えられる制約のもとでそのような割り当てが必ず存在することが示せます。

 * */