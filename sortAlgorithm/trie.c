#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int trie_insertion(int tab[], int n){
    int temp, j, k=1;
    for(int i=1;i<n;i++){
        j=i;
        k++;
        while(j>0){
            k++;
            if(tab[j] < tab[j-1]){
                temp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = temp;
            }
            j-=1;
        }
    }
    return k+n;
}

int *copytab(int *tab, int n, int f, int l){
    int i = 0, j=0;
    int *copytab = malloc((l+1)*sizeof(int));
    while(i <= l)
    {
        j = i+f;
       copytab[i] = *(tab + j);
       i++;
    }
    return copytab;

}

int *fusion(int *tab_left, int *tab_rigth, int t1, int t2){
    int t = t1 + t2;
    int *tab = malloc(t*sizeof(int));
    //int tab = (int*)calloc(t, sizeof(int));
    if(tab_left == NULL )
        return tab_rigth;
    else if(tab_rigth == NULL )
        return tab_left;
    else{
        int i1=0, i2=0, k=0;
            while(i1 < t1 && i2 < t2){
                if(*(tab_left + i1) < *(tab_rigth + i2)){
                    tab[k] = *(tab_left + i1);
                    i1++;
                }else{
                    tab[k] = *(tab_rigth + i2);
                    i2++;
                }
                k++;
            }
            if (i1 == t1){
                while(i2 < t2)
                {
                    tab[k] = *(tab_rigth + i2);
                    i2++;
                    k++;
                }
            }else{
                while(i1 < t1)
                {
                    tab[k] = *(tab_left + i1);
                    i1++;
                    k++;
                }
            }
        return tab;
    }
}

int *triFusion(int *tab, int n){
    int m=0, i=0, j=0;
    //int *finaltab;
    if (n <= 1)
        return tab;
    else{
        m = n/2;
        j=n-m;
        int *tab1, *tab2;
        tab1=copytab(tab, n, 0, m);
        tab2=copytab(tab, n, m, n);
        tab = fusion(triFusion(tab1, m), triFusion(tab2, j), m, j);
    }
    return tab;

}
