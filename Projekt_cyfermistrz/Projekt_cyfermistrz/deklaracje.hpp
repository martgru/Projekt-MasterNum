//
//  deklaracje.hpp
//  Projekt_cyfermistrz
//
//  Created by Martyna Gruszka on 01/02/2019.
//  Copyright © 2019 Martyna Gruszka. All rights reserved.
//

#ifndef deklaracje_hpp
#define deklaracje_hpp

#include <stdio.h>


unsigned int ilosc_cyfr = 4;
int opcja;
bool wygrana = false;
bool przegrana = false;
int prog = 15; // próg_górny
int numer_pliku = 0;
int numer_wyniku = 1; // kontrola: liczby gier na jedno uruchomienie programu
int max_liczba_wynikow = 20;
int main_max_liczba_wynikow = 1000;

int numerek = 1;


struct cyfry{
    char wartosc;
    int pozycja;
    bool czy_trafione;
    bool czy_juz_wliczone;
    bool czy_przypisano_cyfre;
    bool czy_zarezerwowana_pozycja;
    
    
    
    
};

void menu();

void clrscr(bool duze);

void wroc();

void gra();

void zakoncz_i_wroc_do_menu(bool rezultat);

void instrukcja();

int aktualizacja_numeru_pliku_i_wyniku(int *numer_pliku, int *numer_wyniku,int max_liczba_wynikow);

void wyniki(int numer_pliku, int max_liczba_wynikow);

void zapisz_wynik(bool rezultat,int runda,int numer_pliku);

unsigned int sprawdzanie_cyfr(cyfry Moja_liczba[ilosc_cyfr], cyfry Wylosowana_liczba[ilosc_cyfr], bool flag);

void zmien_poziom_trudnosci();

void nowy_prog(int *prog);

void nowa_ilosc_cyfr(unsigned int *ilosc_cyfr);

void nowa_ilosc_wynikow(int *max_liczba_wynikow);

void przepisz_dane_do_pliku0(int numer_pliku);

int ilosc_linii_w_pliku(int numer_pliku);

#endif /* deklaracje_hpp */

