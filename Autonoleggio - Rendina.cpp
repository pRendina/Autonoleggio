#include <iostream>
#include <fstream>

#define FILE_NAME "Auto.csv"

using namespace std;

struct auton{
    string categoria;
    string marca;
    string modello;
    string colore;
    string g[7];
    bool free;
};

void riempi_vet(auton autovett, auton vet[], auton *ptr_vet)
{
    ifstream fin(FILE_NAME, ios::in);
    int i = 0;

    while(!fin.eof()){
        getline(fin, (ptr_vet+i)->categoria, ',');

        //cout<<vet[i].categoria<<" ";

        getline(fin, (ptr_vet+i)->marca, ',');
       // cout<<vet[i].marca<<" ";

        getline(fin, (ptr_vet+i)->modello, ',');
       // cout<<vet[i].modello<<" ";

        getline(fin, (ptr_vet+i)->colore, ',');
       // cout<<vet[i].colore<<endl;

        for(int k=0; k<7; k++){
            getline(fin, (ptr_vet+i)->g[k], ',');
        }
    i++;

    }
}

void stampa_catalogo(auton autovett, auton *ptr_auto, auton vet[])
{
    int i = 0;
    fstream fin(FILE_NAME, ios::in);
    cin.ignore();
    string appoggio = "";

    while(!fin.eof())
    {
        cout<<"VETTURA N."<<i+1<<": ";
        getline(fin, appoggio);
        cout<<appoggio<<endl<<endl;

        i++;
    }
    fin.close();
}

void menu()
{
    auton autovett, *ptr_auto = &autovett, vet[20], *ptr_vet = vet;
    int scelta;

    riempi_vet(autovett, vet, ptr_vet);

    cout<<"\n\t\tMENU'"<<endl;
    cout<<"1 - Consulta catalogo"<<endl
        <<"2 - Ricerca vettura"<<endl;

    cin>>scelta;
    switch(scelta){
        case 1: stampa_catalogo(autovett, ptr_auto, vet);
                break;
    }
}

int main()
{
    menu();
    return 0;
}
