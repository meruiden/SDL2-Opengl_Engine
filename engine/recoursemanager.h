#ifndef RECOURCEMANAGER_H
#define RECOURCEMANAGER_H

#include <vector>
#include <engine/image.h>
#include <SDL_TTF.h>
class Recoursemanager{
public:
    Recoursemanager();
    virtual ~Recoursemanager();

    std::vector<Image*> loadedImages;

    TTF_Font* getFont(std::string fontpath, int size);

    Image* getImage(std::string imagepath, bool tga);
private:
    std::vector<TTF_Font*> loadedFonts;
    std::vector<std::string> fontPaths;
};

#endif
