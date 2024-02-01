#include <stdio.h>

int numSum(int num) {
    if (num == 0) {
        return 0;
    } else {
        return (num % 10) + numSum(num / 10);
    }
}

int main() {
    int num, res;
    scanf("%d", &num);
    res = numSum(num);
    printf("%d.\n", res);
    return 0;
}
