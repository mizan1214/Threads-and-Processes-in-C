#include <stdio.h>
#include <math.h>

void do_work() {
    double result = 0;
    for (int i = 1; i <= 10000000; i++) {
        result += log(i) * sin(i) * cos(i); // math operation
    }
    
}

int main() {
    do_work();
    return 0;
}
// Change in branch
