# include<bits/stdc++.h>
using namespace std;
long long int has(string a){
	int n=a.size();
	long long int b=0;
	int i=n-1;
	while(i>=0){
		int q=a[i]-'a'+1;
		b=(b*50)+q;
		i--;
	}
	return b;
	
}
bool check(string s,string v){
	long long int w=has(v);
	int n=s.size();
	int q=v.size();
	int lo=0;
	int hi=q-1;
	string g=s.substr(lo,q);
	long long int code=has(g);
	if(code==w){
		if(v==g){
			return true;
		}
	}
	while(hi<n){
		long long int l=pow(50,q-1)*(s[lo]-'a'+1);
		code=code-l;
		code=code*50;
		lo++;
		hi++;
		code=code+(s[hi]-'a'+1);
		if(code==w){
			int t=lo-1;
			int u=0;
			int h=0;
			while(t<=hi-1){
				if(s[t]!=v[u]){
					h=1;
					break;
				}
				u++;
				t++;
			}
			if(h==0){
				return true;
			}
			
		}
		
	}
	return false;
}

int main(){
	string s;
	cin>>s;
	string a="gggtcgcgtt";
	string b="aaccatgccg";
	string c="gaagagtctt";
	if(check(s,a) or check(s,b) or check(s,c)){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
	
	
}
