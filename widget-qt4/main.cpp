/*
 * main.cpp
 * 
 * Based on the pykpart_launcher.cpp source file for the KPart launcher library.
 * 
 * Copyright (C) 2003-2005 Jim Bublitz, David Boddie <david@boddie.org.uk>
 * 
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public
 * License along with this library; see the file COPYING
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include <Python.h>
#include <QApplication>
#include <QLayout>
#include <QWidget>

#define DEBUG 1

#ifdef DEBUG
#include <QDebug>
#endif

void report_error(char *msg, bool report_python = true)
{
    #ifdef DEBUG
    qDebug() << "error:" << msg;

    if (report_python) PyErr_Print();
    #endif
}

PyObject* call_function(PyObject *callable, PyObject *args)
{
    PyObject *result = NULL, *pArgs;

    if (callable == NULL)
    {
        return NULL;
    }

    if (PyCallable_Check(callable))
    {
        if (args == NULL)
            pArgs = PyTuple_New(0);
        else
            pArgs = args;

        result = PyObject_CallObject(callable, pArgs);

        // If the arguments were created in this function then decrement
        // their reference count.
        if (args == NULL)
            Py_XDECREF(pArgs);
            // pDict and pFunc are borrowed and must not be Py_DECREF-ed.

        if (result == NULL)
        {
            #if debug == 1
            PyErr_Print();
            #else
            PyErr_Clear();
            #endif
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *parentWidget = new QWidget;

    Py_Initialize();

    // Locate the path to the Python module and append it to sys.path list.

    PyRun_SimpleString("import os, sys\n");
    PyRun_SimpleString("sys.path.append('"MODULE_PATH"')\n");

    PyObject *pyModule = PyImport_ImportModule(MODULE_NAME);
    // pyModule is a new reference.

    if (!pyModule) {
        #if debug == 1
        report_error("***failed to import module\n");
        #endif
        return 1;
    }

    PyObject *pyDict = PyModule_GetDict(pyModule);
    /* pDict is a borrowed reference */

    Py_XDECREF(pyModule);

    PyRun_String("import PyQt4.QtGui, sip\n"
                 "def __embedded_factory__wrap_widget__(parentPtr):\n"
                 "    parent = sip.wrapinstance(parentPtr, PyQt4.QtGui.QWidget)\n"
                 "    return parent\n"
                 "def __embedded_factory__create__(parent):\n"
                 "    widget = Widget(parent)\n"
                 "    return sip.unwrapinstance(widget)\n",
                 Py_file_input, pyDict, pyDict);

    // Get the Python module's factory function from the header file at
    // compile time.
    PyObject *pyWrapper = PyDict_GetItemString(pyDict, "__embedded_factory__wrap_widget__");
    // pyWrapper is a borrowed reference.
    PyObject *pyFactory = PyDict_GetItemString(pyDict, "__embedded_factory__create__");
    // pyFactory is a borrowed reference.

    if (!pyFactory || !pyWrapper) {
        #if debug == 1
        report_error("Failed to create embedded functions.\n");
        #endif
        return 2;
    }

    // Set up the args for the Python factory function call.
    PyObject *wrapperArgs = PyTuple_New(1);
    PyObject *pyParentWidgetPtr = PyLong_FromVoidPtr(parentWidget);
    PyTuple_SetItem(wrapperArgs, 0, pyParentWidgetPtr);
    // pyParentWidgetPtr is now owned by the tuple and maintains its reference
    // (it is only referenced once because PyTuple_SetItem does not increase
    // its reference count).

    // Wrap the parent widget so that we can use it with the factory function.
    PyObject *pyParentWidget = call_function(pyWrapper, wrapperArgs);
    // Decrement the reference counts of the wrapper function and its arguments.
    Py_XDECREF(pyWrapper);
    Py_XDECREF(wrapperArgs);

    // Create a tuple containing the arguments to the factory function.
    PyObject *args = PyTuple_New(1);
    PyTuple_SetItem(args, 0, pyParentWidget);
    // pyParentWidget is now owned by the tuple and maintains its reference
    // (it is only referenced once because PyTuple_SetItem does not increase
    // its reference count).

    QGridLayout *layout = new QGridLayout(parentWidget);

    for (int i = 0; i < 2; ++i) {

        for (int j = 0; j < 3; ++j) {

            // Instantiate the class and receive a Widget pointer.
            PyObject *pyWidgetPtr = call_function(pyFactory, args);
            // pyWidgetPtr is a new reference to a long PyObject instance.

            if (pyWidgetPtr)
            {
                // Extract the C++ pointer from the PyObject.
                QWidget *widget = (QWidget*)PyLong_AsVoidPtr(pyWidgetPtr);
                // Decrement the reference count of the long value.
                Py_XDECREF(pyWidgetPtr);
                layout->addWidget(widget, i, j);
            }
            else
            {
                #ifdef DEBUG
                qDebug() << "Failed";
                #endif
            }
        }
    }

    // Decrement the references to the factory function and its arguments.
    Py_XDECREF(args);
    Py_XDECREF(pyFactory);

    parentWidget->show();
    int result = app.exec();

    Py_Finalize();
    return result;
}
