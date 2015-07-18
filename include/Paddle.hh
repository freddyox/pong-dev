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
  std::map<std::string, sf::RectangleShape> PaddleMap;

  sf::Color LeftColor;
  sf::Color RightColor;


public:
  Paddle(std::string); // 1 player
  Paddle(std::string,std::string); //2 players
  ~Paddle() {};
  float width() {return Px;}
  float height() {return Py;}

  void draw(sf::RenderTarget&, sf::RenderStates) const;

  void movePaddle();
  bool HowManyPlayers(); //true for 2 players

  sf::Vector2f positionL() { return Left.getPosition(); }
  sf::Vector2f positionR() { return Right.getPosition(); }
  std::string getLeftName(){ return LeftName; }
  std::string getRightName(){ return RightName; }


  std::map<std::string, sf::RectangleShape>::iterator mit;

};
#endif
