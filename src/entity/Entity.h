#pragma once
#include "../common.h"
#include "../components/ID.h"
#include "../components/Transform2D.h"
// #include "./EntityManager.h"

#include <vector>
// #include <unordered_map>
#include <memory>

typedef size_t ComponentID;
typedef size_t EntityID;

// typedef ComponentList std::vector<std::shared_ptr<Component>>;

class Entity {
public:

    EntityID id;

    Entity() {
        // addComponent<ID>();
        // addComponent<Transform2D>();
    }

    // Should be handled by EntityManager, since components keep incrementing ID

    // template <class T>
    // void addComponent() {
    //     // m_components.insert(std::make_pair(m_componentID++, std::shared_ptr<T>()));
    //     m_components.push_back(std::shared_ptr<T>());
    // }

    // std::vector<std::shared_ptr<Component>> getComponents() const {
    //     return m_components;
    // }

    // template <class T>
    // std::shared_ptr<T> getComponent(unsigned int id) {
    //     // auto it = m_components.find(id);

    //     // if(it != m_components.end()) {
    //     //     return it->second;
    //     // }

    //     // return { 0 }; // std::optional???

    //     return m_components[id];
    // }

private:
    // ComponentID m_componentID = 0;
    // std::unordered_map<ComponentID, std::shared_ptr<Component>> m_components;
    // std::vector<std::shared_ptr<Component>> m_components;
};
