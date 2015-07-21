//    ************************************************************
//    *               Freddy Obrecht's Emulated Pong             *
//    *                        June 2015                         *
//    ************************************************************
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../include/Menu.hh"
#include "../include/Options.hh"
#include "../include/Paddle.hh"
#include "../include/Ball.hh"
#include "../include/Starmap.hh"
#include "../include/TableMap.hh"
#include "../include/Score.hh"
#include "../include/ScoreWindow.hh"

#include <iostream>


const float gDisplayx = 800;
const float gDisplayy = 500;
int main() {
  //GAME SETUP
  sf::RenderWindow window(sf::VideoMode(gDisplayx,gDisplayy), "PONG - Obrecht");
  window.setFramerateLimit(60);

  // Initialize the Menu
  Menu menu( window.getSize().x, window.getSize().y );
  bool menuBool = true; //Boolean to clear Menu

  Options options( window.getSize().x, window.getSize().y );
  bool optionsBool = false;
  bool computerAIBool = false;
  bool playertwoBool = true; //default behavior

  // Initialize Score
  Score score( window.getSize().x, window.getSize().y );
  ScoreWindow scorewindow( window.getSize().x, window.getSize().y );

  // Initialize the TableMap
  sf::Color PongTableColor = sf::Color(4,27,90);
  TableMap tablemap( window.getSize().x, window.getSize().y );

  // Initialize the Paddles
  Paddle Paddles("Player 1","Player 2");
  
  // AI Paddle
  Paddle Paddle("Player 1");

  // Initialize the Ball
  Ball ball;

  while( window.isOpen() ) {
    sf::Event event;
    while( window.pollEvent(event) ) {
	if( event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ) {
	  window.close();
	}
	// Handling Menu Options:
	if( menuBool ) {
	  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) ) {
	    menu.MoveUp();
	  }
	  else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) ) {
	    menu.MoveDown();
	  }
	  else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Return ) ) {
	    switch( menu.getPressedItem() ) {
	    case 0:
	      menuBool = false;
	      break;
	    case 1:
	      menuBool = false;
	      optionsBool = true;
	      break;
	    case 2:
	      window.close();
	      break;
	    }
	  }
	}
	if( optionsBool ) {
	  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) ) {
	      options.MoveUp();
	    }
	    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) ) {
	      options.MoveDown();
	    }
	    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Return ) ) {
	      switch( options.getPressedItem() ) {
	      case 1:
		computerAIBool = true;
		playertwoBool = false;
		break;
	      case 2:
		playertwoBool = true;
		break;
	      case 3:
		optionsBool = false;
		menuBool = true;
		break;
	      }
	    }
	}
    }
    
    //DRAWING - Layers of draw commands, i.e. first is layer one
    // Menu at beginning of game
    if( menuBool && !optionsBool) {
      window.clear();
      window.draw(menu); 
    }
    // If Options is pushed
    if( optionsBool ) {
      window.clear();
      window.draw(options); 
    }
    if( !menuBool && !optionsBool ) {
      // Table Lines
      window.clear(PongTableColor);
      window.draw(tablemap);

      // Score
      window.draw(score);

      // Paddles
      if( playertwoBool ) {
	window.draw(Paddles);
	Paddles.movePaddle();
      }

      // Computer AI
      if( computerAIBool ){
      }

      // Ball
      window.draw(ball);
      ball.update(&Paddles);

      // Score Keeper
      if(ball.didLeftPaddleScore() || ball.didRightPaddleScore() ) {
	window.clear();
	window.draw(scorewindow);
      }
    }
    // Clean up / Updates
    window.display();
    
  }
  return 0;
}
