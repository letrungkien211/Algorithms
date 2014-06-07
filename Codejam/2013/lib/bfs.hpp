#ifndef BFS_HPP
#define BFS_HPP

#include <stack>
#include <set>

using namespace std;

template<class State>
State BFS(const State &start, const State &goal){
    stack<State> fringe;
    set<State> closed;

    fringe.push(start);
    while(!fringe.empty()){
	State node = fringe.top();
	fringe.pop();
	if(node.IsGoal(goal)){
	    return node;
	}
	closed.push(node);
	stack<State> childrenList;
	node.MakeChildren(childrenList);
	while(!childrenList.empty()){
	    State child = childrenList.top();
	    childrenList.pop();
	    if(closed.find(child)==closed.end()){
		fringe.push(child);
	    }
	}
    }
}    
#endif
