#ifndef ENTITY_H
#define ENTITY_H

#include <lavendframework/input.h>
#include <lavendframework/singleton.h>

class Entity
{
public:
	Entity();
	virtual ~Entity();

	/// @brief get a pointer to the Input
	/// @return Input* a pointer to the Input
	Input* input() { return _input; };

private:
	Input* _input; ///< @brief the Input instance
};

#endif