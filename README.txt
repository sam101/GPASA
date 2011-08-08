________________________________
LISEZ MOI: Projet tutoré, 
Générateur pseudo-aléatoire de
scénarios d'aventure
________________________________



__________________
Comment compiler ?
__________________
La gui se compile de la façon suivante dans le repertoire "Ui":

qmake && make -j (NOMBRE DE PROCESSEURS)


Le projet console/de test se compile à l'aide du Makefile fourni.

_______________________________
Notes particulières
_______________________________

-> Un compilateur supportant dirent.h est necessaire pour compiler (Cf classe Dossier), ce qui signifie que le compilateur de Visual Studio sous Windows n'est pas supporté (si vous êtes
 suffisament motivé, vous pouvez essayez de faire une implémentation de la classe utilisant la lib WIN32 mais je ne le ferai pas). L'utilisation de MingW sous Windows est donc recommandée.  

->42 ?
