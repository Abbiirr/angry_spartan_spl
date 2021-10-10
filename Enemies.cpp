#include "Enemies.h"


//all the enemies will be initialized here
Enemies::Enemies(float defaultY)
{
	this->defaultY = defaultY;
}

Enemies::~Enemies()
{
}

void Enemies::chooseLevel(int level)
{
	if (level == 1)
	{
		this->initLevel1Enemies();
	}
	else if (level == 2)
	{
		this->initLevel2Enemies();
	}
	else if (level == 3)
	{
		this->initLevel3Enemies();
	}
}

void Enemies::updateMovements(Sprite spartan, float deltaTime)
{
	/*for (int i = 0; i < swordsmen.size(); i++) {
		this->swordsmen[i]->updateMovement(spartan, deltaTime);
	}

	for (int i = 0; i < archers.size(); i++) {
		this->archers[i]->updateMovement(spartan, deltaTime);
	}

	for (int i = 0; i < brutes.size(); i++) {
		this->brutes[i]->updateMovement(spartan, deltaTime);
	}*/

	for (int i = 0; i < enemyList.size(); i++) {
		this->enemyList[i]->updateMovement(spartan, deltaTime);
	}
}

void Enemies::updateHealthBars()
{
	/*for (int i = 0; i < swordsmen.size(); i++) {
		this->swordsmen[i]->updateHealthBar();
	}

	for (int i = 0; i < archers.size(); i++) {
		this->archers[i]->updateHealthBar();
		//cout << "arhcer health : " << archers[i]->health << endl;
	}

	for (int i = 0; i < brutes.size(); i++) {
		//this->brutes[i]->updateHealthBar(brutes[i]->health, brutes[i]->health, target);
	}*/

	for (int i = 0; i < this->enemyList.size(); i++) {
		this->enemyList[i]->updateHealthBar(enemyList[i]->maxHealth);
	}

}

void Enemies::render(RenderTarget & target)
{
	/*for (int i = 0; i < this->swordsmen.size(); i++) {
		this->swordsmen[i]->renderEnemy(target);
	}
	for (int i = 0; i < this->archers.size(); i++) {
		this->archers[i]->renderEnemy(target);
	}

	for (int i = 0; i < this->brutes.size(); i++) {
		this->brutes[i]->renderEnemy(target);
	}*/

	for (int i = 0; i < this->enemyList.size(); i++) {
		this->enemyList[i]->render(target);
	}
}

void Enemies::clearEnemies()
{
	/*swordsmen.clear();
	archers.clear();
	brutes.clear();*/
	enemyList.clear();
}

void Enemies::initLevel1Enemies()
{
	this->clearEnemies();
	

	this->spawner.spawnEnemy1(1, "Swordsman", enemyList, Vector2f(1050, 120));
	this->spawner.spawnEnemy1(0, "Swordsman", enemyList, Vector2f(6200, 180));
	this->spawner.spawnEnemy1(0, "Archer", enemyList, Vector2f(2700, 90));
	this->spawner.spawnEnemy1(1, "Brute", enemyList, Vector2f(3300, 330));
	this->spawner.spawnEnemy1(0, "Immortal", enemyList, Vector2f(8000, 310));
}

void Enemies::initLevel2Enemies()
{
	this->clearEnemies();

	this->spawner.spawnEnemy1(1, "Swordsman", enemyList, Vector2f(1050, 120));
	this->spawner.spawnEnemy1(0, "Swordsman", enemyList, Vector2f(6200, 180));
	this->spawner.spawnEnemy1(0, "Archer", enemyList, Vector2f(2700, 90));
	this->spawner.spawnEnemy1(1, "Brute", enemyList, Vector2f(3300, 330));
	this->spawner.spawnEnemy1(0, "Immortal", enemyList, Vector2f(8000, 310));
}

void Enemies::initLevel3Enemies()
{
	this->clearEnemies();
	this->spawner.spawnEnemy1(1, "Swordsman", enemyList, Vector2f(1050, 120));
	this->spawner.spawnEnemy1(0, "Swordsman", enemyList, Vector2f(6200, 180));
	this->spawner.spawnEnemy1(0, "Archer", enemyList, Vector2f(2700, 90));
	this->spawner.spawnEnemy1(1, "Brute", enemyList, Vector2f(3300, 330));
	this->spawner.spawnEnemy1(0, "Immortal", enemyList, Vector2f(8000, 310));
}



