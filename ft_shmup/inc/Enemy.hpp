#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "shmup.hpp"
#include "Spaceship.hpp"

class Enemy : public Spaceship
{
	public:
						Enemy();
						~Enemy();
		EnemyType		getType() const;
		void			setType(EnemyType tp);
		void			updater(double time);
		void			shoot();
		double			offset;

	private:
		EnemyType		_type;
};

#endif