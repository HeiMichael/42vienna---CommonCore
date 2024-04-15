#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <ncurses.h>

class Game;

class Object
{
	public:
							Object();
		virtual				~Object();

		float				getX() const;
		void				setX(float x);
		float				getY() const;
		void				setY(float y);
		int					getStartX() const;
		void				setStartX(int x);
		int					getStartY() const;
		void				setStartY(int y);
		int					getColor() const;
		void				setColor(int c);
		void				setGame(Game* g);
		float				getSpeed() const;
		void				setSpeed(float speed);
		// virtual bool		is_colliding(int y, int x) = 0;
		virtual void		draw(WINDOW* w) = 0;
		virtual void		update() = 0;

	protected:
		Game*				_game;
		int					_color;
		int					_startX;
		int					_startY;
		float				_x;
		float				_y;
		float				_speed;
};

#endif