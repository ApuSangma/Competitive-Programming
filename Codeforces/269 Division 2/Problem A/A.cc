#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int li;
map<int, int> l;

int main(){
	for(int i = 0; i < 6; i++){
		sd(li);
		l[li]++;
	}
	if(l.size() > 3){
		puts("Alien");
	}
	if(l.size() == 3){
		bool ok = false;
		foreach(it, l){
			if(it->se == 4) ok = true;
		}
		if(ok) puts("Bear");
		else puts("Alien");
	}
	if(l.size() == 1){
		puts("Elephant");
	}
	if(l.size() == 2){
		bool ok = true;
		foreach(it, l){
			if(it->se != 4 and it->se != 2) ok = false;
		}
		if(ok) puts("Elephant");
		else{
			ok = true;
			foreach(it, l){
				if(it->se != 5 and it->se != 1) ok = false;
			}
			if(ok) puts("Bear");
			else puts("Alien");
		}	
	}
	return 0;
}
