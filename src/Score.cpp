#include "../include/Score.hh"

Score::Score(float width, float height) {
  if( !font.loadFromFile("fonts/arial.ttf") ) {
    std::cerr << "Error handling the fonts" << std::endl;
  }
  mwidth = width;
  mheight = height;
  mopt1 = "0";
  mopt2 = "0";
  mcharsize = 20.0;

  score[0].setFont(font);
  score[0].setColor(sf::Color::White);
  score[0].setString(mopt1);
  score[0].setCharacterSize(mcharsize);
  sf::FloatRect textRect = score[0].getLocalBounds();
  score[0].setPosition( sf::Vector2f(width/2.0 - 4*textRect.width/2.0 - 4, height - 2*textRect.height - 4) );

  score[1].setFont(font);
  score[1].setColor(sf::Color::White);
  score[1].setString(mopt2);
  score[1].setCharacterSize(mcharsize);
  textRect = score[1].getLocalBounds();
  score[1].setPosition( sf::Vector2f(width/2.0 + 2*textRect.width/2.0 + 4, height - 2*textRect.height - 4) );
}


void Score::draw(sf::RenderTarget &target, sf::RenderStates) const {
  for( int i=0; i<2; i++ )
    target.draw(score[i]);
}
