#include <iostream>
#include <vector>
#include <fstream>
#include <regex>

using namespace std;

struct uczen
{
        string imie, nazwisko, status;
        int numer;
};

class klasa
{
                vector <struct uczen> spis;
       
        public:
                void zapiszDoPliku(const char *);
                void wczytajZPliku(const char *);                
};

void klasa::wczytajZPliku(const char *nazwa){
	ifstream plik1;
	struct uczen wprowadzany;
	regex imie("[A-Z]{1}[a-z]+");
	regex nazwisko("[A-Z]{1}[a-z]+");
	plik1.open(nazwa);
	while(!plik1.eof()){
		plik1>>wprowadzany.numer>>wprowadzany.imie>>wprowadzany.nazwisko;
		if(regex_match(wprowadzany.imie, imie) && regex_match(wprowadzany.nazwisko, nazwisko)){
			wprowadzany.status = "OK";
		} else {
			wprowadzany.status = "ERROR";
		}
		spis.push_back(wprowadzany);
	}
	
	
}

void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik2;
        plik2.open(nazwa);
        plik2<<"["<<endl;
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                plik2<<"{\"nr\":\""<<it->numer<<"\", \"imie\":\""<<it->imie<<"\", \"nazwisko\":\""<<it->nazwisko<<"\", \"status\":\""<<it->status<<"\"}\n";
        }
        plik2<<"]";
         
}



int main(int argc, char** argv) {
        klasa TI;
//        TI.wprowadz();
//        TI.wypisz();
		TI.wczytajZPliku("c:\\od.txt");	
        TI.zapiszDoPliku("c:\\do.txt");
        
        return 0;
}


