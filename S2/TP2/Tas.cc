#include <iostream>
#include "Tas.h"

using namespace std;


// ====================
//  TAS ET TRI PAR TAS
// ====================

void afficher(int n, int* T)
{
  cout << "[ ";
  int i = 0;
  for(i; i < n-1; i++){
    cout << T[i] << ", ";
  }
  cout << T[n-1] << " ]"<< endl;
} 

bool estTasMax(int n, int* T)
{
  int i = 0;
  bool valide = true;
  while(2*i < n && valide){
    if(2*i +1 < n){
      if(T[2*i+1] > T[i]){
        valide = false;
      }
    }
    if(2*i +2 < n){
      if(T[2*i+2] > T[i]){
        valide = false;
      }
    }
    i++;
  }
  return valide;
}

bool estTasMin(int n, int* T)
{
  int i = 0;
  bool valide = true;
  while(2*i < n && valide){
    if(2*i +1 < n){
      if(T[2*i+1] < T[i]){
        valide = false;
      }
    }
    if(2*i +2 < n){
      if(T[2*i+2] < T[i]){
        valide = false;
      }
    }
    i++;
  }
  return valide;
}

void tableauManuel(int n, int* T)
{
  int val;
  for(int i = 0; i < n; i++){
    cout << "Rentrez une valeur svp : ";
    cin >> val;
    T[i] = val;
  }
}

void tableauAleatoire(int n, int* T, int m, int M)
{
  //srand(time(NULL));
  int random;
  for(int i = 0; i<n; i++){
    random = rand()%(M+1) + m;
    T[i] = random;
  }
}

void entasser(int n, int* T, int i)
{
  // A compléter
}

void tas(int n, int* T)
{
  // A compléter
}

int* trier(int n, int* T)
{
  int* Ttrie;
  return Ttrie; // A modifier...
}

void trierSurPlace(int n, int* T)
{
  // A compléter
}

