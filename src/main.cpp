#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "worldcomponent.hpp"
#include "bullet.hpp"
#include "generationBullet.hpp"
#include <iostream>


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
    Transform player{
        .size = (64,64)
    };
    sf::Texture texture;
    if (!texture.loadFromFile("assets/sprite.png")) {
        std::cout << "Hello World!";
        // Gérer l'erreur (fichier introuvable, etc.)
    }
    sf::Sprite playersprite;
    playersprite.setTexture(texture);
    playersprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    player.position.x = player.position.y = 200.f;
    playersprite.setPosition(player.position.x, player.position.y);

    // Create multiple shapes with random starting positions and directions
    for (int i = 0; i < 100; ++i) {

        Bullet bullet=createBullet(windo);
        bullets.push_back(bullet);

        sf::CircleShape shape(bullet.transform.size.x);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(bullet.transform.position.x, bullet.transform.position.y);
        shapes.push_back(shape);
    }

    // Largeur et hauteur de la fenêtre
    int widthWindow = 800, heightWindow = 600;
    // Création d'une fenêtre "render"
    sf::RenderWindow window(
        sf::VideoMode(widthWindow, heightWindow),
        "Titre de la fenêtre",
        sf::Style::Default); // Pour un style personnalisé

    // Boucle principale avec gestion frame par frame
    while (window.isOpen()) {
        // Gestion des évènements
        sf::Event event;
        while (window.pollEvent(event)) {
            // Demande de fermeture (croix de la fenêtre, ALT+F4)
            if (event.type == sf::Event::Closed)
                window.close();
            // D'autres évènements peuvent être gérés ici
        }
        Motion playermotion{
            .speed=2.f
        };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
           playermotion.direction_normalized = {0,-1};
        };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            playermotion.direction_normalized = {-1,0};
        };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            playermotion.direction_normalized = {0,1};
            
        }; 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            playermotion.direction_normalized = {1,0};
        };
        update_position(playermotion,player,0.16f);
        

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
        //std::cout << player.position.x << player.position.y << std::endl;
        playersprite.setPosition(player.position.x,player.position.y);
        window.draw(playersprite);

        // Affiche la nouvelle frame à l'écran
        window.display();
    }
}
