#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <map>
#include <queue>
#include<unordered_set>

using namespace std;

class Solution {
public:

    vector<vector<string>> getPaths(string start, string end,
	unordered_map<string, unordered_set<string>> backtrack, unordered_set<string> dict){
	    vector<vector<string>> results;
	    unordered_set<string> curr_track = backtrack[end];
	    if(backtrack[end].empty())
	        return results;
	    for(unordered_set<string>::iterator it = curr_track.begin(); it!=curr_track.end(); it++){
	        results = getPaths(start,*it, backtrack, dict);
	        for(int i =0; i < results.size(); i++)
	            results[i].push_back(end);
	    }
	    return results;  
	    
	}

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        queue <string > open;
        unordered_set<string> closed;
        unordered_set<string> levelClosed;
        unordered_map<string,unordered_set<string>> backtrack;

		if (start == end){
		    return  vector<vector<string>>{vector<string>{start}};
		}			
		open.push(start);
		closed.insert(start);
		
		int minLength = numeric_limits<int>::max();
		int length = 0;
		bool flag = false;
		while (!open.empty()){
		    if(length>=minLength)
		        break;
		    string curr = open.front();
		    string hold_curr = curr;
		    open.pop();
		    for(int i =0; i<curr.size(); i++){
		      char tmp = curr[i];
		          for (char c = 'a'; c <= 'z'; c++){
		            if(c==tmp)
		            	continue;
    				curr[i] = c;
    				if (curr == end){
    				    minLength = min(minLength,length+1);
    					backtrack[end].insert(hold_curr);
    					break;
    				}
					else if (closed.find(curr)==closed.end() && dict.find(curr) != dict.end()){
        				    backtrack[curr].insert(hold_curr);
        				    levelClosed.insert(curr);
					}
		            curr[i]=tmp;
		        }
		    }
		    
		    if(!open.empty()){
		        for(auto s : levelClosed){
		            open.push(s);
		            closed.insert(s);
		            length++;
		        }
		    }
		}
		return getPaths(start, end, backtrack, dict);
	}
};