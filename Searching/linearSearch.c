#include <stdio.h>

void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int target, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
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
    
    int targetIndex = linearSearch(arr, target, n);
    
    
    if (targetIndex != -1){
        printf("index found at index %d", targetIndex);
    }else{
        printf("element not found");
    }
    
    
    
}