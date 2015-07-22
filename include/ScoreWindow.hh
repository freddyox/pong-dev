#ifndef SCOREWINDOW_HH
#define SCOREWINDOW_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class ScoreWindow: public sf::Drawable
{
private:
  float mwidth;
  float mheight;
  std::string mopt1, mopt2, mopt3, mopt4;
  float mcharsize;

  sf::Font font;
  sf::Text score[2];
  
public:
  ScoreWindow(float, float);
  ~ScoreWindow() {};
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  void updateScore(int,int); //might need a pointer
  
};
#endif
