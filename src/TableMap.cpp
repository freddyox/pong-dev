#include "../include/TableMap.hh"

TableMap::TableMap(float x, float y) {
  displayx = x;
  displayy = y;
  LineWidth = 4.0;
  sf::Color PongTableColor = sf::Color(4,27,90);
  sf::Color TableLines = sf::Color(174,175,178);

  sf::Vector2f LineSize(displayx, LineWidth);
  TableLineTop = sf::RectangleShape( LineSize );
  TableLineTop.setFillColor( TableLines );

  TableLineBot = sf::RectangleShape( LineSize );
  TableLineBot.setPosition( 0, displayy - LineWidth);
  TableLineBot.setFillColor(TableLines);

  sf::Vector2f LineSizeLR(LineWidth, displayy);
  TableLineLeft = sf::RectangleShape( LineSizeLR );
  TableLineLeft.setFillColor( TableLines );

  TableLineRight = sf::RectangleShape( LineSizeLR );
  TableLineRight.setFillColor( TableLines );
  TableLineRight.setPosition( displayx - LineWidth, 0 );

  sf::Vector2f LineSizeCenter( LineWidth, displayy-2*LineWidth );
  TableLineCenter = sf::RectangleShape( LineSizeCenter );
  TableLineCenter.setFillColor( TableLines );
  TableLineCenter.setOrigin( LineWidth/2.0, 0.5*(displayy-2*LineWidth) );
  TableLineCenter.setPosition( displayx/2.0, displayy/2.0 );
}

void TableMap::draw(sf::RenderTarget& target, sf::RenderStates) const {
  target.draw(TableLineTop);
  target.draw(TableLineBot);
  target.draw(TableLineLeft);
  target.draw(TableLineRight);
  target.draw(TableLineCenter);
}
