# Angry Spartan
 This is the repo for the SPL-1 project Angry Spartan
 All dependencies are given, you only need to have Visual Studio 2017 to run it.

 
 
 ## How the Camera works
 
 I have added a view which is basically the camera. The view moves with the player.
  ```
  this->view = sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(windowX, windowY));
  ```
  But if I move the camera from the start of the game then this happens
  
  ![image](https://user-images.githubusercontent.com/72934078/127184449-feb2a7f0-46b5-4cc3-9f3d-d6f5da86863c.png)
  
  So I have added a minimum threshold and camera will only move if the player crosses that threshold.
  
  ```
  if (spartan.GetPosition().x >= minCameraX)	//camera will only move if player crosses the threshold
	{
		view.setCenter(spartan.GetPosition());
		window.setView(view);
	}
 ```
But before the theshold, if I jump too high then the player goes out of view and things like these happens
![image](https://user-images.githubusercontent.com/72934078/127185111-8dca0a33-2161-4d0c-98bb-713ecad14544.png)

![image](https://user-images.githubusercontent.com/72934078/127185138-e03ac7b9-7959-453c-baee-18c2f6989c96.png)

So, I have put platforms away from the threshold so that **player can never jump too high inside the threshold**.
But this is a hack and still gameplay might be a little glitchy near the border areas. **Need a fix**.



# How the UI Texts work

## Pause
All texts for pause and gameOver are initialized when UIElements class is initialized.
If anyone presses Space in the game, the game triggers updatePause() function which determines if the game is in paused position or unpaused and acts accordingly.
If the game is paused then all update of enemy and players is suspended temporarily. 

The texts appear in a default location on the screen at first. But if the player crosses the minimum threshold for camera to work then the texts also recenter themselves with the player.
```
if (isMoreThanThreshold)
	{
		pauseText.setPosition(pos.x - 50.f, pos.y- 100.f);
		gameOverText.setPosition(pos.x - 50.f, pos.y - 100.f);
	}
```
## Game Over
It is only game over when the player dies.
The game class triggers the checkGameOver function of UIElements and passes two bools(one for close attack death and another for ranged attack death, **this method will change**). Then the function checks if player has died and acts accordingly.
```
if (closeDeath) {
		this->isGameOver = true;
	}

	if (rangedDeath) {
		this->isGameOver = true;
	}
```


# How Combat works

### From game.cpp a function _***attack***_ of _***combat***_ class is called
```
this->combat.attack(&spartan, &this->level.enemies, arrows, deltaTime);
```
This function then manually iterates over every enemy and uses their respective functions.

## Swordsman
If the global bounds of a swordsman insersects with the player then the swordsman can attack.  
But if the player presses left shift, the attack is blocked.

## Archer
For the archer enemy we need a projectile container which is created in the game class and the reference is passed to combat class.  
The archer shoots projectiles which after shooting is on their own and have have no affliation to any other class but the game class.  
**They are own on their on, on a lonesome journey towards hitting the player or dissappearing from the edge of the screen into the abyss, never to seen or heard ever again.**

## Spartan (Player)
We check every enemy separately to see if any intersects with the spartan's global bounds.  
If any does, then the spartan can attack them(may attack multiple at once).  
For now, there is only close quarter attack of the spartan.  
