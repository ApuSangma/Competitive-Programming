#include<bits/stdc++.h>
using namespace std;
int a, b;
long long f;
map<int, int> x, y;
map<pair<int, int>, int> r;
int main(){
	scanf("%d", &a);
	for(;~scanf("%d%d",&a, &b);) f += x[a]++ + y[b]++ - r[make_pair(a,b)]++;
	cout << f;
	exit(0);
}
