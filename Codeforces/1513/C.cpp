#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define Endl '\n'
#define cont continue
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define pb push_back
#define mp make_pair
#define mem(x) memset(x, 0, sizeof(x))
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;

const ll inf=1e18;
const int mod=1e9+7;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
const int mxn = 2e5+10;

int Mod(int a) {
	if(a < 0)
		return (a+mod)%mod;
	else return a % mod;
}
int Mul(int a, int b) {
	return Mod(Mod(a) * Mod(b));
}
int Add(int a, int b) {
	return Mod(Mod(a) + Mod(b));
}

/*
//sieve starts here
#define svMX            200005
bitset<svMX>siv;
vector<ll>prime;
 
void sieve () {
    siv[0] = siv[1] = 1; // 0 and 1 are not prime
 
    prime.push_back(2); // Only Even Prime
    for ( int i = 4; i <= svMX; i += 2 ) siv[i] = 1; // Remove multiples of 2
 
    int sqrtn = sqrt ( svMX );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( siv[i] == 0 ) {
            for ( int j = i * i; j <= svMX; j += 2 * i ) siv[j] = 1;
        }
    }
 
    for ( int i = 3; i <= svMX; i += 2 ) if ( siv[i] == 0 ) prime.push_back(i);
}
//sieve ends here
*/

//ll fact[mxn];
//ll in_fact[mxn];
//fact[0] = 1;
//for(ll i = 1; i < mxn; i++) {
	//fact[i] = (i*fact[i-1])%mod;
//}
//in_fact[mxn-1] = bigmod(fact[mxn-1],mod-2);
//for(ll i = mxn-2; i >= 0; i--) {
	//in_fact[i] = (in_fact[i+1] * (i+1))%mod;
//}
//ll c(ll n,ll r) {
	//ll ans = (fact[n] * (in_fact[r] * in_fact[n-r]%mod))%mod;
	//return ans;
//}
//int dp[10][mxn];
//int func(int pos, int op) {
	//if(op == 0) return 1;
	//int &ans = dp[pos][op];
	//if(ans != -1) return ans;
	//if(pos == 9) {
		//ans = func(1,op-1)+func(0,op-1);
		//if(ans > mod) ans -= mod;
	//}
	//else {
		//ans = func(pos+1,op-1);
		//if(ans > mod) ans -= mod;
	//}
	//return ans;
//}
ll dp[mxn][10];
void solve() {
	int m;
	ll ans = 0;
	string s;
	cin>>s>>m;
	for(char c:s) ans = Add(ans,dp[m][c-'0']);
	cout<<ans<<endl;
}
	
signed main(){
    fast;
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
    int tt = 1;
    cin>>tt;
    memset(dp,0,sizeof dp);
    for(int i = 0; i < 10; i++) dp[0][i] = 1;
    for(int i = 1; i <= 200003; i++) {
		for(int j = 0; j < 9; j++) {
			dp[i][j] = dp[i-1][j+1];
		}
		dp[i][9] = (dp[i-1][1] + dp[i-1][0]) % mod;
	}
    for(int tc = 1; tc <= tt; tc++) {
		solve();
        //ll m,ans=0;
        //string n;
        //cin>>n>>m;
        //int len = n.size();
        //for(int i = 0; i < len; i++) {
			//ans = ans+func(n[i]-'0',m);
			//if(ans > mod) ans -= mod;
		//}
		//cout<<ans<<endl;
			
        
        
    }



return 0;
}
