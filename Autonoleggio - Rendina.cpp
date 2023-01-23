#include <iostream>
#include <fstream>
#include <string>

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

void riempi_vet(auton autovett, auton vet[])
{
    ifstream fin(FILE_NAME,ios::in);

    string app;
    while(!fin.eof())
    {
        getline(fin,app);
        for(int i=0; i<7; i++)
        {
            fin>>vet[i].categoria>>vet[i].marca>>vet[i].modello>>vet[i].colore;
            for(int k=0; k<7; k++)
                fin>>vet[i].g[k];
        }
    }
    fin.close();
}

void stampa_catalogo(auton autovett, auton *ptr_auto, auton vet[])
{
    int i = 0;
    fstream fin(FILE_NAME, ios::in);
    cin.ignore();
    string appoggio = "";

    system("cls");
    cout<<"\t\t\t\t\t CATALOGO\n"<<endl;

    while(!fin.eof())
    {
        cout<<"\tVETTURA N."<<i+1<<": ";
        getline(fin, appoggio);
        cout<<appoggio<<endl<<endl;

        i++;
    }
    fin.close();
}

void findA(auton vet[], string sett, string g, int cont)
{
    for(int i=0; i<7; i++){
        if(g == sett){
            if(vet[i].g[cont] == "L"){
                cout<<endl<<vet[i].marca<<" "<<vet[i].modello<<" "<<vet[i].colore<<" ";
            }
        }
    }
}

void cerca_vettura(auton autovett, auton vet[])
{

  //  ifstream fin(FILE_NAME, ios::in);
    string cate;

    cout<<"Inserire categoria dell'auto: ";
    cin>>cate;
    if(cate!="utilitaria" && cate!="lusso" && cate!="sportiva" && cate!="furgone")
        cout<<"Categoria non esistente\n";
    else{
        string g, sett_vet[]{"Lunedì", "Martedì", "Mercoledì", "Giovedì", "Venerdì", "Sabato", "Domenica"};
        cout<<"Inserire giorno da prenotare: ";
        cin>>g;

        if(cate == "utilitaria"){
            for(int k=0; k<7; k++)
                findA(vet, sett_vet[k], g, k);
        }
        if(cate == "lusso"){
            for(int k=0; k<7; k++)
                findA(vet, sett_vet[k], g, k);
        }
        if(cate == "sportiva"){
            for(int k=0; k<7; k++)
                findA(vet, sett_vet[k], g, k);
        }
        if(cate == "furgone"){
            for(int k=0; k<7; k++)
                findA(vet, sett_vet[k], g, k);
        }
    }

}

void menu()
{
    auton autovett, *ptr_auto = &autovett, vet[20], *ptr_vet = vet;
    int scelta;

    riempi_vet(autovett, vet);
    cout<<"\n\t\tMENU'"<<endl;
    cout<<"1 - Consulta catalogo"<<endl
        <<"2 - Ricerca vettura"<<endl;

    cin>>scelta;
    switch(scelta){
        case 1: stampa_catalogo(autovett, ptr_auto, vet);
                break;
        case 2: cerca_vettura(autovett, vet);
    }
}

int main()
{
    menu();
    return 0;
}
