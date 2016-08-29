#include "recoursemanager.h"
#include <iostream>

Recoursemanager::Recoursemanager(){

}

Recoursemanager::~Recoursemanager(){
    for(unsigned int i = 0; i < loadedImages.size(); i++){
        delete this->loadedImages[i];
        this->loadedImages[i] = NULL;
    }
    loadedImages.clear();
    for(unsigned int i = 0; i < fontPaths.size(); i++){
        TTF_CloseFont(loadedFonts[i]);
        loadedFonts[i]= NULL;
    }
    loadedFonts.clear();
    fontPaths.clear();
}

Image* Recoursemanager::getImage(std::string imagepath, bool tga){
    for(unsigned int i = 0; i < loadedImages.size(); i++){
        if(this->loadedImages[i]->getImgPath() == imagepath){
            return this->loadedImages[i];
        }
    }

    Image* img;
    img = new Image();
    if(tga){
        img->loadTGA(imagepath);
    }else{
        img->loadPNG(imagepath);
    }

    this->loadedImages.push_back(img);
    return img;
}

TTF_Font* Recoursemanager::getFont(std::string fontpath, int size){
    for(unsigned int i = 0; i < fontPaths.size(); i++){
        if(this->fontPaths[i] == fontpath){
            return this->loadedFonts[i];

        }
    }
    std::cout << "loading font: " << fontpath << std::endl;
    TTF_Font* f;
    f = NULL;
    f = TTF_OpenFont(fontpath.c_str(), size);
    loadedFonts.push_back(f);
    fontPaths.push_back(fontpath);

    return f;
}
