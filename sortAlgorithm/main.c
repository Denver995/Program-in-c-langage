#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "trie.h"
#include "recherche.h"

const int MAX = 1000;
const int MIN = 100;

void fill_table(int tab[], int taille);
void sequentialexec(int tab[], int max_size, int action_type);
void print_table(int tab[], int n);

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    int n = 2000;
    int tab[2000];
    sequentialexec(tab, n, 1);//recherche sequentielle
    sequentialexec(tab, n, 2);//recherche dichotomique
    sequentialexec(tab, n, 3);//trie  par insertion
    sequentialexec(tab, n, 4);//trie fusion ne fonctionne pas encore


    return 0;
}

//function that will fill the table with a random values
void fill_table(int tab[], int taille){
    //int* allocatedMemory = NULL;
    //allocatedMemory = malloc(taille*sizeof(int));
    for(int i=0; i<taille; i++){
        tab[i]=rand()%((MAX-MIN)+1);
        printf("%d\t", tab[i]);
    }
}

void print_table(int tab[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t", tab[i]);
    }
}

void print_pointer_table(int *tab, int n){
    for (int i = 0 ; i < n ; i++)
    {
        printf("%d\t", *(tab + i));
    }
}

void sequentialexec(int tab[], int max_size, int action_type){
    int j=2, k=0;
    //generate a number to find betwen MIN AND MAX
    int number_to_finder=rand()%((MAX-MIN)+1);
    FILE* fichier = NULL;
    switch(action_type){
        case 1: //1=recherche_sequentielle
            printf("----------------------------recherche séquentielle------------------------------------------------------------------------------------------");
            fichier = fopen("recherche_sequentielle.csv", "a+");
            if (fichier != NULL)
            {
                while(j<=max_size){
                    fill_table(tab, j);
                    //call the sequential reshearch function
                    k=recherche_sequentielle(tab, j, number_to_finder);
                    //print the result
                    printf("\nnombre recherche: %d, taille tableau: %d, nombre comparaison: %d", number_to_finder , j, k);
                    // write in the file the number of comparition and the size of the current table
                    fprintf(fichier, "%d;%d\n", j, k);
                    //increment j for table size
                    j++;
                    printf("\n\n");

                }
                fclose(fichier); // close the file
            }
            //open the sequential reshearch classifier file
            system("recherche_sequentielle.csv");
            break;
        case 2://2="recherche dichotomique"
            printf("----------------------------recherche dichotomique-------------------------------------------------------------------------------");
            fichier = fopen("recherche_dichotomique.csv", "a+");
            if (fichier != NULL)
            {
                while(j<=max_size){
                    fill_table(tab, j);
                    k=recherche_dichotomique(tab, j, 0, j, number_to_finder);
                    //print the result
                    printf("\n\nnombre recherche: %d, \ntaille tableau: %d, \nnombre comparaison: %d", number_to_finder , j, k);
                    // write in the file the number of comparition and the size of the current table
                    fprintf(fichier, "%d;%d\n", j, k);
                    //increment j for table size
                    j++;
                    printf("\n\n");

                }
                fclose(fichier); // close the file
            }
            //open the dichotomique research classifier file
            system("recherche_dichotomique.csv");
            break;
        case 3://3="trie insertion"
            printf("----------------------------trie insertion----------------------------------------------------------------------------------------------------");
            fichier = fopen("trie_insertion.csv", "a+");
            if (fichier != NULL)
            {
                while(j<=max_size){
                    fill_table(tab, j);//call the trie insertion reshearch function
                    k=trie_insertion(tab, j);
                    //print the sorted table
                    printf("\n\ntableau trié par trie insertion\n\n");
                    print_table(tab, j);
                    //print the result
                    printf("\n\ntaille tableau: %d, \nnombre comparaison: %d", j, k);
                    // write in the file the number of comparition and the size of the current table
                    fprintf(fichier, "%d;%d\n", j, k);
                    //increment j for table size
                    j++;
                    printf("\n\n");

                }
                fclose(fichier); // close the file
            }
            //open the trie insertion classifier file
            system("trie_insertion.csv");
            break;
        case 4://3="trie insertion"
            printf("----------------------------trie fusion----------------------------------------------------------------------------------------------------");
            fichier = fopen("trie_fusion.csv", "a+");
            if (fichier != NULL)
            {
                while(j<=max_size){

                    int *tab1 = malloc(j * sizeof(int));
                    fill_table(tab, j);//call the trie insertion reshearch function
                    tab1=triFusion(tab, j);
                    //print the sorted table
                    printf("\n\ntableau trié par trie fusion\n\n");
                    print_pointer_table(tab1, j);
                    free(tab1);
                    //print the result
                    printf("\n\ntaille tableau: %d, \nnombre comparaison: %d", j, k);
                    // write in the file the number of comparition and the size of the current table
                    fprintf(fichier, "%d;%d\n", j, k);
                    //increment j for table size
                    j++;
                    printf("\n\n");

                }
                fclose(fichier); // close the file
            }
            //open the trie insertion classifier file
            system("trie_fusion.csv");
            break;
        default:
            printf("there're any action to perform");
            break;

    }
}
