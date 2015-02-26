#include <iostream>
#include <cmath>
using namespace std;
int n;
int main(){
    freopen("test.in","r",stdin);
    cin >> n;
    double sum = -n;
    int fc = 0;
    for (int i = 1; i <= 2 * n; i++){
        double a;
        cin >> a;
        int ai = a;
        if (a - ai == 0)
        fc++;
        sum += a - ai;
    }
    cout<<sum<<endl;
    cout<<fc<<endl;
    double ans = 1000000000;
    for (int i = 0; i <= fc; i++) {
        cout<<"ans "<<ans<<endl;
        cout<<"sum+i "<<sum+i<<endl;
        ans = min(abs(sum + i), ans);
    }
    cout.precision(3);
    cout << fixed << ans << endl;
}
