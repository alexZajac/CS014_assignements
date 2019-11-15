#include "graph.h"

Node* findMinAndPop(vector<Node*>* v){
  int min_distance = INT16_MAX, index_min = 0;
  for (int i = 0; i < v->size(); ++i){
    if(v->at(i)->getMinDistance() < min_distance){
      min_distance = v->at(i)->getMinDistance();
      index_min = i;
    }
  }
  Node* result = v->at(index_min);
  v->erase(v->begin() + index_min);
  return result;
}


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
  //NICO
}


 void Graph::DijkstraShortest(Node* start){
   // even if the nodes are constructed with infity distance, we miust re run that part in case nodes are added
   // Iterate each node
   vector<Node*> unvisited_queue;
   map<string,Node* >::iterator it;
   for(it=graph->begin(); it != graph->end();it++) {
      Node* n = (*it).second;
      n->setMinDistance(INT16_MAX);
      n->setPredShort(0);
      unvisited_queue.push_back(n);
   }
   // start city to 0 distance
   start->setMinDistance(0);
   // process
   while(!unvisited_queue.empty()){
     // visit vertex with min_distance
     Node* currV = findMinAndPop(&unvisited_queue);
     // get adjacents
     vector<Edge* >* adjVect = currV->adjacentsList();
     for (Edge* adjE : *adjVect){
       Node* adjV = adjE->getNode();
       int edgeWeight = adjE->getWeight();
       int alternativeDistance = currV->getMinDistance() + edgeWeight;

       // if shorted path from start to adjV is found, update predShort and min_distance of adjV
       if(alternativeDistance < adjV->getMinDistance()){
         adjV->setMinDistance(alternativeDistance);
         adjV->setPredShort(currV);
       }
     }
   }
   
 }

 // WE ASSUME THAT NODE DO NOT HAVE A LARGER DISTANCE THAN INT16_MAX
 double Graph::GetMinDistance(string city1, string city2){
   // getting start and end node
   map<string,Node* >::iterator it1,it2;
   it1 = graph->find(city1);
   it2 = graph->find(city2);
   Node* start = (*it1).second; 
   Node* end = (*it2).second;

   // utilizing Djikstra's algorithm
   this->DijkstraShortest(start);
   
   // we return the min distance of the destination node
   return end->getMinDistance();
 }

 bool Graph::isGraphConnected() {
   //NICO
 }

 int Graph::longestSimplePath() {
  //TODO
 }



int main() {
  cout << "Graph Example 2.0\n";
  // undirected
  Graph g(false);
  
  g.addNode("e");
  g.addNode("f");
  g.addNode("h");
  g.addNode("g");
  g.addNode("j");
  g.addNode("k");

  g.addEdge("e","f",4);
  g.addEdge("e","h",1);
  g.addEdge("f","h",2);
  g.addEdge("f","j",3);
  g.addEdge("f","g",11);
  g.addEdge("g","j",7);
  g.addEdge("g","k",5);
  g.addEdge("j","k", 8);
  double d = g.GetMinDistance("e", "g");
  cout << "Min distance: " << d << endl;

  g.printGraph();
  cout << system("pause");
}


