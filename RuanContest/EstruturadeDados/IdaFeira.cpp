#include<iostream>

using namespace std;

struct Produto {
    string name;
    double price;
};

double price(Produto* produtos, int length, string name, int quant) {
    for (int i = 0; i < length; i++) {
        if (produtos[i].name == name) {
            // cout << "produtos[i].name = " << produtos[i].name << " == " << "name = " << name << endl;
            // cout << "return value = " << (produtos[i].price * quant) << endl;
            return (produtos[i].price * quant);
        }
    }
    // cout << "naõ encontrou o produto" << endl;
    return -1;
}

int main() {
    int nCases, nProdutsDisponible, nProdutsBougth;
    string productName;
    int quantProduct;
    double total;
    Produto* produtos;
    cin >> nCases;
    for (int n = 0; n < nCases; n++) {
        total = 0;
        cin >> nProdutsDisponible;
        produtos = new Produto[nProdutsDisponible];
        for (int np = 0; np < nProdutsDisponible; np++) {
            cin >> produtos[np].name >> produtos[np].price;
            // cout << produtos[np].name << produtos[np].price << endl;
        }
        cin >> nProdutsBougth;
        for (int np = 0; np < nProdutsBougth; np++) {
            cin >> productName >> quantProduct;
//            cout << productName << quantProduct << endl;
            total += price(produtos, nProdutsDisponible, productName, quantProduct);
            // cout << "total = " << total << endl;
        }
        // cout << "R$ " << total << endl;
        printf("R$ %.2lf\n", total);
    }
    return 0;
}