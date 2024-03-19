#include <iostream>
using namespace std;

void next_config (int a[], int k, int i)
{
	a[i] += 1;
	i ++;
	while (i <= k){
		a[i] = a[i-1] + 1;
		i ++;
	}
}
void view_config (int a[], int k)
{
	for (int i = 1; i<=k; i++){
		cout<<a[i];
	}
	cout<<endl;
}
void listing_configs (int k, int n)
{
	int i, a[k+1] = {0};
	for(i=1 ; i <= k; i++){
		a[i] = i;
	}
	do{
		view_config(a, k);
		i = k;
		while (i>0 && a[i] == n - k + i) i--;
		if (i>0) next_config(a, k, i);
	}while (i>0);
}
int main()
{
	int k, n;
	cout<<"k= "; cin>>k;
	cout<<"n= "; cin>>n;
	listing_configs(k, n);
}