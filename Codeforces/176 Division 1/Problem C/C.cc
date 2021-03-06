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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

const int N = 1001000;

int n, t, p[N], q[N];
int s[N], tp;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(p[i]);
	}
	
	sd(t);
	for(int i = 0; i < t; i++){
		sd(q[i]);
		p[q[i]-1] *= -1;
	}
	
	reverse(p, p+n);
	for(int i = 0; i < n; i++){
		if(p[i] < 0){
			s[tp++] = -p[i];
		}
		else{
			if(tp == 0){
				s[tp++] = p[i];
				p[i] *= -1;
			}
			else if(s[tp-1] != p[i]){
				s[tp++] = p[i];
				p[i] *= -1;
			}
			else tp -= 1;
		}
	}
	
	if(tp > 0){
		puts("NO"); return 0;
	}
	
	reverse(p, p+n);
	puts("YES");
	for(int i = 0; i < n; i++){
		printf("%d ", p[i]);
	}
	puts("");
	
	return 0;
}
