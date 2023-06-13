#include<iostream>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std;


string matrica[6][6] = { "B", "2", "E", "5", "R","L" ,
		"I", "9", "N", "A", "1","C" ,
		"3", "D", "4", "F", "6","G" ,
		"7", "H", "8", "J", "0","K" ,
		"M", "O", "P", "Q", "S","T" ,
		"U", "V", "W", "X", "Y","Z" ,
};
char slova[6] = {'A',  'D',   'F', 'G', 'V','X' };

string slovo;

string Dekodiraj(vector<char> unos) {
	string slovo1, slovo2;
	int indeks1, indeks2;
	
	bool nasaoRed = false, nasaoKolonu = false;
	for (int i = 0; i < unos.size(); i += 2)
	{
		for (int j = 0; j < 6; j++)
		{
			if (unos[i] == slova[j]) {
				indeks1 = j;
				nasaoKolonu = true;
			}
			if (unos[i + 1] == slova[j]) {
				indeks2 = j;
				nasaoRed = true;
			}
			if (nasaoKolonu == true && nasaoRed == true) {
				slovo += matrica[indeks1][indeks2];

				break;
			}

		}
		nasaoKolonu = false; nasaoRed = false;
	}

	return slovo;
}

vector<char> Priprema(const string& tekst) {
	vector<char> pripremljeno;
	for (int i = 0; i < tekst.size();i++) {
		if(isspace(tekst[i])){
			break;
		}
		if (isalpha(tekst[i]) && !isspace(tekst[i])) {
			pripremljeno.push_back(toupper(tekst[i]));
		}
	}
	return pripremljeno;
}


int main() {
	//ispis matrice
	/*for (int i = 0; i <6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}*/
	string unos;
	cout << "UNESITE: " << endl;
	cin>>unos;
	vector<char> pripremljenTekst = Priprema(unos);
	//pripremljen tekst
	cout << "Pripremljen tekst: " << endl;
	for (int i = 0; i < pripremljenTekst.size(); i++)
	{
		cout << pripremljenTekst[i];
	}
	cout << endl;
	string dekodirano = Dekodiraj(pripremljenTekst);
	
	cout << "DEKODIRANO: " << endl;
	for (int i = 0; i < dekodirano.size(); i++)
	{
		cout << dekodirano[i];
	}
	
	return 0;
}