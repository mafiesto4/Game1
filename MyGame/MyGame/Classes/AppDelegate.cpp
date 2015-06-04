#include "AppDelegate.h"
#include "MainMenu\MainMenuScene.h"
#include "Game.h"
#include "HUD/DebugGUI.h"
#include "Scores/Highscores.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

	GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if(!glview)
	{
		glview = GLViewImpl::create("Spejson");

		glview->setFrameSize(1280, 720);

		/*glview->setFrameSize(1024, 720);
		auto win32 = glview->getWin32Window();
		
		HDC hDC = ::GetWindowDC(NULL);
		::SetWindowPos(win32, 
					   NULL, 0, 0, 
					   ::GetDeviceCaps(hDC, HORZRES),
					   ::GetDeviceCaps(hDC, VERTRES),
					   SWP_FRAMECHANGED);*/

		director->setOpenGLView(glview);
	}

	// turn on/off display FPS
	director->setDisplayStats(false);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60);

	// Pobierz instancje gry
	auto game = Game::getInstance();

	// Load scores
	Scores.load();

	// setup background audio
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Audio/moon_paris.wav", true);

	// otworz menu
	auto scene = MainMenuScene::create();

	// run
	director->runWithScene(scene);

	//CocosDenshion::SimpleAudioEngine::getInstance()->end();

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
	Director::getInstance()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	//CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	//CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
