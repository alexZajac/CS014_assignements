#include "graph.h"
#include<vector>


 vector<string>* Node::neighbors() {
   vector<string>* vec = new vector<string>();
   vector<Edge*>::iterator it;
   for(it=adjacents->begin();it!=adjacents->end();it++) {
     vec->push_back((*it)->getNode()->getPayload());
   }
   return vec;
 }


 void Graph::addNode(string name) {
    Node* node = new Node(name);
    graph->insert(pair<string,Node*>(name,node));
 }

 void Graph::addEdge(string k1, string k2, double w=1.0) {
   map<string,Node* >::iterator it1,it2;
   it1 = graph->find(k1);
   it2 = graph->find(k2);

   //Check both nodes exists using the map
   if (it1 != graph->end() && it2 != graph->end()) {
      Node* n1 = (*it1).second;
      Node* n2 = (*it2).second;
      //Create the edge and add it to the adjacents
      Edge* e = new Edge(n2,w);
      n1->addEdge(e);
      //Undirected graph: we add the reverse or back edge
      if (!directed) {
        Edge* be = new Edge(n1,w);
        n2->addEdge(be);
      }
   }
 }


void Graph::printGraph() {
   //Iterate each node
  map<string,Node* >::iterator it;
  for (it=graph->begin(); it != graph->end();it++) {
    Node* n = (*it).second;
    cout << n->getPayload() << "[";
    
    //Iterate the neighboors
    vector<string>* neigh  = n->neighbors(); 
    vector<string>::iterator itn;
    for(itn=neigh->begin();itn!=neigh->end();itn++) {
       cout << (*itn) << " ";
    }
    cout << "]" << endl;
  }
}

bool Graph::IsThereTripletClique(){

}

 double Graph:: GetMinDistance(string city1,string city2){

 }

 bool Graph::isGraphConnected() {
    //Initialize connected nodes with the first node
    vector<string> visited = vector<string>();
    visited.push_back(this->graph->begin()->first);
    this->graph->begin()->second->setVisited(true);

    //traverse currently connected node
    for(size_t i = 0; i < visited.size(); i++){
      Node* node = this->graph->at(visited.at(i));
      //Check what nodes are connected to it to add them to connected nodes
      for(vector<Edge*>::iterator itn = node->adjacentsList()->begin();itn!=node->adjacentsList()->end();itn++) {
        if(!(*itn)->getNode()->isVisited()){
          visited.push_back((*itn)->getNode()->getPayload());
          (*itn)->getNode()->setVisited(true);
        }
      }
    }

    return visited.size() == this->graph->size();
 }

 int Graph::longestSimplePath() {

 }



int main() {
  cout << "Graph Example 2.0\n";
  Graph g(false);
  
  g.addNode("a");
  g.addNode("b");
  g.addNode("c");

  //g.addEdge("a","b",10);
  g.addEdge("b","c",5);
  // g.addEdge("c","a",9);


  g.printGraph();

  cout << g.isGraphConnected() << endl;
  system("pause");
}


