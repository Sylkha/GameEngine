// Code released into the public domain
// in January 2021
// by Silvia

#include "Entity.h"
#include "Scene.h"

namespace gameEngine {
	void Entity::addComponent(Id id, Component* c) {
		components[id] = c;
	}

	Component* Entity::getComponent(const Id& id) {
		return components[id];
	}

	void Entity::set_transform(Matrix44 _transform) {
		transform.transform = _transform;
	}

	Matrix44 Entity::get_transform() {
		/** Posición relativa al del padre. */
		if(parent){
			return parent->get_transform() * transform.transform;
	    }
		else {
			return transform.transform;
		}
	}
}