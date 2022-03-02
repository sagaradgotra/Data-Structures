# include <iostream>
# include <stack>
using namespace std;

void reversestack(stack<int> s1,stack<int> s2){
		if(s1.size()==1){
			return;
		}
		else{
		
		
		int x;
		x=s1.top();
		s1.pop();
		int f=0;
		while(!s1.empty()){
			int p;
			p=s1.top();
			s2.push(p);
			s1.pop();
			f++;
			
		}
		int h=0;
		while(!s2.empty()){
			int p;
			p=s2.top();
			s1.push(p);
			s2.pop();
			h++;
			
		}
		s1.push(x);
		
		return reversestack(s1,s2);
	}
	}
	
int main(){
	stack<int> s1;
	stack<int> s2;
	int s;
	for(int i=0;i<s;i++){
		int r;
		cin>>r;
		s1.push(r);
	}
	
	reversestack(s1,s2);
	for(int j=0;j<s;j++){
		cout<<s1.top()<<endl;
		s1.pop();
	}
	
	
	
	
	return 0;
}
