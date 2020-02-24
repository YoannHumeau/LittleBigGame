#include "include/Scene.hh"
#include "include/TimeManager.hh"
#include "include/json.hpp"
#include <iostream>
#include "include/MonsterFactory.hh"

using json = nlohmann::json;

Scene::Scene() 
{}

Scene::Scene(const std::string& sceneJson)
{
    json j = json::parse(sceneJson);
    Character *c;
    MonsterFactory *mf = new MonsterFactory();

    for(json object: j) {
        c = mf->Unserialize(object.dump());
        this->AddEntity(c);
    }
}

Scene::~Scene() 
{}

std::list<AbstractEntity*> Scene::GetEntities() const
{
    return this->_entities;
}

void Scene::AddEntity(AbstractEntity *entity)
{
    this->_entities.push_back(entity);
}

void Scene::RemoveEntity(AbstractEntity *entity)
{
    this->_entities.remove(entity);
}

void Scene::Update(void)
{
    TimeManager &tm = TimeManager::GetInstance();
    tm.Update();

    for (AbstractEntity *entity: this->_entities) {
        entity->Update();
        entity->Draw();
    }
}

std::string Scene::Serialize()
{
    json j;
    
    for(AbstractEntity *entity: this->_entities)
        j.push_back(json::parse(entity->Serialize()));

    return j.dump();
}