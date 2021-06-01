#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k,d;
    cin>>n>>k>>d;
    bool ok = false;
    int tmp = 1;
    for(int i = 0; i < d; i++) {
        tmp *= k;
        if(tmp >= n) {
            ok = true;
            break;
        }
    }
    if(!ok) {
        cout<<-1<<endl;
        return 0;
    }
    int ans[d][n];
    int val = 1,cnt;
    tmp = 1;
    for(int i = 0; i < d; i++) {
        val = 1;
        if(i) tmp *= k;
        cnt = 0;
        for(int j = 0; j < n; j++) {
            ans[i][j] = val;
            cnt++;
            if(cnt >= tmp) {
                val++;
                cnt = 0;
            }
            if(val > k) {
                val %= k;
            }
        }
    }
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < n; j++) cout<<ans[i][j]<<' ';
        cout<<endl;
    }



return 0;
}
