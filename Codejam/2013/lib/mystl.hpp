#ifndef MYSTL_HPP
#define MYSTL_HPP

#include <list>
#include <stack>
#include <queue>
#include <set>
using namespace std;

template <class T>
class Stack{
private:
    stack<T> data;
public:
    bool empty() const{
	return data.empty();
    }
    T pop(){
	T t = data.top();
	data.pop();
	return t;
    }
    void push(const T &t){
	data.push(t);
    }
    int size() const{
	return data.size();
    }
};

template <class T>
class Queue{
private:
    queue<T> data;
public:
    bool empty() const{
	return data.empty();
    }
    T pop(){
	T t = data.front();
	data.pop();
	return t;
    }
    void push(const T &t){
	data.push(t);
    }
    int size() const{
	return data.size();
    }
};

template <class T, class Compare>
class PQ{
private:
    priority_queue<T, vector<T>, Compare> data;
public:
    bool empty() const{
	return data.empty();
    }
    T pop(){
	T t = data.top();
	data.pop();
	return t;
    }
    void push(const T &t){
	data.push(t);
    }
    int size() const{
	return data.size();
    }
};

#endif
