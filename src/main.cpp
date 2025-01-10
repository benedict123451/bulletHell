#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "worldcomponent.hpp"
#include "bullet.hpp"
#include "generationBullet.hpp"


int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation

    /*std::vector<Motion> motions;
    std::vector<Transform> transforms;*/
    std::vector<Bullet> bullets;
    std::vector<sf::CircleShape> shapes;
    Transform windo{
        .size = (800,600)
    };


    // Create multiple shapes with random starting positions and directions
    for (int i = 0; i < 100; ++i) {

        Bullet bullet=createBullet(windo);
        bullets.push_back(bullet);

        sf::CircleShape shape(bullet.transform.size.x);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(bullet.transform.position.x, bullet.transform.position.y);
        shapes.push_back(shape);
    }

    // Largeur et hauteur de la fen�tre
    int widthWindow = 800, heightWindow = 600;
    // Cr�ation d'une fen�tre "render"
    sf::RenderWindow window(
        sf::VideoMode(widthWindow, heightWindow),
        "Titre de la fen�tre",
        sf::Style::Default); // Pour un style personnalis�

    // Boucle principale avec gestion frame par frame
    while (window.isOpen()) {
        // Gestion des �v�nements
        sf::Event event;
        while (window.pollEvent(event)) {
            // Demande de fermeture (croix de la fen�tre, ALT+F4)
            if (event.type == sf::Event::Closed)
                window.close();
            // D'autres �v�nements peuvent �tre g�r�s ici
        }

        for (size_t i = 0; i < shapes.size(); ++i) {
            update_position(bullets[i].motion, bullets[i].transform, 0.016f);
            shapes[i].setPosition(bullets[i].transform.position.x, bullets[i].transform.position.y);
        }

        // Effacement de l'ancienne frame (framebuffer)
        window.clear(sf::Color::Black);

        // Dessin des objets
        for (const auto& shape : shapes) {
            window.draw(shape);
        }

        // Affiche la nouvelle frame � l'�cran
        window.display();
    }
}
