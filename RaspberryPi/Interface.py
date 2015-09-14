"""
Interface de controlo para o Hexapod

Versao: 0.8
Feito por: Helder Mascarenhas

Texto adicional: Adicionar mais widgets
				 Talvez de para melhorar a temporalidade dos metodos.
"""

import sys, Packet, serial
from PySide import QtCore, QtGui

pacote = Packet.Packet()
patas = {}

class Widget(QtGui.QWidget):
    
    def __init__(self):
        super(Widget, self).__init__()
        
        self.initUI()
        
    def initUI(self):

        grid = QtGui.QGridLayout()
        transmit = QtGui.QPushButton("Transmit")
        lbl = QtGui.QLabel(self)
        qle = QtGui.QLineEdit(self)
        legs = []

        #Coloca os sliders e os lcd's nas posicoes indicadas.
        for i in range(6):
            legs.append(self.slidernlcd())
            legs[i].setTitle("Leg #" + str(i+1))
            if i < 3:
                grid.addWidget(legs[i], 0, i)
            else:
                grid.addWidget(legs[i], 1, i-3)

        #Mensagem na label
        lbl.setText("Serial: /dev/tty")
            
        #Coloca o botao, textbox e label nas posicoes indicadas.
        grid.addWidget(transmit, 2, 2)
        grid.addWidget(lbl, 2, 0)
        grid.addWidget(qle, 2, 1)


        #Executa a funcao sendpacket() caso o botao transmit tenha sido clicado.
        self.connect(transmit, QtCore.SIGNAL("clicked()"), lambda: self.sendpacket(legs, qle))
        
        self.setLayout(grid)


        
    def slidernlcd(self):
        groupBox = QtGui.QGroupBox()
        groupBox.setCheckable(True)
        groupBox.setChecked(False)

        #SLIDER
        sld = QtGui.QSlider(QtCore.Qt.Horizontal)
        sld1 = QtGui.QSlider(QtCore.Qt.Horizontal)
        sld2 = QtGui.QSlider(QtCore.Qt.Horizontal)
        sld.setFocusPolicy(QtCore.Qt.NoFocus)
        sld1.setFocusPolicy(QtCore.Qt.NoFocus)
        sld2.setFocusPolicy(QtCore.Qt.NoFocus)
        sld.setRange(0,180) #Alterar conforme necessario
        sld1.setRange(0,180) #Alterar conforme necessario
        sld2.setRange(0,180) #Alterar conforme necessario
        sld.setStatusTip('1st Angle!')
        sld1.setStatusTip('2nd Angle!')
        sld2.setStatusTip('3rd Angle!')

        #LCD
        lcd = QtGui.QLCDNumber(self)
        lcd1 = QtGui.QLCDNumber(self)
        lcd2 = QtGui.QLCDNumber(self)
        black = "#000000"
        style_str = "QWidget {background-color: %s}"
        lcd.setStyleSheet(style_str % black)
        lcd1.setStyleSheet(style_str % black)
        lcd2.setStyleSheet(style_str % black)

        #Altera o valor do lcd quando o slider altera.
        sld.valueChanged.connect(lcd.display)
        sld1.valueChanged.connect(lcd1.display)
        sld2.valueChanged.connect(lcd2.display)

        #Junta 3 lcd's e 3 sliders numa box de modo a poder representar uma perna.
        vbox = QtGui.QVBoxLayout()
        vbox.addWidget(sld)
        vbox.addWidget(lcd)
        vbox.addWidget(sld1)
        vbox.addWidget(lcd1)
        vbox.addWidget(sld2)
        vbox.addWidget(lcd2)
        vbox.addStretch(1)
        groupBox.setLayout(vbox)

        return groupBox

    def sendpacket(self, y, txt):
        i = 0
        for x in y:  
            if x.isChecked():
                ang1 = x.children()[2].intValue()
                ang2 = x.children()[4].intValue()
                ang3 = x.children()[6].intValue()
                patas[i] = Packet.Leg()
                patas[i].setAngles(ang1, ang2, ang3)
                pacote.setLeg(i+1, patas[i])
            i += 1

        
        for character in pacote.getPack():
            print character, character.encode('hex')
        
        ser = serial.Serial('/dev/tty' + txt.text(), 9600)

        for x in pacote.getPack():
        	ser.write(x)
        
    
class MainWindow(QtGui.QMainWindow):
    
    def __init__(self):
        super(MainWindow, self).__init__()
        
        self.initUI()
        
    def initUI(self):               
        
        et = Widget()
        self.setCentralWidget(et)

        #BARRA DE STATUS
        self.statusBar()

        
        #SAIR (shortcuts, mensagens, etc)
        exitAction = QtGui.QAction('Exit', self)
        exitAction.setShortcut('Ctrl+Q')
        exitAction.setStatusTip('Exit application')
        exitAction.triggered.connect(self.close)
        

        #TOOLBAR INTEGRADA
        toolbar = self.addToolBar('Toolbar')
        toolbar.addAction(exitAction)

        #MENU DE TOPO
        menubar = self.menuBar()
        fileMenu = menubar.addMenu('&File')
        fileMenu.addAction(exitAction)

        
        #MAIN WINDOW
        self.setFixedSize(500, 600);
        self.setWindowTitle('RaspberryPi To Arduino')    
        self.show()

    def closeEvent(self, event):
        
        reply = QtGui.QMessageBox.question(self, 'Message', "Are you sure to quit?", QtGui.QMessageBox.Yes | QtGui.QMessageBox.No)

        if reply == QtGui.QMessageBox.Yes:
            event.accept()
        else:
            event.ignore()   
        
        
def main():
    
    app = QtGui.QApplication(sys.argv)
    ex = MainWindow()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()