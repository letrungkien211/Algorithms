#ifndef GSEARCH_HPP
#define GSEARCH_HPP

#include "mystl.hpp"
#include <list>
#include <set>
#include <queue>
#include <cstdio>
using namespace std;


#define MAXITERATION 10000000  // Maximum iterations

enum SearchType {DFS, BFS, ASTAR}; // Search types

// Template class GSearch ( GraphSearch)
template <class DataType, class FringeType>
class Gsearch{
private:
    int numIteration;  // Number of iterations
public:
    // Typename
    SearchType Type;   // Search type
    typedef typename DataType::CompareByCost CompareByCost;  // Compare by cost (multiple)
    typedef typename DataType::CompareByState CompareByState; // Compare by state (unique)
    typedef set<DataType, CompareByState> ClosedType; // Closed type

    // Search operator
    DataType operator()(const DataType &start, const DataType& goal);
    
    // Expand method
    void Expand(FringeType &fringe, ClosedType &closed, ClosedType &buffer,
		const DataType & node,const DataType & goal);

    // Number of iterations
    int NumIteration() const;
};

// Expanding class
template <class DataType, class FringeType>
void Gsearch<DataType,FringeType>::Expand(
    FringeType &fringe, ClosedType &closed, ClosedType &buffer, 
    const DataType &node, const DataType &goal)
{
    Stack<DataType> childrenList;
    DataType child;
    typename ClosedType::iterator it ;
    CompareByCost comparer;
    node.MakeChildren(childrenList);
    while(!childrenList.empty()){
	child = childrenList.pop();
	if((it=buffer.find(child)) != buffer.end()){
	    if(Type == ASTAR){
		child.EvaluateCost(goal);
		if(comparer(child, *it)){
		    fringe.push(child);
		}
	    }
	    continue;
	}
	if((it=closed.find(child)) != closed.end()){
	    if(Type == ASTAR){
		child.EvaluateCost(goal);
		if(comparer(child, *it)){
		    closed.erase(it);
		    fringe.push(child);
		    buffer.insert(child);
		}
	    }
	    continue;
	}
	if(Type == ASTAR)
	    child.EvaluateCost(goal);
	fringe.push(child);
	buffer.insert(child);
    }
}

template <class DataType, class FringeType>
DataType Gsearch<DataType,FringeType >::operator()(const DataType &start, const DataType& goal)
{
    FringeType fringe;
    ClosedType buffer;
    ClosedType closed;
    typename ClosedType::iterator it; 
    fringe.push(start);
    buffer.insert(start);
    numIteration = 0;
    while(!fringe.empty() && numIteration++<MAXITERATION){
	DataType node = fringe.pop();
	if((it = buffer.find(node))!=buffer.end())
	    buffer.erase(it);
	if(node == goal){
	    return node;
	}
	if(closed.find(node)==closed.end()){
	    closed.insert(node);
	    Expand(fringe, closed, buffer, node, goal);
	}
    }
    return DataType();
}

template <class DataType, class FringeType>
int Gsearch<DataType,FringeType>::NumIteration() const 
{
    return numIteration;
}

#endif

