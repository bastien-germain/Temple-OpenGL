#include "moteurRendu/Drawer.hpp"

Drawer::Drawer(const Program &program) : _rotateIndicator(0), _lastRotateIndex(0)
{
	_projMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
	_globalMVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -3.f));
	_normalMatrix = glm::transpose(glm::inverse(_globalMVMatrix));

	_uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    _uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    _uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    _uTexture = glGetUniformLocation(program.getGLId(), "uTexture");
    _uAmbiantLight = glGetUniformLocation(program.getGLId(), "uAmbiantLight");
    _uNbLights = glGetUniformLocation(program.getGLId(), "uNbLights");

}

Drawer::~Drawer()
{
}

void Drawer::initializeLights(const Program &program)
{
	glUniform3f(_uAmbiantLight, 0.2, 0.2, 0.2);

    _lights.push_back(Light(false, glm::vec3(0.0, 0.0, -5), glm::vec3(0.5, 0.7, 1.0), glm::vec3(0.0), 8, glm::vec3(0.4)));

    for (int i = 0; i < 4; ++i)
    {
        _lights.push_back(Light(true, glm::vec3(-2.0, 4.5, - i * LIGHTS_SPACE), glm::vec3(0.5, 0.7, 1.0), glm::vec3(0), 8, glm::vec3(4.0)));
        _lights.push_back(Light(true, glm::vec3(2.0, 4.5, - i * LIGHTS_SPACE), glm::vec3(0.5, 0.7, 1.0), glm::vec3(0), 8, glm::vec3(4.0)));
    }

    for (int i = 0; i < _lights.size(); ++i)
    {
        _lights[i].sendLightShader(program, _refLight);
    }

    glUniform1i(_uNbLights, _lights.size()); 
}

void Drawer::draw(std::vector<std::vector<Section*>> &sectionMat, const glm::mat4 &trackMat, Player &player, Enemy &enemy, const Program &program) 
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _worldMatrix = glm::translate(trackMat * _globalMVMatrix, glm::vec3(0,-3,2));

 	for (int i = 1; i < _lights.size(); ++i)
    {
    	_lights[i].goOn(WORLD_SPEED, - (i%2) * LIGHTS_SPACE - 2 * LIGHTS_SPACE);

        _lights[i].getPos() = glm::vec3(trackMat * glm::vec4(_lights[i].getPos(), 1));
        _lights[i].sendLightShader(program, _refLight);
        _lights[i].getPos() = glm::vec3(glm::inverse(trackMat) * glm::vec4(_lights[i].getPos(), 1));
    }

    /////////// RELATIVE TO PLAYER /////////

    _playerMatrix = _worldMatrix;
    _playerMatrix = glm::translate(_playerMatrix, glm::vec3(player.posX(), player.posY(), 0));

    glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_playerMatrix));
    glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
    glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _playerMatrix));
    
    glUniform1i(_uTexture, 0);
    player.model()->texture().bind();
    player.model()->vbo().draw();
    player.model()->texture().debind();

    ////////////////////////////////////////
    
    /////////// RELATIVE TO ENEMY /////////

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

    ////////////////////////////////////////

    _objectMatrix = _worldMatrix;

    for (int i = 0; i < sectionMat[0].size(); ++i)
    {   
        sectionMat[0][i]->goOn(WORLD_SPEED);

        if (fabs(sectionMat[0][i]->posZ()) < DRAW_DISTANCE)
        {
            switch (_rotateIndicator)
            {
                case 0:
                  	_objectMatrix =  glm::translate(_objectMatrix , glm::vec3(0, 0, sectionMat[0][i]->posZ() - i * POSITION_OFFSET_Z));
                    break;
                case 1:
                    _objectMatrix =  glm::translate(_objectMatrix , glm::vec3(sectionMat[0][_lastRotateIndex]->posZ() + _lastRotateIndex * POSITION_OFFSET_Z, 0, POSITION_OFFSET_Z));
                    break;
                default:
                    break;
            }

            glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_objectMatrix));
            glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
            glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _objectMatrix));

    		glUniform1i(_uTexture, 0);
            sectionMat[0][i]->model()->texture().bind();
            sectionMat[0][i]->model()->vbo().draw();
            sectionMat[0][i]->model()->texture().debind();

            if (sectionMat[0][i]->obstacle().model() != NULL)
            {	
            	_objectMatrix = glm::translate(_objectMatrix, glm::vec3(sectionMat[0][i]->obstacle().posX(), 0, 0));
            	glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_objectMatrix));
            	glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
            	glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _objectMatrix));

            	glUniform1i(_uTexture, 0);
	            sectionMat[0][i]->obstacle().model()->texture().bind();
	            sectionMat[0][i]->obstacle().model()->vbo().draw();
	            sectionMat[0][i]->obstacle().model()->texture().debind();
            	_objectMatrix = glm::translate(_objectMatrix, glm::vec3(-sectionMat[0][i]->obstacle().posX(), 0, 0));
            }

            switch (_rotateIndicator)
            {
                case 0:
                  	_objectMatrix =  glm::translate(_objectMatrix  , glm::vec3(0, 0, -sectionMat[0][i]->posZ() + i * POSITION_OFFSET_Z));
                    break;
                case 1:
                    _objectMatrix =  glm::translate(_objectMatrix  , glm::vec3(-sectionMat[0][_lastRotateIndex]->posZ() - _lastRotateIndex * POSITION_OFFSET_Z, 0, -POSITION_OFFSET_Z));
                    break;
                default:
                    break;
            }

            if (sectionMat[0][i]->isCorner())
            {   
                _objectMatrix = glm::rotate(_objectMatrix, glm::radians(sectionMat[0][i]->cornerDirection() * 90.f), glm::vec3(0,1,0));
                rotated(sectionMat[0][i]->cornerDirection());
                _lastRotateIndex = i;

                if (sectionMat[0][i]->posZ() + i * POSITION_OFFSET_Z <= player.posZ())
                {
                	_globalMVMatrix = glm::rotate(_globalMVMatrix, glm::radians(sectionMat[0][i]->cornerDirection() * 180.f), glm::vec3(0,1,0));
                }
            }
        }
    }
    _objectMatrix = glm::rotate(_objectMatrix, glm::radians(_rotateIndicator * 90.f), glm::vec3(0,-1,0));
    rotated(-_rotateIndicator);

}