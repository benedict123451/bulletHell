#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "worldcomponent.hpp"
int main()
{
	Motion motion = {
		.direction_normalized = {1.f,0.f},
		.speed = 10.0f
	};

	Transform transform = {
		.position = {0.f,0.f}
	};

	sf::CircleShape shape(50.0f);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(10.f, 50.f);

// Largeur et hauteur de la fen�tre
int widthWindow = 800, heightWindow = 600;
// Cr�ation d'une fen�tre "render"
sf::RenderWindow window(
	sf::VideoMode(widthWindow, heightWindow),
	"Titre de la fen�tre",
	sf::Style::Default); // Pour un style personnalis�
// Boucle principale avec gestion frame par frame
while(window.isOpen()) {
	// Gestion des �v�nements
	sf::Event event;
	while (window.pollEvent(event)) {
		// Demande de fermeture (croix de la fen�tre, ALT+F4)
		if (event.type == sf::Event::Closed)
			window.close();
		// D'autres �v�nements peuvent �tre g�r�s ici
	}

	update_position(motion, transform, 0.016f);


	// Effacement de l'ancienne frame (framebuffer)
	window.clear(sf::Color::Black);
	sf::CircleShape shape(50.0f);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(10.f, 50.f);
	// ... Ici on dessine les objets, sprites, textes, formes
	// Affiche la nouvelle frame � l'�cran
	window.display();
}
}