#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    long long a,b,x,ans;
    cin>>a>>b>>x;
    if (a==0){
        ans =((b/x)+1);
    }
    else{
        ans = ((b/x)+1) - (((a-1)/x)+1);
    }

    cout<<ans<<endl;


}
