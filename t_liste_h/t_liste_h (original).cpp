/**
 * Implmente la liste semi-dynamique dcrite dans t_liste_h23.h.
 *
  Auteur ; Pierre Blisle
  Version : Copyright H2023
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>  // Pour les cas d'exception
#include "t_liste_h.h"


/* La liste vide est initialise avec la capacit demande.*/
void init_liste(t_liste liste, int capacite)
{
 // liste = (t_liste)malloc(capacite * sizeof(struct_t_liste));
 // if (liste != NULL) {
    liste->tab_donnees = NULL;
    liste->tab_donnees=(t_element*)malloc(capacite * sizeof(t_element));
    if(liste->tab_donnees!=NULL){
        liste->capacite=capacite;
        liste->nb_elements = 0;
    }
  //}
}

/*
    Retourne l'lment qui se trouve  la position fournie.

   La liste doit avoir t initialise.
   La liste ne doit pas tre vide.
   La position doit tre entre 0 et get_nb_elements(liste) - 1.
*/
t_element obtenir_element(const t_liste liste, int position)
{
    if(liste->capacite!=NULL && liste_est_vide(liste)==false
      && position>=0 && position<obtenir_nb_elements(liste)){
      return liste->tab_donnees[position];
    }
    // Pour la compilation
    return NULL;
}

/*
    Retourne le nombre d'lments de la liste.
  
    La liste doit avoir t initialise.
  */
int obtenir_nb_elements(const t_liste  liste)
{
    if(liste->capacite!=NULL){
      return liste->nb_elements;
    }
    
    // Pour la compilation
    return 0;

}


/*
    Retourne si la liste est vide ou non.

    La liste doit avoir t initialise.
*/
bool liste_est_vide(const t_liste liste)
{

    if (liste->capacite!=NULL && obtenir_nb_elements(liste)==0){
      return true;
    }

    // Pour la compilation
    return false;

}

/*
    Retourne si la liste est pleine ou non.

    La liste doit avoir t initialise.
*/
bool liste_est_pleine(const t_liste  liste){

    if (liste->capacite!=NULL && obtenir_nb_elements(liste)==liste->capacite){
      return true;
    }

    // Pour la compilation
    return false;

}


/*
    Insre aprs le dernier lment de la liste.

    La liste doit avoir t initialise et elle n'est pas pleine.
*/
void inserer_apres_dernier(t_liste  liste, t_element element) {
    if (liste->capacite!=NULL && liste_est_pleine(liste)==false){
      //On ajoute un élément après le dernier élément de la liste
      liste->tab_donnees[obtenir_nb_elements(liste)]=element;
      //On ajoute un élément au compte
      liste->nb_elements++;
    }
}

/*
   Insre un lment dans la liste  la position fournie  l'appel.
   (Cela a pour effet d'insrer devant l'lment actuellement en place, qui
   est dcal  droite ainsi que les lments subsquents).

   La liste doit avoir t initialise et elle n'est pas pleine.
   La position doit tre entre 0 et get_nb_elements(liste) - 1.

   */
void inserer_a_la_position(t_liste liste, t_element element, int position){

    if(liste->capacite!=NULL && liste_est_pleine(liste)==false
      && position>=0 && position<=obtenir_nb_elements(liste)){
      for(int i=obtenir_nb_elements(liste);i>position;i--){
        /*On décale vers la droite, donc de +1, tous les éléments du
          tableau de données après l'élément de la position fournie.*/
        liste->tab_donnees[i]=liste->tab_donnees[i-1];
             
      }
      //On insère l'élément à la position fournie
      liste->tab_donnees[position]=element;
      //On ajoute un élément au compte
      liste->nb_elements++;
    }

}

/*
  Supprime l'lment  la position fournie.
  
  La liste doit avoir t initialise et elle n'est pas vide.
  La position doit tre entre 0 et get_nb_elements(liste) - 1.

 */
void supprimer_element(t_liste* liste, int position)
{
    if((*liste)->capacite!=NULL && liste_est_vide(*liste)==false
      && position>=0 && position<obtenir_nb_elements(*liste)){
       for(int i=obtenir_nb_elements(*liste)-1;i>position;i--){
        //On décale vers la gauche, donc de -1, tous les éléments du tableau de données après l'élément de la position fournie.
        (*liste)->tab_donnees[i-1]=(*liste)->tab_donnees[i];
      }
      //On enlève un élément au compte
      (*liste)->nb_elements--;
    }
}

/*
    Libre la mmoire alloue pour la collection.
*/
void liberer_liste(t_liste liste)
{
  free(liste->tab_donnees);
  liste->capacite =0;
  liste->nb_elements = 0;
}







/*****Test unitaires?******/

void test_init_liste(t_liste liste, int capacite){
  assert(liste->tab_donnees!=NULL && liste->capacite==capacite && liste->nb_elements == 0);
}

/*
    Retourne l'lment qui se trouve  la position fournie.

   La liste doit avoir t initialise.
   La liste ne doit pas tre vide.
   La position doit tre entre 0 et get_nb_elements(liste) - 1.
*/
void test_obtenir_element(const t_liste liste, int position){
  //assert();
}

/*
    Retourne le nombre d'lments de la liste.
  
    La liste doit avoir t initialise.
  */
void test_obtenir_nb_elements(const t_liste liste);

/*
    Retourne si la liste est pleine ou non.

    La liste doit avoir t initialise.
*/
void test_liste_est_pleine(const t_liste liste);

/*
    Retourne si la liste est vide ou non.

    La liste doit avoir t initialise.
*/
void test_liste_est_vide(const t_liste liste);


/*
    Insre aprs le dernier lment de la liste.

    La liste doit avoir t initialise et elle n'est pas pleine.
*/
void test_inserer_apres_dernier(t_liste  liste, t_element element);


/*
   Insre un lment dans la liste  la position fournie  l'appel.
   (Cela a pour effet d'insrer devant l'lment actuellement en place, qui
   est dcal  droite ainsi que les lments subsquents).

   La liste doit avoir t initialise et elle n'est pas pleine.
   La position doit tre entre 0 et get_nb_elements(liste) - 1.

   */
void test_inserer_a_la_position(t_liste  liste, t_element element, int position);

/*
  Supprime l'lment  la position fournie.
  
  La liste doit avoir t initialise et elle n'est pas vide.
  La position doit tre entre 0 et get_nb_elements(liste) - 1.

 */
void test_supprimer_element(t_liste* liste, int position);

/*
    Libre la mmoire alloue pour la collection.
*/
void test_liberer_liste(t_liste liste);
