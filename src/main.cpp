#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
int main()
{
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
	// Effacement de l'ancienne frame (framebuffer)
	window.clear(sf::Color::Black);
	// ... Ici on dessine les objets, sprites, textes, formes
	// Affiche la nouvelle frame � l'�cran
	window.display();
}
}