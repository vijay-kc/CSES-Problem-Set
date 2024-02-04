#include<bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n, int source, int destination, int auxilary){ 
	if (n == 1) 
	{ 
		cout<<source<<" "<<destination<<endl; 
		return; 
	} 
	towerOfHanoi(n - 1, source, auxilary, destination);
	cout<<source<<" "<<destination<<endl; 
	towerOfHanoi(n - 1, auxilary, destination, source); 
} 
int main (){
	int n; cin>>n;
    cout<<((1<<n) -1)<<endl;
	towerOfHanoi(n, 1, 3, 2);
 
	return 0;
}