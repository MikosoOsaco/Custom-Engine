#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H
#include "ResourceManager.h"
#include "Image.h"

class ImageManager
{
public:
	typedef ResourceHandle<Image> HandleType;

	static ImageManager* GetInstance();

	ImageManager::HandleType Put(std::string &name, std::string fileName);

	Image* Get(ImageManager::HandleType &handle);
	Image* Get(std::string &name);

	~ImageManager();

private:
	ImageManager();

	ResourceManager<Image> imageManager;
	static ImageManager* instance;
};

#endif // !IMAGEMANAGER_H
