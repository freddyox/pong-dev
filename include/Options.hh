#ifndef OPTIONS_HH
#define OPTIONS_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#define MAX_NUMBER_OPT 4

class Options: public sf::Drawable
{
private:
  float mwidth;
  float mheight;
  std::string mopt1, mopt2, mopt3, mopt4;
  float mcharsize;

  int selectedItemIndex;
  sf::Font font;
  sf::Text options[MAX_NUMBER_OPT];

public:
  Options(float, float);
  ~Options() {};
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  void MoveUp();
  void MoveDown();
  int getPressedItem() { return selectedItemIndex; }

};
#endif
