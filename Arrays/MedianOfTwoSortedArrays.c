// Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <stdlib.h>

int getMin(int* nums1, int m, int* nums2, int n, int* p1, int* p2) {
    if (*p1 < m && *p2 < n) {
        return nums1[*p1] < nums2[*p2] ? nums1[(*p1)++] : nums2[(*p2)++];
    } else if (*p1 < m) {
        return nums1[(*p1)++];
    } else {
        return nums2[(*p2)++];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = nums1Size, n = nums2Size;
    int p1 = 0, p2 = 0;
    int total = m + n;

    if (total % 2 == 0) {
        for (int i = 0; i < total / 2 - 1; i++) {
            getMin(nums1, m, nums2, n, &p1, &p2);
        }
        int a = getMin(nums1, m, nums2, n, &p1, &p2);
        int b = getMin(nums1, m, nums2, n, &p1, &p2);
        return (a + b) / 2.0;
    } else {
        for (int i = 0; i < total / 2; i++) {
            getMin(nums1, m, nums2, n, &p1, &p2);
        }
        return getMin(nums1, m, nums2, n, &p1, &p2);
    }
}
