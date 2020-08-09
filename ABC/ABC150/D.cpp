//
// Created on 2020/01/10.
//

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

int main() {
    int N;
    cin>>N;
    int M;
    cin>>M;
    vector<int>A(N);
    for (int i = 0; i < N; ++i) {
        cin>>A[i];
    }
    sort(all(A));
    A.erase( unique(A.begin(), A.end()), A.end() );
    //A.erase(std::unique(A.begin(),A.begin()),A.end());
    ll X =1;
    for(int j : A){
        X *= j/2;
    }
    ll ans = 0;
    ll a =0;
    ll b =0;
    for (int k = 1; X*k <= M; ++k) {
       ll temp = X*k;

       int frag = 0;//0=ok 1=ng
       int max = *max_element(all(A));
       if(temp < max) continue;
       for (int i : A) {
            if (0 != (temp - i/2)%i){
                frag = 1;
                break;
            }
        }
        if (frag == 0){
            if (a == 0){
                a = temp;
            }
            else{
                b = temp;
                break;
            }

        }
    }
    if (a==0 && b==0) {
        cout<<0<<endl;
        return 0;
    }

    ans = ((M)-(a)) / abs(b-a);
    ans++;
    if((M-a)%abs(b-a) == 0)ans++;


    cout<<ans<<endl;
}
