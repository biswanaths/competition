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


int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("D:\\MyCode\\Data\\test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
	cin>>n>>m;
	map<int,int> o4;
	int  nn = (int )pow(2.0,n);
	int total = 0 ; 
	for(int i=0;i<nn;i++) {
		int k; cin>>k;
		if( i ==0 ) {total = total ^ k; o4[i+1]=k; }
		if( i == nn - 1) {total = total ^ k ; o4[i+1]=k; }
		if( i == 1 && n > 1 ) {total = total ^ k ; o4[i+1]=k; } 
		if( i == nn -2 && n > 1 ) {total = total ^ k ; o4[i+1]=k;}  
	} 
	cout<<nn; cout<<total;

	for(int i=0;i<m;i++) { 
		int p,q; 
		cin>>p>>q; 
		if(p== 1 || ( p==2 && n>1) || p == n || ( p==n-1 && n >1 )) {
			total = total ^ o4[p]; 
			total = total ^ q;
			cout<<total<<endl;
		}
		else {
			cout<<total<<endl;
		}
	}

	return 0;
}