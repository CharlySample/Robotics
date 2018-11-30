
# Este programa se ejecuta en la consola Python de FreeCAD con el comando "execfile(/carpeta/*.py)". Este archivo en particular permite mover los componentes con las funciones de la libreria C++

import FreeCAD as App
import FreeCADGui as Gui
from PyQt4 import QtCore, QtGui

# execfile("/home/carlos/Documents/Universidad/Simulacion/engranessim.py")
FreeCAD.open("/home/carlos/Documents/Universidad/Simulacion/engranes.fcstd")
App.setActiveDocument("engranes")
App.ActiveDocument=App.getDocument("engranes")
Gui.ActiveDocument=Gui.getDocument("engranes")
import sys
sys.path.append('/home/carlos/Documents/Universidad/Simulacion')
import MoveModule

move=MoveModule.pMovement()
PI = 3.14159
w0=0

def Leonardo():
     global PI, move, w0, w1
     
     # Primer Engran (se mueve solo)
     w0+=PI/8
     App.getDocument("engranes").E0.Placement=App.Placement(App.Vector(0,0,0), App.Rotation(w0,0,0), App.Vector(0,0,0))
     
     #Segundo y tercer engran
     move.GearToGear(w0,20,20,1)
     w1=move.ResultW
     App.getDocument("engranes").E0002.Placement=App.Placement(App.Vector(-50.8,0,0), App.Rotation(-9+w1,0,0), App.Vector(0,0,0))
     App.getDocument("engranes").E0001.Placement=App.Placement(App.Vector(50.8,0,0), App.Rotation(9+w1,0,0), App.Vector(0,0,0))

timer=QtCore.QTimer()
timer.timeout.connect(Leonardo)
timer.start(10)


