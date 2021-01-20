#pragma once
#include "Component.h"
#include "Model.hpp"
#include "Math.hpp"
#include <memory>

using namespace std;
using namespace glt;
namespace gameEngine {
	class Model_Component : public Component{
	public:
		shared_ptr <Model> model;

		Model_Component();

		void set_model(shared_ptr <Model> _model) { model = _model; }
		shared_ptr<Model> get_model() { return model; }

	};
}

