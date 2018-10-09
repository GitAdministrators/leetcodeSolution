/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.empty())
        {
            res.push_back(newInterval);
            return res;
        }
        if(newInterval.end< intervals[0].start)
        {
            res = std::move(intervals);
            res.insert(res.begin(),newInterval);
            return res;
        }
        if(newInterval.start> intervals[intervals.size()-1].end)
        {
            res = std::move(intervals);
            res.push_back(newInterval);
            return res;
        }
        
        for(int i = 0 ;i<intervals.size();i++)
        {
            if(intervals[i].end < newInterval.start || intervals[i].start > newInterval.end) 
            {
                res.push_back(intervals[i]);                 
                if(i+1<intervals.size() 
                   && intervals[i].end < newInterval.start 
                   && intervals[i+1].start> newInterval.end)
                {
                    res.push_back(newInterval);
                }
            }
            else
            {
                while(i<intervals.size() && intervals[i].start <= newInterval.end)
                {
                    newInterval.start = min(intervals[i].start,newInterval.start);
                    newInterval.end   = max(intervals[i].end  ,newInterval.end);
                    i++;
                }
                res.push_back(newInterval);
                i--;
            }
        }
        return res;
    }
};
