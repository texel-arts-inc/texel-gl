#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace TexelGL {
    class Context {
    private:
        struct ImmutableState {
            struct Version {
                uint32_t major = 0;
                uint32_t minor = 0;
            };

            using Extensions = std::vector <std::string>;

            Version version = {};
            Extensions extensions = {};
        };

    private:
        ImmutableState const immutableState = {};

    public:
        Context(void);
        virtual ~Context(void);

        ImmutableState::Extensions const &
        getExtensions(void) const;

        uint32_t
        getMajorVersion(void) const;

        uint32_t
        getMinorVersion(void) const;
    };
} // namespace TexelGL