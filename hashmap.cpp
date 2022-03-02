# include <string>
using namespace std;

template<typename T>
class Mapnode{
	public:
		string key;
		T value;
		Mapnode<T>* next;
	
		Mapnode(string key,T value){
			this->key=key;
			this->value=value;
			this->next=NULL;
	}
};

template<typename T>
class Map{
	int size;
	int bucket;
	Mapnode<T>** buckets;
	
	Map(){
		int size=0;
		int bucket=10;
		buckets=new Mapnode<T>*[bucket];
		for(int i=0;i<bucket;i++){
			buckets[i]=NULL;
		}
	
	}
	~Map(){
		for(int i=0;i<bucket;i++){
			delete buckets[i];
		}
		delete buckets;
	}
	
	private:
		int getInt(string key){
			int code=0;
			int i=key.size()-1;
			int power=1;
			while(i>=0){
				code+=key[i]*power;
				code=code%bucket;
				power=power*31;
				power=power%bucket;
				i--;
			}
			return code%bucket;
		}
		
		
		
		
	public:
		void insert(string key,T value){
			int j=getInt(key,bucket);
			
			
			Mapnode<T>* newnode=buckets[j];
			
			while (newnode!=NULL){
				if(newnode->key==key){
					newnode->value=value;
					return;
				}
				newnode=newnode->next;
			}
			Mapnode<T>* node=new Mapnode<T>(key,value);
			node->next=newnode;
			buckets[j]=node;
			size++;
		
	}
		int count(){
			return size;
		}
		
		T getvalue(string key){
			
		}
		
		T remove(string s){
			int j=getInt(s);
			Mapnode<T>* newnode=buckets[j];
			Mapnode<T>* previous=NULL;
			while(newnode!=NULL){
				if(newnode->key=s){
					if(previous==NULL){
						buckets[j]=newnode->next;
					}
					else{
						previous->next=newnode->next;
						
					}
					T num=newnode->value;
					
					newnode->next=NULL;
					delete(newnode);
					size--;
					return num;
					
				}
				previous=newnode;
				newnode=newnode->next;
				
			}
			return 0;
			
		}
	
};
