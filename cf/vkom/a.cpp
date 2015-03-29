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
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second



int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    double a, b, c, x1, x2, determinant, realPart, imaginaryPart;
    cin >> a >> b >> c; 
    determinant = b*b - 4*a*c;
    if (determinant > 0) { 
        x1 = (-b + sqrt(determinant)) / (2*a); x2 = (-b - sqrt(determinant)) / (2*a) ; 
        cout << min(x1,x2)  << " " << max(x1,x2) << endl;
    } else if (determinant == 0) { 
        x1 = (-b + sqrt(determinant)) / (2*a);
        cout << x1 << endl;
    } else { 
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-determinant)/(2*a);
    }
    return 0;
}

