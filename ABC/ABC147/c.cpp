#include <bits/stdc++.h>
#include <numeric>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
typedef long long  ll;
using namespace std;
using gragh = vector<vector<int>>;

int bit_count(int i){
    //数字iを二進数表記にした際の1の数を調べる
    if (i==0) return 0;
    return bit_count(i>>1) + (i & 1);
}

int main() {
    int N;
    cin>>N;
    int ans = 0;

    vector<vector<vector<int>>>g(N,vector<vector<int>>(0,vector<int>(2)));

    for (int k = 0; k < N; ++k) {
        //三次元配列に入力を受け取る
        int An;
        cin>>An;
        for (int i = 0; i < An; ++i) {
            int a;
            int b;
            cin>>a>>b;
            //添字を揃えるためにディクリメントする
            a--;
            //1d次元目に配列をpush_backする
            g[k].push_back({a,b});

        }
    }

    for (int bit = 0; bit < (1<<N)  ; ++bit) {
        //bit全探索。(1<<N)は"0001"をN個左方向へシフトするという意味。
        // N＝3の時、"1000"となりの、この数-1、すなわち"0111"までの数字全てを試す事になる。
        bool ok = true;//矛盾があるかどうかのフラグ
        for (int i = 0 ; i < N ; i++) {
            if(bit & (1<<i)){
                //bitが仮に2="0010"だとして、iが0だったら"0010"かつ"0001"なのでfalse、1だったらtrue.
                for(auto xy :g[i]){
                    if(xy[1] == 1){
                        if(!(bit & (1<<xy[0]))){
                            ok = false;//矛盾したらfragを折る
                            break;
                        }
                    }else if(xy[1] == 0){
                        if(bit & (1<<xy[0])){
                            ok = false;//矛盾したらfragを折る
                            break;
                        }
                    }
                }
            }
        if (!(ok)) break;
        }
        if (ok) ans = max(ans,bit_count(bit));
    }

    cout<<ans<<endl;


}
