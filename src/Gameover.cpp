#include "../include/Gameover.hh"

Gameover::Gameover(float width, float height) {
  if( !font.loadFromFile("fonts/arial.ttf") ) {
    std::cerr << "Error handling the fonts" << std::endl;
  }
  mwidth = width;
  mheight = height;
  mopt1 = "GAMEOVER";
  mopt2 = "0";
  mcharsize = 50.0;

  game[0].setFont(font);
  game[0].setColor(sf::Color::Red);
  game[0].setString(mopt1);
  game[0].setCharacterSize(mcharsize);
  sf::FloatRect textRect = game[0].getLocalBounds();
  game[0].setPosition( sf::Vector2f( (mwidth-textRect.width )/2.0, (mheight-textRect.height)/(2 + 1)*1 ) );
}

void Gameover::draw(sf::RenderTarget &target, sf::RenderStates) const{
  for( int i=0; i<2; i++)
    target.draw( game[i] );
}

void Gameover::setWinner(std::string winner) {
  mopt2 = winner;

  game[1].setFont(font);
  game[1].setColor(sf::Color::Red);
  game[1].setString(mopt2);
  game[1].setCharacterSize(mcharsize);
  sf::FloatRect textRect = game[1].getLocalBounds();
  game[1].setPosition( sf::Vector2f( (mwidth-textRect.width )/2.0, (mheight-textRect.height)/(2 + 1)*2 ) );
}

void Gameover::loadsound() {
  if(!gameoverbuffer.loadFromFile( "sounds/gameovercrowd.wav" ) ){
    std::cerr << "ERROR: Gameover sound did not load properly" << std::endl;
  }
  gameoversound.setBuffer(gameoverbuffer);
}

void Gameover::playsound() {
  gameoversound.play();
}
