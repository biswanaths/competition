#include <iostream>

using namespace std;

int main() {
	int t, lin = 0;
     freopen("test.in", "r",stdin);
	cin >> t;
	long arr[t];
	long Li, v, l, r;
	for (int i = 0 ; i < t ; i++) {
		cin >> Li >> v >> l >> r;
		arr[i] = Li/v - ((r / v) - ((l-1) / v));	
	}
	
	for (int i = 0 ; i < t ; i++) {
		cout << arr[i] << endl;
	}
	
	return 0;
}
