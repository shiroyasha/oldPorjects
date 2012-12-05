#!/usr/bin/env python

from PyQt4 import QtGui, QtCore

class CodeEditor(QtGui.QPlainTextEdit):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)

        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Quit button')

