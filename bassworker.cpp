/**************************************************************************
 * Event Music Machine
 * Copyright (C) 2014-2017 Christoph Kraemer
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 **************************************************************************/

#include "bassworker.h"

using namespace Bass::Internal;

BassWorker::~BassWorker()
{
    if (!m_initialized) {
        return;
    }

    if (!BASS_Free()) {
        emit errorOccured(BASS_ErrorGetCode());
    }
}

void BassWorker::initialize(int deviceId)
{
    if (!BASS_Init(deviceId, 44100, 0, 0, NULL)) {
        emit errorOccured(BASS_ErrorGetCode());
        return;
    }

    if (!BASS_SetDevice(deviceId)) {
        emit errorOccured(BASS_ErrorGetCode());
        return;
    }

    if (!BASS_GetInfo(&m_info)) {
        emit errorOccured(BASS_ErrorGetCode());
        return;
    }

    emit outputCountUpdated(m_info.speakers / 2);

    m_initialized = true;
}
