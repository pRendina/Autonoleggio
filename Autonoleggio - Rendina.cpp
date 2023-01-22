#include <iostream>
#include <fstream>

#define FILE_NAME "Auto.csv"

using namespace std;

struct auton{
    string categoria;
    string marca;
    string modello;
    string colore;
    bool free;
};

void catalogo(auton autovett, auton *ptr_auto)
{
    int i = 0;
    fstream fin(FILE_NAME);
    while(!fin.eof())
    {

        string appoggio = "";
        getline(fin,autovett.categoria,',');
        cout<<autovett.categoria<<" ";

        getline(fin,autovett.marca,',');
        cout<<autovett.marca<<" ";

        getline(fin,autovett.modello,',');
        cout<<autovett.modello<<" ";

        getline(fin,autovett.colore,',');
        cout<<autovett.colore<<endl;

        for(int k = 0; k < 7; k++)
        {
            getline(fin, appoggio, ',');
            if(appoggio == " L" || appoggio == "L " || appoggio ){
                autovett.free = true;
                cout<<"Libera ";
            }

            else if(appoggio == " A"){
                autovett.free = false;
                cout<<"Occupata ";
            }
        }
        cout<<endl;
        i++;
    }
    fin.close();
}

void menu()
{
    auton autovett, *ptr_auto = &autovett;
    int scelta;

    cout<<"\t\tMENU'"<<endl;
    cout<<"1 - Consulta catalogo"<<endl
        <<"2 - Ricerca vettura"<<endl;

    cin>>scelta;
    switch(scelta){
        case 1: catalogo(autovett, ptr_auto);
                break;
    }
}

int main()
{
    menu();
    return 0;
}