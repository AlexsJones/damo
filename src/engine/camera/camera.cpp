/*********************************************************************************
 *     File Name           :     /home/jonesax/Work/damo/src/engine/camera/camera.cpp
 *     Created By          :     jonesax
 *     Creation Date       :     [2017-02-27 11:13]
 *     Last Modified       :     [2017-02-27 13:57]
 *     Description         :      
 **********************************************************************************/
#include "camera.hpp"
#include <iostream>
#include <jnxc_headers/jnx_log.h>

Camera::Camera(SDL_Window *window){

	SDL_GetWindowSize( window, &m_bounds.w, &m_bounds.h );

	m_box.w = m_bounds.w;
	m_box.h = m_bounds.w;
	m_box.x = 0;
	m_box.y =0;
}
shared_ptr<IActor> Camera::getFocus(void) {

	return m_followed_actor;
}
void Camera::focusActor(shared_ptr<IActor> a) {

	std::cout << "Following actor " << a->getUniqueIdentifier() << std::endl;
	m_followed_actor = a;
}
void Camera::update(void) {

	if(m_followed_actor) {
		
		auto object_texture = m_followed_actor->getTextureSize();
		auto object_position = m_followed_actor->getPosition();

		std::cout << "Camera updating object position " << object_position->x << " : " << object_position->y << std::endl;
			// Center camera over object.
		m_box.x = (object_position->x + (object_texture.w / 2)) - (m_box.w / 2);
		m_box.y = (object_position->y + (object_texture.h / 2)) - (m_box.h / 2);

		std::cout << "m_box:x " << m_box.x << " m_box:y" << m_box.y << std::endl;

		//if (m_bounds.w < m_box.w) { m_box.x = m_bounds.x + (m_bounds.w / 2) - (m_box.w / 2); }
		//if (m_bounds.h < m_box.h) { m_box.y = m_bounds.y + (m_bounds.h / 2) - (m_box.h / 2); }	
	}
}

SDL_Rect Camera::getBox(void) {
	return m_box;
}