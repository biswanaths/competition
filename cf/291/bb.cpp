#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <utility>

#include <cmath>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef pair<int, long long> PILL;
typedef vector<int> VI;
typedef vector<PII > VP;

#define EPS 10e-20

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);

#define MAX_SIZE 50+10


int n, x_0, y_0;

set<double> slopes;

int main()
{
    //IN

    int i, j, x, y; 

    // while(cin >> n >> x_0 >> y_0) {
    while(scanf("%d%d%d", &n, &x_0, &y_0) == 3) {
        
        slopes.clear();

        int count = 0;

        FORN(i, n) {
            scanf("%d %d", &x, &y);
            // cin >> x >> y;

            double slope = 0.0;

            if(x == x_0) {
                slope = 10e9;
            } else {
                slope = ((double)(y - y_0)) / ((double) (x - x_0)); 
            }

            slopes.insert(slope);
        }

        cout << slopes.size() << endl;
    }

    return 0;
}



