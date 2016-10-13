// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <engine/renderer.h>
#include <project/mainscene.h>
#include <project/menuscene.h>
#include <project/creditsscene.h>
#include <engine/scene.h>

Renderer* renderer;
Mainscene* mainscene;
MenuScene* menuscene;
CreditsScene* creditsscene;
int main(int argc, char *argv[])
{
    std::vector<Scene*> scenes;
    renderer = new Renderer();
    mainscene = new Mainscene();
    menuscene = new MenuScene();
    creditsscene = new CreditsScene();
    scenes.push_back(menuscene);
    scenes.push_back(mainscene);
    scenes.push_back(creditsscene);

    Scene* curscene = menuscene;
    int sceneCounter = 0;
    do{
        if(sceneCounter == 0){
            if(menuscene->cred){
                creditsscene->clickfix = false;
                sceneCounter +=2;
                menuscene->cred = false;
            }
        }
        if(curscene->nextScene){

            if(sceneCounter == 0){
                sceneCounter = 1;
            }else {
                sceneCounter = 0;
            }
            curscene->nextScene = false;

        }
        curscene = scenes[sceneCounter];
        renderer->renderScene(curscene);
    }
	while(!renderer->mustStop() && !curscene->wantsToQuit);

    delete creditsscene;
    delete mainscene;
    delete menuscene;
    delete renderer;
    scenes[0] = NULL;
    scenes[1] = NULL;
    scenes[2] = NULL;
    scenes.clear();

	return 0;
}
