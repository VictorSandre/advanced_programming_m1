#include <iostream>
#include <random>
#include <chrono>
#include "Image.h"

void updatePixelRandomly(Pixel& pixel);
void updateImageRandomly(Image& image);

/**
 * TP1 exercice 3.
 *
 * Bien commenter tous les "cout" avant de lancer le test de rapidité.
 *
 * @return
 */
int main() {
    Image image(5, 4);

    // Nombre d'itération pour la boucle a changer. Flemme de faire un cin>>.
    const int n = 100;

    for (int i = 0; i < n; ++i) {
        updateImageRandomly(image);
    }
    return 0;
}

/**
 * Modification de tous les pixels d'une image.
 *
 * Les valeurs R,G,B des pixels reçoivent des valeurs aléatoires comprises entre [0;255].
 *
 * @param image une image passé par référence pour éviter la copie.
 */
void updateImageRandomly(Image& image) {
    for (int i = 0; i < image.getHeight()*image.getWidth() ; ++i) {
        updatePixelRandomly(image[i]);
    }
}

/**
 * Modie le caractériques R,G,B d'un Pixel.
 *
 * @param pixel référence au pixel donné pour éviter une copie.
 */
void updatePixelRandomly(Pixel& pixel) {
    // Le timeSinceEpoch permet de faire passer le rand a un srand.
    unsigned long timeSinceEpoch = std::chrono::system_clock::now().time_since_epoch().count();
    // Moteur qui permet de générer des nombres pseudo-aléatoires.
    std::default_random_engine randomEngine(timeSinceEpoch);

    // Choix de la loi de distribution (uniform, bernoulli, ...).
    std::uniform_int_distribution<int> distrib {0, 255};

    // Mise a jour du pixel.
    pixel.setR(distrib(randomEngine));
    pixel.setG(distrib(randomEngine));
    pixel.setB(distrib(randomEngine));
}
