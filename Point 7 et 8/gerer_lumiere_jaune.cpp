void gerer_lumiere_jaune(double position, double longueur_coin, double longueur_vehicule, int conducteur_avec_delai) {
    double position_finale = position + longueur_vehicule;
    double position_max_arret;
    
    if (conducteur_avec_delai && position_finale > longueur_coin - 3 * longueur_vehicule
        && position_finale < longueur_coin - longueur_vehicule) {
        // Le véhicule décélère d'une DECELERATION_RAPIDE (point 9).
        decelerer_vehicule(v, v.vitesse, DECELERATION_RAPIDE);
    } else if (position_finale > longueur_coin) {
        // Vous enlevez le véhicule de la voie (fonction de « t_coin »).
        // Code pour enlever le véhicule ici
    }
}

