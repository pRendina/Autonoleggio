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
};

int sizee()
{
    ifstream fin(FILE_NAME);
    string app;
    int i = 0;
    while(getline(fin, app))
        i++;
    fin.close();
    return i;
}

void riempi_vet(auton vet[])
{
    fstream fin(FILE_NAME, ios::in);
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

void stampa_catalogo(auton vet[])
{
    for(int i=0; i<sizee(); i++){
            cout<<i+1<<") ";
            cout<<vet[i].categoria<<" "<<vet[i].marca<<" "<<vet[i].modello<<" "<<vet[i].colore;
            cout<<"\n\tDisponibilita':\n"<<
            "\t\t1] Lunedi': "<<vet[i].lun<<
            "\n\t\t2] Martedi': "<<vet[i].mar<<
            "\n\t\t3] Mercoledi': "<<vet[i].mer<<
            "\n\t\t4] Giovedi': "<<vet[i].gio<<
            "\n\t\t5] Venerdi': "<<vet[i].ven<<
            "\n\t\t6] Sabato: "<<vet[i].sab<<
            "\n\t\t7] Domenica: "<<vet[i].dom<<endl<<endl;

    }
}

void scrivi_file(auton vet[], int grand)
{
    fstream out(FILE_NAME, ios::out);

    for(int i=0; i<grand; i++){
        out<<vet[i].categoria
        <<","<<vet[i].marca
        <<","<<vet[i].modello
        <<","<<vet[i].colore
        <<","<<vet[i].lun
        <<","<<vet[i].mar
        <<","<<vet[i].mer
        <<","<<vet[i].gio
        <<","<<vet[i].ven
        <<","<<vet[i].sab<<",";
        if(i==grand-1)
            out<<vet[i].dom;
        else
            out<<vet[i].dom<<endl;
    }

    out.close();
}

void cambia_vet(auton vet[], int g, int pos)
{
    int grandezza = sizee();
    switch(g){
        case 1: vet[pos].lun = "A";
                break;
        case 2: vet[pos].mar = "A";
                break;
        case 3: vet[pos].mer = "A";
                break;
        case 4: vet[pos].gio = "A";
                break;
        case 5: vet[pos].ven = "A";
                break;
        case 6: vet[pos].sab = "A";
                break;
        case 7: vet[pos].dom = "A";
                break;
    }

    scrivi_file(vet, grandezza);
}

bool ok(auton vet[], int pos, string g[])
{
    int controllo = 0;
    bool istrue[7];

    for(int i=0; i<7; i++){
        switch(i){
            case 0: if(g[i] != vet[pos].lun)
                        istrue[i] = true;
                    else
                        istrue[i] = false;
                    break;

            case 1: if(g[i] != vet[pos].mar)
                        istrue[i] = true;
                    else
                        istrue[i] = false;
                    break;

            case 2: if(g[i] != vet[pos].mer)
                        istrue[i] = true;
                    else
                        istrue[i] = false;
                    break;

            case 3: if(g[i] != vet[pos].gio)
                        istrue[i] = true;
                    else
                        istrue[i] = false;
                    break;

            case 4: if(g[i] != vet[pos].ven)
                        istrue[i] = true;
                    else
                        istrue[i] = false;
                    break;

            case 5: if(g[i] != vet[pos].sab)
                        istrue[i] = true;
                    else
                        istrue[i] = false;
                    break;

            case 6: if(g[i] != vet[pos].dom)
                        istrue[i] = true;
                    else
                        istrue[i] = false;
        }
    }

    for(int i=0; i<7; i++){
        if(istrue[i] == false)
            controllo++;
    }

    if(controllo != 0)
        return false;
    else
        return true;

}

void findA(auton vet[], string cate, string g[])
{
    for(int i=0; i<sizee(); i++){
        if(vet[i].categoria == cate && ok(vet,i,g) == true){
            cout<<i+1<<") ";
            cout<<vet[i].marca<<" "<<vet[i].modello<<" "<<vet[i].colore;
            cout<<"\n\tDisponibilita':\n"<<
            "\t\t1] Lunedi': "<<vet[i].lun<<
            "\n\t\t2] Martedi': "<<vet[i].mar<<
            "\n\t\t3] Mercoledi': "<<vet[i].mer<<
            "\n\t\t4] Giovedi': "<<vet[i].gio<<
            "\n\t\t5] Venerdi': "<<vet[i].ven<<
            "\n\t\t6] Sabato: "<<vet[i].sab<<
            "\n\t\t7] Domenica: "<<vet[i].dom<<endl<<endl;
        }
    }

    int select,cont = 0;;
    cout<<"Inserire macchina da selezionare: ";
    cin>>select;

    for(int i=0; i<7; i++){
        if(g[i] == "A"){
            switch(i){
                case 0: if(vet[select-1].lun == "A")
                        cout<<"\n\tMacchina occupata lunedi'\n";
                        else cambia_vet(vet, i+1, select-1);
                        break;

                case 1: if(vet[select-1].mar == "A")
                        cout<<"\n\tMacchina occupata martedi'\n";
                        else cambia_vet(vet, i+1, select-1);
                        break;

                case 2: if(vet[select-1].mer == "A")
                        cout<<"\n\tMacchina occupata mercoledi'\n";
                        else cambia_vet(vet, i+1, select-1);
                        break;

                case 3: if(vet[select-1].gio == "A")
                        cout<<"\n\tMacchina occupata giovedi'\n";
                        else cambia_vet(vet, i+1, select-1);
                        break;

                case 4: if(vet[select-1].ven == "A")
                        cout<<"\n\tMacchina occupata venerdi'\n";
                        else cambia_vet(vet, i+1, select-1);
                        break;

                case 5: if(vet[select-1].sab == "A")
                        cout<<"\n\tMacchina occupata sabato\n";
                        else cambia_vet(vet, i+1, select-1);
                        break;

                case 6: if(vet[select-1].dom == "A")
                        cout<<"\n\tMacchina occupata domenica\n";
                        else cambia_vet(vet, i+1, select-1);
            }
        }
    }
}

void cerca_vettura(auton vet[])
{
    string cate="", all;
    int i=0, k=0;
    string g[7];

    cout<<"Inserire categoria dell'auto e giorni da affittare: ";
    cin.ignore();
    getline(cin, all);

    for(i=0; all.at(i) != ' '; i++)
        cate +=  all.at(i);
    i++;
    for(i; i<all.length(); i++){
        switch (all.at(i))
        {
            case '1': g[0] = "A";
                      break;
            case '2': g[1] = "A";
                      break;
            case '3': g[2] = "A";
                      break;
            case '4': g[3] = "A";
                      break;
            case '5': g[4] = "A";
                      break;
            case '6': g[5] = "A";
                      break;
            case '7': g[6] = "A";

        }
        k++;
    }

    if(cate!="utilitaria" && cate!="lusso" && cate!="sportiva" && cate!="furgone")
        cout<<"Categoria non esistente\n";
    else{
        if(cate == "utilitaria"){
            findA(vet, cate, g);
        }
        if(cate == "lusso"){
            findA(vet, cate, g);
        }
        if(cate == "sportiva"){
            findA(vet, cate, g);
        }
        if(cate == "furgone"){
            findA(vet, cate, g);
        }
    }
}

void menu()
{
    auton vet[20];
    int scelta;

    riempi_vet(vet);
    while(scelta!=3){
        cout<<"\n\t\tMENU'"<<endl;
        cout<<"1 - Consulta catalogo"<<endl
            <<"2 - Ricerca vettura"<<endl
            <<"3 - Uscita\n>>";
        cin>>scelta;

        switch(scelta){
            case 1: stampa_catalogo(vet);
                    break;
            case 2: cerca_vettura(vet);
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
