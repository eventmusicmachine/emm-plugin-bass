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

#include "basschannel.h"

using namespace Bass::Internal;

BassChannel::BassChannel(QString fileName) : Audio::IChannel()
{
    m_stream = BASS_StreamCreateFile(false, fileName.toLatin1(), 0, 0, BASS_SAMPLE_FLOAT | BASS_STREAM_DECODE);
}

void BassChannel::play()
{

}

void BassChannel::pause()
{

}

void BassChannel::stop()
{

}
