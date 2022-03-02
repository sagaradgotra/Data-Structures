# include<iostream>
using namespace std;
int count(int n) {
        int a[n+1];
        
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(n==3){
        	return 4;
		}
        a[1]=1;
        a[2]=2;
        a[3]=4;
        for(int i=4;i<n+1;i++){
            a[i]=a[i-1]+a[i-2]+a[i-3];
        }
        return a[n];
    }
int main(){
	int n;
	cin>>n;
	cout<<count(n)<<endl;
	return 0;
}
