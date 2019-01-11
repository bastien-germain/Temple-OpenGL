#include "moteurRendu/Drawer.hpp"

Drawer::Drawer(const Program &program) : 
	_localRotateIndicator(0), _globalRotateIndicator(0), 
	_lastGlobalRotateDirection(0), _rotateProgress(0),
	_corner(false), _counter(0)
{

	_projMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 600.f);
	_globalMVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -3.f));
	_normalMatrix = glm::transpose(glm::inverse(_globalMVMatrix));

	_uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    _uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    _uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    _uTexture = glGetUniformLocation(program.getGLId(), "uTexture");

    _uAmbiantLight = glGetUniformLocation(program.getGLId(), "uAmbiantLight");
    _uNbLights = glGetUniformLocation(program.getGLId(), "uNbLights");
    _uLightOn = glGetUniformLocation(program.getGLId(), "uLightOn");


    _objectMatrix = glm::mat4();

}

Drawer::~Drawer()
{
}

void Drawer::initializeLights(const Program &program)
{
	glUniform3f(_uAmbiantLight, 0.1, 0.1, 0.1);

    _lights.push_back(Light(false, glm::vec3(0.0, 0.0, -5), glm::vec3(0.5, 0.7, 1.0), glm::vec3(0.0), 8, glm::vec3(0.3)));

    for (int i = 0; i < 4; ++i)
    {
        _lights.push_back(Light(true, glm::vec3(-2.0, 4.5, - i * LIGHTS_SPACE), glm::vec3(0.5, 0.7, 1.0), glm::vec3(0.5), 8, glm::vec3(4.0)));
        _lights.push_back(Light(true, glm::vec3(2.0, 4.5, - i * LIGHTS_SPACE), glm::vec3(0.5, 0.7, 1.0), glm::vec3(0.5), 8, glm::vec3(4.0)));
    }

    for (int i = 0; i < _lights.size(); ++i)
    {
        _lights[i].sendLightShader(program, _refLight);
    }

    glUniform1i(_uNbLights, _lights.size()); 
}

void Drawer::drawPlayer(Player &player)
{
	_playerMatrix = _worldMatrix;
    _playerMatrix = glm::translate(_playerMatrix, glm::vec3(player.posX(), player.posY(), 0));

    glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_playerMatrix));
    glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
    glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _playerMatrix));
    
    glUniform1i(_uTexture, 0);
    player.model()->texture().bind();
    player.model()->vbo().draw();
    player.model()->texture().debind();
}

void Drawer::drawSkybox(Skybox &skybox)
{
    _playerMatrix = glm::scale(_worldMatrix, glm::vec3(4));
    _playerMatrix = glm::translate(_playerMatrix, glm::vec3(skybox.posX(), skybox.posY(), 0));

    glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_playerMatrix));
    glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
    glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _playerMatrix));
    glUniform1i(_uLightOn, 0);

    glUniform1i(_uTexture, 0);
    skybox.model()->texture().bind();
    skybox.model()->vbo().draw();
    skybox.model()->texture().debind();
    glUniform1i(_uLightOn, 1);
}

void Drawer::drawEnemy(Enemy &enemy)
{
	_enemyMatrix = _worldMatrix;
    _enemyMatrix = glm::translate(_enemyMatrix, glm::vec3(0, REGULAR_Y, enemy.distanceToPlayer()));

    glUniform1i(_uTexture, 0);
    enemy.model()->texture().bind();

    glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_enemyMatrix));
    glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
    glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _enemyMatrix));

    enemy.model()->vbo().draw();

    _enemyMatrix = glm::translate(_enemyMatrix, glm::vec3(-1, 0, 0));
    glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_enemyMatrix));
    glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
    glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _enemyMatrix));
    enemy.model()->vbo().draw();
    
    _enemyMatrix = glm::translate(_enemyMatrix, glm::vec3(2, 0, 0));
    glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_enemyMatrix));
    glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
    glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _enemyMatrix));
    enemy.model()->vbo().draw();

    enemy.model()->texture().debind();
}

void Drawer::drawSection(const Section &section, const float &posX, const float &posZ)
{
   	_tmpMatrix =  glm::translate(_tmpMatrix , glm::vec3(posX, 0, posZ));

	glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_tmpMatrix));
    glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
    glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _tmpMatrix));

	glUniform1i(_uTexture, 0);
    section.model()->texture().bind();
    section.model()->vbo().draw();
    section.model()->texture().debind();

    if (section.obstacle().model() != NULL)
    {	
    	_tmpMatrix = glm::translate(_tmpMatrix, glm::vec3(section.obstacle().posX(), 0, 0));

    	glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_tmpMatrix));
    	glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
    	glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _tmpMatrix));

    	glUniform1i(_uTexture, 0);
        section.obstacle().model()->texture().bind();
        section.obstacle().model()->vbo().draw();
        section.obstacle().model()->texture().debind();

    	_tmpMatrix = glm::translate(_tmpMatrix, glm::vec3(-section.obstacle().posX(), 0, 0));
    }

   	_tmpMatrix =  glm::translate(_tmpMatrix , glm::vec3(-posX, 0, -posZ));
}


bool Drawer::draw(std::vector<Section> &sectionVec, const glm::mat4 &trackMat, Player &player, Enemy &enemy, Skybox &skybox, const Program &program) 
{

	float x, z;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _worldMatrix = glm::translate(trackMat * _globalMVMatrix, glm::vec3(0,-3,2));

    drawPlayer(player);
    drawEnemy(enemy);
    drawSkybox(skybox);

 	for (int i = 1; i < _lights.size(); ++i)
    {
    	_lights[i].goOn(WORLD_SPEED, - (i%2) * LIGHTS_SPACE - 2 * LIGHTS_SPACE);

        _lights[i].getPos() = glm::vec3(trackMat * glm::vec4(_lights[i].getPos(), 1));
        _lights[i].sendLightShader(program, _refLight);
        _lights[i].getPos() = glm::vec3(glm::inverse(trackMat) * glm::vec4(_lights[i].getPos(), 1));
    }

    _tmpMatrix = _worldMatrix * _objectMatrix;

    _counter += WORLD_SPEED;
    for (std::vector<Section>::iterator it = sectionVec.begin(); it != sectionVec.end(); ++it)
    {   
    	if (!_corner)
    	{
	    	switch (_globalRotateIndicator) 
	    	{	
	    		case 0:
	    		{
	    			switch(_localRotateIndicator)
	    			{
	    				case 0:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	                    case 1:
	                        it->goOnX(WORLD_SPEED);
	                        break;
	                    case 2:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	                    case 3:
							it->goOnX(-WORLD_SPEED);
	                        break;
	                    case -1:
	                        it->goOnX(-WORLD_SPEED);
	                        break;
	                    case -2:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	                    case -3:
	                        it->goOnX(WORLD_SPEED);
	                        break;
	    				default:
	    					break;
	    			}
	       			break;
	    		}
	    		case 1:
	    		{
	    			switch(_localRotateIndicator)
	    			{
	    				case 0:
	                        it->goOnX(-WORLD_SPEED);
	                        break;
	                    case 1:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	                    case 2:
	                        it->goOnX(WORLD_SPEED);
	                        break;
	                    case 3:
							it->goOnZ(-WORLD_SPEED);
	                        break;
	                    case -1:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	                    case -2:
	                        it->goOnX(WORLD_SPEED);
	                        break;
	                    case -3:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	    				default:
	    					break;
	    			}
	       			break;
	    		}
	    		case 2:
	    		{
	    			switch(_localRotateIndicator)
	    			{
	    				case 0:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	                    case 1:
	                        it->goOnX(-WORLD_SPEED);
	                        break;
	                    case 2:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	                    case 3:
							it->goOnX(WORLD_SPEED);
	                        break;
	                    case -1:
	                        it->goOnX(WORLD_SPEED);
	                        break;
	                    case -2:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	                    case -3:
	                        it->goOnX(-WORLD_SPEED);
	                        break;
	    				default:
	    					break;
	    			}
	    			break;
	    		}
	    		case 3:
	    			switch(_localRotateIndicator)
	    			{
	    				case 0:
	                        it->goOnX(WORLD_SPEED);
	                        break;
	                    case 1:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	                    case 2:
	                        it->goOnX(-WORLD_SPEED);
	                        break;
	                    case 3:
							it->goOnZ(WORLD_SPEED);
	                        break;
	                    case -1:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	                    case -2:
	                        it->goOnX(-WORLD_SPEED);
	                        break;
	                    case -3:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	    				default:
	    					break;
	    			}
	    			break;
	    		case -1: 
	    			switch(_localRotateIndicator)
	    			{
	    				case 0:
	                        it->goOnX(WORLD_SPEED);
	                        break;
	                    case 1:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	                    case 2:
							it->goOnX(-WORLD_SPEED);
	                        break;
	                    case 3:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	                    case -1:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	                    case -2:
	                        it->goOnX(-WORLD_SPEED);
	                        break;
	                    case -3:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	    				default:
	    					break;
	    			}
	    			break;
	    		case -2:
	    			switch(_localRotateIndicator)
	    			{
	    				case 0:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	                    case 1:
	                        it->goOnX(-WORLD_SPEED);
	                        break;
	                    case 2:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	                    case 3:
							it->goOnX(WORLD_SPEED);
	                        break;
	                    case -1:
	                        it->goOnX(WORLD_SPEED);
	                        break;
	                    case -2:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	                    case -3:
	                        it->goOnX(-WORLD_SPEED);
	                        break;
	    				default:
	    					break;
	    			}
	       			break;
	    		case -3:
	    			switch(_localRotateIndicator)
	    			{
	    				case 0:
	                        it->goOnX(-WORLD_SPEED);
	                        break;
	                    case 1:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	                    case 2:
							it->goOnX(WORLD_SPEED);
	                        break;
	                    case 3:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	                    case -1:
	                        it->goOnZ(-WORLD_SPEED);
	                        break;
	                    case -2:
	                        it->goOnX(WORLD_SPEED);
	                        break;
	                    case -3:
	                        it->goOnZ(WORLD_SPEED);
	                        break;
	    				default:
	    					break;
	    			}
	    		default:
	    			break;
			}
    	}

    	if((it - sectionVec.begin()) * (- POSITION_OFFSET_Z) - DRAW_DISTANCE < _counter && 
    		_counter < (it - sectionVec.begin()) * (- POSITION_OFFSET_Z) + DRAW_DISTANCE)
			drawSection(*it, it->posX(), it->posZ());

		if (it->isCorner())
		{
			rotated(it->cornerDirection(), _localRotateIndicator);
            _tmpMatrix = glm::rotate(_tmpMatrix, glm::radians(it->cornerDirection() * -90.f), glm::vec3(0,1,0));

            if (
            	!it->hasTurned() && 
            	(fabs((it->posZ() - SECTION_WIDTH) - REGULAR_Z) <= WORLD_SPEED) &&
            	(fabs((it->posX())) <= 5 * WORLD_SPEED)
            	)
            {	
            	_corner = true;
            	_lastGlobalRotateDirection = it->cornerDirection();
            	it->turned();
            	_rotateProgress = 0;
            }
		}

	    if (_corner)
	    {	
	    	if ((_lastGlobalRotateDirection == 1 && player._turningRight) || (_lastGlobalRotateDirection == -1 && player._turningLeft))
	    	{
	    		if (_rotateProgress <= glm::radians(90.f))
	    		{	
	    			_rotateProgress += ROTATE_SMOOTH;	
	    			_objectMatrix = glm::rotate(_objectMatrix, _lastGlobalRotateDirection * ROTATE_SMOOTH, glm::vec3(0,1,0));
	    		}
	    		else 
	    		{
	    			rotated(_lastGlobalRotateDirection, _globalRotateIndicator);
	    			_corner = false;
	    		}
	    	}
	    	else
	    	{
	    		if (_counter > TIME_TO_TURN)
	    		{
	    			return false;
	    			std::cout << "end" << std::endl;
	    		}
	    		else
	    			_counter += 0.0002;
	    	}
		}
    }

    rotated(-_localRotateIndicator, _localRotateIndicator);

    if(enemy.distanceToPlayer() == 0)
		return false;

	return true;
}