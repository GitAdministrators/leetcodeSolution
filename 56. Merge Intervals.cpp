/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
   bool cmp(const Interval& a,const Interval& b)
    {
        return a.start < b.start;
    }

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
       if(intervals.empty()|| intervals.size()==1) return intervals;
       sort(intervals.begin(),intervals.end(),cmp);
       vector<Interval> res;
       for(int i = 0 ; i<intervals.size();i++)
       {
           if(i+1<intervals.size()
              && intervals[i].end >= intervals[i+1].start)
           {
               int tmp = intervals[i].end>intervals[i+1].end?intervals[i].end:intervals[i+1].end;
               Interval node(intervals[i].start,tmp);
               intervals[i+1].start = node.start;
               intervals[i+1].end = node.end;
           }
           else if(res.empty()|| (res.back().start!= intervals[i].start
                   &&res.back().end!=intervals[i].end))
           {
               res.push_back(intervals[i]);
           }
       }
       if(res.back().start != intervals.back().start && intervals.back().end != res.back().end)
           res.push_back(intervals.back());
       return res;
    }
};
