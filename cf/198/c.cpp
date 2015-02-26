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

int a[400][2];

bool diffside(int p1,int p2, int ap, int bp ) {
//	((y1−y2)(ax−x1)+(x2−x1)(ay−y1))((y1−y2)(bx−x1)+(x2−x1)(by−y1))<0.
	return ((a[p1][1] - a[p2][1])*(a[ap][0]-a[p1][0])+(a[bp][0]-a[ap][0])*(a[ap][1]-a[p1][1])) *
		((a[p1][1] - a[p2][1])*(a[bp][0]-a[p1][0])+(a[bp][0]-a[ap][0])*(a[bp][1]-a[p1][1])) < 0;
}


double area(int i,int j,int k) { 
	double c = 0.0;
	c += a[i][0]*(a[j][1]-a[k][1]) + a[j][0]*(a[k][1]-a[i][1]) + a[k][0]*(a[i][1]-a[j][1]);
	cout<<fabs((double)c/2.0)<<endl;
	return fabs(c/2.0);
}

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("D:\\MyCode\\Data\\test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
	cin>>n;
	for(int i=0;i<n;i++) 
		cin>>a[i][0]>>a[i][1];
	double maxarea = -1.0,karea;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			if(i!=j) {
				for(int k=0;k<n;k++) {
					if(k!=i && k !=j ) { 
						karea = area(i,j,k);
						for(int l=0;l<n;l++) {
							if(l!=i && l!=j && l!=k) {
								if(diffside(i,j,k,l)) {
									double curr = karea + area(i,j,l);
									maxarea = ( maxarea > curr ) ? maxarea : curr;
								}
							}
						}
					}
				}
			}
		}
	}

	cout<<maxarea;								

	return 0;
}
