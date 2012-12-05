#!/usr/bin/env python

import sys

from PyQt4.QtCore import QSize, Qt
from PyQt4.QtGui import QBrush, QPainter, QWidget


print sys.version
from PyQt4.pyqtconfig import _pkg_config
print _pkg_config

class Widget(QWidget):

    def __init__(self, *args):
    
        QWidget.__init__(self, *args)
    
    def __del__(self):
    
        print "__del__", self
    
    def paintEvent(self, event):
    
        painter = QPainter()
        painter.begin(self)
        painter.fillRect(event.rect(), QBrush(Qt.white))
        size = min(self.width(), self.height())
        painter.setViewport(self.width()/2 - size/2, self.height()/2 - size/2,
                            size, size)
        painter.setWindow(0, 0, 100, 100)
        painter.drawText(10, 10, 80, 80, Qt.AlignCenter, "Python")
        painter.end()
    
    def sizeHint(self):
    
        return QSize(200, 200)


if __name__ == "__main__":

    from PyQt4.QtGui import QApplication, QGridLayout
    
    app = QApplication(sys.argv)
    parentWidget = QWidget()
    layout = QGridLayout(parentWidget)
    for i in range(2):
        for j in range(3):
        
            widget = Widget(parentWidget)
            layout.addWidget(widget, i, j)
    
    parentWidget.show()
    sys.exit(app.exec_())
