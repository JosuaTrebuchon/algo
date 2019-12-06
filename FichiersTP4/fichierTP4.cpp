#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
#include "fichierTP4.h"
using namespace std;


ArbreBin creerArbreBin(int e, ArbreBin G, ArbreBin D){
  /* Res : renvoie une ArbreBin dont la racine vaut e, le sag G et le sad D   */
  ArbreBin A = new NoeudSC;
  A->info=e;  A->sag=G;  A->sad=D;
  return A;}
  
void codageABdot(ofstream& fichier, ArbreBin A){
  if (A != NULL){ 
    fichier << (long) A << " [label=\""  << A->info << "\" ] ;\n";
    if (A->sag != NULL) {
      fichier << (long)A << " -> " << (long)(A->sag) <<  " [color=\"red\",label=\"g\" ] ;\n";
      codageABdot(fichier,A->sag);} 
    if (A->sad != NULL) {
      fichier << (long)A << " -> " << (long)(A->sad) << " [color=\"blue\",label=\"d\" ] ;\n";
      codageABdot(fichier,A->sad);}
  }
  return;}
    

void dessinerAB(ArbreBin A, const char * nomFic, string titre){
  ofstream f(nomFic);
  if (!f.is_open()){
   cout << "Impossible d'ouvrir le fichier en �criture !" << endl;
  }
  else {
    f<< "digraph G { label = \""<< titre << "\" \n";
    codageABdot(f,A);
    f << "\n }\n" ;
    f.close();}
  return;}


/* A COMPLETER */
int sommeNoeuds(ArbreBin A){
  /* renvoie la somme des etiquettes des noeuds de l arbre binaire A */
  /* A COMPLETER */
  if(A == NULL){ 
    return 0;
  }else{
    return sommeNoeuds(A->sag) + sommeNoeuds(A->sad) + A->info;
  }
}

int profMinFeuille(ArbreBin A){
  /* renvoie la profondeur minimum des feuilles de l'arbre A ; A est non vide */
  assert(A!=NULL);
  /* A COMPLETER */
  if(A->sad == NULL && A->sag == NULL){
    return 0;
  }else{
    int droite =0, gauche = 0;
    if(A->sad != NULL){
      droite = profMinFeuille(A->sad) + 1;
    }
    if(A->sag != NULL){
      gauche = profMinFeuille(A->sag) + 1;
    }
    if(droite > gauche){ return gauche;}
    else{ return droite;}
  }
}
    
ListeSC parcoursInfixe(ArbreBin A){
  /* renvoie la liste composee des etiquettes des noeuds de l'arbre A ordonn�e
     selon l'ordre infixe */
  /* A COMPLETER */
  if(A==NULL){
    return NULL;
  }else{
    return concatLSC(parcoursInfixe(A->sag),creerLSC(A->info, parcoursInfixe(A->sad)));
  }
}

void effeuiller(ArbreBin& A){
  /* modifie l'arbre A en supprimant ses feuilles */
  /* A COMPLETER */
  if(A != NULL){
    if(A->sad == NULL && A->sag == NULL){
      A = NULL;
    }else{
      effeuiller(A->sag);
      effeuiller(A->sad);
    }
  }
  return;}

void tailler(ArbreBin& A, int p){
  /* modifie l'arbre A, en supprimant ses noeuds de profondeur au moins p ; p est un entier positif ou nul */
  /* A COMPLETER */
  if(p == 0 && A != NULL){
    A = NULL;
  }else if( A != NULL){
    tailler(A->sag, p-1);
    tailler(A->sad, p-1);
  }
  return;}

void tronconner(ArbreBin& A){
  /* modifie l'arbre A, en supprimant les noeuds dont un seul sous-arbre est vide */
  /* A COMPLETER */
  if(A != NULL){
    tronconner(A->sad);
    tronconner(A->sag);
    if(A->sag != NULL && A->sad == NULL){
      A = A->sag;
    }else if(A->sag == NULL && A->sad != NULL){
      A = A->sad;
    }
  }
  return;}

ArbreBin genereAB(int n){
  /* A COMPLETER */
  if(n == 1){
    return creerArbreBin(n, NULL, NULL);
  }else{
    return creerArbreBin(n, genereAB(n-(n/2)), genereAB(n/2));
  }
  return NULL;}


bool estParfait(ArbreBin A){
  // V�rifie si A est un arbre binaire parfait
  // A finir
  if(A == NULL){
    return true;
  }else if((A->sad == NULL && A->sag != NULL) || (A->sad != NULL && A->sag == NULL)){
    return false;
  }else{
    bool gauche, droite, prof;
    if(A->sad != NULL && A->sag != NULL){
      gauche = estParfait(A->sag);
      droite = estParfait(A->sad);
      prof = profMinFeuille(A->sag) == profMinFeuille(A->sad);
    }else{
      gauche = true; droite = true; prof = true;
    }
    if(gauche && droite && prof){
      return true;
    }else{
      return false;
    }
  }
}

