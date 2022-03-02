#include <iostream>
#define li long long int
using namespace std;

li linearSearch(li *arr, li n, li x)
{
	for (li i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

signed main(){
	li n,val;
	cin >> n;
	li *arr = new li[n];
	for (li i = 0; i < n; i++){
		cin >> arr[i];
	}
	cin >> val;
	cout << linearSearch(arr, n, val) << endl;
	return 0;
}