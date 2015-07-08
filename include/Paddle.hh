#ifndef PADDLE_HH
#define PADDLE_HH

//#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <vector>

class Paddle : public sf::Transformable, public sf::Drawable
{
private:
  int displayx, displayy;
  float mvelocity, mtime, posAcc, negAcc;
  float Px, Py; // dimensions of paddle
  sf::Vector2f PaddleSize;
  sf::RectangleShape Left, Right;
  std::string LeftName, RightName;
  std::vector<std::string> PaddleVec;
  std::vector<sf::RectangleShape> PaddleVector;
  std::map<std::string, sf::RectangleShape> PaddleMap;

  sf::Color LeftColor;
  sf::Color RightColor;

public:
  Paddle(std::string);
  ~Paddle() {};
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  void movePaddle();
  void initialize();
  float width() {return Px;}
  float height() {return Py;}
  sf::Vector2f position() { return Left.getPosition(); }

  std::string getLeftName(){ return LeftName; }
  std::string getRightName(){ return RightName; }

};
#endif
