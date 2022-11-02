#include <stdio.h>

// int* twoSum(int *nums, int size, int target);

int main() {
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int size = 4;
    int indices_list[2] = {0, 0};
    int length = sizeof(nums);
    int num1 = -1;
    int num2 = -1;
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            if(nums[i]+nums[j]==target) {
                num1 = i;
                num2 = j;
            }
        }
    }
    indices_list[0] = num1;
    indices_list[1] = num2;


    //int *index = twoSum(nums, 4, target);
    //printf(twoSum(nums, target));
    printf("%d, %d \n", indices_list[0], indices_list[1]);
    return 0;
}

// int* twoSum(int *nums, int size, int target) {
//     int indices_list[2] = {0, 0};
//     int length = sizeof(nums);
//     int num1 = -1;
//     int num2 = -1;
//     for(int i = 0; i < size; i++) {
//         for(int j = i+1; j < size; j++) {
//             if(nums[i]+nums[j]==target) {
//                 num1 = i;
//                 num2 = j;
//             }
//         }
//     }
//     indices_list[0] = num1;
//     indices_list[0] = num2;
//     return indices_list;
// }