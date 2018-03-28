#include "MaterialManager.h"

MaterialManager::MaterialManager()
{

}

MaterialManager* MaterialManager::instance = nullptr;
MaterialManager* MaterialManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new MaterialManager();
	}
	return instance;
}

MaterialManager::~MaterialManager()
{
	materialManager.clearKeysAndValues();
	delete instance;
}

MaterialManager::HandleType MaterialManager::Put(std::string &name, Material *mat)
{
	mat->SetName(name);
	return materialManager.put(name, mat);
}

Material* MaterialManager::Get(MaterialManager::HandleType &handle)
{
	return materialManager.get(handle);
}

Material* MaterialManager::Get(std::string &name)
{
	MaterialManager::HandleType handle = materialManager.get(name);
	return Get(handle);
}