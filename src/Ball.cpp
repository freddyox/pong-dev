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

  sf::Vector2f PaddleCenter = ptr->position(); 
  sf::Vector2f PaddleSize( width, height);
  // Make Paddle Rectangle:
  sf::FloatRect PaddleRect(PaddleCenter, PaddleSize);

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
    sf::Vector2f D = BallCenter - PaddleCenter;
    float distance = sqrt( pow(D.x,2) + pow(D.y,2) );

    // Collisions between Ball & Walls:
    if( (BallCenter.y - radius) <= 5.0 ) // top wall
      vy = -vy;
    if( (BallCenter.y + radius) >= displayy - 5.0 ) // bottom wall
      vy = -vy;	
    if ( (BallCenter.x + radius) >=  displayx - 5.0 ) // only for development ---delete
	vx = -vx;
    //if( (BallCenter.x -radius) <= 5.0 ) // only for development ---delete
	//vx = -vx; 

    
    // Collisions between Ball & Paddles
    if( distance < 5.0*radius ) {
      if( BallRect.intersects( PaddleRect ) && vx < 0.0 ) {
      	vx = -vx;
      	bounceNumber++;
      }
    }

      
    it->move(vx,vy);
  }
}
