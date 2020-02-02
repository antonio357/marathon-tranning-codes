#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	double enfeites;
	double peso;
} pacote;

bool operator<(const pacote& p1, const pacote& p2) { // if true p1.>>>, if false p1.<<<
	if (!(p1.enfeites != p2.enfeites)) 
		return p1.enfeites < p2.enfeites;
	return p1.peso > p2.peso;
}

class Galho {

	private:
		int limit_weight; 
		int weight;
		int enfeites;
		priority_queue <pacote> pacotes_on;
		priority_queue <pacote> pacotes_out;
		priority_queue <pacote> pacotes_rmv;

	public:
		Galho(int limit_weight, priority_queue <pacote> pacotes_on) {
			this->limit_weight = limit_weight;
			this->pacotes_rmv = pacotes_on;
			this->weight = 0;
			this->enfeites = 0;
		}

		void initial_setting() {
			while (pacotes_rmv.size() > 0) {
				if (weight + pacotes_rmv.top().peso <= limit_weight) {
					pacotes_on.push(pacotes_rmv.top());
				} else pacotes_out.push(pacotes_rmv.top());
				pacotes_rmv.pop();
			}
		}

		int getEnfeites() {
			return this->enfeites;
		}

		void fitBetter() {
			while (pacotes_out.size() > 0){
				

				pacotes_rmv.push(pacotes_out.top());
				pacotes_out.pop();
			}
		}
};


int main() {
    double nCases, nPacotes, nEnfeites, Peso, pesoLimit;

	cin >> nCases;

	for (int i = 0; i < nCases; i++) {
		priority_queue <pacote> pacotes;
        double enfeitesCouter = 0, pesoCounter = 0;

		cin >> nPacotes;
		cin >> pesoLimit;

		for (int j = 0; j < nPacotes; j++) {
			cin >> nEnfeites >> Peso;

			pacote p = {nEnfeites, Peso};
			pacotes.push(p);
		}

		Galho galho = Galho(pesoLimit, pacotes);
		galho.initial_setting();
		galho.fitBetter();

		cout << "Galho " << i + 1 << ':' << endl;
		cout << "Numero total de enfeites: " << galho.getEnfeites() << endl << endl;
	}
	return 0;
}