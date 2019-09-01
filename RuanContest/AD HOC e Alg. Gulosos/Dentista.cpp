#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

struct consulta {
    int inicio, fim;
};

bool compare(consulta c1, consulta c2) {
    if (c1.fim > c2.fim) return false;
    return true;
}

int main() {
    int quantConsultas;
    consulta* consultas;
    cin >> quantConsultas;
    consultas = new consulta[quantConsultas];
    for (int con = 0; con < quantConsultas; con++) {
        cin >> consultas[con].inicio >> consultas[con].fim;
    }
    sort(consultas, consultas + quantConsultas, compare);
    // printando as consultas para ver se elas estão ordenadas corretamente
    /*for (int i = 0; i < quantConsultas; i++) cout << consultas[i].dif << ", "; 
    cout << endl;*/
    int quantConsultasSeramFeitas = 1;
    int finalDaUltimaConsulta = consultas[0].fim;
    for (int con = 1; con < quantConsultas; con++) {
        if (consultas[con].inicio >= finalDaUltimaConsulta) {
            quantConsultasSeramFeitas++;
            finalDaUltimaConsulta = consultas[con].fim;
        }
    }
    cout << quantConsultasSeramFeitas << endl;
    return 0;
}