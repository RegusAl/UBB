#include "service.h"

#include <algorithm>

vector<Device> Service::sortareModel() {
    vector<Device> sorted{getAll()};
    sort(sorted.begin(), sorted.end(), cmpModel);
    return (sorted);
}

vector<Device> Service::sortarePret() {
    vector<Device> sorted{getAll()};
    sort(sorted.begin(), sorted.end(), cmpPret);
    return (sorted);
}