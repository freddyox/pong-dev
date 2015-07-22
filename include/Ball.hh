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

  sf::Sound ballsound;
  sf::SoundBuffer ballsoundbuff;

public:
  Ball();
  ~Ball() {};
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  float getRadius() { return mradius;}

  int getRightScore() { return RightScore; }
  int getLeftScore() { return LeftScore; }
  void setRightScore(int temp) {RightScore = temp;}
  void setLeftScore(int temp) {LeftScore = temp;}

  bool didLeftPaddleScore() { return LeftScoreBool; }
  bool didRightPaddleScore() { return RightScoreBool; }
  bool setLeftBool(bool temp) { LeftScoreBool = temp; }
  bool setRightBool(bool temp) { RightScoreBool = temp; }

  void update(Paddle*);
  void ballupdate();
  void loadsound();

};


#endif
