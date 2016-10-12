#include "HelloWorldScene.h"
#include "CameraRotationTest.h"
#include "PhotoShow.h"
#include "Shadow.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
		Size size = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
										   "CloseNormal.png",
										   "CloseSelected.png",
										   CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
								origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	auto layer = Shadow::create();
	this->addChild(layer);

	//scheduleUpdate();
	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
	
	//auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	//
	//// position the label on the center of the screen
	//label->setPosition(Vec2(origin.x + visibleSize.width/2,
	//                        origin.y + visibleSize.height - label->getContentSize().height));

	//// add the label as a child to this layer
	//this->addChild(label, 1);

	//// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("HelloWorld.png");

	//// position the sprite on the center of the screen
	//sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//// add the sprite as a child to this layer
	//this->addChild(sprite, 0);

	////setSkewY效果
 //       CCSprite* pTest = CCSprite::create("godness.png");
 //       pTest->setPosition(ccp(size.width*0.7, size.height*0.75));
 //       this->addChild(pTest);
 //       pTest->setSkewY(25.0);
 //      
 //       //两张旋转图片
 //       p3D1 = cwSprite3D::create("godness.png");
 //       p3D1->setPosition(ccp(size.width*0.3, size.height*0.5));
 //       p3D1->rotateY(0);
 //       this->addChild(p3D1);

 //       p3D2 = cwSprite3D::create("godness.png");
 //       p3D2->setPosition(ccp(size.width*0.6, size.height*0.25));
 //       p3D2->rotateY(0);
 //       this->addChild(p3D2);
 //      
 //       //角度计数器
 //       fDegree1 = 0;
 //       fDegree2 = 0;
 //      
 //       this->scheduleUpdate();
	//auto camera = CameraRotationTest::create();
	//addChild(camera);
	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
void HelloWorld::update(float dt)
{

}