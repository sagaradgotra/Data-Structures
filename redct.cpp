# include <iostream>
# include <stack>
using namespace std;
int main(){
	string s;
	cin>>s;
	int g=0;
	stack<char>stk;
	int p;
	p=s.size();
	int i=0;
	while(i<p){
		if(s[i]!=')'){
			stk.push(s[i]);
			i++;
		}
		else{
			int c=0;
			int j=0;
			while(stk.top()!='('){
				stk.pop();
				
				c++;
				
				j++;
				
				
			}
			if (stk.top()=='(' ){
				if (c==0){
					cout<<"true"<<endl;
					g=1;
					
					break;
				}
				
				stk.pop();
				i++;
			}
			
		}
	}
	
	
	if(g==0){
		cout<<"false"<<endl;}
	
	return 0;
	
}
