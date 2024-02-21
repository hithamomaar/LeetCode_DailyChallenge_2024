class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        while (r > l)
            r &= (r - 1);
        return r;
    }
};
