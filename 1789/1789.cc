#include <iostream>

int main() {
    unsigned int s;
    unsigned long long int sum = 0;
    
    scanf("%u", &s);
    
    for (int i = 1;; ++i) {
        sum += i;
        
        if (s <= sum) {
			printf("%d", (s == sum) ? i : i - 1);
			break;
		}
    }
    
    return 0;
}