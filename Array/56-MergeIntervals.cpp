/* 56 Merge Intervals
 * Given a collection of intervals, merge all overlapping intervals.
 * example:
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 */


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a, Interval b) {return a.start < b.start;}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size();
        if(len <= 1) return intervals;
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), compare);
        
        res.push_back(intervals[0]);
        for(int i = 1; i < len; i++){
            if(intervals[i].start <= res.back().end) 
                res.back().end = intervals[i].end >= res.back().end? intervals[i].end: res.back().end;
            else res.push_back(intervals[i]);
        }
        return res;
    }
};