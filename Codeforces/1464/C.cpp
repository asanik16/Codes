#include<bits/stdc++.h>
using namespace std;
const int mxn = 5e5+10;
bool vis[mxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,cus_no = 1,mx = 0;
    queue<int>mono;
    priority_queue<pair<int,int>>poly;
//    map<int,int>poly;
    cin>>t;
    while(t--) {
        int q;
        cin>>q;
        if(q == 1) {
            int m;
            cin>>m;
            mono.push(cus_no);
            poly.push({m,-1*cus_no});
            cus_no++;
        }
        else if(q == 2) {
            while(vis[mono.front()]) {
                mono.pop();
            }
            cout<<mono.front()<<' ';
            vis[mono.front()] = 1;
        }
        else {
            while(vis[-1*poly.top().second]) {
                poly.pop();
            }
            cout<<-1*poly.top().second<<' ';
            vis[-1*poly.top().second] = 1;
        }

    }



return 0;
}
