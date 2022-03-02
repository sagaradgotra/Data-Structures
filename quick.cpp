#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
     
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSorts(int arr[], int low, int high)
{
    if (low >= high){
        return;
    }
        
        int pi = partition(arr, low, high);
 
        quickSorts(arr, low, pi - 1);
        quickSorts(arr, pi + 1, high);
    }
void quickSort(int input[], int size) {
    quickSorts(input,0 , size-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


