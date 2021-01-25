#pragma once

#include <map>
#include <string>
#include "Observer.h"
#include <list>

using namespace std;
namespace gameEngine {
	class Messenger {
		map <string, list<Observer*>> observers; // varios observers pueden suscribirse a un solo evento

		/** Los observers son unicos por cada id */
		bool add_Observer(string id, Observer* observer) {
			bool found = false;
			for (auto& obs : observers) {
				list<Observer*>::iterator ite;
				ite = find(obs.second.begin(), obs.second.end(), observer);
				/** Si no llega al final es que ha encontrado algo */
				if (ite != obs.second.end())
					found = true;
			}
			
			if (!found)
				observers[id].push_back(observer);

			return !found;
		}

		void send_Messages(Message& mes) {
			auto messageObserver = observers.find(mes.id); // buscamos los observers suscritos al id de ese mensaje
			if (messageObserver != observers.end()) { // Ha encontrado los observers que están suscritos al id del mensaje que vamos a enviar
				for (auto& obs : messageObserver->second) {
					obs->handle(mes);
				}
			}
		}
	};
}