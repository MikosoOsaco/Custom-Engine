#include "MeshManager.h"

MeshManager::MeshManager()
{

}

MeshManager* MeshManager::instance = nullptr;
MeshManager* MeshManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new MeshManager();
	}
	return instance;
}

MeshManager::~MeshManager()
{
	meshManager.clearKeysAndValues();
	delete instance;
}

MeshManager::HandleType MeshManager::Put(std::string &name, SingleMesh* mesh)
{
	return meshManager.put(name, mesh);
}

SingleMesh* MeshManager::Get(MeshManager::HandleType &handle)
{
	return meshManager.get(handle);
}

SingleMesh* MeshManager::Get(std::string &name)
{
	MeshManager::HandleType handle = meshManager.get(name);
	return Get(handle);
}