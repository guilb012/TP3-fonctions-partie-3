void gerer_lumiere_rouge(double position, double longueur, double espacement, int avec_delai, double longueur_coin) {
    double position_finale = position + longueur + espacement;
    
    if (position_finale >= longueur_coin) {
        if (avec_delai) {
            set_vit_vehicule(0);
        } else {
            double vitesse_arret = (longueur_coin - position) / 2;
            set_vit_vehicule(vitesse_arret);
        }
    } else {
        if (avec_delai && position + 1.5 * longueur >= longueur_coin - espacement) {
            set_vit_vehicule(0);
        } else if (position_finale > longueur_coin - 3 * longueur) {
            while (get_vit_vehicule() > 0) {
                set_vit_vehicule(get_vit_vehicule() - DECELERATION_RAPIDE);
            }
        } else {
            set_vit_vehicule(VITESSE_MAX);
        }
    }
}

