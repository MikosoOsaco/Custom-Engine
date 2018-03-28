#ifndef MESHMANAGER_H
#define MESHMANAGER_H
#include "ResourceManager.h"
#include "SingleMesh.h"

class MeshManager 
{
public:
	typedef ResourceHandle<SingleMesh> HandleType;

	static MeshManager* GetInstance();

	MeshManager::HandleType Put(std::string &name, SingleMesh *mesh);

	SingleMesh* Get(MeshManager::HandleType &handle);
	SingleMesh* Get(std::string &name);

	~MeshManager ();

private:
	MeshManager();

	ResourceManager<SingleMesh> meshManager;
	static MeshManager* instance;
};

#endif // !MESHMANAGER_H
