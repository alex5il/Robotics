/*
 * AStar.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: colman
 */

#include "AStar.h"
#include "../Map/Map.h"


#include <iostream>
#include <iomanip>

#include <vector>
#include <utility>
#include <queue>

#include <map>

#include <algorithm>

using namespace std;




// Priority queue for , getting the location with least amount of total 'weight'
struct PriorityQueue {

	// We use pair here for , weight priority and the location itself
  typedef pair<int, Location> element;

  priority_queue<element, vector<element>,
                 greater<element> > elements;

  // Create simple syntatic sugar methods for us to use later
  bool empty() { return elements.empty(); }

  void put(Location item, int priority) {
	  pair<int, Location> newElement;
	  newElement.first = priority;
	  newElement.second = item;

	  elements.push(newElement);
  }

  Location get() {
	  Location best_item = elements.top().second;
    elements.pop();
    return best_item;
  }

};

// heuristic method (the whole point of a*)
float heuristic(Location a, Location b) {
  return abs(a.posX - b.posX) + abs(a.posY - b.posY);
}

// Reconstruct the path via the 'came_from' parameters and the start end goals
vector<Location> reconstruct_path(
   Location start,
   Location goal,
   map<Location, Location>& came_from
) {
  vector<Location> path;
  Location current = goal;

  path.push_back(current);

  // Just push until we arrive to the begining
  while (current != start) {
    current = came_from[current];
    path.push_back(current);
  }

  // Reverse it cause we ran trough the end to the start
  std::reverse(path.begin(), path.end());

  return path;
}

// The a* algo
void a_star_search
  (Graph* graph,
   Location start,
   Location goal,
   map<Location, Location>& came_from,
   map<Location, float>& cost_so_far)
{

	// Set up the parameters , and our priority queue
  PriorityQueue frontier;
  frontier.put(start, 0);

  came_from[start] = start;
  cost_so_far[start] = 0;

  // We run until we went trough all the locations on the grid , or until we've found our end location
  while (!frontier.empty()) {
	Location current = frontier.get();

	// We've found our goal so break
    if (current == goal) {
      break;
    }

    // Get all the neighbors to the current Location
    vector<Location> neighbors = graph->neighbors(current);

    for(int i = 0; i<neighbors.size(); i++) {

    	Location next = neighbors[i];
    	float new_cost = cost_so_far[current] + graph->Cost(current, next);

    	if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
    		cost_so_far[next] = new_cost;
    		float priority = new_cost + heuristic(next, goal);

    		frontier.put(next, priority);
    		came_from[next] = current;
    	}
    }

  }
}




AStar::AStar() {
	// TODO Auto-generated constructor stub


}

vector<Location> AStar::runAstar(Graph* graph,
		   Location start,
		   Location goal,
		   map<Location, Location>& came_from,
		   map<Location, float>& cost_so_far) {

	// Find path via the alghorithm
	a_star_search(graph, start, goal, came_from, cost_so_far);

	// Recreate the path from vector and return it
	return reconstruct_path(start, goal, came_from);

}


AStar::~AStar() {
	// TODO Auto-generated destructor stub
}

