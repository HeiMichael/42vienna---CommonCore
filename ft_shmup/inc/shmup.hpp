#ifndef SHMUP_HPP
#define SHMUP_HPP

#include <locale.h>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdlib>
#include <thread>

#define MAX_PLAYER_LIFES 5
#define ENEMY_CREATION_RYTHM .5
#define COOLDOWN_MAX 0.5
#define PHANTOM_SPEED -8
#define BULLET_VELOCITY 60
#define INFOBOX_H 3
#define DIS_UP 7 
#define DIS_LEFT 1
#define BOSSTIME 60.0
#define BOSSLIVES 30 

const int TARGET_FPS = 60;

enum GameState
{
	MENU,
	PLAYING,
	GAMEOVER,
	EXIT
};

enum Side
{
	ENEMY,
	PLAYER,
	NOSIDE
};

enum EnemyType
{
	PHANTOM,
	LURKER,
	BEE,
	OKTO
};


#endif