#include <iostream>
#include <stack>
using namespace std;
string getstring(char x)
{
    
    string s(1, x);
 
    return s;  
}

int main(){
	int  t;
	cin>>t;
	for(int j=0;j<t;j++){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    stack<char>st;
	    stack<string>st2;
	    string a;
	    for(int i=0;i<n;i++){
	        if (s[i]== '(' or s[i]== ')' or s[i]== '+' or s[i]== '-' or s[i]== '*' or s[i]== '/' or s[i]== '^'){
	            if (s[i]==')'){
	                while(st.top()!='('){
	                    char q=st.top();
	                    string b=getstring(q);
	                    a=a+b;
	                    st.pop();
	                    st2.pop();
	                    st2.push(a);
	                    
	                }
	                st.pop();
	            }
	            
	            else{
	            	if (st.empty()!=true){
					
	                	if(st.top()<=s[i]){
	                		if(s[i]=='('){
	                			st.push(s[i]);
						}
							else{
						
	                    		st.push(s[i]);
	                }
	                }
	                	else{
	                		if(s[i]=='('){
	                			st.push(s[i]);
						}
							else{
						
	                    		while(st.top()>s[i] and st.top()!='('){
	                        	char q=st.top();
	                        	string b=getstring(q);
	                        	a=a+b;
	                        	st.pop();
	                        	st2.pop();
	                        	st2.push(a);
	                        
	                        
	                        
	                    }
	                }
	                }
	            }
	            	else{
	            		st.push(s[i]);
	            		
					}
	                
	                
	            }
	            
	            
	        }
	        else{
	            if(st2.empty()==true){
	                string w;
	                w=getstring(s[i]);
	                st2.push(w);
	                a=st2.top();
	            }
	            else{
	                string f;
	                f=getstring(s[i]);
	                a=a+f;
	                st2.pop();
	                st2.push(a);
	            }
	            
	        }
	        
	    }
	    if (st.empty()==true){
	        cout<<st2.top()<<endl;
	    }
	    else{
	        while(st.empty()==false){
	            string z;
	            z=getstring(st.top());
	            a=a+z;
	            st.pop();
	            st2.pop();
	            st2.push(a);
	            
	        }
	        cout<<st2.top()<<endl;
	        
	    }
	   
	}
    return 0;
}

