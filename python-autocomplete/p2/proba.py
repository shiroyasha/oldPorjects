from PyQt4 import QtGui,QtCore
from PyQt4.Qsci import QsciScintilla, QsciLexerCPP
import sys

app = QtGui.QApplication(sys.argv)
window = QtGui.QWidget()

scint = QsciScintilla(window)
lex = QsciLexerCPP(window,False)
scint.setLexer(lex)
window.show()

sys.exit( app.exec_() )
