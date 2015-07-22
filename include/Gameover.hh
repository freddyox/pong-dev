#ifndef GAMEOVER_HH
#define GAMEOVER_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Gameover: public sf::Drawable {
private:
  float mwidth;
  float mheight;
  std::string mopt1, mopt2;
  float mcharsize;

  sf::Font font;
  sf::Text game[2];

public:
  Gameover(float,float);
  ~Gameover() {};
  void draw(sf::RenderTarget&, sf::RenderStates) const;
void setWinner(std::string);
};
#endif
