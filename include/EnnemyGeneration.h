#ifndef ENNEMYGENERATION_H
#define ENNEMYGENERATION_H

#include <map>
#include <list>

struct EnnemyToGenerate {
    int ennemyType;
    int ypos;
};

class EnnemyGeneration
{
    public:
        static std::map<int, std::list<EnnemyToGenerate>> GetEnnemiesToGenerate();
};

#endif 