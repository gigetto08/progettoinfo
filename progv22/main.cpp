#include <iostream>
#include <fstream>
#include <list>
#include <cstring>
#include <sstream>
#include <set>
using namespace std;
const string nomef="corsi_studenti.csv";
struct per{
    string descrizionemateria;
    string codicemateria;
    string codicecorso;
    string descrizionecorso;
    string matricola;
    string cognome;
    string nome;
};
list<per> u;

void caricadig1();
int findm2(string q);
int findco3(const string& key);
void findcod4(string cod,per kia[101]);
void findcorso5(string cod, per kia[101]);
int numero6(int c);
int main() {
    string f;
    int i = 0;
    string codice;
    per audi[101];

    caricadig1();

    cout << "Dimmi la matricola da cercare: ";
    cin >> f;
    int n = findm2(f);
    cout << "Posizione matricola: " << n << endl;

    cout << "Dimmi il cognome da cercare: ";
    cin >> f;
    int pos = findco3(f);
    if (pos != -1)
        cout << "Trovato alla posizione: " << pos << endl;
    else
        cout << "Cognome non trovato.\n";

    cout<<"Dimmi il codice del corso"<<endl;
    cin>>codice;
    findcod4(codice,audi);
    //da fare cout 5
    //6
    for(int i=0;i<3;i++){
    int porro=numero6(i);
    cout<<"ci sono "<<porro<<" studenti nel corso"<<i+1<<"\t";
    }
    cout<<endl;
    for(int i=0;i<3;i++){
    int porro=numero6(i);
    cout<<"ci sono "<<porro<<" materie nel corso"<<i+1<<"\t";
    }
    cout<<endl;

    return 0;
}

void caricadig1() {
    string line;
    per m;
    ifstream file(nomef);
    if (!file.is_open()) {
        cout << "Errore nell'aprire il file.\n";
        return;
    }
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, m.codicecorso, ',');
        getline(ss, m.descrizionecorso, ',');
        getline(ss, m.codicemateria, ',');
        getline(ss, m.descrizionemateria, ',');
        getline(ss, m.matricola, ',');
        getline(ss, m.cognome, ',');
        getline(ss, m.nome);
        u.push_back(m);
    }

    file.close();
}
void stampa_lista() {
    // Attraversa la lista e stampa i dettagli di ogni elemento
    for (const per& m : u) {
        cout << "Codice Corso: " << m.codicecorso << endl;
        cout << "Descrizione Corso: " << m.descrizionecorso << endl;
        cout << "Codice Materia: " << m.codicemateria << endl;
        cout << "Descrizione Materia: " << m.descrizionemateria << endl;
        cout << "Matricola: " << m.matricola << endl;
        cout << "Cognome: " << m.cognome << endl;
        cout << "Nome: " << m.nome << endl;
        cout << "--------------------------" << endl;
    }
}

int findm2(string q){
    int cont=-1;
    bool flag=false;
    for(per m : u){
        cont++;
        if(m.matricola==q){
            break;
            flag=true;
        }

    }
    if(flag)
    return cont;
    else
    return -1;
}

int findco3(const string& is) {
    int i = 0;
    for (const per& m : u) {
        if (m.cognome == is) {
            return i;
        }
        i++;
    }
    return -1;
}

void findcod4(string cod, per kia[101]) {
    int i = 0;
    set<pair<string, string>> addedStudents;
    for (auto it1 = u.begin(); it1 != u.end(); ++it1) {
        if (it1->codicecorso == cod) {

            pair<string, string> studentIdentifier = {it1->cognome, it1->nome};


            if (addedStudents.find(studentIdentifier) == addedStudents.end()) {

                kia[i] = *it1;
                addedStudents.insert(studentIdentifier);
                i++;
            }
        }
    }
}
void findcorso5(string cod, per kia[101]) {
    int i=0,j;
    for (auto it1 = u.begin(); it1 != u.end(); it1++) {
        if(it1->codicecorso==cod){
        kia[i]=*it1;
        i++;
        }
    }
}
int numero6(int c){
    int cont;
    string cod;
    if(c==0)
        cod="C001";
    else if(c==1)
        cod="C002";
    else
        cod="C003";
    for (auto it1 = u.begin(); it1 != u.end(); it1++){
        if(it1->codicecorso==cod){
        if(cont==0){
            cont++;
        }
        else{
            for (auto it2 = next(it1); it2 != u.end(); it2++) {
                if (it1->cognome == it2->cognome and it1->nome==it2->nome) {
                    cont--;
                    break;
                }
            }
        cont++;
        }
        }

    }
    return cont;
}
int math(int c){
    int cont = 0;
    string cod;
    if (c == 0)
        cod = "C001";
    else if (c == 1)
        cod = "C002";
    else
        cod = "C003";
    set<string> uniqueMaterie;

    for (auto it1 = u.begin(); it1 != u.end(); ++it1) {
        if (it1->codicecorso == cod) {
            if (uniqueMaterie.find(it1->codicemateria) == uniqueMaterie.end()) {
                uniqueMaterie.insert(it1->codicemateria);
                cont++;
            }
        }
    }

    return cont;
}

