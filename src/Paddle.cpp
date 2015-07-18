#include "../include/Paddle.hh"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

Paddle::Paddle(std::string left) {
  displayx = 800;
  displayy = 500;
  LeftName = left;
  
  Px = 8.0;
  Py = 60.0;
  mvelocity = 300.f;
  mtime = 1/60.0;
  posAcc = 5*0.1;
  negAcc = 10*0.1;
  sf::Color LeftColor = sf::Color(181,10,73);
  sf::Vector2f PaddleSize = sf::Vector2f( Px, Py );

  Left.setSize( PaddleSize );
  Left.setOrigin( Px/2.0, Py/2.0 );
  Left.setFillColor( LeftColor );
  Left.setPosition( Px/2.0 + 4.0, displayy/2.0 );

  PaddleVec.push_back(LeftName);
  PaddleMap[LeftName] = Left;
}

Paddle::Paddle(std::string left, std::string right) {
  displayx = 800;
  displayy = 500;
  LeftName = left;
  RightName = right;
  
  Px = 8.0;
  Py = 60.0;
  sf::Vector2f PaddleSize = sf::Vector2f( Px, Py );

  mvelocity = 300.f;
  mtime = 1/60.0;
  posAcc = 5*0.1;
  negAcc = 10*0.1;

  sf::Color LeftColor = sf::Color(181,10,73);
  sf::Color RightColor = sf::Color(17,191,11);

  Left.setSize( PaddleSize );
  Left.setOrigin( Px/2.0, Py/2.0 );
  Left.setFillColor( LeftColor );
  Left.setPosition( Px/2.0 + 4.0, displayy/2.0 );

  Right.setSize( PaddleSize );
  Right.setOrigin( Px/2.0, Py/2.0 );
  Right.setFillColor( RightColor );
  Right.setPosition( displayx - Px/2.0 - 4.0, displayy/2.0 );
  
  PaddleVec.push_back( LeftName );
  PaddleVec.push_back( RightName );
  PaddleMap[LeftName] = Left;
  PaddleMap[RightName] = Right;
}

bool Paddle::HowManyPlayers() {  
  if( PaddleMap.size()==1 ) {
    return false;
  }
  else if( PaddleMap.size() == 2 ) {
    return true;
  }
  else
    std::cerr << "ERROR: Number of Paddles is incorrect!" << std::endl;
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates) const {
  target.draw( Left );
  target.draw( Right );
}

void Paddle::movePaddle() {
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ){
    if( Left.getPosition().y >= Py/2.0 ) {
      mvelocity += posAcc;
    }
    else {
      if( fabs(mvelocity) <= posAcc ) {
	mvelocity = 0.0;
      }
      else {
	mvelocity -= negAcc;
      }
    }
    if( Left.getPosition().y >= Py/2.0 )
      Left.move( 0, -mvelocity*mtime );
  }

  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
    if( Left.getPosition().y <  displayy - Py/2.0 ) {
      mvelocity += posAcc;
    }
    else {
      if( fabs(mvelocity) <= posAcc ) {
	mvelocity = 0.0;
      }
      else {
	mvelocity -= negAcc;
      }
    }
    if( Left.getPosition().y < displayy - Py/2.0 ) 
      Left.move( 0, mvelocity*mtime );
  }

  if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ){
    if( Right.getPosition().y >= Py/2.0 ) {
      mvelocity += posAcc;
    }
    else {
      if( fabs(mvelocity) <= posAcc ) {
	mvelocity = 0.0;
      }
      else {
	mvelocity -= negAcc;
      }
    }
    if( Right.getPosition().y >= Py/2.0 )
      Right.move( 0, -mvelocity*mtime );
  }

  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ) {
    if( Right.getPosition().y <  displayy - Py/2.0 ) {
      mvelocity += posAcc;
    }
    else {
      if( fabs(mvelocity) <= posAcc ) {
	mvelocity = 0.0;
      }
      else {
	mvelocity -= negAcc;
      }
    }
    if( Right.getPosition().y < displayy - Py/2.0 ) 
      Right.move( 0, mvelocity*mtime );
  }

}
