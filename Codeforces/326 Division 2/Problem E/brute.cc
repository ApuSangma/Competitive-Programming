#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

const int N = 100100;

int n, m, q;
vector<int> g[N];
vector<int> people[N];
set<int> s;

bool dfs(int cur, int prev, int to){
	if(cur == to){
		foreach(it, people[cur]){
			s.insert(*it);
		}
		return true;
	}
	
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		if(dfs(*it, cur, to)){
			foreach(it, people[cur]){
				s.insert(*it);
			}
			return true;
		}
	}
	return false;
}

int main(){
	sd3(n,m,q);
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for(int i = 1; i <= m; i++){
		int c; sd(c);
		people[c].pb(i);	
	}
	
	while(q--){
		int u, v, a; sd3(u,v,a);
		s.clear();
		dfs(u,-1,v);
		
		a = min(a, (int)s.size());
		cout << a << " ";
		set<int>::iterator it = s.begin();
		while(a--){
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}	
		
	return 0;
}
