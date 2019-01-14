/* 57 Insert Interval
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times.
 * example:
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        if(intervals.size() <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start <= res.back().end)
                res.back().end = max(intervals[i].end, res.back().end);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};