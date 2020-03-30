/**
 * This file is part of the game Vixel in the RT2D framework.
 *
 * - Copyright 2019 Lucy Jongebloed
 *     - Initial commit
 */

#ifndef BASICENTITY_H
#define BASICENTITY_H

#include <lavendframework/entity.h>

class BasicEntity: public Entity
{
	public:
		BasicEntity();
		virtual ~BasicEntity();

		virtual void update(float deltaTime);

	private:
		/* add your private declarations */
};

#endif /* BASICENTITY_H */
