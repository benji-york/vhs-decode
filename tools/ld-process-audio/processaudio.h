/************************************************************************

    processaudio.h

    ld-process-audio - Analogue audio processing for ld-decode
    Copyright (C) 2019 Simon Inns

    This file is part of ld-decode-tools.

    ld-process-audio is free software: you can redistribute it and/or
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

#ifndef PROCESSAUDIO_H
#define PROCESSAUDIO_H

#include <QObject>
#include <QFileInfo>

#include "sourcevideo.h"
#include "lddecodemetadata.h"

class ProcessAudio : public QObject
{
    Q_OBJECT
public:
    explicit ProcessAudio(QObject *parent = nullptr);

    bool process(QString inputFileName, bool outputLabels, bool silenceAudio, bool labelEveryField);

signals:

public slots:

private:
    LdDecodeMetaData ldDecodeMetaData;
    LdDecodeMetaData::VideoParameters videoParameters;

    QFile *audioInputFile;
    QFile *audioOutputFile;
    QFile *audacityOutputFile;

    struct AudioData {
        qint16 left;
        qint16 right;
    };

    struct AudioDropout {
        qint32 startSample;
        qint32 endSample;
    };

    QVector<AudioData> fieldAudioData;
    QVector<AudioDropout> fieldAudioDropouts;
    QVector<qint64> sampleStartPosition;

    bool fieldContainsAnalogueAudio(qint32 fieldNumber);
    void getFieldAudioDropouts(qint32 fieldNumber, qint32 minimumDropoutLength);
    void correctAudioDropout(qint32 fieldNumber, qint32 startSample, qint32 endSample);
    void silenceAudioSample(void);

    void writeFieldAudio(void);
    QVector<AudioData> readFieldAudio(qint32 fieldNumber);

    bool openInputAudioFile(QString filename);
    void closeInputAudioFile(void);

    bool openOutputAudioFile(QString filename);
    void closeOutputAudioFile(void);

    bool openAudacityMetadataFile(QString filename);
    void closeAudacityMetadataFile(void);
    void writeAudacityLabels(qint32 fieldNumber, bool labelEveryField);
    void writeAudacityMetadataLabel(qint64 startSample, qint64 endSample, QString description);
};

#endif // PROCESSAUDIO_H
