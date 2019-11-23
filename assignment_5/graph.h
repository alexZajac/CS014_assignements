#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Edge;

//Node
// visited: bool
// payload: string
// adjacents: vector<Edge*>


class Node {
public:
 Node(const string& elem):payload(elem),visited(false),min_distance(INT16_MAX),predShort(0){ 
    adjacents = new vector<Edge* >();
  };
  ~Node() {};
  void   setVisited(bool v)        {visited = v;};
  void   setMinDistance(double d)  {min_distance = d;};
  void   setPredShort(Node * n)    {predShort = n;};
  bool   isVisited()               {return visited;};
  void   addEdge(Edge* e)    {
    adjacents->push_back(e);
  };
  // operator overloading for minPQ
  bool operator< (Node* n)         {return this->min_distance < n->min_distance;};
  int    degree()  const           {return adjacents->size();};
  string getPayload() const        {return payload;}
  double getMinDistance() const    {return min_distance;};
  Node* getPredShort() const       {return predShort;};
  vector<string>*  neighbors();
  vector<Edge* >*  adjacentsList() {return adjacents;};
private:
  string        payload;
  bool          visited;
  int      min_distance;
  Node*       predShort;
  vector<Edge* >* adjacents;
};


//Edge-
class Edge {
public:
  Edge(Node* n, double w):node(n),weight(w){};
  ~Edge() {};
  void      setWeight(double w)  {weight=w;};
  Node*     getNode()   const    {return node;};
  double    getWeight() const    {return weight;};
private:
  Node*  node;
  double weight;
  friend class Node;
};


//Graph
class Graph {
public:
  Graph(bool directed):directed(directed){
    graph = new map<string, Node*>();
  };

  ~Graph() {
    delete graph;
   };
  
  //DO NOT CHANGE THE FOLLOWING METHODS
  void addNode(string node);
  void addEdge(string nid1 , string nid2, double w);
  void printGraph();

  //Homework 
  bool IsThereTripletClique();
  int GetMinDistance(string city1,string city2);
  bool isGraphConnected();
  int longestSimplePath();
  map<string,Node*>* getGraph();

  
private:
  bool IsThereTripletClique(Node*, Node*, int);
  int getMaxDistance(Node* n, int);
  map<string,Node*>* graph;
  bool directed;
  // helper 
  void DijkstraShortest(Node*);
};
#endif