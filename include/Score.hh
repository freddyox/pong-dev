#ifndef SCORE_HH
#define SCORE_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Score: public sf::Drawable
{
private:
  float mwidth;
  float mheight;
  std::string mopt1, mopt2;
  float mcharsize;

  sf::Font font;
  sf::Text score[2];
  
public:
  Score(float, float);
  ~Score() {};
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  void updateScore(); //might need a pointer
  
};
#endif
