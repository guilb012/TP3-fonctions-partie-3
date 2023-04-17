#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "t_liste_h.h"

void init_liste(t_liste liste, int capacite)
{
    liste->tab_donnees = NULL;
    liste->tab_donnees=(t_element*)malloc(capacite * sizeof(t_element));
    if(liste->tab_donnees!=NULL){
        liste->capacite=capacite;
        liste->nb_elements = 0;
    } else {
        // Error handling: free previously allocated memory and exit
        free(liste);
        printf("Error: unable to allocate memory for list data.\n");
        exit(EXIT_FAILURE);
    }
}

t_element obtenir_element(const t_liste liste, int position)
{
    if(liste->capacite!=0 && !liste_est_vide(liste)
      && position>=0 && position<obtenir_nb_elements(liste)){
      return liste->tab_donnees[position];
    }
    return NULL;
}

int obtenir_nb_elements(const t_liste  liste)
{
    if(liste->capacite!=0){
      return liste->nb_elements;
    }
    return 0;
}

bool liste_est_vide(const t_liste liste)
{
    if (liste->capacite!=0 && obtenir_nb_elements(liste)==0){
      return true;
    }
    return false;
}

bool liste_est_pleine(const t_liste  liste){
    if (liste->capacite!=0 && obtenir_nb_elements(liste)==liste->capacite){
      return true;
    }
    return false;
}

void inserer_apres_dernier(t_liste  liste, t_element element) {
    if (liste->capacite!=0 && liste_est_pleine(liste)==false){
      liste->tab_donnees[obtenir_nb_elements(liste)]=element;
      liste->nb_elements++;
    }
}

void inserer_a_la_position(t_liste liste, t_element element, int position){
    if(liste->capacite!=0 && liste_est_pleine(liste)==false
      && position>=0 && position<=obtenir_nb_elements(liste)){
      for(int i=obtenir_nb_elements(liste);i>position;i--){
        liste->tab_donnees[i]=liste->tab_donnees[i-1];
      }
      liste->tab_donnees[position]=element;
      liste->nb_elements++;
    }
}

void supprimer_element(t_liste* liste, int position)
{
    if((*liste)->capacite!=0 && liste_est_vide(*liste)==false
      && position>=0 && position<obtenir_nb_elements(*liste)){
       for(int i=obtenir_nb_elements(*liste)-1;i>position;i--){
        (*liste)->tab_donnees[i-1]=(*liste)->tab_donnees[i];
       }
       (*liste)->nb_elements--;
    }
}

