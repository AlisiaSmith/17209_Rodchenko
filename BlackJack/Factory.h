#pragma once

#include <map>
#include <string>

#include "Player.h"
//forward declaration
//class Player;


template<class ID,
		 class Creator>
class Factory {
public:

  Player * createPlayerByID(const ID & id) {
	   auto it = creators.find(id);
     if (creators.end() == it) {
     		//no creator found
     		return nullptr;
     		}

     Creator creator = it->second;
     Player * p = creator();
     return p;
     //или return it->second();
     }
  bool registerPlayer(const ID & id, Creator &creator) {
  creators[id] = creator;
  return true;
  }

  static Factory * getInstance() {
    static Factory f;
    return &f;
  }

private:
     	Factory() = default;
     	Factory(const Factory &) = delete;
     	Factory & operator=(const Factory &) = delete;
        std::map < ID, Creator > creators;
 };
