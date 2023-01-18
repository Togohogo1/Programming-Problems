int MAXN = 1e5+5;

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *fwd = (int *)malloc(MAXN*sizeof(int));
    int *bwd = (int *)malloc(MAXN*sizeof(int));
    int *ans = (int *)malloc(MAXN*sizeof(int));
    *returnSize = numsSize;

    fwd[0] = 1;
    bwd[0] = 1;

    for (int i = 0; i < numsSize; i++) {
        fwd[i+1] = nums[i]*fwd[i];
        bwd[i+1] = nums[numsSize-i-1]*bwd[i];
    }

    for (int i = 0; i < numsSize; i++) {
        ans[i] = fwd[i]*bwd[numsSize-i-1];
    }

    return ans;
}
