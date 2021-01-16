#pragma once
#include <string>
#include <map>
#include "Component.h"

using namespace std;
namespace gameEngine {
	class Entity {
		typedef string Id;
		map<Id, Component*> components;

		void add(Id, Component* c);
		/** Busca en el mapa el id para devolver el respectivo componente */
		Component* get(Id);
	};

}