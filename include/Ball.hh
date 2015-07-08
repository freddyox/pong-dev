#ifndef BALL_HH
#define BALL_HH

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector> 

class Paddle;

class Ball: public sf::Drawable, public sf::Transformable
{
private:
  sf::CircleShape ball;
  float mradius;
  float dT;
  float Posx, Posy;
  float angle, vx, vy;
  float displayx;
  float displayy;
  float bounceNumber;
  float deltaV;
  std::vector<sf::CircleShape> ballVector;

public:
  Ball();
  ~Ball() {};
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  float getRadius() { return mradius;}
  void update(Paddle*);
};


#endif
