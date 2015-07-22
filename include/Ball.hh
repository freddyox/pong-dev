#ifndef BALL_HH
#define BALL_HH

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
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
  bool LeftScoreBool, RightScoreBool;
  int RightScore, LeftScore;


public:
  Ball();
  ~Ball() {};
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  float getRadius() { return mradius;}
  void update(Paddle*);
  int getRightScore() { return RightScore; }
  int getLeftScore() { return LeftScore; }

  bool didLeftPaddleScore() { return LeftScoreBool; }
  bool didRightPaddleScore() { return RightScoreBool; }

  bool setLeftBool(bool temp) { LeftScoreBool = temp; }
  bool setRightBool(bool temp) { RightScoreBool = temp; }
  void ballupdate();
  void loadsound();

  // sf::Sound ballsound;
  // sf::SoundBuffer ballsoundbuffer;

};


#endif
