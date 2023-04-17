//Fonction pour déplacer tous les véhicules en utilisant la fonction d'ajustement de comportement
void deplacer_tous_vehicules(t_coin* coin, int type_comportement) {
    int i, j;
    t_vehicule* v; // Modification : utiliser un pointeur à la place d'une variable
    int nb_vehicules;

    // Pour chacune des voies
    for(i = VOIE_GAUCHE; i <= VOIE_DROITE; i++) {
        // On détermine le nombre de véhicules dans la voie.
        nb_vehicules = obtenir_nb_vehicules_dans_voie(coin, i);
        // Boucle pour tous les véhicules de la voie
        for(j = 0; j < nb_vehicules; j++) {
            // Obtenir un pointeur vers le véhicule.
            v = obtenir_pointeur_vehicule_a_position(coin, i, j); // Modification : utiliser obtenir_pointeur_vehicule_a_position() à la place de obtenir_vehicule_a_position()
            // Ajuster le comportement du véhicule
            ajuster_comportement(coin, v, type_comportement); // Modification : passer le pointeur de coin en paramètre
            // Deplacer le vehicule.
            deplacer_vehicule(v);
        }
    }
}

