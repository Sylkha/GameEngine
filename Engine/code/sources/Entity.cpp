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
		/** Posici�n relativa al del padre. Se tiene solo en cuenta aqu� porque en el Render System ya hacemos esta transformaci�n al hacer el get */
		if(parent){
			return parent->get_transform() * transform.transform;
	    }
		else {
			return transform.transform;
		}
	}
}