#include "Shadow.h"

bool Shadow::init()
{
	if(!Layer::init()){
		return false;
	}
	Size size = Director::getInstance()->getWinSize();
	auto bg = Sprite::create("bk.jpg");
	bg->setPosition(size.width/2,size.height/2);
	this->addChild(bg);
	//直接投影在当前png图像上
	//auto sprite = Sprite::create("fish.png");  
	//sprite->setPosition(size.width/2, size.height /2 );  

	//auto shader_program = GLProgram::createWithFilenames("shadow.vsh", "shadow.fsh");  
	//shader_program->use();  
	//shader_program->setUniformsForBuiltins();
	//sprite->setGLProgram(shader_program); 
	//this->addChild(sprite);


	auto sprite = Sprite::create("fish.png");  
	sprite->setPosition(size.width/2, size.height /2 );  

	auto shader_program = GLProgram::createWithFilenames("shadow.vsh", "shadow.fsh");  
	shader_program->use();  
	shader_program->setUniformsForBuiltins();

	auto fishClone = Sprite::createWithSpriteFrame(sprite->getSpriteFrame());
	fishClone->setPosition(10, 5); 
	fishClone->setGLProgram(shader_program);
	sprite->addChild(fishClone, -1); 
	this->addChild(sprite);

	return true;
}
