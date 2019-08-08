#include<iostream>
#include<fstream>
#include<stack>
#include<queue>
#include<list>

using namespace std;

ofstream file;

#define add 1
#define rem 2

void showlist(list <int> g) { 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it;
        file << '\t' << *it; 
    cout << '\n'; 
    file << endl;
} 

bool equals(list<int>* lis1, list<int>* lis2) {
    cout << "at equals" << endl;
    file << "at equals" << endl;
    cout << "lis1 = ";
    file << "lis1 = ";
    showlist(*lis1);
    cout << "lis2 = ";
    file << "lis2 = ";
    showlist(*lis2);
    if (lis1->size() != lis2->size()) {
        cout << "returned false, cause lists got diferent sizes" << endl;
        file << "returned false, cause lists got diferent sizes" << endl;
        return false;
    }
    list <int> :: iterator it1 = lis1->begin(); 
    list <int> :: iterator it2 = lis2->begin();
    while (it1 != lis1->end() and it2 != lis2->end()) {
        it1++; it2++;
        if (*it1 != *it2) {
            cout << "returned false, cause " << *it1 << " != " << *it2 << endl;
            file << "returned false, cause " << *it1 << " != " << *it2 << endl;
            return false;
        }
    }
    cout << "returned true, cause all the elements were identical" << endl;
    file << "returned true, cause all the elements were identical" << endl;
    return true;
}

string match(stack<int>* pilha, queue<int>* fila, priority_queue<int>* filaPrioridade, list<int>* output) {
    string out = "impossible";
    int notSureCounter = 0;
    list<int> forPilha; 
    list<int> forFila; 
    list<int> forFilaPrioridade; 
    while (pilha->empty() != true){
        forPilha.push_back(pilha->top());
        forFila.push_back( fila->front());
        forFilaPrioridade.push_back(filaPrioridade->top());
        pilha->pop();
        fila->pop();
        filaPrioridade->pop();
    }
    cout << "Pilha = ";
    file << "Pilha = " << pilha->size() << endl;
    cout << "Fila = ";
    file << "Fila = " << fila->size() << endl; 
    cout << "FilaPrioridade = ";
    file << "FilaPrioridade = " << filaPrioridade->size() << endl; 

    cout << "forPilha = ";
    file << "forPilha = ";
    showlist(forPilha);
    cout << "forFila = ";
    file << "forFila = "; 
    showlist(forFila);
    cout << "forFilaPrioridade = ";
    file << "forFilaPrioridade = ";
    showlist(forFilaPrioridade);
    cout << "output = ";
    file << "output = ";
    showlist(*output);
    if (equals(output, &forPilha) == true) {
        notSureCounter++;
        out = "stack";
    }
    if (equals(output, &forFila) == true) {
        notSureCounter++;
        out = "queue";
    }
    if (equals(output, &forFilaPrioridade) == true) {
        notSureCounter++;
        out = "priority queue";
    }
    if (notSureCounter > 1) out = "not sure";
    return out;
}

int main() {
    file.open("txtsFiles\\log");
    int nCases;
    int comandType, cons;
    string dataStrucut;
    while (scanf("%d", &nCases) != EOF) {
        stack<int> pilha;
        queue<int> fila;
        priority_queue<int> filaPrioridade;
        list<int> output;
        for (int i = 0; i < nCases; i++) {
            cin >> comandType >>  cons;
            if (comandType == add) {
                pilha.push(cons);
                fila.push(cons);
                filaPrioridade.push(cons);
            }
            else if (comandType == rem) output.push_back(cons);
        }
        dataStrucut = match(&pilha, &fila, &filaPrioridade, &output);
        cout << dataStrucut << endl;
        file << dataStrucut << endl;
    }
    file.close();
    return 0;
}