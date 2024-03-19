#include <iostream>
using namespace  std;

void swap(int &a, int &b)
{
	int tg = a;
	a = b;
	b = tg;
}
void view_config ( int a[], int n)
{
	for(int i=1; i<=n; i++){
		cout<<a[i];
	}
	cout<<endl;
}
void next_config (int a[], int n, int i)
{
	int k = n;
	while (a[k] < a[i]){
		k--;
	}
	swap(a[i], a[k]);
	int j = n; i++;
	while (i<j){
		swap(a[i], a[j]); i ++; j--;
	}
}
void listing_configs(int n)
{
	int i, a[n+1] = {0};
	for(i=1; i <= n; i++){
		a[i] = i;
	}
	do{
		view_config(a, n);
		i = n-1;
		while (i >0 && a[i] > a[i+1]) i--;
		if (i>0){
			next_config(a, n, i);
		}
	}while (i>0);
}
int main()
{
	int n;
	cout<<"n= "; cin>>n;
	listing_configs(n);
	return 0;
}