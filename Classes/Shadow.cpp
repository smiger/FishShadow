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
	//1、直接投影在当前png图像上
	//auto sprite = Sprite::create("fish.png");  
	//sprite->setPosition(size.width/2, size.height /2 );  

	//auto shader_program = GLProgram::createWithFilenames("shadow.vsh", "shadow.fsh");  
	//shader_program->use();  
	//shader_program->setUniformsForBuiltins();
	//sprite->setGLProgram(shader_program); 
	//this->addChild(sprite);

	////2、拷贝进行投影
	//auto sprite = Sprite::create("fish.png");  
	//sprite->setPosition(size.width/2, size.height /2 );  

	//auto shader_program = GLProgram::createWithFilenames("shadow.vsh", "shadow.fsh");  
	//shader_program->use();  
	//shader_program->setUniformsForBuiltins();

	//auto fishClone = Sprite::create("fish.png");  
	//
	//fishClone->setGLProgram(shader_program);
	//fishClone->setPosition(-10.f, -10.f);
	//fishClone->setAnchorPoint(Vec2(0,0));
	//fishClone->setScale(0.8f);
	//sprite->addChild(fishClone, -1); 
	//this->addChild(sprite);

	//3、以上创建的GLProgram可能在android上跑不出来，
	//原因是shader_program返回的是空值，可用以下方法解决

	auto shader_program = new CCGLProgram();  
	shader_program->retain();  
	shader_program->initWithVertexShaderFilename("shadow.vsh", "shadow.fsh");  

	shader_program->link();  
	shader_program->updateUniforms();


	auto sprite = Sprite::create("fish.png");  
	sprite->setPosition(size.width/2, size.height /2 ); 

	auto fishClone = Sprite::create("fish.png");  
	fishClone->setGLProgram(shader_program);
	fishClone->setPosition(-10.f, -10.f);
	fishClone->setAnchorPoint(Vec2(0,0));
	fishClone->setScale(0.8f);
	sprite->addChild(fishClone, -1); 
	this->addChild(sprite);

	return true;
}
