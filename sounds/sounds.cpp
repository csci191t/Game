#include "sounds.h"
using namespace irrklang;

ISoundEngine* engine = createIrrKlangDevice();

sounds::sounds()
{
    //ctor

}

sounds::~sounds()
{
    //dtor
    engine->drop(); // delete engine
}
void sounds::playMusic(char* File)
{
      engine->play2D(File,true);

}

void sounds::playSound(char* File)
{
     engine->play2D(File,false,false);

}

void sounds::pauseSound(char* File)
{
    engine->play2D(File, true,false);
}

void sounds::stopAllSounds()
{

}


int sounds::initSounds()
{

     if (!engine)
	{
		cout<<"Could not startup engine\n";
		return 0; // error starting up the engine
	}
	return 1;
}
/*
unifrom sampler2D myTextrure;
varyin vec2 VtexCoord;
void main*()
           {
           gl_FragColor - vec4(1.0,0.0.,0.0,1.0);// just change color
           gl_FragColor = texture2D(myTexture),vTexCoord).rgba;//with texture



           // extra
           uniform float scale;
           varying vec2vTExCoord;
           vec4 a - gl)vertex; // "a" will get hte verticies value form CPU

           vTextCoord - vec2(gl_MultiTexCoord
           }
*/

