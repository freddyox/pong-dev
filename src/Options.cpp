#include "../include/Options.hh"

Options::Options(float width, float height) {
  if( !font.loadFromFile("fonts/arial.ttf") ) {
    std::cerr << "Error handling the fonts" << std::endl;
  }
  selectedItemIndex = 2; // default 

  mwidth = width;
  mheight = height;
  mopt1 = "Turn Computer AI ON/OFF";
  mopt2 = "On";
  mopt3 = "Off ( Default )";
  mopt4 = "Go Back";
  mcharsize = 30.0;

  options[0].setFont(font);
  options[0].setColor(sf::Color(25,155,60));
  options[0].setString(mopt1);
  options[0].setCharacterSize(mcharsize);
  sf::FloatRect textRect = options[0].getLocalBounds();
  options[0].setPosition( sf::Vector2f( (mwidth-textRect.width )/2.0, (mheight-0.5*textRect.height)/(MAX_NUMBER_OPT + 1)*1 ) );

  options[1].setFont(font);
  options[1].setColor(sf::Color::White);
  options[1].setString(mopt2);
  options[1].setCharacterSize(mcharsize);
  textRect = options[1].getLocalBounds();
  options[1].setPosition( sf::Vector2f( (mwidth-textRect.width)/2.0, (mheight-4*textRect.height)/(MAX_NUMBER_OPT+1)*2 ) );

  options[2].setFont(font);
  options[2].setColor(sf::Color::Red);
  options[2].setString(mopt3);
  options[2].setCharacterSize(mcharsize);
  textRect = options[2].getLocalBounds();
  options[2].setPosition( sf::Vector2f( (mwidth-textRect.width)/2.0, (mheight-6*textRect.height)/(MAX_NUMBER_OPT+1)*3 ) );

  options[3].setFont(font);
  options[3].setColor(sf::Color::White);
  options[3].setString(mopt4);
  options[3].setCharacterSize(mcharsize);
  textRect = options[3].getLocalBounds();
  options[3].setPosition( sf::Vector2f( (mwidth-textRect.width)/2.0, (mheight-4*textRect.height)/(MAX_NUMBER_OPT+1)*4 ) );
}

void Options::draw(sf::RenderTarget &target, sf::RenderStates) const {
  for( int i=0; i< MAX_NUMBER_OPT; i++ )
    target.draw( options[i] );
}

void Options::MoveUp(){
  if( selectedItemIndex - 1 >= 1 ) {
    options[ selectedItemIndex ].setColor( sf::Color::White );
    selectedItemIndex--;
    options[ selectedItemIndex ].setColor( sf::Color::Red );
  }
}

void Options::MoveDown(){
  if( selectedItemIndex + 1 < MAX_NUMBER_OPT ) {
    options[ selectedItemIndex ].setColor( sf::Color::White );
    selectedItemIndex++;
    options[ selectedItemIndex ].setColor( sf::Color::Red );
  }
}
