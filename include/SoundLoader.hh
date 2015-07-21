#ifndef SOUNDLOADER_HH
#define SOUNDLOADER_HH

#include "SFML/Audio.hpp"
//#include "Enums.h"
#include <map>
#include <vector>
#include <iostream>

class SoundLoader
{
public:
  //SoundNames is an enum
  SoundLoader();
  ~SoundLoader();
  enum SoundNames{};

  void LoadSounds();
  void PlaySound(SoundNames soundName);

  std::map<SoundNames, sf::SoundBuffer> Sounds;
  std::vector<sf::Sound> playingSounds;
};
#endif
