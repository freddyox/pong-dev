#include "../include/ScoreWindow.hh"
#include <sstream>

ScoreWindow::ScoreWindow(float width, float height) {
  if( !font.loadFromFile("fonts/arial.ttf") ) {
    std::cerr << "Error handling the fonts" << std::endl;
  }
  mwidth = width;
  mheight = height;
  mopt1 = "0";
  mopt2 = "0";
  // mopt3 = ptr->getLeftName();
  // mopt4 = ptr->getRightName();
  mcharsize = 40.0;

  score[0].setFont(font);
  score[0].setColor(sf::Color::White);
  score[0].setString(mopt1);
  score[0].setCharacterSize(mcharsize);
  sf::FloatRect textRect = score[0].getLocalBounds();
  score[0].setPosition( sf::Vector2f(width/2.0 - 4*textRect.width/2.0 - 4, height/2.0 - textRect.height/2.0) );

  score[1].setFont(font);
  score[1].setColor(sf::Color::White);
  score[1].setString(mopt2);
  score[1].setCharacterSize(mcharsize);
  textRect = score[1].getLocalBounds();
  score[1].setPosition( sf::Vector2f(width/2.0 + 2*textRect.width/2.0 + 4, height/2.0 - textRect.height/2.0) );
}

void ScoreWindow::draw(sf::RenderTarget &target, sf::RenderStates) const {
  for( int i=0; i<2; i++ )
    target.draw(score[i]);
}

void ScoreWindow::updateScore(int Left, int Right) {
  std::ostringstream LeftTemp;
  LeftTemp << Left;
  mopt1 = LeftTemp.str();
  score[0].setString(mopt1);

  std::ostringstream RightTemp;
  RightTemp << Right;
  mopt2 =  RightTemp.str();
  score[1].setString(mopt2);
}
