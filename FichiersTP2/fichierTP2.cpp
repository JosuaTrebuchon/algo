#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
using namespace std;

//  DERNIERLSC ET ESTTRIEELSC 
// Res : Renvoie l'adresse de la derniere cellule de la liste non vide L 
ListeSC dernierLSC(ListeSC L){
  assert(L != NULL);
  ListeSC p = L;
  while(p->succ!=NULL){
    p=p->succ;
  }
  return p;
}

//   Res : Renvoie 1 si L est une ListeSC triee, 0 sinon 
bool estTrieeLSC(ListeSC L){
  ListeSC p = L;
  while(p->succ != NULL){
    if(p->info <= p->succ->info){
      p = p->succ;
    }else{
      return false;
    }
  }
  return true;

}


//  OTERREPETITION 
//    Res : Supprime de la ListeSC L tous les elements consecutifs egaux 
//          Opere en modifiant le chainage de la ListeSC L 
// version iterative 
void oterRepetitionLSC(ListeSC L){
  ListeSC p = L;
  while (p->succ != NULL)
  {
    if(p->info == p->succ->info){
      p->succ = p->succ->succ;
    }else{
      p = p->succ;
    }
  }
  return;
}

//    Res : Supprime de la ListeSC L tous les elements consecutifs egaux 
//          Opere en modifiant le chainage de la ListeSC L 
//    version recursive 
void oterRepetitionLSCR(ListeSC L){
  if(L!= NULL && L->succ != NULL){
    if(L->info == L->succ->info){
      L->succ = L->succ->succ;
      oterRepetitionLSCR(L);
    }else{
      oterRepetitionLSCR(L->succ);
    }
  }
  return;
}


//   CONCATENATION DE 2 LISTES  
//   Res : Modifie la liste L1 en la concatenant avec la liste l2 
//         Opere en modifiant le chainage de la listeSC L1 
//   Version utilisant la fonction dernierLSC 
void concatLSC(ListeSC& L1,ListeSC L2){
  if(L2 != NULL)
    dernierLSC(L1)->succ = L2;
  return;
}

//   Res : Renvoie la ListeSC obtenue par concatenation des ListeSC L1 et L2 
//         Opere en recopiant les elements des 2 listeSC L1 et L2 
//   complexite : ??? 
ListeSC concatLSCCopie(ListeSC L1,ListeSC L2){
  ListeSC L3 = creerLSC(L1->info, NULL);
  if(L1 != NULL){
    cout << "boucle 1" << endl;
    ListeSC P1 = L1->succ;
    while (P1->succ != NULL)
    {
      insererFinLSC(L3,P1->info);
      P1 = P1->succ; 
    }
  }
  if(L2 != NULL){
    cout << "boucle 2" << endl;
    ListeSC P2 = L2;
    while (P2->succ != NULL)
    {
      insererFinLSC(L3,P2->info);
      P2 = P2->succ; 
    }
  }
  return L3;
}


