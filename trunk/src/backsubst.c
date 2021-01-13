#include "backsubst.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
                /**
                 * Tutaj należy umieścić właściwą implemntację.
                 */

                /* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */
    if( mat->r != b->r ) 
        {
        fprintf( stderr, "Podane macierze nie pasują o siebie!\n");
        return 2;
        }   
    if( b->c != 1 ) 
        {
        fprintf( stderr, "Macierz B jest niewłaściwych rozmiarów!\n");
        return 2;
        }       
    if( mat->c != mat->r ) 
        {
        fprintf( stderr, "Macierz A jest niewłaściwych rozmiarów!\n");
        return 2;
        }           
    int r = mat->r;
    int c = mat->c;
    for( int ir= r-1; ir >= 0; ir-- ) 
    {
        double s = 0;
        for( int ic= ir+1; ic < c; ic++ ) s += x->data[ic][0] * mat->data[ir][ic];
        if( mat->data[ir][ir] == 0 ) 
        {
        fprintf( stderr, "Macierz jest nieosobliwa!\n");
        return 1;
        }
        x->data[ir][0] = (b->data[ir][0] - s) / mat->data[ir][ir];  
    }

    return 0;
}

