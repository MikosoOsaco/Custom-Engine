#include "ImageManager.h"

ImageManager::ImageManager()
{

}

ImageManager* ImageManager::instance = nullptr;
ImageManager* ImageManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ImageManager();
	}
	return instance;
}

ImageManager::~ImageManager()
{
	imageManager.clearKeysAndValues();
	delete instance;
}

ImageManager::HandleType ImageManager::Put(std::string &name, std::string fileName)
{
	return imageManager.put(name, new Image(name, fileName));
}

Image* ImageManager::Get(ImageManager::HandleType &handle)
{
	return imageManager.get(handle);
}

Image* ImageManager::Get(std::string &name)
{
	ImageManager::HandleType handle = imageManager.get(name);
	return Get(handle);
}