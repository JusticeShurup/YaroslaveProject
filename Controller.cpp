#include "Controller.h"

int Distance(float targetX, float targetY, float coordinateX, float coordinateY) {
     return sqrt(pow(targetX - coordinateX, 2) + pow(targetY - coordinateY, 2));
}

Controller* Controller::instance = nullptr;

Controller::Controller() {
	damage = 10;
	HP = 50;
	Stamina = 100;
    idle = new Idle();
    walk = new Walk();
    run = new Run();
    punch = new Punch();
    animation = idle;
    isCooldown = false;
    stoped = false;

    enemy = new Enemy(300, 400, 100, 32, 32, "NES Slave - Toby Orbon Free Files/Walk/Walk_North_frame_0.png");
    enemy->setPosition(enemy->getCoordinateX(), enemy->getCoordinateY());
    
}

Controller* Controller::getInstance() {
	if (!Controller::instance) {
		Controller::instance = new Controller;
	}
	return Controller::instance;
}

void Controller::moveAfterHit() {
    switch (player->sost )
    {
    case 0: enemy->setCoordinateX(enemy->getCoordinateX() + 15); break;
    case 1: enemy->setCoordinateX(enemy->getCoordinateX() - 15); break;
    case 2: enemy->setCoordinateX(enemy->getCoordinateX() - 15); break;
    case 3: enemy->setCoordinateX(enemy->getCoordinateX() + 15); break;
    }
}

void Controller::giveDamage(Enemy* enemy) {
    if (canHit(player->getCoordinateX(), player->getCoordinateY(), enemy->getCoordinateX(), enemy->getCoordinateY()) && enemy != nullptr) {
        enemy->setHP(enemy->getHP() - damage);
        moveAfterHit();
        if (enemy->getHP() <= 0)
            Die();
    }
    else {
        if (enemy->getHP() <= 0)
            Die();
        return;
    }
}

void Controller::takeDamage(Enemy* enemy) {
    //damage = setDamage(player->damage)
    //std::cout << enemy->getHP() << std::endl;
    if (enemy == nullptr)
        return;
    if (canHit(enemy->getCoordinateX(), enemy->getCoordinateY(), player->getCoordinateX(), player->getCoordinateY())) {
        int newHealth = enemy->getHP() - damage;
        enemy->setHP(newHealth);
    }
    else
        return;
    if (enemy->getHP() <= 0)
        Die();
}

void Controller::setDamage(int damage) {
	this->damage = damage;
}

int Controller::getDamage() {
	return damage;
}

bool Controller::canHit(float targetX, float targetY, float X, float Y) {
    bool correctsost = false; //Переменная отвечающая за корректность состояния игрока по отношению к врагу
    switch(player->sost)
    {
    case 0: if (X > targetX) correctsost = true; break;
    case 1: if (X < targetX) correctsost = true; break;
    case 2: if (Y > targetY) correctsost = true; break;
    case 3: if (Y < targetY) correctsost = true; break;
    }
    if (Distance(targetX, targetY, X, Y) < 20 && correctsost) 
        return true;
    else 
        return false;
}

int Controller::getHP() {
	return HP;
}

void Controller::setHP(int quantity) {
	HP = quantity;
}

void Controller::setStamina(int quantity) {
	Stamina = quantity;
}

int Controller::getStamina() {
	return Stamina;
}

void Controller::setPlayer(Player* player) {
	this->player = player;
}

Player* Controller::getPlayer() {
    return player;
}

void Controller::setEnemy(Enemy* enemy) {
    this->enemy = enemy;
}

Enemy* Controller::getEnemy() {
    return enemy;
}

void Controller::setHUD(HUD* hud) {
	this->hud = hud;
}

HUD* Controller::getHUD() {
	return hud;
}

void Controller::setAnimiationState(AnimationState* animation) {
    this->animation = animation;
}

AnimationState* Controller::getAnimationState() {
    return animation;
}

void Controller::deleteAnimation() {
    delete animation;
}

void Controller::makeMove() {
    if(!stoped)
        animation = idle;
    player -> dx = 0; player -> dy = 0;
    if (Keyboard::isKeyPressed(Keyboard::W) && !stoped)
    {
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            if (Keyboard::isKeyPressed(Keyboard::LShift)) {
                animation = run;
                player->sost = 1; player -> dx = -0.1;
            }
            else {
                animation = walk;
                player->sost = 1; player -> dx = -0.05;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::D)) {
            if (Keyboard::isKeyPressed(Keyboard::LShift)) {
                animation = run;
                player->sost = 0; player -> dx = 0.1;
            }
            else {
                animation = walk;
                player->sost = 0; player -> dx = 0.05;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::LShift)) {
            animation = run;
            player -> sost = 3; player -> dy = -0.1;
        }
        else {
            animation = walk;
            player->sost = 3; player -> dy = -0.05;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::S) && !stoped)
    {
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            if (Keyboard::isKeyPressed(Keyboard::LShift)) {
                animation = run;
                player->sost = 1; player->dx = -0.1;
            }
            else {
                animation = walk;
                player->sost = 1; player->dx = -0.05;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::D)) {
            if (Keyboard::isKeyPressed(Keyboard::LShift)) {
                animation = run;
                player->sost = 0; player->dx = 0.1;
            }
            else {
                animation = walk;
                player->sost = 0; player->dx = 0.05;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::LShift)) {
            animation = run;
            player -> sost = 2; player -> dy = 0.1;
        }
        else {
            animation = walk;
            player -> sost = 2; player -> dy = 0.05;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::A) && !stoped)
    {

        if (Keyboard::isKeyPressed(Keyboard::LShift)) {
            animation = run;
            player -> sost = 1; player -> dx = -0.1;
        }
        else {
            animation = walk;
            player -> sost = 1; player -> dx = -0.05;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::D) && !stoped)
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift)) {
            animation = run;
            player -> sost = 0; player -> dx = 0.1;
        }
        else {
            animation = walk;
            player -> sost = 0; player -> dx = 0.05;
        }
    }
    if ((Keyboard::isKeyPressed(Keyboard::Space) || Mouse::isButtonPressed(Mouse::Left)) && !isCooldown) {
        cooldown_start = clock();
        animation = punch;
        player->speed = 0;
        if (enemy != nullptr)
            //std::cout << canHit(enemy->getCoordinateX(), enemy->getCoordinateY(), player->getCoordinateX(), player->getCoordinateY()) << std::endl;
            giveDamage(enemy);
        isCooldown = true;
        stoped = true;
    }
}

void Controller::playerUpdate(float time, Map* map) {
    makeMove();
	if (Stamina < 10) 
		player->speed = 0.05;
	if (player->speed >= 0.06) {
        //std::cout << player->speed << std::endl;
		if (Stamina > 10)
			Stamina -= 0.05;
		player->stamina = Stamina;
		hud->setStamina(Stamina);
	}
	else {
		if (Stamina < 100)
			Stamina += 0.5;
		player->stamina = Stamina;
		hud->setStamina(Stamina);
	}
    player->Update(time, map);
    cooldown_end = clock();

    if (cooldown_end - cooldown_start > 500) // Проверка на кулдаун
        isCooldown = false;

    if (cooldown_end - cooldown_start > 150) // Проверка на остановку игрока во время удара
        stoped = false;
}


void Controller::Die() {
    delete enemy;
    enemy = nullptr;
}