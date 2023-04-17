void afficher_tous_vehicules(t_coin* coin, int type_comportement) {
    int i, j;
    t_vehicule* v; // Déclaration d'un pointeur t_vehicule*
    int nb_vehicules = 0;
    
    // Pour chacune des voies
    for (i = VOIE_GAUCHE; i <= VOIE_DROITE; i++) {
        // On détermine le nombre de véhicules dans la voie.
        nb_vehicules = obtenir_nb_vehicules_dans_voie(coin, i);
        // Boucle pour tous les véhicules de la voie
        for (j = 0; j < nb_vehicules; j++) {
            // Obtenir un véhicule.
            v = obtenir_vehicule_a_position(coin, i, j);
            // Ajuster le comportement du véhicule
            ajuster_comportement(v, type_comportement);
            // Afficher le vehicule
            afficher_vehicule(v);
        }
    }
}

