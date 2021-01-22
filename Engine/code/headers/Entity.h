// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include <string>
#include <map>
#include "Component.h"
#include "Transform_Component.h"
#include "Math.hpp"
#include <memory>

using namespace std;
namespace gameEngine {
	class Scene;
	/** Esto es como el gameObject de Unity */
	class Entity {
		typedef string Id;
		map<Id, Component*> components; 
		Transform_Component transform;
		shared_ptr <Entity> parent;
		string IDNombre;

		Scene& scene;

	public:
		Entity(Scene& scene, string IDNombre) : scene(scene), IDNombre(IDNombre) { parent = nullptr; };

		/** Añadimos componentes a nuestro objeto/entity */
		void addComponent(Id, Component* c);
		/** Busca en el mapa el id para devolver el respectivo componente */
		Component* getComponent(const Id& id);

		void set_parent(shared_ptr <Entity> _parent) { parent = _parent; }
		void set_transform(Matrix44 transform);

		/** Matrix44 es lo que se usa para manejar transforms */
		Matrix44 get_transform();
		string get_IDNombre() { return IDNombre; }
	};

}