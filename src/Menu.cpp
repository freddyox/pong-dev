#include "../include/Menu.hh"

Menu::Menu(float width, float height) {
  if( !font.loadFromFile("fonts/arial.ttf") ) {
    std::cerr << "Error handling the fonts" << std::endl;
  }
  selectedItemIndex = 0;

  mwidth = width;
  mheight = height;
  mopt1 = "Play";
  mopt2 = "Options";
  mopt3 = "Exit";
  mcharsize = 40.0;

  menu[0].setFont(font);
  menu[0].setColor(sf::Color::Red);
  menu[0].setString(mopt1);
  menu[0].setCharacterSize(mcharsize);
  sf::FloatRect textRect = menu[0].getLocalBounds();
  menu[0].setPosition( sf::Vector2f( (mwidth-textRect.width )/2.0, (mheight-textRect.height)/(MAX_NUMBER + 1)*1 ) );

  menu[1].setFont(font);
  menu[1].setColor(sf::Color::White);
  menu[1].setString(mopt2);
  menu[1].setCharacterSize(mcharsize);
  textRect = menu[1].getLocalBounds();
  menu[1].setPosition( sf::Vector2f( (mwidth-textRect.width)/2.0, (mheight-textRect.height)/(MAX_NUMBER+1)*2 ) );

  menu[2].setFont(font);
  menu[2].setColor(sf::Color::White);
  menu[2].setString(mopt3);
  menu[2].setCharacterSize(mcharsize);
  textRect = menu[2].getLocalBounds();
  menu[2].setPosition( sf::Vector2f( (mwidth-textRect.width)/2.0, (mheight-textRect.height)/(MAX_NUMBER+1)*3 ) );
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates) const {
  for( int i=0; i< MAX_NUMBER; i++ )
    target.draw(menu[i]);
}

void Menu::MoveUp(){
  if( selectedItemIndex - 1 >= 0 ) {
    menu[ selectedItemIndex ].setColor( sf::Color::White );
    selectedItemIndex--;
    menu[ selectedItemIndex ].setColor( sf::Color::Red );
  }
}

void Menu::MoveDown(){
  if( selectedItemIndex + 1 < MAX_NUMBER ) {
    menu[ selectedItemIndex ].setColor( sf::Color::White );
    selectedItemIndex++;
    menu[ selectedItemIndex ].setColor( sf::Color::Red );
  }
}

