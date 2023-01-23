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
    string lun,mar,mer,gio,ven,sab,dom;
    bool free;
};

int sizee()
{
    ifstream fin(FILE_NAME, ios::app);
    string app;
    int i = 0;
    while(getline(fin, app))
        i++;
    fin.close();
    return i;
}

void riempi_vet(auton autovett, auton vet[])
{
    ifstream fin(FILE_NAME,ios::in);
    int i = 0;
    while(!fin.eof())
    {
        getline(fin,vet[i].categoria, ',');
        getline(fin,vet[i].marca, ',');
        getline(fin,vet[i].modello, ',');
        getline(fin,vet[i].colore, ',');

        getline(fin,vet[i].lun, ',');
        getline(fin,vet[i].mar, ',');
        getline(fin,vet[i].mer, ',');
        getline(fin,vet[i].gio, ',');
        getline(fin,vet[i].ven, ',');
        getline(fin,vet[i].sab, ',');
        getline(fin,vet[i].dom);
        i++;
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

void cambia_file(auton vet[])
{

}

void findA(auton vet[], string cate)
{
    string sett_vet[]{"Lunedì", "Martedì", "Mercoledì", "Giovedì", "Venerdì", "Sabato", "Domenica"};
    for(int i=0; i<sizee(); i++){
        if(vet[i].categoria == cate){
            cout<<i+1<<") ";
            cout<<vet[i].marca<<" "<<vet[i].modello<<" "<<vet[i].colore;
            cout<<"\n\tDisponibilita':\n"<<
            "\t\tLunedi': "<<vet[i].lun<<
            "\n\t\tMartedi': "<<vet[i].mar<<
            "\n\t\tMercoledi': "<<vet[i].mer<<
            "\n\t\tGiovedi': "<<vet[i].gio<<
            "\n\t\tVenerdi': "<<vet[i].ven<<
            "\n\t\tSabato: "<<vet[i].sab<<
            "\n\t\tDomenica: "<<vet[i].dom<<endl<<endl;
        }
    }

    int select,cont = 0;;
    cout<<"Inserire macchina da selezionare: ";
    cin>>select;

    string g[7];
    do{
        cout<<"\nInserire giorni da prenotare (inserire ESCI per uscire): ";
        cin>>g[cont];
        cont++;
    }while(g[cont-1] != "ESCI");

    for(int i=0; i<7; i++){
        if(g[i]=="") break;

        if(g[i] == sett_vet[i]){
            if(vet[select-1].lun == "A")
                cout<<"Macchina occupata quel giorno\n";
            else cambia_file(vet);
        }

        if(g[i] == sett_vet[i]){
            if(vet[select-1].mar == "A")
                cout<<"Macchina occupata quel giorno\n";
            else cambia_file(vet);
        }

        if(g[i] == sett_vet[i]){
            if(vet[select-1].mer == "A")
                cout<<"Macchina occupata quel giorno\n";
            else cambia_file(vet);
        }

        if(g[i] == sett_vet[i]){
            if(vet[select-1].gio == "A")
                cout<<"Macchina occupata quel giorno\n";
            else cambia_file(vet);
        }

        if(g[i] == sett_vet[i]){
            if(vet[select-1].ven == "A")
                cout<<"Macchina occupata quel giorno\n";
            else cambia_file(vet);
        }

        if(g[i] == sett_vet[i]){
            if(vet[select-1].sab == "A")
                cout<<"Macchina occupata quel giorno\n";
            else cambia_file(vet);
        }

        if(g[i] == sett_vet[i]){
            if(vet[select-1].dom == "A")
                cout<<"Macchina occupata quel giorno\n";
            else cambia_file(vet);
        }

    }

}

void cerca_vettura(auton autovett, auton vet[])
{
    string cate;

    cout<<"Inserire categoria dell'auto: ";
    cin>>cate;
    if(cate!="utilitaria" && cate!="lusso" && cate!="sportiva" && cate!="furgone")
        cout<<"Categoria non esistente\n";
    else{
        if(cate == "utilitaria"){
            findA(vet, cate);
        }
        if(cate == "lusso"){
            findA(vet, cate);
        }
        if(cate == "sportiva"){
            findA(vet, cate);
        }
        if(cate == "furgone"){
            findA(vet, cate);
        }
    }
}

void menu()
{
    auton autovett, *ptr_auto = &autovett, vet[20], *ptr_vet = vet;
    int scelta;

    riempi_vet(autovett, vet);
    while(scelta!=3){
        cout<<"\n\t\tMENU'"<<endl;
        cout<<"1 - Consulta catalogo"<<endl
            <<"2 - Ricerca vettura"<<endl
            <<"3 - Uscita"<<endl;

        cin>>scelta;
        switch(scelta){
            case 1: stampa_catalogo(autovett, ptr_auto, vet);
                    break;
            case 2: cerca_vettura(autovett, vet);
                    break;
            case 3: cout<<"USCITA...";
                    break;
            default: cout<<"Scelta sbagliata\n";
        }
    }
}

int main()
{
    menu();
    return 0;
}
