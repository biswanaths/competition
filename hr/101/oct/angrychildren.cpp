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
int a[100000];

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("D:\MyCodkke\Data\test.out", "w",stdout);
#endif
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int mindiff = a[n-1] + 10;
    for(int i=0;i<n-k;i++) {
        mindiff = mindiff > ( a[i+k-1]-a[i]) ? a[i+k-1]-a[i] : mindiff;
    }

    cout<<mindiff;
    
	return 0;
}
