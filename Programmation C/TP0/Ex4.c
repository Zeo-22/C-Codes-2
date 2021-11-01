#include<stdio.h>
#include<stdlib.h>

struct tableau
{
    unsigned taille;
    double * tete;
};
typedef struct tableau tableau;


tableau allouer(unsigned); 
void saisie(tableau);
void affichage(tableau);
tableau concatenation(tableau, tableau);
void liberer(tableau);


tableau allouer(unsigned n)
{
    tableau T;
    if(n==0)
    {
        T.taille=0;
        T.tete=NULL;
    }
    else
    {
        T.taille=n;
        T.tete=(double *)malloc(sizeof(double));
    }
    return T;
}



void affichage(tableau T)
{
    
    if(T.tete==NULL)
        printf("[]\n");
    else
    {
        printf("[");
        int i;
        for(i=0;i<T.taille-1;i++)
            printf("%lf \t",T.tete[i]);
        printf("%lf]\n",T.tete[T.taille-1]);
    }
}


void saisie(tableau T)
{
    if(T.tete==NULL)
        return;
    else
    {
        int i;
        for(i=0;i<T.taille;i++)
            scanf("%lf",T.tete+i);
    }
}


void liberer(tableau T)
{
    if(T.tete!=NULL)
        free(T.tete);
}


int main()
{
    tableau T=allouer(3);
    tableau S=allouer(4);
    printf("Saisie dans le tableau T.\n");
    saisie(T);
    printf("Saisie dans le tableau S.\n");
    saisie(S);
    printf("Affichage du tableau T.\n");
    affichage(T);
    printf("Affichage du tableau S.\n");
    affichage(S);
    liberer(T);
    liberer(S);
    return 0;
}

