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


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

int n; int k ; 
int a[100002],s[100002];

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("D:\MyCodkke\Data\test.out", "w",stdout);
#endif
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    s[0]=a[0];
    for(int i=1;i<n;i++) s[i]=s[i-1]+a[i];
    int m = (k+1)/2;
    int mins = s[n-1]+10;
    for(int i=0;i+k<n;i++) { 
        int ns = s[m+i]-s[i]+a[i];
        int ps = s[i+k] - s[m+i];
        int alls = -ns + ps ; 
        mins = min(alls,mins);
    }
    cout<<mins;
	return 0;
}
