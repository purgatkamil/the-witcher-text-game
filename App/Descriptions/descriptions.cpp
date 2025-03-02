#include "descriptions.hpp"

DescriptionsMap Descriptions::descriptions;

void Descriptions::initialize(GameWorld& world) {
    // Pobieramy wskaźniki do lokacji z mapy `world`
    Location* KaerMorhen = world["KaerMorhen"];
    Location* KaerMorhen_Courtyard_Lower = world["KaerMorhen_Courtyard_Lower"];
    Location* KaerMorhen_Courtyard_Middle = world["KaerMorhen_Courtyard_Middle"];
    Location* KaerMorhen_Courtyard_Upper = world["KaerMorhen_Courtyard_Upper"];

    // Przypisujemy opisy do wskaźników lokacji
    descriptions[KaerMorhen] = "The ancient stronghold of the witchers, nestled deep within the Amell Mountains, shrouded in mist and forgotten history. Its weathered stone walls still stand tall over the valley, though their days of glory have long since faded. The wind howls through abandoned towers, carrying echoes of past battles and training. The courtyard, once bustling with young adepts, is now overgrown with weeds, and the old forge barely remembers the warmth of fire. The main hall still smells of smoke and damp stone, while the underground chambers guard tomes filled with knowledge of monsters and elixirs. On the ramparts, the past lingers-a silent presence of long-gone mages and warriors watching over the fallen sanctuary.";
    descriptions[KaerMorhen_Courtyard_Lower] = "The main entrance to Kaer Morhen, guarded by a reinforced gate. A small stable leans against the walls, sheltering a few hardy horses. Scattered training dummies stand battered and worn, silent witnesses to countless drills.";
    descriptions[KaerMorhen_Courtyard_Middle] = "The stronghold’s core, with an old stone well at its center. Nearby, the ruins of a small workshop lie in decay, tools rusting among the rubble. The inner gate looms ahead, leading deeper into the fortress.";
    descriptions[KaerMorhen_Courtyard_Upper] = "Windswept and desolate, with rusting siege cauldrons left to time. Narrow windows and arrow slits offer a stunning yet lonely view of the Amell Mountains. A heavy wooden door, reinforced with iron, leads into the keep’s interior.";
}

std::string Descriptions::getDescription(Location* location) {
    if (descriptions.find(location) != descriptions.end()) {
        return descriptions[location];
    }
    return "No description available.";
}
