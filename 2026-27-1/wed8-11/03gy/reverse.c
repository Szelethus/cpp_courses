#include <stdio.h>

int main() {
    unsigned int num, reversed = 0;
    
    scanf("%u", &num);
    
    unsigned int original = num;
    int bit_count = sizeof(num) * 8; 

    for (int i = 0; i < bit_count; i++) {
        reversed <<= 1;           
        
        reversed |= (num & 1);    
        
        num >>= 1;                
    }
    
    printf("Original: %u\n", original);
    printf("Reversed: %u\n", reversed);
    
    return 0;
}
