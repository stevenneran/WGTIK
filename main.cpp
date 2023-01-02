#include "cobalagila.h"

int main() {
    adrNode G = nil, NO;

    NO = newNode_1301210417('A');
    addNode_1301210417(G, NO);
    NO = newNode_1301210417('B');
    addNode_1301210417(G, NO);
    NO = newNode_1301210417('C');
    addNode_1301210417(G, NO);
    NO = newNode_1301210417('D');
    addNode_1301210417(G, NO);

    addEdge_1301210417(G, 'A', 'C', 15);
    addEdge_1301210417(G, 'A', 'D', 25);
    addEdge_1301210417(G, 'B', 'A', 30);
    addEdge_1301210417(G, 'C', 'C', 5);
    addEdge_1301210417(G, 'D', 'A', 15);
    addEdge_1301210417(G, 'D', 'B', 15);

    printGraph_1301210417(G);

    cout << "inDegree(A): " << inDegree(G, 'A') << "; outDegree(A): " << outDegree(G, 'A') << endl;
    cout << "inDegree(B): " << inDegree(G, 'B') << "; outDegree(B): " << outDegree(G, 'B') << endl;
    cout << "inDegree(C): " << inDegree(G, 'C') << "; outDegree(C): " << outDegree(G, 'C') << endl;
    cout << "inDegree(D): " << inDegree(G, 'D') << "; outDegree(D): " << outDegree(G, 'D') << endl << endl;

    cout << "node A has loop? " << boolalpha << hasLoop(G, 'A') << endl;
    cout << "node B has loop? " << hasLoop(G, 'B') << endl;
    cout << "node C has loop? " << hasLoop(G, 'C') << endl;
    cout << "node D has loop? " << hasLoop(G, 'D') << endl << endl;

    printEdge(G);

    return 0;
}
