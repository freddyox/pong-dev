#include "../include/Ball.hh"
#include "../include/Paddle.hh"

#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iostream>

Ball::Ball(){
  displayx = 800.0;
  displayy = 500.0;
  mradius = 8.0;
  bounceNumber = 0.0;
  dT = 1/200.0;
  vx = 5.0;
  vy = 5.0;
  deltaV = 0.3;
 
  srand( time(NULL) );
  float randy = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(displayy-10)) );

  // Needs updating,
  Posx = (displayx-mradius)/2.0;
  Posy = randy/2.0 + 5.0;
  angle = rand() % 361;
  angle*=3.1415/180.0;

  ball.setRadius(mradius);
  sf::FloatRect recttemp = ball.getLocalBounds();
  ball.setOrigin( 0.5*(recttemp.width), 0.5*(recttemp.height) );
  ball.setFillColor(sf::Color(222,232,245));
  // Initialize position
  ball.setPosition( Posx, Posy );
  ballVector.push_back( ball );

  LeftScoreBool = false;
  RightScoreBool = false;
  RightScore = 0;
  LeftScore = 0;
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates) const {
std::vector<sf::CircleShape>::const_iterator it;
  for( it=ballVector.begin(); it!=ballVector.end(); ++it)
    target.draw(*it);
}

void Ball::update(Paddle *ptr) {

  // Center of Paddle
  float width = ptr->width();
  float height = ptr->height();
  sf::Vector2f PaddleSize( width, height);

  // LEFT:
  sf::Vector2f PaddleCenterL = ptr->positionL(); 
  // Make Paddle Rectangle:
  sf::FloatRect PaddleRectL(PaddleCenterL, PaddleSize);
  // RIGHT:
  sf::Vector2f PaddleCenterR = ptr->positionR(); 
  // Make Paddle Rectangle:
  sf::FloatRect PaddleRectR(PaddleCenterR, PaddleSize);
  std::vector<sf::CircleShape>::iterator it;
  for( it=ballVector.begin(); it!=ballVector.end(); ++it) {
    //Center Coordinates of Ball
    sf::Vector2f BallCenter = it->getPosition();
    sf::FloatRect temp = it->getLocalBounds();
    float radius = (temp.width)/2.0;

    // Make Ball Rectangle:
    sf::Vector2f BallSize( temp.width, temp.height);
    sf::FloatRect BallRect(BallCenter, BallSize);

    // Distance between the two:
    sf::Vector2f DLeft = BallCenter - PaddleCenterL;
    float distanceLeft = sqrt( pow(DLeft.x,2) + pow(DLeft.y,2) );
    sf::Vector2f DRight = BallCenter - PaddleCenterR;
    float distanceRight = sqrt( pow(DRight.x,2) + pow(DRight.y,2) );

    // Collisions between Ball & Walls:
    if( (BallCenter.y - radius) <= 5.0 ) // top wall
      vy = -vy;
    if( (BallCenter.y + radius) >= displayy - 5.0 ) // bottom wall
      vy = -vy;	
    
    // Collisions between Ball & Paddles
    if( distanceLeft < 5.0*radius ) {
      if( BallRect.intersects( PaddleRectL ) && vx < 0.0 ) {
      	vx = -vx;
      	bounceNumber++;
      }
    }
    if( distanceRight < 5.0*radius ) {
      if( BallRect.intersects( PaddleRectR ) && vx > 0.0 ) {
      	vx = -vx;
      	bounceNumber++;
      }
    }
    it->move(vx,vy);

    // Handle Scoring
    if( (BallCenter.x - radius/2.0) < 0 ) {
      if( (BallCenter.x - radius/2.0) < 0 && (BallCenter.x - radius/2.0) >= -3 ) {
	RightScore++;
	RightScoreBool = true; //Right Paddle Scored
      }
    }
    if( (BallCenter.x - radius/2.0) > displayx ) {
      if( (BallCenter.x - radius/2.0) > displayx && (BallCenter.x - radius/2.0) <= displayx+3 ) {
	LeftScore++;
	LeftScoreBool = true; //Left Paddle Scored
      }
    }
  }
}

void Ball::ballupdate() {
  std::vector<sf::CircleShape>::iterator it;
  for( it=ballVector.begin(); it!=ballVector.end(); ++it) {
    sf::Vector2f BallCenter = it->getPosition();
    if( BallCenter.x < 0 || BallCenter.x > displayx ) {
      (*it).setPosition( Posx, Posy );
    }
  }  
}
