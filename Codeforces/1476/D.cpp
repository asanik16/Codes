//Bismillahir-Rahmanir-Rahim
//Atik Shahriar Anik
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
const int mxn = 3e5+10;

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
int n,i,j,k;
string s;
int vis[mxn];
vector<int> func(int f) {
	memset(vis,0,sizeof vis);
	if(f == 1) {
		reverse(s.begin(),s.end());
		for(i = 0; i < n; i++) {
			if(s[i] == 'R') s[i] = 'L';
			else s[i] = 'R';
		}
	}
	vector<int>tmp(n+1);
	tmp[n] = 0;
	for(i = 0; i < n; i++) {
		if(s[i] == 'R') {
			if(vis[i]) {
				tmp[i] = tmp[i-2]-2;
			}
			else {
				int c = 1;
				vis[i] = 1;
				for(j = i+1; j < n; j++) {
					if(c%2 && s[j] != 'L') break;
					if(c%2==0 && s[j] != 'R') break;
					c++;
					vis[j] = 1;
				}
				tmp[i] = c;
			}
		}
		else tmp[i] = 0;
	}
	
	
	return tmp;
}
void solve() {
	cin>>n>>s;
	vector<int>R(n+1),L(n+1);
	R = func(0);
	L = func(1);
	reverse(L.begin(), L.end());
	for(i = 0; i < n+1; i++) cout<<R[i] + L[i] + 1<<' ';
	cout<<endl;
	
}

signed main(){
    fast;
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
    int tt = 1;
    cin>>tt;
    for(int tc = 1; tc <= tt; tc++) {
        solve();
			
        
        
    }



return 0;
}
