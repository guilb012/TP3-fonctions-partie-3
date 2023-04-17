void decelerer_vehicule(t_vehicule* v, double vit, double deceleration) {
    double nouvelle_vitesse = vit - deceleration;
    if (nouvelle_vitesse < 0.1) {
        nouvelle_vitesse = 0.1; // vitesse minimale pour éviter de s'arrêter complètement
    }
    v->vitesse = nouvelle_vitesse;
}

