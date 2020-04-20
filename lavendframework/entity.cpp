#include <lavendframework/entity.h>

Entity::Entity()
{
	_input = Singleton<Input>::instance();
}

Entity::~Entity()
{
	
}