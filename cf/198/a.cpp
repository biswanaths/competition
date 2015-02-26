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

int gcd(int a,int b) { 
	int lcm = 1;
	for(int i=2;i<1003 && a > 1 && b>1;i++) {
		while( a % i == 0 && b % i == 0 ) 
			lcm *= i, a/=i,b/=i; 
	}
	lcm *= ( a* b);
	return lcm;
}


int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("D:\\MyCode\\Data\\test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
	int a,b,x,y; 
	cin>>a>>b>>x>>y;

	int g = gcd(a,b); 
	int min,max;
	if( x%g==0) 
		min = x/g;
	else 	
		min = x/g + 1; 

	if( y % g==0) 
		max = y/g; 
	else 
		max = y/g ; 
	
	cout<< max - min + 1;
	
	return 0;
}