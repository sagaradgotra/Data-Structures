# include <iostream>
# include "stackusingll.h"
using namespace std;
int main(){
	stackusingll stk;
	stk.push(10);
	stk.push(20);
	stk.push(50);
	stk.push(60);
	stk.push(70);
	cout<< stk.size()<<endl;
	
	return 0;
	
}
