#include <bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int no;
};
    
static bool comp(meeting a, meeting b){
    return a.end<b.end;
}
    
int maxMeetings(vector<int> start, vector<int> end) {
    vector<meeting> meetings;
    for(int i = 0; i<start.size(); i++)
        meetings.push_back({start[i], end[i], i+1});
    sort(meetings.begin(), meetings.end(), comp);
    int count = 0, lastEnd = -1;
    for(auto meet: meetings){
        if(meet.start>lastEnd){
            count++;
            lastEnd = meet.end;
        }
    }
    return count;
}