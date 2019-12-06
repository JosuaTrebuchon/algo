#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
#include "fichierTP3.h"
using namespace std;



bool estTrieeLSC(ListeSC L){
  //   Res : Renvoie true si L est une ListeSC tri�e, false sinon 
  if (estVideLSC(L) || estVideLSC(L->succ))
    return true;
  else
    return (L->info < (L->succ)->info) &&  estTrieeLSC(L->succ);
}

bool estListeIntervalle(ListeSC L){
  //   Res : renvoie true si L est une Liste intervalle, renvoie false sinon 
  // 
  ListeSC A = L;
  while(A->succ != NULL){
    if(A->info == A->succ->info-1){
      A = A->succ;
    }else{
      return false;
    }
  }
  return true;
}

ListeSC consListeIntervalle1(int l, int p){
  //     Donn�e : l entier positif
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 
  //     Complexit� : O(n²) dans le pire des cas
  assert(l>=0);
  
  int i; ListeSC L;
  L=NULL;
  for(i=0;i<l;i++)    
    insererFinLSC(L,p+i);
  return L;
}

ListeSC consListeIntervalle2(int l, int p){
  //     Donn�e : l entier positif
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 
  //     Complexit� : O(n) où n est la taille de la liste (soit l'entier l)

  // A COMPLETER
  assert(l>=0);
  
  ListeSC L =NULL;
  for(int i=l;i>0; i--){
    insererDebutLSC(L, p+i-1);
  }

  return L;
}

ListeSC consListeIntervalle3(int l, int p){
  //     Donn�e : l entier positif
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 
  //     Complexit� : O(n) dans tous les cas 
  //     Version r�cursive
  // A COMPLETER
  assert(l>=0);
  if(l == 0){
    return NULL;
  }else{
    ListeSC L = NULL;
    L = creerLSC(p,L);
    L->succ = consListeIntervalle3(l-1,p+1);
    return L;
  }
  return NULL;
}

// Temps de construction d'une liste intervalle de taille 50000 :
// avec consListeIntervalle1 : 8.21006 sec
// avec consListeIntervalle2 : 0.00147 sec
// avec consListeIntervalle3 : 0.001478 sec

void transfListeIntervalle(ListeSC L){
  //     Donn�e : L est une liste tri�e non vide  
  //     Res : modifie L en y inserant des �l�ments de sorte qu'elle soit une Liste Intervalle
  //     Complexit� : O(n) où n est la taille finale de la liste
  assert((L!=NULL));
  assert(estTrieeLSC(L));
  // A COMPLETER
  ListeSC R = L;
  while(R->succ != NULL){
    if(R->info != R->succ->info-1){
      insererApresLSC(L, R, R->info+1);
    }
    R = R->succ;
  }

  return;
}

ListeSC intersectionListesIntervalles(ListeSC l1, ListeSC l2){
  //     Donn�e : l1 et l2 2 listes intervalles
  //     Res : Renvoie l'intersection de l1 et l2; les �l�ments de la liste r�sultat sont recopi�s
  //     Complexit� : O(n) ou n est la somme des longueur des listes l1, l2
  assert(estListeIntervalle(l1));
  assert(estListeIntervalle(l2));
  // A COMPLETER
  ListeSC L = NULL;
  ListeSC L1, L2;L1= l1;L2=l2;
  while(L1 != NULL || L2 != NULL){
    if(L1->info > L2->info){
      L2 = L2->succ;
    }else if(L2->info > L1->info){
      L1 = L1->succ;
    }else{
      insererFinLSC(L, L1->info);
    }
  }
  return L;
}
  
void plusLgSsLiInterv(ListeSC &L){
  //     Donn�e : L liste
  //     Res : L est modifiee, elle est la plus longue sous-liste intervalle de la liste en entr�e
  //     Complexit� : ????
  // A COMPLETER

}





