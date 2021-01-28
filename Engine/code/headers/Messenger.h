// Code released into the public domain
// in January 2021
// by Silvia


#pragma once

#include <map>
#include <string>
#include "Observer.h"
#include <list>

using namespace std;
namespace gameEngine {
	/** Esta clase es la encargada de enviar los mensajes a los Observers que estén suscritos a un evento (id) */
	class Messenger {
		/** Varios observers pueden suscribirse a un solo evento */
		map <string, list<Observer*>> observers; 
	public:
		/** Los observers son unicos por cada id */
		bool add_Observer(string id, Observer* observer) {
			bool found = false;
			/** Buscamos el id en el mapa, y si coincide el id (existe en el mapa), buscamos el observer que queremos */
			for (auto& obs : observers) {
				if (obs.first == id) {
					list<Observer*>::iterator ite;
					ite = find(obs.second.begin(), obs.second.end(), observer);
					/** Si no llega al final es que ha encontrado algo */
					if (ite != obs.second.end())
						found = true;
					break;
				}
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