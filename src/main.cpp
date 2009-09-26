/***************************************************************************
 *   Copyright (C) 2008 by DDD                                          *
 *   dedodong@163.com                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <QApplication>
#include <QFile>

#include "libfetion.h"

#include "FxInstance.h"

#ifdef HAVE_LOG4QT_DEBUG_ENABLED
  /* log4qt configure load */
  #include "log4qt/propertyconfigurator.h"
#endif

int main(int argc, char *argv[])
{
    if (!fx_init())
    {
        fprintf(stderr, "Initialize low level fetion library failed \n");
        exit(0);
    }

    QApplication app(argc, argv);
    QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath());

#ifdef HAVE_LOG4QT_DEBUG_ENABLED
    /*FIXME: real log4qt configuration path */
    Log4Qt::PropertyConfigurator::configure(
            app.applicationDirPath() + "/log4qt.properties");
#endif

    FxInstance *inst = new FxInstance();

    app.setQuitOnLastWindowClosed(false);
    int reslut = app.exec();

    if (inst)
    {
        inst->deleteLater();
    }

    //destroy the libfetion
    fprintf(stderr, "Destroy low level fetion library, ready to exit! \n");
    fx_terminate();

    return reslut;
}
