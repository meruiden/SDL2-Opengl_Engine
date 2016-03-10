// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <engine/renderer.h>
#include <project/mainscene.h>

Renderer* renderer;
Mainscene* mainscene;
int main( void )
{
    renderer = new Renderer();
    mainscene = new Mainscene();
    do{
        renderer->renderScene(mainscene);
    } // Check if the ESC key was pressed or the window was closed
	while( !renderer->mustStop() );

    delete renderer;
    delete mainscene;

	return 0;
}
