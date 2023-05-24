#include "device.h"

bool cmpModel(const Device &d1, const Device &d2) {
    return d1.getModel() < d2.getModel();
}

bool cmpPret(const Device &de1, const Device &de2) {
    return de1.getPret() < de2.getPret();
}