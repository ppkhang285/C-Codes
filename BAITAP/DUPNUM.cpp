#include <bits/stdc++.h>

using namespace std;

int findDuplicate(int nums[]){
    int tortoise =nums[0];
    int hare = nums[0];
    while (true){
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
        if (tortoise == hare) break;
    }
    int ptr1 = nums[0];
    int ptr2 = tortoise;
    while (ptr1 != ptr2){
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }
    return ptr1;
}

int main(){
    int nums[5] = {1,2,3,2,4};
    cout<< findDuplicate(nums);
    return 0;
}
