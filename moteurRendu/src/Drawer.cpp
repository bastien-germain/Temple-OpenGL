#include "moteurRendu/Drawer.hpp"

Drawer::Drawer(const Program &program) : _rotateIndicator(0), _playerRotateX(0.f), _playerRotateXSpeed(0.f), _speed(0.f)
{
	_projMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
	_globalMVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -3.f));
	_normalMatrix = glm::transpose(glm::inverse(_globalMVMatrix));

	_uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    _uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    _uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    _uTexture = glGetUniformLocation(program.getGLId(), "uTexture");
}

Drawer::~Drawer()
{
}

void Drawer::draw(const float &time, std::vector<std::vector<Section*>> &sectionMat, const glm::mat4 &trackMat, const Player &player) 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _speed = time * 0.0005;
    
    /*if (_speed > 95 && turned == false)
    {
        globalMVMatrix = glm::rotate(globalMVMatrix, glm::radians(90.f), glm::vec3(0,1,0));
        turned = true;
    }*/

    _tmpMatrix = glm::translate(trackMat * _globalMVMatrix, glm::vec3(0,-2,0));
    
    /////////// RELATIVE TO PLAYER ///////////

    _playerMatrix = _tmpMatrix;

    if (_playerRotateX > 25.f || _playerRotateX < -25.f)
        _playerRotateXSpeed *= -1;

    _playerRotateX += _playerRotateXSpeed;

    _playerMatrix = glm::rotate(_playerMatrix, glm::radians(_playerRotateX), glm::vec3(1, 0, 0));
    _playerMatrix = glm::translate(_playerMatrix, glm::vec3(player.posX(), player.posY(), 0));

    glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_playerMatrix));
    glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
    glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _playerMatrix));
    
    glUniform1i(_uTexture, 0);
    player.model()->texture().bind();
    player.model()->vbo().draw();
    player.model()->texture().debind();

    ////////////////////////////////////////

    for (int i = 0; i < sectionMat[0].size(); ++i)
    {   
        sectionMat[0][i]->goOn(-_speed);
        if (fabs(sectionMat[0][i]->posZ()) < 6*POSITION_OFFSET_Z)
        {
            switch (_rotateIndicator)
            {
                case 0:
                    _tmpMatrix =  glm::translate(_tmpMatrix  , glm::vec3(0, 0, -sectionMat[0][i]->posZ()));
                    break;
                case 1:
                    _tmpMatrix =  glm::translate(_tmpMatrix  , glm::vec3(sectionMat[0][5]->posZ(), 0, (i-5)*POSITION_OFFSET_Z));
                    break;
                default:
                    break;
            }

            glUniformMatrix4fv(_uMVMatrix , 1, GL_FALSE, glm::value_ptr(_tmpMatrix));
            glUniformMatrix4fv(_uNormalMatrix , 1, GL_FALSE, glm::value_ptr(_normalMatrix));
            glUniformMatrix4fv(_uMVPMatrix , 1, GL_FALSE, glm::value_ptr(_projMatrix * _tmpMatrix));

            switch (_rotateIndicator)
            {
                case 0:
                    _tmpMatrix =  glm::translate(_tmpMatrix  , glm::vec3(0, 0, sectionMat[0][i]->posZ()));
                    break;
                case 1:
                    _tmpMatrix =  glm::translate(_tmpMatrix  , glm::vec3(-sectionMat[0][5]->posZ(), 0, -(i-5)*POSITION_OFFSET_Z));
                    break;
                default:
                    break;
            }
    		glUniform1i(_uTexture, 0);
            sectionMat[0][i]->model()->texture().bind();
            sectionMat[0][i]->model()->vbo().draw();
            sectionMat[0][i]->model()->texture().debind();

            if (sectionMat[0][i]->isCorner())
            {   
                _tmpMatrix = glm::rotate(_tmpMatrix, glm::radians(sectionMat[0][i]->cornerDirection() * 90.f), glm::vec3(0,1,0));
                rotated(sectionMat[0][i]->cornerDirection());
            }
        }
    }
    _tmpMatrix = glm::rotate(_tmpMatrix, glm::radians(_rotateIndicator * 90.f), glm::vec3(0,-1,0));
    rotated(-_rotateIndicator);

}