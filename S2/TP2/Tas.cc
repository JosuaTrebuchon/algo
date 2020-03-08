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
  for(; i < n-1; i++){
    cout << T[i] << ", ";
  }
  cout << T[n-1] << " ]    Taille = "<< n << endl;
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
  int random;
  for(int i = 0; i<n; i++){
    random = rand()%(M+1) + m;
    T[i] = random;
  }
}

void entasser(int n, int* T, int i)
{
  int m = i, g = 2*i+1, d = 2*i+2;
  
  if(g < n && T[g] > T[m]){
    m = g;
  }
  if(d < n && T[d] > T[m]){
    m = d;
  }
  if(m != i){
    int temp = T[i];
    T[i] = T[m];
    T[m] = temp;
    entasser(n, T, m);
  }
}

void tas(int n, int* T)
{
  for(int i = (n/2)-1; i >= 0; i--){
    entasser(n, T, i);
  } 
}

int* trier(int n, int* T)
{
  int* Ttrie = new int[n];
  tas(n, T);
  int taille = n;
  for(int i = n-1; i >= 0; i--){
    Ttrie[i] = T[0];
    T[0] = T[taille-1];
    taille = taille - 1;
    entasser(taille, T, 0);
  }
  return Ttrie;
}

void trierSurPlace(int n, int* T)
{
  tas(n, T);
  int taille = n;
  for(int i = n-1; i >= 0; i--){
    int temp = T[0];
    T[0] = T[taille-1];
    T[taille-1] = temp;
    taille = taille - 1;
    entasser(taille,T, 0);
  }
}

