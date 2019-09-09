#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

unsigned long cosine(float x);

int main(){
    int base = time(NULL);
    int offset;
    int delta_x = 15;
    int* blocks;

    for (;;){
        offset = (time(NULL) - base);
        if(offset == 1){
            unsigned long num_of_blocks = cosine(2*3.14/30 * delta_x);
            blocks = (int *) realloc(blocks, sizeof(int) * num_of_blocks);
            if(blocks == NULL)
                printf("malloc() failed\n");
            delta_x++;
            base = time(NULL);
            printf("%d\n", sizeof(int) * num_of_blocks);
        }
    }

    getchar();
    return 0;
}

unsigned long cosine(float x){
    float result = (float) cos(x) + 1.0;
    unsigned long amplitude = 200000000;

    return ceil(result * amplitude);
}