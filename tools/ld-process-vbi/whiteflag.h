/************************************************************************

    whiteflag.h

    ld-process-vbi - VBI and IEC NTSC specific processor for ld-decode
    Copyright (C) 2018-2021 Simon Inns

    This file is part of ld-decode-tools.

    ld-process-vbi is free software: you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

************************************************************************/

#ifndef WHITEFLAG_H
#define WHITEFLAG_H

#include "sourcevideo.h"
#include "lddecodemetadata.h"

class WhiteFlag
{
public:
    bool getWhiteFlag(const SourceVideo::Data &activeLineData, LdDecodeMetaData::VideoParameters videoParameters);
};

#endif // WHITEFLAG_H
