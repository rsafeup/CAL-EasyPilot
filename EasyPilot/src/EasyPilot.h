
#ifndef SRC_EASYPILOT_H_
#define SRC_EASYPILOT_H_

#include "Graph.h"
#include "graphviewer.h"
#include "iostream"
#include "fstream"
#include "string"
#include <float.h>
#include <algorithm>

#define GV_WINDOW_WIDTH 1600 	// graph viewer x resolution
#define GV_WINDOW_HEIGHT 700	// gv y resolution

class EasyPilot {
private:
	Graph<unsigned> graph;
	GraphViewer * gv;
	string map;
	int sourceID;
	int destinyID;
	vector<int> pointsOfInterest; // definido pelo utilizador
	vector<int> inaccessibleZones; //o melhor ser� fazer um ficheiro com esta informa��o
public:
	EasyPilot();
	virtual ~EasyPilot();
	bool readOSM();
	void graphInfoToGV();
	int highlightNode(int id, string color);
	int highlightEdge(int id);
	void highlightPath();
	void eraseMap();
	void updateMap();
	string getMap() const;
	void setMap(string m);
	int getsourceID() const;
	int setsourceID(int id);
	int getdestinyID() const;
	int setdestinyID(int id);
	int addPointOfInterest(int id);
	int removePointOfInterest(int id);
};

/*Utility functions and classes to adapt nodes position in GV*/

//continua a fazer a documenta��o aleixo. T�s a trabalhar bem, gg

struct Link {
	Link() {}
	unsigned node1Id, node2Id, roadId;
	Link(unsigned r, unsigned n1, unsigned n2) :
			roadId(r), node1Id(n1), node2Id(n2) {
	}
};

/**
 * LimitCoords will store the highest and lowest longitude and latitude of the nodes
 */
struct LimitCoords
{
	double maxLat;
	double minLat;
	double maxLong;
	double minLong;
};

/**
 * Stores in a LimitCoords struct the max coordinate values of map graph g
 */
LimitCoords getLimitCoords(Graph<unsigned> g);
int resizeLat(double lat, LimitCoords l, float windowH);
int resizeLong(double lon, LimitCoords l, float windowW);

#endif /* SRC_EASYPILOT_H_ */
