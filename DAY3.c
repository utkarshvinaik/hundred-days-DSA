#include <stdio.h>

int main() {
    int n, k, i, comp = 0, index = -1;
    
    scanf("%d", &n);
    int arr[n];
    
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    
    for(i = 0; i < n; i++) {
        comp++;
        if(arr[i] == k) {
            index = i;
            break;
        }
    }
    
    if(index != -1) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comp);
    
    return 0;
}