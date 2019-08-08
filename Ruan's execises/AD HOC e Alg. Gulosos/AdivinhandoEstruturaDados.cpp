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
    file << "showlist" << endl;
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        file << '\t' << *it; 
    file << endl;
}

void showstack(stack <int> a) {   
    stack <int> s = a;
    file << "showstack" << endl;
    while (!s.empty()) { 
        file << '\t' << s.top(); 
        s.pop(); 
    } 
    file << endl; 
}

void showqueue(queue <int> a) {   
    queue <int> s = a;
    file << "showqueue" << endl;
    while (!s.empty()) { 
        file << '\t' << s.front(); 
        s.pop(); 
    } 
    file << endl; 
}

void showpriority_queue(priority_queue <int> a) {   
    priority_queue <int> s = a;
    file << "showpriority_queue" << endl;
    while (!s.empty()) { 
        file << '\t' << s.top(); 
        s.pop(); 
    } 
    file << endl; 
}

bool equals(list<int>* lis1, list<int>* lis2) {
    file << "at equals" << endl;
    file << "lis1 = ";
    showlist(*lis1);
    file << "lis2 = ";
    showlist(*lis2);
    if (lis1->size() != lis2->size()) {
        file << "returned false, cause lists got diferent sizes" << endl;
        return false;
    }
    list <int> :: iterator it1 = lis1->begin(); 
    list <int> :: iterator it2 = lis2->begin();
    while (it1 != lis1->end() and it2 != lis2->end()) {
        file << "the values that are been compared are, from lis1 = " << *it1 << ", and from lis2 = " << *it2 << endl;
        if (*it1 != *it2) {
            file << "returned false, cause " << *it1 << " != " << *it2 << endl;
            return false;
        }
        it1++; it2++;
    }
    file << "returned true, cause all the elements were identical" << endl;
    return true;
}

string match(stack<int>* pilha, queue<int>* fila, priority_queue<int>* filaPrioridade, list<int>* output, int quantRemoved) {
    string out = "impossible";
    int popCounter = 0;
    int notSureCounter = 0;
    list<int> forPilha; 
    list<int> forFila; 
    list<int> forFilaPrioridade; 
    while (popCounter < quantRemoved){
        forPilha.push_back(pilha->top());
        forFila.push_back( fila->front());
        forFilaPrioridade.push_back(filaPrioridade->top());
        pilha->pop();
        fila->pop();
        filaPrioridade->pop();
        popCounter++;
    }

    file << "output = " << endl;
    showlist(*output);
    file << "list from Pilha = " << endl;
    showlist(forPilha);
    file << "list from Fila = " << endl;
    showlist(forFila); 
    file << "list from FilaPrioridade = " << endl;
    showlist(forFilaPrioridade); 

    if (equals(output, &forPilha) == true) {
        file << "it is a stack, cause output were equals to forPilha" << endl;
        notSureCounter++;
        out = "stack";
    }
    if (equals(output, &forFila) == true) {
        file << "it is a queue, cause output were equals to forFila" << endl;
        notSureCounter++;
        out = "queue";
    }
    if (equals(output, &forFilaPrioridade) == true) {
        file << "it is a priority_queue, cause output were equals to forFilaPrioridade" << endl;
        notSureCounter++;
        out = "priority queue";
    }
    if (notSureCounter > 1) out = "not sure";
    return out;
}

int main() {
    file.open("txtsFiles\\testingeachpart");
    int nCases;
    int comandType, cons, qunatRemoved;
    int counter = 0;
    string dataStrucut;
    while (scanf("%d", &nCases) != EOF) {
        file << "CASE " << ++counter << ':' << endl;
        qunatRemoved = 0;
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
            else if (comandType == rem) {
                output.push_back(cons);
                qunatRemoved++;
            }
        }
        dataStrucut = match(&pilha, &fila, &filaPrioridade, &output, qunatRemoved);
        /*file << "before calling the judg" << endl;
        file << "output = ";
        showlist(output);
        file << "pilha = ";
        showstack(pilha);
        file << "fila = ";
        showqueue(fila);
        file << "filaPrioridade = ";
        showpriority_queue(filaPrioridade);*/
        cout << dataStrucut << endl;
        file << "answer = " << dataStrucut << endl;
        file << "=======================================" << endl;
    }
    file.close();
    return 0;
}