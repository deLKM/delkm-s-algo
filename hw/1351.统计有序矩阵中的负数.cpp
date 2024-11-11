#include <vector>

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int num = 0;
        for (auto x : grid) {
            int l = 0, r = (int)x.size() - 1, pos = -1;
            while (l <= r) {
                int mid = l + ((r - l) / 2);
                if (x[mid] < 0) {
                    pos = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if (~pos) num += (int)x.size() - pos;// pos=-1表示这一行全是>=0的数，不能统计
        }
        return num;
    }
};