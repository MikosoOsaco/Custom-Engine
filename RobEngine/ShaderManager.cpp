#include "ShaderManager.h"

ShaderManager::ShaderManager()
{

}

ShaderManager* ShaderManager::instance = nullptr;
ShaderManager* ShaderManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ShaderManager();
	}
	return instance;
}

ShaderManager::~ShaderManager()
{
	shaderManager.clearKeysAndValues();
	delete instance;
}

ShaderManager::HandleType ShaderManager::Put(std::string &name, const char* vertexPath, const char* fragmentPath)
{
	return shaderManager.put(name, new Shader(name, vertexPath, fragmentPath));
}

Shader* ShaderManager::Get(ShaderManager::HandleType &handle)
{
	return shaderManager.get(handle);
}

Shader* ShaderManager::Get(std::string &name)
{
	ShaderManager::HandleType handle = shaderManager.get(name);
	return Get(handle);
}