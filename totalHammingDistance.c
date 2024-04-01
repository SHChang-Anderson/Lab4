#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

int totalHammingDistance(int* nums, int numsSize)
{
    int total = 0;;
    for (int i = 0;i < numsSize;i++)
        for (int j = 0; j < numsSize;j++)
            total += __builtin_popcount(nums[i] ^ nums[j]); 
    return total >> 1;
}

int totalHammingDistance_(int* nums, int numsSize)
{
    int total = 0;
    for (int i = 0;i < 32;i++) {
        int ct = 0;
        for (int j = 0; j < numsSize;j++)
            ct += ((nums[j] >> i) & 1);

        total += ct * (numsSize - ct);
    }
    return total;
}

int main() 
{
    srand(time(NULL));
    int nums[10000];
    for (int i = 0; i < 10000; i++) {
        nums[i] = (int)random();
    }
    assert(totalHammingDistance(nums, 10000) == totalHammingDistance_(nums, 10000));

    printf("Pass ! \n");

    return 0;
}