#include <stdio.h>
#include <stdlib.h>

void update_value(int *ptr) {
    *ptr = *ptr + 10;
}

int main() {
    int x = 5;
    int *ptr = &x;
    
    printf("Before: %d\n", x);
    update_value(ptr);
    printf("After: %d\n", x);
    
    int *arr = malloc(3 * sizeof(int));
    arr[0] = 10;
    arr[1] = 20;
    free(arr);
    
    return 0;
}