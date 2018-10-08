/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool lessSort(Interval a, Interval b) {
    return a.start<b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& ints) {
        vector<Interval> res;
        if (ints.empty()) return res;
        sort(ints.begin(), ints.end(), lessSort);
        res.push_back(ints[0]);
        for (int i=1;i<ints.size();++i) {
            if (res.back().end>=ints[i].start) {
                res.back().end = max(ints[i].end, res.back().end);
            }
            else res.push_back(ints[i]);
        }
        return res;
    }
};
