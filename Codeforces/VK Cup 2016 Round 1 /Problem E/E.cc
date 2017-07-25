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
ostream& operator<<(ostream& out,pair<S,T> const& prnt){out<<'('<<prnt.fi<<", "<<prnt.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int LOGN = 19;
const int N = 300100;

int n, m, q;

int dtime;

vector<pii> g[N];
int low1[N], disc1[N];
int bic1[N], bno1;

vector<int> bgraph[N];

int biccomp[N], biccompno;
int l[N], r[N];

int prnt[LOGN][1 << LOGN], dpth[1 << LOGN];

vector<pii> compressedForest[N];
int f[N];
int low2[N], disc2[N];
int bic2[N], bno2;

stack<int> st;
void dfs1(int u, int edge){
	low1[u] = disc1[u] = ++dtime;
	
	st.push(u);
	foreach(it, g[u]){
		int v = it->fi, e = it->se;
		if(e == edge) continue;
		
		if(disc1[v]) low1[u] = min(low1[u], disc1[v]);
		else{
			dfs1(v, e);
			low1[u] = min(low1[u], low1[v]);
		}
	}
	
	if(disc1[u] == low1[u]){
		bic1[u] = ++bno1;
		while(st.top() != u){
			bic1[st.top()] = bno1; st.pop();
		}
		st.pop();
	}
}

void dfs2(int cur, int prev){
	l[cur] = ++dtime;
	prnt[0][cur] = prev;
	biccomp[cur] = biccompno;
	
	foreach(it, bgraph[cur]){
		if(*it == prev) continue;
		dpth[*it] = dpth[cur] + 1;
		dfs2(*it, cur);
	}
	
	r[cur] = ++dtime;
}

void dfs3(int u, int edge){
	low2[u] = disc2[u] = ++dtime;
	
	st.push(u);
	foreach(it, compressedForest[u]){
		int v = it->fi, e = it->se;
		if(e == edge) continue;
		
		if(disc2[v]) low2[u] = min(low2[u], disc2[v]);
		else{
			dfs3(v, e);
			low2[u] = min(low2[u], low2[v]);
		}
	}
	
	if(disc2[u] == low2[u]){
		bic2[u] = ++bno2;
		while(st.top() != u){
			bic2[st.top()] = bno2; st.pop();
		}
		st.pop();
	}
}

void buildJumpTable(){
	for(int j = 1; j < LOGN; j++)
		for(int i = 1; i <= n; i++)
			prnt[j][i] = prnt[j-1][prnt[j-1][i]];
}

int LCA(int x, int y){
	if(dpth[x] < dpth[y]) swap(x,y);
	
	int tmp = 1;
	while((1 << tmp) <= dpth[x]) tmp++;
	tmp--;
	
	for(int i = tmp; i >= 0; i--) 
		if(dpth[x] - (1 << i) >= dpth[y]) x = prnt[i][x];
	
	if(x == y) return y;
	
	for(int i = tmp; i >= 0; i--)
		if(prnt[i][x] > 0 and prnt[i][x] != prnt[i][y]) x = prnt[i][x], y = prnt[i][y];

	return prnt[0][x];
}

void rotate(int &x, int &r){
	x = (x + r) % n;
	if(x == 0) x = n;
}

bool comp(const int &x, const int &y){
	return l[x] < l[y];
}

int main(){
	sd3(n,m,q);
	
	int u, v;
	for(int i = 1; i <= m; i++){
		sd2(u,v);
		g[u].pb(mp(v,i));
		g[v].pb(mp(u,i));
	}

	for(int i = 1; i <= n; i++) if(!disc1[i]) dfs1(i, 0);
	
	for(int i = 1; i <= n; i++){
		foreach(it, g[i]){
			if(bic1[i] != bic1[it->fi]) bgraph[bic1[i]].pb(bic1[it->fi]);
		}
	}
	
	dtime = 0;
	for(int i = 1; i <= bno1; i++){
		if(!l[i]){
			biccompno++;
			dfs2(i, i);
		}
	}

	buildJumpTable();
	
	int R = 0;
	for(int qr = 1; qr <= q; qr++){
		int ni, mi; sd2(ni, mi);
		vector<pii> edges;
		vector<int> nodes, subset;
		
		for(int i = 1; i <= ni; i++){
			sd(u);
			rotate(u, R);
			nodes.pb(bic1[u]);
			subset.pb(bic1[u]);
		}
		
		for(int i = 1; i <= mi; i++){
			sd2(u,v);
			rotate(u, R); u = bic1[u];
			rotate(v, R); v = bic1[v];
			edges.pb(mp(u,v));
			nodes.pb(u); nodes.pb(v);
		}

		sort(nodes.begin(), nodes.end(), comp);
		
		int nsz = nodes.size();
		for(int i = nsz-1; i > 0; i--){
			int x = nodes[i], y = nodes[i-1];
			if(biccomp[x] == biccomp[y]) nodes.pb(LCA(x, y));
		}
		
		sort(nodes.begin(), nodes.end(), comp);
		nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
		
		nsz = nodes.size();
		
		for(int i = 0; i < nsz; i++) f[nodes[i]] = i + 1;
		
		for(int i = 1; i <= nsz; i++){
			compressedForest[i].clear();
			low2[i] = disc2[i] = 0;
			bic2[i] = 0;
		}
		
		int edgenumber = 0;
		st.push(nodes[0]);
		for(int i = 1; i < nsz; i++){
			while(!st.empty() and r[nodes[i]] > r[st.top()]) st.pop();
			if(!st.empty()){
				edgenumber++;
				compressedForest[f[st.top()]].pb(mp(f[nodes[i]], edgenumber));
				compressedForest[f[nodes[i]]].pb(mp(f[st.top()], edgenumber));
			}
			st.push(nodes[i]);
		}
		
		for(int i = 0; i < mi; i++){
			int x = f[edges[i].fi], y = f[edges[i].se];
			edgenumber++;
			compressedForest[x].pb(mp(y, edgenumber));
			compressedForest[y].pb(mp(x, edgenumber));
		}
		
		while(!st.empty()) st.pop();
		
		bno2 = 0, dtime = 0;
		for(int i = 1; i <= nsz; i++) if(!low2[i]) dfs3(i, 0);
		
		bool ok = true;
		for(int i = 1; i < ni; i++){
			if(bic2[f[subset[i]]] != bic2[f[subset[i-1]]]){
				ok = false;
				break;
			}
		}
				
		if(ok){
			printf("YES\n");
			R = (R + qr) % n;
		}
		else printf("NO\n");
	}
		
	return 0;
}
