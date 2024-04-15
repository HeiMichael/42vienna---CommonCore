#ifndef SPACESHIP_HPP 
#define SPACESHIP_HPP

#include "Object.hpp"
#include "shmup.hpp"

class Spaceship : public Object
{
	public:
						Spaceship();
		virtual			~Spaceship();
						Spaceship(const Spaceship& rhs);
		Spaceship&		operator=(const Spaceship& rhs);
		double			getCooldown() const;
		void			setCooldown(double cool);
		double			getCooldownMax() const;
		void			setCooldownMax(double cool);
		const char*		getSprite() const;
		void			setSprite(const char* s);
		bool			canShoot() const;
		int				getHP() const;
		void			setHP(int hp);
		Side			getAlign() const;
		void			setAlign(Side al);
		void			draw(WINDOW* w) override;
		void			update() override;
		// virtual bool	isColliding(int y, int x);
		virtual void	shoot();

	protected:
		double			_cooldown;
		double			_cooldown_max;
		const char*		_sprite;
		bool			_can_shoot;
		Side			_align;
		int				_hit_points;
};

#endif

