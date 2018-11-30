
# Este programa se ejecuta en la consola Python de FreeCAD con el comando "execfile(/carpeta/*.py)". Este archivo en particular permite mover los componentes con las funciones de la libreria C++

import FreeCAD as App
import FreeCADGui as Gui
from PyQt4 import QtCore, QtGui
import math

# execfile("/home/carlos/Documents/Universidad/Robotica/programas/5nov/brazob.py")
FreeCAD.open("/home/carlos/Documents/Universidad/Robotica/programas/5nov/brazo.fcstd")
App.setActiveDocument("brazo")
App.ActiveDocument=App.getDocument("brazo")
Gui.ActiveDocument=Gui.getDocument("brazo")
import sys
sys.path.append('/home/carlos/Documents/Universidad/Robotica/programas/5nov/')
import MoveModuleb

move=MoveModuleb.pMovement()
PI = 3.14159
w0=0
t=0
def Leonardo():
     global PI, move, w0, w1, t, phi0, phi1, phi2, phi3, d1, d2	

     move.brazo(t)
     phi1 = move.phi1
     d1 = (move.d1 ) * 100
     phi2 = move.phi2
     phi3 = move.phi3
     d2 = (move.d2) * 100
     phi0 = move.phi0

     #if d1 < 50:
        #  d1 = 70

     #if d2 < 50:
        #  d2 = 70

	

     
     #primero base
     App.getDocument("brazo").Part__Feature001.Placement=App.Placement(App.Vector(0,0,0), App.Rotation(math.degrees(phi1),0,0), App.Vector(0,0,0))
     #primera extension
     App.getDocument("brazo").Part__Feature002.Placement=App.Placement(App.Vector((d1+7)*math.cos(phi1),(d1+7)*math.sin(phi1),0), App.Rotation(math.degrees(phi1),0,0), App.Vector(0,0,0))
     #articulacion
     App.getDocument("brazo").Part__Feature003.Placement=App.Placement(App.Vector((d1+208)*math.cos(phi1),(d1+208)*math.sin(phi1),0), App.Rotation(0,0,0), App.Vector(0,0,0))
     #segunda base
     App.getDocument("brazo").Part__Feature004.Placement=App.Placement(App.Vector((d1+210)*math.cos(phi1),(d1+210)*math.sin(phi1),0), App.Rotation(math.degrees(phi1+phi2),0,0), App.Vector(0,0,0))
     #segunda extension
     App.getDocument("brazo").Part__Feature005.Placement=App.Placement(App.Vector((d1+210)*math.cos(phi1)+d2*math.cos(phi1+phi2),(d1+210)*math.sin(phi1)+d2*math.sin(phi1+phi2),0),App.Rotation(math.degrees(phi1+phi2),0,0), App.Vector(0,0,0))
     #articulacion
     App.getDocument("brazo").Part__Feature006.Placement=App.Placement(App.Vector((d1+210)*math.cos(phi1)+(d2+200)*math.cos(phi1+phi2),(d1+210)*math.sin(phi1)+(d2+200)*math.sin(phi1+phi2),0), App.Rotation(0,0,0), App.Vector(0,0,0))
     #pinza
     App.getDocument("brazo").Part__Feature007.Placement=App.Placement(App.Vector((d1+210)*math.cos(phi1)+(d2+210)*math.cos(phi1+phi2),(d1+210)*math.sin(phi1)+(d2+210)*math.sin(phi1+phi2),0), App.Rotation(math.degrees(phi1+phi2+phi3),0,0), App.Vector(0,0,0))

     t+=1

     if t > 20000000000000:
          t=0

timer=QtCore.QTimer()
timer.timeout.connect(Leonardo)
timer.start(30)

x
