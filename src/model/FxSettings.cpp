/*
 * FxSettings.cpp
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#include "FxSettings.h"

FxSettings::FxSettings()
{
    // TODO Auto-generated constructor stub

}

FxSettings::~FxSettings()
{
    // TODO Auto-generated destructor stub
}

FxSettings *
FxSettings::getInstance()
{
    static FxSettings objectInstance;
    return &objectInstance;
}
