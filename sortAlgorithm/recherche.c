#include <stdio.h>
#include <stdlib.h>
#include "recherche.h"

int recherche_sequentielle(int tab[], int n, int x){
    int trouve=0, i=0, k=0;
    while(!trouve && i<n){
        k+=2;
        if(tab[i]==x){
            trouve = 1;
        }
        k++;
        i++;
    }
    k=k==0?2:k;
    return k;
}

int recherche_dichotomique(int tab[], int n, int id1, int idn, int x){
    int i=n/2, k=0;
    if(n<=1){
        k++;
        return k;
    }
    else if(tab[i]==x){
        k++;
        return k;
    }else if(tab[i]<x){
        k+=2;
        k+=recherche_dichotomique(tab, n/2, i, idn, x);
    }else{
        k+=3;
        k+=recherche_dichotomique(tab, n/2, 0, i, x);
    }
    return k;
}
