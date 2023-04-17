void ajuster_vitesse_si_seul_en_avant(int coin_rue, struct vehicule* vehicule_concerne, struct vehicule* vehicule_en_avant, int delai_depart, int couleur_feu) {
    double distance = calculer_distance(coin_rue, vehicule_concerne, vehicule_en_avant);
    double vitesse_max = vehicule_concerne->vitesse_max;
    
    if (vehicule_en_avant == NULL) {
        if (couleur_feu == ROUGE) {
            gerer_lumiere_rouge();
        }
        else if (couleur_feu == JAUNE) {
            gerer_lumiere_jaune();
        }
        else {
            vehicule_concerne->set_vitesse(vitesse_max);
        }
    }
    else {
        double vitesse_en_avant = vehicule_en_avant->vitesse;
        double longueur_vehicule = vehicule_concerne->longueur;
        double espace_entre_vehicules = ESPACE_ENTRE_VEHICULES;
        
        if (distance > 2 * longueur_vehicule + vitesse_max + espace_entre_vehicules) {
            vehicule_concerne->set_vitesse(vitesse_max);
        }
        else if (distance < 1.5 * longueur_vehicule + espace_entre_vehicules) {
            vehicule_concerne->set_vitesse(vitesse_en_avant);
        }
        else if (distance <= 2 * longueur_vehicule + espace_entre_vehicules) {
            vehicule_concerne->decelerer(1);
        }
    }
}

