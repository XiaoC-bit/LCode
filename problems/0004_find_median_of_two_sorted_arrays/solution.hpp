#pragma once
#include "../../include/utils.h"

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;

        /**
         * 假设numsRes是新的合并数组，但并不需要真的去合并，所以这个算法只是寻找这个新数组的某个位置（如果是偶数，就是某两个位置）的元素而已。
         * 此处思路是，将两个数组，分别在i处和j处分开成左右两边。其中i+j = (m+n+1)/2
         * 由于两个数组本来就有序，所以只要满足 nums1[i-1] <= nums2[j]  &&  nums2[j-1] <= nums1[i]
         * 就可以得到新数组前 (m+n+1)/2  个元素。
         * 得到这个信息后，就很有用了。
         *
         * 第一个数组左边为 [0,i-1] 总共i个
         * 第二个数组右边为 [0,j-1] 总共j个
         * 如果m+n是偶数，以下的算式  "+1"的部分，并不会起作用。中位数在两个数组分割处的“左边最大” 与 ”右边最小“，这两个元素的平均值
         * 如果m+n是奇数，那么左边部分的最大元素，就是中位数
         */
        int totalLeft = (n + m + 1) / 2;

        while (left <= right)
        {

            // 对较短的数组，进行二分查找。另外一个数组根据上方的数学证明，使用减法得到下标即可。
            /*
             *  数组A
             *  a[0] a[1] a[2]..... a[i-1] a[i] ..... a[m]
             *  数组B
             *  b[0] b[1] b[2]..... b[j-1] b[j] ..... b[n]
             *
             */
            int i = (left + right) / 2;
            int j = totalLeft - i;

            int ALeft, ARight, BLeft, BRight;

            /**
             * 参考上方的数组示意图，存在一些corner case 需要讨论
             */
            ALeft = (i == 0) ? INT_MIN : nums1.at(i - 1);
            ARight = (i == m) ? INT_MAX : nums1.at(i);
            BLeft = (j == 0) ? INT_MIN : nums2.at(j - 1);
            BRight = (j == n) ? INT_MAX : nums2.at(j);

            if (ALeft <= BRight && BLeft <= ARight)
            {
                // 此处满足了nums1[i-1] <= nums2[j]  &&  nums2[j-1] <= nums1[i]
                // 因此找到了所需要的分割处

                if ((m + n) % 2 == 1)
                {
                    return std::max(ALeft, BLeft);
                }
                else
                {
                    return (std::max(ALeft, BLeft) + std::min(ARight, BRight)) / 2.0;
                }
            }

            if (ALeft > BRight)
            {
                /**
                 * a[i-1] > b[j] 说明i太大了。i要往左边移动
                 * 那么就收缩右边界
                 */
                right = i - 1;
            }
            if (BLeft > ARight)
            {
                /**
                 * 此处和上面一样，收缩左边界
                 */
                left = i + 1;
            }
        }
        return 0.0;
    }
};
