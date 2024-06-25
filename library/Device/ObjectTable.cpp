#include "Buffer.h"
#include "ObjectTable.h"

TexelGL::ObjectTable::ObjectTable(void)
{
}

TexelGL::ObjectTable::~ObjectTable(void)
{
    this->freeList.clear();
    this->objectList.clear();
}

uint32_t
TexelGL::ObjectTable::allocateObject(std::shared_ptr<Object> const &object)
{
    if (!this->freeList.empty()) {
        auto const id = this->freeList.back();

        this->freeList.pop_back();
        return id;
    }

    auto const id = this->objectList.size() +
                    1;

    this->objectList.resize(id);
    this->objectList[id -
                     1] = object;
    return id;
}

void
TexelGL::ObjectTable::deallocateObject(uint32_t id)
{
    auto &objectList = this->objectList;

    if (!id ||
        (id >
         objectList.size())) {
        return;
    }

    if (!objectList[id]) {
        return;
    }

    objectList[id -
               1] = nullptr;
    this->freeList.push_back(id);
}

std::shared_ptr <TexelGL::Object>
TexelGL::ObjectTable::getObject(uint32_t id) const
{
    auto &objectList = this->objectList;

    if (!id ||
        (id >
         objectList.size())) {
        return nullptr;
    }

    return objectList[id -
                      1];
}