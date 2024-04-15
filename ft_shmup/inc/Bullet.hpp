#ifndef BULLET_HPP
#define BULLET_HPP

#include "Object.hpp"
#include "shmup.hpp"

class Bullet : public Object
{
	public:
					Bullet();
					~Bullet();

		void		setAlign(Side s);
		Side		getAlign() const;
		bool		getDestroyed() const;

		void		draw(WINDOW *) override;	
		void		update() override;

	private:
		Side		_align;
		const char*	_sprite;
		bool		_destroyed;
};

#endif