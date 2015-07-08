#ifndef MENU_HH
#define MENU_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#define MAX_NUMBER 3

class Menu: public sf::Drawable
{
private:
float mwidth;
float mheight;
std::string mopt1, mopt2, mopt3;
float mcharsize;

int selectedItemIndex;
sf::Font font;
sf::Text menu[MAX_NUMBER];

public:
Menu(float, float);
~Menu() {};
void draw(sf::RenderTarget&, sf::RenderStates) const;
void MoveUp();
void MoveDown();
int getPressedItem() { return selectedItemIndex; }

};
#endif
