# Resource object code (Python 3)
# Created by: object code
# Created by: The Resource Compiler for Qt version 6.9.3
# WARNING! All changes made in this file will be lost!

from PySide6 import QtCore

qt_resource_data = b"\
\x00\x00\x00\x03\
a\
bc\
"

qt_resource_name = b"\
\x00\x06\
\x07\xaa\x8a\xf3\
\x00s\
\x00t\x00a\x00t\x00i\x00c\
\x00\x0c\
\x03\x81\x0et\
\x00t\
\x00e\x00s\x00t\x00f\x00i\x00l\x00e\x00.\x00t\x00x\x00t\
"

qt_resource_struct = b"\
\x00\x00\x00\x00\x00\x02\x00\x00\x00\x01\x00\x00\x00\x01\
\x00\x00\x00\x00\x00\x00\x00\x00\
\x00\x00\x00\x00\x00\x02\x00\x00\x00\x01\x00\x00\x00\x02\
\x00\x00\x00\x00\x00\x00\x00\x00\
\x00\x00\x00\x12\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\
\x00\x00\x01\x91\xe0\x22%\xe0\
"

def qInitResources():
    QtCore.qRegisterResourceData(0x03, qt_resource_struct, qt_resource_name, qt_resource_data)

def qCleanupResources():
    QtCore.qUnregisterResourceData(0x03, qt_resource_struct, qt_resource_name, qt_resource_data)

qInitResources()
