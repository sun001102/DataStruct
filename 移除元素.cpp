int removeElement(int* nums, int numsSize, int val) {
    int src = 0, dst = 0;
    while (src < numsSize)
    {
        if (nums[src] != val)
        {
            nums[dst] = nums[src];
            ++src;
            ++dst;
        }
        else
        {
            ++src;
        }
    }
    return dst;
}