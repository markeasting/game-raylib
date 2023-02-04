#pragma once
#include "../common.h"
#include "../components/Component.h"
#include "../components/ID.h"

#include "./Entity.h"

#include <vector>
#include <memory>

typedef size_t EntityID;

class EntityManager {
public:
    // std::vector<std::shared_ptr<unsigned int>> m_entities;
    // std::bitset mapping

    // Entity create() {
    //     auto e = std::shared_ptr<Entity>();
    //     m_entities.push_back(e);
    //     return e;
    // }

    EntityID add(Entity entity) {
        size_t id = m_entities.size();

        entity.id = id;

        ID entityID;
        addComponent(entity, entityID);
        // addComponent<ID>(entity);

        m_entities.push_back(std::make_shared<Entity>(entity));

        return entity.id; // m_entityIdx++;
    }

    template <typename T>
    void addComponent(Entity entity, T component) {
        m_components.push_back(std::make_shared<T>(component));
    }

    // template <class T>
    // void addComponent(Entity entity) {
    //     // m_components.insert(std::make_pair(m_componentID++, std::shared_ptr<T>()));
    //     m_components.push_back(std::make_shared<T>());
    // }

private:
    // EntityID m_entityIdx = 0;
    std::vector<std::shared_ptr<Entity>> m_entities;
    std::vector<std::shared_ptr<Component>> m_components;
};
