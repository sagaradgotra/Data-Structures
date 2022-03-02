# include <vector>
using namespace std;
template <typename T>
class treenode{
	public:
	T data;
	vector<treenode<T>*> children;
	
	treenode(T element){
		this ->data=element;
		
		
	}
	
	
};
