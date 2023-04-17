void ajuster_vitesse_vehicule(Vehicule* vehicule_concerne, Vehicule* vehicule_avant, double distance) {
    double longueur_vehicule = vehicule_concerne->get_longueur();
    double vitesse_max = vehicule_concerne->get_vitesse_max();
    double vitesse_avant = vehicule_avant->get_vitesse();

    if (distance > 2 * longueur_vehicule + vitesse_max + ESPACE_ENTRE_VEHICULES) {
        vehicule_concerne->set_vitesse(vitesse_max);
    }
    else if (distance < 1.5 * longueur_vehicule + ESPACE_ENTRE_VEHICULES) {
        vehicule_concerne->set_vitesse(vitesse_avant);
    }
    else if (distance <= 2 * longueur_vehicule + ESPACE_ENTRE_VEHICULES) {
        double nouvelle_vitesse = vehicule_concerne->get_vitesse() - 1;
        vehicule_concerne->set_vitesse(nouvelle_vitesse);
    }
}

