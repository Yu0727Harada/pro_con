#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    long long N;
    cin>>N;
    long long ans=0;
    for (int i = 1 ; i <(N/2+1) ; ++i) {
        if ((i + N-i) == N and i != N-i and i ){
            ans ++;
        }
    }
    cout<<ans<<endl;

}
