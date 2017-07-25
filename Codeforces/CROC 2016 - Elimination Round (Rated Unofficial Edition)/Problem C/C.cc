#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 200100;

string s;
int n, k;
int cnt[N];

bool f(int x){
	for(int i = x; i <= n; i++){
		if(s[i-1] == '1') continue;
		int a = max(i - x - 1,  0);
		int b = min(n, i + x);
		if(cnt[b] - cnt[a] >= k+1) return true;
	}
	return false;
}

int main(){ _
	cin >> n >> k;
	cin >> s;
	
	for(int i = 1; i <= n; i++){
		cnt[i] = cnt[i-1] + (s[i-1] == '0');
	}
	
	int lo = 0, hi = n, mid;
	while(lo + 1 < hi){
		mid = (lo + hi) >> 1;
		if(f(mid)) hi = mid;
		else lo = mid;
	}
	
	cout << hi << endl;
	
	return 0;
}
