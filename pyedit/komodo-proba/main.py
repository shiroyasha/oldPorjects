#!/usr/bin/env python

import sys
import CodeEdit
from PyQt4 import QtGui, QtCore

            
def main():
    print "proba"
    app = QtGui.QApplication(sys.argv)
    qb =  CodeEdit.CodeEditor()
    qb.show()
    
    sys.exit(app.exec_())
    
main()

