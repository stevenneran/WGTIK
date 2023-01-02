#include "cobalagila.h"

adrNode newNode_1301210417(infotype X) {
    adrNode N = new node;

    infoNode(N) = X;
    child(N) = nil;
    nextNode(N) = nil;

    return N;
}

void addNode_1301210417(adrNode &G, adrNode P) {
    if (G==nil) {
        G = P;
    } else {
        adrNode readN = G;

        while (nextNode(readN)!=nil) {
            readN = nextNode(readN);
        }

        nextNode(readN) = P;
    }
}

adrNode findNode_1301210417(adrNode G, infotype X) {
    adrNode readN = G, foundN = nil;

    while (readN!=nil) {
        if (infoNode(readN)==X) {
            foundN = readN;
        }

        readN = nextNode(readN);
    }

    return foundN;
}

void addEdge_1301210417(adrNode &G, infotype X, infotype Y, int bobot) {
    if (G==nil) {
        cout << "Belum ada node pada graf; tidak bisa menambahkan edge." << endl;
    } else if (next(G)==nil) {
        cout << "Hanya ada satu node pada graf; kurang satu node lagi." << endl;
    } else {
        adrNode searchN = findNode_1301210417(G, X);
        adrNode searchM = findNode_1301210417(G, Y);

        if (searchN==nil && searchM==nil) {
            cout << "Kedua node tidak ditemukan" << endl;
        } else if (searchN==nil && searchM!=nil) {
            cout << "Node dengan info x tidak ditemukan" << endl;
        } else if (searchN!=nil && searchM==nil) {
            cout << "Node dengan info y tidak ditemukan" << endl;
        } else {
            adrEdge ENM = new edge;

            infoEdge(ENM) = infoNode(searchM);
            bobot(ENM) = bobot;
            nextEdge(ENM) = nil;

            if (child(searchN)==nil) {
                child(searchN) = ENM;
            } else {
                adrEdge readE = child(searchN);

                while (nextEdge(readE)!=nil) {
                    readE = nextEdge(readE);
                }

                nextEdge(readE) = ENM;
            }
        }
    }
}

bool isConnected_1301210417(adrNode G, infotype X, infotype Y) {
    bool found = false;

    adrNode searchN = findNode_1301210417(G, X);
    adrEdge readE = child(searchN);

    while (!found && readE!=nil) {
        found = infoEdge(readE)==Y;
        readE = nextEdge(readE);
    }

    return found;
}

void printGraph_1301210417(adrNode G) {
    if (G==nil) {
        cout << "Belum ada node pada graf; tidak ada yang bisa ditampilkan." << endl;
    } else {
        adrNode readN = G;
        adrEdge readE;

        cout << "==============================" << endl;

        while (readN!=nil) {
            cout << "node " << infoNode(readN) << ":";

            readE = child(readN);

            while (readE!=nil) {
                cout << " - " << infoEdge(readE);

                readE = nextEdge(readE);
            }

            readN = nextNode(readN);

            cout << endl;
        }

        cout << "==============================" << endl;
    }

    cout << endl;
}

int outDegree(adrNode G, infotype X) {
    adrNode searchN = findNode_1301210417(G, X);
    adrEdge readE = child(searchN);
    int numberOfOD = 0;

    while (readE!=nil) {
        numberOfOD++;
        readE = nextEdge(readE);
    }

    return numberOfOD;
}

int inDegree(adrNode G, infotype X) {
    adrNode readN = G;
    adrEdge readE;
    int numberOfID = 0;

    while (readN!=nil) {
        readE = child(readN);

        while (readE!=nil) {
            if (infoEdge(readE)==X) {
                numberOfID++;
            }

            readE = nextEdge(readE);
        }

        readN = nextNode(readN);
    }

    return numberOfID;
}

int getBobot(adrNode G, infotype X, infotype Y) {
    int weight = 0;

    if (isConnected_1301210417(G, X, Y)) {
        adrNode searchN = findNode_1301210417(G, X);
        adrEdge readE = child(searchN);

        while (readE!=nil) {
            if (infoEdge(readE)==Y) {
                weight = bobot(readE);
            }

            readE = nextEdge(readE);
        }
    }

    return weight;
}

bool hasLoop(adrNode G, infotype X) {
    return (isConnected_1301210417(G, X, X));
}

void printEdge(adrNode G) {
    adrNode readN = G;
    adrEdge readE;
    int numberOfE = 0;

    while (readN!=nil) {
        readE = child(readN);

        while (readE!=nil) {
            numberOfE++;

            cout << "edge " << numberOfE << ": "  << infoNode(readN) << " - " << infoEdge(readE) << " berbobot " << bobot(readE) << endl;

            readE = nextEdge(readE);
        }

        readN = nextNode(readN);
    }
}
