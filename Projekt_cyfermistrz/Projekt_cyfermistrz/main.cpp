//
//  main.cpp
//  Projekt_cyfermistrz
//
//  Created by Martyna Gruszka on 14/12/2018.
//  Copyright © 2018 Martyna Gruszka. All rights reserved.
//

#include <iostream>
#include <ctime>
#include<string>
#include <iomanip>
#include <stdlib.h>
#include<ncurses.h>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include <string>
#include "deklaracje.hpp"


using namespace std;




int main() {
    // pseudolosowość
    srand(time(NULL));
    
    
   menu();
    
    
 
}


void wroc(){
    cout<<endl;
    cout << "Wroc do menu [m]"<<endl;
    cout<<endl;
    bool poprawnie_wpisane=false;
    while (!poprawnie_wpisane){
        char wybor;
        cin>>wybor;
        cin.ignore(INT_MAX,'\n');
        
        if (wybor == 'm'){
            poprawnie_wpisane = true;
            clrscr(true);
            menu();
        }
        else {
            cout<<"Nie ma takiej opcji.Spróbuj jeszcze raz"<<endl;
        }
    }
    
    
}

void clrscr(bool duze){
    unsigned int max;
    if (duze==true){
        max = 40;
        for (unsigned int i =0;i<max;i++){
            cout <<endl;
        }
    }
    else if (duze==false){
        max = 10;
        for (unsigned int i =0;i<max;i++){
            cout <<endl;
        }
    }
}

void gra(){
    
   
    
    char cyfry_do_wykorzystania[] = {'0','1','2','3','4','5','6','7','8','9'};
    int ilosc_cyfr_do_wykorzystania = 10;
    
    int runda = 1;
    unsigned int ilosc_trafien_poz,ilosc_trafien;
    cyfry Liczba[(const unsigned int )ilosc_cyfr]; //tu zmiana byla
    
    
    char a = (rand()%10)+'0';
    char b = (rand()%10)+'0';
    char c = (rand()%10)+'0';
    char d = (rand()%10)+'0';
    
    
    char znaki[] = {a,b,c,d};
    
    
    cyfry cyfra[(const unsigned int )ilosc_cyfr];
    
    for (int i=0; i<ilosc_cyfr;i++){
        
        cyfra[i].wartosc=znaki[i];
        cyfra[i].pozycja=i;
        cyfra[i].czy_trafione = false;
        cyfra[i].czy_juz_wliczone = false;
        cyfra[i].czy_zarezerwowana_pozycja = false;
        
    }
    
    
    
    
    
    cout<<right << setw(58) << "'T+' - Ilość trafionych cyfr na dobrych miejscach"<<endl;
    cout<<right << setw(60) << "'T-' - Ilość trafionych cyfr, ale na złych miejscach"<<endl;
    
    
    
    
    cout<<right << setw(48) <<"Zakończ i wróć do Menu [!]"<<endl;
    
    cout << endl;
    cout <<setw(28);
    
    // liczba wylosowana (do kontroli)
    for (int i=0;i<ilosc_cyfr;i++){
        cout<<cyfra[i].wartosc;
    }
    cout<<endl;
    cout<< right << setw(10)<<"Próba:";
    cout << right <<setw(26)<<"Twoja liczba";
    cout <<right << setw(10)<<"T+";
    cout << right << setw(10)<<"T-";
    
    cout<<endl;
    cout<<endl;
    
    while (!wygrana && !przegrana){
        
        
        
        
        ilosc_trafien_poz=0;
        ilosc_trafien=0;
        
        
        
        cout <<right<< setw(6)<<runda;
        cout <<right <<setw(21)<<"";
        
        
        char c;
        
        int niepoprawny_zapis=0;
        
        cin.width(30);
        for (unsigned int i=0; i<ilosc_cyfr;i++){
            cin >> right >> c;
            
            
            
            Liczba[i].wartosc=c;
            
            int it = 0;
            bool ok = 0;
            while (it < ilosc_cyfr_do_wykorzystania && ok == 0){
                
                if (Liczba[i].wartosc == cyfry_do_wykorzystania[it]){
                    ok = 1;
                }
                if (Liczba[i].wartosc == '!'){
                    clrscr(false);
                    menu();
                }
                it++;
                
                
            }
            if (!ok){
                
                
                niepoprawny_zapis++;
                //cout << "ERORR" << endl;
                
            }
            
            
            
            Liczba[i].czy_przypisano_cyfre = false;
            Liczba[i].pozycja = i;
            Liczba[i].czy_juz_wliczone = false;
            Liczba[i].czy_trafione = false;
            
            
            
        }
        
        cin.ignore(INT_MAX,'\n');
        
        
        
        if (niepoprawny_zapis>0){
            cout << right <<setw(40)<<"ERORR: Błędny zapis!" << endl;
            
        }
        else {
            
            ilosc_trafien_poz = sprawdzanie_cyfr(Liczba,cyfra,true);
            ilosc_trafien = sprawdzanie_cyfr(Liczba,cyfra,false);
            
            
            
        }
        // zawartość Liczba do kontroli!
        /*for (int i = 0;i<ilosc_cyfr;i++){
            cout<<Liczba[i].wartosc;
        }*/
        
        cout << right <<setw(44)<<ilosc_trafien_poz;
        cout << right << setw(10)<<ilosc_trafien;
        cout<<endl;
        
        
        bool win = true;
        bool lose = false;
        
        
        
        
        
        
        if (ilosc_trafien_poz==ilosc_cyfr){
            
            
            zapisz_wynik(win,runda,aktualizacja_numeru_pliku_i_wyniku(&numer_pliku, &numer_wyniku,main_max_liczba_wynikow));
            
            cout<<endl;
            cout << setw(35)<<"WYGRANA!!!"<<endl;
            
            
            zakoncz_i_wroc_do_menu(win);
            
            
            
        }
        runda++;
        
        if (runda==prog-4){
            
            
            cout <<right<<setw(20)<< "Co tak słabo?! Pozostało Ci jeszcze tylko 5 prób."<<endl;
        }
        
        
        
        if (runda>prog && !wygrana){
            
            
            
            zapisz_wynik(lose,runda,aktualizacja_numeru_pliku_i_wyniku(&numer_pliku, &numer_wyniku,main_max_liczba_wynikow));
            
            cout<<right<<setw(25)<<"PRZEGRANA!"<<endl;
            
            
            zakoncz_i_wroc_do_menu(lose);
            
            
            
            
            
            
        }
    }
}




void menu (){
    
    
    clrscr(false);
    cout << right << setw(38)<<"MasterNum"<<endl;
    cout<<endl;
    cout<<right << setw(20);
    for (int i =0;i<30;i++){
        cout<<"_";
    }
    cout<<endl;
    cout<<right << setw(20)<<"|" <<right <<setw(15)<< "Menu"<<setw(14);
    cout<<right << setw(14)<<"|"<<endl;
    cout<<right << setw(20)<<"|" <<setw(29)<<"|"<<endl;
    cout<<right << setw(20)<<"|"  << right<< setw(6) <<"Gra"<<right<<setw(12)<<"[1]"<<setw(11)<<"|"<<endl;
    cout<<right << setw(20) <<"|" << right << setw(13)<< "Instrukcja"<<right<<setw(5)<<"[2]"<<setw(11)<<"|"<<endl;
    cout<<right << setw(20)<<"|" << right << setw(9)<< "Wyniki"<<right<<setw(9)<<"[3]"<<setw(11)<<"|"<<endl;
    cout<<right << setw(20) <<"|" << right << setw(13)<< "Ustawienia"<<right<<setw(5)<<"[4]"<<setw(11)<<"|"<<endl;
    cout<<right << setw(20)<<"|" << right << setw(11)<< "Wyjście"<<right<<setw(8)<<"[x]"<<setw(11)<<"|"<<endl;
    cout<<right << setw(20)<<"|";
    
    for (int i =0;i<28;i++){
        cout<<"_";
    }
    cout<<"|"<<endl;
    bool poprawne_wprowadzenie = false;
    
    poprawne_wprowadzenie = false;
    
    while(!poprawne_wprowadzenie){
        
        char opcja;
        cin >> opcja;
        cin.ignore(INT_MAX,'\n');
        
        
        if (opcja == '1'){
            poprawne_wprowadzenie=true;
            clrscr(true);
            if (ilosc_cyfr>4){
                printf( "Twoja Liczba powinna zawierać %d cyfr",ilosc_cyfr); cout<<'\n';
                
            }
            else {
                printf( "Twoja Liczba powinna zawierać %d cyfry",ilosc_cyfr); cout<<'\n';
            }
            cout<<endl;
            cout << right << setw(30)<<"Gra"<<endl;
            cout<<endl;
            gra();
            
            break;
        }
        else if (opcja == '2'){
            poprawne_wprowadzenie=true;
            clrscr(true);
            cout << "Instrukcja"<<endl;
            cout<<endl;
            instrukcja();
            break;
        }
        else if (opcja=='3'){
            poprawne_wprowadzenie=true;
            clrscr(true);
            cout<<right<<setw(36)<< "Wyniki"<<endl;
            wyniki(numer_pliku,max_liczba_wynikow);
            break;
        }
        else if (opcja == '4'){
            poprawne_wprowadzenie=true;
            clrscr(true);
            zmien_poziom_trudnosci();
            break;
        }
        
        else if (opcja == 'x'){
            
            //przepisz_dane_do_pliku0(numer_pliku);
            clrscr(true);
            poprawne_wprowadzenie = true;
            exit(0);
            break;
            
        }
        
        else {
            cout << "Nie ma takiej opcji. Spróbuj jeszcze raz."<<endl;
            
        }
        
        
    }
    
}



unsigned int sprawdzanie_cyfr(cyfry Moja_liczba[(const unsigned int )ilosc_cyfr], cyfry Wylosowana_liczba[(const unsigned int )ilosc_cyfr], bool flag){
    
    int cyfry_trafione_plus_pozycja = 0;
    int cyfry_trafione = 0;
    
    for (unsigned int i=0; i<ilosc_cyfr;i++){
        Wylosowana_liczba[i].czy_trafione = false;
        Wylosowana_liczba[i].czy_juz_wliczone = false;
        Wylosowana_liczba[i].czy_zarezerwowana_pozycja = false;
        Moja_liczba[i].czy_przypisano_cyfre=false;
        
        
        
        
        
    }
    
    
    int licznik_zarezerwowana_pozycja=0;
    
    
    for (unsigned int i=0; i<ilosc_cyfr;i++){
        
        
        for (unsigned int j=0;j<ilosc_cyfr;j++){
            
            if (Moja_liczba[i].wartosc==Wylosowana_liczba[j].wartosc && Moja_liczba[i].pozycja == Wylosowana_liczba[j].pozycja) {
                
                Wylosowana_liczba[j].czy_trafione = true;
                cyfry_trafione_plus_pozycja++;
                break;
                
            }
            else {
                
                
                
                
                if (Moja_liczba[i].wartosc==Wylosowana_liczba[j].wartosc && Moja_liczba[i].pozycja != Wylosowana_liczba[j].pozycja && Wylosowana_liczba[j].czy_trafione==false && Wylosowana_liczba[j].czy_juz_wliczone == false && Moja_liczba[i].czy_przypisano_cyfre==false && Wylosowana_liczba[j].czy_zarezerwowana_pozycja==false){
                    
                    unsigned int k = j+1;
                    unsigned int l = i+1;
                    int licznik_kontrolny =0;
                    
                    licznik_zarezerwowana_pozycja = 0;
                    k=j+1;
                    l=i+1;
                    
                    while (k<ilosc_cyfr){
                        
                        // sprawdzam czy cyfra z MojejLiczby jest trafiona na dalszej pozycji (zeby nie uwzglądniać jej niepotrzebnie jako trafionej na złym miejscu, jeśli taka sama cyfra wystąpiłaby wcześniej)
                        if (Moja_liczba[i].wartosc == Wylosowana_liczba[k].wartosc && Moja_liczba[i].pozycja == Wylosowana_liczba[k].pozycja){
                            
                            licznik_zarezerwowana_pozycja++;
                            Wylosowana_liczba[k].czy_zarezerwowana_pozycja = true;
                            
                            //break;
                            
                        }
                        
                        
                        k++;
                    }
                    
                    licznik_kontrolny =0;
                    // sprawdzam czy inna cyfra (o takiej samej wartosci) z MojejLiczby, która pojawia się w dalszej kolejności, jest trafiona i na odpowiedniej pozycji - żeby uniknąć niepotrzebnego wliczania jej jako trafionej na złym miejscu
                    while (l<ilosc_cyfr){
                        
                        if ( Wylosowana_liczba[j].wartosc== Moja_liczba[l].wartosc && Moja_liczba[l].pozycja == Wylosowana_liczba[j].pozycja){
                            
                            
                            licznik_kontrolny++;
                            Moja_liczba[l].czy_przypisano_cyfre = true;
                            //break;
                            
                        }
                        l++;
                        
                    }
                    
                    if (licznik_zarezerwowana_pozycja>0){
                        Moja_liczba[i].czy_przypisano_cyfre = true;
                    }
                    else if (licznik_kontrolny>0){
                        Wylosowana_liczba[j].czy_zarezerwowana_pozycja = true;
                    }
                    
                    else{
                        cyfry_trafione++;
                        Wylosowana_liczba[j].czy_juz_wliczone = true;
                        Moja_liczba[i].czy_przypisano_cyfre = true;
                    }
                    
                    
                    
                    
                }
                
            }
            
        }
    }
    
    if (flag==true){
        return cyfry_trafione_plus_pozycja;
    }
    else {
        return cyfry_trafione;
    }
}

void zakoncz_i_wroc_do_menu(bool rezultat){
    
    cout<<endl;
    cout<<right<<setw(47)<<"Zakończ i wróć do Menu [m]"<<endl;
    cout<<right <<setw(37)<<"Zakończ [z]"<<endl;
    bool poprawny_zapis=false;
    while(!poprawny_zapis){
        char wybor;
        cin >> wybor;
        cin.ignore(INT_MAX,'\n');
        
        if(wybor == 'm'){
            poprawny_zapis=true;
            clrscr(false);
            menu();
        }
        else if (wybor == 'z'){
            poprawny_zapis =true;
            clrscr(true);
            
            if (rezultat ==true){
                wygrana = true;
            }
            else {
                przegrana = true;
            }
            
            //przepisz_dane_do_pliku0(numer_pliku);
            exit(0);
            break;
        }
        else{
            cout<<"Nie ma takiej opcji. Spróbuj jeszcze raz."<<endl;
        }
    }
    
}


void instrukcja(){
    
    cout<<right<<setw(38)<<"Witaj w grze MasterNum!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<right<<setw(79)<<"Twoim zadaniem jest odgadnąć: 4-cyfrową liczbę wylosowaną przez komputer" <<endl;
    cout<<right<<setw(33)<<"na podstawie dwóch informacji:"<<endl;
    cout<<endl;
    cout<<right<<setw(55)<<"1. Ilości trafionych cyfr znajdujących się na dobrych pozycjach;"<<endl;
    cout<<right<<setw(55)<<"2. Ilości trafionych cyfr, ale znajdujących się na złych miejscach."<<endl;
    cout<<right<<setw(55)<<"(możesz też zmienić ilość cyfr liczby, korzystając z odpowiedniej opcji w ustawieniach)"<<endl;
    cout<<endl;
    cout<<right<<setw(82)<<"Przed rozpoczęciem gry, u góry ekranu  zostanie wyświetlona informacja o tym,"<<endl;
    cout<<right<<setw(84)<<"ile cyfr posiada liczba, którą musisz odgadnąć.Masz 15 prób by tego dokonać."<<endl;
    cout<<right<<setw(68)<<"(górny próg również możesz zmienić w Ustawieniach)"<<endl;
    cout<<right<<setw(79)<<"Jeśli jednak nie uda Ci się odgadnąć liczby do tego momentu: PRZEGRYWASZ."<<endl;
    cout<<endl;
    
    cout<<right<<setw(68)<<"Każdy wynik jest zapisywany do tabeli wyników dostępnej w menu."<<endl;
    cout<<right<<setw(79)<<"(możesz zmienić ilość wyświetlanych rekordów, korzystając z Ustawień)"<<endl;
    cout<<endl;
    cout<<right<<setw(89)<<"Jeśli ilość cyfr w Twojej liczbie będzie mniejsza od zadanej ilości, poprawność "<<endl;
    cout<<right<<setw(81)<<"trafień nie będzie sprawdzana - program poczeka aż wpiszesz zadaną ilość." <<endl;
    cout<<right<<setw(80)<<"Jeśli zaś ilość cyfr byłaby większa od zadanej, nie martw się, wczytana"<<endl;
    cout<<right<<setw(80)<<"zostanie liczba o zadanej ilości cyfr, a dodatkowe cyfry zostaną pominięte."<<endl;
    cout<<endl;
    cout<<right<<setw(74)<<"W razie wpisania innych nieprzewidzianych znaków, wyświetlona zostanie"<<endl;
    cout<<right<<setw(82)<<"informacja o błędzie. Pamiętaj, że przed zatwierdzeniem wprowadzonej liczby,"<<endl;
    cout<<right<<setw(80)<<"zawsze możesz usunąć uprzednio wpisane znaki i wprowadzić liczbę na nowo."<<endl;
    cout<<right<<setw(72)<<"Jeśli jednak komunikat błędu zostanie wywołany - tracisz kolejkę."<<endl;
    cout <<endl;
    cout<<right<<setw(82)<<"Możesz przerwać grę w każdej chwili, wpisując znak '!' w miejsce wpisywania"<<endl;
    cout<<right<<setw(76)<<"Twojej liczby. Jednakże w takim wypadku, wynik gry nie zostanie zapisany,"<<endl;
    cout<<right<<setw(43)<<" a Ty stracisz swoją szansę na WYGRANĄ."<<endl;
    cout<<endl;
    cout<<right<<setw(35)<< "Powodzenia!!!"<<endl;
    cout<<endl;
    wroc();
}

int aktualizacja_numeru_pliku_i_wyniku(int *numer_pliku, int *numer_wyniku,int max_liczba_wynikow){
    
    
    
    int max_liczba_linii = max_liczba_wynikow+2*max_liczba_wynikow+1;
    
    int licznik_linii = 0;
    string baza(".txt");
    char z;
    ifstream plik(to_string(*numer_pliku)+baza);
    
    if (plik.is_open())
    {
        while (!plik.eof())
        {
            
            plik.get(z);
            
            if (z=='\n'){
                licznik_linii++;
            }
            
        }
        
        if (licznik_linii >= max_liczba_linii){
            //przepisz_dane_do_pliku0(*numer_pliku);
            *numer_pliku=*numer_pliku+1;
            *numer_wyniku = 1;
            
        }
        else {
            *numer_wyniku=*numer_wyniku+1;
        }
    }
    
    plik.close();
    
    
    return *numer_pliku;
    
   
    
    
}

void zapisz_wynik(bool rezultat,int runda, int numer_pliku){
    
    
    time_t czas;
    time(&czas);
    ctime(&czas);
    
    string baza(".txt");
    
    
    
    //wyniki5.txt
    fstream plik(to_string(numer_pliku)+baza,ios::out | ios::app);
    
    
    
    
    cout<<endl;
    
    if ( rezultat == true ){
        plik<<" "<<" "<<" ";
        plik <<" WYGRANA w "<< runda;
        if (runda == 1){
            plik<<" próbie."<<right << setw(5)<<ilosc_cyfr<<"-cyfrowa"<<right<<setw(11)<<prog<<right << setw(10)<<"";;
            
            
            
        }
        else{
            plik<< " próbach."<<right << setw(4)<<ilosc_cyfr<<"-cyfrowa"<<right<<setw(11)<<prog<<right << setw(10)<<"";
            
        }
        
    }
    else if (rezultat == false){
        plik<<" "<<" "<<" ";
        plik << " PRZEGRANA"<<right << setw(15)<<ilosc_cyfr<<"-cyfrowa"<<right<<setw(11)<<prog<<right << setw(11)<<"";
        
        
    }
    plik<<left<<ctime(&czas)<<endl;
    plik<<endl;
    plik.close();
}

void wyniki(int numer_pliku, int max_liczba_wynikow){
    //max_liczba_wynikow+2*(max_liczba_wynikow-1)
    int max_liczba_linii = max_liczba_wynikow+2*max_liczba_wynikow+1;
    int licznik_linii= ilosc_linii_w_pliku(numer_pliku); // zmiana z 0
    int lokalny_licznik_linii = 0;
    
    string baza(".txt");
    
    cout<<endl;
    cout<<right<<setw(40)<<"Twoje rozgrywki: "<<endl;
    cout<<endl;
    cout<<right<<setw(10)<<"Wyniki: ";
    cout<<right<<setw(25)<<"Liczba:";
    cout<<right<<setw(15)<<"Próg:";
    cout<<right<<setw(20)<<"Data: "<<endl;
    cout<<endl;
    
    char z;
    ifstream plik(to_string(numer_pliku)+baza);
    if (plik.is_open())
    {
        
        while (!plik.eof())
        {
            
            plik.get(z);
            if (z=='\n'){
                lokalny_licznik_linii++;
            }
            
            if (licznik_linii<=max_liczba_linii){
                if (lokalny_licznik_linii<max_liczba_linii){
                    cout<<z;
                }
                
            }
            else {
                if (lokalny_licznik_linii>=(licznik_linii - max_liczba_linii)){
                    cout<<z;
                }
            }
            
        }
        //kontrolują ilość wyświetlanych wyników
        //cout << lokalny_licznik_linii<<endl;
        //cout<<max_liczba_linii<<endl;
        
    }
    
    else{
        cout << "Nie ma jeszcze żadnych rekordów." << endl;
    }
    
    plik.close();
    cout<<endl;
    cout<<endl;
    wroc();
    
    
    
    
}



void zmien_poziom_trudnosci(){
    
    
    
    cout <<right<<setw(35)<<"Ustawienia: "<<endl;
    cout<<endl;
    cout<<right<<setw(11);
    for (int i=0;i<38;i++){
        cout <<"-";
    }
    cout<<endl;
    
    cout <<right<<setw(46)<<"Zmień maksymalną ilość ruchów"<<right <<setw(5)<<"[z]"<<endl;
    cout<<endl;
    cout <<right<<setw(38)<<"Zmień ilość cyfr liczby"<<right<<setw(11)<<"[c]"<<endl;
    cout<<endl;
    cout <<right<<setw(44)<<"Zmień ilość wyników w tabeli"<<right<<setw(6)<<"[w]"<<endl;
    cout<<endl;
    cout <<right<<setw(34)<< "Nie zmieniaj ustawień" << right <<setw(13)<<"[n]"<<endl;
    cout<<right<<setw(11);
    for (int i=0;i<38;i++){
        cout <<"-";
    }
    cout<<endl;
    cout<<right<<setw(30)<<"";
    
    bool poprawnie_wprowadzone = false;
    while(!poprawnie_wprowadzone){
        
        poprawnie_wprowadzone = false;
        char c;
        cin>>c;
        
        if (c == 'n'){
            poprawnie_wprowadzone = true;
            clrscr(false);
            menu();
        }
        else if (c == 'z'){
            poprawnie_wprowadzone = true;
            cout<<right<<setw(66)<<"Wprowadz nowy próg ( maksymalna dozwolona ilość ruchów 1 - 15 )"<<endl;
            cout<<endl;
            cout<<right<<setw(20)<<"";
            nowy_prog(&prog);
        }
        else if (c == 'c'){
            poprawnie_wprowadzone=true;
            cout<<right<<setw(51)<<"Wprowadz nową ilość cyfr ( 4 - 8 )"<<endl;
            cout<<endl;
            cout<<right<<setw(30)<<"";
            nowa_ilosc_cyfr(&ilosc_cyfr);
        }
        else if (c=='w'){
            poprawnie_wprowadzone=true;
            cout<<right<<setw(61)<<"Wprowadz nową maksymalną ilość wyników w Tabeli Wyników: "<<endl;
            cout<<endl;
            cout<<right<<setw(30)<<"";
            nowa_ilosc_wynikow(&max_liczba_wynikow);
        }
        
        else {
            
            cout << "Błędny zapis. Spróbuj jeszcze raz."<<endl;
            cout<<endl;
        }
            
    }

    
    
   
    
    
}

void nowy_prog(int *prog){
    
    
    bool poprawny_zapis = false;
    
    
    while (!poprawny_zapis){
        
        int c;
        
        
        cin >> c;
        cin.sync();
        
        while(cin.fail()){
            
            cout << "Nie można ustawić takiego progu. Spróbuj jeszcze raz."<<endl;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cin >> c;
            
        }
        
        if ( c>0 && c<16){
            poprawny_zapis=true;
            *prog = c;
            wroc();
        }
        else {
            cout << "Nie można ustawić takiego progu. Zakres: 1 - 15."<<endl;
        }
            
        
    }
    
    
    
}

void nowa_ilosc_cyfr(unsigned int *ilosc_cyfr){
    
    bool poprawny_zapis = false;
    
    
    while (!poprawny_zapis){
        
        unsigned int c;
        
        
        cin >> c;
        cin.sync();
        
        while(cin.fail()){
            
            cout <<right<<setw(51)<< "Błędny zapis. Spróbuj jeszcze raz."<<endl;
            cout<<endl;
            cout<<right<<setw(30)<<"";
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cin >> c;
            
        }
        
        if ( c>3 && c<9){
            poprawny_zapis=true;
            *ilosc_cyfr = c;
            wroc();
        }
        else {
            
            cout <<right<<setw(49)<< "Zła ilość cyfr! Zakres: 4 - 8."<<endl;
            cout<<endl;
            cout<<right<<setw(30)<<"";
        }
        
        
    }
}

void nowa_ilosc_wynikow(int *max_liczba_wynikow){
    
    bool poprawny_zapis = false;
    
    
    while (!poprawny_zapis){
        
        int c;
        
        
        cin >> c;
        cin.sync();
        
        while(cin.fail()){
            
            cout <<right<<setw(51)<< "Błędny zapis. Spróbuj jeszcze raz."<<endl;
            cout<<endl;
            cout<<right<<setw(30)<<"";
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cin >> c;
            
        }
        
        if ( c>0 && c<main_max_liczba_wynikow){
            poprawny_zapis=true;
            *max_liczba_wynikow = c;
            wroc();
        }
        else {
            
            cout <<right<<setw(49)<< "Nie można ustawić takiej liczby wyników."<<endl;
            cout<<endl;
            cout<<right<<setw(30)<<"";
        }
        
        
    }
}

void przepisz_dane_do_pliku0(int numer_pliku){
    
    int licznik_linii = ilosc_linii_w_pliku(numer_pliku);
    int lokalny_licznik_linii =0;
    string baza(".txt");
    string nazwa_pliku = to_string(numer_pliku)+baza;
    
    if (numer_pliku>0){
        ofstream plik("0.txt",ios::out | ios::app);
        
        ifstream plik2(nazwa_pliku);
        plik.seekp(0,ios::end);
        char z;
        if (plik2.is_open())
        {
            while (!plik2.eof())
            {
                
                plik2.get(z);
                if (z=='\n'){
                    lokalny_licznik_linii++;
                }
                // zapisujemy bez ostatniej spacji żeby odległość między wynikami była taka sama
                if (lokalny_licznik_linii!=licznik_linii){
                    plik << z;
                }
                
                
            }
        }
        
        plik2.close();
        plik.close();
        
        remove(nazwa_pliku.c_str());
    }
}

int ilosc_linii_w_pliku(int numer_pliku){
    string baza(".txt");
    int licznik_linii = 0;
    char z;
    ifstream plik(to_string(numer_pliku)+baza);
    if (plik.is_open())
    {
        
        while (!plik.eof())
        {
            
            plik.get(z);
            if (z=='\n'){
                licznik_linii++;
            }
    
            
        }
        
        
    }
    plik.close();
    return licznik_linii;
   
    
}


