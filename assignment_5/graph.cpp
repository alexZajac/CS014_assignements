#include "graph.h"
#include <time.h>
#include <vector>
#include <chrono>
using std::chrono::high_resolution_clock;

Node* findMinAndPop(vector<Node*>* v){
  int min_distance = INT16_MAX, index_min = 0;
  for (unsigned int i = 0; i < v->size(); ++i){
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

bool Graph::IsThereTripletClique(Node* origin, Node* current,int depth){

  if(depth >3) return false;
  else if(depth == 3) return current == origin;
  else{
    for (vector<Edge*>::iterator it=current->adjacentsList()->begin(); it != current->adjacentsList()->end();it++)
      if(IsThereTripletClique(origin,(*it)->getNode(),depth+1))
        return true;
    return false;
  }
}

bool Graph::IsThereTripletClique(){
  for (map<string,Node* >::iterator it=graph->begin(); it != graph->end();it++)
    if(this->IsThereTripletClique(it->second,it->second,0))
      return true;
  return false;
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
 // WE ASSUME THAT NODE DO NOT HAVE A LARGER DISTANCE THAN INT16_MAX
 int Graph::GetMinDistance(string city1, string city2){
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

 map<string,Node*>* Graph::getGraph(){
   return this->graph;
 }

 // longest distance you can travel (weights) to with no cycle
 int Graph::longestSimplePath() {
   int max_distance = 0;
   map<string,Node* >::iterator it;
   for(it=graph->begin(); it!=graph->end(); it++) {
      Node* n = (*it).second;
      int curr_distance = this->getMaxDistance(n, 0);
      if (curr_distance > max_distance)
          max_distance = curr_distance;
   }
   return max_distance;
 }

 int Graph::getMaxDistance(Node* n, int currDistance){
    n->setVisited(true);
    int max_distance = currDistance;
    for (Edge* adjE : *(n->adjacentsList())){
        Node* adjV = adjE->getNode();
        int pathDistance = currDistance;
        if(!adjV->isVisited())
            pathDistance = getMaxDistance(adjV, currDistance + adjE->getWeight());
        max_distance = max(pathDistance, max_distance);
    }
    n->setVisited(false); 
    return max_distance;
 }

 Graph* createGraph(int num_nodes=100, int num_edges=500, int num_weights=3, bool directed=false){
   Graph* g = new Graph(directed);
   srand(0);
   // 100 nodes
   for(int i = 0; i < num_nodes; i++){
     g->addNode(to_string(i));
   }
   // 500 with weight1, 500 with weight 2 and 500 with weight 3
   int weight = 1;
   while(weight <= num_weights){
     for(int i = 0; i < num_edges; i++){
       string r1 = to_string(rand() % num_nodes);
       string r2 = to_string(rand() % num_nodes);
       // checking if connection is already there
       bool is_valid = true;
       map<string,Node* >::iterator it;
       Node* n = (g->getGraph()->find(r1))->second;
       for (Edge* e : *(n->adjacentsList()))
          if(e->getNode()->getPayload() == r2)
            is_valid = false;

       while(r1 == r2 || !is_valid){
          r1 = to_string(rand() % num_nodes);
          r2 = to_string(rand() % num_nodes);
          is_valid = true;
          map<string,Node* >::iterator it;
          Node* n = (g->getGraph()->find(r1))->second;
          for (Edge* e : *n->adjacentsList())
              if(e->getNode()->getPayload() == r2)
                is_valid = false;
       }
       // valid connection
       g->addEdge(r1, r2);
     }
     weight++;
   }
   return g;
 }


 void time_testing(){
   int n_nodes = 100;
   bool directed = false;
   // shouldn't exceed n*(n-1)/6 for undirected and n*(n-1)/3 for directed, since that's the max unique edges times the n_weight
   int n_weights = 3;
   int n_edges = n_nodes*(n_nodes-1)/(directed ? n_weights : n_weights*2);
   Graph* g = createGraph(n_nodes, n_edges, n_weights, directed);
   g->printGraph();

   cout << "Measuring isTripletClique(): \n";
   auto s1 = high_resolution_clock::now();
   bool b1 = g->IsThereTripletClique();
   auto e1 = high_resolution_clock::now();
   cout << "Result: " << b1 << endl;
   std::chrono::duration<double> elapsed1 = e1 - s1;
   cout << "Duration of execution: " << elapsed1.count() << endl;

   cout << "Measuring isConnected(): \n";
   auto s2 = high_resolution_clock::now();
   bool b2 = g->isGraphConnected();
   auto e2 = high_resolution_clock::now();
   cout << "Result: " << b2 << endl;
   std::chrono::duration<double> elapsed2 = e2 - s2;
   cout << "Duration of execution: " << elapsed2.count() << endl;

   cout << "Measuring getMinDistance(): \n";
   string r1 = to_string(rand() % n_nodes);
   string r2 = to_string(rand() % n_nodes);
   while(r1 == r2){
      r1 = to_string(rand() % n_nodes);
      r2 = to_string(rand() % n_nodes);
   }
   cout << "First city: " + r1 << endl;
   cout << "Second city: " + r2 << endl; 
   auto s3 = high_resolution_clock::now();
   int res1 = g->GetMinDistance(r1, r2);
   auto e3 = high_resolution_clock::now();
   cout << "Result: " << res1 << endl;
   std::chrono::duration<double> elapsed3 = e3 - s3;
   cout << "Duration of execution: " << elapsed3.count() << endl;

   cout << "Measuring longestSimplePath(): \n";
   auto s4 = high_resolution_clock::now();
   int res2 = g->longestSimplePath();
   auto e4 = high_resolution_clock::now();
   cout << "Result: " << res2 << endl;
   std::chrono::duration<double> elapsed4 = e4 - s4;
   cout << "Duration of execution: " << elapsed4.count() << endl;
   
 }


 void function_testing(){
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
  int d = g.longestSimplePath();
  cout << "Max distance: " << d << endl;
  g.printGraph();
 }


int main() {
  time_testing();
  cout << system("pause");
}


