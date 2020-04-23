/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   Copyright 2019, Adriaan de Groot <groot@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#include "utils/Logger.h"

#include <kpmcore/core/partitiontable.h>

#include <QtTest/QtTest>

class KPMTests : public QObject
{
    Q_OBJECT
public:
    KPMTests();
    ~KPMTests() override;
private Q_SLOTS:
    void initTestCase();

    void testFlagNames();
};

KPMTests::KPMTests() {}

KPMTests::~KPMTests() {}

void
KPMTests::initTestCase()
{
    Logger::setupLogLevel( Logger::LOGDEBUG );
}

void
KPMTests::testFlagNames()
{
    int f = 1;
    QStringList names;
    QString s;
    while ( !( s = PartitionTable::flagName( static_cast< PartitionTable::Flag >( f ) ) ).isEmpty() )
    {
        cDebug() << f << s;
        names.append( s );

        f <<= 1;
    }
}


QTEST_GUILESS_MAIN( KPMTests )

#include "moc-warnings.h"

#include "KPMTests.moc"
