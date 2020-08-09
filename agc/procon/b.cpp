#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<int>D(N+1,0);
    for (int i = 1; i <= N; ++i) {
        cin>>D[i];
    }
    vector<int>answer(N+1,0);
    
    if(D[1]!=0){
        cout<<0<<endl;
        return 0;
    }
    answer[0]=1;
    long long ans=1;
    sort(D.begin(),D.end());
    for (int k = 2; k <= N; ++k) {
        ans *= answer[D[k]-1];
        ans = ans%998244353;
        answer[D[k]]++;
    }

    cout<<ans<<endl;
}
