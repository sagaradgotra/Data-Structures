#include<bits/stdc++.h>
using namespace std;

template <typename T>
class stack1{
	T *data;
	int nextindex;
	int capacity;
	
	
	public:
		 stack1(){
		 	data=new T[4];
		 	nextindex=0;
		 	capacity=4;
			
		}
		void push(T element){
			if(nextindex==capacity){
				T *data1=new T[2*capacity];
				for(int i=0;i<capacity;i++){
					data1[i]=data[i];
				}
				data1[nextindex]=element;
				capacity=2*capacity;
				nextindex++;
				
				delete [] data;
				data=data1;
				return;
			}
			else{
				data[nextindex]=element;
				nextindex++;
				return;
			}
			
			
			
		}
		
		int pop(){
			if (nextindex==0){
				
				return 0;
			}
			else{
				T p=data[nextindex-1];
				nextindex--;
				return p;
				
			}
		}
		int top(){
			if (nextindex==0){
				return 0;
				
			}
			else{
				return data[nextindex-1];
			}
		}
		
		
		int size(){
			return nextindex;
		}
		
		bool empty(){
			if (nextindex==0){
				return true;
			}
			else{
				return false;
			}
		}
};

void infixToPostfix(string s){

		string ans;
        stack1<char> st;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='(') {
                st.push(s[i]);
                continue;
            }
            if(s[i]==')'){
                while(!st.empty()&&st.top()!='('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
                continue;
            }
            if(s[i]>='A'&&s[i]<='Z'){
                ans += s[i];
                continue;
            }
            else{
                if(st.empty()){
                    st.push(s[i]);
                    continue;
                }
                if(s[i]=='+'||s[i]=='-'){
                    while(!st.empty()&&(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/'||st.top()=='^')){
                        ans+= st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                else if(s[i]=='*'||s[i]=='/'){
                    while(!st.empty()&&(st.top()=='*'||st.top()=='/'||st.top()=='^')){
                        ans+= st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                else{
                    while(!st.empty()&&st.top()=='^'){
                        ans+= st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                    
                }
            }
            
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        cout<<"Postfix expression:"<<ans<<'\n';
    
    return ;
}


int main(){
	string s;
	cout<<"Enter your Infix expression:"<<endl;
	cin>>s;
	infixToPostfix(s);
	int a;
	cout<<"Do you want to continue:"<<endl;
	cin>>a;
	while(a!=-1){
		string s1;
		cout<<"Enter your Infix expression:"<<endl;
		cin>>s1;
		infixToPostfix(s1);
		cout<<"Do you want to continue:"<<endl;
		cin>>a;
	}
		
    return 0;
}
