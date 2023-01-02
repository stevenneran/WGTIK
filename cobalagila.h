#ifndef COBALAGILA_H_INCLUDED
#define COBALAGILA_H_INCLUDED

#include <iostream>

#define nil NULL
#define infoNode(N) N->infoNode
#define child(N) N->child
#define nextNode(N) N->nextNode
#define infoEdge(E) E->infoEdge
#define bobot(E) E->bobot
#define nextEdge(E) E->nextEdge

using namespace std;

typedef char infotype;
typedef struct node *adrNode;
typedef struct edge *adrEdge;

struct node {
    infotype infoNode;
    adrEdge child;
    adrNode nextNode;
};

struct edge {
    infotype infoEdge;
    int bobot;
    adrEdge nextEdge;
};

adrNode newNode_1301210417(infotype X);
void addNode_1301210417(adrNode &G, adrNode P);
adrNode findNode_1301210417(adrNode G, infotype X);
void addEdge_1301210417(adrNode &G, infotype X, infotype Y, int bobot);
bool isConnected_1301210417(adrNode G, infotype X, infotype Y);
void printGraph_1301210417(adrNode G);

int outDegree(adrNode G, infotype X);
int inDegree(adrNode G, infotype X);
int getBobot(adrNode G, infotype X, infotype Y);
bool hasLoop(adrNode G, infotype X);
void printEdge(adrNode G);

#endif // COBALAGILA_H_INCLUDED
