void simuler_comportement_coin(t_coin* coin, int comportement) {
    // Préparer les voies du coin
    preparer_voies_coin(coin);
    
    int i, j;
    t_vehicule* v;
    int nb_vehicules;
    
    // Pour chacune des voies
    for (i = VOIE_GAUCHE; i <= VOIE_DROITE; i++) {
        nb_vehicules = obtenir_nb_vehicules_dans_voie(coin, i);
        
        // Boucle pour tous les véhicules de la voie
        for (j = 0; j < nb_vehicules; j++) {
            v = obtenir_vehicule_a_position(coin, i, j);
            
            // Ajuster le comportement selon le coin de rue
            if ((coin->type == COIN_GAUCHE && i == VOIE_GAUCHE) ||
                (coin->type == COIN_DROIT && i == VOIE_DROITE)) {
                ajuster_comportement(coin, v, comportement);
            }
            
            // Déplacer le véhicule
            deplacer_vehicule(v);
        }
    }
}

void ajuster_comportement(t_coin* coin, t_vehicule* vehicule, int comportement) {
    int no_voie = get_no_voie(vehicule);
    int position_x = get_position_x(vehicule);
    int vitesse = get_vitesse(vehicule);
    int longueur = get_longueur(vehicule);
    int delai_depart = get_delai_depart(vehicule);
    int vitesse_max = get_vitesse_max_coin(coin);
    int longueur_coin = get_longueur_coin(coin);

    t_vehicule* vehicule_avant = obtenir_vehicule_devant(coin, no_voie, position_x);
    
    // Si le véhicule dépasse le coin de rue
    if (position_x + longueur - 2 * ESPACE_ENTRE_VEHICULES > longueur_coin) {
        enlever_vehicule_tete(coin, no_voie);
    }
    // Sinon si la lumière n'est pas rouge (RED), le véhicule est AVEC_DELAI,
    // le véhicule est arrêté et que la lumière est verte (GREEN)
    else if (get_couleur_feu(coin) != RED && comportement == AVEC_DELAI && vitesse == 0 && get_couleur_feu(coin) == GREEN) {
        // On maintient le véhicule à l'arrêt
        vehicule->temps_arret++;
    }
    // Sinon si le véhicule est avec délai et le délai n'est pas égal à 0
    else if (comportement == AVEC_DELAI && delai_depart != 0) {
        set_delai_depart(vehicule, delai_depart - 1);
    }
    // Sinon s'il n'y a pas de véhicule en avant
    else if (vehicule_avant == NULL) {
        gerer_vehicule_tete(coin, vehicule, comportement, vitesse_max);
    }
    // Sinon ajuster la vitesse
    else {
        ajuster_vitesse(coin, vehicule, vehicule_avant, comportement, vitesse_max);
    }
}
