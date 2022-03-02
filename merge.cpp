#include <iostream>
using namespace std;

void merge(int input[],int l, int m ,int r){
    int n1 = m - l +1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0;i < n1;i++){
        L[i] = input[l+i];
    }
    for(int i = 0;i < n2;i++){
        R[i] = input[m+1+i];
    }
    int i , j , k;
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            input[k++] = L[i++];
        }else{
            input[k++] = R[j++];
        }
    }
    while(i < n1){
        input[k++] = L[i++];
    }
    while(j < n2){
        input[k++] = R[j++];
    }
}
void helper(int input[], int l, int r){
    if(l >= r){
        return;
    }
    int m = (l+r-1)/2;
    helper(input,l,m);
    helper(input,m+1,r);
    merge(input,l,m,r);
}



void mergeSort(int input[], int size){
	helper(input,0,size-1);
        
}

int main() {
  int len;
  cin >> len;
  int* input = new int[len];
  for(int i=0; i < len; i++)
    cin >> input[i];
  mergeSort(input, len);
  for(int i = 0; i < len; i++) {
    cout << input[i] << " ";
  }
}
