#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define lld long long int 
#define EOL '\0'
#define PEL cout<<endl;
#define N 100002
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)	
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repi(n) for(int i =0;(i)<(int)(n);(i)++)
#define repj(n) for(int j =0;(j)<(int)(n);(j)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)
#define rep1n(n) for(int i=1;i<(int )(n);i++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define PB push_back
#define ST first
#define ND second

int m; int n ;
int result[1001];
string s;
int dfs(int prev,int diff,int depth) {
	if(depth==m) 
		return 1;
	for(int i=0;i<10;i++) {
		if(s[i]=='1' && diff < i+1 && i+1 != prev) { 
			result[depth]=i+1;
			int f = dfs(i+1,i+1-diff,depth+1);
			if(f==1) return 1;
		}
	}
	return 0;
} 


int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("D:\\MyCode\\Data\\test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
	
	cin>>s;
	cin>>m;
	int f = dfs(0,0,0);
	if( f==1) {
		cout<<"YES\n";
		for(int i=0;i<m;i++)
			cout<<result[i]<<" ";
	}
	else cout<<"NO";
	return 0;
}