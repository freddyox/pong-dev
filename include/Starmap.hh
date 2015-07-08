#ifndef STARMAP_HH
#define STARTMAP_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Starmap : public sf::Drawable {
private:
  sf::CircleShape m_small, m_medium, m_large;
  float m_smallrad, m_mediumrad, m_largerad;
  std::vector<sf::CircleShape> small_v, medium_v, large_v;
  float m_tslow, m_tmedium, m_tlarge,m_v;
  float displayx, displayy;
public:
  Starmap();
  ~Starmap();
  void init_star();
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  void update();
};

#endif
