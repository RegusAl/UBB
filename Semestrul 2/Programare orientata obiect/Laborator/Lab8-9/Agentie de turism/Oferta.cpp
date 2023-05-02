#include "Oferta.h"

bool cmpDenumire(const Oferta& o1, const Oferta& o2)
{
    return o1.getDenumire() < o2.getDenumire();
}

bool cmpDestinatie(const Oferta& o1, const Oferta& o2)
{
    return o1.getDestinatie() < o2.getDestinatie();
}

bool cmpTipPret(const Oferta& o1, const Oferta& o2)
{
    if (o1.getTip() == o2.getTip())
        return o1.getPret() < o2.getPret();
    else
        return o1.getTip() < o2.getTip();
}