# -*- coding: utf-8 -*-
# <Copyright and license information goes here.>
from PyQt4.QtCore import *
from PyQt4.QtGui import *
from PyKDE4.plasma import Plasma
from PyKDE4 import plasmascript
import imaplib, re
 
class HelloPython(plasmascript.Applet):
    def __init__(self,parent,args=None):
        plasmascript.Applet.__init__(self,parent)
 
    def init(self):
        self.setHasConfigurationInterface(False)
        self.resize(125, 125)
        self.setAspectRatioMode(Plasma.Square)
 
    def paintInterface(self, painter, option, rect):
        painter.save()
        painter.setPen(Qt.white)
        
        conn = imaplib.IMAP4_SSL("imap.gmail.com", 993)
        conn.login("igisar", "x3i2u51n4")
        unreadCount = re.search("UNSEEN (\d+)", conn.status("INBOX", "(UNSEEN)")[1][0]).group(1)

        painter.drawText(rect, Qt.AlignVCenter | Qt.AlignHCenter, unreadCount)
        painter.restore()
 
def CreateApplet(parent):
    return HelloPython(parent)
