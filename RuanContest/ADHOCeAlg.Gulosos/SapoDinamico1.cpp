#include<iostream> 

using namespace std;

#define small 'S'
#define big 'B'

struct Pedra {
    bool podePular;
    char tipo;
    int distMargenEsq;
};

int pular(Pedra* pedraAtual, Pedra* pedraSeguinte) {
    int tamanhoDoSalto = -1;
    if (pedraSeguinte->podePular == true) {
        tamanhoDoSalto = abs(pedraAtual->distMargenEsq - pedraSeguinte->distMargenEsq);
        if (pedraSeguinte->tipo == small) pedraSeguinte->podePular = false;
    }
    return tamanhoDoSalto;
}

int biggerSmallestJump(Pedra* pedras, int lengthPedras) {
    // verificando se a entrada esta correta 
    /*for (int i = 0; i < lengthPedras; i++) {
        std::cout << pedras[i].distMargenEsq << endl;
        std::cout << pedras[i].tipo << endl;
        std::cout << pedras[i].podePular << endl << endl;
    }*/  
    // verificando se a entrada esta correta
    int bigger = 0;
    int value;
    // indo 
    int indo = 0;
    int ultimoIndex = lengthPedras - 1;
    Pedra pedraAtual, pedraSeguinte;
    while (indo < ultimoIndex) {
        pedraAtual = pedras[indo];
        pedraSeguinte = pedras[indo + 1];
        if (pedraSeguinte.tipo == big) {
            indo++;
            value = pular(&pedraAtual, &pedras[indo]);
        }
        else if (pedraSeguinte.tipo == small) {
            indo += 2;
            value = pular(&pedraAtual, &pedras[indo]);
        }
        if (value < 0) std::cout << "deu merda" << endl;
        else if (value > bigger) bigger = value;
    }
    // voltando
    int voltando = ultimoIndex;
    while (voltando > 0) {
        pedraAtual = pedras[voltando];
        pedraSeguinte = pedras[voltando - 1];
        if (pedraSeguinte.tipo == big) {
            voltando--;
            value = pular(&pedraAtual, &pedras[voltando]);
        }
        else if (pedraSeguinte.tipo == small) {
            if (pedraSeguinte.podePular == true) {
                voltando -= 1;
                value = pular(&pedraAtual, &pedras[voltando]);
            }
            else {
                voltando -= 2;
                value = pular(&pedraAtual, &pedras[voltando]);
            }
        }
        if (value < 0) std::cout << "deu merda" << endl;
        else if (value > bigger) bigger = value;
    }
    return bigger;
}

int main() {
    int nCasos, counterCasos = 0, resposta;
    int nPedras, difMargens, numCounter, inputCounter;
    string* input;
    Pedra* pedras;
    cin >> nCasos;
    for (int i = 0; i < nCasos; i++) {
        cin >> nPedras >> difMargens;
        // lista para as pedras + lista das entradas para as pedras
        pedras = new Pedra[nPedras + 2];
        input = new string[nPedras];
        // lista para as pedras + lista das entradas para as pedras
        // setanda as margens
        pedras[0].tipo = big;
        pedras[0].podePular = true;
        pedras[0].distMargenEsq = 0;
        pedras[nPedras + 2 - 1].tipo = big;
        pedras[nPedras + 2 - 1].podePular = true;
        pedras[nPedras + 2 - 1].distMargenEsq = difMargens;
        // setando as margens
        // for para entradas
        for (int j = 0; j < nPedras; j++) {
            cin >> input[j];
        }
        // for para entradas
        // for para setar todas as pedras das entradas
        inputCounter = 0;
        for (int j = 1; j < nPedras + 1; j++) {
            pedras[j].tipo = input[inputCounter][0];
            pedras[j].podePular = true;
            char num[input[inputCounter].length() - 2];
            numCounter = 0;
            for (int z = 2; z < input[inputCounter].length(); z++) {
                num[numCounter] = input[inputCounter][z];
                numCounter++;
            }
            pedras[j].distMargenEsq = atoi(num);
            inputCounter++;
        }
        // for para setar todas as pedras das entradas
        resposta = biggerSmallestJump(pedras, nPedras + 2);
        std::cout << "Case " << ++counterCasos << ": " << resposta << endl;
    }
    return 0;
}