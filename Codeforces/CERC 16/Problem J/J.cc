#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const int N = 300300;

int n, d;
int m;

int a[N];

map<pair<pii, int>, ll> offers;
map<pair<pii, int>, int> cnt;

map<pii, vector<int> > ans;

int main(){ _
	cin >> n >> d;
	
	for(int i = 0; i < d; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i < d; i++){
		int x = a[i-1], y = a[i];
		if(x > y) swap(x,y);
		
		ans[mp(x,y)].pb(a[i-1]);
		ans[mp(x,y)].pb(a[i]);
	}
	
	foreach(it, ans){
		vector<int> v = it->se;
		vector<int> u;
		
		u.pb(v[0]);
		for(int j = 1; j < v.size(); j++){
			if(v[0] != 
		}
	}
	
	cin >> m;
	
	for(int i = 0; i < m; i++){
		int x, y;
		ll c;
		char t;
		
		cin >> x >> y >> t >> c;
		
		int id = (t == 'O')? 1 : 2;
		
		offers[mp(mp(x,y),id)] = min(offers[mp(mp(x,y),id)], c);
	}
		
		
	return 0;
}
