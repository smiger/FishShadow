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
	//1��ֱ��ͶӰ�ڵ�ǰpngͼ����
	//auto sprite = Sprite::create("fish.png");  
	//sprite->setPosition(size.width/2, size.height /2 );  

	//auto shader_program = GLProgram::createWithFilenames("shadow.vsh", "shadow.fsh");  
	//shader_program->use();  
	//shader_program->setUniformsForBuiltins();
	//sprite->setGLProgram(shader_program); 
	//this->addChild(sprite);

	////2����������ͶӰ
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

	//3�����ϴ�����GLProgram������android���ܲ�������
	//ԭ����shader_program���ص��ǿ�ֵ���������·������

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
