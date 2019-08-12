#include<iostream>
#include<iterator>
#include<fstream>
#include<list>
#include<map>
using namespace std;
#define NONE ':'
#define LEFT 1
#define RIGHT 2
#define NOSIDE -1
ofstream file__;

struct vertex {
    char root;
    char left;
    char righ;
};

class BinaryTree {
    private:
        int nRootsRema;
        char mainRoot;
        map<char, vertex> vertices;
        string prOrd;
        string inOrd;
        char* rootsRemanningPr;
        char* rootsRemanningIn;
    public:
        BinaryTree(string ver, string inOrd);
        char getMainRoot();
        void buildTree();
        void travelPoOrd(char ver);   
        void printTree(); 
        int whichSide(char root, char desc, bool forRoots);
};

void BinaryTree::printTree() {
    file__ << endl;
    file__ << "at printTree()" << endl;
    file__ << "mainRoot = " << mainRoot << endl;
    file__ << "prOrd = " << prOrd << endl;
    file__ << "inOrd = " << inOrd << endl;
    map<char, vertex>::iterator itr;
    file__ << "\nThe map vertices is : \n"; 
    file__ << "\tKEY\tELEMENT\n"; 
    for (itr = vertices.begin(); itr != vertices.end(); ++itr) { 
        file__ << '\t' << itr->first 
                     << '\t' << itr->second.root
                     << '\t' << itr->second.left
                     << '\t' << itr->second.righ << '\n';
    } 
    file__ << endl;  
}

BinaryTree::BinaryTree(string prOrdStr, string inOrdStr) {
    mainRoot = prOrdStr[0];
    nRootsRema = prOrdStr.length();
    for (int i = 0; i < prOrdStr.length(); i++) {
        vertex ver;
        ver.root = NONE;
        ver.left = NONE;
        ver.righ = NONE;
        vertices.insert(pair <char, vertex> (prOrdStr[i], ver));
    }
    prOrd = prOrdStr;
    inOrd = inOrdStr;
}

void BinaryTree::travelPoOrd(char ver) {
    if (vertices[ver].left != NONE) travelPoOrd(vertices[ver].left);
    if (vertices[ver].righ != NONE) travelPoOrd(vertices[ver].righ);
    cout << ver;
    file__ << ver;
}

int BinaryTree::whichSide(char root, char desc, bool forRoots) {
    file__ << endl;
    file__ << "at whichSide(root = " << root << ", desc = " << desc << ", forRoots = " << forRoots << endl;
    int i;
    int size;
    if (forRoots == false) {
        size = inOrd.length();
        for (i = 0; i < size; i++) {
        if (inOrd[i] == root) break;
        }
        if (i > 0 and inOrd[i - 1] == desc) return LEFT;
        else if (i < size - 1 and inOrd[i + 1] == desc) return RIGHT;
    }
    else {
        size = nRootsRema;
        for (i = 0; i < size; i++) {
        if (rootsRemanningIn[i] == root) break;
        }
        if (i > 0 and rootsRemanningIn[i - 1] == desc) return LEFT;
        else if (i < size - 1 and rootsRemanningIn[i + 1] == desc) return RIGHT;
    }
    return NOSIDE;
}

void BinaryTree::buildTree() {
    file__ << endl;
    file__ << "at buildTree" << endl;
    int size = prOrd.length();
    char tempRoot; vertex* tempRootPointer;
    char possiDesc; vertex* possiDescPointer;
    int side;

    file__ << "processing all vertex" << endl;
    for (int i = 0; i < size - 1; i++) {
        file__ << "i = " << i << endl;
        tempRoot = prOrd[i];
        file__ << "tempRoot = " << tempRoot << endl; 
        if (i < size - 1) {
            possiDesc = prOrd[i + 1];
            file__ << "possiDesc = " << possiDesc << endl;
            side = whichSide(tempRoot, possiDesc, false);
            file__ << "side = " << side << endl;
            tempRootPointer = &vertices[tempRoot];
            possiDescPointer = &vertices[possiDesc];

            if (side == LEFT) {
                tempRootPointer->left = possiDesc;
                possiDescPointer->root = tempRoot;
                nRootsRema--;
            }
            else if (side == RIGHT) {
                tempRootPointer->righ = possiDesc;
                possiDescPointer->root = tempRoot;
                nRootsRema--;
            }
        }
        if (i < size - 2) {
            possiDesc = prOrd[i + 2];
            side = whichSide(tempRoot, possiDesc, false);
            file__ << "side = " << side << endl;
            tempRootPointer = &vertices[tempRoot];
            possiDescPointer = &vertices[possiDesc];

            if (side == LEFT) {
                tempRootPointer->left = possiDesc;
                possiDescPointer->root = tempRoot;
                nRootsRema--;
            }
            else if (side == RIGHT) {
                tempRootPointer->righ = possiDesc;
                possiDescPointer->root = tempRoot;
                nRootsRema--;
            }
        }
        file__ << "checking if Tree has chaged acording to the return of side" << endl;
        printTree();
    }

    rootsRemanningPr = new char[nRootsRema];
    rootsRemanningIn = new char[nRootsRema];
    int c = -1;
    file__ << "rootsRemanningPr = ";
    for (int i = 0; i < size; i++) {
        if (vertices[prOrd[i]].root == NONE) {
            rootsRemanningPr[++c] = prOrd[i];
            file__ << rootsRemanningPr[c];
        }
    }
    file__ << endl;
    c = -1;
    file__ << "rootsRemanningIn = ";
    for (int i = 0; i < size; i++) {
        if (vertices[inOrd[i]].root == NONE) {
            rootsRemanningIn[++c] = inOrd[i];
            file__ << rootsRemanningPr[c];
        }
    }
    file__ << endl;

    size = nRootsRema;
    for (int i = 0; i < size - 1; i++) {
        tempRoot = rootsRemanningPr[i];
        if (i < size - 1) {
            possiDesc = rootsRemanningPr[i + 1];
            side = whichSide(tempRoot, possiDesc, true);
            file__ << "side = " << side << endl;
            tempRootPointer = &vertices[tempRoot];
            possiDescPointer = &vertices[possiDesc];

            if (side == LEFT) {
                tempRootPointer->left = possiDesc;
                possiDescPointer->root = tempRoot;
            }
            else if (side == RIGHT) {
                tempRootPointer->righ = possiDesc;
                possiDescPointer->root = tempRoot;
            }
        }
        if (i < size - 2) {
            possiDesc = rootsRemanningPr[i + 2];
            side = whichSide(tempRoot, possiDesc, true);
            file__ << "side = " << side << endl;
            tempRootPointer = &vertices[tempRoot];
            possiDescPointer = &vertices[possiDesc];

            if (side == LEFT) {
                tempRootPointer->left = possiDesc;
                possiDescPointer->root = tempRoot;
            }
            else if (side == RIGHT) {
                tempRootPointer->righ = possiDesc;
                possiDescPointer->root = tempRoot;
            }
        }
        file__ << "checking if Tree has chaged acording to the return of side" << endl;
        printTree();
    }
}

char BinaryTree::getMainRoot() {
    return mainRoot;
}

int main () {
    file__.open("PrefixaInfixaPosfixa_Output.txt");
    int nCases;
    int quantVer;
    string prOrd;
    string inOrd;
    string poOrd;
    cin >> nCases;
    for (int i = 0; i < nCases; i++) {
        cin >> quantVer; cin >> prOrd; cin >> inOrd;
        // test input (state: working fine)
        file__ << endl;
        file__ << "at input()" << endl;
        file__ << "quantVer = " << quantVer << endl;
        file__ << "prOrd = " << prOrd << endl;
        file__ << "inOrd = " << inOrd << endl;
        BinaryTree binaryTree = BinaryTree(prOrd, inOrd);
        file__ << "checking if tree was correctly initialized ...";
        binaryTree.printTree(); // test constructor (state: wrokinf fine)
        binaryTree.buildTree();
        binaryTree.printTree();
        binaryTree.travelPoOrd(binaryTree.getMainRoot());
        cout << endl;
        file__ << endl;
    }
    file__.close();
    return 0;
}