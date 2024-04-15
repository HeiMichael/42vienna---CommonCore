#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Spaceship.hpp"

class Player : public Spaceship
{
	public:
						Player();
						~Player();
		void			update();
		bool			isDead() const;
		void			setDead(bool d);
		void			shoot();

		void			setHP(int);
		
	private:
		bool			_isdead;

};

#endif