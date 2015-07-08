#ifndef TABLEMAP_HH
#define TABLEMAP_HH

#include <SFML/Graphics.hpp>

class TableMap : public sf::Drawable
{
private:
float displayx, displayy;
float LineWidth;
sf::RectangleShape TableLineTop, TableLineBot, TableLineLeft, TableLineRight, TableLineCenter;

public:
TableMap(float, float);
~TableMap() {};
void draw(sf::RenderTarget&, sf::RenderStates) const;


};
#endif
