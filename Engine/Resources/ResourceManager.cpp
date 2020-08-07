#include "pch.h"
#include "ResourceManager.h"

bool bleh::ResourceManger::Startup()
{
    return true;
}

void bleh::ResourceManger::Shutdown()
{
    RemoveAll();
}

void bleh::ResourceManger::Update()
{
    
}

void bleh::ResourceManger::RemoveAll()
{
    for (auto resource : m_resources)
    {
        resource.second->Destroy();
        delete resource.second;
    }

    m_resources.clear();
}
