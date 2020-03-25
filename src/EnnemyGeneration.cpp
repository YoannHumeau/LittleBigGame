#include <iostream>
#include <fstream>
#include <string>
#include "EnnemyGeneration.h"
#include "CsvReader.h"
#include <map>
#include <list>
#include <vector>

std::map<int, std::list<EnnemyToGenerate>> EnnemyGeneration::GetEnnemiesToGenerate()
{
    // Create dictionnary of list of enemy
    std::map<int, std::list<EnnemyToGenerate>> enm;

    // Second for the value

    // Read the csv file
    io::CSVReader<3> csv("level1.csv");
    // Get values for each lines
    int time, ennemy, ypos;
    csv.read_header(io::ignore_extra_column, "time", "ennemy", "ypos");
    // For each lines, insert the ennemy in the dictionnary of ennemies
    while(csv.read_row(time, ennemy, ypos)) {
        enm[time].push_back({ennemy, ypos});
    }

    return enm;
}