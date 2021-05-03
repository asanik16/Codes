#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int n = s.size(),ansx = 0, ansy = 0;
        int x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'R') x++;
            else if(s[i] == 'L') x--;
            else if(s[i] == 'U') y++;
            else y--;
            int tx = 0, ty = 0;
            for(int j = 0; j < n; j++) {
                if(s[j] == 'R') {
                    tx++;
                    if(tx == x && ty == y) tx--;
                }
                else if(s[j] == 'L') {
                    tx--;
                    if(tx == x && ty == y) tx++;
                }
                else if(s[j] == 'U') {
                    ty++;
                    if(tx == x && ty == y) ty--;
                }
                else {
                    ty--;
                    if(tx == x && ty == y) ty++;
                }
            }
            if(tx == 0 && ty == 0) {
                ansx = x;
                ansy = y;
                break;
            }
        }
        cout<<ansx<<' '<<ansy<<endl;

    }
    return 0;
}
