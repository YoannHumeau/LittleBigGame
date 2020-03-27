#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <unordered_map>
#include "CustomException.h"
#include <string_view>

template <typename T>
class ResourceManager
{
    
    public:
        ResourceManager() = delete;

        static T const& getResource(std::string_view const& path) {
            auto result = map.find(path);
            if (result == std::end(map)) {
                if (!map[path].loadFromFile(path.data()))
                    throw CustomException(path);
                return map[path];
            }
            // Return the value of the pair founded above
            return result->second;
        }
        
    private:
        static inline std::unordered_map<std::string_view, T> map;
};

#endif