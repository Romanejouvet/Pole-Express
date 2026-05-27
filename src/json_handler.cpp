#include "json_handler.hpp"

GridParam readJson(std::string path){
    std::ifstream f(path);
    json data = json::parse(f);
    GridParam params;

    params.size_grid = data["size_grid"].get<int>();

    params.origin.x = data["origin"][0].get<int>();
    params.origin.y = data["origin"][1].get<int>();

    for (const auto& element : data["path"]) {
        Position p;
        p.x = element[1].get<int>();
        p.y = element[0].get<int>();
        
        // Ajout du point dans le vector de la structure
        params.path.push_back(p);
    }
    return params;
}