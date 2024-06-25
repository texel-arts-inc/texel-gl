#pragma once

#include <cstdint>
#include <memory>
#include <vector>

namespace TexelGL {
class Buffer;
class Object;

class ObjectTable {
private:
    std::vector <std::shared_ptr <Object>> objectList = {};
    std::vector <size_t> freeList = {};

public:
    ObjectTable(void);

    ~ObjectTable(void);

    uint32_t
    allocateObject(std::shared_ptr <Object> const &object);

    void
    deallocateObject(uint32_t id);

    std::shared_ptr <Object>
    getObject(uint32_t id) const;
};
} // namespace TexelGL