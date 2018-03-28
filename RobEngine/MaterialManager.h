#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H
#include "ResourceManager.h"
#include "Material.h"

class MaterialManager
{
public:
	typedef ResourceHandle<Material> HandleType;

	static MaterialManager* GetInstance();

	MaterialManager::HandleType Put(std::string &name, Material *mat);

	Material* Get(MaterialManager::HandleType &handle);
	Material* Get(std::string &name);

	~MaterialManager();

private:
	MaterialManager();

	ResourceManager<Material> materialManager;
	static MaterialManager* instance;
};

#endif // !MATERIALMANAGER_H
