#include <stdio.h>

int main() {
    int n, y, x;
    
    scanf("%d", &n);
    
    int arr[n + 1];
    
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    
    scanf("%d", &y);
    scanf("%d", &x);
    
    
    int index = y - 1;
    
    
    for(int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
   
    arr[index] = x;
    n++;
    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}