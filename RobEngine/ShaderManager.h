#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H
#include "ResourceManager.h"
#include "Shader.h"

class ShaderManager
{
public:
	typedef ResourceHandle<Shader> HandleType;

	static ShaderManager* GetInstance();

	ShaderManager::HandleType Put(std::string &name, const char* vertexPath, const char* fragmentPath);

	Shader* Get(ShaderManager::HandleType &handle);
	Shader* Get(std::string &name);

	~ShaderManager();

private:
	ShaderManager();

	ResourceManager<Shader> shaderManager;
	static ShaderManager* instance;
};

#endif // !SHADERMANAGER_H
