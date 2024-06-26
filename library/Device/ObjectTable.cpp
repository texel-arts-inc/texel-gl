#include <cassert>
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
TexelGL::ObjectTable::allocateObject(std::shared_ptr <Object> const &object)
{
    assert(object);

    auto id = uint32_t(0);

    if (!this->freeList.empty()) {
        id = this->freeList.back();
        this->freeList.pop_back();
    } else {
        id = this->objectList.size() +
             1;

        this->objectList.resize(id);
    }

    assert(!this->objectList[id -
                             1]);
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

    if (!objectList[id -
                    1]) {
        assert(false);
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

void
TexelGL::ObjectTable::reset(void)
{
    this->objectList.clear();
}
