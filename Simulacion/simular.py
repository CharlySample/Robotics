
# Este programa se ejecuta en la consola Python de FreeCAD con el comando "execfile(/carpeta/*.py)". Este archivo en particular permite mover los componentes con las funciones de la libreria C++

import FreeCAD as App
import FreeCADGui as Gui
from PyQt4 import QtCore, QtGui

# execfile("/home/carlos/Documents/Universidad/Simulacion/simular.py")
FreeCAD.open("/home/carlos/Documents/Universidad/Simulacion/Mecanismo.fcstd")
App.setActiveDocument("Mecanismo")
App.ActiveDocument=App.getDocument("Mecanismo")
Gui.ActiveDocument=Gui.getDocument("Mecanismo")
import sys
sys.path.append('/home/carlos/Documents/Universidad/Simulacion/')
import MoveModule

move=MoveModule.pMovement()
PI = 3.14159
w0=0

def Leonardo():
     global PI, move, w0, w1, v
     
     # Primer Engran (se mueve solo)
     w0+=PI/5
     App.getDocument("Mecanismo").E0.Placement=App.Placement(App.Vector(-1.524,0,0), App.Rotation(0,1+w0,0), App.Vector(0,0,0))
     
     # Segundo engran
     move.GearToGear(w0,15,26,0)
     w1=move.ResultW
     App.getDocument("Mecanismo").E1.Placement=App.Placement(App.Vector(50.8,0,0), App.Rotation(0,w1,0), App.Vector(0,0,0))
     
     # Piston
     move.Oscilar(w1/10,50)
     v=move.ResultV
     App.getDocument("Mecanismo").L3.Placement=App.Placement(App.Vector(80+v,0,80+v), App.Rotation(0,0,0), App.Vector(0,0,0))
     

timer=QtCore.QTimer()
timer.timeout.connect(Leonardo)
timer.start(10)


