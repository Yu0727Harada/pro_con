#include <bits/stdc++.h>
#include <numeric>

using namespace std;
#define all(x) (x).begin(),(x).end()

using gragh = vector<vector<int>>;

vector<int> color;//二部グラフの色を保管 -1 = not seen
//頂点vからみて二部グラフならtrueを返す
//調べるグラフ、調べる頂点、最初の色（一番初めはなくて良い）
bool dfs(const gragh &edge_gragh,int v,int cur=0){
    color[v] = cur;
    for(auto next_v:edge_gragh[v]){
        if (color[next_v]!=-1){
            if(color[next_v]==cur) {
                return false;
            }
            continue;
        }
        if(!dfs(edge_gragh,next_v,1-cur)) return false;
    }
    return true;
}
//nは頂点数、グラフの全ての頂点に対して調べる
bool is_bipartite(int n, const gragh &edge_gragh){
    color.assign(n,-1);
    for(int v=0;v<n;++v){
        if(color[v]!= -1) continue;
        if(!dfs(edge_gragh,v)){
            return false;
        }
    }
    return true;
}
const int MAX = 510000;//nCkのn,kの取りうるMAX
const int MOD = 1000000007;

long long fac[MAX],finv[MAX],inv[MAX];

//階乗のテーブルを作る
void COM_initialize(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2 ; i < MAX ; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD -inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

//二項係数計算,nCkのn,kを引数として渡す
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD)% MOD;
}

int main() {

    int N;
    int M;
    cin>>N>>M;

    gragh edge_gragh(N);
    for (int i = 0; i < M; ++i) {
        int A,B;
        cin>>A>>B;
        A--;
        B--;
        edge_gragh[A].push_back(B);
        edge_gragh[B].push_back(A);
    }

    bool bipartite = is_bipartite(N,edge_gragh);

    if (bipartite){
        long long sum = accumulate(all(color),0LL);
        long long ans =sum * ((long long)N-sum) - (long long)M;
        cout<<ans<<endl;
    }else{
        long long ans =(((long long)N * ((long long)N - 1)) / 2) - (long long)M;
        cout << ans << endl;
    }
}