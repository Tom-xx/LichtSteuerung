# LichtSteuerung
Lichtsteuerung auf Arduino Nano Basis mit 6 Schaltern und 8 Lampen über ein Relais-Modul. Mit 3D-Vorlage für ein Hutschienen (Din-Rail) Gehäuse und Bauteilliste.

# Bauteilliste

* Gehäuse
  * Hutschiene / Basis / 8-Fach Relais
  * Arduino Aufsatz
* Arduino Nano V3.0
* Arduino Nano Breakout Board / Screw Terminal
* 8 Solid State Relay Low Level Trigger Modul
* Schaltdraht zum verkabeln
* 5V Netzteil für Hutschiene

Es sind idr. keine Lötarbeiten erforderlich.

# Konfiguration

Über die Datei main.ino kann im Array "arrrSwitchGroups" jeder Schalter verschiedenen Lampen zugeordnet werden, bei Betätigung vom jeweiligen Schalter werden die entsprechenden Lampen geschaltet / ausgeschaltet. Schalter, welche gemeinsame Lampen schalten, bilden virtuelle Wechselschalter. Die Zuordnung von Lampen zu Lichtschaltern geschieht über ein "true" in der Tabelle.
