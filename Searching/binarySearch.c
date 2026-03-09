#include <stdio.h>

void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int binarySearch(int arr[], int target, int n){
    int mid;
    int low = 0;
    int high = n-1;
    int i = 0;
    
    while(low <= high){
        mid = (low + high)/2;
        
        if(arr[mid] == target) return mid;
        if(arr[mid] < target) high = mid - 1;
        else low = mid + 1;
        
    }
    return -1;
}

int binarySearchRecursive(int arr[], int target, int low, int high){
    
    if(low <= high){
        
        int mid = (low + high)/2;
        
        if (arr[mid] == target) return mid;
        
        if (arr[mid] > target){
            return binarySearchRecursive(arr,target,mid+1,high);
        }
        return binarySearchRecursive(arr,target,low, mid-1);
    }
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    
    int arr[n];
        
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printArray(arr,n);
    
    int target = 21;
    
    int targetIndex = binarySearchRecursive(arr, target, 0, n-1);
    
    if (targetIndex != -1){
        printf("index found at index %d", targetIndex);
    }else{
        printf("element not found");
    }
    
    
    
}